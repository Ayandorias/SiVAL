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
    ProjectDocument *prjdoc = getActiveProject();
    prjdoc->createEnclosure(doc);
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
ProjectDocument* ProjectTreeWidget::getActiveProject() {

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
        break;
    }
    default:
        break;
    }
}
//// end protected slots

//// begin private slots
//// end private slots
