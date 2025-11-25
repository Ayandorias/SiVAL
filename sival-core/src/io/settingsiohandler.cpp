/*
 * SiVAL Core
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDir>
#include <QStandardPaths>

#include <iostream>
//// end includes

//// begin system includes
//// end system includes

//// begin project specific includes
#include "sivalcore/io/settingsiohandler.hpp"
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin static definitions
//// end static definitions

//// begin static functions
//// end static functions

namespace SiVAL::Core {
//// begin public member methods
SettingsIOHandler* SettingsIOHandler::createInstance(const QString& filename)
{
    // Hier wird die Instanz erzeugt.
    // Man könnte hier auch Singleton-Logik einbauen, wenn gewünscht.
    SettingsIOHandler *handler = new SettingsIOHandler(filename);
    return handler;
}

SettingsIOHandler::~SettingsIOHandler() {
}

bool SettingsIOHandler::load(AbstractDocument *doc) {
    QString userFilePath = getUserFilePath();
    std::cout << userFilePath.toStdString() << std::endl;

    QFile userFile(userFilePath + QDir::separator() + m_filename);

    // SCHRITT 1: Prüfen, ob User-Datei existiert
    if (userFile.exists()) {
        if (userFile.open(QIODevice::ReadOnly)) {
            std::cout << "Lade User-Settings von:" << userFilePath.toStdString() << std::endl;

            QByteArray data = userFile.readAll();
            userFile.close();

            // HIER SPÄTER: Daten an SettingsDocument übergeben
            // parseData(data);

            return true;
        }
    }

    // SCHRITT 2: Fallback auf Default (Ressourcen)
    std::cout << "User-Datei nicht gefunden. Lade Defaults." << std::endl;

    // Wir bauen den Pfad zur Ressource.
    // Annahme: Die Datei heißt in der qrc "default_" + dein Dateiname
    // Oder fest: ":/config/default_settings.sival"
    QString resourcePath = ":/config/settings/default_" + m_filename;

    QFile defaultFile(resourcePath);
    if (defaultFile.open(QIODevice::ReadOnly)) {
        QByteArray defaultData = defaultFile.readAll();
        defaultFile.close();

        // HIER SPÄTER: Daten an SettingsDocument übergeben
        // parseData(defaultData);

        // SCHRITT 3: Sofortiges Speichern (Datei anlegen)
        std::cout << "Erstelle initiale User-Datei..." << std::endl;
        save(doc);

        return true;
    } else {
        std::cout << "FEHLER: Weder User-Datei noch Default-Ressource gefunden:" << resourcePath.toStdString() << std::endl;
        return false;
    }
}

bool SettingsIOHandler::save(AbstractDocument *doc) {
    QString userFilePath = getUserFilePath();
    QFile file(userFilePath + QDir::separator() + m_filename);

    if (file.open(QIODevice::WriteOnly)) {
        file.write("Hallo Welt");
        // HIER SPÄTER: Daten aus SettingsDocument holen
        // QByteArray data = serializeData();

        // DUMMY: Wir schreiben erst mal das, was wir (theoretisch) im Speicher haben
        // file.write(data);

        std::cout << "Settings gespeichert unter:" << std::endl;
        file.close();
        return true;
    }

    return false;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
SettingsIOHandler::SettingsIOHandler(const QString & filename)
    :AbstractIOHandler(filename) {
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);

    std::cout << configPath.toStdString() << ": " << m_filename.toStdString() << std::endl;
}

QString SettingsIOHandler::getUserFilePath() const
{
    // Speicherort: AppConfigLocation (z.B. AppData/Local/SiVAL/)
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + QDir::separator() + QString("SiVAL");
    QDir dir(configPath);

    // Ordner erstellen, falls nicht existent
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    return dir.path();//filePath(m_filename); // z.B. ".../SiVAL/settings.sival"
}
//// end private member methods
}
