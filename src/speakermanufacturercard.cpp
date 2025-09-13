/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QPainter>
//// end includes

//// begin specific includes
#include "speakermanufacturercard.hpp"
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
SpeakerManufacturerCard::SpeakerManufacturerCard(SpeakerManufacturer *man, QWidget *parent, bool indexed)
    :NW::Card(parent), m_pManufacturer(man) {
    m_bWithIndex = indexed;
    m_sTitle = man->name();
    m_sInfoText = tr("Available chassis: %1").arg(man->chassisList().count());

    m_pCheckRenderer = new QSvgRenderer(QString::fromUtf8(":/sival/checked_dark.svg"), this);
    m_pUncheckRenderer = new QSvgRenderer(QString::fromUtf8(":/sival/unchecked_dark.svg"), this);
}

/**************************************************************************************************/
/**
 *
 */
SpeakerManufacturerCard::~SpeakerManufacturerCard() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SpeakerManufacturerCard::mouseReleaseEvent(QMouseEvent *event) {
    if(this->rect().contains(event->pos())) {
        if(m_bPressed) {
            if(m_bWithIndex) {
                if(m_pManufacturer->isIndexed()) {
                    m_pManufacturer->indexed(false);
                } else {
                    m_pManufacturer->indexed(true);
                }
            }

            emit selected(m_pManufacturer);
        }
    }

    NW::Card::mouseReleaseEvent(event);
}
void SpeakerManufacturerCard::paintEvent(QPaintEvent *event) {
    NW::Card::paintEvent(event);

    if(m_bWithIndex) {
        QPainter painter(this);

        if(m_pManufacturer->isIndexed()) {
            m_pCheckRenderer->render(&painter, QRectF(8, 8, 48, 48));
        } else {
            m_pUncheckRenderer->render(&painter, QRectF(8, 8, 48, 48));
        }
    }
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
