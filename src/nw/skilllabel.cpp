/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <iostream>
#include <QHashIterator>
#include <QPainter>
//// end includes

//// begin specific includes
#include "nw/skilllabel.hpp"
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
NW::SkillLabel::SkillLabel(const QString &label, QWidget *parent)
:QLabel(parent) {
    m_sLabel = label;
    m_sSep = QString (": ");
    m_bLast = false;
    setMinimumHeight(64);
    setMaximumHeight(64);
    m_pIconRenderer = nullptr;
    m_bSubentry = false;
    m_iSubentry = 0;
}

/**************************************************************************************************/
/**
 *
 */
NW::SkillLabel::~SkillLabel() {
}
void NW::SkillLabel::addInfoText(const QString &key, const QString &value, bool dummy) {
    map.append(qMakePair(key, value));
    m_bDummy = dummy;
}
void NW::SkillLabel::last() {
    m_bLast = true;
}
void NW::SkillLabel::setIcon(const QString &icon) {
    m_pIconRenderer = new QSvgRenderer(icon, this);
}
void NW::SkillLabel::setSeparator(const QString &sep) {
    m_sSep = sep;
}
void NW::SkillLabel::setSubentry(bool entry) {
    m_bSubentry = entry;
    if(m_bSubentry) {
        m_iSubentry = 20;
    }
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void NW::SkillLabel::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QBrush brush;
    QBrush infoBrush;
    QPen pen;

    infoBrush.setStyle(Qt::SolidPattern);
    infoBrush.setColor(QColor(225, 225, 225));

    painter.fillRect(rect(), QColor(255, 255, 255));

    pen.setColor(QColor(235, 235, 235));
    painter.setPen(pen);
    if(m_bLast) {
        painter.drawRect(0,0, width() - 1, height() - 1);
    } else {
        painter.drawRect(0,0, width() - 1, height());
    }

    pen.setColor(QColor(96, 96, 96));
    QFont font = painter.font();
    int ps = font.pointSize();
    font.setPointSize(13);
    painter.setFont(font);
    painter.setPen(pen);
    if(m_bDummy) {
        painter.drawText(QRect(10 + m_iSubentry, 3, width(), height() - 6), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, m_sLabel);
    } else {
        painter.drawText(QRect(10 + m_iSubentry, 3, width(), height() / 2 - 3), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, m_sLabel);
    }

    font.setPointSize(ps);
    painter.setFont(font);
    pen.setColor(QColor(160, 160, 160));
    painter.setPen(pen);

    int x = width() - 50;
    QFontMetrics fm(painter.font());
    // i.toBack();

    for(int i = 0; i < map.size(); ++i) {
        QPair<QString, QString> p = map.at(i);
        if(i == 0) {
            painter.drawText(QRect(10 + m_iSubentry, height() / 2, width(), height() / 2- 3), Qt::AlignLeft | Qt::AlignVCenter, p.first + m_sSep + p.second);
        } else {
            QString label = p.first + m_sSep + p.second;
            int length = fm.horizontalAdvance(p.second);

            QFont font = painter.font();
            font.setBold(true);
            painter.setFont(font);
            int keylength = fm.horizontalAdvance(p.first + m_sSep);

            x = x - length - keylength - 40;
            painter.drawRoundedRect(x, 15, keylength + length + 25, height() - 30, 5, 5);
            painter.drawText(QRect(x + 10, 3, keylength + 5, height() - 6), Qt::AlignHCenter | Qt::AlignVCenter, p.first + m_sSep);
            font.setBold(false);
            painter.setFont(font);
            painter.drawText(QRect(x + keylength + 15, 3, length, height() - 6), Qt::AlignHCenter | Qt::AlignVCenter, p.second);
        }
        x -= 40;
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
