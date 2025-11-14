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
//// end system includes

//// begin project specific includes
#include "recentprojectcard.hpp"
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
RecentProjectCard::RecentProjectCard(const QString &title, const QString &info, QWidget *parent)
    :SiVAL::Card(parent) {

    m_sTitle = title;
    infoText = info;
    setIcon(":/sival/project_dark.svg");
    // setChecvron(true);
}

/**************************************************************************************************/
/**
 *
 */
RecentProjectCard::~RecentProjectCard() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void RecentProjectCard::mouseReleaseEvent(QMouseEvent *event) {
    if(this->rect().contains(event->pos())) {
        if(m_bPressed) {
            emit openRecent(infoText);
        }
    } else {
        m_bHovered = false;
    }
    m_bPressed = false;
    update();
    SiVAL::Card::mouseReleaseEvent(event);
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
