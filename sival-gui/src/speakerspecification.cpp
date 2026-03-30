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

#include <iostream>
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
SpeakerSpecification::SpeakerSpecification(Core::SpeakerDocument *doc, QWidget *parent)
    :QWidget(parent) {
    m_doc = doc;

    m_speakerLayout = new QGridLayout(this);
    m_speakerLayout->setContentsMargins(0, 0, 0, 0);
    m_speakerLayout->setSpacing(0);
    setMinimumHeight(72);
    setMaximumHeight(72);

    m_title = new HeaderLabel(this);
    m_title->setMaximumHeight(40);
    m_speakerLayout->addWidget(m_title, 0, 0, 1, 2);

    ////////////////////////////////////////////////////
    m_volume = new QLabel(this);
    m_volume->setMaximumHeight(32);
    m_speakerLayout->addWidget(m_volume, 1, 0, 1, 1);

    m_volSpinner = new SpinWidget(this);
    m_speakerLayout->addWidget(m_volSpinner, 1, 1, 1, 1);
    //////////////////////////////////////////////////////
    m_damping = new Label(this);
    m_damping->setMaximumHeight(32);
    m_damping->setText(tr("Damping (%)"));
    m_speakerLayout->addWidget(m_damping, 2, 0, 1, 1);

    m_dampingSpinner = new SpinWidget(this);
    m_dampingSpinner->setMinimum(0);
    m_dampingSpinner->setMaximum(25);
    m_speakerLayout->addWidget(m_dampingSpinner, 2, 1, 1, 1);
    //////////////////////////////////////////////////////

    QString header = m_doc->name() + QString(" - ") + m_doc->type();
    m_title->setText(header);
    double volume;
    QString unit;
    m_doc->volume(volume, unit);
    m_volume->setText(tr("Volume (") + unit + QString(")"));
    m_volSpinner->setValue(volume);
    m_dampingSpinner->setValue(m_doc->damping());
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