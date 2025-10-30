/*
 * AetheriumArchivar
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QToolButton>
#include <sivalgui/framebar.hpp>
//// end system includes

//// begin project specific includes
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
SiVAL::FrameBar::FrameBar(QWidget *parent)
    :TitleBar(parent) {

    setMinimumHeight(45);
    setMaximumHeight(45);

    m_pLayout->setSpacing(0);
    m_pLayout->setObjectName("m_pLayout");
    m_pLayout->setContentsMargins(0, 0, 0, 0);

    m_pButtonSidebar = new SiVAL::FrameBarButton(":/icon/sidebar_dark.svg", ":/icon/sidebar_light.svg", ":/icon/sidebar_closed_dark", ":/icon/sidebar_closed_light", this);
    m_pLayout->insertWidget(0, m_pButtonSidebar);
    m_pButtonSidebar->setCheckable(true);
    connect(m_pButtonSidebar, &SiVAL::FrameBarButton::toggled, this, &SiVAL::FrameBar::toggled);

    // m_pButtonMenu = new SiVAL::FrameBarButton(":/icon/menu_dark.svg", ":/icon/menu_light.svg", QString(), QString(), this);
    // m_pLayout->addWidget(m_pButtonMenu);
    // connect(m_pButtonMenu, &SiVAL::FrameBarButton::clicked, this, &SiVAL::FrameBar::mainMenu);

    // m_pLayout->addSpacing(50);

    m_pButtonMin = new SiVAL::FrameBarButton(":/icon/iconize_dark.svg", ":/icon/iconize_light.svg", QString(), QString(), this);
    m_pLayout->addWidget(m_pButtonMin);
    connect(m_pButtonMin, &SiVAL::FrameBarButton::clicked, this, &SiVAL::FrameBar::iconize);


    m_pButtonNormal = new SiVAL::FrameBarButton(":/icon/min_dark.svg", ":/icon/min_light.svg", QString(), QString(), this);
    m_pLayout->addWidget(m_pButtonNormal);
    connect(m_pButtonNormal, &SiVAL::FrameBarButton::clicked, this, &SiVAL::FrameBar::normal);

    m_pButtonMax = new SiVAL::FrameBarButton(":/icon/max_dark.svg", ":/icon/max_light.svg", QString(), QString(), this);
    m_pLayout->addWidget(m_pButtonMax);
    connect(m_pButtonMax, &SiVAL::FrameBarButton::clicked, this, &SiVAL::FrameBar::maximize);

    m_pButtonQuit = new SiVAL::FrameBarButton(":/icon/close_dark.svg", ":/icon/close_light.svg", QString(), QString(), this, SiVAL::FB_Close);
    m_pLayout->addWidget(m_pButtonQuit);
    connect(m_pButtonQuit, &SiVAL::FrameBarButton::clicked, this, &SiVAL::FrameBar::quit);

    setStyleSheet("border-radius: 0px;");
}

/**************************************************************************************************/
/**
 *
 */
SiVAL::FrameBar::~FrameBar() {
}
/**************************************************************************************************/
/**
 * @brief checkMaximized
 * @param max
 */
void SiVAL::FrameBar::checkMaximized(bool max) {

    if(max) {
        m_pButtonNormal->show();
        m_pButtonMax->hide();
    } else {
        m_pButtonNormal->hide();
        m_pButtonMax->show();
    }
}
void SiVAL::FrameBar::insertWidget(int pos, QWidget *widget) {
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
