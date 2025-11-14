#pragma once

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QObject>
#include <QToolButton>
//// end system includes

//// begin project specific includes
#include <sivalgui/global.hpp>
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
/**
 * class NavigationButton
 *
 * Der NavigationButton  wird zur Navigation in dem jeweiligen hauptfenster genutzt.
 * Er wird in der Seitenleiste auf der linken Seite platziert.
 * Der NavigationButton dient dazu zwischen den Unterschiedlichen Ansichten zu wechseln.
 * Dafür sendet er beim Klick die aktuelle Position.
 *
 */
class SIVAL_GUI_EXPORT NavigationButton : public QToolButton
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit NavigationButton(QWidget *parent);
    /// Destructor
    virtual ~NavigationButton();
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
