/*
 * Nebenwelten
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
//// end system includes

//// begin project specific includes
#include <sivalgui/pushbutton.hpp>
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
SiVAL::PushButton::PushButton(QWidget *parent)
    :QPushButton(parent) {
    setStyleSheet(QString::fromUtf8("QPushButton { \n"
                                    "	background-color: #FFFFFF;\n"
                                    "	color: rgb(160, 160, 160);\n"
                                    "	border: none; \n"
                                    "	padding: 10px 20px; \n"
                                    "	border: 1px solid #A0A0A0;\n"
                                    "	border-radius: 5px;\n"
                                    "}\n"
                                    "QPushButton:hover { \n"
                                    "	background-color: rgb(235, 100, 254); \n"
                                    "	color: #FFF; \n"
                                    "}\n"
                                    ""));
}

/**************************************************************************************************/
/**
 *
 */
SiVAL::PushButton::~PushButton() {
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
