
#if 1

#include "sivalwindow.hpp"

#include <QApplication>

#include "settingsdocument.hpp"
#include "manufacturerdocument.hpp"

// Korrigierter logischer Ablauf der Entwicklung

// GUI und Grundlayout: Beginnen Sie mit der visuellen Oberfläche.

// Datenverwaltung der Lautsprecher: Implementieren Sie die Logik, um die Lautsprecherdaten zu laden. Dazu gehört das Einlesen der Haupt-Indexdatei und die Funktion, einzelne, vollständige Lautsprecherdateien bei Bedarf zu laden.

// Projektstruktur und -verwaltung: Nachdem die Lautsprecherdaten geladen und zugänglich sind, können Sie die Struktur für das Projektobjekt definieren und die Funktionen zum Speichern, Laden und Verwalten von Projekten implementieren.

// Import-Funktion: Erstellen Sie die Funktion zum Importieren neuer Lautsprecherdaten. Sie wird neue Dateien im korrekten Format erstellen und die Haupt-Indexdatei aktualisieren.

// Anzeige der Graphen: Visualisieren Sie die Daten. Dies ist der letzte Schritt, da er auf den erfolgreich geladenen Projektdaten und Lautsprecherparametern aufbaut.

int main(int argc, char *argv[])
{
    QString project;
    SettingsDocument setdoc;
    ManufacturerDocument *doc = new ManufacturerDocument(setdoc.speakerDb());
    QApplication a(argc, argv);
    SiVALWindow w(project, doc);
    w.show();
    return a.exec();
}
#endif










#if 0 // Graphen zeichnen lassen

#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLogValueAxis>
#include <QPointF>
#include <QVector>
#include <QRandomGenerator>
#include <cmath> // For std::log10 and pow
#include <QDebug>
#include <QMouseEvent>


/**
 * @class MainWindow
 *
 * A main window class for displaying the chart.
 */
class MainWindow : public QMainWindow {


public:
    explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Qt Charts mit logarithmischer X-Achse");
        resize(800, 600);

        // Define start and end variables for the frequency range.
        const double startFrequency = 10.0;
        const double endFrequency = 1000.0;

        // Create a series to store the data points.
        QLineSeries *series = new QLineSeries();
        series->setName("Beispieldaten");

        // Fill the series with points in 10% steps on the X-axis.
        double x = startFrequency;
        int i = 0;
        while (x <= endFrequency) {
            *series << QPointF(x, 10.0 + static_cast<double>(i) * 5.0);
            x *= 1.1;
            i++;
        }

        // Create the chart and add the series to it.
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Liniendiagramm mit logarithmischer X-Achse");
        chart->setTheme(QChart::ChartThemeLight);

        // Create a logarithmic axis for the X-values (Frequency).
        QLogValueAxis *axisX = new QLogValueAxis();
        axisX->setBase(10.0);
        axisX->setLabelFormat("%g Hz");
        // Activate major grid lines.
        axisX->setGridLineVisible(true);
        // Activate minor grid lines.
        // These lines are especially important for a logarithmic axis.
        axisX->setMinorGridLineVisible(true);
        axisX->setTitleText("X-Achse (Logarithmisch)");
        axisX->setRange(startFrequency, endFrequency);
        axisX->setMinorTickCount(9); // Sets the number of small ticks to 9 per decade.
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        // Create a linear axis for the Y-values.
        QValueAxis *axisY = new QValueAxis();
        axisY->setGridLineVisible(true);
        axisY->setMinorGridLineVisible(true);
        axisY->setTitleText("Y-Achse (Linear)");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        // Create a QChartView widget to display the chart.
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Set the ChartView as the central widget in the main window.
        setCentralWidget(chartView);

        // Install the event filter on the ChartView to capture mouse events.
        chartView->installEventFilter(this);
    }

private:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QChartView *chartView = qobject_cast<QChartView*>(obj);
            if (chartView) {
                // Convert the mouse position from widget coordinates to chart coordinates.
                QPointF chartPos = chartView->chart()->mapToValue(mouseEvent->pos());
                qDebug() << "Mausposition: X =" << chartPos.x() << ", Y =" << chartPos.y();
            }
        }
        return QMainWindow::eventFilter(obj, event);
    }
};

// Main application function.
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    return a.exec();
}




#endif






#if 0

#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLogValueAxis>
#include <QPointF>
#include <QVector>
#include <QRandomGenerator>
#include <cmath>
#include <QDebug>
#include <QMouseEvent>
#include <QtCharts/QAbstractAxis>


