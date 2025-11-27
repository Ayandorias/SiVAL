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
// #include <sivalcore/sivalglobal.hpp>
//// end system includes

//// begin project specific includes
#include "startview.hpp"
#include <sivalgui/cardlist.hpp>
#include <startpanel.hpp>
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
StartView::StartView()
    :Gui::View() {
}

StartView::~StartView() {
}

Gui::NavigationPanel* StartView::navigationPanel() {
    if(m_navBarPanel == nullptr) {
        Gui::CardList *l = new Gui::CardList();

        m_cardNew = new Gui::Card();
        m_cardNew->setMinimumHeight(40);
        m_cardNew->setMaximumHeight(40);
        l->addCard(m_cardNew);

        m_cardOpen = new Gui::Card();
        m_cardOpen->setMinimumHeight(40);
        m_cardOpen->setMaximumHeight(40);
        l->addCard(m_cardOpen);

        m_cardSave = new Gui::Card();
        m_cardSave->setMinimumHeight(40);
        m_cardSave->setMaximumHeight(40);
        l->addCard(m_cardSave);

        m_cardSaveAs = new Gui::Card();
        m_cardSaveAs->setMinimumHeight(40);
        m_cardSaveAs->setMaximumHeight(40);
        l->addCard(m_cardSaveAs);

        m_navBarPanel = l;
        retranslate();
    }
    return m_navBarPanel;
}

QWidget* StartView::centerPanel() {
    if(m_centerPanel == nullptr) {
        m_centerPanel = new SiVAL::StartPanel();
    }
    return m_centerPanel;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void StartView::retranslate() {
    if(m_navBarPanel != nullptr) {
        m_cardNew->setTitle(tr("New..."));
        m_cardOpen->setTitle(tr("Open..."));
        m_cardSave->setTitle(tr("Save"));
        m_cardSaveAs->setTitle(tr("Save as"));

        m_cardNew->setIcon(":/sival/" + sSettings()->theme() + "/new.svg");
        m_cardOpen->setIcon(":/sival/" + sSettings()->theme() + "/open.svg");
        m_cardSave->setIcon(":/sival/" + sSettings()->theme() + "/save.svg");
        m_cardSaveAs->setIcon(":/sival/" + sSettings()->theme() + "/save_as.svg");
    }
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods
}
