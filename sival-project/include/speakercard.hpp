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
#include <sivalgui/card.hpp>
#include <sival/abstractions/driver.hpp>
//// end system includes

//// begin project specific includes

//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL {
/**
 * class SpeakerCard
 *
 * @brief
 *
 */
class SpeakerCard : public SiVAL::Gui::Card
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SpeakerCard(QWidget *parent);
    /// Destructor
    virtual ~SpeakerCard();

    std::shared_ptr<SiVAL::Engine::AbstractDriver> driver();
    void setDriver(std::shared_ptr<SiVAL::Engine::AbstractDriver> driver);
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
    std::shared_ptr<SiVAL::Engine::AbstractDriver> m_driver;
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
