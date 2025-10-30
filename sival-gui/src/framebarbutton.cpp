/*
 * AetheriumArchivar
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <sivalgui/framebarbutton.hpp>
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
SiVAL::FrameBarButton::FrameBarButton(const QString &icon, const QString &icon_hover, const QString icon_checked, const QString &icon_checked_hover, QWidget *parent, ToolButtonStyle style)
    :ToolButton(parent) {

    setMinimumSize(QSize(45, 35));
    setMaximumSize(QSize(45, 35));

    if(style == SiVAL::FB_Normal) {
        setStyleSheet("QToolButton {\n"
                      "	background-color: #FFF; \n"
                      "	border: none; \n"
                      " border-radius: 3px;"
                      "	image: url(\"" + icon + "\");\n"
                               "	padding: 7px;\n"
                               "}\n"
                               "QToolButton:hover {\n"
                               "	background-color: #A0A0A0;\n"
                               "	image: url(\"" + icon_hover + "\");\n"
                                     "	padding: 7px;\n"
                                     "}"
                                     "QToolButton:checked {\n"
                                     "	background-color: #efefef;\n"
                                     "	image: url(\"" + icon_checked + "\");\n"
                                       "	padding: 7px;\n"
                                       "}"
                                       "QToolButton:checked:hover {\n"
                                       "	background-color: #a0a0a0;\n"
                                       "	image: url(\"" + icon_checked_hover + "\");\n"
                                       "	padding: 7px;\n"
                                       "}");
    } else if(style == SiVAL::FB_Close) {

        setStyleSheet("QToolButton {\n"
                    "	background-color: #FFF; \n"
                    "	border: none; \n"
                    "	margin-right: 5px;\n"
                    "	image: url(\":/icon/close_dark.svg\");\n"
                    "	image: url(\"" + icon /*:/icon/close_dark.svg*/ + "\");\n"
                    "	padding: 7px;\n"
                    "}\n"
                    "QToolButton:hover {\n"
                    "	background-color: #F00;\n"
                    "	image: url(\"" + icon_hover /*:/icon/close_light.svg*/ + "\");\n"
                    "	padding: 7px;\n"
                    "	border-radius: 3px;\n"
                    "}");
    }
}

/**************************************************************************************************/
/**
 *
 */
SiVAL::FrameBarButton::~FrameBarButton() {
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
