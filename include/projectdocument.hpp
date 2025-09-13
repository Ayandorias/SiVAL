#ifndef HEADER_GUARD_SiVAL_ProjectDocument_HPP
#define HEADER_GUARD_SiVAL_ProjectDocument_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QJsonArray>
#include <QJsonObject>
#include <QVector>
//// end includes

//// begin specific includes
#include "idocument.hpp"
#include "enclosuredocument.hpp"
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
 * class ProjectDocument
 *
 * @brief
 *
 */
class ProjectDocument : public IDocument
{
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectDocument(const QString &filename);
    /// Destructor
    virtual ~ProjectDocument();
    void setAuthor(const QString &author);
    QString author();
    void createEnclosure(SpeakerDocument *doc, SiVAL::ENCLOSURE_TYPE type = SiVAL::ENC_SEALED);
    QString created();
    void setDescription(const QString &description);
    QString description();
    QJsonArray enclosures();
    void setName(const QString &prjname);
    QString name();
    bool save() override;
    bool saveAs(const QString &filename) override;
    QString projectId();
    QString version();
    void setVolume(const double &vol);
    double volume();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    virtual void read() override;
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    void readSetups();
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QVector<EnclosureDocument*> m_Setups;
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
