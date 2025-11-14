#if 1


#include <sivalgui.hpp>
#include "sivalwindow.hpp"

#include <QApplication>
#include <QtCharts/QLineSeries>

// #include "settingsdocument.hpp"
// #include "manufacturerdocument.hpp"

// Korrigierter logischer Ablauf der Entwicklung

// GUI und Grundlayout: Beginnen Sie mit der visuellen Oberfläche.

// Datenverwaltung der Lautsprecher: Implementieren Sie die Logik, um die Lautsprecherdaten zu laden. Dazu gehört das Einlesen der Haupt-Indexdatei und die Funktion, einzelne, vollständige Lautsprecherdateien bei Bedarf zu laden.

// Projektstruktur und -verwaltung: Nachdem die Lautsprecherdaten geladen und zugänglich sind, können Sie die Struktur für das Projektobjekt definieren und die Funktionen zum Speichern, Laden und Verwalten von Projekten implementieren.

// Import-Funktion: Erstellen Sie die Funktion zum Importieren neuer Lautsprecherdaten. Sie wird neue Dateien im korrekten Format erstellen und die Haupt-Indexdatei aktualisieren.

// Anzeige der Graphen: Visualisieren Sie die Daten. Dies ist der letzte Schritt, da er auf den erfolgreich geladenen Projektdaten und Lautsprecherparametern aufbaut.

int main(int argc, char *argv[])
{
    QString project;
    // SettingsDocument setdoc;
    // ManufacturerDocument *doc = new ManufacturerDocument(setdoc.speakerDb());
    QApplication a(argc, argv);
    SiVALWindow w(project/*, doc*/);
    w.show();
    return a.exec();
}
#endif

#if 0


#include <iostream>
#include <complex>
#include <numbers>
#include <fstream>
#include <iomanip>
#include <cmath>

//------------------ Konstanten ------------------
constexpr double RHO = 1.2041; // kg/m³
constexpr double C   = 343.0;  // m/s

//------------------ Strukturen ------------------
struct Speaker {
    double Re;    // Ohm
    double Le;    // H
    double Bl;    // T·m
    double Cms;   // m/N
    double Rms;   // N·s/m
    double Mms;   // kg
    double Sd;    // m²
    double Vas;   // m³
    double Qms;   // mechanische Güte
};

struct Box {
    double Vb;        // m³
    double stuffing;  // 0..1 Anteil gedämpft
};

//------------------ Hilfsfunktionen ------------------
double Cbox(const Box& box, const Speaker& sp) {
    return box.Vb / (RHO * C * C * sp.Sd * sp.Sd);
}

double Rms_eff_with_stuffing(const Speaker& sp, double stuffing) {
    return sp.Rms * (1.0 + stuffing);
}

// Mechanische Impedanz inkl. Box-Kompression und Radiation
std::complex<double> Z_mech(const Speaker& sp, const Box& box, double f) {
    double w = 2.0 * std::numbers::pi * f;
    double Ctot = (sp.Cms * Cbox(box, sp)) / (sp.Cms + Cbox(box, sp));

    std::complex<double> Zm(Rms_eff_with_stuffing(sp, box.stuffing), w * sp.Mms);
    Zm += std::complex<double>(0.0, -1.0 / (w * Ctot));

    // Radiation impedance (vereinfachte Näherung)
    double R_rad = 0.5 * sp.Sd * std::sqrt(RHO * C / (2.0 * M_PI * f));
    double M_rad = 0.2 * sp.Sd * RHO; // added mass
    Zm += std::complex<double>(R_rad, w * M_rad);

    return Zm;
}

// Elektrische Impedanz inkl. Le(f)
std::complex<double> Z_elec(const Speaker& sp, const std::complex<double>& Zm, double f) {
    double w = 2.0 * std::numbers::pi * f;
    double Le_f = sp.Le * std::sqrt(f / 100.0); // √f Näherung
    std::complex<double> Ze(sp.Re, w * Le_f);
    Ze += (sp.Bl * sp.Bl) / Zm;
    return Ze;
}

// Komplette Impedanz geschlossen
std::complex<double> impedanceClosedAdvanced(const Speaker& sp, const Box& box, double f) {
    auto Zm = Z_mech(sp, box, f);
    auto Ze = Z_elec(sp, Zm, f);
    return Ze;
}

// CSV Export
void write_impedance_csv(const Speaker& sp, const Box& box, const std::string& filename,
                         double f_start=10.0, double f_stop=500.0, int n=200) {
    std::ofstream fout(filename);
    fout << "f,Re,Im,|Z|,phase_deg\n";
    for (int i = 0; i < n; ++i) {
        double f = f_start + i*(f_stop-f_start)/(n-1);
        std::complex<double> Z = impedanceClosedAdvanced(sp, box, f);
        double mag = std::abs(Z);
        double phase = std::atan2(Z.imag(), Z.real()) * 180.0 / std::numbers::pi;
        fout << f << "," << Z.real() << "," << Z.imag() << "," << mag << "," << phase << "\n";
    }
    fout.close();
}

