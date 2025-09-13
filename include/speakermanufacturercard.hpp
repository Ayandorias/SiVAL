#ifndef HEADER_GUARD_SiVAL_SpeakerManufacturerCard_HPP
#define HEADER_GUARD_SiVAL_SpeakerManufacturerCard_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QObject>
#include <QSvgRenderer>
//// end includes

//// begin specific includes
#include "speakermanufacturer.hpp"
#include "nw/card.hpp"
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
 * class SpeakerManufacturerCard
 *
 * @brief
 *
 */
class SpeakerManufacturerCard : public NW::Card
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SpeakerManufacturerCard(SpeakerManufacturer *man, QWidget *parent, bool indexed = true);
    /// Destructor
    virtual ~SpeakerManufacturerCard();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
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
    bool m_bWithIndex;
    SpeakerManufacturer *m_pManufacturer;
    QSvgRenderer *m_pCheckRenderer;
    QSvgRenderer *m_pUncheckRenderer;
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
    void selected(SpeakerManufacturer *man);
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_SpeakerManufacturerCard_HPP
