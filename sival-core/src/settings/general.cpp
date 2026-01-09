/*
 * SiVAL Core
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
#include "sivalcore/settings/general.hpp"
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

namespace SiVAL::Core {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
General::General(QJsonObject obj)
    :QObject() {

    if(obj["theme"].isString()) {
        m_object["theme"] = obj["theme"].toString();
    } else {
        m_object["theme"] = "auto";
    }
    m_object["openLastPrj"] = false;


m_language = "en_EN";
m_unit_system = tr("Metric");
m_decimal_precision =  2;

m_recent_projects = QStringList();
m_max_recent_items = 10;
m_show_splash_screen = true;



}

/**************************************************************************************************/
/**
 *
 */
General::~General() {
}

QJsonObject General::object() {
    return m_object;
}

QString General::currentTheme() {
    return m_object["theme"].toString();
}
void General::setCurrentTheme(const QString &theme) {
    std::cout << "theme wird neu gesetzt: " << theme.toStdString() << std::endl;
    m_object["theme"] = theme;
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
