/*
 * SiVAL Core
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
#include <QGuiApplication>
#include <QStandardPaths>
#include <QStyleHints>
#include <QJsonDocument>
#include <QJsonObject>

#include <iostream>
//// end system includes

//// begin project specific includes
#include "sivalcore/documents/settingsdocument.hpp"
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin static definitions
SiVAL::Core::SettingsDocument* SiVAL::Core::SettingsDocument::m_instance = nullptr;
//// end static definitions

//// begin static functions
//// end static functions

namespace SiVAL::Core {
//// begin public member methods
SettingsDocument::SettingsDocument(AbstractIOHandler *handler)
    :AbstractDocument(handler) {
    if (m_instance == nullptr) {
        m_instance = this;
    }

    m_project = new Project();
    m_system = new System();

    QByteArray data = m_handler->load();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    m_doc = doc.object();
    m_general = new General(m_doc["general"].toObject());
    m_lastProjectList = new LastProjectList(m_doc["projectlist"].toArray());
}

SettingsDocument::~SettingsDocument() {
    if (m_instance == this) {
        m_instance = nullptr;
    }

    delete m_general;
    delete m_project;
    delete m_system;
}

SettingsDocument* SettingsDocument::instance()
{
    return m_instance;
}

void SettingsDocument::parse() {

}

bool SettingsDocument::save() {
    m_doc["general"] = m_general->object();

    QJsonDocument doc;
    doc.setObject(m_doc);
    m_handler->save(doc.toJson());

    return true;
}

bool SettingsDocument::saveLastProject() {

    QJsonDocument doc;
    m_doc["projectlist"] = m_lastProjectList->array();
    doc.setObject(m_doc);
    m_handler->save(doc.toJson());

    return true;
}

QString SettingsDocument::projectPath() {
    return QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
}

QString SettingsDocument::theme() {
    QString theme = themeSelect();

    if(theme == "light") { return "light"; }
    else if(theme == "dark") { return "dark"; }
    else {
        Qt::ColorScheme scheme = QGuiApplication::styleHints()->colorScheme();
        if (scheme == Qt::ColorScheme::Dark) {
            return "dark";
        } else {
            return "light";
        }
    }

    return theme;
}

QString SettingsDocument::author(){
    return m_general->author();
}
void SettingsDocument::setAuthor(const QString &author) {
    m_general->setAuthor(author);
}

bool SettingsDocument::autoSave() {
    return m_general->autoSave();
}
void SettingsDocument::setAutoSave(bool autosave) {
    m_general->setAutoSave(autosave);
}

int SettingsDocument::autoSaveTime() {
    return m_general->autoSaveTime();
}
void SettingsDocument::setAutoSaveTime(int min) {
    m_general->setAutoSaveTime(min);
}

QString SettingsDocument::company() {
    return m_general->company();
}
void SettingsDocument::setCompany(const QString &company) {
    m_general->setCompany(company);
}

QString SettingsDocument::themeSelect() {
    return m_general->currentTheme();
}

void SettingsDocument::setThemeSelect(const QString &theme) {
    m_general->setCurrentTheme(theme);
}

int SettingsDocument::lastProjectCount() {
    return m_general->lastProjectCount();
}
void SettingsDocument::setLastProjectCount(int count) {
    m_general->setLastProjectCount(count);
}

bool SettingsDocument::openLastProject() {
    return m_general->openLastProject();
}
void SettingsDocument::setOpenLastProject(bool open) {
    m_general->setOpenLastProject(open);
}

bool SettingsDocument::showSplashScreen() {
    return m_general->showSplashScreen();
}
void SettingsDocument::setShowSplashScreen(bool show) {
    m_general->setShowSplashScreen(show);
}

QStringList SettingsDocument::lastProjects() {
    QStringList stringList;
    QJsonArray jsonArray = m_lastProjectList->array();
    stringList.reserve(jsonArray.size());

    for (const QJsonValue &value : jsonArray) {
        stringList.append(value.toString());
    }

    return stringList;
}

void SettingsDocument::addProject(const QString &project) {
    m_lastProjectList->add(project);
    saveLastProject();
}

void SettingsDocument::addSpeaker(SiVAL::Core::SpeakerDocument *doc) {
    m_speakerList.append(doc);
}

SiVAL::Core::SpeakerDocument* SettingsDocument::speaker(int pos) {
    return m_speakerList.at(pos);
}

int SettingsDocument::speakerCount() {
    return m_speakerList.size();
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
