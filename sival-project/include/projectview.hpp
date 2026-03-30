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
#include <sivalgui/card.hpp>
#include <sivalgui/toolbutton.hpp>
#include <projectpanel.hpp>
#include <sival/abstractions/enclosure.hpp>
#include <sivalcore/documents/projectdocument.hpp>
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

namespace SiVAL::PM {
/**
 * class ProjectView
 *
 * @brief
 *
 */
class ProjectView : public Gui::View
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectView();
    /// Destructor
    virtual ~ProjectView();
    virtual Gui::NavigationPanel* navigationPanel() override;
    virtual QWidget* centerPanel() override;
    void setProjectDocument(SiVAL::Core::ProjectDocument *doc);
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
    SiVAL::Core::ProjectDocument *m_projectDoc;
    SiVAL::Gui::Card *m_enclosure;
    SiVAL::Gui::Card *m_information;
    SiVAL::Gui::Card *m_properties;

    QHBoxLayout *horizontalLayout;
    SiVAL::Gui::ToolButton *m_save;
    SiVAL::Gui::ToolButton *m_close;
    QSpacerItem *horizontalSpacer;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void enclosure();
    void information();
    void projectChanged();
    void properties();
    void save();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
