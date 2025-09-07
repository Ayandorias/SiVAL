#ifndef HEADER_GUARD_SiVAL_SiVALWindow_HPP
#define HEADER_GUARD_SiVAL_SiVALWindow_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QButtonGroup>
#include <QMainWindow>
#include <QStackedWidget>
//// end includes

//// begin specific includes
#include "nw/mainwindow.hpp"
#include "nw/navbarpanel.hpp"
#include "nw/selectionbutton.hpp"
#include "centerstack.hpp"
#include "enclosurenewdialog.hpp"
#include "encloserwidget.hpp"
#include "homepanel.hpp"
#include "homewidget.hpp"
#include "projectnewdialog.hpp"
#include "projectpanel.hpp"
#include "manufacturerdocument.hpp"
#include "speakersettingswidget.hpp"
//// end specific includes

//// begin using namespaces
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class SiVALWindow
 *
 * @brief
 *
 */
class SiVALWindow : public NW::MainWindow
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SiVALWindow(const QString &projectfile, ManufacturerDocument *doc, QWidget *parent = nullptr);
    /// Destructor
    virtual ~SiVALWindow();
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
    void menu(bool visible, QButtonGroup *group);
    void speakerSettings();
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QButtonGroup *m_pGroup;
    QButtonGroup *m_pSettingsGroup;

    HomeWidget *m_pHomeWidget;
    CenterStack *m_pCenterStack;
    EnclosureNewDialog *m_pNewEnclosure;
    EnclosureWidget *m_pCenterView;

    QStackedWidget *m_pSettingsStack;
    SpeakerSettingsWidget *m_pSettingsWidget;
    NW::SelectionButton *m_pEnclosureBtn;

    NW::SelectionButton *m_pSpeakerBtn;
    NW::SelectionButton *m_pSpeakerSearchBtn;

    HomePanel *m_pHomePanel;
    ProjectPanel *m_pProjectPanel;

    ManufacturerDocument *m_pSpeakerDoc;
    ProjectNewDialog *m_pProjectNewDialog;

    NW::NavBarPanel *m_pNavBarPanel;

    enum BTN_POS {
        BTN_NONE = 0,
        BTN_Enclosure,
        BTN_Speaker,
        BTN_Search
    };

    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void centerViewSelection(int id);
    void createEnclosure();
    void enclosureSelection(int id);
    void mainMenu() override;
    void newEnclosure();
    void newProject();
    void openProjectEnclosure();
    void openProject(const QString &filepath);
    void settingsSelection(int id);
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_SiVALWindow_HPP
