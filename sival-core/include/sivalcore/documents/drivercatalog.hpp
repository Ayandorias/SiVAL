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
#include <QJsonDocument>
#include <QJsonObject>
#include <QVector>
//// end system includes

//// begin project specific includes
#include <sival/abstractions/driver.hpp>
#include <sival/components/driver/factory.hpp>
#include <sivalcore/core_global.hpp>
#include <sivalcore/abstractions/abstractdocument.hpp>
#include <sivalcore/generic/chassismanufacturer.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL::Core {
/**
 * class DriverCatalog
 *
 * @brief
 *
 */
class SIVAL_CORE_EXPORT DriverCatalog : public AbstractDocument
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit DriverCatalog(AbstractIOHandler *handler);
    /// Destructor
    virtual ~DriverCatalog();
    void extracted(QJsonArray &arr);
    QString filename();
    virtual void parse() override;
    void processing();
    virtual bool save() override;
    QVector<ChassisManufacturer*> manufacturerList();
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
    QJsonDocument m_doc;
    QJsonObject m_speakerObject;
    QVector<ChassisManufacturer*> m_manufacturer;
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
    void status(const QString &status);
    void error(const QString &msg);
    void finished();
    //// end signals
};
}
