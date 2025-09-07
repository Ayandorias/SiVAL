#ifndef HEADER_GUARD_SiVAL_SpeakerSettingsPage_HPP
#define HEADER_GUARD_SiVAL_SpeakerSettingsPage_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QWidget>
#include <QJsonDocument>
//// end includes

//// begin specific includes
#include "manufacturerdocument.hpp"
//// end specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
namespace Ui {
class SpeakerSettingsPage;
}
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class SpeakerSettingsPage
 *
 * @brief
 *
 */
class SpeakerSettingsPage : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SpeakerSettingsPage(QWidget *parent = nullptr);
    /// Destructor
    virtual ~SpeakerSettingsPage();
    ///
    void setDocument(ManufacturerDocument *doc);
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
    Ui::SpeakerSettingsPage *ui;
    ManufacturerDocument *m_pDocument;
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
#endif // HEADER_GUARD_SiVAL_SpeakerSettingsPage_HPP
