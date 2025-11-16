/*
 * AetheriumArchivar
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QScrollArea>
#include <QToolButton>
#include <sivalgui/navigationwidget.hpp>
#include <sivalgui/navigationbutton.hpp>
#include <QScroller>
//// end system includes

//// begin project specific includes
// #include "ui_navbarpanel.h"
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
NavigationWidget::NavigationWidget(QWidget *parent)
    :QWidget(parent) {
    setProperty("class", "SiVALNavigationWidget");
    setAttribute(Qt::WA_StyledBackground, true);

    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setObjectName("verticalLayout");
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    m_header = new HeaderLabel(this);
    m_header->setMinimumSize(QSize(0, 40));
    m_header->setMaximumSize(QSize(16777215, 40));
    verticalLayout->addWidget(m_header);

    m_navStack = new QStackedWidget(this);
    m_navStack->setObjectName("stackedWidget");
    verticalLayout->addWidget(m_navStack);
}
NavigationWidget::~NavigationWidget() {
}

void NavigationWidget::addWidget(QWidget *widget) {
    m_navStack->addWidget(widget);
}

int NavigationWidget::currentIndex() {
    return m_navStack->currentIndex();
}

void NavigationWidget::setCurrentIndex(int index) {
    m_navStack->setCurrentIndex(index);
}

void NavigationWidget::setHeader(const QString &header) {
    m_header->setText(header);
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
}
