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
#include <QButtonGroup>
#include <QVector>
#include <sivalgui/mainwindow.hpp>
#include <sivalcore/documents/projectdocument.hpp>
#include <projectnewdialog.hpp>
//// end system includes

//// begin project specific includes
#include <helpview.hpp>
#include <projectview.hpp>
#include <startview.hpp>
#include <settingsview.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL::PM {
/**
 * class MainWindow
 *
 * @brief
 *
 */
class ProjectManager : public Gui::MainWindow
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectManager(MainWindow *parent = nullptr);
    /// Destructor
    virtual ~ProjectManager();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void resizeEvent(QResizeEvent *event) override;
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    void setNavigationHeader(int id);
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QButtonGroup *m_group;
    SiVAL::PM::HelpView *m_helpView;
    SiVAL::PM::ProjectView *m_projectView;
    SiVAL::PM::StartView *m_startView;
    SiVAL::PM::SettingsView *m_settingsView;
    SiVAL::PM::ProjectNewDialog *m_projectNewDialog;
    SiVAL::Core::ProjectDocument *m_projectDoc;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void newProject();
    void open(const QString &filepath);
    void openProject();
    void saveProject();
    void saveAsProject();
    void retranslateUI();
    void sealedEnclosure();
    void selection(QAbstractButton *btn);
    void ventedEnclosure();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
