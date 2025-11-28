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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
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
 * class SettingsAbout
 *
 * @brief
 *
 */
class SettingsAbout : public SiVAL::Gui::NavigationPanel
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SettingsAbout(QWidget *parent = nullptr);
    /// Destructor
    virtual ~SettingsAbout();
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
    QGridLayout *gridLayout;
    QSpacerItem *m_bottomSpacer;
    QLabel *m_version;
    QSpacerItem *m_topSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *m_logo;
    QSpacerItem *verticalSpacer;
    QLabel *m_license;
    QSpacerItem *m_leftSpacer;
    QLabel *m_copyright;
    QGroupBox *m_systemInfoBox;
    QGridLayout *gridLayout_2;
    QLabel *m_revisionInfo;
    QLabel *m_qtVersion;
    QLabel *m_revision;
    QLabel *m_buildDate;
    QLabel *m_compiler;
    QLabel *m_system;
    QLabel *m_buildDateInfo;
    QLabel *m_compilerInfo;
    QLabel *m_qtVersionInfo;
    QLabel *m_SystemInfo;
    QSpacerItem *verticalSpacer_3;
    QLabel *m_title;
    QFrame *line;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *m_library;
    QLabel *m_libQt;
    QLabel *m_libSival;
    QLabel *m_libLohmann;
    QSpacerItem *verticalSpacer_4;
    QLabel *m_assets;
    QSpacerItem *m_rightSpacer;
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
