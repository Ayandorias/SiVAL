#ifndef HEADER_GUARD_SiVAL_IDocument_HPP
#define HEADER_GUARD_SiVAL_IDocument_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QByteArray>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
//// end includes

//// begin specific includes
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
 * class Document
 *
 * @brief
 *
 */
class IDocument
{
    //// begin public member methods
public:
    explicit IDocument();
    /// Constructor
    explicit IDocument(const QString &filename);
    /// Destructor
    virtual ~IDocument();

    void change();
    bool isChanged();
    ///
    virtual bool save();
    virtual bool saveAs(const QString &filename);
    int type();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    virtual void read() = 0;
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    bool m_bChanged;
    QJsonObject m_Object;
    QString m_sFilename;
    int m_iType;
    //// end protected member

    //// begin private member
private:
    //// end private member
};
#endif // HEADER_GUARD_SiVAL_Document_HPP
