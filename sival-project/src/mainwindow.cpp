/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
//// end system includes

//// begin project specific includes
#include "mainwindow.hpp"

#include <iostream>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin static definitions
//// end static definitions

//// begin static functions
//// end static functions

namespace SiVAL {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
MainWindow::MainWindow(MainWindow *parent)
    :Gui::MainWindow(parent) {

    m_group = new QButtonGroup(this);
    m_group->setExclusive(true);


    m_startView = new StartView();
    SiVAL::Gui::NavigationButton *btn = m_startView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/home.svg"));
    m_navBar->addButton(btn);
    m_group->addButton(btn, 0);
    m_navWidget->addWidget(m_startView->navigationPanel());
    m_stackWidget->addWidget(m_startView->centerPanel());



    m_projectView = new ProjectView();
    btn = m_projectView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/projects.svg"));
    m_navBar->addButton(btn);
    m_group->addButton(btn, 1);
    m_navWidget->addWidget(m_projectView->navigationPanel());
    m_stackWidget->addWidget(m_projectView->centerPanel());



    m_helpView = new HelpView();
    btn = m_helpView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/help.svg"));
    m_navBar->appendButton(btn);
    m_group->addButton(btn, 2);
    m_navWidget->addWidget(m_helpView->navigationPanel());
    m_stackWidget->addWidget(m_helpView->centerPanel());



    m_settingsView = new SettingsView();
    btn = m_settingsView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/cogwheel.svg"));
    m_navBar->appendButton(btn);
    m_group->addButton(btn, 3);
    m_navWidget->addWidget(m_settingsView->navigationPanel());
    m_stackWidget->addWidget(m_settingsView->centerPanel());

    connect(m_group, &QButtonGroup::buttonClicked, this, &MainWindow::selection);

    retranslateUI();

    m_startView->navigationButton(m_navBar)->animateClick();
}

/**************************************************************************************************/
/**
 *
 */
MainWindow::~MainWindow() {
    if(m_startView) {
        delete m_startView;
    }
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void MainWindow::setNavigationHeader(int id) {
    switch(id) {
        case 0: {
            m_navWidget->setHeader(tr("Welcome"));
            break;
        }
        case 1: {
            m_navWidget->setHeader(tr("Project"));
            break;
        }
        case 2: {
            m_navWidget->setHeader(tr("Help"));
            break;
        }
        case 3: {
            m_navWidget->setHeader(tr("Settings"));
            break;
        }
        default: break;
    }
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void MainWindow::retranslateUI() {
    m_startView->navigationButton(m_navBar)->setText(tr("Welcome"));
    m_projectView->navigationButton(m_navBar)->setText(tr("Project"));
    m_helpView->navigationButton(m_navBar)->setText(tr("Help"));
    m_settingsView->navigationButton(m_navBar)->setText(tr("Settings"));
}

void MainWindow::selection(QAbstractButton *btn) {
    for(QAbstractButton *button : m_group->buttons()) {
        if(button->isChecked()) {
            m_navWidget->setCurrentIndex(m_group->id(button));
            m_stackWidget->setCurrentIndex(m_group->id(button));
            setNavigationHeader(m_group->id(button));
            break;
        }
    }
}
//// end protected slots

//// begin private slots
//// end private slots
}
