#if 1
#include "mainwindow.hpp"

#include <QStandardPaths>
#include <sivalcore/io/settingsiohandler.hpp>
#include <QApplication>
#include <QFile>

#include "version.hpp"

int main(int argc, char *argv[])
{
    SiVAL::Core::SettingsDocument doc(SiVAL::Core::SettingsIOHandler::createInstance("settings.sival"));
    QApplication a(argc, argv);

    // UND die Anwendung kann das Theme laden:
    QFile file(":/sival/" + doc.theme() + "/" + doc.theme() + ".qss");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        a.setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }


    SiVAL::MainWindow w;
    w.show();
    return a.exec();
}

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
