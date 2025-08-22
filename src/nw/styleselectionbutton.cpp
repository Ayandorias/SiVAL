/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin specific includes
#include "nw/styleselectionbutton.hpp"
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
NW::StyleSelectionButton::StyleSelectionButton()
:NW::Style() {
    m_sBgColor = QString::fromUtf8("#fafafa");
    m_sBgColorHover = QString::fromUtf8("#f5f5f5");
    m_sBgColorChecked = QString::fromUtf8("#EBEBEB");
    m_sBgColorPressed = QString::fromUtf8("#606060");

    m_sFgColor = QString::fromUtf8("#606060");
    m_sFgColorPressed = QString::fromUtf8("#fafafa");
}

/**************************************************************************************************/
/**
 *
 */
NW::StyleSelectionButton::~StyleSelectionButton() {
}

QString NW::StyleSelectionButton::styleSheet() {
    QString style;
    style = QString::fromUtf8("QPushButton { background-color: %1;").arg(m_sBgColor) +
    QString::fromUtf8("border: none;") +
    QString::fromUtf8("border-radius: 24px;") +
    QString::fromUtf8("padding-left: 15px;") +
    QString::fromUtf8("padding-right: 15px;") +
    QString::fromUtf8("color: %1;").arg(m_sFgColor) +
    QString::fromUtf8("}") +
    QString::fromUtf8("QPushButton:hover { background-color: %1;").arg(m_sBgColorHover) +
    QString::fromUtf8("border: none;") +
    QString::fromUtf8("border-radius: 24px;") +
    QString::fromUtf8("padding-left: 15px;") +
    QString::fromUtf8("padding-right: 15px;") +
    QString::fromUtf8("color: %1;").arg(m_sFgColor) +
    QString::fromUtf8("}") +
    QString::fromUtf8("QPushButton:checked { background-color: %1;").arg(m_sBgColorChecked) +
    QString::fromUtf8("border: none;") +
    QString::fromUtf8("border-radius: 24px;") +
    QString::fromUtf8("padding-left: 15px;") +
    QString::fromUtf8("padding-right: 15px;") +
    QString::fromUtf8("color: %1;").arg(m_sFgColor) +
    QString::fromUtf8("}")  +
    // QString::fromUtf8("QPushButton:pressed { background-color: %1;").arg(m_sBgColorPressed) +
    // QString::fromUtf8("border: none;") +
    // QString::fromUtf8("border-radius: 24px;") +
    // QString::fromUtf8("padding-left: 15px;") +
    // QString::fromUtf8("padding-right: 15px;") +
    // QString::fromUtf8("color: %1;").arg(m_sFgColorPressed) +
    // QString::fromUtf8("}") +
    QString::fromUtf8("QPushButton:checked:hover { background-color: %1;").arg(m_sBgColorHover) +
    QString::fromUtf8("border: none;") +
    QString::fromUtf8("border-radius: 24px;") +
    QString::fromUtf8("padding-left: 15px;") +
    QString::fromUtf8("padding-right: 15px;") +
    QString::fromUtf8("color: %1;").arg(m_sFgColor) +
    QString::fromUtf8("}");
    return style;
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

