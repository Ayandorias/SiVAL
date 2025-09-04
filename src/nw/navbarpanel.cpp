/*
 * AetheriumArchivar
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QToolButton>
#include <iostream>
//// end includes

//// begin specific includes
#include "nw/navbarpanel.hpp"
#include "nw/navbarbutton.hpp"
// #include "ui_navbarpanel.h"
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
 * @brief NW::NavBarPanel::NavBarPanel
 * @param parent
 */
NW::NavBarPanel::NavBarPanel(QWidget *parent)
    :QWidget(parent) {

    setStyleSheet("border-radius: 0px;");

    QHBoxLayout *h = new QHBoxLayout(this);
    h->setContentsMargins(0, 0, 0, 0);
    h->setSpacing(0);

    m_pButtonLayout = new QVBoxLayout();
    m_pButtonLayout->setContentsMargins(0, 0, 0, 0);
    m_pButtonLayout->setSpacing(0);
    h->addLayout(m_pButtonLayout);



    m_pGroup = new QButtonGroup(this);
    m_pGroup->setExclusive(true);


    // verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    NW::NavBarButton *toolButton = new NW::NavBarButton(":/icon/aa_light.svg", ":/icon/aa_pink.svg", this, NB_Menu);
    toolButton->setMinimumSize(QSize(45, 45));
    toolButton->setMaximumSize(QSize(45, 45));
    toolButton->setObjectName("toolButton");

    connect(toolButton, &QToolButton::clicked, this, &NW::NavBarPanel::mainMenu);
    m_pButtonLayout->addWidget(toolButton);

    m_pButtonLayout->insertSpacerItem(-1, new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding));

    m_pPanelStack = new QStackedWidget(this);
    h->addWidget(m_pPanelStack);


    connect(m_pGroup, &QButtonGroup::buttonClicked, this, &NW::NavBarPanel::selection);
}
/**************************************************************************************************/
/**
 * @brief NW::NavBarPanel::~NavBarPanel
 */
NW::NavBarPanel::~NavBarPanel() {
}
/**************************************************************************************************/
/**
 * @brief NW::NavBarPanel::addPanel
 * @param icon
 * @param icon_hover
 * @param panel
 */
void NW::NavBarPanel::addPanel(const QString &icon, const QString &icon_hover, QWidget *panel) {
    int count = m_pButtonLayout->count() - 2;
    // NW::NavBarButton *toolButton = new NW::NavBarButton(icon, icon_hover, this);
    // toolButton->setMinimumSize(QSize(48, 48));
    // toolButton->setMaximumSize(QSize(48, 48));
    // toolButton->setObjectName("toolButton");
    // toolButton->setCheckable(true);
    // m_pGroup->addButton(toolButton, count);
    // m_pButtonLayout->insertWidget(count + 1, toolButton);

    // // Panel zum QStackedWidget hinzufügen.
    // m_pPanelStack->addWidget(panel);

    insertPanel(icon, icon_hover, count, count + 1, panel);
}
void NW::NavBarPanel::appendPanel(const QString &icon, const QString &icon_hover, QWidget *panel) {
    int count = m_pButtonLayout->count() - 2;
    insertPanel(icon, icon_hover, count, -1, panel);
    // NW::NavBarButton *toolButton = new NW::NavBarButton(icon, icon_hover, this);
    // toolButton->setMinimumSize(QSize(48, 48));
    // toolButton->setMaximumSize(QSize(48, 48));
    // toolButton->setObjectName("toolButton");
    // toolButton->setCheckable(true);
    // m_pGroup->addButton(toolButton, count);
    // m_pButtonLayout->insertWidget(count + 1, toolButton);

    // // Panel zum QStackedWidget hinzufügen.
    // m_pPanelStack->addWidget(panel);
}
void NW::NavBarPanel::select(int id) {
    QAbstractButton *btn = m_pGroup->button(1);
    if(btn) {
        btn->click();//setChecked(true);
    }
}
void NW::NavBarPanel::toggle(bool checked) {
    if(checked) {
        m_pPanelStack->hide();
    } else {
        m_pPanelStack->show();
    }
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void NW::NavBarPanel::insertPanel(const QString &icon, const QString &icon_hover, int btn_id, int position, QWidget *panel) {
    // int count = m_pButtonLayout->count() - 2;
    NW::NavBarButton *toolButton = new NW::NavBarButton(icon, icon_hover, this);
    toolButton->setMinimumSize(QSize(48, 48));
    toolButton->setMaximumSize(QSize(48, 48));
    toolButton->setObjectName("toolButton");
    toolButton->setCheckable(true);
    if(btn_id == 0) {
        toolButton->setChecked(true);
    }
    m_pGroup->addButton(toolButton, btn_id);
    m_pButtonLayout->insertWidget(position, toolButton);

    // Panel zum QStackedWidget hinzufügen.
    m_pPanelStack->addWidget(panel);
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void NW::NavBarPanel::selection(QAbstractButton *btn) {
    Q_UNUSED(btn);

    for(QAbstractButton *button : m_pGroup->buttons()) {
        if(button->isChecked()) {
            m_pPanelStack->setCurrentIndex(m_pGroup->id(button));
            emit changeCenterView(m_pGroup->id(button));
            break;
        }
    }
    // if(btn == ui->m_pCharakter) {
    //     ui->m_pStackedWidget->setCurrentIndex(0);
    //     emit changeview(NW::CV_CharacterPage);
    // } else if(btn == ui->m_pSettings) {
    //     ui->m_pStackedWidget->setCurrentIndex(1);
    //     emit changeview(NW::CV_SettingsSkill);
    // }
}
//// end protected slots

//// begin private slots
//// end private slots
