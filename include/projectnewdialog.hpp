#ifndef HEADER_GUARD_SiVAL_ProjectNewDialog_HPP
#define HEADER_GUARD_SiVAL_ProjectNewDialog_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QWidget>
//// end includes

//// begin specific includes
#include "nw/overlaydialog.hpp"
//// end specific includes

//// begin using namespaces
namespace Ui {
class ProjectNewDialog;
}
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class ProjectNewDialog
 *
 * @brief
 *
 */
class ProjectNewDialog : public NW::OverlayDialog
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectNewDialog(QWidget *parent);
    /// Destructor
    virtual ~ProjectNewDialog();
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
    Ui::ProjectNewDialog *ui;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void createNewProject();
    void openProjectFolder();
    void textChanged(const QString &text);
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void newProject(const QString &filepath);
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_ProjectNewDialog_HPP
