/*
 * AetheriumArchivar
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QScreen>        // Für Bildschirmgröße (moderner Ansatz)
#include <QApplication> // Für QScreen
#include <QDebug>         // Für Debug-Ausgaben (optional)
#include <QWindow>
#include <sivalgui//mainwindow.hpp>
//// end system includes

//// begin project specific includes
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin static definitions
//// end static definitions

//// begin static functions
//// end static functions

namespace SiVAL {
namespace Gui {
//// begin public member methods
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);

    m_pCenterWidget = nullptr;
    m_pSideBarWidget = nullptr;
    m_pRightTitleBar = nullptr;
    m_pLeftTitleBar = nullptr;

    // Legt eine Startgröße für das Fenster fest
    resize(1600, 800);
    setMinimumSize(200, 150);

    // Pseudofenster für abgerundete Ecken
    QWidget *w = new QWidget(this);
    setCentralWidget(w);

    QHBoxLayout *hl = new QHBoxLayout(w);
    hl->setContentsMargins(3, 3, 3, 3);
    hl->setSpacing(0);


    m_navBar = new SiVAL::NavigationBar(w);
    hl->addWidget(m_navBar);


    // Centerwidget
    m_pSplitter = new QSplitter(w);
    hl->addWidget(m_pSplitter);

    // The Navigation Widget on the Left Side of the application
    m_navWidget = new SiVAL::Gui::NavigationWidget(this);
    m_navWidget->setMinimumWidth(48);
    m_navWidget->setMaximumWidth(800);
    m_pSplitter->addWidget(m_navWidget);

    // The Center View of the application
    QWidget *right = new QWidget();
    m_pRightLayout = new QVBoxLayout(right);
    m_pRightLayout->setSpacing(0);
    m_pRightLayout->setContentsMargins(0, 0, 0, 0);
    right->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_pSplitter->addWidget(right);
    m_pSplitter->setChildrenCollapsible(false);
    m_pSplitter->setStretchFactor(0, 0); // index 0 und nicht stretchen
    m_pSplitter->setStretchFactor(1, 1); // index 1 und stretchbar

    QList<int> sizes;
    sizes << 250 << 100;
    m_pSplitter->setSizes(sizes);

    m_pFrameBar = new SiVAL::Gui::FrameBar(right);
    m_pRightLayout->addWidget(m_pFrameBar);

    connect(m_pFrameBar, &SiVAL::Gui::FrameBar::iconize, this, &SiVAL::Gui::MainWindow::iconize);
    connect(m_pFrameBar, &SiVAL::Gui::FrameBar::maximize, this, &SiVAL::Gui::MainWindow::maximze);
    connect(m_pFrameBar, &SiVAL::Gui::FrameBar::normal, this, &SiVAL::Gui::MainWindow::normal);
    connect(m_pFrameBar, &SiVAL::Gui::FrameBar::quit, this, &SiVAL::Gui::MainWindow::quit);
    connect(m_pFrameBar, &SiVAL::Gui::FrameBar::toggled, this, &SiVAL::Gui::MainWindow::toggleSidebar);

    m_stackWidget = new QStackedWidget(this);
    m_pRightLayout->addWidget(m_stackWidget);
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    // Destruktor (leer, da keine dynamisch zugewiesenen Ressourcen verwaltet werden müssen)
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::setTitleBar
 * @param right
 * @param left
 */
void MainWindow::setTitleBar(QWidget *right, QWidget *left) {
    if(m_pRightTitleBar && right) {
        m_pRightTitleBar->close();
    }
    if(right) {
        m_pRightTitleBar = right;
        m_pRightLayout->addWidget(m_pRightTitleBar);
    }

    if(m_pLeftTitleBar && left) {
        m_pLeftTitleBar->close();
    }
    if(left) {
        m_pLeftTitleBar = left;
        m_pLeftLayout->addWidget(m_pLeftTitleBar);
    }
}
//// end public member methods

//// begin public member methods (internal use only)
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::setCenterWidget
 * @param widget
 */
