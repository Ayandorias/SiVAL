#ifndef HEADER_GUARD_SiVAL_EnclosureDocument_HPP
#define HEADER_GUARD_SiVAL_EnclosureDocument_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QJsonObject>
#include <QString>
//// end includes

//// begin specific includes
#include "ienclosure.hpp"
#include "sival.hpp"
#include "speakerdocument.hpp"
//// end specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class EnclosureDocument
 *
 * @brief
 *
 */
class EnclosureDocument {
    //// begin public member methods
public:
    /// Constructor
    explicit EnclosureDocument(SpeakerDocument *doc, SiVAL::ENCLOSURE_TYPE type = SiVAL::ENC_SEALED);
    /// Destructor
    virtual ~EnclosureDocument();
    ///
    QJsonObject toJson();
    void setType(SiVAL::ENCLOSURE_TYPE type);
    SiVAL::ENCLOSURE_TYPE type();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    SiVAL::ENCLOSURE_TYPE m_EncType;
    IEnclosure *m_pEnclosure;
    SpeakerDocument *m_pSpeakerDoc;
    //// end private member
};
#endif // HEADER_GUARD_SiVAL_EnclosureDocument_HPP
