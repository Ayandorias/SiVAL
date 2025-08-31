/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include<QScrollArea>
//// end includes

//// begin specific includes
#include "nw/navbarpanel.hpp"
#include "sivalwindow.hpp"
//// end specific includes

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
SiVALWindow::SiVALWindow(const QString &projectfile, SpeakerSettingsDocument *doc, QWidget *parent)
    :NW::MainWindow(parent), m_pSpeakerDoc(doc) {

    m_pGroup = new QButtonGroup(this);
    m_pGroup->setExclusive(true);
    connect(m_pGroup, &QButtonGroup::idClicked, this, &SiVALWindow::enclosureSelection);

    /* Fensterleiste bearbeiten, damit die Button ausgeblendet werden können. */
    m_pEnclosureBtn = new NW::SelectionButton("Enclosure", m_pFrameBar);
    m_pEnclosureBtn->hide();
    m_pEnclosureBtn->setCheckable(true);
    m_pEnclosureBtn->setMinimumHeight(45);
    m_pEnclosureBtn->setMaximumHeight(45);
    m_pEnclosureBtn->setChecked(true);
    m_pFrameBar->insertWidget(BTN_Enclosure, m_pEnclosureBtn);
    m_pGroup->addButton(m_pEnclosureBtn, 0);


    speakerSettings();


    /* Hauptansicht des Programms */
    m_pCenterStack = new CenterStack(this);
    setCenterWidget(m_pCenterStack);

    /* Unterfenster für die Hauptansicht des Fensters.
     * Diese werden mit den Buttons in der Seitenleiste ausgewählt
     */

    /*
     * Das Start-Ansicht. Von hier können Projekte erstellt werden und weitere Dinge.
     * */
    QWidget *m_pHomeWidget = new QWidget(this);
    m_pCenterStack->addWidget(m_pHomeWidget);

    /*
     * Die Ansicht, in der die Eigenschaften des Gehäuses überprüft werden können.
     * */
    m_pCenterView = new EnclosureWidget(this);
    m_pCenterStack->addWidget(m_pCenterView);


    m_pSettingsStack = new QStackedWidget(m_pCenterStack);
    m_pCenterStack->addWidget(m_pSettingsStack);
    /*
     * Die Ansicht in dem die Eisntellungen des Programms eingestellt werden können.
     * z.B. welche Lautsprecher Hersteller beim Starten geladen werden.
     */
    m_pSettingsWidget = new SpeakerSettingsWidget(doc, this);
    m_pSettingsStack->addWidget(m_pSettingsWidget);

    NW::NavBarPanel *m_pNavBarPanel = new NW::NavBarPanel(this);
    setSideBarWidget(m_pNavBarPanel);

    m_pHomePanel = new HomePanel();
    m_pNavBarPanel->addPanel(QString(":/icon/home_light.svg"), QString(":/icon/home_dark.svg"), m_pHomePanel);

    // QScrollArea *area = new QScrollArea();
    // area->setMinimumSize(100, 100);
    m_pProjectPanel = new ProjectPanel();
    // m_pProjectPanel->setMinimumSize(area->width(), area->height());
    // area->setWidget(m_pProjectPanel);
    m_pNavBarPanel->addPanel(QString(":/sival/enclosure_light.svg"), QString(":/sival/enclosure_dark.svg"), m_pProjectPanel);


    m_pNavBarPanel->appendPanel(QString(":/icon/cogwheel_light.svg"), QString(":/icon/cogwheel_dark.svg"), new QWidget());

    connect(m_pNavBarPanel, &NW::NavBarPanel::changeCenterView, this, &SiVALWindow::centerViewSelection);


    QList<int> s;
    s << 450 << width() - 450;
    m_pSplitter->setSizes(s);
}

/**************************************************************************************************/
/**
 *
 */
SiVALWindow::~SiVALWindow() {
    m_pSpeakerDoc->save();
    delete m_pSpeakerDoc;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
/**
 * @brief speakerSettings
 */
void SiVALWindow::speakerSettings() {
    m_pSettingsGroup = new QButtonGroup(this);
    m_pSettingsGroup->setExclusive(true);
    connect(m_pSettingsGroup, &QButtonGroup::idClicked, this, &SiVALWindow::settingsSelection);

    /* Fensterleiste bearbeiten, damit die Button ausgeblendet werden können. */
    m_pSpeakerBtn = new NW::SelectionButton("Speaker", m_pFrameBar);
    m_pSpeakerBtn->hide();
    m_pSpeakerBtn->setCheckable(true);
    m_pSpeakerBtn->setMinimumHeight(45);
    m_pSpeakerBtn->setMaximumHeight(45);
    m_pSpeakerBtn->setChecked(true);
    m_pFrameBar->insertWidget(BTN_Speaker, m_pSpeakerBtn);
    m_pSettingsGroup->addButton(m_pSpeakerBtn, 0);

    m_pSpeakerSearchBtn = new NW::SelectionButton("Search", m_pFrameBar);
    m_pSpeakerSearchBtn->hide();
    m_pSpeakerSearchBtn->setCheckable(true);
    m_pSpeakerSearchBtn->setMinimumHeight(45);
    m_pSpeakerSearchBtn->setMaximumHeight(45);
    m_pFrameBar->insertWidget(BTN_Search, m_pSpeakerSearchBtn);
    m_pSettingsGroup->addButton(m_pSpeakerSearchBtn, 1);
}
/**
 * @brief SpeakerSettingsMenu
 * @param visible
 */
void SiVALWindow::menu(bool visible, QButtonGroup *group) {
    QList<QAbstractButton*> list = group->buttons();
    for(int i = 0; i < list.count(); ++i) {
        QAbstractButton *btn = list.at(i);
        if(visible) {
            btn->show();
        } else {
            btn->hide();
        }
    }
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void SiVALWindow::centerViewSelection(int id) {
    if(id == 1) {
        menu(true, m_pGroup);
    } else {
        menu(false, m_pGroup);
    }

    if(id == 2) {
        menu(true, m_pSettingsGroup);
    } else {
        menu(false, m_pSettingsGroup);
    }

    m_pCenterStack->setCurrentIndex(id);
}

void SiVALWindow::enclosureSelection(int id) {
}

void SiVALWindow::mainMenu() {
}

void SiVALWindow::settingsSelection(int id) {

}
//// end protected slots

//// begin private slots
//// end private slots
