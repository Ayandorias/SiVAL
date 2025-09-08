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
#include "projectpanel.hpp"
#include "ui_projectpanel.h"
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
ProjectPanel::ProjectPanel(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::ProjektPanel) {
    ui->setupUi(this);

    m_pProjectDocument = nullptr;
    connect(ui->m_pNewProject, &QToolButton::clicked, this, &ProjectPanel::newProject);
    connect(ui->m_pNewEnclosure, &QToolButton::clicked, this, &ProjectPanel::newEnclosure);
    connect(ui->m_pOpen, &QToolButton::clicked, this, &ProjectPanel::openProject);
    connect(ui->m_pSave, &QToolButton::clicked, this, &ProjectPanel::save);

    connect(ui->m_pPojectTree, &ProjectTreeWidget::projectChanged, this, &ProjectPanel::projectChanged);

    checkButtons();
}

/**************************************************************************************************/
/**
 *
 */
ProjectPanel::~ProjectPanel() {
    delete ui;
}
void ProjectPanel::addEnclosure(SpeakerDocument *doc) {
    ui->m_pPojectTree->addEnclosure(doc);
}
/**
 * @brief ProjectPanel::load
 * @param projectfile
 */
void ProjectPanel::open(const QString &projectfile) {
    m_pProjectDocument = new ProjectDocument(projectfile);

    ui->m_pPojectTree->addProject(m_pProjectDocument);

    ui->m_pNewEnclosure->setDisabled(false);
    checkButtons();
}
/**
 * @brief ProjectPanel::save
 */
void ProjectPanel::save() {
    ui->m_pPojectTree->save();
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void ProjectPanel::checkButtons() {
    if(m_pProjectDocument == nullptr) {
        ui->m_pNewEnclosure->setDisabled(true);
    } else {
        ui->m_pNewEnclosure->setDisabled(false);
    }

}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots

