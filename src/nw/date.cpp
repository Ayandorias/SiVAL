/*
 * Nebenwelten$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin specific includes
#include "nw/date.hpp"
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
NW::Date::Date() {
    init();
}
NW::Date::Date(int day, int month, int year) {
    init();
}
NW::Date::Date(quint64 sec) {
    init();
}

/**************************************************************************************************/
/**
 *
 */
NW::Date::~Date() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void NW::Date::init() {
    SECPERMIN = 60;
    SECPERHOUR = SECPERMIN * 60;
    SECPERDAY = SECPERHOUR * 24;
    SECPERMONTH = SECPERDAY * 30;
    SECPERYEAR = SECPERMONTH * 12;
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
