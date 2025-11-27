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
SettingsDocument::SettingsDocument(SettingsIOHandler *handler)
    :AbstractDocument(handler) {
    if (m_instance == nullptr) {
        m_instance = this;
    }

    m_general = new General();
    m_project = new Project();
    m_system = new System();

    m_handler->load(this);
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

void SettingsDocument::parse(const QString &doc) {

}

QString SettingsDocument::theme() {
    return "dark";
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
