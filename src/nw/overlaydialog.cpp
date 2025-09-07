/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <iostream>
//// end includes

//// begin specific includes
#include "nw/overlaydialog.hpp"
// #include "ui_overlaydialog.h"
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
NW::OverlayDialog::OverlayDialog(QWidget *parent)
:QWidget(parent)/*, m_pUi(new Ui::OverlayDialog())*/ {
    // m_pUi->
    setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setGeometry(0, 0, parent->width(), parent->height());

    // connect(m_pUi->m_pClose, &QToolButton::clicked, this, &NW::OverlayDialog::cancel);
    connect(m_pClose, &QToolButton::clicked, this, &NW::OverlayDialog::cancel);

}

/**************************************************************************************************/
/**
 *
 */
NW::OverlayDialog::~OverlayDialog() {
    // delete m_pUi;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
bool NW::OverlayDialog::eventFilter(QObject *obj, QEvent *event) {
    // Prüfen, ob das Event vom Parent-Widget kommt
    if (obj == parentWidget()) {
        // --- 1. Auf Größen- und Positionsänderungen reagieren ---
        if (event->type() == QEvent::Resize) {
            if (parentWidget()) { // Sicherheitsüberprüfung
                // Setze die Geometrie des Overlays exakt auf die Geometrie des Parents
                setGeometry(parentWidget()->rect());
                // Die Zentrierung des m_contentWidget innerhalb des Overlays
                // wird automatisch durch das QVBoxLayout 'overlayLayout' gehandhabt,
                // da es an 'this' (dem OverlayDialog) gesetzt ist und 'this' sich anpasst.
            }
        }
    }
    // Für alle anderen Objekte oder Event-Typen, die nicht von uns gefiltert werden,
    // das Event an die Basisklasse weitergeben.
    return QWidget::eventFilter(obj, event);
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
/**
 * @brief NW::OverlayDialog::setupUi
 * @param OverlayDialog
 */
void NW::OverlayDialog::setupUi(QWidget *OverlayDialog)
{
    if (OverlayDialog->objectName().isEmpty())
        OverlayDialog->setObjectName("OverlayDialog");
    OverlayDialog->resize(1433, 1107);
    OverlayDialog->setMinimumSize(QSize(800, 600));
    OverlayDialog->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0.3);"));
    horizontalLayout = new QHBoxLayout(OverlayDialog);
    horizontalLayout->setObjectName("horizontalLayout");
    widget = new QWidget(OverlayDialog);
    widget->setObjectName("widget");
    widget->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0.3);\n"
                                            "border-radius: 5px;"));
    gridLayout = new QGridLayout(widget);
    gridLayout->setObjectName("gridLayout");
    verticalSpacer_4 = new QSpacerItem(20, 227, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    gridLayout->addItem(verticalSpacer_4, 0, 1, 1, 1);

    horizontalSpacer_8 = new QSpacerItem(290, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    gridLayout->addItem(horizontalSpacer_8, 1, 0, 1, 1);

    m_pDialog = new QWidget(widget);
    m_pDialog->setObjectName("m_pDialog");
    m_pDialog->setMinimumSize(QSize(300, 300));
    m_pDialog->setStyleSheet(QString::fromUtf8("background-color: #e0e0e0;\n"
                                               "border-radius: 5px\n"
                                               ""));
    verticalLayout = new QVBoxLayout(m_pDialog);
    verticalLayout->setSpacing(0);
    verticalLayout->setObjectName("verticalLayout");
    verticalLayout->setContentsMargins(3, 3, 3, 3);
    m_pTitleBar = new QWidget(m_pDialog);
    m_pTitleBar->setObjectName("m_pTitleBar");
    m_pTitleBar->setMinimumSize(QSize(0, 45));
    m_pTitleBar->setMaximumSize(QSize(16777215, 45));
    m_pTitleBar->setSizeIncrement(QSize(0, 0));
    m_pTitleBar->setStyleSheet(QString::fromUtf8("border-radius:0px; \n"
                                                 "background-color: #fff"));
    m_pTitleBarLayout = new QHBoxLayout(m_pTitleBar);
    m_pTitleBarLayout->setSpacing(0);
    m_pTitleBarLayout->setObjectName("m_pTitleBarLayout");
    m_pTitleBarLayout->setContentsMargins(0, 0, 0, 0);
    horizontalSpacer_3 = new QSpacerItem(45, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

    m_pTitleBarLayout->addItem(horizontalSpacer_3);

    m_pLabel = new QLabel(m_pTitleBar);
    m_pLabel->setObjectName("m_pLabel");
    QFont font;
    font.setBold(true);
    m_pLabel->setFont(font);
    m_pLabel->setStyleSheet(QString::fromUtf8("color: rgb(60, 60, 60);"));

    m_pTitleBarLayout->addWidget(m_pLabel);

    horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    m_pTitleBarLayout->addItem(horizontalSpacer_5);

    m_pClose = new QToolButton(m_pTitleBar);
    m_pClose->setObjectName("m_pClose");
    m_pClose->setMinimumSize(QSize(45, 35));
    m_pClose->setMaximumSize(QSize(45, 35));
    m_pClose->setStyleSheet(QString::fromUtf8("QToolButton {\n"
                                              "	background-color: #FFF; \n"
                                              "	border: none; \n"
                                              "	margin-right: 5px;\n"
                                              "	image: url(\":/icon/close_dark.svg\");\n"
                                              "	padding: 7px;\n"
                                              "}\n"
                                              "QToolButton:hover {\n"
                                              "	background-color: #F00;\n"
                                              "	image: url(\":/icon/close_light.svg\");\n"
                                              "	padding: 7px;\n"
                                              "	border-radius: 3px;\n"
                                              "}"));
    m_pClose->setAutoRaise(false);

    m_pTitleBarLayout->addWidget(m_pClose);


    verticalLayout->addWidget(m_pTitleBar);

    m_pCenterWidget = new QWidget(m_pDialog);
    m_pCenterWidget->setObjectName("m_pCenterWidget");

    verticalLayout->addWidget(m_pCenterWidget);

    m_pButtonBar = new QHBoxLayout();
    m_pButtonBar->setObjectName("m_pButtonBar");
    horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    m_pButtonBar->addItem(horizontalSpacer_6);

    m_pPrevButton = new QPushButton(m_pDialog);
    m_pPrevButton->setObjectName("m_pPrevButton");
    m_pPrevButton->setMinimumSize(QSize(0, 35));
    m_pPrevButton->setMaximumSize(QSize(16777215, 35));
    m_pPrevButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icon/chevron-left_dark.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
    m_pPrevButton->setIcon(icon);

    m_pButtonBar->addWidget(m_pPrevButton);

    m_pNextButton = new QPushButton(m_pDialog);
    m_pNextButton->setObjectName("m_pNextButton");
    m_pNextButton->setMinimumSize(QSize(0, 35));
    m_pNextButton->setMaximumSize(QSize(16777215, 35));
    m_pNextButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
                                                   "}"));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/icon/chevron-right_dark.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
    m_pNextButton->setIcon(icon1);

    m_pButtonBar->addWidget(m_pNextButton);

    m_pAccept = new QPushButton(m_pDialog);
    m_pAccept->setObjectName("m_pAccept");
    m_pAccept->setMinimumSize(QSize(0, 35));
    m_pAccept->setMaximumSize(QSize(16777215, 35));
    m_pAccept->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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

    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/icon/check_dark.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
    m_pAccept->setIcon(icon2);

    m_pButtonBar->addWidget(m_pAccept);

    horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    m_pButtonBar->addItem(horizontalSpacer_7);

    m_pButtonBar->setStretch(0, 1);
    m_pButtonBar->setStretch(4, 1);

    verticalLayout->addLayout(m_pButtonBar);

    verticalLayout->setStretch(1, 1);

    gridLayout->addWidget(m_pDialog, 1, 1, 1, 1);

    horizontalSpacer = new QSpacerItem(289, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

    verticalSpacer_2 = new QSpacerItem(20, 226, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


    horizontalLayout->addWidget(widget);

    retranslateUi(OverlayDialog);

    QMetaObject::connectSlotsByName(OverlayDialog);
} // setupUi
/**
 * @brief NW::OverlayDialog::retranslateUi
 * @param OverlayDialog
 */
void NW::OverlayDialog::retranslateUi(QWidget *OverlayDialog)
{
    m_pLabel->setText(QCoreApplication::translate("OverlayDialog", "Text", nullptr));
    m_pClose->setText(QString());
    m_pPrevButton->setText(QCoreApplication::translate("OverlayDialog", "PushButton 1", nullptr));
    m_pNextButton->setText(QCoreApplication::translate("OverlayDialog", "PushButton 2", nullptr));
    m_pAccept->setText(QCoreApplication::translate("OverlayDialog", "PushButton 3", nullptr));
} // retranslateUi

//// end private member methods

//// begin public slots
void NW::OverlayDialog::cancel() {
    close();
}
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots










