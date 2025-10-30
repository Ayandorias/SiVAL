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
#include "recentprjpage.hpp"
#include "ui_recentprjpage.h"
#include "recentprojectcard.hpp"
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
RecentPrjPage::RecentPrjPage(QWidget *parent)
    :QWidget(parent), ui(new Ui::RecentPrjPage) {
    ui->setupUi(this);
    pos = 1;

    // QWidget *widget = new QWidget(this);
    // widget->setObjectName("widget");
    // widget->setStyleSheet("background-color: #000;");

    // widget->setMinimumSize(QSize(0, 64));
    // widget->setMaximumSize(QSize(16777215, 64));

    // ui->verticalLayout->addWidget(widget);




    // widget = new QWidget(this);
    // widget->setObjectName("widget");
    // widget->setStyleSheet("background-color: #000;");

    // widget->setMinimumSize(QSize(0, 64));
    // widget->setMaximumSize(QSize(16777215, 64));
    // ui->verticalLayout->insertWidget(1, widget);
}

/**************************************************************************************************/
/**
 *
 */
RecentPrjPage::~RecentPrjPage() {
    delete ui;
}

void RecentPrjPage::createCard(QJsonObject prj) {
    RecentProjectCard *card = new RecentProjectCard(prj["name"].toString(), prj["filepath"].toString(), this);
    card->setObjectName("widget");
    card->setMinimumSize(QSize(0, 64));
    card->setMaximumSize(QSize(16777215, 64));
    ui->verticalLayout->insertWidget(pos++, card);
    connect(card, &RecentProjectCard::openRecent, this, &RecentPrjPage::openProject);
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
