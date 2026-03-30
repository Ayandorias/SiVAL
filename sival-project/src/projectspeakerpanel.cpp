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
#include <QApplication>
#include <QInputDialog>
#include <QMainWindow>

#include <sival/abstractions/enclosure.hpp>
#include <iostream>
//// end system includes

//// begin project specific includes
#include <sivalcore/documents/speakerdocument.hpp>
#include <sivalgui/inputdialog.hpp>
#include <enclosurenewdialog.hpp>
#include "projectspeakerpanel.hpp"
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

namespace SiVAL::PM {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
ProjectSpeakerPanel::ProjectSpeakerPanel(QWidget *parent)
    :QWidget(parent) {

    m_enclosureNew = nullptr;
    m_speakerNew = nullptr;
    m_projectDocument = nullptr;
    m_spkrDoc = nullptr;

    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName("verticalLayout");

    // QLabel *label_3 = new QLabel(this);
    // label_3->setObjectName("label_3");
    // label_3->setMinimumSize(QSize(120, 40));
    // label_3->setMaximumSize(QSize(120, 40));
    // label_3->setPixmap(QPixmap(QString::fromUtf8(":/sival/logo/sival_logo.svg")));
    // label_3->setScaledContents(true);
    // verticalLayout->addWidget(label_3);

    // SiVAL::Gui::Line *line = new SiVAL::Gui::Line(this);
    // verticalLayout->addWidget(line);

    m_newLabel = new Gui::Label(this);
    m_newLabel->setMinimumHeight(30);
    m_newLabel->setMaximumHeight(30);
    verticalLayout->addWidget(m_newLabel);

    m_newLabel->setText("Choose an enclosure to add to your Project.");

    scrollArea = new QScrollArea(this);
    scrollArea->setObjectName("scrollArea");
    scrollArea->setMinimumSize(QSize(0, 200));
    scrollArea->setMaximumSize(QSize(16777215, 200));
    scrollArea->setWidgetResizable(true);
    m_speakerWidget = new QWidget();
    m_speakerWidget->setObjectName("scrollAreaWidgetContents");
    m_speakerWidget->setGeometry(QRect(0, 0, 1137, 178));
    scrollArea->setWidget(m_speakerWidget);
    verticalLayout->addWidget(scrollArea);

    m_speakerLayout = new QHBoxLayout(m_speakerWidget);
    m_speakerLayout->setContentsMargins(0,0,0,0);
    m_speakerLayout->setSpacing(65);


    createSpeakerNew();



    line = new SiVAL::Gui::Line(this);
    verticalLayout->addWidget(line);


    m_projectEnclosures = new Gui::Label(this);
    m_projectEnclosures->setMinimumHeight(30);
    m_projectEnclosures->setMaximumHeight(30);
    verticalLayout->addWidget(m_projectEnclosures);

    scrollArea_2 = new QScrollArea(this);
    scrollArea_2->setObjectName("scrollArea_2");
    scrollArea_2->setWidgetResizable(true);
    QWidget *scrollAreaWidgetContents_2 = new QWidget();
    scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
    scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1137, 661));
    scrollArea_2->setWidget(scrollAreaWidgetContents_2);


    m_EnclosureList = new QHBoxLayout(scrollAreaWidgetContents_2);
    m_EnclosureList->setContentsMargins(0, 0, 0, 0);
    m_EnclosureList->setSpacing(65);

    verticalLayout->addWidget(scrollArea_2);

    retranslate();
}

/**************************************************************************************************/
/**
 *
 */
