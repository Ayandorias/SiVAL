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
#include <QWidget>
#include <QHBoxLayout>
#include <sivalgui/framebarbutton.hpp>
//// end system includes

//// begin project specific includes
#include "sivalgui/global.hpp"
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
 * class FrameBar
 *
 * @brief
 *
 */
class SIVAL_GUI_EXPORT FrameBar : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit FrameBar(QWidget *parent);
    /// Destructor
    virtual ~FrameBar();
    ///
    void checkMaximized(bool max);
    ///
    void insertWidget(int pos, QWidget *widget);
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
    FrameBarButton *m_buttonMax;
    FrameBarButton *m_pButtonMenu;
    FrameBarButton *m_buttonMin;
    FrameBarButton *m_buttonNormal;
    FrameBarButton *m_buttonQuit; // m_pButtonQuit;
    // FrameBarButton
    QToolButton *m_pButtonSidebar;

    QHBoxLayout *m_pLayout;
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
    void iconize();
    void mainMenu();
    void maximize();
    void normal();
    void quit();
    void toggled(bool toggle);
    //// end signals
};
}
}
