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
#include <QDir>
#include <QFile>
#include <QFileInfo>

#include <iostream>
//// end system includes

//// begin project specific includes
#include <sival/libsival.hpp>
#include <sival/components/driver/factory.hpp>
#include "sivalcore/documents/speakerdocument.hpp"
#include "sivalcore/generic/chassismanufacturer.hpp"
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
ChassisManufacturer::ChassisManufacturer(QJsonObject man, SpeakerDocument *doc) {
    m_manufacturer = man;
    m_doc = doc;
    parse();
}

/**************************************************************************************************/
/**
 *
 */
ChassisManufacturer::~ChassisManufacturer() {
}
QString ChassisManufacturer::name() {
    return m_manufacturer["manufacturer"].toString();
}
void ChassisManufacturer::parse() {
    QFileInfo info(m_doc->filename());
    QString path = info.absolutePath();

    path += QDir::separator() + name().toLower() + QDir::separator();
    QJsonArray arr = m_manufacturer["uuids"].toArray();
    for (const QJsonValue &value : arr) {
        QString p = path + value.toString();

        if(QFile::exists(p)) {
            SiVAL::Engine::Driver::Factory::create(SiVAL::Engine::DriverRole::WOOFER, p.toStdString());
            // Chassis *ch = new Chassis(p);
            // m_chassisList.append(ch);
        }
    }
}
void ChassisManufacturer::setChassisList(QJsonArray arr) {

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
