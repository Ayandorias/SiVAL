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
#include "projectenclosurepanel.hpp"
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
ProjectEnclosurePanel::ProjectEnclosurePanel(QWidget *parent)
    :QWidget(parent) {

    m_projectDocument = nullptr;

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
    QWidget *scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1137, 178));
    scrollArea->setWidget(scrollAreaWidgetContents);
    verticalLayout->addWidget(scrollArea);



    QHBoxLayout *hl = new QHBoxLayout(scrollAreaWidgetContents);
    hl->setContentsMargins(0,0,0,0);
    hl->setSpacing(65);

    m_sealedEnclosure = new StartItem(scrollAreaWidgetContents);
    m_sealedEnclosure->setMinimumSize(200, 200);
    m_sealedEnclosure->setMaximumSize(200, 200);
    m_sealedEnclosure->setIcon(":/sival/" + sSettings()->theme() + "/sealed.svg");
    connect(m_sealedEnclosure, &StartItem::clicked, this, &SiVAL::PM::ProjectEnclosurePanel::sealedEnclosure);
    hl->addWidget(m_sealedEnclosure);

    m_ventedEnclosure = new StartItem(scrollAreaWidgetContents);
    m_ventedEnclosure->setMinimumSize(200, 200);
    m_ventedEnclosure->setMaximumSize(200, 200);
    m_ventedEnclosure->setIcon(":/sival/" + sSettings()->theme() + "/vented.svg");
    connect(m_ventedEnclosure, &StartItem::clicked, this, &ProjectEnclosurePanel::ventedEnclosure);
    hl->addWidget(m_ventedEnclosure);




    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    hl->addItem(spacer);

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

    m_EnclosureList = new QVBoxLayout(scrollAreaWidgetContents_2);
    m_EnclosureList->setContentsMargins(0, 0, 0, 0);
    m_EnclosureList->setSpacing(0);
    spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    m_EnclosureList->addItem(spacer);

    verticalLayout->addWidget(scrollArea_2);

    retranslate();
}

/**************************************************************************************************/
/**
 *
 */
ProjectEnclosurePanel::~ProjectEnclosurePanel() {
}
void ProjectEnclosurePanel::update(SiVAL::Core::ProjectDocument *doc) {
    m_projectDocument = doc;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void ProjectEnclosurePanel::retranslate() {
    m_newLabel->setText(tr("New"));
    m_sealedEnclosure->setTitle(tr("Sealed Enclosure"));
    m_ventedEnclosure->setTitle(tr("Vented Enclosure"));

    m_projectEnclosures->setText(tr("Enlcosures in the project"));
}
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
}
