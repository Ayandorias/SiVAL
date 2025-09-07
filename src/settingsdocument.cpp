/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDir>
#include <QJsonArray>
#include <QStandardPaths>
#include <iostream>
//// end includes

//// begin specific includes
#include "settingsdocument.hpp"

//// end specific includes

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

//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
SettingsDocument::SettingsDocument()
    :IDocument(QString()) {

    QStringList list = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);

    QDir dir(list.at(0));

    if(!dir.exists(".SiVAL")) {
        dir.mkdir(".SiVAL");
    }
    dir.cd(".SiVAL");

    m_sSettingsPath = dir.absolutePath();
    m_sSpeakerPath = m_sSettingsPath + QString(QDir::separator()) + QString("speakerdb");
    m_sFilename = m_sSettingsPath + QString(QDir::separator()) + "settings.sival";
    QFile file(m_sFilename);
    if(file.exists()) {
        read();
    } else {
        create();
        save();
    }


}

/**************************************************************************************************/
/**
 *
 */
SettingsDocument::~SettingsDocument() {
}

QString SettingsDocument::projectDir() {
    return m_Object["project_dir"].toString();
}
QString SettingsDocument::speakerDb() {
    QString comp = m_sSpeakerPath + QString(QDir::separator()) + "speakers.json";
    return comp;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void SettingsDocument::create() {
    m_sSpeakerPath = m_sSettingsPath + QString(QDir::separator()) + QString("speakerdb");
    QDir dir(m_sSpeakerPath);
    if(!dir.exists()) {
        dir.mkdir(m_sSpeakerPath);
    }

    m_Object["autosave"] = false; // Unter Allgemeine Einstellungen
    QStringList list = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    m_Object["project_dir"] = list.at(0); // Unter Allgemeine Einstellungen
    m_Object["last_opened_prj"] = QJsonArray();
    m_Object["last_opend_wrk"] = QJsonArray();
    m_Object["open_last_workspace"] = false; // Unter Allgemeine Einstellungen
    m_Object["last_workspave"] = QString();
}
void SettingsDocument::read() {
    QFile file(m_sFilename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray json = file.readAll();
        file.close();
        QJsonDocument doc = QJsonDocument::fromJson(json);
        // std::cout << doc.toJson().toStdString() << std::endl;

        m_Object = doc.object();
    } else {
        // std::cout << "Kann die Datei: " << filename.toStdString() << " nicht öffnen" << std::endl;
    }
}
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
