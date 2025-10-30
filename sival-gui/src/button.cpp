/*
 * AtheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <sivalgui/button.hpp>
//// end system includes

//// begin project specific includes
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
SiVAL::Button::Button(const QString &label, SiVAL::Style *style, QWidget *parent)
:QPushButton(label, parent), m_pStyle(style) {
    if(m_pStyle) {
        setStyleSheet(m_pStyle->styleSheet());
    }
}

SiVAL::Button::Button(QWidget *parent)
:QPushButton(parent) {

}
/**************************************************************************************************/
/**
 *
 */
SiVAL::Button::~Button() {
    if(m_pStyle) {
        delete m_pStyle;
    }
}

int SiVAL::Button::id() {
    return m_Id;
}

void SiVAL::Button::setId(int id) {
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
