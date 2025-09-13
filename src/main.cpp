#if 1

#include "sivalwindow.hpp"

#include <QApplication>
#include <QtCharts/QLineSeries>

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
#include <QVBoxLayout>

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

/**
 * @class SpeakerEnclosureSimulator
 *
 * Eine abstrakte Basisklasse, die die Kernlogik der Lautsprechersimulation enthält
 * und die Schnittstelle für die abgeleiteten Klassen definiert.
 */
class SpeakerEnclosureSimulator {
protected:
    ThieleSmallParameters tsp;
    double Vb;
    double sensitivity;

public:
    SpeakerEnclosureSimulator(const ThieleSmallParameters& parameters, double boxVolume, double refSensitivity)
        : tsp(parameters), Vb(boxVolume), sensitivity(refSensitivity) {}

    virtual ~SpeakerEnclosureSimulator() = default;

    // Reine virtuelle Funktion für die SPL-Berechnung. Muss von abgeleiteten Klassen implementiert werden.
    virtual double calculateSPL(double frequency) const = 0;

    // Reine virtuelle Funktion für die Impedanzberechnung. Muss von abgeleiteten Klassen implementiert werden.
    virtual double calculateImpedance(double frequency) const = 0;
};

/**
 * @class SealedEnclosureSimulator
 *
 * Eine Klasse zur Simulation der SPL- und Impedanzkurve eines Lautsprechers in einem geschlossenen Gehäuse.
 */
class SealedEnclosureSimulator : public SpeakerEnclosureSimulator {
public:
    SealedEnclosureSimulator(const ThieleSmallParameters& parameters, double boxVolume, double refSensitivity)
        : SpeakerEnclosureSimulator(parameters, boxVolume, refSensitivity) {}

