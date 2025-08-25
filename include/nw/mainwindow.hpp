#ifndef HEADER_GUARD_AetheriumArchivar_MainWindow_HPP
#define HEADER_GUARD_AetheriumArchivar_MainWindow_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QMainWindow>
#include <QMouseEvent> // Für Maus-Events
#include <QPoint>      // Für Mausposition
#include <QRect>       // Für Fenstergrößenberechnung
#include <QSplitter>
#include <QCursor>     // Für Mauscursor-Anpassung
#include <QVBoxLayout>
#include <QWidget>
//// end includes

//// begin specific includes
#include "nw/framebar.hpp"
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
 * class MainWindow
 *
 * @brief
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit MainWindow(QWidget *parent = nullptr);
    /// Destructor
    virtual ~MainWindow();
    ///
    void setTitleBar(QWidget *right, QWidget *left = nullptr);
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    void setCenterWidget(QWidget *widget);
    void setSideBarWidget(QWidget *widget);
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    void checkMaximized();
    Qt::Edges getResizeEdges(const QPoint &pos); // Ermittelt die Kanten, an denen die Größe geändert werden soll
    void setCursorShape(const QPoint &pos);      // Passt die Form des Mauscursors an
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    QSplitter *m_pSplitter;
    QVBoxLayout *m_pLeftLayout;
    QVBoxLayout *m_pRightLayout;
    QWidget *m_pLeftTitleBar;
    QWidget *m_pRightTitleBar;
    QWidget *m_pCenterWidget;
    QWidget *m_pSideBarWidget;
    int m_timerId;
    FrameBar *m_pFrameBar;
    //// end protected member

    //// begin private member
private:
    QPoint m_dragPosition;         // Position für das Verschieben
    bool m_resizing = false;       // Flag, ob gerade die Größe geändert wird
    Qt::Edges m_resizeEdges;       // Kanten, an denen die Größe geändert wird

    // Konstanten für die Erkennung von Mausbereichen
    const int BORDER_WIDTH = 10;    // Breite des unsichtbaren Ziehbereichs am Rand (in Pixeln)
    const int DRAG_AREA_HEIGHT = 45; // Höhe des Bereichs am oberen Rand, in dem das Fenster verschoben werden kann (in Pixeln)

    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    virtual void mainMenu() = 0;
    virtual void toggleSidebar(bool toggle);
    //// end protected slots

    //// begin private slots
private slots:
    void iconize();
    void maximze();
    void normal();
    void quit();
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
#endif // HEADER_GUARD_AetheriumArchivar_MainWindow_HPP