/**
 * @class MainWindow
 *
 * A main window class for displaying the chart.
 */
class MainWindow : public QMainWindow {


public:
    explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Qt Charts mit logarithmischer X-Achse und zwei Y-Achsen");
        resize(800, 600);

        // Define start and end variables for the frequency range.
        const double startFrequency = 10.0;
        const double endFrequency = 20000.0;

        // Create a series to store the data points for the first curve (dB).
        QLineSeries *series1 = new QLineSeries();
        series1->setName("Dezibel (dB)");

        // Fill the first series with points in 10% steps on the X-axis with dB-like values.
        double x1 = startFrequency;
        int i1 = 0;
        while (x1 <= endFrequency) {
            *series1 << QPointF(x1, -10.0 - static_cast<double>(i1) * 2.0);
            x1 *= 1.1;
            i1++;
        }

        // Create a second series to store the data points for the second curve (Ohm).
        QLineSeries *series2 = new QLineSeries();
        series2->setName("Widerstand (Ohm)");

        // Fill the second series with Ohm values.
        double x2 = startFrequency;
        int i2 = 0;
        while (x2 <= endFrequency) {
            *series2 << QPointF(x2, 50.0 + sin(x2 / 1000.0) * 20.0);
            x2 *= 1.1;
            i2++;
        }

        // Create the chart and add both series to it.
        QChart *chart = new QChart();
        chart->addSeries(series1);
        chart->addSeries(series2);
        chart->setTitle("Liniendiagramm mit zwei Y-Achsen");
        chart->setTheme(QChart::ChartThemeLight);

        // Create a logarithmic axis for the X-values (Frequency).
        QLogValueAxis *axisX = new QLogValueAxis();
        axisX->setBase(10.0);
        axisX->setLabelFormat("%g Hz");
        axisX->setGridLineVisible(true);
        axisX->setMinorGridLineVisible(true);
        axisX->setTitleText("X-Achse (Frequenz)");
        axisX->setRange(startFrequency, endFrequency);
        axisX->setMinorTickCount(9);
        chart->addAxis(axisX, Qt::AlignBottom);

        // Create the primary linear Y-axis (for dB).
        QValueAxis *axisY1 = new QValueAxis();
        axisY1->setGridLineVisible(true);
        axisY1->setMinorGridLineVisible(true);
        axisY1->setTitleText("Y-Achse (dB)");
        axisY1->setRange(-100.0, 0.0);
        chart->addAxis(axisY1, Qt::AlignLeft);

        // Create the secondary linear Y-axis (for Ohm).
        QValueAxis *axisY2 = new QValueAxis();
        axisY2->setGridLineVisible(true);
        axisY2->setMinorGridLineVisible(true);
        axisY2->setTitleText("Y-Achse (Ohm)");
        axisY2->setRange(0.0, 100.0);
        chart->addAxis(axisY2, Qt::AlignRight);

        // Attach the series to their respective axes.
        series1->attachAxis(axisX);
        series1->attachAxis(axisY1);
        series2->attachAxis(axisX);
        series2->attachAxis(axisY2);

        // Create a QChartView widget to display the chart.
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Set the ChartView as the central widget in the main window.
        setCentralWidget(chartView);

        // Install the event filter on the ChartView to capture mouse events.
        chartView->installEventFilter(this);
    }

private:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QChartView *chartView = qobject_cast<QChartView*>(obj);
            if (chartView) {
                // Konvertiere die Mausposition von Widget-Koordinaten zu den Werten der primären Achsen.
                QPointF chartPos = chartView->chart()->mapToValue(mouseEvent->pos());
                qDebug() << "Mausposition: X =" << chartPos.x() << ", Y =" << chartPos.y();
            }
        }
        return QMainWindow::eventFilter(obj, event);
    }
};

// Main application function.
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    return a.exec();
}


#endif




#if 0
#include <iostream>





#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLogValueAxis>
#include <QPointF>
#include <QVector>
#include <QDebug>
#include <QMouseEvent>
#include <QtCharts/QAbstractAxis>

#include <cmath>
#include <complex>

// Eine Struktur zur Speicherung der Thiele-Small-Parameter.
struct ThieleSmallParameters {
    double Re;   // Gleichstromwiderstand (Ohm)
    double Fs;   // Resonanzfrequenz (Hz)
    double Qms;  // Mechanischer Gütefaktor
    double Qes;  // Elektrischer Gütefaktor
    double Qts;  // Gesamter Gütefaktor
    double Le;   // Schwingspuleninduktivität (H)
    double Vas;  // Äquivalentes Luftvolumen (l)
};

