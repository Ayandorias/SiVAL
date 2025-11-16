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

        SiVAL::Gui::Card *card = new SiVAL::Gui::Card("Neu...", QString(), nullptr);
        card->setIcon(":/sival/light/new.svg");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        l->addCard(card);

        card = new SiVAL::Gui::Card(tr("Öffnen..."), QString(), nullptr);
        card->setIcon(":/sival/light/open.svg");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        l->addCard(card);

        card = new SiVAL::Gui::Card(tr("Speichern"), QString(), nullptr);
        card->setIcon(":/sival/light/save.svg");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        l->addCard(card);

        card = new SiVAL::Gui::Card(tr("Speichern unter..."), QString(), nullptr);
        card->setIcon(":/sival/light/save_as.svg");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        l->addCard(card);

        card = new SiVAL::Gui::Card(tr("Importieren..."), QString(), nullptr);
        card->setIcon(":/sival/light/import.svg");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        l->addCard(card);

        card = new SiVAL::Gui::Card(tr("Exportieren..."), QString(), nullptr);
        card->setIcon(":/sival/light/export.svg");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        l->addCard(card);

        card = new SiVAL::Gui::Card(tr("Drucken..."), QString(), nullptr);
        card->setIcon(":/sival/light/print.svg");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        l->addCard(card);


            // "Importieren..." (standardmäßig deaktiviert)

            // "Exportieren..." (standardmäßig deaktiviert)

            // "Drucken..." (standardmäßig deaktiviert)



        m_navBarPanel = l;
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
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods
}
