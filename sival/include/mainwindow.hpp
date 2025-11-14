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
#include <QVector>
#include <sivalgui/mainwindow.hpp>
//// end system includes

//// begin project specific includes
#include <startview.hpp>
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
 * class MainWindow
 *
 * @brief
 *
 */
class MainWindow : public Gui::MainWindow
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit MainWindow(MainWindow *parent = nullptr);
    /// Destructor
    virtual ~MainWindow();
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
    StartView *m_startView;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void retranslateUI();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
