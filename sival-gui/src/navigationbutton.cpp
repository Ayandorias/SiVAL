/*
 * AetheriumArchivar
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <sivalgui/navigationbutton.hpp>
//// end system includes

//// begin project specific includes
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
namespace SiVAL::Gui {
//// begin public member methods
NavigationButton::NavigationButton(QWidget *parent)
    :QToolButton(parent) {
    setProperty("class", "SiVALNavigationButton");
    setCheckable(true);
}
NavigationButton::~NavigationButton() {
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
