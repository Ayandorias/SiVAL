/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin specific includes
#include "speakersettingswidget.hpp"
#include "ui_speakersettingswidget.h"
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
SpeakerSettingsWidget::SpeakerSettingsWidget(ManufacturerDocument *doc, QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::SpeakerSettingsWidget)
    , m_pDocument(doc) {

    ui->setupUi(this);
    ui->m_pSettingsPage->setDocument(doc);
}

/**************************************************************************************************/
/**
 *
 */
SpeakerSettingsWidget::~SpeakerSettingsWidget() {
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
