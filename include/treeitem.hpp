#ifndef HEADER_GUARD_SiVAL_TreeItem_HPP
#define HEADER_GUARD_SiVAL_TreeItem_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QObject>
#include <QTreeWidgetItem>
//// end includes

//// begin specific includes
#include "idocument.hpp"
//// end specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class SiVALTreeItem
 *
 * @brief
 *
 */
class TreeItem : public QTreeWidgetItem
{
    //// begin public member methods
public:
    /// Constructor
    explicit TreeItem(QTreeWidget *parent, int type = Type);
    TreeItem(QTreeWidgetItem *parent, int type = Type);
    /// Destructor
    virtual ~TreeItem();
    IDocument* data();
    void setData(IDocument *doc);
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
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
    IDocument *m_pDocument;
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
#endif // HEADER_GUARD_SiVAL_TreeItem_HPP
