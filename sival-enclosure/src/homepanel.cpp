/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
//// end system includes

//// begin project specific includes
#include "homepanel.hpp"
#include "ui_homepanel.h"
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
HomePanel::HomePanel(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::HomePanel) {

    ui->setupUi(this);

    ui->m_pNewWorkspace->setTitle(tr("Create new Workspace ..."));
    ui->m_pNewWorkspace->setIcon(":/sival/sound_system_dark.svg");
    ui->m_pNewWorkspace->hide();

    ui->m_pOpenWorkspace->setTitle(tr("Open Workspace ..."));
    ui->m_pOpenWorkspace->setIcon(":/sival/open_dark.svg");
    ui->m_pOpenWorkspace->hide();

    ui->m_pNewEnclosure->setTitle(tr("New Project ..."));
    ui->m_pNewEnclosure->setIcon(":/icon/new_dark.svg");
    connect(ui->m_pNewEnclosure, &SiVAL::Card::clicked, this, &HomePanel::newProject);

    ui->m_pOpenEnclosure->setTitle(tr("Open Project ..."));
    ui->m_pOpenEnclosure->setIcon(":/sival/open_dark.svg");
    connect(ui->m_pOpenEnclosure, &SiVAL::Card::clicked, this, &HomePanel::openProject);


    ui->m_pImportToWorkspace->setTitle(tr("Import Project to Workspace ..."));
    ui->m_pImportToWorkspace->setIcon(":/icon/import_dark.svg");
    ui->m_pImportToWorkspace->hide();

    ui->sivalInfo->setTitle("Information");
    ui->sivalInfo->setIcon(":/sival/info_dark.svg");
}

/**************************************************************************************************/
/**
 *
 */
HomePanel::~HomePanel() {
    delete ui;
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
