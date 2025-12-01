#if 1
#include "mainwindow.hpp"

#include <QStandardPaths>
#include <sivalcore/io/settingsiohandler.hpp>
#include <QApplication>
#include <QFile>
// #include <QSplashScreen>
// #include <QPainter>
// #include <QThread>

int main(int argc, char *argv[])
{
    SiVAL::Core::SettingsDocument doc(SiVAL::Core::SettingsIOHandler::createInstance("settings.sival"));
    QApplication a(argc, argv);


    // Generating a SplachScreen for loadng the speaker information.
    // QString svgPath = ":/sival/logo/speaker.svg";
    // QSize splashSize(500, 300);
    // QPixmap pixmap(splashSize);
    // pixmap.fill(Qt::transparent);
    // QPainter painter(&pixmap);
    // painter.setRenderHint(QPainter::Antialiasing);
    // QSvgRenderer renderer(svgPath);
    // if (renderer.isValid()) {
    //     renderer.render(&painter);
    // } else {
    //     painter.setPen(Qt::red);
    //     painter.drawText(pixmap.rect(), Qt::AlignCenter, "SVG Fehler");
    // }
    // painter.end();
    // QSplashScreen splash(pixmap);
    // splash.setMask(pixmap.mask());

    // splash.show();




    // UND die Anwendung kann das Theme laden:
    QFile file(":/sival/" + doc.theme() + "/" + doc.theme() + ".qss");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        a.setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }


    SiVAL::MainWindow w;
    w.show();
    // splash.finish(&w);
    return a.exec();
}

#endif


#if 0


#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QHeaderView>
#include <QStatusBar>
#include <QDebug>

// =============================================================================
// Klasse: ChassisSelectTree
// Beschreibung: Implementiert die Logik für Checkboxen in Spalte 0 und
//               die "Alles Auswählen"-Funktion via Header-Klick.
// =============================================================================
class ChassisSelectTree : public QTreeWidget
{
    Q_OBJECT

public:
    explicit ChassisSelectTree(QWidget *parent = nullptr)
        : QTreeWidget(parent)
    {

    }



private slots:

};

// =============================================================================
// Hauptfenster
// =============================================================================
class DemoWindow : public QMainWindow
{
public:
    DemoWindow() {
        setWindowTitle("SiVAL Chassis Selector Demo");
        resize(500, 400);

        QWidget* central = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(central);

        // Instanz des Baums erstellen
        tree = new ChassisSelectTree(this);

        // Dummy-Daten hinzufügen
        tree->addChassisEntry("Visaton", 42, true);
        tree->addChassisEntry("Scan-Speak", 15);
        tree->addChassisEntry("Seas", 23);
        tree->addChassisEntry("Dayton Audio", 108);
        tree->addChassisEntry("Accuton", 8);
        tree->addChassisEntry("Morel", 12);
        tree->addChassisEntry("SB Acoustics", 35);
        tree->addChassisEntry("Wavecor", 19);

        layout->addWidget(tree);

        // Info-Label
        statusBar()->showMessage("Klicken Sie auf 'Auswahl' im Kopfbereich, um alle umzuschalten.");

        setCentralWidget(central);
    }

private:
    ChassisSelectTree* tree;
};

// =============================================================================
// Main
// =============================================================================
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Styling für bessere Sichtbarkeit der Header-Interaktion
    app.setStyleSheet(
        "QHeaderView::section {"
        "    background-color: #E5E5E5;"
        "    padding: 4px;"
        "    border: 1px solid #C5C5C5;"
        "}"
        "QHeaderView::section:hover {"
        "    background-color: #DADADA;" /* Visuelles Feedback beim Hover über Header */
        "}"
        );

    DemoWindow win;
    win.show();

    return app.exec();
}

// WICHTIG für Single-File-Qt-Projekte:
// Da wir Q_OBJECT in einer .cpp Datei nutzen, muss der MOC-Output hier inkludiert werden.
#include "main.moc"


