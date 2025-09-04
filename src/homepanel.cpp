/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin specific includes
#include "homepanel.hpp"
#include "ui_homepanel.h"
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
HomePanel::HomePanel(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::HomePanel) {

    ui->setupUi(this);

    ui->m_pNewWorkspace->setTitle(tr("Create new Sound System ..."));
    ui->m_pNewWorkspace->setIcon(":/sival/sound_system_dark.svg");
    ui->m_pNewWorkspace->hide();

    ui->m_pOpenWorkspace->setTitle(tr("Open Sound System ..."));
    ui->m_pOpenWorkspace->setIcon(":/sival/open_dark.svg");
    ui->m_pOpenWorkspace->hide();

    ui->m_pNewProject->setTitle(tr("Create new Project ..."));
    ui->m_pNewProject->setIcon(":/icon/new_dark.svg");
    connect(ui->m_pNewProject, &NW::Card::clicked, this, &HomePanel::newProject);

    ui->m_pImportToWorkspace->setTitle(tr("Import Project to Sound System ..."));
    ui->m_pImportToWorkspace->setIcon(":/icon/import_dark.svg");
    ui->m_pImportToWorkspace->hide();
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
