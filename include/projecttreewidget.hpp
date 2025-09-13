#ifndef HEADER_GUARD_SiVAL_ProjectTreeWidget_HPP
#define HEADER_GUARD_SiVAL_ProjectTreeWidget_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QTreeWidget>
#include <QVector>
//// end includes

//// begin specific includes
#include "projectdocument.hpp"
#include "treeitem.hpp"
//// end specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class ProjectTreeView
 *
 * @brief
 *
 */
class ProjectTreeWidget : public QTreeWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectTreeWidget(QWidget *parent = nullptr);
    /// Destructor
    virtual ~ProjectTreeWidget();
    ///
    void addEnclosure(SpeakerDocument *doc);
    /// Adding new project to the view
    void addProject(ProjectDocument *prjdoc);
    ///
    void save();
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
    void addEnclosure(ProjectDocument *doc);
    TreeItem *getActiveProject();
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QVector<ProjectDocument*> m_PrjDocVector;
    QString m_sActiveProject;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void itemChanged();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void projectChanged(ProjectDocument *doc);
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_ProjectTreeWidget_ProjectTreeView_HPP
