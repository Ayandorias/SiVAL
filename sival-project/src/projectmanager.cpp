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
#include <QFileDialog>
#include <iostream>
//// end system includes

//// begin project specific includes
#include "enclosurenewdialog.hpp"
#include "projectmanager.hpp"
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

namespace SiVAL::PM {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
ProjectManager::ProjectManager(const QString filename, MainWindow *parent)
    :Gui::MainWindow(parent) {

    m_projectDoc = nullptr;
    m_projectNewDialog = nullptr;
    m_group = new QButtonGroup(this);
    m_group->setExclusive(true);

    m_startView = new SiVAL::PM::StartView();
    SiVAL::Gui::NavigationButton *btn = m_startView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/home.svg"));
    m_navBar->addButton(btn);
    m_group->addButton(btn, 0);
    m_navWidget->addWidget(m_startView->navigationPanel());
    m_stackWidget->addWidget(m_startView->centerPanel());
    connect(m_startView, &SiVAL::PM::StartView::newProject, this, &ProjectManager::newProject);
    connect(m_startView, &SiVAL::PM::StartView::openProject, this, &ProjectManager::openProject);
    connect(m_startView, &SiVAL::PM::StartView::saveProject, this, &ProjectManager::saveProject);
    connect(m_startView, &SiVAL::PM::StartView::saveAsProject, this, &ProjectManager::saveAsProject);

    m_projectView = new SiVAL::PM::ProjectView();
    btn = m_projectView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/projects.svg"));
    btn->setDisabled(true);
    m_navBar->addButton(btn);
    m_group->addButton(btn, 1);
    m_navWidget->addWidget(m_projectView->navigationPanel());
    m_stackWidget->addWidget(m_projectView->centerPanel());
    connect(m_projectView, &SiVAL::PM::ProjectView::sealedEnclosure, this, &ProjectManager::sealedEnclosure);
    connect(m_projectView, &SiVAL::PM::ProjectView::ventedEnclosure, this, &ProjectManager::ventedEnclosure);

    m_helpView = new SiVAL::PM::HelpView();
    btn = m_helpView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/help.svg"));
    m_navBar->appendButton(btn);
    m_group->addButton(btn, 2);
    m_navWidget->addWidget(m_helpView->navigationPanel());
    m_stackWidget->addWidget(m_helpView->centerPanel());

    m_settingsView = new SiVAL::PM::SettingsView();
    btn = m_settingsView->navigationButton(m_navBar);
    btn->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/cogwheel.svg"));
    m_navBar->appendButton(btn);
    m_group->addButton(btn, 3);
    m_navWidget->addWidget(m_settingsView->navigationPanel());
    m_stackWidget->addWidget(m_settingsView->centerPanel());

    connect(m_group, &QButtonGroup::buttonClicked, this, &ProjectManager::selection);

    retranslateUI();

    m_startView->navigationButton(m_navBar)->animateClick();
    if(!filename.isEmpty()) {
        open(filename);
    }
}

/**************************************************************************************************/
/**
 *
 */
ProjectManager::~ProjectManager() {
    if(m_startView) {
        delete m_startView;
    }
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void ProjectManager::resizeEvent(QResizeEvent *event) {
    if(m_projectNewDialog && m_projectNewDialog->isVisible()) {
        m_projectNewDialog->setGeometry(0,0, width(), height());
    }
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void ProjectManager::setNavigationHeader(int id) {
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
void ProjectManager::newProject() {
    m_projectNewDialog = new ProjectNewDialog(this);
    connect(m_projectNewDialog, &ProjectNewDialog::newProject, this, &ProjectManager::open);
    connect(m_projectNewDialog, &ProjectNewDialog::closeOverlay, this, [this] {
        m_projectNewDialog = nullptr;
    });
    m_projectNewDialog->showNormal();
    m_projectNewDialog->raise();
}

void ProjectManager::newSealedEnclosure(std::shared_ptr<SiVAL::Engine::AbstractDriver> driver) {
    std::cout << "Add new to Projekt: " << driver->model()<< std::endl;
}

void ProjectManager::newVentedEnclosure(std::shared_ptr<SiVAL::Engine::AbstractDriver> driver) {
    std::cout << "Add new to Projekt: " << driver->model()<< std::endl;
}

void ProjectManager::open(const QString &filepath) {
    // TODO: Es müssen noch alle Hauptfenster bis auf das ProjectManager geschlossen werden.
    // TODO: Es muss dann auf das ProjectView gewechselt werden.
    if(m_projectDoc) {
        m_projectDoc->save();
    } else {
        if(QFile::exists(filepath)) {
            m_projectDoc = SiVAL::Core::ProjectDocument::open(filepath);
            m_projectView->navigationButton(nullptr)->setDisabled(false);
            m_projectView->setProjectDocument(m_projectDoc);
        }
    }
}
void ProjectManager::openProject() {
    QString file = QFileDialog::getOpenFileName(this, tr("Open Project"), QString(), tr("Projects (*.sivalprj)"));
    if(!file.isEmpty()) {
        open(file);
    }
}


void ProjectManager::saveProject() {

}
void ProjectManager::saveAsProject() {

}

void ProjectManager::retranslateUI() {
    m_startView->navigationButton(m_navBar)->setText(tr("Welcome"));
    m_projectView->navigationButton(m_navBar)->setText(tr("Project"));
    m_helpView->navigationButton(m_navBar)->setText(tr("Help"));
    m_settingsView->navigationButton(m_navBar)->setText(tr("Settings"));
}

void ProjectManager::sealedEnclosure() {
    EnclosureNewDialog *dlg = new EnclosureNewDialog(this);
    connect(dlg, &EnclosureNewDialog::newEnclosure, this, &ProjectManager::newSealedEnclosure);
    dlg->showNormal();
    dlg->raise();
}

void ProjectManager::selection(QAbstractButton *btn) {
    for(QAbstractButton *button : m_group->buttons()) {
        if(button->isChecked()) {
            m_navWidget->setCurrentIndex(m_group->id(button));
            m_stackWidget->setCurrentIndex(m_group->id(button));
            setNavigationHeader(m_group->id(button));
            break;
        }
    }
}

void ProjectManager::ventedEnclosure() {
    EnclosureNewDialog *dlg = new EnclosureNewDialog(this);
    connect(dlg, &EnclosureNewDialog::newEnclosure, this, &ProjectManager::newVentedEnclosure);
    dlg->showNormal();
    dlg->raise();
}
//// end protected slots

//// begin private slots
//// end private slots
}
