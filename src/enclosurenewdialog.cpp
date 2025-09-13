/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDir>
#include <QVector>

#include <iostream>
//// end includes

//// begin specific includes
#include "enclosurenewdialog.hpp"
#include "ui_enclosurenewdialog.h"
#include "speakermanufacturer.hpp"
#include "speakermanufacturercard.hpp"

#include "settingsdocument.hpp"
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
EnclosureNewDialog::EnclosureNewDialog(ManufacturerDocument *doc, QWidget *parent)
    :NW::OverlayDialog(parent),
    ui(new Ui::EnclosureNewDialog),
    m_pSpeakerSettingsDoc(doc) {

    ui->setupUi(m_pCenterWidget);
    m_pLabel->setText(tr("SiVAL New Enclosure"));

    m_pLastSelected = nullptr;

    QDoubleValidator *validator = new QDoubleValidator(0, 99999, 2, ui->m_pFsMin);
    ui->m_pFsMin->setValidator(validator);

    validator = new QDoubleValidator(0, 99999, 2, ui->m_pFsMax);
    ui->m_pFsMax->setValidator(validator);
    validator = new QDoubleValidator(0, 99999, 2, ui->m_pQtsMax);
    ui->m_pQtsMax->setValidator(validator);
    validator = new QDoubleValidator(0, 99999, 2, ui->m_pQtsMin);
    ui->m_pQtsMin->setValidator(validator);
    validator = new QDoubleValidator(0, 99999, 2, ui->m_pRMSMin);
    ui->m_pRMSMin->setValidator(validator);
    validator = new QDoubleValidator(0, 99999, 2, ui->m_pRMSMax);
    ui->m_pRMSMax->setValidator(validator);
    validator = new QDoubleValidator(0, 99999, 2, ui->m_pSPLMax);
    ui->m_pSPLMax->setValidator(validator);
    validator = new QDoubleValidator(0, 99999, 2, ui->m_pSPLMin);
    ui->m_pSPLMin->setValidator(validator);


    m_pVerticalLayout = new QVBoxLayout(ui->m_pManufacturer);
    m_pVerticalLayout->setObjectName("verticalLayout");
    m_pVerticalSpacer = new QSpacerItem(20, 608, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    m_pVerticalLayout->addItem(m_pVerticalSpacer);



    m_pSpeakerLayout = new QVBoxLayout(ui->m_pSpeaker);
    m_pSpeakerLayout->setObjectName("speakervertical");
    m_pVerticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    m_pSpeakerLayout->addItem(m_pVerticalSpacer);



    buildManufacturerList();

    m_pAccept->setText(tr("Erstellen"));
    m_pAccept->setDisabled(true);
    connect(m_pAccept, &QPushButton::clicked, this, &EnclosureNewDialog::newEnclosure);

    m_pPrevButton->hide();
    m_pNextButton->hide();

    SettingsDocument setdoc;
}

/**************************************************************************************************/
/**
 *
 */
EnclosureNewDialog::~EnclosureNewDialog() {
    delete ui;
}

SpeakerDocument* EnclosureNewDialog::speaker() {
    return m_pSpeakerDoc;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
/**
 * @brief Creates the view where you can select a Manufacturer from a list. The amount of manufacturers are set in the settings page.
 */
void EnclosureNewDialog::buildManufacturerList() {
    QVector<SpeakerManufacturer*> man = m_pSpeakerSettingsDoc->manufacturers();
    bool start = true;
    int j = 0;
    for(int i = 0; i < man.size(); ++i) {
        SpeakerManufacturer *m = man.at(i);
        if(m->isIndexed() == true) {
            SpeakerManufacturerCard *card = new SpeakerManufacturerCard(m, ui->m_pManufacturer, false);
            connect(card, &SpeakerManufacturerCard::selected, this, &EnclosureNewDialog::changeSpeakerList);
            m_pVerticalLayout->insertWidget(j++, card);

            if(start) {
                changeSpeakerList(m);
                start = false;
            }
        }
    }
}
/**
 * @brief Clears the view for the speakers. When you click on a manufacturer the speaker list will be cleared for the new speakerlsit.
 */
void EnclosureNewDialog::clearSpeakerList() {

}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void EnclosureNewDialog::changeSpeakerList(SpeakerManufacturer *man) {

    m_pAccept->setDisabled(true);
    /// Löshe alle Fenster aus der Ansicht
    while (m_pSpeakerLayout->count() > 0) {
        QLayoutItem *item = m_pSpeakerLayout->takeAt(0); // Nimm das erste Element
        if (item) {
            QWidget *widget = item->widget();
            if (widget) {
                widget->close(); // Schließt das Widget, bevor es gelöscht wird
                widget->deleteLater(); // Plant das Widget zur Löschung
            } else {
                // Wenn es kein Widget ist (z.B. QSpacerItem),
                // muss es auch gelöscht werden, falls es dynamisch alloziert wurde.
                // Standard-Layouts wie QVBoxLayout erstellen QSpacerItem oft selbst,
                // aber zur Sicherheit kann man es hier löschen.
                // delete item;
            }
        }
    }

    QVector<SpeakerManufacturer*> sm = m_pSpeakerSettingsDoc->manufacturers();
    bool start = true;

    for(int i = 0; i < sm.size(); ++i) {
        SpeakerManufacturer *m = sm.at(i);
        if(m->name() == man->name()) {

            QVector<SpeakerDocument*> docs = m->speakerList();
            for(int j = 0; j < docs.size(); ++j) {
                SpeakerDocument *doc = docs.at(j);
                SpeakerBrandCard *card = new SpeakerBrandCard(doc, ui->m_pSpeaker);
                connect(card, &SpeakerBrandCard::selected, this, &EnclosureNewDialog::speakerSelected);
                card->setTitle(doc->model());
                card->setInfo(doc->uuid());
                m_pSpeakerLayout->insertWidget(j, card);
            }
        }

    }
}

void EnclosureNewDialog::speakerSelected(SpeakerDocument *doc){

    if(m_pLastSelected) {
        std::cout << "Hier wird was geändert" << std::endl;
        m_pLastSelected->setSelected(false);
    }

    m_pLastSelected = qobject_cast<SpeakerBrandCard*>(sender());
    m_pSpeakerDoc = doc;

    m_pAccept->setDisabled(false);
}
//// end protected slots

//// begin private slots
//// end private slots
