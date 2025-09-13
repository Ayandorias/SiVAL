/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin specific includes
#include "enclosurewidget.hpp"
#include "ui_enclosurewidget.h"
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
EnclosureWidget::EnclosureWidget(QWidget *parent)
    :QWidget(parent),
    ui(new Ui::EnclosureWidget) {

    ui->setupUi(this);

    connect(ui->m_pProjectMenu, &ProjectMenu::grossVolumeChanged, this, &EnclosureWidget::grossVolumeChanged);
    connect(ui->m_pProjectMenu, &ProjectMenu::authorChanged, this, &EnclosureWidget::authorChanged);

    ui->m_pProjectMenu->setDisabled(true);
}

/**************************************************************************************************/
/**
 *
 */
EnclosureWidget::~EnclosureWidget() {
    delete ui;
}

void EnclosureWidget::setPage(SiVAL::PRJ_MENU page) {
    ui->m_pMenu->setCurrentIndex(page);
}
void EnclosureWidget::setProject(ProjectDocument *doc) {
    m_pProjectDoc = doc;
    updateMenu();

    ui->m_pProjectMenu->setDisabled(false);
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void EnclosureWidget::updateMenu() {
    ui->m_pProjectMenu->setAuthor(m_pProjectDoc->author());
    ui->m_pProjectMenu->setName(m_pProjectDoc->name());
    ui->m_pProjectMenu->setVolume(m_pProjectDoc->volume());
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void EnclosureWidget::authorChanged(const QString &name) {
    if(m_pProjectDoc != nullptr) {
        m_pProjectDoc->setAuthor(name);
    }
}
void EnclosureWidget::grossVolumeChanged(const QString &volume) {
    if(m_pProjectDoc != nullptr) {
        m_pProjectDoc->setVolume(volume.toDouble());
    }
}
//// end protected slots

//// begin private slots
//// end private slots
