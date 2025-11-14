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

    m_startView = new StartView();
    NavigationButton *btn = m_startView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/icon/home_dark.svg"));
    m_navBar->addButton(btn);

    m_navWidget->addWidget(m_startView->navigationPanel());

    m_stackWidget->addWidget(m_startView->centerPanel());

    retranslateUI();
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
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void MainWindow::retranslateUI() {
    m_startView->navigationButton(m_navBar)->setText(tr("Willkommen"));
}
//// end protected slots

//// begin private slots
//// end private slots
}
