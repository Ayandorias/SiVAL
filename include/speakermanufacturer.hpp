#ifndef HEADER_GUARD_SiVAL_SpeakerManufacturer_HPP
#define HEADER_GUARD_SiVAL_SpeakerManufacturer_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QObject>
#include <QString>
#include <QStringList>
//// end includes

//// begin specific includes
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
 * class SpeakerManufacturer
 *
 * @brief
 *
 */
class SpeakerManufacturer
{
    //// begin public member methods
public:
    /// Constructor
    explicit SpeakerManufacturer(const QString &name, bool indexed, QStringList chassisList);
    /// Destructor
    virtual ~SpeakerManufacturer();
    QStringList chassisList();
    void indexed(bool n);
    bool isIndexed();
    QString name();
    QVector<SpeakerDocument*> speakerList();
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
    void init();
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QString m_sName;
    bool m_bIndexed;
    QStringList m_ChassisList;
    QVector<SpeakerDocument*> m_SpeakerList;
    //// end private member
};
#endif // HEADER_GUARD_SiVAL_SpeakerManufacturer_HPP
