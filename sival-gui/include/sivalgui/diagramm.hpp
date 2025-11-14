#pragma once

/*
 * SIVAL Gui
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QWidget>
#include <QVector>
#include <QPointF>
#include <QRectF>
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
namespace Gui {
/**
 * class Diagramm
 *
 * @brief
 *
 */
class SIVAL_GUI_EXPORT Diagramm : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit Diagramm(QWidget *parent = nullptr);
    /// Destructor
    virtual ~Diagramm();
    // Datenpunkte hinzufügen
    void addDataPoint(double x, double y);
    void setDataPoints(const QVector<QPointF>& points);
    void clearData();

    // Achsenbereiche setzen
    void setXRange(double min, double max);
    void setYRange(double min, double max);

    // Diagrammposition und -größe
    void setPlotMargins(int left, int top, int right, int bottom);
    QRectF getPlotRect() const { return m_plotRect; }

    // Aktuelle Mausposition im Diagramm-Koordinatensystem
    QPointF getMouseDataPosition() const { return m_mouseDataPos; }
    bool isMouseInPlot() const { return m_mouseInPlot; }
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    void updatePlotRect();
    QPointF pixelToData(const QPoint& pixel) const;
    QPoint dataToPixel(const QPointF& data) const;
    void drawAxes(QPainter& painter);
    void drawGrid(QPainter& painter);
    void drawData(QPainter& painter);
    void drawCrosshair(QPainter& painter);
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QVector<QPointF> m_dataPoints;

    // Achsenbereiche
    double m_xMin, m_xMax;
    double m_yMin, m_yMax;

    // Ränder
    int m_leftMargin, m_topMargin, m_rightMargin, m_bottomMargin;

    // Plot-Bereich
    QRectF m_plotRect;

    // Mausposition
    QPointF m_mouseDataPos;
    QPoint m_mousePixelPos;
    bool m_mouseInPlot;
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
    void mousePositionChanged(QPointF dataPos);
    void mouseEnteredPlot();
    void mouseLeftPlot();
    //// end signals
};
}
}
