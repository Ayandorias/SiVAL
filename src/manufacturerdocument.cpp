/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <iostream>
//// end includes

//// begin specific includes
#include <QJsonArray>
#include "manufacturerdocument.hpp"
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
 * @brief ManufacturerDocument::ManufacturerDocument
 * @param filename
 */
ManufacturerDocument::ManufacturerDocument(const QString &filename)
    :IDocument(filename) {

    read();
}
/**************************************************************************************************/
/**
 * @brief ManufacturerDocument::~ManufacturerDocument
 */
ManufacturerDocument::~ManufacturerDocument() {
}
/**
 * @brief ManufacturerDocument::save
 * @return
 */
bool ManufacturerDocument::save() {
    QJsonArray man_arr;
    for(SpeakerManufacturer *man : m_ManufacturerList) {
        QJsonObject obj;
        obj["manufacturer"] = man->name();
        obj["indexed"] = man->isIndexed();
        QJsonArray list;
        for(QString entry : man->chassisList()) {
            list.append(entry);
        }
        obj["uuids"] = list;
        man_arr.append(obj);
    }
    QJsonObject obj;
    obj["manufacturers"] = man_arr;
    m_Object = obj;
    return IDocument::save();
}
/**
 * @brief ManufacturerDocument::import
 * @param obj
 */
void ManufacturerDocument::import(const QString &filename) {

}
/**
 * @brief ManufacturerDocument::manufacturers
 * @return
 */
QVector<SpeakerManufacturer*>& ManufacturerDocument::manufacturers() {
    return m_ManufacturerList;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
/**
 * @brief ManufacturerDocument::read
 */
void ManufacturerDocument::read() {
    QJsonArray man = m_Object["manufacturers"].toArray();

    for (const QJsonValue &value : man) {
        if (value.isString()) {
            qDebug() << "Gefundener String:" << value.toString();
        } else if (value.isDouble()) {
            qDebug() << "Gefundene Zahl:" << value.toDouble();
        } else if (value.isBool()) {
            qDebug() << "Gefundener boolescher Wert:" << value.toBool();
        } else if (value.isObject()) {
            // Bei einem Objekt kann man es weiter verarbeiten
            QString manufacturer = value.toObject()["manufacturer"].toString();
            bool indexed = value.toObject()["indexed"].toBool();

            QStringList list;
            QJsonArray uuids = value.toObject()["uuids"].toArray();
            for(const QJsonValue &uuid: uuids) {
                list << uuid.toString();
            }
            SpeakerManufacturer *m = new SpeakerManufacturer(manufacturer, indexed, list);
            m_ManufacturerList.append(m);
        } else {
            qDebug() << "Gefundener unbekannter Typ.";
        }
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
