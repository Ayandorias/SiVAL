/*
 * AetheriumArchivar
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QToolButton>

#include <iostream>
//// end includes

//// begin specific includes
#include "nw/framebar.hpp"
//// end specific includes

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
NW::FrameBar::FrameBar(QWidget *parent)
    :TitleBar(parent) {

    setMinimumHeight(45);
    setMaximumHeight(45);

    m_pLayout->setSpacing(0);
    m_pLayout->setObjectName("m_pLayout");
    m_pLayout->setContentsMargins(0, 0, 0, 0);

    m_pButtonSidebar = new NW::FrameBarButton(":/icon/sidebar_dark.svg", ":/icon/sidebar_light.svg", ":/icon/sidebar_closed_dark", ":/icon/sidebar_closed_light", this);
    m_pLayout->insertWidget(0, m_pButtonSidebar);
    m_pButtonSidebar->setCheckable(true);
    connect(m_pButtonSidebar, &NW::FrameBarButton::toggled, this, &NW::FrameBar::toggled);

    // m_pButtonMenu = new NW::FrameBarButton(":/icon/menu_dark.svg", ":/icon/menu_light.svg", QString(), QString(), this);
    // m_pLayout->addWidget(m_pButtonMenu);
    // connect(m_pButtonMenu, &NW::FrameBarButton::clicked, this, &NW::FrameBar::mainMenu);

    // m_pLayout->addSpacing(50);

    m_pButtonMin = new NW::FrameBarButton(":/icon/iconize_dark.svg", ":/icon/iconize_light.svg", QString(), QString(), this);
    m_pLayout->addWidget(m_pButtonMin);
    connect(m_pButtonMin, &NW::FrameBarButton::clicked, this, &NW::FrameBar::iconize);


    m_pButtonNormal = new NW::FrameBarButton(":/icon/min_dark.svg", ":/icon/min_light.svg", QString(), QString(), this);
    m_pLayout->addWidget(m_pButtonNormal);
    connect(m_pButtonNormal, &NW::FrameBarButton::clicked, this, &NW::FrameBar::normal);

    m_pButtonMax = new NW::FrameBarButton(":/icon/max_dark.svg", ":/icon/max_light.svg", QString(), QString(), this);
    m_pLayout->addWidget(m_pButtonMax);
    connect(m_pButtonMax, &NW::FrameBarButton::clicked, this, &NW::FrameBar::maximize);

    m_pButtonQuit = new NW::FrameBarButton(":/icon/close_dark.svg", ":/icon/close_light.svg", QString(), QString(), this, NW::FB_Close);
    m_pLayout->addWidget(m_pButtonQuit);
    connect(m_pButtonQuit, &NW::FrameBarButton::clicked, this, &NW::FrameBar::quit);

    setStyleSheet("border-radius: 0px;");
}

/**************************************************************************************************/
/**
 *
 */
NW::FrameBar::~FrameBar() {
}
/**************************************************************************************************/
/**
 * @brief checkMaximized
 * @param max
 */
void NW::FrameBar::checkMaximized(bool max) {

    if(max) {
        m_pButtonNormal->show();
        m_pButtonMax->hide();
    } else {
        m_pButtonNormal->hide();
        m_pButtonMax->show();
    }
}
void NW::FrameBar::insertWidget(int pos, QWidget *widget) {
    m_pLayout->insertWidget(pos, widget);
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
