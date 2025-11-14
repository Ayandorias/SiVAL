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
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
//// end system includes

//// begin project specific includes
#include <sivalgui/global.hpp>
#include <sivalgui/cardlist.hpp>
#include <sivalgui/headerlabel.hpp>
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
 * class NavigationWidget
 *
 * @brief
 *
 */
class SIVAL_GUI_EXPORT NavigationWidget : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit NavigationWidget(QWidget *parent = nullptr);
    /// Destructor
    virtual ~NavigationWidget();
    void addWidget(QWidget *widget);
    int currentIndex();
    void setCurrentIndex(int index);
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
    HeaderLabel *m_header;
    QStackedWidget *m_navStack;
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
