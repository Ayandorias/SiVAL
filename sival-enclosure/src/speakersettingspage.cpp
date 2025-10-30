/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QString>
//// end system includes

//// begin project specific includes
#include "speakermanufacturercard.hpp"
#include "speakersettingspage.hpp"
#include "ui_speakersettingspage.h"
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
SpeakerSettingsPage::SpeakerSettingsPage(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::SpeakerSettingsPage) {

    ui->setupUi(this);

}

/**************************************************************************************************/
/**
 *
 */
SpeakerSettingsPage::~SpeakerSettingsPage() {
    delete ui;
}

/**
 *
 */
// void SpeakerSettingsPage::setDocument(ManufacturerDocument *doc) {
//     m_pDocument = doc;

//     QVector<SpeakerManufacturer*> list = doc->manufacturers();

//     for(SpeakerManufacturer *man : list) {

//         ui->verticalLayout->insertWidget(0, new SpeakerManufacturerCard(man, this));
//     }
// }
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
