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
//// end system includes

//// begin project specific includes
#include "sivalgui/navigationbar.hpp"
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

//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
SiVAL::NavigationBar::NavigationBar(QWidget *parent)
    :QWidget(parent), m_pos(1) {
    // setProperty("class", "SiVALNavigationBar");
    setAttribute(Qt::WA_StyledBackground, true);

    setMinimumWidth(80);
    setMaximumWidth(80);


    m_vl = new QVBoxLayout(this);
    m_vl->setContentsMargins(0, 0, 0, 0);

    SiVAL::NavigationButton *btn = new SiVAL::NavigationButton(this);
    btn->setObjectName("mainMenu");
    btn->setMinimumSize(80, 40);
    btn->setMaximumSize(80, 40);
    m_vl->addWidget(btn);


    QSpacerItem *verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    m_vl->addItem(verticalSpacer_2);

    m_line = new QFrame(this);
    m_line->setObjectName("separator");
    m_line->setMinimumSize(QSize(0, 1));
    m_line->setMaximumSize(QSize(16777215, 1));
    m_vl->addWidget(m_line);
}

/**************************************************************************************************/
/**
 *
 */
SiVAL::NavigationBar::~NavigationBar() {
}
void SiVAL::NavigationBar::addButton(SiVAL::NavigationButton *btn) {
    m_vl->insertWidget(m_pos++, btn);
}
void SiVAL::NavigationBar::appendButton(SiVAL::NavigationButton *btn) {
    m_vl->addWidget(btn);
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
