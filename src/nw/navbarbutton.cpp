/*
 * AetheriumArchivar
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <iostream>
//// end includes

//// begin specific includes
#include "nw/navbarbutton.hpp"
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
 * @brief NW::NavBarButton::NavBarButton
 * @param parent
 */
NW::NavBarButton::NavBarButton(const QString &light, const QString &dark, QWidget *parent, NavBarButtonStyle style)
    :NW::ToolButton(parent) {

    if(style == NB_Normal) {
        setStyleSheet (QString::fromUtf8("QToolButton {"
                                    "background-color: #e0e0e0;"
                                    "border-radius: 0px;"
                                    "image: url(") + dark + QString::fromUtf8(");"
                                             "padding: 14px 14px 14px 14px;"
                                             "}"
                                             "QToolButton:hover {"
                                             "background-color: rgb(215, 100, 254);"
                                             "image: url(") +
                  light +
                  QString::fromUtf8(");"
                                    "}"
                                    "QToolButton:checked{"
                                    "background-color: rgb(215, 59,254);"
                                    "image: url(") +
                  light +
                  QString::fromUtf8(");"
                                    "border: none;"
                                    "border-left: 3px solid #000;"
                                    "}"));
    } else {
        setStyleSheet (QString::fromUtf8("QToolButton {"
                                        "background-color: #e0e0e0;"
                                        // "margin: 5px 5px 5px 5px;"
                                        "border-radius: 10px;"
                                        "image: url(") + dark + QString::fromUtf8(");"
                                                 "padding: 14px 14px 14px 14px;"
                                                 "}"
                                                 "QToolButton:hover {"
                                                 "background-color: rgb(215, 100, 254);"
                                                 "image: url(") +
                      light +
                      QString::fromUtf8(");"
                                        "}"
                                        "QToolButton:checked{"
                                        "background-color: rgb(215, 59,254);"
                                        "image: url(") +
                      light +
                      QString::fromUtf8(");"
                                        "border: none;"
                                        "border-left: 3px solid #000;"
                                        "}"));
    }
}
/**************************************************************************************************/
/**
 * @brief NW::NavBarButton::~NavBarButton
 */
NW::NavBarButton::~NavBarButton() {
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
