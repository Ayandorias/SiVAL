/*
 * AetheriumArchivar
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QScreen>        // Für Bildschirmgröße (moderner Ansatz)
#include <QGuiApplication> // Für QScreen
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

//// begin public member methods
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::MainWindow
 * @param parent
 */
SiVAL::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_pCenterWidget = nullptr;
    m_pSideBarWidget = nullptr;
    m_pRightTitleBar = nullptr;
    m_pLeftTitleBar = nullptr;
    // Entfernt den Standard-Fensterrahmen des Betriebssystems
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);

    // Setzt eine Beispiel-Hintergrundfarbe und einen kleinen Rand, um das Fenster sichtbar zu machen
    // setStyleSheet("background-color: #2e2e2e; border: 1px solid #555555;");

    // Legt eine Startgröße für das Fenster fest
    resize(1600, 800);

    // Zentriert das Fenster auf dem primären Bildschirm (optional)
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect screenRect = screen->geometry();
        move(screenRect.center() - rect().center());
    }
    // Setzt eine Mindestgröße, um zu verhindern, dass das Fenster zu klein gezogen wird
    setMinimumSize(200, 150);

    setStyleSheet("background-color:#e0e0e0; border-radius:5px; border: none;");

    QWidget *w = new QWidget(this);
    setCentralWidget(w);

    QVBoxLayout *vl = new QVBoxLayout(w);
    vl->setContentsMargins(3, 3, 3, 3);
    w->setLayout(vl);
    m_pSplitter = new QSplitter(w);
    // m_pSplitter->setStyleSheet("background-color: #f00; border-radius: 0px;");
    vl->addWidget(m_pSplitter);

    // Seitenlöeiste auf der linken Seite.
    QWidget *left = new QWidget();
    left->setMinimumWidth(48);
    left->setMaximumWidth(800);
    m_pLeftLayout = new QVBoxLayout(left);
    m_pLeftLayout->setSpacing(0);
    m_pLeftLayout->setContentsMargins(0, 0, 0, 0);


    QWidget *right = new QWidget();
    right->setStyleSheet("background-color: #fff;border-radius: 0px;");
    m_pRightLayout = new QVBoxLayout(right);
    m_pRightLayout->setSpacing(0);
    m_pRightLayout->setContentsMargins(0, 0, 0, 0);
    right->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_pSplitter->addWidget(left);
    m_pSplitter->addWidget(right);
    m_pSplitter->setChildrenCollapsible(false);
    m_pSplitter->setStretchFactor(0, 0); // index 0 und nicht stretchen
    m_pSplitter->setStretchFactor(1, 1); // index 1 und stretchbar
    // setCentralWidget(m_pSplitter);




    m_pFrameBar = new SiVAL::FrameBar(right);
    m_pRightLayout->addWidget(m_pFrameBar);

    connect(m_pFrameBar, &SiVAL::FrameBar::iconize, this, &SiVAL::MainWindow::iconize);
    connect(m_pFrameBar, &SiVAL::FrameBar::mainMenu, this, &SiVAL::MainWindow::mainMenu);
    connect(m_pFrameBar, &SiVAL::FrameBar::maximize, this, &SiVAL::MainWindow::maximze);
    connect(m_pFrameBar, &SiVAL::FrameBar::normal, this, &SiVAL::MainWindow::normal);
    connect(m_pFrameBar, &SiVAL::FrameBar::quit, this, &SiVAL::MainWindow::quit);
    connect(m_pFrameBar, &SiVAL::FrameBar::toggled, this, &SiVAL::MainWindow::toggleSidebar);

    // QWidget *eins = new QWidget(right);
    // eins->setStyleSheet("background-color: #eee;");
    // m_pRightLayout->addWidget(eins);
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::~MainWindow
 */
SiVAL::MainWindow::~MainWindow()
{
    // Destruktor (leer, da keine dynamisch zugewiesenen Ressourcen verwaltet werden müssen)
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::setTitleBar
 * @param right
 * @param left
 */
void SiVAL::MainWindow::setTitleBar(QWidget *right, QWidget *left) {
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
void SiVAL::MainWindow::setCenterWidget(QWidget *widget) {
    if(m_pCenterWidget) {
        m_pCenterWidget->close();
    }
    m_pCenterWidget = widget;
    m_pCenterWidget->setStyleSheet("border-radius: 0px;");
    m_pRightLayout->addWidget(m_pCenterWidget);
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::setSideBarWidget
 * @param widget
 */
void SiVAL::MainWindow::setSideBarWidget(QWidget *widget) {
    if(m_pSideBarWidget) {
        m_pSideBarWidget->close();
    }

    m_pSideBarWidget = widget;
    m_pSideBarWidget->setStyleSheet("background-color: #ebebed;");
    m_pLeftLayout->addWidget(m_pSideBarWidget);
}
//// end public member methods (internal use only)

//// begin protected member methods
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::mouseDoubleClickEvent
 * @param event
 */
void SiVAL::MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
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
void SiVAL::MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QMainWindow::mouseMoveEvent(event);
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::mousePressEvent
 * @param event
 */
void SiVAL::MainWindow::mousePressEvent(QMouseEvent *event)
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
void SiVAL::MainWindow::mouseReleaseEvent(QMouseEvent *event)
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
void SiVAL::MainWindow::resizeEvent(QResizeEvent *event)
{
    m_pFrameBar->checkMaximized(isMaximized());
    killTimer(m_timerId);
    m_timerId = startTimer(100);
    // Dieser Event-Handler wird von Qt aufgerufen, wenn sich das Fenster vergrößert/verkleinert.
    // Er wird nicht direkt zum Auslösen der Größenänderung per Mauszug verwendet,
    // kann aber genutzt werden, um auf die neue Größe zu reagieren (z.B. Layouts anpassen).
    QMainWindow::resizeEvent(event); // Wichtig: Basisimplementierung aufrufen!
}

void SiVAL::MainWindow::timerEvent(QTimerEvent *event) {
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
void SiVAL::MainWindow::checkMaximized() {
    m_pFrameBar->checkMaximized(isMaximized());
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::getResizeEdges
 * @param pos
 * @return
 */
Qt::Edges SiVAL::MainWindow::getResizeEdges(const QPoint &pos)
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
void SiVAL::MainWindow::setCursorShape(const QPoint &pos)
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
void SiVAL::MainWindow::iconize() {
    showMinimized();
    m_pFrameBar->checkMaximized(isMaximized());
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::normal
 */
void SiVAL::MainWindow::normal() {
    showNormal();
    m_pFrameBar->checkMaximized(isMaximized());
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::maximze
 */
void SiVAL::MainWindow::maximze() {
    showMaximized();
    m_pFrameBar->checkMaximized(isMaximized());
}
/**************************************************************************************************/
/**
 * @brief SiVAL::MainWindow::quit
 */
void SiVAL::MainWindow::quit() {
    qApp->quit();
}
void SiVAL::MainWindow::toggleSidebar(bool toggle) {

}
//// end private slots


































