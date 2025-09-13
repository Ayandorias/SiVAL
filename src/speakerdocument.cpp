/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDir>
#include <iostream>
//// end includes

//// begin specific includes
#include "settingsdocument.hpp"
#include "speakerdocument.hpp"
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
SpeakerDocument::SpeakerDocument() {

}
SpeakerDocument::SpeakerDocument(QJsonObject obj) {
    QString man = obj["manufacturer"].toString().toLower();
    QString uuid = obj["uuid"].toString();

    SettingsDocument *doc = SettingsDocument::instance();
    QString filename = doc->speakerPath() + QDir::separator() + man + QDir::separator() + uuid + QString(".json");
    open(filename);
}
SpeakerDocument::SpeakerDocument(const SpeakerDocument &doc)
    :IDocument() {
    m_Object = doc.m_Object;
    m_bChanged = doc.m_bChanged;
    m_iType = doc.m_iType;
}
/**************************************************************************************************/
/**
 *
 */
SpeakerDocument::SpeakerDocument(const QString &filename)
    :IDocument(filename) {

    std::cout << filename.toStdString() << std::endl;
}

/**************************************************************************************************/
/**
 *
 */
SpeakerDocument::~SpeakerDocument() {
}

QString SpeakerDocument::brand() {
    return m_Object["brand"].toString();
}
QString SpeakerDocument::manufacturer() {
    return m_Object["manufacturer"].toString();
}
QString SpeakerDocument::model() {
    return m_Object["model"].toString();
}
QString SpeakerDocument::uuid() {
    return m_Object["uuid"].toString();
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void SpeakerDocument::read() {

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
