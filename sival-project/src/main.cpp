#include "projectmanager.hpp"

#include <QStandardPaths>
#include <sivalcore/documents/settingsdocument.hpp>
#include <sivalcore/io/settingsiohandler.hpp>
#include <QApplication>
#include <QFile>
// #include <QSplashScreen>
// #include <QPainter>
// #include <QThread>

int main(int argc, char *argv[])
{
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


    SiVAL::Core::SettingsDocument doc(SiVAL::Core::SettingsIOHandler::createInstance("settings.sival"));
    // UND die Anwendung kann das Theme laden:
    QFile file(":/sival/" + doc.theme() + "/" + doc.theme() + ".qss");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        a.setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }

    SiVAL::PM::ProjectManager w;

    w.show();
    // splash.finish(&w);
    return a.exec();
}
