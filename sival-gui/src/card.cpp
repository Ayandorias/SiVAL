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
#include <QStyleOption>
//// end system includes

//// begin project specific includes
#include <iostream>
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
namespace Gui {

//// begin public member methods
Card::Card(const QString &title, const QString &info, QWidget *parent)
    : QWidget(parent), m_sTitle(title), m_infoText(info){

    m_bHovered = false;
    m_bPressed = false;
    setMouseTracking(true);
    setMinimumHeight(64);
    setMaximumHeight(64);

    m_pIconRenderer = nullptr; //
    m_bChecvron = false;
    m_pChevronRenderer = new QSvgRenderer(QString::fromUtf8(":/icon/chevron-right_dark.svg"), this);
}
/**************************************************************************************************/
/**
 *
 */
Card::~Card() {
}

QString Card::info() {
    return m_infoText;
}
void Card::setChevron(bool enable) {
    m_bChecvron = enable;
}
void Card::setIcon(const QString &icon) {
    m_pIconRenderer = new QSvgRenderer(icon, this);
}
void Card::setInfo(const QString &info) {
    m_infoText = info;
}

void Card::setTitle(const QString &title) {
    m_sTitle = title;
}

void Card::setInfoColor(const QColor &color) {
    m_infoColor = color;
    update(); // Wichtig: Neuzeichnen anfordern
}
QColor Card::getInfoColor() const { return m_infoColor; }
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void Card::enterEvent(QEnterEvent * event) {
    m_bHovered = true;
    update();
    QWidget::enterEvent(event);
}
void Card::leaveEvent(QEvent *event) {
    m_bHovered = false;
    update();
    QWidget::leaveEvent(event);
}

void Card::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);

}
void Card::mousePressEvent(QMouseEvent *event) {
    m_bPressed = true;
    update();
}
void Card::mouseReleaseEvent(QMouseEvent *event) {
    if(this->rect().contains(event->pos())) {
        if(m_bPressed) {
            emit clicked();
            emit infoText(m_infoText);
        }
    } else {
        m_bHovered = false;
    }
    m_bPressed = false;
    update();
    QWidget::mouseReleaseEvent(event);
}

void Card::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    // Drawing the Background
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    int y = 7;
    int div = 2;
    if(m_infoText.isEmpty()) {
        y = 0;
        div = 1;
    }
    // Drawing the first Text
    painter.setPen(palette().color(QPalette::WindowText));
    painter.drawText(QRect(height(), y, width() - height(), height() / div - y), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, m_sTitle);

    // Drawing the second Text
    painter.setPen(m_infoColor);
    painter.drawText(QRect(height(), height() / 2, width(), height() / 2 - 7), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, m_infoText);

    if(m_pIconRenderer) {
        m_pIconRenderer->render(&painter, QRectF(8, 8, height() - 16, height() - 16));
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
}
}
