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
#include <sivalcore/core_global.hpp>
//// end system includes

//// begin project specific includes
#include <sivalcore/settings/general.hpp>
#include <sivalcore/settings/lastprojectlist.hpp>
#include <sivalcore/settings/project.hpp>
#include <sivalcore/settings/system.hpp>
#include <sivalcore/documents/drivercatalog.hpp>
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
    explicit SettingsDocument(AbstractIOHandler *handler);
    /// Destructor
    virtual ~SettingsDocument();
    static SettingsDocument* instance();
    virtual void parse() override;
    virtual bool save() override;
    bool saveLastProject();

    QString projectPath();
    QString theme();

    QString author();
    void setAuthor(const QString &author);

    bool autoSave();
    void setAutoSave(bool autosave);

    int autoSaveTime();
    void setAutoSaveTime(int min);

    QString company();
    void setCompany(const QString &company);

    QString lastProject();
    void setLastProject(const QString &project);

    QString themeSelect();
    void setThemeSelect(const QString &theme);

    int lastProjectCount();
    void setLastProjectCount(int count);

    bool openLastProject();
    void setOpenLastProject(bool open);

    bool showSplashScreen();
    void setShowSplashScreen(bool show);

    QStringList lastProjects();
    void addProject(const QString &project);

    void addSpeaker(SiVAL::Core::DriverCatalog *doc);
    SiVAL::Core::DriverCatalog* speaker(int pos);
    int speakerCount();

    QByteArray standardFileValues(const QString &filename);
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
    QJsonObject m_doc;
    General *m_general;
    LastProjectList *m_lastProjectList;
    Project *m_project;
    System *m_system;
    // SiVAL::Core::DriverCatalog *m_speaker;
    //// end public member

    //// begin protected member
protected:
    QVector<SiVAL::Core::DriverCatalog*> m_speakerList;
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
