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
#include "manufacturercard.hpp"
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
ManufacturerCard::ManufacturerCard(QWidget *parent)
    :SiVAL::Gui::Card(parent) {
}

/**************************************************************************************************/
/**
 *
 */
ManufacturerCard::~ManufacturerCard() {
}

SiVAL::Core::ChassisManufacturer* ManufacturerCard::manufacturer() {
    return m_manufacturer;
}
void ManufacturerCard::setManufacturer(SiVAL::Core::ChassisManufacturer *m) {
    m_manufacturer = m;
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
