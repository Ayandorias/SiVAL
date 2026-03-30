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
#include <iostream>
//// end system includes

//// begin project specific includes
#include "sivalcore/settings/lastprojectlist.hpp"
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
LastProjectList::LastProjectList(QJsonArray arr)
    :QObject() {
    m_array = arr;
    if(arr.isEmpty()) {
        std::cout << "Das Geht nicht so gut." << std::endl;
    }
}

/**************************************************************************************************/
/**
 *
 */
LastProjectList::~LastProjectList() {
}

void LastProjectList::add(const QString &project) {
    for (int i = 0; i < m_array.count(); ++i) {
        QString prj = m_array.at(i).toString();
        if(prj == project) {
            std::cout << "Project already bekannt" << std::endl;
            m_array.removeAt(i);
            break;
        }
    }

    m_array.prepend(project);
}

QJsonArray LastProjectList::array() {
    return m_array;
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
