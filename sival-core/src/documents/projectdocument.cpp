/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QJsonDocument>
#include <QUuid>
#include <iostream>
//// end system includes

//// begin project specific includes
#include <sivalcore/io/fileiohandler.hpp>
#include "sivalcore/documents/projectdocument.hpp"
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
/**************************************************************************************************/
/**
 *
 */
ProjectDocument::~ProjectDocument() {
}
ProjectDocument* ProjectDocument::create(const QString & filename) {
    return new ProjectDocument(filename, new FileIOHandler(filename));
}
ProjectDocument* ProjectDocument::open(const QString &filename) {
    ProjectDocument *pd = new ProjectDocument(filename, new FileIOHandler(filename));
    pd->parse();
    return pd;
}
void ProjectDocument::parse() {
    QJsonDocument doc = QJsonDocument::fromJson(m_handler->load());
    m_object = doc.object();
    QStringList list = speakerFiles();
    QFileInfo info(filename());
    for(int i = 0; i < list.count(); ++i) {

        std::cout << "inträge in prj datei: " << list.at(i).toStdString() << std::endl;
        QString filename = info.absolutePath() + QDir::separator() + "speaker" + QDir::separator() + list.at(i) + QDir::separator() + QString("speaker.sivalspkr");
        QFile file(filename);
        if(file.exists()) {
            std::cout << "Datei existiert: " << filename.toStdString() << std::endl;
            SpeakerDocument *sd = SpeakerDocument::open(filename);
            connect(sd, &SpeakerDocument::changed, this, &ProjectDocument::changed);
            m_speakerList.append(sd);
        }
    }
}
bool ProjectDocument::save() {
    // TODO: Anlegen des Pfades, wenn nicht vorhanden und Speichern der Daten in der Datei.
    QJsonDocument doc(m_object);
    m_handler->save(doc.toJson());

    QFileInfo info(filename());
    QString path = info.absolutePath();
    // Subfolder for all Speakers in the project
    path += QDir::separator() + QString("speaker");
    std::cout << "Speicherort" << path.toStdString() << std::endl;
    QDir dir(path);
    if(!dir.exists()) {
        dir.mkpath(path);
    }

    for(int i = 0; i < m_speakerList.count(); ++i) {
        SpeakerDocument *doc = m_speakerList.at(i);
        doc->save();
    }
    return true;
}
void ProjectDocument::setAuthor(const QString &author) {
    m_object["author"] = author;
    emit changed();
}
QString ProjectDocument::author() {
    return m_object["author"].toString();
}
void ProjectDocument::setCreateDate(const QString &date) {
    m_object["created_at"] = date;
    emit changed();
}
QString ProjectDocument::createDate() {
    return m_object["created_at"].toString();
}
void ProjectDocument::setDescription(const QString &desc) {
    m_object["description"] = desc;
    emit changed();
}
QString ProjectDocument::description() {
    return m_object["description"].toString();
}
QString ProjectDocument::filename() {
    return m_filename;
}
void ProjectDocument::setGrossVolume(const double &volume, const QString &unit) {
    QJsonObject obj;
    obj["value"] = volume;
    obj["unit"] = unit;

    m_object["gross_volume"] = obj;
    emit changed();
}
void ProjectDocument::grossVolume(double &volume, QString &unit) {
    QJsonObject obj = m_object["gross_volume"].toObject();
    volume = obj["value"].toDouble();
    unit = obj["unit"].toString();
}
void ProjectDocument::setProjectId(const QString &id) {
    m_object["project_id"] = id;
    emit changed();
}
QString ProjectDocument::projectId() {
    return m_object["project_id"].toString();
}
void ProjectDocument::setProjectName(const QString &name) {
    m_object["project_name"] = name;
    emit changed();
}
QString ProjectDocument::projectName() {
    return m_object["project_name"].toString();
}

SpeakerDocument *ProjectDocument::createSpeaker(const QString &name) {
    QJsonDocument doc;
    SpeakerDocument *spkr = nullptr;

    QFile file(":/config/settings/speaker.sivalspkr");
    if(file.open(QFile::ReadOnly | QFile::Text)) {
        doc = QJsonDocument::fromJson(file.readAll());
    }
    QString uuid = QUuid::createUuid().toString(QUuid::WithoutBraces);
    QJsonObject obj = doc.object();
    obj["speaker_id"] = uuid;
    obj["speaker_name"] = name;
    QDateTime dt = QDateTime::currentDateTime();
    obj["created_at"] = dt.toString("yyyy-MM-dd hh:mm:ss");


    QFileInfo info(filename());
    QString filename = info.absolutePath() + QDir::separator() + "speaker" + QDir::separator() + uuid;
    QDir dir(filename);
    if(!dir.exists()) {
        dir.mkpath(filename);
    }

    filename += QDir::separator() + QString("speaker.sivalspkr");
    QFile jf(filename);
    if(jf.open(QFile::WriteOnly | QFile::Text)) {
        doc.setObject(obj);
        jf.write(doc.toJson());
        jf.close();
        spkr = SpeakerDocument::open(filename);
        m_speakerList.append(spkr);

        QJsonArray arr = m_object["speaker"].toArray();
        QJsonObject objspr;
        objspr["speaker_id"] = uuid;
        arr.append(objspr);
        m_object["speaker"] = arr;
        save();
    }


    emit changed();

    return spkr;
}
QVector<SpeakerDocument*>& ProjectDocument::speakerList() {
    return m_speakerList;
}
void ProjectDocument::setVersion(float version) {
    m_object["version"] = version;
    emit changed();
}
float ProjectDocument::version() {
    return m_object["version"].toDouble();
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
ProjectDocument::ProjectDocument(const QString &filename, AbstractIOHandler *handler)
    : SiVAL::Core::AbstractDocument(handler) {
    m_filename = filename;

}
//// end protected member methods (internal use only)

//// begin private member methods
QStringList ProjectDocument::speakerFiles() {
    QStringList list;
    QJsonArray arr = m_object["speaker"].toArray();
    for (const QJsonValue &value : arr) {
        if(value.isObject()) {
            std::cout << "hier kommt ein Object" << std::endl;
            QJsonObject obj = value.toObject();
            list.append(obj["speaker_id"].toString());
        }
        // if (value.isString()) {
        //     list.append(value.toString());
        // }
    }
    return list;
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
}
