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
#include <QFile>
//// end system includes

//// begin project specific includes
#include "projectcard.hpp"
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
ProjectCard::ProjectCard(const QString &filename, QWidget *parent)
    :SiVAL::Gui::Card(parent) {
    if(QFile::exists(filename)) {
        m_projectDoc = SiVAL::Core::ProjectDocument::open(filename);
        setTitle(m_projectDoc->projectName());
        setIcon(":/sival/" + sSettings()->theme() + "/enclosure.svg");
    }
}

/**************************************************************************************************/
/**
 *
 */
ProjectCard::~ProjectCard() {
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