// Funktion zur Berechnung der Impedanz eines Lautsprechers in einem geschlossenen Gehäuse.
double calculateSealedBoxImpedance(double frequency, const ThieleSmallParameters& tsp, double Vb) {
    if (frequency == 0.0) {
        return tsp.Re;
    }

    double w = 2.0 * M_PI * frequency;

    // Berechnung der Parameter des äquivalenten elektrischen Schaltkreises für das Chassis im freien Raum.
    double Lces = (tsp.Qes * tsp.Re) / (2.0 * M_PI * tsp.Fs);
    double Cmes = 1.0 / (Lces * (2.0 * M_PI * tsp.Fs) * (2.0 * M_PI * tsp.Fs));
    double Res = tsp.Re * tsp.Qms / tsp.Qes;

    // Die akustische Steifigkeit des Gehäuses (Vb) wird als zusätzliche Kapazität
    // in Reihe zur mechanischen Compliance (Cmes) des Chassis modelliert.
    double alpha = tsp.Vas / Vb;
    double Cmes_total = Cmes / (1.0 + alpha);

    // Neuberechnung der motionalen Impedanz mit der angepassten Gesamtkapazität.
    // std::complex ist für die komplexe Zahlenberechnung notwendig.
    std::complex<double> motional_impedance(
        Res / (1.0 + std::pow(w * Cmes_total - 1.0 / (w * Lces), 2.0) * Res * Res),
        (w * Cmes_total - 1.0 / (w * Lces)) * Res * Res / (1.0 + std::pow(w * Cmes_total - 1.0 / (w * Lces), 2.0) * Res * Res)
        );

    // Die Gesamtimpedanz ist die Summe des Gleichstromwiderstands, der Induktivität der Schwingspule
    // und der motionalen Impedanz des Systems.
    std::complex<double> total_impedance = std::complex<double>(tsp.Re, w * tsp.Le) + motional_impedance;

    // Rückgabe des Betrags der Gesamtimpedanz.
    return std::abs(total_impedance);
}

/**
 * @class MainWindow
 *
 * Eine Hauptfensterklasse zur Darstellung des Diagramms.
 */
class MainWindow : public QMainWindow {

public:
    explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Impedanzkurve - Geschlossenes Gehäuse");
        resize(800, 600);

        // Definieren des Frequenzbereichs.
        const double startFrequency = 10.0;
        const double endFrequency = 500.0;

        // Thiele-Small-Parameter für den Visaton AL130A 8 Ohm.
        ThieleSmallParameters tsp;
        tsp.Re = 5.5;
        tsp.Fs = 40.0;
        tsp.Qms = 5.19;
        tsp.Qes = 0.39;
        tsp.Qts = 0.363;
        tsp.Le = 0.67e-3; // 0.67 mH
        tsp.Vas = 15.6; // 15.6 Liter

        // Definieren des Gehäusevolumens (in Litern).
        const double sealedEnclosureVolume = 8.0;

        // Erstellen einer Datenreihe für die Impedanzkurve.
        QLineSeries *impedanceSeries = new QLineSeries();
        impedanceSeries->setName("Impedanz (Ohm)");

        // Befüllen der Datenreihe mit den Impedanzwerten.
        double freq = startFrequency;
        while (freq <= endFrequency) {
            double impedance = calculateSealedBoxImpedance(freq, tsp, sealedEnclosureVolume);
            std::cout << "Frequenz: " << freq << "\t| Impedance: " << impedance << std::endl;
            *impedanceSeries << QPointF(freq, impedance);
            freq *= 1.003; // Logarithmische Schrittweite
        }

        // Erstellen des Diagramms und Hinzufügen der Datenreihe.
        QChart *chart = new QChart();
        chart->addSeries(impedanceSeries);
        chart->setTitle("Impedanzkurve des Visaton AL130A 8 Ohm in 8l-Gehäuse");
        chart->setTheme(QChart::ChartThemeLight);

        // Erstellen einer logarithmischen Achse für die Frequenz (X-Werte).
        QLogValueAxis *axisX = new QLogValueAxis();
        axisX->setBase(10.0);
        axisX->setLabelFormat("%g Hz");
        axisX->setGridLineVisible(true);
        axisX->setMinorGridLineVisible(true);
        axisX->setTitleText("Frequenz");
        axisX->setRange(startFrequency, endFrequency);
        axisX->setMinorTickCount(9);
        chart->addAxis(axisX, Qt::AlignBottom);

