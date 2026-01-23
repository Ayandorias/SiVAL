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
#include <iostream>
//// end system includes

//// begin project specific includes
#include "sivalcore/settings/general.hpp"
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
General::General(QJsonObject obj)
    :QObject() {

    if(obj["theme"].isString()) {
        m_object["theme"] = obj["theme"].toString();
    } else {
        m_object["theme"] = "auto";
    }

    if(obj["splash"].isBool()) {
        m_object["splash"] = obj["splash"].toBool();
    } else {
        m_object["splash"] = false;
    }

    if(obj["open_last_project"].isBool()) {
        m_object["open_last_project"] = obj["open_last_project"].toBool();
    } else {
        m_object["open_last_project"] = false;
    }
    if(obj["last_project_count"].isDouble()) {
        m_object["last_project_count"] = obj["last_project_count"].toInteger();
    } else {
        m_object["last_project_count"] = 10;
    }

    if(obj["autosave"].isBool()) {
        m_object["autosave"] =obj["autosave"].toBool();
    } else {
        m_object["autosave"] = false;
    }

    if(obj["autosave_time"].isDouble()) {
        m_object["autosave_time"] =obj["autosave_time"].toInteger();
    } else {
        m_object["autosave_time"] = 5;
    }

    if(obj["author"].isString()) {
        m_object["author"] = obj["author"].toString();
    } else {
        m_object["author"] = QString();
    }

    if(obj["company"].isString()) {
        m_object["company"] = obj["company"].toString();
    } else {
        m_object["company"] = QString();
    }
}
/**************************************************************************************************/
/**
 *
 */
General::~General() {
}

QJsonObject General::object() {
    return m_object;
}

QString General::author(){
    return m_object["author"].toString();
}
void General::setAuthor(const QString &author) {
    m_object["author"] = author;
}

bool General::autoSave() {
    return m_object["autosave"].toBool();
}
void General::setAutoSave(bool autosave){
    m_object["autosave"] = autosave;
}

int General::autoSaveTime(){
    return m_object["autosave_time"].toInteger();
}
void General::setAutoSaveTime(int min){
    m_object["autosave_time"] = min;
}

QString General::company() {
    return m_object["company"].toString();
}
void General::setCompany(const QString &company) {
    m_object["company"] = company;
}

QString General::currentTheme() {
    return m_object["theme"].toString();
}
void General::setCurrentTheme(const QString &theme) {
    m_object["theme"] = theme;
}

int General::lastProjectCount() {
    return m_object["last_project_count"].toInteger();
}
void General::setLastProjectCount(int count) {
    m_object["last_project_count"] = count;
}

bool General::openLastProject() {
    return m_object["open_last_project"].toBool();
}
void General::setOpenLastProject(bool open) {
    m_object["open_last_project"] = open;
}

bool General::showSplashScreen() {
    return m_object["splash"].toBool();
}
void General::setShowSplashScreen(bool enable) {
    m_object["splash"] = enable;
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
