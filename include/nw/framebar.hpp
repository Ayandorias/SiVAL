#ifndef HEADER_GUARD_AetheriumArchivar_FrameBar_HPP
#define HEADER_GUARD_AetheriumArchivar_FrameBar_HPP

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
#include "nw/framebarbutton.hpp"
#include "nw/titlebar.hpp"
//// end specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace NW {
/**
 * class FrameBar
 *
 * @brief
 *
 */
class FrameBar : public TitleBar
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
    FrameBarButton *m_pButtonMax;
    FrameBarButton *m_pButtonMenu;
    FrameBarButton *m_pButtonMin;
    FrameBarButton *m_pButtonNormal;
    FrameBarButton *m_pButtonQuit;
    FrameBarButton *m_pButtonSidebar;
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
#endif // HEADER_GUARD_AetheriumArchivar_FrameBar_HPP
