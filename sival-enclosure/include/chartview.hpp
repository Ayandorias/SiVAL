#ifndef HEADER_GUARD_SiVAL_ChartView_HPP
#define HEADER_GUARD_SiVAL_ChartView_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QChart>
#include <QChartView>
#include <QLineSeries>
// #include <sival/speaker.hpp>
// #include <sival/sival.hpp>
//// end system includes

//// begin project specific includes
// #include "enclosuredocument.hpp"
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class ChartView
 *
 * @brief
 *
 */
class ChartView : public QChartView
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ChartView(/*SiVAL::GRAPH_TYPE gt, */const QString &title, QWidget *parent = nullptr);
    /// Destructor
    virtual ~ChartView();
    // void enclosureDocument(double vol, EnclosureDocument *enc);
    void init();
    void setEndY(int end);
    void setStartY(int start);
    void setTitleX(const QString &title);
    void setTitleY(const QString &title);
    void setStartFrequency(double freq);
    void setEndFrequency(double freq);

    void updateChart();
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
    int startFrequency;
    int endFrequency;
    int startY;
    int endY;
    double power;
    double step;
    QChart *chart;
    QString chartTitle;
    QString titleX;
    QString titleY;
    QLineSeries *serie;
    double volume;
    // SiVAL::GRAPH_TYPE graphType;
    // EnclosureDocument *enclosure;
    // SiVAL::Speaker *speaker;
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
#endif // HEADER_GUARD_SiVAL_ChartView_HPP