        // Erstellen einer linearen Achse für die Impedanz (Y-Werte).
        QValueAxis *axisY = new QValueAxis();
        axisY->setGridLineVisible(true);
        axisY->setMinorGridLineVisible(true);
        axisY->setTitleText("Impedanz (Ohm)");
        axisY->setRange(0, 100);
        chart->addAxis(axisY, Qt::AlignLeft);
        impedanceSeries->attachAxis(axisX);
        impedanceSeries->attachAxis(axisY);

        // Erstellen eines QChartView-Widgets zur Anzeige des Diagramms.
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        setCentralWidget(chartView);

        // Installieren des Event-Filters, um Mausereignisse zu erfassen.
        chartView->installEventFilter(this);
    }

private:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QChartView *chartView = qobject_cast<QChartView*>(obj);
            if (chartView) {
                QPointF chartPos = chartView->chart()->mapToValue(mouseEvent->pos());
                qDebug() << "Mausposition: X =" << chartPos.x() << ", Y =" << chartPos.y();
            }
        }
        return QMainWindow::eventFilter(obj, event);
    }
};

// Hauptfunktion der Anwendung.
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();
}


#endif


#if 0

#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLogValueAxis>
#include <QPointF>
#include <QVector>
#include <cmath>
#include <QDebug>
#include <QMouseEvent>
#include <QtCharts/QAbstractAxis>
#include <complex>
#include <iostream>


// Eine Struktur zur Speicherung der Thiele-Small-Parameter.
struct ThieleSmallParameters {
    double Re;   // Gleichstromwiderstand (Ohm)
    double Fs;   // Resonanzfrequenz (Hz)
    double Qms;  // Mechanischer Gütefaktor
    double Qes;  // Elektrischer Gütefaktor
    double Qts;  // Gesamter Gütefaktor
    double Le;   // Schwingspuleninduktivität (H)
    double Vas;  // Äquivalentes Luftvolumen (l)
};

// Funktion zur Berechnung der Impedanz eines Lautsprechers in einem geschlossenen Gehäuse.
double calculateSealedBoxImpedance(double frequency, const ThieleSmallParameters& tsp, double Vb) {
    if (frequency == 0.0) {
        return tsp.Re;
    }

    double w = 2.0 * M_PI * frequency;

    // Berechnung der Parameter des äquivalenten elektrischen Schaltkreises für das Chassis im freien Raum.
    double Lces = (tsp.Qes * tsp.Re) / (2.0 * M_PI * tsp.Fs);
    double Cmes = 1.0 / (Lces * (2.0 * M_PI * tsp.Fs) * (2.0 * M_PI * tsp.Fs));
    double Res = tsp.Re * tsp.Qms / tsp.Qes;

    // Die akustische Steifigkeit des Gehäuses (Vb) wird als zusätzliche Kapazität
    // in Reihe zur mechanischen Compliance (Cmes) des Chassis modelliert.
    double alpha = tsp.Vas / Vb;
    double Cmes_total = Cmes / (1.0 + alpha);

    // Neuberechnung der motionalen Impedanz mit der angepassten Gesamtkapazität.
    // std::complex ist für die komplexe Zahlenberechnung notwendig.
    std::complex<double> motional_impedance(
        Res / (1.0 + std::pow(w * Cmes_total - 1.0 / (w * Lces), 2.0) * Res * Res),
        (w * Cmes_total - 1.0 / (w * Lces)) * Res * Res / (1.0 + std::pow(w * Cmes_total - 1.0 / (w * Lces), 2.0) * Res * Res)
        );

    // Die Gesamtimpedanz ist die Summe des Gleichstromwiderstands, der Induktivität der Schwingspule
    // und der motionalen Impedanz des Systems.
    std::complex<double> total_impedance = std::complex<double>(tsp.Re, w * tsp.Le) + motional_impedance;

    // Rückgabe des Betrags der Gesamtimpedanz.
    return std::abs(total_impedance);
}

