/*
 * SIVAL Gui
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <QtMath>
//// end system includes

//// begin project specific includes
#include "sivalgui/diagramm.hpp"
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
 *
 */
Diagramm::Diagramm(QWidget *parent)
    :QWidget(parent)
    , m_xMin(1.0)
    , m_xMax(1000.0)
        , m_yMin(0.0)
        , m_yMax(100.0)
        , m_leftMargin(60)
        , m_topMargin(40)
        , m_rightMargin(40)
        , m_bottomMargin(60)
        , m_mouseInPlot(false)
    {
        setMouseTracking(true);
        setMinimumSize(400, 300);
        updatePlotRect();

        // Beispieldaten
        for (int i = 1; i <= 100; ++i) {
            double x = qPow(10.0, i / 25.0); // 1 bis 10000
            double y = 50.0 + 30.0 * qSin(i * 0.3);
            addDataPoint(x, y);
        }
}

/**************************************************************************************************/
/**
 *
 */
Diagramm::~Diagramm() {
}
void Diagramm::addDataPoint(double x, double y)
{
    m_dataPoints.append(QPointF(x, y));
    update();
}

void Diagramm::setDataPoints(const QVector<QPointF>& points)
{
    m_dataPoints = points;
    update();
}

void Diagramm::clearData()
{
    m_dataPoints.clear();
    update();
}
void Diagramm::setXRange(double min, double max)
{
    if (min > 0 && max > min) {
        m_xMin = min;
        m_xMax = max;
        update();
    }
}

void Diagramm::setYRange(double min, double max)
{
    if (max > min) {
        m_yMin = min;
        m_yMax = max;
        update();
    }
}

void Diagramm::setPlotMargins(int left, int top, int right, int bottom)
{
    m_leftMargin = left;
    m_topMargin = top;
    m_rightMargin = right;
    m_bottomMargin = bottom;
    updatePlotRect();
    update();
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void Diagramm::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Hintergrund
    painter.fillRect(rect(), Qt::white);

    // Grid zeichnen
    drawGrid(painter);

    // Achsen zeichnen
    drawAxes(painter);

    // Daten zeichnen
    drawData(painter);

    // Fadenkreuz zeichnen
    if (m_mouseInPlot) {
        drawCrosshair(painter);
    }
}

void Diagramm::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    updatePlotRect();
}

void Diagramm::mouseMoveEvent(QMouseEvent *event)
{
    m_mousePixelPos = event->pos();

    bool wasInPlot = m_mouseInPlot;
    m_mouseInPlot = m_plotRect.contains(m_mousePixelPos);

    if (m_mouseInPlot) {
        m_mouseDataPos = pixelToData(m_mousePixelPos);
        emit mousePositionChanged(m_mouseDataPos);

        if (!wasInPlot) {
            emit mouseEnteredPlot();
        }
    } else if (wasInPlot) {
        emit mouseLeftPlot();
    }

    update();
}

