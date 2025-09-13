/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <iostream>
//// end includes

//// begin specific includes
#include "enclosuredocument.hpp"
#include "sealedenclosure.hpp"
#include "ventedenclosure.hpp"
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
EnclosureDocument::EnclosureDocument(const SpeakerDocument &doc, SiVAL::ENCLOSURE_TYPE type)
    : m_SpeakerDoc(doc) {
    m_pEnclosure = nullptr;
    m_iQuantity = 1;

    setType(type);

}
EnclosureDocument::EnclosureDocument(QJsonObject obj) {
    m_pEnclosure = nullptr;
    m_iQuantity = 1;

    QJsonObject enc = obj["enclosure"].toObject();
    QJsonObject speaker = obj["speaker"].toObject();
    m_SpeakerDoc = SpeakerDocument(speaker);
    if(!enc.isEmpty()) {
        QString type = enc["type"].toString();
        std::cout << "Type: " << type.toStdString() << std::endl;
        if(type == "sealed") {
            std::cout << "hier bin ich da 1" << std::endl;
            setType(SiVAL::ENC_SEALED);
            std::cout << "hier bin ich da 2" << std::endl;
        } else if(type == "vented") {
            setType(SiVAL::ENC_SEALED);
        }
        std::cout << "enclosure: " << m_pEnclosure << std::endl;
        m_pEnclosure->setProperties(enc);
    }
}
/**************************************************************************************************/
/**
 *
 */
EnclosureDocument::~EnclosureDocument() {

}

QJsonObject EnclosureDocument::toJson() {
    QJsonObject obj;
    obj["name"] = m_SpeakerDoc.model();
    QJsonObject speaker;
    speaker["uuid"] = m_SpeakerDoc.uuid();
    speaker["manufacturer"] = m_SpeakerDoc.manufacturer();
    speaker["quantity"] = m_iQuantity;
    obj["speaker"] =speaker;

    std::cout << "bis hier: " << m_pEnclosure << std::endl;
    QJsonObject enclosure = m_pEnclosure->toJson();
    std::cout << "bis hier 2" << std::endl;
    obj["enclosure"] = enclosure;

    std::cout << "bis hier 3" << std::endl;
    return obj;
}

void EnclosureDocument::setType(SiVAL::ENCLOSURE_TYPE type) {

    std::cout << "hier bin ich da 3" << std::endl;
    if(m_pEnclosure != nullptr) {
        std::cout << "hier bin ich da 4" << std::endl;
        if(m_pEnclosure->type() == type) {
            std::cout << "hier bin ich da 5" << std::endl;
            return;
        }
        std::cout << "hier bin ich da 6" << std::endl;
        delete m_pEnclosure;
    }

    std::cout << "hier bin ich da 7" << std::endl;
    m_EncType = type;

    switch(m_EncType) {
        case SiVAL::ENC_SEALED: {
        std::cout << "hier bin ich da 8" << std::endl;
            m_pEnclosure = new SealedEnclosure(&m_SpeakerDoc);
            break;
        }
        case SiVAL::ENC_VENTED: {
            std::cout << "hier bin ich da 9" << std::endl;
            m_pEnclosure = new VentedEnclosure(&m_SpeakerDoc);
            break;
        }
    }
        std::cout << "hier bin ich da 10" << std::endl;
}

SiVAL::ENCLOSURE_TYPE EnclosureDocument::type() {
    return m_EncType;
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
