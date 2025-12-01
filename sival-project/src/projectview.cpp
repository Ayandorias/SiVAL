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
#include "projectview.hpp"
#include <sivalgui/cardlist.hpp>
#include <sivalgui/enclosurecard.hpp>
#include <sivalgui/section.hpp>
#include <sivalgui/sectioncard.hpp>
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
ProjectView::ProjectView()
    :Gui::View() {
}

/**************************************************************************************************/
/**
 *
 */
ProjectView::~ProjectView() {
}
Gui::NavigationPanel* ProjectView::navigationPanel() {
    if(m_navBarPanel == nullptr) {
        Gui::CardList *l = new Gui::CardList();

        sec = new SiVAL::Gui::Section(nullptr);
        sec->setIcon(":/sival/" + sSettings()->theme() + "/enclosure-fill.svg");
        sec->setMinimumHeight(40);
        sec->setMaximumHeight(40);
        l->addCard(sec);

        QWidget *w = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(w);
        layout->setContentsMargins(0,0,0,0);
        layout->setSpacing(0);
        l->addCard(w);

        SiVAL::Gui::EnclosureCard *card = new SiVAL::Gui::EnclosureCard(w);
        card->setIcon(":/sival/" + sSettings()->theme() + "/sealed.svg");
        card->setTitle("TestDingen");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        layout->addWidget(card);

        card = new SiVAL::Gui::EnclosureCard(w);
        card->setIcon(":/sival/" + sSettings()->theme() + "/vented.svg");
        card->setTitle("TestDingen");
        card->setMinimumHeight(40);
        card->setMaximumHeight(40);
        layout->addWidget(card);

        m_navBarPanel = l;

        retranslate();
    }
    return m_navBarPanel;
}
QWidget* ProjectView::centerPanel() {
    if(m_centerPanel == nullptr) {
        m_centerPanel = new QWidget();
    }
    return m_centerPanel;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void ProjectView::retranslate() {
    if(m_navBarPanel != nullptr) {
        sec->setTitle(tr("Enclosure"));
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
//// end protected slots

//// begin private slots
//// end private slots
}
