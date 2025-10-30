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

#include <QToolButton>
//// end system includes

//// begin project specific includes
#include <sivalgui/titlebar.hpp>
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
SiVAL::TitleBar::TitleBar(QWidget *parent)
    :QWidget(parent) {
    setStyleSheet("background-color: #fff;");

    m_pLayout = new QHBoxLayout(this);
    QSpacerItem *horizontalSpacer = new QSpacerItem(896, 37, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    m_pLayout->addItem(horizontalSpacer);





}

/**************************************************************************************************/
/**
 *
 */
SiVAL::TitleBar::~TitleBar() {
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
