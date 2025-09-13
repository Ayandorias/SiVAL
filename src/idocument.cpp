/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <iostream>
//// end includes

//// begin specific includes
#include "idocument.hpp"
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
IDocument::IDocument() {

}
/**************************************************************************************************/
/**
 *
 */
IDocument::IDocument(const QString &filename) {

    open(filename);
}

/**************************************************************************************************/
/**
 *
 */
IDocument::~IDocument() {
}

void IDocument::change() {
    m_bChanged = true;
}
bool IDocument::isChanged() {
    return m_bChanged;
}
void IDocument::open(const QString &filename) {
    m_sFilename = filename;
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
/**
 *
 */
bool IDocument::save() {
    QJsonDocument doc(m_Object);

    std::cout << "Einstellungen: " << m_sFilename.toStdString() << std::endl;

    QFile file(m_sFilename);
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
    qint64 res = file.write(doc.toJson());
    file.close();

    if(res > 0) {
        return true;
    } else {
        return false;
    }
}
bool IDocument::saveAs(const QString &filename) {
    m_sFilename = filename;
    return save();
}

int IDocument::type() {
    return m_iType;
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
