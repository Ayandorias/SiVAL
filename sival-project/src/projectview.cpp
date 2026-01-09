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
#include <sival.hpp>
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

namespace SiVAL::PM {
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

        m_enclosure = new SiVAL::Gui::Card(nullptr);
        m_enclosure->setIcon(":/sival/" + sSettings()->theme() + "/enclosure-fill.svg");
        m_enclosure->setMinimumHeight(40);
        m_enclosure->setMaximumHeight(40);
        connect(m_enclosure, &SiVAL::Gui::Card::clicked, this, &ProjectView::enclosure);
        l->addCard(m_enclosure);

        m_properties = new SiVAL::Gui::Card(nullptr);
        m_properties->setIcon(":/sival/" + sSettings()->theme() + "/project_properties.svg");
        m_properties->setMinimumHeight(40);
        m_properties->setMaximumHeight(40);
        connect(m_properties, &SiVAL::Gui::Card::clicked, this, &ProjectView::properties);
        l->addCard(m_properties);


        // m_information = new SiVAL::Gui::Card(nullptr);
        // m_information->setIcon(":/sival/" + sSettings()->theme() + "/info.svg");
        // m_information->setMinimumHeight(40);
        // m_information->setMaximumHeight(40);
        // connect(m_enclosure, &SiVAL::Gui::Card::clicked, this, &ProjectView::information);
        // l->addCard(m_information);

        // QWidget *w = new QWidget();
        // QVBoxLayout *layout = new QVBoxLayout(w);
        // layout->setContentsMargins(0,0,0,0);
        // layout->setSpacing(0);
        // l->addCard(w);

        // SiVAL::Gui::EnclosureCard *card = new SiVAL::Gui::EnclosureCard(w);
        // card->setIcon(":/sival/" + sSettings()->theme() + "/sealed.svg");
        // card->setTitle("TestDingen");
        // card->setMinimumHeight(40);
        // card->setMaximumHeight(40);
        // layout->addWidget(card);

        // card = new SiVAL::Gui::EnclosureCard(w);
        // card->setIcon(":/sival/" + sSettings()->theme() + "/vented.svg");
        // card->setTitle("TestDingen");
        // card->setMinimumHeight(40);
        // card->setMaximumHeight(40);
        // layout->addWidget(card);

        m_navBarPanel = l;

        retranslate();
    }
    return m_navBarPanel;
}
QWidget* ProjectView::centerPanel() {
    if(m_centerPanel == nullptr) {
        ProjectPanel *panel = new ProjectPanel();
        connect(panel, &ProjectPanel::sealedEnclosure, this, &ProjectView::sealedEnclosure);
        connect(panel, &ProjectPanel::ventedEnclosure, this, &ProjectView::ventedEnclosure);
        m_centerPanel = panel;
    }
    return m_centerPanel;
}
void ProjectView::setProjectDocument(SiVAL::Core::ProjectDocument *doc) {
    m_projectDoc = doc;
    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->setCurrentIndex(static_cast<int>(SiVAL::Project::Enclosure));
    p->update(doc);
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void ProjectView::retranslate() {
    if(m_navBarPanel != nullptr) {
        m_enclosure->setTitle(tr("Enclosure"));
        m_properties->setTitle(tr("Properties"));
        // m_information->setTitle(tr("Information"));
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
void ProjectView::enclosure() {
    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->setCurrentIndex(static_cast<int>(SiVAL::Project::Enclosure));
}
void ProjectView::information() {
    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->setCurrentIndex(static_cast<int>(SiVAL::Project::Enclosure));

}
void ProjectView::properties() {
    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->setCurrentIndex(static_cast<int>(SiVAL::Project::Properties));
}
//// end protected slots

//// begin private slots
//// end private slots
}
