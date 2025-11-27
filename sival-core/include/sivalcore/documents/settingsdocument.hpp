#pragma once

/*
 * SiVAL Core
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <sivalcore/abstractions/abstractdocument.hpp>
#include <sivalcore/io/settingsiohandler.hpp>
#include <sivalcore/core_global.hpp>
//// end system includes

//// begin project specific includes
#include <sivalcore/settings/general.hpp>
#include <sivalcore/settings/project.hpp>
#include <sivalcore/settings/system.hpp>
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
 * class SettingsDocument
 *
 * @brief
 *
 */
class SIVAL_CORE_EXPORT SettingsDocument : public AbstractDocument
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SettingsDocument(SettingsIOHandler *handler);
    /// Destructor
    virtual ~SettingsDocument();
    static SettingsDocument* instance();
    virtual void parse(const QString &doc) override;
    QString theme();
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
    General *m_general;
    Project *m_project;
    System *m_system;
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    static SettingsDocument* m_instance;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots
};
}
