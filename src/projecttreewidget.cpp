/*
 * SiVAL_ProjectTreeWidget
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QHeaderView>
#include <QTreeWidgetItem>
//// end includes

//// begin specific includes
#include "projecttreewidget.hpp"
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

    header()->setVisible(false);
    QTreeWidgetItem *item = new QTreeWidgetItem(this);
    item->setText(0, tr("SiVAL Sound System"));
}
/**************************************************************************************************/
/**
 * @brief ProjectTreeWidget::~ProjectTreeWidget
 */
ProjectTreeWidget::~ProjectTreeWidget() {
}
/**************************************************************************************************/
/**
 * @brief ProjectTreeWidget::newProject
 * @param prjdoc
 */
void ProjectTreeWidget::addProject(ProjectDocument *prjdoc) {
    m_PrjDocVector.append(prjdoc);
    QTreeWidgetItem *ti = topLevelItem(0);
    QTreeWidgetItem *item = new QTreeWidgetItem(ti);
    item->setText(0, prjdoc->name());

    expandItem(ti);
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
//// end protected slots

//// begin private slots
//// end private slots