// Funktion zur Berechnung der SPL-Kurve eines geschlossenen Gehäuses unter Verwendung der Transferfunktion.
double calculateSPL(double frequency, const ThieleSmallParameters& tsp, double Vb, double sensitivity) {
    if (frequency == 0.0) {
        return 0.0;
    }

    double fc = tsp.Fs * std::sqrt(1.0 + tsp.Vas / Vb);
    double Qtc = tsp.Qts * std::sqrt(1.0 + tsp.Vas / Vb);
    double omega = 2.0 * M_PI * frequency;
    double omega_c = 2.0 * M_PI * fc;
    double ratio_sq = std::pow(omega / omega_c, 2.0);

    // Berechnung des Betragsquadrats der Transferfunktion eines Hochpassfilters 2. Ordnung.
    double transfer_function_sq = ratio_sq * ratio_sq / (std::pow(1.0 - ratio_sq, 2.0) + std::pow(omega / omega_c / Qtc, 2.0));

    // SPL in dB, basierend auf der Transferfunktion und der Empfindlichkeit.
    double spl = sensitivity + 10.0 * std::log10(transfer_function_sq);

    return spl;
}

/**
 * @class MainWindow
 *
 * Eine Hauptfensterklasse zur Darstellung des Diagramms.
 */
class MainWindow : public QMainWindow {


public:
    explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("SPL-Kurve - Geschlossenes Gehäuse");
        resize(800, 600);

        // Definieren des Frequenzbereichs.
        const double startFrequency = 10.0;
        const double endFrequency = 20000.0;

        // Thiele-Small-Parameter für den Visaton AL130A 8 Ohm.
        ThieleSmallParameters tsp;
        tsp.Re = 5.5;
        tsp.Fs = 40.0;
        tsp.Qms = 5.19;
        tsp.Qes = 0.39;
        tsp.Qts = 0.36;
        tsp.Le = 0.67e-3; // 0.67 mH
        tsp.Vas = 15.6; // 15.6 Liter

        // Definieren des Gehäusevolumens (in Litern).
        const double sealedEnclosureVolume = 8.0;
        // Referenzempfindlichkeit bei 1W/1m
        const double referenceSensitivity = 86.12;

        // Erstellen einer Datenreihe für die SPL-Kurve.
        QLineSeries *splSeries = new QLineSeries();
        splSeries->setName("Schalldruckpegel (dB)");

        // Befüllen der Datenreihe mit den Werten.
        double freq = startFrequency;
        while (freq <= endFrequency) {
            double spl = calculateSPL(freq, tsp, sealedEnclosureVolume, referenceSensitivity);

            std::cout << "Frequenz: " << freq << "\t| SPL: " << spl << " dB" << std::endl;

            *splSeries << QPointF(freq, spl);
            freq *= 1.05; // Logarithmische Schrittweite für eine höhere Auflösung
        }

        // Erstellen des Diagramms und Hinzufügen der Datenreihe.
        QChart *chart = new QChart();
        chart->addSeries(splSeries);
        chart->setTitle("SPL-Kurve des Visaton AL130A in 8l-Gehäuse");
        chart->setTheme(QChart::ChartThemeLight);

        // Erstellen einer logarithmischen Achse für die Frequenz (X-Werte).
        QLogValueAxis *axisX = new QLogValueAxis();
        axisX->setBase(10.0);
        axisX->setLabelFormat("%g Hz");
        axisX->setGridLineVisible(true);
        axisX->setMinorGridLineVisible(true);
        axisX->setTitleText("Frequenz");
        axisX->setRange(startFrequency, endFrequency);
        axisX->setMinorTickCount(9);
        chart->addAxis(axisX, Qt::AlignBottom);

        // Erstellen einer linearen Achse für die SPL-Werte.
        QValueAxis *axisY = new QValueAxis();
        axisY->setGridLineVisible(true);
        axisY->setMinorGridLineVisible(true);
        axisY->setTitleText("SPL (dB)");
        axisY->setRange(40, 100);
        axisY->setMinorTickCount(14);
        chart->addAxis(axisY, Qt::AlignLeft);
        splSeries->attachAxis(axisX);
        splSeries->attachAxis(axisY);

        // Erstellen eines QChartView-Widgets zur Anzeige des Diagramms.
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        setCentralWidget(chartView);

        // Installieren des Event-Filters, um Mausereignisse zu erfassen.
        chartView->installEventFilter(this);
    }

private:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QChartView *chartView = qobject_cast<QChartView*>(obj);
            if (chartView) {
                QPointF chartPos = chartView->chart()->mapToValue(mouseEvent->pos());
                qDebug() << "Mausposition: X =" << chartPos.x() << ", Y =" << chartPos.y();
            }
        }
        return QMainWindow::eventFilter(obj, event);
    }
};

// Hauptfunktion der Anwendung.
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();
}



#endif
