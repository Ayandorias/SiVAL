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
#include "speakermanufacturer.hpp"
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
SpeakerManufacturer::SpeakerManufacturer(const QString &name, bool indexed, QStringList chassisList)
    : m_sName(name), m_bIndexed(indexed), m_ChassisList(chassisList){
    std::cout << "anzahl chassis: " << chassisList.count() << std::endl;
    std::cout << "anzahl chassis: " << m_ChassisList.count() << std::endl;
}

/**************************************************************************************************/
/**
 *
 */
SpeakerManufacturer::~SpeakerManufacturer() {
}
/**
 *
 */
QStringList SpeakerManufacturer::chassisList(){
    std::cout << "anzahl chassis: " << m_ChassisList.count() << std::endl;
    return m_ChassisList;
}
void SpeakerManufacturer::indexed(bool n) {
    m_bIndexed = n;
}
bool SpeakerManufacturer::isIndexed() {
    return m_bIndexed;
}
QString SpeakerManufacturer::name() {
    return m_sName;
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
