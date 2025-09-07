/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <iostream>
//// end includes

//// begin specific includes
#include "speakermanufacturer.hpp"
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
SpeakerManufacturer::SpeakerManufacturer(const QString &name, bool indexed, QStringList chassisList)
    : m_sName(name), m_bIndexed(indexed), m_ChassisList(chassisList){

    init();
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
QVector<SpeakerDocument*> SpeakerManufacturer::speakerList() {
    return m_SpeakerList;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void SpeakerManufacturer::init() {
    SettingsDocument setdoc;
    QFileInfo fileInfo(setdoc.speakerDb());

    for(int i = 0; i < m_ChassisList.count(); ++i) {
        SpeakerDocument *doc = new SpeakerDocument(fileInfo.absolutePath() + QString(QDir::separator() + name().toLower() + QString(QDir::separator()) +  m_ChassisList.at(i) + QString(".json")));

        m_SpeakerList.append(doc);
    }
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
