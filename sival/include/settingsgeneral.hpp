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
#include <QCoreApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <QPushButton>
#include "sivalgui/headerlabel.hpp"
#include "sivalgui/label.hpp"
#include "sivalgui/spinwidget.hpp"

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
 * class SettingsGeneral
 *
 * @brief
 *
 */
class SettingsGeneral : public SiVAL::Gui::NavigationPanel
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SettingsGeneral(QWidget *parent = nullptr);
    /// Destructor
    virtual ~SettingsGeneral();
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
    //// end protected member

    //// begin private member
private:
    QGridLayout *gridLayout;
    QCheckBox *m_settingsLang;
    QComboBox *comboBox;
    QCheckBox *m_splashScreen;
    QLineEdit *m_licenseUrlEdit;
    SiVAL::Gui::Label *m_company;
    SiVAL::Gui::Label *m_author;
    QComboBox *m_licenseBox;
    SiVAL::Gui::HeaderLabel *m_appearance;
    SiVAL::Gui::Label *m_licenseUrl;
    SiVAL::Gui::Label *m_minute;
    QCheckBox *m_autoSave;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    SiVAL::Gui::Label *m_themeSel;
    QFrame *line_3;
    QLineEdit *m_authorEdit;
    SiVAL::Gui::HeaderLabel *m_project;
    QWidget *m_themeDark;
    SiVAL::Gui::SpinWidget *m_SaveTime;
    SiVAL::Gui::HeaderLabel *m_startup;
    QFrame *line_2;
    QWidget *m_themeAuto;
    SiVAL::Gui::HeaderLabel *m_lang_app;
    SiVAL::Gui::Label *m_recProCount;
    QLineEdit *m_companyEdit;
    QCheckBox *m_openLast;
    SiVAL::Gui::SpinWidget *m_projectCount;
    SiVAL::Gui::Label *m_selLang;
    QFrame *horizontalLine;
    QFrame *line_4;
    SiVAL::Gui::Label *m_license;
    QWidget *m_themeLight;
    SiVAL::Gui::Label *m_language;
    QPushButton *m_selectHelp;
    QCheckBox *m_onlineHelp;
    SiVAL::Gui::Label *m_localHelp;
    QLineEdit *m_helpPath;
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
