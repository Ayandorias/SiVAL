/*
 * SiVAL GUI
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
#include <QVBoxLayout>
#include <QLabel>
//// end system includes

//// begin project specific includes
#include <sivalgui/card.hpp>
#include <sivalgui/cardlist.hpp>
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
namespace Gui {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
CardList::CardList(QWidget *parent)
    :NavigationPanel(parent) {

    setWidgetResizable(true);
    m_index = 0;

    m_scrollContentWidget = new QWidget;
    m_scrollContentWidget->setProperty("class", "CardList");

    m_contentLayout = new QVBoxLayout(m_scrollContentWidget);
    m_contentLayout->setContentsMargins(0,0,0,0);
    m_contentLayout->setSpacing(1);

    // SiVAL::Gui::Card *card = new SiVAL::Gui::Card("hello", "hello2", m_scrollContentWidget);
    // card->setIcon(":/sival/icon/new_dark.svg");
    // m_contentLayout->addWidget(card);

    // QLabel *label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);
    // label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);
    // label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);
    // label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);
    // label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);
    // label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);
    // label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);
    // label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);
    // label = new QLabel("hallo", m_scrollContentWidget);
    // m_contentLayout->addWidget(label);

    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    m_contentLayout->addItem(spacer);

    setWidget(m_scrollContentWidget);
}

/**************************************************************************************************/
/**
 *
 */
CardList::~CardList() {
}

void CardList::addCard(Card *card) {
    card->setParent(m_scrollContentWidget);
    m_contentLayout->insertWidget(m_index++, card);
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
}
