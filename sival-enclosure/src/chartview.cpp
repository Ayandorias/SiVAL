/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
#include <QLogValueAxis>
#include <QValueAxis>

// #include <sival/coneexcursionsealed.hpp>
// #include <sival/frequencyresponsesealed.hpp>
// #include <sival/gain.hpp>
// #include <sival/groupdelaysealed.hpp>
// #include <sival/impedancesealed.hpp>

#include <cmath>
#include <iostream>
//// end system includes

//// begin project specific includes
#include "chartview.hpp"
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
 *
 */
ChartView::ChartView(/*SiVAL::GRAPH_TYPE gt, */const QString &title, QWidget *parent)
    :QChartView(parent), chartTitle(title) {
    setStyleSheet("border: 1px solid #efefef; border-radius: 5px; margin: 2px;");

    // graphType = gt;
    power = 1;
}

/**************************************************************************************************/
/**
 *
 */
ChartView::~ChartView() {
}

// void ChartView::enclosureDocument(double vol, EnclosureDocument *enc) {
//     volume = vol;
//     enclosure = enc;

//     updateChart();
// }

void ChartView::init() {
    step = std::pow(10, 1.0/100.0);
    chart = new QChart();

    serie = new QLineSeries();
    chart->addSeries(serie);

    QLogValueAxis *axisX_spl = new QLogValueAxis();
    axisX_spl->setBase(10.0);
    axisX_spl->setLabelFormat("%g Hz");
    axisX_spl->setRange(startFrequency, endFrequency);
    axisX_spl->setTitleText(titleX);
    axisX_spl->setMinorTickCount(8);
    chart->addAxis(axisX_spl, Qt::AlignBottom);
    serie->attachAxis(axisX_spl);

    QValueAxis *axisY_spl = new QValueAxis();
    axisY_spl->setRange(startY, endY);
    axisY_spl->setTitleText(titleY);
    axisY_spl->setMinorTickCount(9);
    chart->addAxis(axisY_spl, Qt::AlignLeft);
    serie->attachAxis(axisY_spl);

    // switch (graphType) {
    // case SiVAL::GT_RESPONSE:
    //     chart->setTitle(chartTitle);
    //     setChart(chart);
    //     break;
    // case SiVAL::GT_GAIN: {
    //     chart->setTitle(chartTitle);
    //     setChart(chart);
    // }
    // case SiVAL::GT_IMPEDANCE: {
    //     chart->setTitle(chartTitle);
    //     setChart(chart);
    // }
    // case SiVAL::GT_GROUP_DELAY: {
    //     chart->setTitle(chartTitle);
    //     setChart(chart);
    // }
    // case SiVAL::GT_CONE_EXCURSION: {
    //     chart->setTitle(chartTitle);
    //     setChart(chart);
    // }
    // default:
    //     break;
    // }
}

void ChartView::setEndY(int end) {
    endY = end;
}
void ChartView::setStartY(int start) {
    startY = start;
}

void ChartView::setTitleX(const QString &title) {
    titleX = title;
}
void ChartView::setTitleY(const QString &title) {
    titleY = title;
}

void ChartView::setStartFrequency(double freq) {
    startFrequency = freq;
}

void ChartView::setEndFrequency(double freq) {
    endFrequency = freq;
}

void ChartView::updateChart() {

    // SiVAL::Speaker *speaker = nullptr;
    // switch(graphType) {
    // case SiVAL::GT_RESPONSE: {
    //     speaker = new SiVAL::FrequencyResponseSealed(volume, enclosure);
    //     break;
    // }
    // case SiVAL::GT_GAIN: {
    //     speaker = new SiVAL::Gain(volume, enclosure);
    //     break;
    // }
    // case SiVAL::GT_IMPEDANCE: {
    //     speaker = new SiVAL::ImpedanceSealed(volume, enclosure);
    //     break;
    // }
    // case SiVAL::GT_GROUP_DELAY: {
    //     speaker = new SiVAL::GroupDelaySealed(volume, enclosure);
    //     break;
    // }
    // case SiVAL::GT_CONE_EXCURSION: {
    //     speaker = new SiVAL::ConeExcursionSealed(power, volume, enclosure);
    //     break;
    // }
    // }

    // if(speaker == nullptr) {
    //     return;
    // }

    // serie->clear();

    // double max = 0;
    // double maxf = 0;
    // bool stop = false;
    // for (float f = startFrequency; f != endFrequency; f *= std::pow(10, 1.0/100.0)) {
    //     if(f >= endFrequency) {
    //         stop = true;
    //     }
    //     double value = speaker->response(f);
    //     if(value > max) {
    //         max = value;
    //         maxf = f;
    //     }
    //     serie->append(f, value);

    //     if(stop) {
    //         break;
    //     }
    // }

    // std::cout << graphType << ") Maximaler Impedanzwert: " << max << " | bei Frequnez: " << maxf << std::endl;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
