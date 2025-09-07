#ifndef HEADER_GUARD_SiVAL_SpeakerSettingsDocument_HPP
#define HEADER_GUARD_SiVAL_SpeakerSettingsDocument_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QVector>
//// end includes

//// begin specific includes
#include "idocument.hpp"
#include "speakermanufacturer.hpp"
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
 * class ManufacturerDocument
 *
 * @brief
 *
 */
class ManufacturerDocument : public IDocument
{
    //// begin public member methods
public:
    /// Constructor
    explicit ManufacturerDocument(const QString &filename);
    /// Destructor
    virtual ~ManufacturerDocument();
    ///
    virtual bool save() override;
    ///
    void import(const QString &filename);
    ///
    QVector<SpeakerManufacturer*>& manufacturers();
    ///
    void read(const QString &filename);
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void read() override;
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
    QVector<SpeakerManufacturer*> m_ManufacturerList;
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
#endif // HEADER_GUARD_SiVAL_SpeakerSettingsDocument_HPP
