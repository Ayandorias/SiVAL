/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QPainter>

#include <iostream>
//// end includes

//// begin specific includes
#include "nw/card.hpp"
// #include "ui_nw_card.h"
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
NW::Card::Card(QWidget *parent)
:QWidget(parent) {//, ui(new Ui::Card) {
    //ui->setupUi(this);
    m_bHovered = false;
    m_bPressed = false;
    setMouseTracking(true);
    setMinimumHeight(64);
    setMaximumHeight(64);

    m_pIconRenderer = nullptr; //
    m_bChecvron = true;
    m_pChevronRenderer = new QSvgRenderer(QString::fromUtf8(":/icon/chevron-right_dark.svg"), this);
}

/**************************************************************************************************/
/**
 *
 */
NW::Card::~Card() {
}

void NW::Card::setChecvron(bool enable) {
    m_bChecvron = enable;
}
void NW::Card::setIcon(const QString &icon) {
    m_pIconRenderer = new QSvgRenderer(icon, this);
}
void NW::Card::setInfoText(const QString &info) {
    m_sInfoText = info;
}

void NW::Card::setInfoText2(const QString &info, const QString &value) {
    m_sInfoText2 = info + QString(": ") + value;
}

void NW::Card::setInfoText3(const QString &info, const QString &value) {
    m_sInfoText3 = info + QString(": ") + value;
}

void NW::Card::setTitle(const QString &title) {
    m_sTitle = title;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void NW::Card::enterEvent(QEnterEvent * event) {
    m_bHovered = true;
    update();
    QWidget::enterEvent(event);
}
void NW::Card::leaveEvent(QEvent *event) {
    m_bHovered = false;
    update();
    QWidget::leaveEvent(event);
}

void NW::Card::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);

}
void NW::Card::mousePressEvent(QMouseEvent *event) {
    m_bPressed = true;
    update();
}
void NW::Card::mouseReleaseEvent(QMouseEvent *event) {
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

void NW::Card::paintEvent(QPaintEvent *event) {
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
    painter.drawText(QRect(80, height() / 2, width(), height() / 2 - 7), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, m_sInfoText);

    QFontMetrics fm(painter.font());

    int startx = 0;
    int length = fm.horizontalAdvance(m_sInfoText);
    int length1 = fm.horizontalAdvance(m_sInfoText2);
    int length2 = fm.horizontalAdvance(m_sInfoText3);

    if(m_sInfoText2 != QString()) {
        startx = width() - 10 - length2 - length1 - 20 - 20 - 20;
        painter.setBrush(infoBrush);
        painter.setPen(Qt::NoPen);
        painter.drawRoundedRect(startx, height() / 2, length1 + 20, height() / 2 - 7, 12, 12);
        pen.setColor(QColor(48, 48, 48));
        painter.setPen(pen);
        painter.drawText(QRect(startx, height() / 2, length1 + 20, height() / 2 - 7), Qt::AlignHCenter | Qt::AlignVCenter | Qt::TextSingleLine, m_sInfoText2);
    }

    if(m_sInfoText3 != QString()) {
        startx = startx + length1 + 20 + 20;
        painter.setBrush(infoBrush);
        painter.setPen(Qt::NoPen);
        painter.drawRoundedRect(startx, height() / 2, length2 + 20, height() / 2 - 7, 12, 12);
        pen.setColor(QColor(48, 48, 48));
        painter.setPen(pen);
        painter.drawText(QRect(startx, height() / 2, length2 + 20, height() / 2 - 7), Qt::AlignHCenter | Qt::AlignVCenter | Qt::TextSingleLine, m_sInfoText3);
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