void MainWindow::setCenterWidget(QWidget *widget) {
    if(m_pCenterWidget) {
        m_pCenterWidget->close();
    }
    m_pCenterWidget = widget;
    // m_pCenterWidget->setStyleSheet("border-radius: 0px;");
    m_pRightLayout->addWidget(m_pCenterWidget);
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::setSideBarWidget
 * @param widget
 */
void MainWindow::setSideBarWidget(QWidget *widget) {
    if(m_pSideBarWidget) {
        m_pSideBarWidget->close();
    }

    m_pSideBarWidget = widget;
    // m_pSideBarWidget->setStyleSheet("background-color: #ebebed;");
    m_pLeftLayout->addWidget(m_pSideBarWidget);
}
//// end public member methods (internal use only)

//// begin protected member methods
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::mouseDoubleClickEvent
 * @param event
 */
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QPoint point = event->position().toPoint();
        if(point.y() > BORDER_WIDTH && point.y() < 3 + DRAG_AREA_HEIGHT) {
            if(isMaximized()) {
                showNormal();
            } else {
                showMaximized();
            }
        }
    }
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::mouseMoveEvent
 * @param event
 */
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QMainWindow::mouseMoveEvent(event);
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::mousePressEvent
 * @param event
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // Überprüft, ob die linke Maustaste gedrückt wurde
    if (event->button() == Qt::LeftButton) {
        // Ermittelt die Kanten, an denen der Mauszeiger beim Klick war
        Qt::Edges edges = getResizeEdges(event->position().toPoint());

        // Wenn der Mauszeiger an einer Ziehkante ist
        if (edges != Qt::Edges()) {
            // m_resizing = true; // Aktiviert den Größenänderungsmodus
            // m_resizeEdges = edges; // Speichert die erkannten Kanten
            // m_dragPosition = event->globalPosition().toPoint(); // Speichert die Startposition für die Größenänderung
            windowHandle()->startSystemResize(edges);
            event->accept(); // Event konsumieren
        }
        // Wenn der Mauszeiger nicht an einer Ziehkante ist, aber im oberen Verschiebebereich
        else if (event->position().y() <= DRAG_AREA_HEIGHT) {
            windowHandle()->startSystemMove();
            // m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft(); // Speichert den Offset für das Verschieben
            event->accept(); // Event konsumieren
        }
    }
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::mouseReleaseEvent
 * @param event
 */
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Setzt die Status-Variablen zurück, wenn die Maustaste losgelassen wird
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = QPoint(); // Setzt die Drag-Position zurück
        m_resizing = false;         // Deaktiviert den Größenänderungsmodus
        setCursor(Qt::ArrowCursor); // Setzt den Standard-Mauscursor
        event->accept(); // Event konsumieren
    }
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::resizeEvent
 * @param event
 */
void MainWindow::resizeEvent(QResizeEvent *event)
{
    m_pFrameBar->checkMaximized(isMaximized());
    killTimer(m_timerId);
    m_timerId = startTimer(100);
    // Dieser Event-Handler wird von Qt aufgerufen, wenn sich das Fenster vergrößert/verkleinert.
    // Er wird nicht direkt zum Auslösen der Größenänderung per Mauszug verwendet,
    // kann aber genutzt werden, um auf die neue Größe zu reagieren (z.B. Layouts anpassen).
    QMainWindow::resizeEvent(event); // Wichtig: Basisimplementierung aufrufen!
}

void MainWindow::timerEvent(QTimerEvent *event) {
    if(m_timerId == event->timerId()) {
        m_pFrameBar->checkMaximized(isMaximized());
        killTimer(m_timerId);
    }
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::checkMaximized
 */
void MainWindow::checkMaximized() {
    m_pFrameBar->checkMaximized(isMaximized());
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::getResizeEdges
 * @param pos
 * @return
 */
Qt::Edges MainWindow::getResizeEdges(const QPoint &pos)
{
    Qt::Edges edges = Qt::Edges();
    // Linker Rand
    if (pos.x() < BORDER_WIDTH)
        edges |= Qt::LeftEdge;
    // Rechter Rand
    else if (pos.x() > width() - BORDER_WIDTH)
        edges |= Qt::RightEdge;
    // Oberer Rand
    if (pos.y() < BORDER_WIDTH)
        edges |= Qt::TopEdge;
    // Unterer Rand
    else if (pos.y() > height() - BORDER_WIDTH)
        edges |= Qt::BottomEdge;
    return edges;
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::setCursorShape
 * @param pos
 */
void MainWindow::setCursorShape(const QPoint &pos)
{
    Qt::Edges edges = getResizeEdges(pos);
    m_resizeEdges = edges; // Speichert die Kanten für mousePressEvent

    // Setzt den Cursor basierend auf den erkannten Kanten
    if (edges == (Qt::LeftEdge | Qt::TopEdge) || edges == (Qt::RightEdge | Qt::BottomEdge)) {
        setCursor(Qt::SizeFDiagCursor); // Schräg nach oben/unten (NW-SE)
    } else if (edges == (Qt::RightEdge | Qt::TopEdge) || edges == (Qt::LeftEdge | Qt::BottomEdge)) {
        setCursor(Qt::SizeBDiagCursor); // Schräg nach unten/oben (NE-SW)
    } else if (edges & (Qt::LeftEdge | Qt::RightEdge)) {
        setCursor(Qt::SizeHorCursor); // Horizontal
    } else if (edges & (Qt::TopEdge | Qt::BottomEdge)) {
        setCursor(Qt::SizeVerCursor); // Vertikal
    } else {
        setCursor(Qt::ArrowCursor); // Standard-Pfeilcursor
    }
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::iconize
 */
void MainWindow::iconize() {
    showMinimized();
    m_pFrameBar->checkMaximized(isMaximized());
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::normal
 */
void MainWindow::normal() {
    showNormal();
    m_pFrameBar->checkMaximized(isMaximized());
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::maximze
 */
void MainWindow::maximze() {
    showMaximized();
    m_pFrameBar->checkMaximized(isMaximized());
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::quit
 */
void MainWindow::quit() {
    qApp->quit();
}
void MainWindow::toggleSidebar(bool toggle) {

}
//// end private slots
}
}
