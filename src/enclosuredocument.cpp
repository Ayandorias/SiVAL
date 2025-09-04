/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
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
EnclosureDocument::EnclosureDocument(const QString &speaker_uuid, SiVAL::ENCLOSURE_TYPE type) {
    m_pEnclosure = nullptr;

    m_pSpeakerDoc = new SpeakerDocument(speaker_uuid);
    setType(type);

}

/**************************************************************************************************/
/**
 *
 */
EnclosureDocument::~EnclosureDocument() {
    delete m_pSpeakerDoc;
}

QJsonObject EnclosureDocument::toJson() {
    return QJsonObject();
}

void EnclosureDocument::setType(SiVAL::ENCLOSURE_TYPE type) {

    if(m_pEnclosure != nullptr) {
        if(m_pEnclosure->type() == type) {
            return;
        }
        delete m_pEnclosure;
    }

    m_EncType = type;

    switch(m_EncType) {
        case SiVAL::ENC_SEALED: {
            m_pEnclosure = new SealedEnclosure(m_pSpeakerDoc);
            break;
        }
        case SiVAL::ENC_VENTED: {
            m_pEnclosure = new VentedEnclosure(m_pSpeakerDoc);
            break;
        }
    }
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
