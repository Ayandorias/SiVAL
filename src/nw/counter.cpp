/*
 * Nebenwelten$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QPaintEvent>
//// end includes

//// begin specific includes
#include "nw/counter.hpp"
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
NW::Counter::Counter(QWidget *parent)
:QWidget(parent) {
    setMouseTracking(true);
    setMinimumHeight(35);
    setMaximumHeight(35);
    button = false;
    m_iIconHeight = m_iIconWidth = height() -4;
    m_iPaddingLeft = m_iPaddingRight = 2;
    m_iValue = m_iMinimumValue = 0;
    m_iMaximumValue = 99;
    m_pRightIcon = new QSvgRenderer(QString::fromUtf8(":/icon/chevron-up_dark.svg"), this);
}

/**************************************************************************************************/
/**
 *
 */
NW::Counter::~Counter() {
}
int NW::Counter::maximum() {
    return m_iMaximumValue;
}
int NW::Counter::minimum() {
    return m_iMinimumValue;
}
void NW::Counter::setMaximum(int value) {
    m_iMaximumValue = value;
}
void NW::Counter::setMinimum(int value) {
    m_iMinimumValue = value;
    emit valueChanged(value);
}
void NW::Counter::setValue(int value) {
    m_iValue = value;
    emit valueChanged(value);
}
int NW::Counter::value() {
    return m_iValue;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void NW::Counter::leaveEvent(QEvent *event) {
    Q_UNUSED(event);
    button = false;
    update();
}
void NW::Counter::mousePressEvent(QMouseEvent *event) {
    if(m_iValue >= m_iMaximumValue) {
        return;
    }
    if(event->pos().x() > width() - m_iIconWidth - m_iPaddingRight && event->pos().x() < width() - m_iPaddingRight) {
        ++m_iValue;
        emit incremented();
        update();
    }
}
void NW::Counter::mouseMoveEvent(QMouseEvent *event) {
    bool b = button;
    if(event->pos().x() > width() - m_iIconWidth - m_iPaddingRight && event->pos().x() < width() - m_iPaddingRight) {
        b = true;
    } else {
        b = false;
    }
    if(b != button) {
        button = b;
        update();
    }
}
void NW::Counter::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(250, 250, 250));
    painter.setBrush(brush);
    QPen pen;
    pen.setColor(QColor(240, 240, 240));
    painter.setPen(pen);
    painter.drawRoundedRect(1, 1, width() - 2, height() - 2, 8, 8);

    painter.setPen(Qt::NoPen);
    brush.setColor(QColor(235, 235, 237));
    painter.setBrush(brush);
    if(button) {
        painter.drawRoundedRect(width() - m_iIconWidth - m_iPaddingRight, 2, m_iIconWidth, m_iIconHeight, m_iIconHeight / 4, m_iIconHeight / 4);
    }
    m_pRightIcon->render(&painter, QRect(width() - m_iIconWidth - m_iPaddingRight, 2, m_iIconWidth, m_iIconHeight));

    pen.setColor(QColor(96, 96, 96));
    painter.setPen(pen);
    painter.drawText(QRect(m_iPaddingLeft, 2, width() - m_iIconWidth - m_iPaddingRight, m_iIconHeight), Qt::AlignHCenter | Qt::AlignVCenter, QString::number(m_iValue));

    // QWidget::paintEvent(event);
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
