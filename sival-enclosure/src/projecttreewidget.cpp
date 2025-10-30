/*
 * SiVAL_ProjectTreeWidget
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QObject>
#include <QHeaderView>

#include <iostream>
//// end system includes

//// begin project specific includes
#include "projecttreewidget.hpp"
#include "sivalgui.hpp"
#include "treeitem.hpp"
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

//// begin public slots
//// end public slots

//// begin protected slots
void ProjectTreeWidget::itemChanged() {
    QTreeWidgetItem *i = currentItem();
    TreeItem *item = (TreeItem*)i;

    // switch(item->type()) {
    // case SiVAL::DT_WORKSPACE: {
    //     break;
    // }
    // case SiVAL::DT_PROJECT: {
    //     ProjectDocument *doc = (ProjectDocument*)item->data();
    //     m_sActiveProject = doc->projectId();
    //     emit projectChanged(doc);
    //     break;
    // }
    // case SiVAL::DT_SPEAKER: {
    //     EnclosureDocument *enc = (EnclosureDocument*)item->data();
    //     SpeakerDocument *d = enc->speaker();
    //     emit enclosureChanged(enc);
    //     break;
    // }
    // default:
    //     break;
    // }
}
//// end protected slots

//// begin private slots
//// end private slots
