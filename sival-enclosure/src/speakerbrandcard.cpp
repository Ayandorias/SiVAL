/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QPainter>
//// end system includes

//// begin project specific includes
#include "speakerbrandcard.hpp"
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
SpeakerBrandCard::SpeakerBrandCard(QWidget *parent)
    :SiVAL::Card(parent){
    setAttribute(Qt::WA_DeleteOnClose);

    m_bSelected = false;
    m_pCheckRenderer = new QSvgRenderer(QString::fromUtf8(":/icon/check_dark.svg"), this);
}

/**************************************************************************************************/
/**
 *
 */
SpeakerBrandCard::~SpeakerBrandCard() {
}

void SpeakerBrandCard::setSelected(bool selected) {
    m_bSelected = selected;
    update();
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SpeakerBrandCard::mouseReleaseEvent(QMouseEvent *event) {
    if(this->rect().contains(event->pos())) {
        if(m_bPressed) {
            if(m_bSelected) {
                m_bSelected = false;
            } else {
                m_bSelected = true;
            }
            // emit selected(m_pSpeakerDoc);
        }
    }

    SiVAL::Card::mouseReleaseEvent(event);
}
void SpeakerBrandCard::paintEvent(QPaintEvent *event) {
    SiVAL::Card::paintEvent(event);

    if(m_bSelected) {
        QPainter painter(this);
        m_pCheckRenderer->render(&painter, QRectF(8, 16, 32, 32));

        // if(m_pManufacturer->isIndexed()) {
        // } else {
        //     m_pUncheckRenderer->render(&painter, QRectF(8, 8, 48, 48));
        // }
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
