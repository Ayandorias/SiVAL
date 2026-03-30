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
#include <QJsonObject>
#include <QVector>
//// end system includes

//// begin project specific includes
#include <sivalcore/abstractions/abstractdocument.hpp>
#include <sivalcore/documents/speakerdocument.hpp>
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
 * class ProjectDocument
 *
 * @brief
 *
 */
class ProjectDocument : public SiVAL::Core::AbstractDocument
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectDocument() = delete;
    /// Destructor
    virtual ~ProjectDocument();
    static ProjectDocument* create(const QString &filename);
    static ProjectDocument* open(const QString &filename);
    void parse();
    bool save();

    void setAuthor(const QString &author);
    QString author();

    void setCreateDate(const QString &date);
    QString createDate();

    void setDescription(const QString &desc);
    QString description();

    QString filename();

    void setGrossVolume(const double &volume, const QString &unit);
    void grossVolume(double &volume, QString &unit);

    void setProjectId(const QString &id);
    QString projectId();

    void setProjectName(const QString &name);
    QString projectName();

    SpeakerDocument* createSpeaker(const QString &name);
    QVector<SpeakerDocument*>& speakerList();

    void setVersion(float version);
    float version();


    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    ProjectDocument(const QString &filename, AbstractIOHandler *handler);
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    QStringList speakerFiles();
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
    QJsonObject m_object;
    QVector<SpeakerDocument*> m_speakerList;
    //// end private membe*

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
