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
}

/**************************************************************************************************/
/**
 *
 */
EnclosureWidget::~EnclosureWidget() {
    delete ui;
}

void EnclosureWidget::setProject(ProjectDocument *doc) {
    m_pProjectDoc = doc;
    updateMenu();
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

}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
