/*
 * SiVAL_ProjectTreeWidget
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QObject>
#include <QHeaderView>

#include <iostream>
//// end includes

//// begin specific includes
#include "projecttreewidget.hpp"
#include "treeitem.hpp"
//// end specific includes

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

//// begin public member methods
/**************************************************************************************************/
/**
 * @brief ProjectTreeWidget::ProjectTreeWidget
 * @param parent
 */
ProjectTreeWidget::ProjectTreeWidget(QWidget *parent)
    :QTreeWidget(parent) {
    m_sActiveProject = QString();

    header()->setVisible(false);
    TreeItem *item = new TreeItem(this, SiVAL::DT_WORKSPACE);
    item->setText(0, tr("SiVAL Sound Systems"));

    connect(this, &QTreeWidget::itemSelectionChanged, this, &ProjectTreeWidget::itemChanged);
}
/**************************************************************************************************/
/**
 * @brief ProjectTreeWidget::~ProjectTreeWidget
 */
ProjectTreeWidget::~ProjectTreeWidget() {

}

void ProjectTreeWidget::addEnclosure(SpeakerDocument *doc) {
    TreeItem *item = getActiveProject();
    std::cout << "Neues Gehäuse wird angelegt" << std::endl;
    ProjectDocument *prjdoc = (ProjectDocument*)item->data();
    if(prjdoc != nullptr) {
        prjdoc->createEnclosure(doc);
        TreeItem *speaker = new TreeItem(item, SiVAL::DT_SPEAKER);
        speaker->setText(0, doc->model());
        expandItem(item);
    }
}
/**************************************************************************************************/
/**
 * @brief ProjectTreeWidget::newProject
 * @param prjdoc
 */
void ProjectTreeWidget::addProject(ProjectDocument *prjdoc) {
    m_PrjDocVector.append(prjdoc);
    QTreeWidgetItem *ti = topLevelItem(0);
    TreeItem *item = new TreeItem(ti, SiVAL::DT_PROJECT);
    item->setData(prjdoc);
    item->setText(0, prjdoc->name());

    m_sActiveProject = prjdoc->projectId();

    expandItem(ti);
    emit projectChanged(prjdoc);
}

void ProjectTreeWidget::save() {

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
TreeItem* ProjectTreeWidget::getActiveProject() {
    QTreeWidgetItem *item = topLevelItem(0);
    int count = item->childCount();
    for(int i = 0; i < count; i++) {
        QTreeWidgetItem *child = item->child(i);
        TreeItem *it = (TreeItem*)child;
        switch(it->type()) {
        case SiVAL::DT_PROJECT: {
            ProjectDocument *doc = (ProjectDocument*)it->data();

            std::cout << doc->projectId().toStdString() << " == " << m_sActiveProject.toStdString() << std::endl;

            if(doc->projectId() == m_sActiveProject) {
                return it;
            }
            break;
        }
        default: break;
        }
    }
    return nullptr;
}
//// begin public slots
//// end public slots

//// begin protected slots
void ProjectTreeWidget::itemChanged() {
    std::cout << "Item has changed" << std::endl;
    QTreeWidgetItem *i = currentItem();
    TreeItem *item = (TreeItem*)i;

    switch(item->type()) {
    case SiVAL::DT_WORKSPACE: {
        break;
    }
    case SiVAL::DT_PROJECT: {
        std::cout << "Projekt gefunden:" << std::endl;
        ProjectDocument *doc = (ProjectDocument*)item->data();
        m_sActiveProject = doc->projectId();
        std::cout << m_sActiveProject.toStdString() << std::endl;
        emit projectChanged(doc);
        break;
    }
    default:
        break;
    }
}
//// end protected slots

//// begin private slots
//// end private slots
