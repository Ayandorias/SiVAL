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
#include "settingspanel.hpp"
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

namespace SiVAL {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
SettingsPanel::SettingsPanel(QWidget *parent)
    :Gui::NavigationWidget(parent) {

    m_header->setObjectName("settingsHeader");

    m_general = new SettingsGeneral(this);
    m_navStack->addWidget(m_general);

    retranslate();
}

/**************************************************************************************************/
/**
 *
 */
SettingsPanel::~SettingsPanel() {
}

void SettingsPanel::changePage(SiVAL::Settings settings) {
    m_navStack->setCurrentIndex(static_cast<int>(settings));
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SettingsPanel::retranslate() {
    m_header->setText(tr("General"));
}
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
