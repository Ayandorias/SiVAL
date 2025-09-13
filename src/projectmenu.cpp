/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDoubleValidator>
//// end includes

//// begin specific includes
#include "projectmenu.hpp"
#include "ui_projectmenu.h"
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
ProjectMenu::ProjectMenu(QWidget *parent)
    :QWidget(parent),
    ui(new Ui::ProjectMenu) {
    ui->setupUi(this);

    QDoubleValidator *validator = new QDoubleValidator(0, 500, 2, ui->m_pGrossVolume);
    ui->m_pGrossVolume->setValidator(validator);
    connect(ui->m_pGrossVolume, &QLineEdit::textChanged, this, &ProjectMenu::grossVolumeChanged);
    connect(ui->m_pAuthor, &QLineEdit::textChanged, this, &ProjectMenu::authorChanged);
}

/**************************************************************************************************/
/**
 *
 */
ProjectMenu::~ProjectMenu() {
    delete ui;
}
void ProjectMenu::setAuthor(const QString &author) {
    ui->m_pAuthor->setText(author);
}
void ProjectMenu::setName(const QString &name) {
    ui->m_pProjectName->setText(name);
}
void ProjectMenu::setVolume(const double &volume) {
    ui->m_pGrossVolume->setText(QString::number(volume));
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
