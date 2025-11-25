/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
//// end system includes

//// begin project specific includes
#include "startpanel.hpp"
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

namespace SiVAL {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
StartPanel::StartPanel(QWidget *parent)
    :QWidget(parent), m_recentPos(0) {

    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName("verticalLayout");

    QLabel *label_3 = new QLabel(this);
    label_3->setObjectName("label_3");
    label_3->setMinimumSize(QSize(120, 40));
    label_3->setMaximumSize(QSize(120, 40));
    label_3->setPixmap(QPixmap(QString::fromUtf8(":/sival/logo/sival_logo.svg")));
    label_3->setScaledContents(true);
    verticalLayout->addWidget(label_3);

    QFrame *line = new QFrame(this);
    line->setObjectName("horizontalLine");
    line->setMinimumSize(QSize(0, 1));
    line->setMaximumSize(QSize(16777215, 1));
    verticalLayout->addWidget(line);

    m_newLabel = new Gui::Label(this);
    m_newLabel->setMinimumHeight(30);
    m_newLabel->setMaximumHeight(30);
    verticalLayout->addWidget(m_newLabel);

    scrollArea = new QScrollArea(this);
    scrollArea->setObjectName("scrollArea");
    scrollArea->setMinimumSize(QSize(0, 200));
    scrollArea->setMaximumSize(QSize(16777215, 200));
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1137, 178));
    scrollArea->setWidget(scrollAreaWidgetContents);
    verticalLayout->addWidget(scrollArea);



    QHBoxLayout *hl = new QHBoxLayout(scrollAreaWidgetContents);
    hl->setContentsMargins(0,0,0,0);
    hl->setSpacing(65);

    m_newBlank = new StartItem(scrollAreaWidgetContents);
    m_newBlank->setMinimumSize(200, 200);
    m_newBlank->setMaximumSize(200, 200);
    m_newBlank->setIcon(":/sival/light/enclosure.svg");
    hl->addWidget(m_newBlank);



    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    hl->addItem(spacer);

    line = new QFrame(this);
    line->setObjectName("horizontalLine2");
    line->setMinimumSize(QSize(0, 1));
    line->setMaximumSize(QSize(16777215, 1));
    verticalLayout->addWidget(line);


    m_recentProjects = new Gui::Label(this);
    m_recentProjects->setMinimumHeight(30);
    m_recentProjects->setMaximumHeight(30);
    verticalLayout->addWidget(m_recentProjects);



    scrollArea_2 = new QScrollArea(this);
    scrollArea_2->setObjectName("scrollArea_2");
    scrollArea_2->setWidgetResizable(true);
    scrollAreaWidgetContents_2 = new QWidget();
    scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
    scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1137, 661));
    scrollArea_2->setWidget(scrollAreaWidgetContents_2);

    m_recentLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
    m_recentLayout->setContentsMargins(0, 0, 0, 0);
    m_recentLayout->setSpacing(0);
    spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    m_recentLayout->addItem(spacer);

    verticalLayout->addWidget(scrollArea_2);
    retranslateUI();
}

/**************************************************************************************************/
/**
 *
 */
StartPanel::~StartPanel() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void StartPanel::retranslateUI() {
    m_newLabel->setText(tr("New"));
    m_newBlank->setTitle(tr("Empty Project"));

    m_recentProjects->setText(tr("Recent Projects"));
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
}
