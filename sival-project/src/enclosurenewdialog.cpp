/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QDir>
#include <QVector>

#include <iostream>
//// end system includes

//// begin project specific includes
#include <sivalcore/sivalglobal.hpp>
#include "enclosurenewdialog.hpp"
#include "ui_enclosurenewdialog.h"
// #include "speakermanufacturer.hpp"
// #include "speakermanufacturercard.hpp"

// #include "settingsdocument.hpp"

#include <sivalgui/card.hpp>
#include <sivalcore/documents/speakerdocument.hpp>
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
namespace  SiVAL {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
EnclosureNewDialog::EnclosureNewDialog(/*ManufacturerDocument *doc, */QWidget *parent)
    :SiVAL::Gui::OverlayDialog(parent),
    ui(new Ui::EnclosureNewDialog)/*,
    m_pSpeakerSettingsDoc(doc) */{

    ui->setupUi(m_centerWidget);
    m_pLabel->setText(tr("SiVAL New Enclosure"));

    // m_pLastSelected = nullptr;

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
    connect(m_pAccept, &QPushButton::clicked, this, &EnclosureNewDialog::createNewEnclosure);

    // m_pPrevButton->hide();
    // m_pNextButton->hide();

    // SettingsDocument setdoc;
    ui->comboBox->hide();
    ui->comboBox_2->hide();
    ui->label_7->hide();
    ui->label_5->hide();
    ui->label_17->hide();
    ui->label_12->hide();
    ui->label_3->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_15->hide();
    ui->label_6->hide();
    ui->label_11->hide();
    ui->label_20->hide();
    ui->label_13->hide();
    ui->label_4->hide();
    ui->label_16->hide();
    ui->label_19->hide();
    ui->label_8->hide();
    ui->m_pQtsMin->hide();
    ui->m_pSPLMax->hide();
    ui->m_pFsMax->hide();
    ui->m_pSPLMin->hide();
    ui->m_pRMSMax->hide();
    ui->m_pFsMin->hide();
    ui->m_pRMSMin->hide();
    ui->m_pQtsMax->hide();
}

/**************************************************************************************************/
/**
 *
 */
EnclosureNewDialog::~EnclosureNewDialog() {
    delete ui;
}

// SpeakerDocument* EnclosureNewDialog::speaker() {
//     return m_pSpeakerDoc;
// }
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

    bool start = true;

    for(int i = 0; i < sSettings()->speakerCount(); i++) {
        SiVAL::Core::SpeakerDocument *doc = sSettings()->speaker(i);
        QVector<SiVAL::Core::ChassisManufacturer*> man = doc->manufacturerList();

        std::cout << __FILE__ << ":" << __FUNCTION__ << ":" << man.count() << "|" << man.size() << std::endl;
        for(int j = 0; j < man.count(); j++) {

            SiVAL::Core::ChassisManufacturer* m = man.at(j);
            std::cout << man.at(j)->name().toStdString() << std::endl;

            SiVAL::ManufacturerCard *card = new SiVAL::ManufacturerCard(ui->m_pManufacturer);
            card->setMinimumHeight(40);
            card->setMaximumHeight(40);
            card->setTitle(m->name());
            card->setManufacturer(m);
            card->setIcon(":/sival/" + sSettings()->theme() + "/check.svg");
            connect(card, &SiVAL::ManufacturerCard::clicked, this, &EnclosureNewDialog::changeSpeakerList);

            m_pVerticalLayout->insertWidget(j, card);

            if(start) {
                changeSpeakerList(card);
                start = false;
            }
        }
    }


    // QVector<SpeakerManufacturer*> man = m_pSpeakerSettingsDoc->manufacturers();
    // bool start = true;
    // int j = 0;
    // for(int i = 0; i < man.size(); ++i) {
    //     SpeakerManufacturer *m = man.at(i);
    //     if(m->isIndexed() == true) {
    //         SpeakerManufacturerCard *card = new SpeakerManufacturerCard(m, ui->m_pManufacturer, false);
    //         connect(card, &SpeakerManufacturerCard::selected, this, &EnclosureNewDialog::changeSpeakerList);
    //         m_pVerticalLayout->insertWidget(j++, card);

    //         if(start) {
    //             changeSpeakerList(m);
    //             start = false;
    //         }
    //     }
    // }
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
void EnclosureNewDialog::changeSpeakerList(SiVAL::Gui::Card *card) {//SpeakerManufacturer *man) {

    std::cout << card->title().toStdString() << std::endl;
    SiVAL::ManufacturerCard* derivedCard = qobject_cast<SiVAL::ManufacturerCard*>(card);

//     m_pAccept->setDisabled(true);
//     /// Löshe alle Fenster aus der Ansicht
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

    SiVAL::Core::ChassisManufacturer* m = derivedCard->manufacturer();
    std::cout << m->name().toStdString() << std::endl;

    if(m->name() == derivedCard->title()) {
        QVector<std::shared_ptr<SiVAL::Engine::AbstractDriver>> driver = m->chassisList();
        for(int k = 0; k < driver.count(); k++) {
            std::shared_ptr<SiVAL::Engine::AbstractDriver> d = driver.at(k);
            std::cout << d->model() << std::endl;
            SiVAL::SpeakerCard *chassis = new SiVAL::SpeakerCard(ui->m_pSpeaker);
            chassis->setTitle(QString::fromStdString(d->model()));
            chassis->setInfo(QString::fromStdString(d->speakerType()));
            chassis->setDriver(d);
            connect(chassis, &SiVAL::Gui::Card::clicked, this, &EnclosureNewDialog::speakerSelected);
            m_pSpeakerLayout->insertWidget(k, chassis);
        }
    }
}

void EnclosureNewDialog::createNewEnclosure() {
    emit newEnclosure(m_driver);
    close();
}

void EnclosureNewDialog::speakerSelected(SiVAL::Gui::Card *card){
    SiVAL::SpeakerCard* derivedCard = qobject_cast<SiVAL::SpeakerCard*>(card);
    m_driver = derivedCard->driver();

    std::cout << m_driver->model() << std::endl;
    m_pAccept->setDisabled(false);
//     if(m_pLastSelected) {
//         m_pLastSelected->setSelected(false);
//     }

//     m_pLastSelected = qobject_cast<SpeakerBrandCard*>(sender());
//     m_pSpeakerDoc = doc;

//     m_pAccept->setDisabled(false);
}
//// end protected slots

//// begin private slots
//// end private slots
}