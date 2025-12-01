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
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "sivalgui/headerlabel.hpp"
#include "sivalgui/selectiontree.hpp"
#include "sivalgui/toolbutton.hpp"

#include <sivalgui/navigationpanel.hpp>
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

namespace SiVAL {
/**
 * class SettingsSpeaker
 *
 * @brief
 *
 */
class SettingsSpeaker : public SiVAL::Gui::NavigationPanel
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SettingsSpeaker(QWidget *parent = nullptr);
    /// Destructor
    virtual ~SettingsSpeaker();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void retranslate(QWidget *w);
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
    QVBoxLayout *verticalLayout;
    SiVAL::Gui::HeaderLabel *label;
    QStackedWidget *m_stack;
    SiVAL::Gui::SelectionTree *m_globalChassis;
    SiVAL::Gui::HeaderLabel *m_path;
    QListWidget *m_pathList;
    QHBoxLayout *horizontalLayout;
    SiVAL::Gui::ToolButton *m_new;
    SiVAL::Gui::ToolButton *m_edit;
    SiVAL::Gui::ToolButton *m_delete;

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
