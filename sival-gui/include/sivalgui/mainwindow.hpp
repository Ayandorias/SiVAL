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
#include <QMainWindow>
#include <QMouseEvent> // Für Maus-Events
#include <QPoint>      // Für Mausposition
#include <QRect>       // Für Fenstergrößenberechnung
#include <QSplitter>
#include <QCursor>     // Für Mauscursor-Anpassung
#include <QVBoxLayout>
#include <QWidget>
#include <QStackedWidget>
#include <sivalgui/framebar.hpp>
//// end system includes

//// begin project specific includes
#include "sivalgui/global.hpp"

#include <sivalgui/navigationbar.hpp>
#include <sivalgui/navigationwidget.hpp>
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
 * @class MainWindow
 * @brief The main application window providing custom frameless UI with navigation
 *
 * MainWindow implements a custom frameless window with sophisticated mouse handling
 * for resizing and moving. It features a splitter-based layout with navigation bar,
 * sidebar, and central content area. The window supports both normal and maximized states
 * with proper visual feedback.
 *
 * @note This window uses Qt::FramelessWindowHint and implements custom window controls
 * including minimize, maximize, restore, and close functionality.
 */
class SIVAL_GUI_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

    //// begin public member methods
public:
    /**
     * @brief Constructs the main application window
     * @param parent Parent widget (optional)
     *
     * Initializes a frameless window with translucent background, sets up the navigation
     * structure, and configures the initial window size and minimum constraints.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     */
    virtual ~MainWindow();

    /**
     * @brief Sets custom title bar widgets for left and right sides
     * @param right Widget for the right title bar area
     * @param left Widget for the left title bar area (optional)
     *
     * Replaces any existing title bar widgets with the provided ones. If a widget
     * is nullptr, the corresponding title bar area remains empty.
     */
    void setTitleBar(QWidget *right, QWidget *left = nullptr);
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    /**
     * @brief Sets the main content widget for the central area
     * @param widget The widget to display in the center
     *
     * Replaces any existing center widget. The widget will be automatically
     * managed and deleted when appropriate.
     */
    void setCenterWidget(QWidget *widget);

    /**
     * @brief Sets the sidebar widget for additional navigation or tools
     * @param widget The widget to display in the sidebar
     *
     * The sidebar appears on the left side of the window and typically contains
     * secondary navigation elements or tool panels.
     */
    void setSideBarWidget(QWidget *widget);
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    /**
     * @brief Handles mouse double-click events for window state toggling
     * @param event The mouse event information
     *
     * Double-clicking in the title bar area toggles between maximized and normal
     * window states. Only affects the top drag area (title bar region).
     */
    void mouseDoubleClickEvent(QMouseEvent *event) override;

    /**
     * @brief Handles mouse movement for cursor shape updates
     * @param event The mouse event information
     *
     * Updates cursor shape when hovering over window borders to indicate
     * resize capabilities. Delegates to base class for default handling.
     */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * @brief Handles mouse press events for window manipulation
     * @param event The mouse event information
     *
     * Initiates window resizing when clicking on borders or window moving
     * when clicking in the title bar area. Uses native system resize/move
     * for smooth operation.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief Handles mouse release events to finalize window operations
     * @param event The mouse event information
     *
     * Cleans up resize/move state and resets cursor to default arrow shape
     * when mouse button is released.
     */
    void mouseReleaseEvent(QMouseEvent *event) override;

    /**
     * @brief Handles window resize events for layout updates
     * @param event The resize event information
     *
     * Updates frame bar state when window is resized and starts a timer
     * for delayed maximization state checking.
     */
    void resizeEvent(QResizeEvent *event) override;

    /**
     * @brief Handles timer events for delayed window state updates
     * @param event The timer event information
     *
     * Used to check and update window maximization state after resize
     * operations complete. Kills the timer after processing.
     */
    void timerEvent(QTimerEvent *event) override;
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    /**
     * @brief Checks and updates window maximization state
     *
     * Queries the current window state and updates the frame bar
     * button appearances accordingly (maximize vs restore buttons).
     */
    void checkMaximized();

    /**
     * @brief Determines which window edges are under mouse cursor for resizing
     * @param pos Mouse position in window coordinates
     * @return Bitmask of Qt::Edges indicating resize-able borders
     *
     * Analyzes mouse position relative to window borders to determine
     * which edges should be used for resizing operations.
     */
    Qt::Edges getResizeEdges(const QPoint &pos);

    /**
     * @brief Updates cursor shape based on mouse position over window borders
     * @param pos Mouse position in window coordinates
     *
     * Changes cursor to appropriate resize cursors (horizontal, vertical, diagonal)
     * when mouse hovers over window borders to provide visual resize feedback.
     */
    void setCursorShape(const QPoint &pos);
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    NavigationBar *m_navBar;               ///< Left navigation bar for view switching
    NavigationWidget *m_navWidget;          ///< Navigation widget container

    QStackedWidget *m_stackWidget;          ///< Stacked widget for multiple views

    QSplitter *m_pSplitter;                 ///< Main splitter separating nav and content
    QVBoxLayout *m_pLeftLayout;             ///< Layout for left sidebar area
    QVBoxLayout *m_pRightLayout;            ///< Layout for right content area
    QWidget *m_pLeftTitleBar;               ///< Optional left title bar widget
    QWidget *m_pRightTitleBar;              ///< Optional right title bar widget
    QWidget *m_pCenterWidget;               ///< Main content widget
    QWidget *m_pSideBarWidget;              ///< Sidebar content widget
    int m_timerId;                          ///< ID for delayed state checking timer
    FrameBar *m_pFrameBar;                  ///< Custom title bar with window controls

    // Legacy UI elements (may be deprecated in future versions)
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *widget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *widget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    //// end protected member

    //// begin private member
private:
    QPoint m_dragPosition;                  ///< Mouse position for drag operations
    bool m_resizing = false;                ///< Flag indicating active resize operation
    Qt::Edges m_resizeEdges;                ///< Current edges being resized

    // Border detection constants
    const int BORDER_WIDTH = 10;            ///< Width of invisible resize border area (pixels)
    const int DRAG_AREA_HEIGHT = 45;        ///< Height of top drag area for window moving (pixels)
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    /**
     * @brief Toggles sidebar visibility
     * @param toggle true to show sidebar, false to hide
     *
     * Virtual method allowing derived classes to implement custom
     * sidebar toggle behavior. Base implementation does nothing.
     */
    virtual void toggleSidebar(bool toggle);
    //// end protected slots

    //// begin private slots
private slots:
    /**
     * @brief Minimizes the window to system tray or taskbar
     */
    void iconize();

    /**
     * @brief Maximizes the window to fill the screen
     */
    void maximze();

    /**
     * @brief Restores window to normal (non-maximized) state
     */
    void normal();

    /**
     * @brief Quits the application
     */
    void quit();
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
}
