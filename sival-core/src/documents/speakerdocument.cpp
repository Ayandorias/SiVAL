/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QFile>
#include <QUuid>

#include <iostream>
//// end includes

//// begin system includes
#include <QDir>
#include <QFileInfo>
#include <QJsonDocument>
//// end system includes

//// begin project specific includes
#include "sivalcore/documents/speakerdocument.hpp"
#include <sivalcore/io/fileiohandler.hpp>
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
SpeakerDocument::~SpeakerDocument() {
}
SpeakerDocument* SpeakerDocument::create(const QString & filename) {
    SpeakerDocument *pd = new SpeakerDocument(filename, new FileIOHandler(filename));

    QFile file(":/config/settings/speaker.sivalspkr");
    if(file.open(QFile::ReadOnly | QFile::Text)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        std::cout << doc.toJson().toStdString() << std::endl;

        file.close();
    }

    return pd;
}
SpeakerDocument* SpeakerDocument::open(const QString &filename) {
    SpeakerDocument *pd = new SpeakerDocument(filename, new FileIOHandler(filename));
    pd->parse();
    return pd;
}
QSharedPointer<SiVAL::Engine::AcousticSetup> SpeakerDocument::createEnclosure(SiVAL::Engine::EnclosureType type) {
    QFileInfo info(m_filename);
    QString encfile = info.absolutePath() + QDir::separator() + "enclosures" + QDir::separator();
    QString uuid = QUuid::createUuid().toString(QUuid::WithoutBraces);
    encfile += uuid;
    QDir dir(encfile);
    if(!dir.exists()) {
        if(dir.mkpath(encfile)) {
            dir.mkpath(encfile + QDir::separator() + QString("driver"));
            encfile += QDir::separator() + QString("enclosure.sivalenc");
            QFile file(encfile);
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
               QJsonDocument doc = QJsonDocument::fromJson(sSettings()->standardFileValues(":/config/settings/enclosure_sealed.sivalenc"));
                QJsonObject obj = doc.object();
                obj["uuid"] = uuid;
                QDateTime dt = QDateTime::currentDateTime();
                obj["created_at"] = dt.toString("yyyy-MM-dd hh:mm:ss");
                doc.setObject(obj);
                file.write(doc.toJson());
                file.close();

                QJsonArray arr = m_object["enclosures"].toArray();
                QJsonObject enc;
                enc["uuid"] = uuid;
                enc["created_at"] = obj["created_at"].toString();
                arr.append(enc);
                m_object["enclosures"] = arr;
                save();
                m_setups.append(QSharedPointer<SiVAL::Engine::AcousticSetup>::create(std::make_shared<SiVAL::Engine::Environment>(), encfile.toStdString()));
            }
        }
    }
    emit changed();
    return m_setups.at(m_setups.count() - 1);
}
void SpeakerDocument::parse() {
    QJsonDocument doc = QJsonDocument::fromJson(m_handler->load());
    std::cout << doc.toJson().toStdString() << std::endl;
    m_object = doc.object();
    QFileInfo info(m_filename);

    if(m_object["enclosures"].isArray()) {
        QJsonArray arr = m_object["enclosures"].toArray();
        QString encfile = info.absolutePath() + QDir::separator() + "enclosures" + QDir::separator();
        std::cout << "200: " << encfile.toStdString() << std::endl;

        for(int i = 0; i < arr.count(); ++i) {
            QJsonValue val = arr.at(i);
            if(val.isObject()) {
                QJsonObject obj = val.toObject();
                QJsonValue uuid = obj["uuid"];
                if(uuid.isString()) {
                    QString fileuuid = encfile + uuid.toString() + QDir::separator() + "enclosure.sivalenc";
                    std::cout << "100: " << fileuuid.toStdString() << std::endl;

                    m_setups.append(QSharedPointer<SiVAL::Engine::AcousticSetup>::create(std::make_shared<SiVAL::Engine::Environment>(), fileuuid.toStdString()));
                }
            }
        }
    }
}
bool SpeakerDocument::save() {
    // TODO: Anlegen des Pfades, wenn nicht vorhanden und Speichern der Daten in der Datei.
    QJsonDocument doc(m_object);
    m_handler->save(doc.toJson());
    std::cout << "Speaker: " << doc.toJson().toStdString() << std::endl;
    return true;
}

int SpeakerDocument::damping() {
    QJsonDocument doc;
    doc.setObject(m_object);
    return static_cast<int>(m_object["damping"].toDouble());//m_object["damping"].toInteger();
}

void SpeakerDocument::setDamping(int damping) {
    m_object["damping"] = damping;
}

QVector<QSharedPointer<SiVAL::Engine::AcousticSetup>>& SpeakerDocument::enclosures() {
    return m_setups;
}
QString SpeakerDocument::name() {
    return m_object["speaker_name"].toString();
}
QString SpeakerDocument::type() {
    return m_object["type"].toString();
}

void SpeakerDocument::volume(double &volume, QString &unit) {
    QJsonObject obj = m_object["volume"].toObject();
    volume = obj["value"].toDouble();
    unit = obj["unit"].toString();
}

void SpeakerDocument::setVolume(double vol) {
    m_object["volume"] = vol;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
SpeakerDocument::SpeakerDocument(const QString &filename, AbstractIOHandler *handler)
    : SiVAL::Core::AbstractDocument(handler) {
    m_filename = filename;

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
}