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
//// end system includes

//// begin project specific includes
#include "settingsspeaker.hpp"
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
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
SettingsSpeaker::SettingsSpeaker(QWidget *parent)
    :SiVAL::Gui::NavigationPanel(parent) {

    QWidget *w = new QWidget();

    if (w->objectName().isEmpty())
        w->setObjectName("w");

    setWidget(w);
    setWidgetResizable(true);

    verticalLayout = new QVBoxLayout(w);
    verticalLayout->setObjectName("verticalLayout");

    // label = new SiVAL::Gui::HeaderLabel(w);
    // label->setObjectName("label");
    // verticalLayout->addWidget(label);

    m_stack = new QStackedWidget(w);
    m_stack->setObjectName("m_stack");
    m_globalChassis = new SiVAL::Gui::SelectionTree();
    m_globalChassis->setObjectName("m_globalChassis");
    m_stack->addWidget(m_globalChassis);

    m_globalChassis->addChassisEntry("Visaton", 42, true);
    m_globalChassis->addChassisEntry("Scan-Speak", 15);
    m_globalChassis->addChassisEntry("Seas", 23);
    m_globalChassis->addChassisEntry("Dayton Audio", 108);
    m_globalChassis->addChassisEntry("Accuton", 8);
    m_globalChassis->addChassisEntry("Morel", 12);
    m_globalChassis->addChassisEntry("SB Acoustics", 35);
    m_globalChassis->addChassisEntry("Wavecor", 19);




    verticalLayout->addWidget(m_stack);

    m_path = new SiVAL::Gui::HeaderLabel(w);
    m_path->setObjectName("m_path");

    verticalLayout->addWidget(m_path);

    m_pathList = new QListWidget(w);
    new QListWidgetItem(m_pathList);
    new QListWidgetItem(m_pathList);
    new QListWidgetItem(m_pathList);
    m_pathList->setObjectName("m_pathList");
    m_pathList->setMinimumSize(QSize(0, 80));
    m_pathList->setMaximumSize(QSize(16777215, 120));

    verticalLayout->addWidget(m_pathList);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName("horizontalLayout");

    m_new = new SiVAL::Gui::ToolButton(w);
    m_new->setObjectName("m_new");

    horizontalLayout->addWidget(m_new);

    m_edit = new SiVAL::Gui::ToolButton(w);
    m_edit->setObjectName("m_edit");

    horizontalLayout->addWidget(m_edit);

    m_delete = new SiVAL::Gui::ToolButton(w);
    m_delete->setObjectName("m_delete");

    horizontalLayout->addWidget(m_delete);

    QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    horizontalLayout->addItem(horizontalSpacer);

    verticalLayout->addLayout(horizontalLayout);


    retranslate(w);
}

/**************************************************************************************************/
/**
 *
 */
SettingsSpeaker::~SettingsSpeaker() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SettingsSpeaker::retranslate(QWidget *w) {
    w->setWindowTitle(QCoreApplication::translate("w", "Form", nullptr));
    // label->setText(QCoreApplication::translate("w", "Chassis Manufacturer", nullptr));
    m_path->setText(QCoreApplication::translate("w", "Available paths", nullptr));

    const bool __sortingEnabled = m_pathList->isSortingEnabled();
    m_pathList->setSortingEnabled(false);
    QListWidgetItem *___qlistwidgetitem = m_pathList->item(0);
    ___qlistwidgetitem->setText(QCoreApplication::translate("w", "/usr/share/sival/speaker", nullptr));
    ___qlistwidgetitem = m_pathList->item(1);
    ___qlistwidgetitem->setText(QCoreApplication::translate("w", "/usr/share/sival/speaker", nullptr));
    ___qlistwidgetitem = m_pathList->item(2);
    ___qlistwidgetitem->setText(QCoreApplication::translate("w", "/usr/share/sival/speaker", nullptr));

    m_pathList->setSortingEnabled(__sortingEnabled);
}

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
}