ProjectSpeakerPanel::~ProjectSpeakerPanel() {
}
void ProjectSpeakerPanel::update(SiVAL::Core::ProjectDocument *doc) {
    m_projectDocument = doc;

    clearSpeakerList();
    createSpeakerNew();

    m_spkrList= doc->speakerList();
    for(int i = 0; i < m_spkrList.count(); ++i) {
        SiVAL::Core::SpeakerDocument *spkr = m_spkrList.at(i);
        m_spkrDoc = spkr;
        speakerNew(spkr);
        clearEnclosureList();
        createEnclosureNew();
        QVector<QSharedPointer<SiVAL::Engine::AcousticSetup>> setup = spkr->enclosures();
        std::cout << "Anzahl Enclosures: " << setup.count() << std::endl;
        for(int j = 0; j < setup.count(); ++j) {
            QSharedPointer<SiVAL::Engine::AcousticSetup> as = setup.at(j);
            enclosureNew(as);
        }
    }

    retranslate();
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void ProjectSpeakerPanel::retranslate() {
    m_newLabel->setText(tr("New"));
    m_speakerNew->setTitle(tr("New Speaker..."));
    // m_ventedEnclosure->setTitle(tr("Vented Enclosure"));
    if(m_enclosureNew) {
        m_enclosureNew->setTitle(tr("New Enclosure..."));
    }

    QString docname;
    if(m_spkrDoc) {
        docname = m_spkrDoc->name();
    }
    m_projectEnclosures->setText(tr("Enlcosures: %1").arg(docname));
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void ProjectSpeakerPanel::clearEnclosureList() {
    while (QLayoutItem* item = m_EnclosureList->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }

    m_enclosureNew = nullptr;
}
void ProjectSpeakerPanel::clearSpeakerList() {
    while (QLayoutItem* item = m_speakerLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
}
void ProjectSpeakerPanel::createEnclosureNew() {
    m_enclosureNew = new SiVAL::Gui::EnclosureItem(m_speakerWidget);
    m_enclosureNew->setDocument(m_spkrDoc);
    m_enclosureNew->setMinimumSize(200, 200);
    m_enclosureNew->setMaximumSize(200, 200);
    m_enclosureNew->setIcon(":/sival/" + sSettings()->theme() + "/enclosure_new.svg");
    connect(m_enclosureNew, &SiVAL::Gui::StartItem::clicked, this, &SiVAL::PM::ProjectSpeakerPanel::createEnclosure);
    m_EnclosureList->addWidget(m_enclosureNew);

    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    m_EnclosureList->addItem(spacer);
}
void ProjectSpeakerPanel::createSpeakerNew() {
    m_speakerNew = new SiVAL::Gui::SpeakerItem(m_speakerWidget);
    m_speakerNew->setMinimumSize(200, 200);
    m_speakerNew->setMaximumSize(200, 200);
    m_speakerNew->setIcon(":/sival/" + sSettings()->theme() + "/speaker_new.svg");
    connect(m_speakerNew, &SiVAL::Gui::StartItem::clicked, this, &SiVAL::PM::ProjectSpeakerPanel::createSpeaker);
    m_speakerLayout->addWidget(m_speakerNew);

    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    m_speakerLayout->addItem(spacer);
}
void ProjectSpeakerPanel::enclosureNew(QSharedPointer<SiVAL::Engine::AcousticSetup> as) {
    SiVAL::Engine::AbstractEnclosure &enc = as->enclosure();

    SiVAL::Gui::EnclosureItem *enclosure = new SiVAL::Gui::EnclosureItem(m_speakerWidget);
    enclosure->setDocument(m_spkrDoc);
    enclosure->setMinimumSize(200, 200);
    enclosure->setMaximumSize(200, 200);

    std::cout << "Type: " << static_cast<int>(enc.type()) << " | " << static_cast<int>(SiVAL::Engine::EnclosureType::Sealed) << std::endl;
    switch(enc.type()) {
    case SiVAL::Engine::EnclosureType::Sealed: {
        enclosure->setIcon(":/sival/" + sSettings()->theme() + "/enclosure_sealed.svg");
        break;
    }
    default: {
        enclosure->setIcon(":/sival/" + sSettings()->theme() + "/enclosure_vented.svg");
        break;
    }
    }

    m_EnclosureList->insertWidget(0, enclosure);
}
void ProjectSpeakerPanel::speakerNew(SiVAL::Core::SpeakerDocument *spkr) {
    SiVAL::Gui::SpeakerItem *speaker = new SiVAL::Gui::SpeakerItem(m_speakerWidget);
    speaker->setMinimumSize(200, 200);
    speaker->setMaximumSize(200, 200);
    speaker->setIcon(":/sival/" + sSettings()->theme() + "/enclosure-fill.svg");
    connect(speaker, &SiVAL::Gui::SpeakerItem::clicked, this, &ProjectSpeakerPanel::speakerItemClicked);
    speaker->setDocument(spkr);
    speaker->setTitle(spkr->name());
    m_speakerLayout->insertWidget(0, speaker);
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void ProjectSpeakerPanel::createEnclosure() {
    QMainWindow* activeMain = qobject_cast<QMainWindow*>(QApplication::activeWindow());

    EnclosureNewDialog *dlg = new EnclosureNewDialog(activeMain);
    dlg->showNormal();
    dlg->raise();
    connect(dlg, &EnclosureNewDialog::newEnclosure, this, [this, dlg] {
        // m_spkrDoc->addEnclosure();
        auto setup = m_spkrDoc->createEnclosure(SiVAL::Engine::EnclosureType::Sealed);
        enclosureNew(setup);
        // (QSharedPointer<SiVAL::Engine::AcousticSetup>::create(std::make_shared<SiVAL::Engine::Environment>(), fileuuid.toStdString());
    });
}
void ProjectSpeakerPanel::createSpeaker() {
    QMainWindow* activeMain = qobject_cast<QMainWindow*>(QApplication::activeWindow());

    if (activeMain) {
        SiVAL::Gui::InputDialog *dlg = new SiVAL::Gui::InputDialog(tr("Create new speaker"), tr("Name for the new speaker."), activeMain);
        dlg->setAcceptLabel(tr("Create"));
        dlg->showNormal();
        dlg->raise();
        connect(dlg, &SiVAL::Gui::InputDialog::ok, this, [this, dlg] {
            SiVAL::Core::SpeakerDocument *doc = m_projectDocument->createSpeaker(dlg->text());
            speakerNew(doc);
            m_spkrDoc = doc;

            clearEnclosureList();
            createEnclosureNew();

            dlg->close();
        });
    }
}
void ProjectSpeakerPanel::speakerItemClicked(SiVAL::Gui::Card *card) {
    SiVAL::Gui::SpeakerItem *item = qobject_cast<SiVAL::Gui::SpeakerItem*>(card);
    m_spkrDoc = item->document();

    clearEnclosureList();
    createEnclosureNew();

    retranslate();

    QVector<QSharedPointer<SiVAL::Engine::AcousticSetup>> setup = m_spkrDoc->enclosures();
    std::cout << "Anzahl Enclosures: " << setup.count() << std::endl;
    for(int j = 0; j < setup.count(); ++j) {
        QSharedPointer<SiVAL::Engine::AcousticSetup> as = setup.at(j);
        enclosureNew(as);
    }
}
//// end protected slots

//// begin private slots
//// end private slots
}
