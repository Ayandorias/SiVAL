/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin system includes
#include <QChart>
#include <QChartView>
#include <QGridLayout>
#include <QPushButton>

// #include <sival/sival.hpp>

#include <iostream>
//// end system includes

//// begin project specific includes
#include "chartview.hpp"
#include "enclosurewidget.hpp"
#include "ui_enclosurewidget.h"
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
EnclosureWidget::EnclosureWidget(QWidget *parent)
    :QWidget(parent),
    ui(new Ui::EnclosureWidget) {

    ui->setupUi(this);

    connect(ui->m_pProjectMenu, &ProjectMenu::grossVolumeChanged, this, &EnclosureWidget::grossVolumeChanged);
    connect(ui->m_pProjectMenu, &ProjectMenu::authorChanged, this, &EnclosureWidget::authorChanged);

    ui->m_pProjectMenu->setDisabled(true);

    QGridLayout *grid = new QGridLayout(ui->chartsView);
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);



    // grid->addWidget(createChart(SiVAL::GT_RESPONSE, 10, 1000, 60, 100, "Frequency", "SPL [dB]"), 0, 0);
    // grid->addWidget(createChart(SiVAL::GT_GAIN, 10, 1000, -30, 10, "Frequency", "SPL [dB]"), 0, 1);
    // grid->addWidget(createChart(SiVAL::GT_IMPEDANCE, 10, 1000, 0, 100, "Frequency", "Ohm"), 0, 2);
    // // grid->addWidget(new ChartView(SiVAL::, "Impedance phase"), 2, 1);

    // grid->addWidget(createChart(SiVAL::GT_GROUP_DELAY, 10, 1000, 0, 20, "Frequency", "ms"), 1, 0);
    // grid->addWidget(createChart(SiVAL::GT_CONE_EXCURSION, 10, 1000, 0, 20, "Frequency", "ms"), 1, 1);


    // grid->addWidget(new ChartView(SiVAL::, "Port air velocity"), 1, 1);
    // grid->addWidget(new ChartView(SiVAL::, "ConeExcursion"), 2, 0);
}

/**************************************************************************************************/
/**
 *
 */
EnclosureWidget::~EnclosureWidget() {
    delete ui;
}

// void EnclosureWidget::setEnclosure(EnclosureDocument *enc) {
//     enclosure = enc;

//     updateCharts();
// }
void EnclosureWidget::setPage(SiVAL::PRJ_MENU page) {
    ui->m_pMenu->setCurrentIndex(page);
}
// void EnclosureWidget::setProject(ProjectDocument *doc) {
//     m_pProjectDoc = doc;
//     updateMenu();

//     ui->m_pProjectMenu->setDisabled(false);
// }
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
// ChartView* EnclosureWidget::createChart(SiVAL::GRAPH_TYPE gt, int startFreq, int endFreq, int startY, int endY, const QString &titleX, const QString &titleY) {
//     ChartView *chart = nullptr;
//     switch(gt) {
//     case SiVAL::GT_RESPONSE: {
//         chartResponse = new ChartView(gt, "Frequency response");
//         chart = chartResponse;
//         break;
//     }
//     case SiVAL::GT_GAIN: {
//         chartGain = new ChartView(gt, "Transpher function magnitude");
//         chart = chartGain;
//         break;
//     }
//     case SiVAL::GT_IMPEDANCE: {
//         chartImpedance = new ChartView(gt, "Impedance");
//         chart = chartImpedance;
//         break;
//     }
//     case SiVAL::GT_GROUP_DELAY: {
//         chartGroupDelay = new ChartView(gt, "Group delay");
//         chart = chartGroupDelay;
//         break;
//     }
//     case SiVAL::GT_CONE_EXCURSION: {
//         chartConeExcursion = new ChartView(gt, "ConeExcursion");
//         chart = chartConeExcursion;
//         break;
//     }
//     }
//     chart->setStartFrequency(startFreq);
//     chart->setEndFrequency(endFreq);

//     chart->setStartY(startY);
//     chart->setEndY(endY);

//     chart->setTitleX(titleX);
//     chart->setTitleY(titleY);

//     chart->init();

//     return chart;
// }

void EnclosureWidget::updateCharts() {
    // chartGain->enclosureDocument(m_pProjectDoc->volume(), enclosure);
    // chartGroupDelay->enclosureDocument(m_pProjectDoc->volume(), enclosure);
    // chartImpedance->enclosureDocument(m_pProjectDoc->volume(), enclosure);
    // chartResponse->enclosureDocument(m_pProjectDoc->volume(), enclosure);
    // chartConeExcursion->enclosureDocument(m_pProjectDoc->volume(), enclosure);
}
void EnclosureWidget::updateMenu() {
    // ui->m_pProjectMenu->setAuthor(m_pProjectDoc->author());
    // ui->m_pProjectMenu->setName(m_pProjectDoc->name());
    // ui->m_pProjectMenu->setVolume(m_pProjectDoc->volume());
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void EnclosureWidget::authorChanged(const QString &name) {
    // if(m_pProjectDoc != nullptr) {
    //     m_pProjectDoc->setAuthor(name);
    // }
}
void EnclosureWidget::grossVolumeChanged(const QString &volume) {
    // if(m_pProjectDoc != nullptr) {
    //     m_pProjectDoc->setVolume(volume.toDouble());
    //     updateCharts();
    // }
}
//// end protected slots

//// begin private slots
//// end private slots
