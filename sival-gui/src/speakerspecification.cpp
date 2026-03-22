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
#include <QDir>
#include <QFile>
//// end system includes

//// begin project specific includes
#include "sivalgui/speakerspecification.hpp"
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

namespace SiVAL::Gui {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
SpeakerSpecification::SpeakerSpecification(const QString &path, const QString &uuid, QWidget *parent)
    :QWidget(parent) {
    m_speakerLayout = new QGridLayout(this);

    m_title = new HeaderLabel(this);
    m_title->setText(uuid);
    m_speakerLayout->addWidget(m_title, 0, 0, 1, 2);

    m_volume = new QLabel(this);
    m_volume->setText(tr("Volume (l)"));
    m_speakerLayout->addWidget(m_volume, 1, 0, 1, 1);

    m_volSpinner = new SpinWidget(this);
    m_volSpinner->setValue(100);
    m_speakerLayout->addWidget(m_volSpinner, 1, 1, 1, 1);



    QString filename = path + QDir::separator() + uuid + QString(".sivalspkr");
    QFile file(filename);
    if(file.exists()) {

    }
}

/**************************************************************************************************/
/**
 *
 */
SpeakerSpecification::~SpeakerSpecification() {
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
}