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

namespace SiVAL::PM{
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

    m_speaker = new SettingsSpeaker(this);
    m_navStack->addWidget(m_speaker);

    m_about = new SettingsAbout(this);
    m_navStack->addWidget(m_about);

    m_accept = new QPushButton(this);
    m_accept->setObjectName("buttonAccept");
    m_accept->setMinimumSize(120, 35);
    m_accept->setMaximumSize(120, 35);
    m_accept->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/check.svg"));
    connect(m_accept, &QPushButton::clicked, this, [this]() {
        sSettings()->save();
    });

    m_verticalLayout->addWidget(m_accept);
    retranslate();
}

/**************************************************************************************************/
/**
 *
 */
SettingsPanel::~SettingsPanel() {
}

void SettingsPanel::changePage(SiVAL::SettingsPanel settings) {
    m_navStack->setCurrentIndex(static_cast<int>(settings));
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SettingsPanel::retranslate() {
    m_header->setText(tr("General"));
    m_accept->setText(tr("Apply"));
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
