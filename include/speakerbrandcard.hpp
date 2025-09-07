#ifndef HEADER_GUARD_SiVAL_SpeakerBrandCard_HPP
#define HEADER_GUARD_SiVAL_SpeakerBrandCard_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
//// end includes

//// begin specific includes
#include "nw/card.hpp"
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
 * class SpeakerBrandCard
 *
 * @brief
 *
 */
class SpeakerBrandCard : public NW::Card
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SpeakerBrandCard(SpeakerDocument *doc, QWidget *parent);
    /// Destructor
    virtual ~SpeakerBrandCard();
    void setSelected(bool select);
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event);
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
    bool m_bSelected;
    QSvgRenderer *m_pCheckRenderer;
    SpeakerDocument *m_pSpeakerDoc;
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
    void selected(SpeakerDocument *doc);
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_SpeakerBrandCard_HPP
