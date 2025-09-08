/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QJsonArray>
#include <QUuid>
//// end includes

//// begin specific includes
#include "projectdocument.hpp"
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
/**
 *
{
    "version": 1.0,
    "project_id":"4b6c382f-5d41-47a8-8f9d-123456789abc",
    "project_name":"Lautsprecher-Testprojekt",
    "created_at":"2025-08-27T11:28:00Z",
    "author":"SiVAL",
    "description":"Die finale, vollständige Dokumentation für alle Gehäusekonstruktionen.",
    "total_volume_m3":0.050,
    "setups":[
        {
            "uuid":"a7b8c9d0-1e2f-3a4b-5c6d-7e8f9a0b1c2d",
            "frequency_step_percent": 0.5,
            "speaker":{
                "uuid":"76e932b7-0248-43d8-a8d6-413d33299719",
                "manufacturer": "Visaton",
                "quantity":1
            },
            "enclosures":[
                {
                    "type":"Sealed",
                    "volume_m3":0.050
                }
            ]
        },
        {
            "uuid":"b8c9d0e1-2f3a-4b5c-6d7e-8f9a0b1c2d3e",
            "speaker":{
                "uuid":"d0124f57-e6ae-4357-9d7a-773c33ce427a",
                "manufacturer": "Visaton",
                "quantity":1
            },
            "enclosures":[
                {
                    "type":"Vented",
                    "volume_m3":0.050,
                    "ports":[
                        {
                            "tuning_frequency_hz":40.0,
                            "length_mm":150.0,
                            "wall_thickness_mm": 5.0,
                            "shape":{
                                "type":"circular",
                                "diameter_mm":50.0
                            }
                        }
                    ]
                }
            ]
        }
    ]
}

 *
 */
ProjectDocument::ProjectDocument(const QString &filename)
    :IDocument(filename) {
    m_bChanged = false;

    read();
}

/**************************************************************************************************/
/**
 *
 */
ProjectDocument::~ProjectDocument() {
    for(int i = 0; i < m_Setups.size(); ++i) {
        EnclosureDocument *doc = m_Setups.at(i);
        delete doc;
    }
}


void ProjectDocument::setAuthor(const QString &author) {
    m_Object["author"] = author;
}
QString ProjectDocument::author() {
    return m_Object["author"].toString();
}
/**
 * @brief ProjectDocument::createEnclosure
 * @param doc The uuid of the apeaker
 */
void ProjectDocument::createEnclosure(SpeakerDocument *doc, SiVAL::ENCLOSURE_TYPE type) {
    m_Setups.append(new EnclosureDocument(*doc, type));
}
QString ProjectDocument::created() {
    return m_Object["created_at"].toString();
}
void ProjectDocument::setDescription(const QString &description) {
    m_Object["description"] = description;
}
QString ProjectDocument::description() {
    return m_Object["description"].toString();
}
void ProjectDocument::setName(const QString &prjname) {
    m_Object["project_name"] = prjname;
}
QString ProjectDocument::name() {
    return m_Object["project_name"].toString();
}
bool ProjectDocument::save() {
    return IDocument::save();
}
bool ProjectDocument::saveAs(const QString &filename) {
    return IDocument::saveAs(filename);
}
QString ProjectDocument::projectId() {
    return m_Object["project_id"].toString();
}
QString ProjectDocument::version() {
    return m_Object["version"].toString();
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void ProjectDocument::read() {
    QFile file(m_sFilename);

    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Fehler: Datei konnte nicht zum Lesen geöffnet werden.";
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError);

    m_Object = jsonDoc.object();
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
