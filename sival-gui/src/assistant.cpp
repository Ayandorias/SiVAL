/*
 * Nebenwelten$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <sivalgui/assistant.hpp>
//// end system includes

//// begin project specific includes
#include "ui_assistant.h"
#include "ui_overlaydialog.h"
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
SiVAL::Assistant::Assistant(QWidget *parent)
:SiVAL::OverlayDialog(parent), m_pCenterUI(new Ui::Assistant()) {

    /*m_pUi->*/m_pDialog->setMinimumSize(800, 600);
    m_pCenterUI->setupUi(/*m_pUi->*/m_pCenterWidget);
    /*m_pUi->*/m_pAccept->hide();
    /*m_pUi->*/m_pNextButton->hide();
    /*m_pUi->*/m_pPrevButton->hide();
    m_pNext = new SiVAL::FrameBarButton(":/icon/chevron-right_dark.svg", ":/icon/chevron-right_light.svg", QString(), QString(), /*m_pUi->*/m_pTitleBar);
    m_pNext->setEnabled(false);
    /*m_pUi->*/m_pTitleBarLayout->insertWidget(0, m_pNext);

    m_pPrevious = new SiVAL::FrameBarButton(":/icon/chevron-left_dark.svg", ":/icon/chevron-left_light.svg", QString(), QString(), /*m_pUi->*/m_pTitleBar);
    m_pPrevious->setEnabled(false);
    /*m_pUi->*/m_pTitleBarLayout->insertWidget(0, m_pPrevious);

    /*m_pUi->*/m_pLabel->setText(tr("Create New Enclosure"));
}

/**************************************************************************************************/
/**
 *
 */
SiVAL::Assistant::~Assistant() {
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