    // Implementierung der SPL-Berechnung für ein geschlossenes Gehäuse.
    double calculateSPL(double frequency) const override {
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

    // Implementierung der Impedanzberechnung für ein geschlossenes Gehäuse.
    double calculateImpedance(double frequency) const override {
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
};

/**
 * @class VentedEnclosureSimulator
 *
 * Eine Klasse zur Simulation der SPL- und Impedanzkurve eines Lautsprechers in einem Bassreflexgehäuse.
 */
class VentedEnclosureSimulator : public SpeakerEnclosureSimulator {
private:
    double Fb; // Abstimmfrequenz des Bassreflexrohrs

public:
    VentedEnclosureSimulator(const ThieleSmallParameters& parameters, double boxVolume, double refSensitivity, double portTuningFrequency)
        : SpeakerEnclosureSimulator(parameters, boxVolume, refSensitivity), Fb(portTuningFrequency) {}

    // Implementierung der SPL-Berechnung für ein Bassreflexgehäuse.
    double calculateSPL(double frequency) const override {
        if (frequency == 0.0) {
            return 0.0;
        }

        // Berechnung des Parameters h (Verhältnis der Frequenzen)
        double h = Fb / tsp.Fs;
        // Berechnung des Parameters alpha (Verhältnis der Volumina)
        double alpha = tsp.Vas / Vb;

        // Hilfsgrößen für die Berechnung der Transferfunktion
        double K = tsp.Qts;
        double k_sq = std::pow(frequency / tsp.Fs, 2.0);
        double h_sq = h * h;

        // Zähler und Nenner der Transferfunktion
        double numerator_sq = std::pow(k_sq * (h_sq + 1), 2.0);
        double denominator_sq = std::pow(k_sq * h_sq - 1, 2.0) + std::pow(k_sq * (1.0 + 1.0 / alpha) - (h_sq + 1), 2.0) / std::pow(K, 2.0);

        // Berechnung des Betragsquadrats der Transferfunktion
        double transfer_function_sq = numerator_sq / denominator_sq;

        // SPL in dB, basierend auf der Transferfunktion und der Empfindlichkeit.
        double spl = sensitivity + 10.0 * std::log10(transfer_function_sq);

        return spl;
    }

    // Implementierung der Impedanzberechnung für ein Bassreflexgehäuse.
    double calculateImpedance(double frequency) const override {
        if (frequency == 0.0) {
            return tsp.Re;
        }

        double w = 2.0 * M_PI * frequency;

        // Berechnung der Parameter des äquivalenten elektrischen Schaltkreises für das Chassis im freien Raum.
        double Lces = (tsp.Qes * tsp.Re) / (2.0 * M_PI * tsp.Fs);
        double Cmes = 1.0 / (Lces * std::pow(2.0 * M_PI * tsp.Fs, 2.0));
        double Res = tsp.Re * tsp.Qms / tsp.Qes;

        // Zusätzliche Parameter für das Bassreflexsystem
        double Lcev = 1.0 / (Cmes * std::pow(2.0 * M_PI * Fb, 2.0));
        double Rcev = 2.0 * M_PI * Fb * Lcev * tsp.Qes;

        // Komplexe Berechnung der Impedanz des Bassreflexsystems
        std::complex<double> z1(Res, w * Lces - 1.0 / (w * Cmes));
        std::complex<double> z2(Rcev, w * Lcev - 1.0 / (w * Cmes));

        std::complex<double> motional_impedance = (z1 * z2) / (z1 + z2);

        std::complex<double> total_impedance = std::complex<double>(tsp.Re, w * tsp.Le) + motional_impedance;

        return std::abs(total_impedance);
    }
};

/**
 * @class MainWindow
 *
 * Eine Hauptfensterklasse zur Darstellung des Diagramms.
 */
class MainWindow : public QMainWindow {

public:
    explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("SPL-Kurve - Lautsprecher-Simulation");
        resize(800, 600);

        // Definieren des Frequenzbereichs.
        const double startFrequency = 10.0;
        const double endFrequency = 1000.0;

        // Thiele-Small-Parameter für den Visaton AL130A 8 Ohm.
        ThieleSmallParameters tsp;
        tsp.Re = 5.5;
        tsp.Fs = 40.0;
        tsp.Qms = 5.19;
        tsp.Qes = 0.39;
        tsp.Qts = 0.36;
        tsp.Le = 0.67e-3; // 0.67 mH
        tsp.Vas = 15.6; // 15.6 Liter

        // Definieren des Gehäusevolumens (in Litern) und der Referenzempfindlichkeit.
        const double enclosureVolume = 8.0;
        const double referenceSensitivity = 89.1;

        // Erstellen der Simulatoren.
        SealedEnclosureSimulator sealedSimulator(tsp, enclosureVolume, referenceSensitivity);
        VentedEnclosureSimulator ventedSimulator(tsp, enclosureVolume, referenceSensitivity, 50.0); // 50 Hz Port-Frequenz

        // ---------------------------------------------------------------------
        // Datenreihen für das geschlossene Gehäuse
        // ---------------------------------------------------------------------
        QLineSeries *sealedSplSeries = new QLineSeries();
        sealedSplSeries->setName("SPL (geschlossen)");
        QLineSeries *sealedImpedanceSeries = new QLineSeries();
        sealedImpedanceSeries->setName("Impedanz (geschlossen)");

        double freq_sealed = startFrequency;
        while (freq_sealed <= endFrequency) {
            sealedSplSeries->append(freq_sealed, sealedSimulator.calculateSPL(freq_sealed));
            sealedImpedanceSeries->append(freq_sealed, sealedSimulator.calculateImpedance(freq_sealed));
            freq_sealed *= 1.05;
        }

        // ---------------------------------------------------------------------
        // Datenreihen für das Bassreflexgehäuse
        // ---------------------------------------------------------------------
        QLineSeries *ventedSplSeries = new QLineSeries();
        ventedSplSeries->setName("SPL (Bassreflex)");
        QLineSeries *ventedImpedanceSeries = new QLineSeries();
        ventedImpedanceSeries->setName("Impedanz (Bassreflex)");

        double freq_vented = startFrequency;
        while (freq_vented <= endFrequency) {
            ventedSplSeries->append(freq_vented, ventedSimulator.calculateSPL(freq_vented));
            ventedImpedanceSeries->append(freq_vented, ventedSimulator.calculateImpedance(freq_vented));
            freq_vented *= 1.003;
        }

        // ---------------------------------------------------------------------
        // Diagramme erstellen
        // ---------------------------------------------------------------------
        QChart *splChart = new QChart();
        splChart->addSeries(sealedSplSeries);
        splChart->addSeries(ventedSplSeries);
        splChart->setTitle("SPL-Kurve im Vergleich");
        splChart->setTheme(QChart::ChartThemeLight);

        QChart *impedanceChart = new QChart();
        impedanceChart->addSeries(sealedImpedanceSeries);
        impedanceChart->addSeries(ventedImpedanceSeries);
        impedanceChart->setTitle("Impedanz-Kurve im Vergleich");
        impedanceChart->setTheme(QChart::ChartThemeLight);

        // Achsen konfigurieren
        QLogValueAxis *axisX_spl = new QLogValueAxis();
        axisX_spl->setBase(10.0);
        axisX_spl->setLabelFormat("%g Hz");
        axisX_spl->setRange(startFrequency, endFrequency);
        axisX_spl->setTitleText("Frequenz");
        splChart->addAxis(axisX_spl, Qt::AlignBottom);

        QValueAxis *axisY_spl = new QValueAxis();
        axisY_spl->setRange(70, 95);
        axisY_spl->setTitleText("SPL (dB)");
        splChart->addAxis(axisY_spl, Qt::AlignLeft);
        sealedSplSeries->attachAxis(axisX_spl);
        sealedSplSeries->attachAxis(axisY_spl);
        ventedSplSeries->attachAxis(axisX_spl);
        ventedSplSeries->attachAxis(axisY_spl);

        QLogValueAxis *axisX_impedance = new QLogValueAxis();
        axisX_impedance->setBase(10.0);
        axisX_impedance->setLabelFormat("%g Hz");
        axisX_impedance->setRange(startFrequency, endFrequency);
        axisX_impedance->setTitleText("Frequenz");
        impedanceChart->addAxis(axisX_impedance, Qt::AlignBottom);

        QValueAxis *axisY_impedance = new QValueAxis();
        axisY_impedance->setRange(0, 100);
        axisY_impedance->setTitleText("Impedanz (Ohm)");
        impedanceChart->addAxis(axisY_impedance, Qt::AlignLeft);
        sealedImpedanceSeries->attachAxis(axisX_impedance);
        sealedImpedanceSeries->attachAxis(axisY_impedance);
        ventedImpedanceSeries->attachAxis(axisX_impedance);
        ventedImpedanceSeries->attachAxis(axisY_impedance);

        // Layout für zwei Diagramme
        QWidget* centralWidget = new QWidget();
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);
        layout->addWidget(new QChartView(splChart));
        layout->addWidget(new QChartView(impedanceChart));
        setCentralWidget(centralWidget);
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
