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
#include <QString>
//// end system includes

//// begin project specific includes
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

namespace SiVAL::Core {

//// begin forward declarations
class AbstractDocument;
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class AbstractIOHandler
 *
 * @brief
 *
 */
class AbstractIOHandler {

    //// begin public member methods
public:
    /// Constructor
    explicit AbstractIOHandler(const QString &filename);
    /// Destructor
    virtual ~AbstractIOHandler();
    virtual bool load(AbstractDocument *doc) = 0;
    virtual bool save(AbstractDocument *doc) = 0;
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
    QString m_filename;
    //// end protected member

    //// begin private member
private:
    //// end private member
};
}
