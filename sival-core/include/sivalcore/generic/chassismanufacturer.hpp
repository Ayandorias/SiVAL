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
#include <QJsonArray>
#include <QJsonObject>
#include <QVector>
//// end system includes

//// begin project specific includes
#include <sival/abstractions/driver.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

namespace SiVAL::Core {
//// begin forward declarations
class SpeakerDocument;
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class ChassisManufacturer
 *
 * @brief
 *
 */
class ChassisManufacturer
{
    //// begin public member methods
public:
    /// Constructor
    explicit ChassisManufacturer(QJsonObject man, SiVAL::Core::SpeakerDocument *doc);
    /// Destructor
    virtual ~ChassisManufacturer();
    QString name();
    void parse();
    void setChassisList(QJsonArray arr);
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
    QString m_filename;
    QJsonObject m_manufacturer;
    SpeakerDocument *m_doc;
    QVector<std::shared_ptr<SiVAL::Engine::AbstractDriver>> m_chassisList;
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
