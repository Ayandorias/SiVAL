#include "projectmanager.hpp"

#include <QStandardPaths>
#include <sivalcore/documents/settingsdocument.hpp>
#include <sivalcore/documents/speakerdocument.hpp>
#include <sivalcore/io/fileiohandler.hpp>
#include <sivalcore/io/settingsiohandler.hpp>
#include <QApplication>
#include <QFile>

#include <QSplashScreen>
#include <QPainter>
#include <QThread>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Holt alle Parameter als Liste von Strings
    QStringList args = QCoreApplication::arguments();

    // args[0] ist immer der Pfad zum Programm selbst
    // Ab args[1] kommen deine eigenen Parameter
    for (int i = 1; i < args.size(); ++i) {
        std::cout << "Parameter" << i << ":" << args.at(i).toStdString() << std::endl;
    }


    SiVAL::Core::SettingsDocument doc(SiVAL::Core::SettingsIOHandler::createInstance("settings.sival"));

    QSplashScreen *splash = nullptr;

    SiVAL::Core::SpeakerDocument *spkr = nullptr;
    if(doc.showSplashScreen()) {
        // Generating a SplachScreen for loadng the speaker information.
        QString svgPath = ":/splash/splash";
        QSize splashSize(350, 350);
        QPixmap pixmap(splashSize);
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        QSvgRenderer renderer(svgPath);
        if (renderer.isValid()) {
            renderer.render(&painter);
        } else {
            painter.setPen(Qt::red);
            painter.drawText(pixmap.rect(), Qt::AlignCenter, "SVG Fehler");
        }
        painter.end();
        splash = new QSplashScreen(pixmap);
        splash->setMask(pixmap.mask());

        // Hier mehrere Dinge prüfen, für die SiVAL-ADH Bibliothek
        spkr = new SiVAL::Core::SpeakerDocument(new SiVAL::Core::FileIOHandler("/usr/share/sival/chassis/speakers.json"));
        doc.addSpeaker(spkr);

        QObject::connect(spkr, &SiVAL::Core::SpeakerDocument::status, splash, [splash](const QString &msg) {
            splash->showMessage(msg, Qt::AlignBottom | Qt::AlignCenter, Qt::white);
        });
        splash->show();
        splash->showMessage(QCoreApplication::translate("splash", "Initialize Speakers ...", nullptr), Qt::AlignBottom | Qt::AlignCenter, Qt::white);

        spkr->processing();
    }

    // Loading theme for the application
    QFile file(":/sival/" + doc.theme() + "/" + doc.theme() + ".qss");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        a.setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }

    QString project = QString();
    if(args.count() > 1) {
        project = args.at(1);
    } else {
        if(sSettings()->openLastProject()) {
            project = sSettings()->lastProject();
        }
    }
    SiVAL::PM::ProjectManager w(project);
    if(splash) {
        splash->finish(&w);
    }
    w.show();
    return a.exec();
}
