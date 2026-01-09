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

    std::cout << "Error: " << err.errorString().toStdString() << std::endl;
    std::cout << doc.toJson().toStdString() << std::endl;
    std::cout << data.toStdString() << std::endl;
    m_general = new General(doc["general"].toObject());
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
    QJsonObject obj;
    obj["general"] = m_general->object();

    QJsonDocument doc;
    doc.setObject(obj);
    m_handler->save(doc.toJson());


    return true;
}

QString SettingsDocument::author() {
    return QString("Bruno Pierucki");
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

QString SettingsDocument::themeSelect() {
    return m_general->currentTheme();
}

void SettingsDocument::setThemeSelect(const QString &theme) {
    m_general->setCurrentTheme(theme);
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
