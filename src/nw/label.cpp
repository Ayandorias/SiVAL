/*
 * AetheriumArchivar
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin specific includes
#include "nw/label.hpp"
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
NW::Label::Label(const QString &label, QWidget *parent)
    :QLabel(label, parent) {
    setStyleSheet();
}
NW::Label::Label(QWidget *parent)
    :QLabel(parent) {
    setStyleSheet();
}
/**************************************************************************************************/
/**
 *
 */
NW::Label::~Label() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void NW::Label::setStyleSheet() {
    QLabel::setStyleSheet("border: none; background-color: transparent; color: #606060;");
}
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
