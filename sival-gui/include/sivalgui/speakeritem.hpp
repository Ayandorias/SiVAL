#pragma once

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <sivalgui/startitem.hpp>
//// end system includes

//// begin project specific includes
#include <sivalcore/documents/speakerdocument.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL::Gui {
/**
 * class SpeakerItem
 *
 * @brief
 *
 */
class SpeakerItem : public StartItem
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SpeakerItem(QWidget *parent);
    /// Destructor
    virtual ~SpeakerItem();
    SiVAL::Core::SpeakerDocument *document();
    void setDocument(SiVAL::Core::SpeakerDocument *doc);
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
    SiVAL::Core::SpeakerDocument *m_spkrDoc;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}