void Diagramm::leaveEvent(QEvent *event)
{
    if (m_mouseInPlot) {
        m_mouseInPlot = false;
        emit mouseLeftPlot();
        update();
    }
    QWidget::leaveEvent(event);
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void Diagramm::updatePlotRect()
{
    m_plotRect = QRectF(
        m_leftMargin,
        m_topMargin,
        width() - m_leftMargin - m_rightMargin,
        height() - m_topMargin - m_bottomMargin
        );
}

QPointF Diagramm::pixelToData(const QPoint& pixel) const
{
    if (m_plotRect.width() <= 0 || m_plotRect.height() <= 0)
        return QPointF();

    // X-Achse: logarithmisch
    double logXMin = qLn(m_xMin);
    double logXMax = qLn(m_xMax);
    double xRatio = (pixel.x() - m_plotRect.left()) / m_plotRect.width();
    double logX = logXMin + xRatio * (logXMax - logXMin);
    double x = qExp(logX);

    // Y-Achse: linear
    double yRatio = (pixel.y() - m_plotRect.top()) / m_plotRect.height();
    double y = m_yMax - yRatio * (m_yMax - m_yMin);

    return QPointF(x, y);
}

QPoint Diagramm::dataToPixel(const QPointF& data) const
{
    if (m_plotRect.width() <= 0 || m_plotRect.height() <= 0)
        return QPoint();

    // X-Achse: logarithmisch
    double logXMin = qLn(m_xMin);
    double logXMax = qLn(m_xMax);
    double logX = qLn(qMax(data.x(), 0.0001));
    double xRatio = (logX - logXMin) / (logXMax - logXMin);
    int pixelX = m_plotRect.left() + xRatio * m_plotRect.width();

    // Y-Achse: linear
    double yRatio = (m_yMax - data.y()) / (m_yMax - m_yMin);
    int pixelY = m_plotRect.top() + yRatio * m_plotRect.height();

    return QPoint(pixelX, pixelY);
}



void Diagramm::drawGrid(QPainter& painter)
{
    painter.setPen(QPen(QColor(220, 220, 220), 1));

    // Vertikale Grid-Linien (logarithmisch)
    double logXMin = qLn(m_xMin);
    double logXMax = qLn(m_xMax);

    for (int decade = -10; decade <= 10; ++decade) {
        double baseValue = qPow(10.0, decade);

        for (int i = 1; i <= 9; ++i) {
            double x = baseValue * i;
            if (x >= m_xMin && x <= m_xMax) {
                QPoint pt = dataToPixel(QPointF(x, m_yMin));
                painter.drawLine(pt.x(), m_plotRect.top(), pt.x(), m_plotRect.bottom());
            }
        }
    }

    // Horizontale Grid-Linien (linear)
    double yStep = (m_yMax - m_yMin) / 10.0;
    for (int i = 0; i <= 10; ++i) {
        double y = m_yMin + i * yStep;
        QPoint pt = dataToPixel(QPointF(m_xMin, y));
        painter.drawLine(m_plotRect.left(), pt.y(), m_plotRect.right(), pt.y());
    }
}

void Diagramm::drawAxes(QPainter& painter)
{
    painter.setPen(QPen(Qt::black, 2));

    // Plot-Rahmen
    painter.drawRect(m_plotRect);

    // X-Achsen-Beschriftung (logarithmisch)
    painter.setFont(QFont("Arial", 10));
    double logXMin = qLn(m_xMin);
    double logXMax = qLn(m_xMax);

    for (int decade = -10; decade <= 10; ++decade) {
        double x = qPow(10.0, decade);
        if (x >= m_xMin && x <= m_xMax) {
            QPoint pt = dataToPixel(QPointF(x, m_yMin));
            painter.drawLine(pt.x(), m_plotRect.bottom(), pt.x(), m_plotRect.bottom() + 5);

            QString label = QString::number(x, 'g', 3);
            QRectF textRect(pt.x() - 30, m_plotRect.bottom() + 10, 60, 20);
            painter.drawText(textRect, Qt::AlignCenter, label);
        }
    }

    // Y-Achsen-Beschriftung (linear)
    double yStep = (m_yMax - m_yMin) / 5.0;
    for (int i = 0; i <= 5; ++i) {
        double y = m_yMin + i * yStep;
        QPoint pt = dataToPixel(QPointF(m_xMin, y));
        painter.drawLine(m_plotRect.left() - 5, pt.y(), m_plotRect.left(), pt.y());

        QString label = QString::number(y, 'f', 1);
        QRectF textRect(m_plotRect.left() - 55, pt.y() - 10, 50, 20);
        painter.drawText(textRect, Qt::AlignRight | Qt::AlignVCenter, label);
    }

    // Achsenbeschriftungen
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.drawText(QRectF(0, height() - 20, width(), 20), Qt::AlignCenter, "X-Achse (logarithmisch)");

    painter.save();
    painter.translate(20, height() / 2);
    painter.rotate(-90);
    painter.drawText(QRectF(-100, -10, 200, 20), Qt::AlignCenter, "Y-Achse (linear)");
    painter.restore();
}

void Diagramm::drawData(QPainter& painter)
{
    if (m_dataPoints.size() < 2)
        return;

    painter.setPen(QPen(Qt::blue, 2));
    painter.setClipRect(m_plotRect);

    QPainterPath path;
    bool firstPoint = true;

    for (const QPointF& point : m_dataPoints) {
        if (point.x() > 0) {
            QPoint pixel = dataToPixel(point);

            if (firstPoint) {
                path.moveTo(pixel);
                firstPoint = false;
            } else {
                path.lineTo(pixel);
            }
        }
    }

    painter.drawPath(path);
    painter.setClipping(false);
}

void Diagramm::drawCrosshair(QPainter& painter)
{
    painter.setPen(QPen(Qt::red, 1, Qt::DashLine));
    painter.setClipRect(m_plotRect);

    // Vertikale Linie
    painter.drawLine(m_mousePixelPos.x(), m_plotRect.top(),
                     m_mousePixelPos.x(), m_plotRect.bottom());

    // Horizontale Linie
    painter.drawLine(m_plotRect.left(), m_mousePixelPos.y(),
                     m_plotRect.right(), m_mousePixelPos.y());

    painter.setClipping(false);

    // Position anzeigen
    QString posText = QString("X: %1, Y: %2")
                          .arg(m_mouseDataPos.x(), 0, 'g', 4)
                          .arg(m_mouseDataPos.y(), 0, 'f', 2);

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    QRectF textRect(m_plotRect.right() - 150, m_plotRect.top() + 5, 145, 20);
    painter.fillRect(textRect, QColor(255, 255, 255, 200));
    painter.drawText(textRect, Qt::AlignCenter, posText);
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
}
}








