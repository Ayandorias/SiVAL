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
#include "startnewtemplate.hpp"
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
StartNewTemplate::StartNewTemplate(QWidget *parent)
    : QWidget(parent)
    /*, ui(new Ui::StartNewTemplate) */{
    // ui->setupUi(this);

    m_layout = new QHBoxLayout(this);
    m_layout->setSpacing(20);

    m_bookShelf = new SiVAL::StartItem(this);
    m_bookShelf->setObjectName("m_bookShelf");
    m_bookShelf->setMinimumSize(QSize(200, 200));
    m_bookShelf->setMaximumSize(QSize(200, 200));
    m_bookShelf->setIcon(":/sival/" + sSettings()->theme() + "/enclosure.svg");
    connect(m_bookShelf, &SiVAL::Gui::Card::clicked, this, &SiVAL::StartNewTemplate::newProject);
    m_layout->addWidget(m_bookShelf);

    m_floorStand = new SiVAL::StartItem(this);
    m_floorStand->setObjectName("m_floorStand");
    m_floorStand->setMinimumSize(QSize(200, 200));
    m_floorStand->setMaximumSize(QSize(200, 200));
    m_floorStand->setIcon(":/sival/" + sSettings()->theme() + "/enclosure.svg");
    connect(m_floorStand, &SiVAL::Gui::Card::clicked, this, &SiVAL::StartNewTemplate::newProject);
    m_layout->addWidget(m_floorStand);

    m_spacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    m_layout->addItem(m_spacer);

    retranslateUi();
}

/**************************************************************************************************/
/**
 *
 */
StartNewTemplate::~StartNewTemplate() {
    // delete ui;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void StartNewTemplate::retranslateUi() {
    m_bookShelf->setTitle(tr("Bookshelf Speaker"));
    m_floorStand->setTitle(tr("Floorstanding Speaker"));
}
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void StartNewTemplate::newProject () {
    QObject *obj = sender();
    if(obj == m_bookShelf) {
        emit createNewProject(SiVAL::ProjectNew::BookShelf);
    } else if(obj == m_floorStand) {
        emit createNewProject(SiVAL::ProjectNew::FloorStand);
    }
}
//// end protected slots

//// begin private slots
//// end private slots
}