/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin specific includes
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
 *
 */
TreeItem::TreeItem(QTreeWidget *parent, int type)
    :QTreeWidgetItem(parent, type) {

    m_pDocument = nullptr;
}

TreeItem::TreeItem(QTreeWidgetItem *parent, int type)
    : QTreeWidgetItem(parent, type) {
    m_pDocument = nullptr;
}

/**************************************************************************************************/
/**
 *
 */
TreeItem::~TreeItem() {
}

IDocument* TreeItem::data() {
    return m_pDocument;
}

void TreeItem::setData(IDocument *doc) {
    m_pDocument = doc;
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
