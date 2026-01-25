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
#include <QApplication>
#include <QJsonArray>
#include <QThread>

#include <iostream>
//// end system includes

//// begin project specific includes
#include "sivalcore/documents/speakerdocument.hpp"
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
SpeakerDocument::SpeakerDocument(AbstractIOHandler *handler)
    :AbstractDocument(handler) {
    QCoreApplication::processEvents();
}

/**************************************************************************************************/
/**
 *
 */
SpeakerDocument::~SpeakerDocument() {
    std::cout << __FILE__ << ":" << __FUNCTION__ << ":" << m_manufacturer.count() << "|" << m_manufacturer.size() << std::endl;

    for(ChassisManufacturer *man : m_manufacturer) {
        delete man;
    }
}
QString SpeakerDocument::filename() {
    return m_handler->filename();
}
void SpeakerDocument::parse() {
    m_speakerObject = m_doc.object();
    QJsonArray arr = m_speakerObject["manufacturers"].toArray();

    int i = 0;
    for (const QJsonValue &value : arr) {
        if (value.isObject()) {
            QJsonObject manufacturer = value.toObject();
            // Hier erfolgt die weitere Extraktion der Daten
            ChassisManufacturer *man = new ChassisManufacturer(manufacturer, this);
            m_manufacturer.append(man);
            std::cout << __FILE__ << ":" << __FUNCTION__ << ":" << m_manufacturer.count() << "|" << m_manufacturer.size() << std::endl;
            // man->setChassisList(manufacturer["uuids"].toArray());
            emit status(tr("Manufacturer: %1").arg(man->name()));
            QCoreApplication::processEvents();
            QThread::msleep(50);
        }
    }
    std::cout << __FILE__ << ":" << __FUNCTION__ << ":" << m_manufacturer.count() << "|" << m_manufacturer.size() << std::endl;
}
void SpeakerDocument::processing() {
    // QThread::msleep(25);
    emit status(tr("Loading speaker file..."));
    QThread::msleep(25);
    QCoreApplication::processEvents();
    QByteArray array = m_handler->load();
    QThread::msleep(500);


    emit status(tr("Parsing Speaker file..."));
    QCoreApplication::processEvents();
    if(array.isEmpty()) {
        emit error(tr("Error while parsing!"));
        QCoreApplication::processEvents();
        QThread::msleep(2000);
        return;
    }

    QJsonParseError err;
    m_doc = QJsonDocument::fromJson(array, &err);

    if(m_doc.isObject()) {
        parse();

    } else {
        emit error(tr("Parsing Error"));
        QCoreApplication::processEvents();
        QThread::msleep(2000);
    }

    QThread::msleep(25);
}

bool SpeakerDocument::save() {
    return true;
}

QVector<ChassisManufacturer*> SpeakerDocument::manufacturerList() {
    std::cout << __FILE__ << ":" << __FUNCTION__ << ":" << m_manufacturer.count() << "|" << m_manufacturer.size() << std::endl;
    return m_manufacturer;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
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
