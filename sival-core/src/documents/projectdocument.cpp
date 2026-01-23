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
#include <QJsonDocument>
#include <sivalcore/io/fileiohandler.hpp>

#include <iostream>
//// end system includes

//// begin project specific includes
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
}
bool ProjectDocument::save() {
    // TODO: Anlegen des Pfades, wenn nicht vorhanden und Speichern der Daten in der Datei.
    QJsonDocument doc(m_object);
    m_handler->save(doc.toJson());
    return true;
}
void ProjectDocument::setAuthor(const QString &author) {
    m_object["author"] = author;
}
QString ProjectDocument::author() {
    return m_object["author"].toString();
}
void ProjectDocument::setCreateDate(const QString &date) {
    m_object["created_at"] = date;
}
QString ProjectDocument::createDate() {
    return m_object["created_at"].toString();
}
void ProjectDocument::setDescription(const QString &desc) {
    m_object["description"] = desc;
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
}
void ProjectDocument::grossVolume(double &volume, QString &unit) {
    QJsonObject obj = m_object["gross_volume"].toObject();
    volume = obj["value"].toDouble();
    unit = obj["unit"].toString();
}
void ProjectDocument::setProjectId(const QString &id) {
    m_object["project_id"] = id;
}
QString ProjectDocument::projectId() {
    return m_object["project_id"].toString();
}
void ProjectDocument::setProjectName(const QString &name) {
    m_object["project_name"] = name;
}
QString ProjectDocument::projectName() {
    return m_object["project_name"].toString();
}
void ProjectDocument::setVersion(float version) {
    m_object["version"] = version;
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
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
}
