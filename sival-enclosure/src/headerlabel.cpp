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
#include "headerlabel.hpp"
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
HeaderLabel::HeaderLabel(const QString &label, QWidget *parent)
    :SiVAL::Label(label,parent) {

    QLabel::setStyleSheet(QString::fromUtf8("color: #606060; font-size: 12pt; font-weight: bold;"));
}
HeaderLabel::HeaderLabel(QWidget *parent)
    :SiVAL::Label(parent) {

    QLabel::setStyleSheet(QString::fromUtf8("color: #606060; font-size: 12pt; font-weight: bold;"));
}
/**************************************************************************************************/
/**
 *
 */
HeaderLabel::~HeaderLabel() {
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
