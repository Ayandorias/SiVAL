/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin specific includes
#include "speakersettingspage.hpp"
#include "ui_speakersettingspage.h"

#include "nw/card.hpp"
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
SpeakerSettingsPage::SpeakerSettingsPage(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::SpeakerSettingsPage) {

    ui->setupUi(this);

    ui->verticalLayout->insertWidget(0, new NW::Card("Visaton", "120 Speaker", this));
}

/**************************************************************************************************/
/**
 *
 */
SpeakerSettingsPage::~SpeakerSettingsPage() {
    delete ui;
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
