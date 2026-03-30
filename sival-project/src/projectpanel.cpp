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
//// end system includes

//// begin project specific includes
#include "projectpanel.hpp"
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

namespace SiVAL::PM {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
ProjectPanel::ProjectPanel(QWidget *parent)
    :Gui::NavigationWidget(parent) {

    m_header->setObjectName("projectHeader");
    m_header->setText("Hier kommt der Projektname hin!!!!");

    m_enclosurePanel = new ProjectSpeakerPanel(this);
    m_navStack->addWidget(m_enclosurePanel);

    m_propertyPanel = new ProjectPropertyPanel(this);
    m_navStack->addWidget(m_propertyPanel);


    setCurrentIndex(0);
}

/**************************************************************************************************/
/**
 *
 */
ProjectPanel::~ProjectPanel() {
}
void ProjectPanel::update(SiVAL::Core::ProjectDocument *doc) {
    m_header->setText(doc->projectName());
    m_enclosurePanel->update(doc);
    m_propertyPanel->update(doc);
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
