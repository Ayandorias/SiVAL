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

namespace SiVAL::Gui {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
FrameBar::FrameBar(QWidget *parent)
    :QWidget(parent) {

    setMinimumHeight(45);
    setMaximumHeight(45);


    m_pLayout = new QHBoxLayout(this);
    setLayout(m_pLayout);

    QSpacerItem *spacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    m_pLayout->addItem(spacer);

    m_pLayout->setSpacing(0);
    m_pLayout->setObjectName("m_pLayout");
    m_pLayout->setContentsMargins(0, 0, 0, 0);

    // m_pButtonSidebar = new QToolButton(this);
    // m_pLayout->insertWidget(0, m_pButtonSidebar);
    // m_pButtonSidebar->setCheckable(true);
    // connect(m_pButtonSidebar, &SiVAL::FrameBarButton::toggled, this, &SiVAL::FrameBar::toggled);

    m_buttonMin = new FrameBarButton(this);
    m_buttonMin->setObjectName("buttonMin");
    m_pLayout->addWidget(m_buttonMin);
    connect(m_buttonMin, &FrameBarButton::clicked, this, &SiVAL::Gui::FrameBar::iconize);

    m_buttonNormal = new FrameBarButton(this);
    m_buttonNormal->setObjectName("buttonNormal");
    m_pLayout->addWidget(m_buttonNormal);
    connect(m_buttonNormal, &FrameBarButton::clicked, this, &SiVAL::Gui::FrameBar::normal);

    m_buttonMax = new FrameBarButton(this);
    m_buttonMax->setObjectName("buttonMax");
    m_pLayout->addWidget(m_buttonMax);
    connect(m_buttonMax, &FrameBarButton::clicked, this, &SiVAL::Gui::FrameBar::maximize);

    m_buttonQuit = new FrameBarButton(this);
    m_buttonQuit->setObjectName("buttonQuit");
    m_pLayout->addWidget(m_buttonQuit);
    connect(m_buttonQuit, &FrameBarButton::clicked, this, &SiVAL::Gui::FrameBar::quit);
}

/**************************************************************************************************/
/**
 *
 */
FrameBar::~FrameBar() {
}
/**************************************************************************************************/
/**
 * @brief checkMaximized
 * @param max
 */
void FrameBar::checkMaximized(bool max) {

    if(max) {
        m_buttonNormal->show();
        m_buttonMax->hide();
    } else {
        m_buttonNormal->hide();
        m_buttonMax->show();
    }
}
void FrameBar::insertWidget(int pos, QWidget *widget) {
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
}
