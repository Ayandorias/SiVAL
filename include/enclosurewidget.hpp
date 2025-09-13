#ifndef HEADER_GUARD_SiVAL_EnclosureWidget_HPP
#define HEADER_GUARD_SiVAL_EnclosureWidget_HPP

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
#include "projectdocument.hpp"
#include "sivalgui.hpp"
//// end specific includes

//// begin using namespaces
namespace Ui {
class EnclosureWidget;
}
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class EnclosureWidget
 *
 * @brief
 *
 */
class EnclosureWidget : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit EnclosureWidget(QWidget *parent);
    /// Destructor
    virtual ~EnclosureWidget();
    ///
    void setPage(SiVAL::PRJ_MENU page);
    void setProject(ProjectDocument *doc);
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
    void updateMenu();
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    ProjectDocument *m_pProjectDoc;
    Ui::EnclosureWidget *ui;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void authorChanged(const QString &name);
    void grossVolumeChanged(const QString &volume);
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_EnclosureWidget_HPP
