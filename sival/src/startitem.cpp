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
#include <QPainter>
#include <QStyleOption>
//// end system includes

//// begin project specific includes
#include "startitem.hpp"
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
StartItem::StartItem(const QString &title, QWidget *parent)
    :Gui::Card(title, QString(), parent) {
}

/**************************************************************************************************/
/**
 *
 */
StartItem::~StartItem() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void StartItem::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    // // Drawing the Background
    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    // Drawing the first Text
    painter.setPen(palette().color(QPalette::WindowText));
    painter.drawText(QRect(0, height() - 90, width(), 90), Qt::AlignCenter | Qt::AlignVCenter | Qt::TextSingleLine, m_sTitle);

    if(m_pIconRenderer) {
        m_pIconRenderer->render(&painter, QRectF(50, 40, height() - 100, height() - 100));
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
