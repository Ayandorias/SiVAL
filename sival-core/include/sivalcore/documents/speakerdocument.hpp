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
#include <QSharedPointer>
#include <QVector>
#include <sival/acousticsetup.hpp>
#include <sival/core/environment.hpp>
//// end system includes

//// begin project specific includes
#include <sivalcore/abstractions/abstractdocument.hpp>
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
 * class SpeakerDocument
 *
 * @brief
 *
 */
class SpeakerDocument : public AbstractDocument
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SpeakerDocument() = delete;
    /// Destructor
    virtual ~SpeakerDocument();
    static SpeakerDocument* create(const QString &filename);
    static SpeakerDocument* open(const QString &filename);

    QSharedPointer<SiVAL::Engine::AcousticSetup> createEnclosure(SiVAL::Engine::EnclosureType type);
    void parse();
    bool save();

    int damping();
    void setDamping(int damping);

    QVector<QSharedPointer<SiVAL::Engine::AcousticSetup>>& enclosures();

    QString name();
    QString type();

    void volume(double &volume, QString &unit);
    void setVolume(double vol);

    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    SpeakerDocument(const QString &filename, AbstractIOHandler *handler);

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
    QJsonObject m_object;
    //// end protected member

    //// begin private member
private:
    QVector<QSharedPointer<SiVAL::Engine::AcousticSetup>> m_setups;
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