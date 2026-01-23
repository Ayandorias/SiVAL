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

    SiVAL::Core::SettingsDocument doc(SiVAL::Core::SettingsIOHandler::createInstance("settings.sival"));

    doc.addProject("hallo");
    doc.addProject("hallo");
    doc.addProject("hallo");
    doc.addProject("hallo");
    doc.addProject("hallo");
    doc.addProject("hallo");
    doc.addProject("hallo");
    doc.addProject("hallo");
    doc.addProject("hallo");
    doc.addProject("hallo");
    QSplashScreen *splash = nullptr;

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
        SiVAL::Core::SpeakerDocument spkr(new SiVAL::Core::FileIOHandler("/usr/share/sival/chassis/speakers.json"));

        QObject::connect(&spkr, &SiVAL::Core::SpeakerDocument::status, splash, [splash](const QString &msg) {
            splash->showMessage(msg, Qt::AlignBottom | Qt::AlignCenter, Qt::white);
        });
        splash->show();
        splash->showMessage(QCoreApplication::translate("splash", "Initialize Speakers ...", nullptr), Qt::AlignBottom | Qt::AlignCenter, Qt::white);

        spkr.processing();
    }

    // Loading theme for the application
    QFile file(":/sival/" + doc.theme() + "/" + doc.theme() + ".qss");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        a.setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }

    SiVAL::PM::ProjectManager w;
    if(splash) {
        splash->finish(&w);
    }
    w.show();
    return a.exec();
}





#if 0

#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QMainWindow>
#include <QDebug>

/**
 * Die Klasse ChronikLeser verkörpert die diskrete Logik des Einlesevorgangs.
 * Sie ist darauf ausgelegt, Informationen über ihren Zustand nach außen zu senden,
 * ohne Kenntnis über die Beschaffenheit der Empfänger zu besitzen.
 */
class ChronikLeser : public QObject {
    Q_OBJECT
public:
    explicit ChronikLeser(QObject *parent = nullptr) : QObject(parent) {}

    void verarbeite(const QString &dateipfad) {
        QFile datei(dateipfad);

        // Simulation: Prüfung der Existenz, bevor der Prozess beginnt
        if (!datei.open(QIODevice::ReadOnly | QIODevice::Text)) {
            emit fehlerGemeldet("Die Chronik-Datei konnte nicht geöffnet werden.");
            return;
        }

        QTextStream in(&datei);
        int zeilenZaehler = 0;

        while (!in.atEnd()) {
            in.readLine();
            zeilenZaehler++;

            // Jede zehnte Zeile wird dem System gemeldet
            // if (zeilenZaehler % 10 == 0) {
                QString status = QString("Dokument %1 wird katalogisiert...").arg(zeilenZaehler);
                emit fortschrittAktualisiert(status);

                // Ein kurzes Verweilen zur Wahrung der Stabilität und Sichtbarkeit
                QThread::msleep(5);

                // Erlaubt der grafischen Oberfläche das notwendige Neuzeichnen
                QCoreApplication::processEvents();
            // }
        }
        emit verarbeitungBeendet();
    }

signals:
    void fortschrittAktualisiert(const QString &nachricht);
    void fehlerGemeldet(const QString &fehler);
    void verarbeitungBeendet();
};

/**
 * Die Hauptfunktion steuert die zeitliche Abfolge und die Bedingung
 * der Darstellung des Splashscreens.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Hier könnte die Abfrage der Einstellungen (Settings) erfolgen
    bool zeigeSplash = true;

    QPixmap pixmap(":/splash/splash"); // Pfad zur Bildressource
    QSplashScreen *splash = nullptr;

    if (zeigeSplash) {
        splash = new QSplashScreen(pixmap);
        splash->show();
        splash->showMessage("System wird initialisiert...", Qt::AlignBottom | Qt::AlignCenter, Qt::white);
        QCoreApplication::processEvents();
    }

    // Erschaffung des ChronikLesers
    ChronikLeser leser;

    // Verbindung der Logik mit der Anzeige, sofern diese existiert
    if (splash) {
        QObject::connect(&leser, &ChronikLeser::fortschrittAktualisiert, splash, [splash](const QString &msg) {
            splash->showMessage(msg, Qt::AlignBottom | Qt::AlignCenter, Qt::white);
        });
    }

    // Der Prozess des Einlesens wird gestartet
    leser.verarbeite("/usr/share/sival/chassis/speakers.json");

    // Sicherstellung der geforderten Mindestverweildauer von 2 Sekunden
    // Dies geschieht nach der Verarbeitung, falls diese schneller war.
    // QThread::sleep(1);

    // Übergang zum Hauptfenster
    QMainWindow hauptFenster;
    hauptFenster.setWindowTitle("Archiv der Aufzeichnungen");
    hauptFenster.resize(800, 600);

    if (splash) {
        splash->finish(&hauptFenster);
        delete splash;
    }

    hauptFenster.show();

    return app.exec();
}

#include "main.moc" // Notwendig für die Meta-Objekt-Kompilierung in einer einzelnen Datei


#endif