#endif














































#if 0
// main.cpp - Beispielanwendung
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>

#include "sivalgui/diagramm.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    QWidget *centralWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    SiVAL::Gui::Diagramm *plot = new SiVAL::Gui::Diagramm();
    QLabel *statusLabel = new QLabel("Bewege die Maus über das Diagramm");

    layout->addWidget(plot);
    layout->addWidget(statusLabel);

    QObject::connect(plot, &SiVAL::Gui::Diagramm::mousePositionChanged, [statusLabel](QPointF pos) {
        statusLabel->setText(QString("Position: X = %1, Y = %2")
                                 .arg(pos.x(), 0, 'g', 5)
                                 .arg(pos.y(), 0, 'f', 2));
    });

    window.setCentralWidget(centralWidget);
    window.resize(800, 600);
    window.setWindowTitle("Logarithmisches Diagramm");
    window.show();

    return app.exec();
}
#endif





































#if 0

#pragma once

#include <QTreeWidget>

namespace SiVAL::GUI {

class ChassisSelectTree : public QTreeWidget
{
    //Q_OBJECT

public:
    explicit ChassisSelectTree(QWidget *parent = nullptr);
    virtual ~ChassisSelectTree() = default;

    // Fügt eine Zeile hinzu: Checkbox | Hersteller | Anzahl
    void addChassisEntry(const QString& manufacturer, int count, bool checked = false);

    // Liefert eine Liste der Hersteller, deren Checkbox aktiviert ist
    QStringList getSelectedManufacturers() const;
};

}

#endif


#if 0


#include "sival-gui/widgets/ChassisSelectTree.h"
#include <QHeaderView>

namespace SiVAL::GUI {

ChassisSelectTree::ChassisSelectTree(QWidget *parent)
    : QTreeWidget(parent)
{
    // 1. Grundkonfiguration der Spalten
    setColumnCount(3);
    setHeaderLabels({ tr("Auswahl"), tr("Hersteller"), tr("Anzahl") });

    // 2. Optische Anpassung
    setAlternatingRowColors(true); // Zur besseren Lesbarkeit
    setRootIsDecorated(false);     // Keine "Aufklapp"-Pfeile an der Seite
    setSelectionMode(QAbstractItemView::NoSelection); // Fokus liegt auf den Checkboxen

    // 3. Spaltenbreiten-Logik
    // Spalte 0 (Checkbox): Fest auf den Inhalt angepasst
    header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    // Spalte 1 (Hersteller): Dehnt sich aus
    header()->setSectionResizeMode(1, QHeaderView::Stretch);

    // Spalte 2 (Anzahl): Fest angepasst
    header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
}

void ChassisSelectTree::addChassisEntry(const QString& manufacturer, int count, bool checked)
{
    // Erstellt ein neues Item im Baum
    QTreeWidgetItem *item = new QTreeWidgetItem(this);

    // Spalte 0: Die Checkbox
    // Qt::ItemIsUserCheckable muss im Flag gesetzt sein (ist Standard)
    item->setCheckState(0, checked ? Qt::Checked : Qt::Unchecked);

    // Spalte 1: Hersteller
    item->setText(1, manufacturer);

    // Spalte 2: Anzahl (als String formatiert)
    item->setText(2, QString::number(count));

    // Zentrierung für die Anzahl sieht meist besser aus
    item->setTextAlignment(2, Qt::AlignCenter);
}

QStringList ChassisSelectTree::getSelectedManufacturers() const
{
    QStringList selected;

    // Durchlaufe alle Top-Level-Items
    for (int i = 0; i < topLevelItemCount(); ++i) {
        QTreeWidgetItem *item = topLevelItem(i);

        // Prüfe den Status der Checkbox in Spalte 0
        if (item->checkState(0) == Qt::Checked) {
            selected.append(item->text(1)); // Text aus Spalte 1 (Hersteller)
        }
    }

    return selected;
}

}


#endif
