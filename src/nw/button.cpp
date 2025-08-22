/*
 * AtheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <iostream>
//// end includes

//// begin specific includes
#include "nw/button.hpp"
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
NW::Button::Button(const QString &label, NW::Style *style, QWidget *parent)
:QPushButton(label, parent), m_pStyle(style) {
    if(m_pStyle) {
        setStyleSheet(m_pStyle->styleSheet());
    }
}

NW::Button::Button(QWidget *parent)
:QPushButton(parent) {

}
/**************************************************************************************************/
/**
 *
 */
NW::Button::~Button() {
    if(m_pStyle) {
        delete m_pStyle;
    }
}

int NW::Button::id() {
    return m_Id;
}

void NW::Button::setId(int id) {
    m_Id = id;
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
