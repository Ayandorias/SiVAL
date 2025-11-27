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
#include <sivalgui/cardlist.hpp>
#include "settingsview.hpp"
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
SettingsView::SettingsView()
    :Gui::View() {
}

/**************************************************************************************************/
/**
 *
 */
SettingsView::~SettingsView() {
}
Gui::NavigationPanel* SettingsView::navigationPanel() {
    if(m_navBarPanel == nullptr) {
        Gui::CardList *l = new Gui::CardList();

        m_cardGeneral = new SiVAL::Gui::Card(nullptr);
        m_cardGeneral->setIcon(":/sival/" + sSettings()->theme() + "/general.svg");
        m_cardGeneral->setMinimumHeight(40);
        m_cardGeneral->setMaximumHeight(40);
        connect(m_cardGeneral, &SiVAL::Gui::Card::clicked, this, &SettingsView::general);
        l->addCard(m_cardGeneral);

        m_cardMouse = new SiVAL::Gui::Card(nullptr);
        m_cardMouse->setIcon(":/sival/" + sSettings()->theme() + "/mouse.svg");
        m_cardMouse->setMinimumHeight(40);
        m_cardMouse->setMaximumHeight(40);
        l->addCard(m_cardMouse);

        m_cardKeyboard = new SiVAL::Gui::Card(nullptr);
        m_cardKeyboard->setIcon(":/sival/" + sSettings()->theme() + "/keyboard.svg");
        m_cardKeyboard->setMinimumHeight(40);
        m_cardKeyboard->setMaximumHeight(40);
        l->addCard(m_cardKeyboard);

        m_cardEnclosure= new SiVAL::Gui::Card(nullptr);
        m_cardEnclosure->setIcon(":/sival/" + sSettings()->theme() + "/enclosure-fill.svg");
        m_cardEnclosure->setMinimumHeight(40);
        m_cardEnclosure->setMaximumHeight(40);
        l->addCard(m_cardEnclosure);

        m_cardAbout = new SiVAL::Gui::Card(nullptr);
        m_cardAbout->setIcon(":/sival/" + sSettings()->theme() + "/info.svg");
        m_cardAbout->setMinimumHeight(40);
        m_cardAbout->setMaximumHeight(40);
        connect(m_cardAbout, &SiVAL::Gui::Card::clicked, this, &SettingsView::about);
        l->addCard(m_cardAbout);

        m_navBarPanel = l;

        retranslate();
    }
    return m_navBarPanel;
}
QWidget* SettingsView::centerPanel() {
    if(m_centerPanel == nullptr) {
        m_centerPanel = new SiVAL::SettingsPanel();
    }
    return m_centerPanel;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SettingsView::retranslate() {
    if(m_navBarPanel != nullptr) {
        m_cardGeneral->setTitle(tr("General"));
        m_cardMouse->setTitle(tr("Mouse"));
        m_cardKeyboard->setTitle(tr("Keyboard"));
        m_cardEnclosure->setTitle(tr("Enclosure"));
        m_cardAbout->setTitle(tr("About"));
    }
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void SettingsView::about() {
    qobject_cast<SiVAL::SettingsPanel*>(m_centerPanel)->changePage(SiVAL::Settings::About);
}
void SettingsView::general() {
    qobject_cast<SiVAL::SettingsPanel*>(m_centerPanel)->changePage(SiVAL::Settings::General);
}
//// end protected slots

//// begin private slots
//// end private slots
}