//------------------ MAIN ------------------
int main() {
    Speaker sp{
        3.9,        // Re [Ohm]
        0.00049,    // Le [H]
        9.0,        // Bl [T·m]
        0.00043,    // Cms [m/N]
        1.05,       // Rms [N·s/m]
        0.0369,     // Mms [kg]
        0.02208,    // Sd [m²]
        0.0297,     // Vas [m³]
        8.87        // Qms
    };

    Box box{0.020, 0.2}; // 20 Liter, 20% stuffing

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "f [Hz], |Z| [Ohm], phase [deg]\n";
    for (double f : {20, 30, 40, 50, 63, 80, 100, 200}) {
        std::complex<double> Z = impedanceClosedAdvanced(sp, box, f);
        double mag = std::abs(Z);
        double phase = std::atan2(Z.imag(), Z.real()) * 180.0 / std::numbers::pi;
        std::cout << f << ", " << mag << ", " << phase << "\n";
    }

    write_impedance_csv(sp, box, "impedance_closed_physical.csv");
    std::cout << "\nCSV geschrieben: impedance_closed_physical.csv\n";

    return 0;
}


#endif





#if 0



#include <iostream>
#include <complex>
#include <numbers>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>

struct Speaker {
    double Re;   // Ohm
    double Le;   // H
    double Bl;   // T·m
    double Cms;  // m/N
    double Rms;  // N·s/m
    double Mms;  // kg
    double Sd;   // m^2
    double Vas;  // m^3
    double Qms;  // mechanische Güte
};

// Konstanten Luft
constexpr double RHO = 1.2041; // kg/m³
constexpr double C   = 343.0;  // m/s

// ----------------- k_loss Schätzung -----------------
double estimate_k_loss_realistic(const Speaker& sp, double Vb) {
    // Box-zu-Treiber Volumen Verhältnis
    double vol_ratio = sp.Vas / Vb;

    // Mechanische Dämpfung erhöhen für kleine Boxen
    double k_loss = 1.5 + 0.5 * vol_ratio; // heuristisch, min 1.5, max ~2.5
    return k_loss;
}

// ----------------- Impedanz geschlossen -----------------
std::complex<double> impedanceClosed(const Speaker& sp, double Vb, double f) {
    double k_loss = estimate_k_loss_realistic(sp, Vb);
    double w = 2.0 * std::numbers::pi * f;

    // Box Compliance
    double Cbox = Vb / (RHO * C * C * sp.Sd * sp.Sd);
    double C_total = (sp.Cms * Cbox) / (sp.Cms + Cbox);

    // Mechanischer Zweig
    double Rms_eff = sp.Rms * k_loss;
    std::complex<double> Zm(Rms_eff, w * sp.Mms);
    Zm += std::complex<double>(0.0, -1.0 / (w * C_total));

    // Elektrischer Zweig
    std::complex<double> Ze(sp.Re, w * sp.Le);
    Ze += (sp.Bl * sp.Bl) / Zm;

    return Ze;
}

// ----------------- CSV Ausgabe -----------------
void write_impedance_csv(const Speaker& sp, double Vb, const std::string& filename,
                         double f_start=10.0, double f_stop=500.0, int n=200) {
    std::ofstream fout(filename);
    fout << "f,Re,Im,|Z|,phase_deg\n";

    for (int i=0; i<n; ++i) {
        double f = f_start + i*(f_stop-f_start)/(n-1);
        std::complex<double> Ze = impedanceClosed(sp, Vb, f);
        double mag = std::abs(Ze);
        double ph = std::atan2(Ze.imag(), Ze.real()) * 180.0 / std::numbers::pi;

        fout << f << "," << Ze.real() << "," << Ze.imag() << "," << mag << "," << ph << "\n";
    }
    fout.close();
}

// ----------------- MAIN -----------------
int main() {
    Speaker sp{
        3.9,        // Re [Ohm]
        0.00049,    // Le [H]
        9.0,        // Bl [T·m]
        0.00043,    // Cms [m/N]
        1.05,       // Rms [N·s/m]
        0.0369,     // Mms [kg]
        0.02208,    // Sd [m^2]
        0.0297,     // Vas [m^3]
        8.87        // Qms
    };

    double Vb = 0.020; // 20 Liter in m^3

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "f [Hz], |Z| [Ohm], phase [deg]\n";

    for (double f : {20, 30, 40, 50, 63, 80, 100, 200}) {
        std::complex<double> Z = impedanceClosed(sp, Vb, f);
        double mag = std::abs(Z);
        double phase = std::atan2(Z.imag(), Z.real()) * 180.0 / std::numbers::pi;
        std::cout << f << ", " << mag << ", " << phase << "\n";
    }

    write_impedance_csv(sp, Vb, "impedance_closed_realistic.csv");
    std::cout << "\nCSV geschrieben: impedance_closed_realistic.csv\n";

    return 0;
}




#endif
