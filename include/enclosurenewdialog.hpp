#ifndef HEADER_GUARD_SiVAL_EnclosureNewDialog_HPP
#define HEADER_GUARD_SiVAL_EnclosureNewDialog_HPP

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
//// end includes

//// begin specific includes
#include "nw/overlaydialog.hpp"
#include "speakerbrandcard.hpp"
#include "speakermanufacturer.hpp"
#include "manufacturerdocument.hpp"
//// end specific includes

//// begin using namespaces
namespace Ui {
class EnclosureNewDialog;
}
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class EnclosureNewDialog
 *
 * @brief
 *
 */
class EnclosureNewDialog : public NW::OverlayDialog
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit EnclosureNewDialog(ManufacturerDocument *doc, QWidget *parent = nullptr);
    /// Destructor
    virtual ~EnclosureNewDialog();
    ///
    SpeakerDocument* speaker();
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
    void buildManufacturerList();
    void clearSpeakerList();
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    Ui::EnclosureNewDialog *ui;
    ManufacturerDocument *m_pSpeakerSettingsDoc;
    QVBoxLayout *m_pVerticalLayout;
    QVBoxLayout *m_pSpeakerLayout;
    QSpacerItem *m_pVerticalSpacer;
    SpeakerBrandCard *m_pLastSelected;
    SpeakerDocument *m_pSpeakerDoc;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void changeSpeakerList(SpeakerManufacturer *man);
    void speakerSelected(SpeakerDocument *doc);
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void newEnclosure();
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_EnclosureNewDialog_HPP
