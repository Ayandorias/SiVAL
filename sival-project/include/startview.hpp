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
#include <sivalgui/view.hpp>
#include <sivalgui/navigationpanel.hpp>
#include <sivalgui/card.hpp>
//// end system includes

//// begin project specific includes
#include <sival.hpp>
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
 * class StartView
 *
 * @brief
 *
 */
class StartView : public Gui::View
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit StartView();
    /// Destructor
    virtual ~StartView();
    virtual Gui::NavigationPanel* navigationPanel() override;
    virtual QWidget* centerPanel() override;
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void retranslate();
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
    //// end protected member

    //// begin private member
private:
    Gui::Card *m_cardNew;
    Gui::Card *m_cardOpen;
    Gui::Card *m_cardSave;
    Gui::Card *m_cardSaveAs;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void newProject();
    void projectOpen();
    // void saveProject();
    void saveAsProject();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void createNewProject(SiVAL::ProjectNew prj);
    void openProject(const QString &filename);
    //// end signals
};
}
