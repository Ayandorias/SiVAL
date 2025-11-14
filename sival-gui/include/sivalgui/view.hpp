#pragma once

/*
 * SiVAL Gui
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QObject>
//// end system includes

//// begin project specific includes
#include <sivalgui/global.hpp>
#include <sivalgui/navigationbutton.hpp>
#include <sivalgui/navigationpanel.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL {
namespace Gui {
/**
 * class View
 *
 * @brief
 *
 */
class SIVAL_GUI_EXPORT View : public QObject
{

    //// begin public member methods
public:
    /// Constructor
    explicit View();
    /// Destructor
    virtual ~View();

    QWidget *mainWidget();
    QWidget *menuBar();
    NavigationButton* navigationButton(QWidget *parent);
    virtual NavigationPanel* navigationPanel() = 0;
    virtual QWidget *centerPanel() = 0;
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
    QWidget *m_mainWidget;
    QWidget *m_menuBar;
    NavigationButton *m_navBarButton;
    NavigationPanel *m_navBarPanel;
    QString m_icon;
    QString m_name;

    QWidget *m_centerPanel;
    //// end protected member

    //// begin private member
private:
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
}
}
