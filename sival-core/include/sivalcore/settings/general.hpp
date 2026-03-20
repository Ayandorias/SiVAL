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
#include <QObject>
#include <QJsonObject>
//// end system includes

//// begin project specific includes

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
 * class General
 *
 * @brief
 *
 */
class General : public QObject
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit General(QJsonObject obj);
    /// Destructor
    virtual ~General();

    QString author();
    void setAuthor(const QString &author);

    bool autoSave();
    void setAutoSave(bool autosave);

    int autoSaveTime();
    void setAutoSaveTime(int min);

    QString company();
    void setCompany(const QString &company);

    QString currentTheme();
    void setCurrentTheme(const QString &theme);

    int lastProjectCount();
    void setLastProjectCount(int count);

    bool openLastProject();
    void setOpenLastProject(bool open);

    QString lastProject();
    void setLastProject(const QString &project);

    bool showSplashScreen();
    void setShowSplashScreen(bool enable);




    QJsonObject object();
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
    QJsonObject m_object;


    // QString m_theme_current;


    QString m_language;
    QString m_unit_system;
    int m_decimal_precision;

    QStringList m_recent_projects;
    int m_max_recent_items;
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
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
