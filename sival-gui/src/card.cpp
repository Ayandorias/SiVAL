/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <sivalgui/card.hpp>
#include <QPainter>
//// end system includes

//// begin project specific includes
// #include "ui_nw_card.h"
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
SiVAL::Card::Card(QWidget *parent)
:QWidget(parent) {

    init();
}

SiVAL::Card::Card(const QString &title, const QString &info, QWidget *parent)
    : QWidget(parent), m_sTitle(title), infoText(info){
    init();
}
/**************************************************************************************************/
/**
 *
 */
SiVAL::Card::~Card() {
}

QString SiVAL::Card::info() {
    return infoText;
}
void SiVAL::Card::setChecvron(bool enable) {
    m_bChecvron = enable;
}
void SiVAL::Card::setIcon(const QString &icon) {
    m_pIconRenderer = new QSvgRenderer(icon, this);
}
void SiVAL::Card::setInfo(const QString &info) {
    infoText = info;
}

void SiVAL::Card::setTitle(const QString &title) {
    m_sTitle = title;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SiVAL::Card::enterEvent(QEnterEvent * event) {
    m_bHovered = true;
    update();
    QWidget::enterEvent(event);
}
void SiVAL::Card::leaveEvent(QEvent *event) {
    m_bHovered = false;
    update();
    QWidget::leaveEvent(event);
}

void SiVAL::Card::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);

}
void SiVAL::Card::mousePressEvent(QMouseEvent *event) {
    m_bPressed = true;
    update();
}
void SiVAL::Card::mouseReleaseEvent(QMouseEvent *event) {
    if(this->rect().contains(event->pos())) {
        if(m_bPressed) {
            emit clicked();
        }
    } else {
        m_bHovered = false;
    }
    m_bPressed = false;
    update();
    QWidget::mouseReleaseEvent(event);
}

void SiVAL::Card::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QBrush brush;
    QBrush infoBrush;
    QPen pen;

    brush.setStyle(Qt::SolidPattern);
    infoBrush.setStyle(Qt::SolidPattern);

    if(m_bPressed) {
        brush.setColor(QColor(235, 235, 235));
    } else {
        if(m_bHovered) {
            brush.setColor(QColor(245, 245, 245));
        } else {
            brush.setColor(QColor(250, 250, 250));
        }
    }

    infoBrush.setColor(QColor(225, 225, 225));

    pen.setColor(QColor(240, 240, 240));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRoundedRect(1, 1, width() - 2, height() - 2, 8, 8);

    if(m_pIconRenderer) {
        m_pIconRenderer->render(&painter, QRectF(8, 8, 48, 48));
    }
    if(m_bChecvron) {
        m_pChevronRenderer->render(&painter, QRectF(width() - 48 - 8, 8, 48, 48));
    }

    pen.setColor(QColor(60, 60, 60));
    painter.setPen(pen);
    painter.drawText(QRect(80, 7, width(), height() / 2 - 7), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, m_sTitle);

    pen.setColor(QColor(160, 160, 160));
    painter.setPen(pen);
    painter.drawText(QRect(80, height() / 2, width(), height() / 2 - 7), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, infoText);
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void SiVAL::Card::init() {
    m_bHovered = false;
    m_bPressed = false;
    setMouseTracking(true);
    setMinimumHeight(64);
    setMaximumHeight(64);

    m_pIconRenderer = nullptr; //
    m_bChecvron = false;
    m_pChevronRenderer = new QSvgRenderer(QString::fromUtf8(":/icon/chevron-right_dark.svg"), this);
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
