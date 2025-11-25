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
#include <QStyledItemDelegate>
//// end system includes

//// begin project specific includes
#include "settingsgeneral.hpp"
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
SettingsGeneral::SettingsGeneral(QWidget *parent)
    :SiVAL::Gui::NavigationPanel(parent) {

    QWidget *w = new QWidget();
    // w->setStyleSheet("background-color: #0f0;");

    if (w->objectName().isEmpty())
        w->setObjectName("w");
    // w->resize(899, 100);
    gridLayout = new QGridLayout(w);
    gridLayout->setObjectName("gridLayout");
    m_settingsLang = new QCheckBox(w);
    m_settingsLang->setObjectName("m_settingsLang");

    gridLayout->addWidget(m_settingsLang, 3, 0, 1, 4);

    comboBox = new QComboBox(w);
    comboBox->setObjectName("comboBox");
    comboBox->setMinimumHeight(28);
    comboBox->setItemDelegate(new QStyledItemDelegate(comboBox));
    comboBox->addItem("Juhu das klappt1");
    comboBox->addItem("Juhu das klappt2");
    comboBox->addItem("Juhu das klappt3");
    comboBox->addItem("Juhu das klappt4");
    comboBox->addItem("Juhu das klappt5");
    comboBox->addItem("Juhu das klappt6");
    comboBox->addItem("Juhu das klappt7");
    comboBox->addItem("Juhu das klappt8");


    gridLayout->addWidget(comboBox, 4, 2, 1, 2);

    m_splashScreen = new QCheckBox(w);
    m_splashScreen->setObjectName("m_splashScreen");

    gridLayout->addWidget(m_splashScreen, 12, 0, 1, 4);

    m_licenseUrlEdit = new QLineEdit(w);
    m_licenseUrlEdit->setObjectName("m_licenseUrlEdit");
    m_licenseUrlEdit->setReadOnly(true);
    m_licenseUrlEdit->setMinimumHeight(28);

    gridLayout->addWidget(m_licenseUrlEdit, 22, 1, 1, 3);

    m_company = new SiVAL::Gui::Label(w);
    m_company->setObjectName("m_company");

    gridLayout->addWidget(m_company, 20, 0, 1, 1);

    m_author = new SiVAL::Gui::Label(w);
    m_author->setObjectName("m_author");

    gridLayout->addWidget(m_author, 19, 0, 1, 1);

    m_licenseBox = new QComboBox(w);
    m_licenseBox->setObjectName("m_licenseBox");
    m_licenseBox->setMinimumHeight(28);

    gridLayout->addWidget(m_licenseBox, 21, 1, 1, 3);

    m_appearance = new SiVAL::Gui::HeaderLabel(w);
    m_appearance->setObjectName("m_appearance");

    gridLayout->addWidget(m_appearance, 5, 0, 1, 4);

    m_licenseUrl = new SiVAL::Gui::Label(w);
    m_licenseUrl->setObjectName("m_licenseUrl");

    gridLayout->addWidget(m_licenseUrl, 22, 0, 1, 1);

    m_minute = new SiVAL::Gui::Label(w);
    m_minute->setObjectName("m_minute");

    gridLayout->addWidget(m_minute, 18, 3, 1, 1);

    m_autoSave = new QCheckBox(w);
    m_autoSave->setObjectName("m_autoSave");

    gridLayout->addWidget(m_autoSave, 18, 0, 1, 2);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    gridLayout->addItem(verticalSpacer, 23, 0, 1, 1);

    line = new QFrame(w);
    line->setObjectName("line");
    line->setFrameShape(QFrame::Shape::HLine);
    line->setFrameShadow(QFrame::Shadow::Sunken);

    gridLayout->addWidget(line, 6, 0, 1, 3);

    m_themeSel = new SiVAL::Gui::Label(w);
    m_themeSel->setObjectName("m_themeSel");

    gridLayout->addWidget(m_themeSel, 7, 0, 1, 4);

    line_3 = new QFrame(w);
    line_3->setObjectName("line_3");
    line_3->setFrameShape(QFrame::Shape::HLine);
    line_3->setFrameShadow(QFrame::Shadow::Sunken);

    gridLayout->addWidget(line_3, 13, 0, 1, 3);

    m_authorEdit = new QLineEdit(w);
    m_authorEdit->setObjectName("m_authorEdit");
    m_authorEdit->setMinimumHeight(28);

    gridLayout->addWidget(m_authorEdit, 19, 1, 1, 3);

    m_project = new SiVAL::Gui::HeaderLabel(w);
    m_project->setObjectName("m_project");

    gridLayout->addWidget(m_project, 16, 0, 1, 4);

    m_themeDark = new QWidget(w);
    m_themeDark->setObjectName("m_themeDark");
    m_themeDark->setMinimumSize(QSize(0, 40));
    m_themeDark->setMaximumSize(QSize(16777215, 40));

    gridLayout->addWidget(m_themeDark, 8, 2, 1, 1);

    m_SaveTime = new SiVAL::Gui::SpinWidget(w);
    m_SaveTime->setObjectName("m_SaveTime");

    gridLayout->addWidget(m_SaveTime, 18, 2, 1, 1);

    m_startup = new SiVAL::Gui::HeaderLabel(w);
    m_startup->setObjectName("m_startup");

    gridLayout->addWidget(m_startup, 9, 0, 1, 4);

    line_2 = new QFrame(w);
    line_2->setObjectName("line_2");
    line_2->setFrameShape(QFrame::Shape::HLine);
    line_2->setFrameShadow(QFrame::Shadow::Sunken);

    gridLayout->addWidget(line_2, 10, 0, 1, 3);

    m_themeAuto = new QWidget(w);
    m_themeAuto->setObjectName("m_themeAuto");
    m_themeAuto->setMinimumSize(QSize(0, 40));
    m_themeAuto->setMaximumSize(QSize(16777215, 40));

    gridLayout->addWidget(m_themeAuto, 8, 0, 1, 1);

    m_lang_app = new SiVAL::Gui::HeaderLabel(w);
    m_lang_app->setObjectName("m_lang_app");

    gridLayout->addWidget(m_lang_app, 0, 0, 1, 4);

    m_recProCount = new SiVAL::Gui::Label(w);
    m_recProCount->setObjectName("m_recProCount");

    gridLayout->addWidget(m_recProCount, 15, 0, 1, 2);

    m_companyEdit = new QLineEdit(w);
    m_companyEdit->setObjectName("m_companyEdit");
    m_companyEdit->setMinimumHeight(28);

    gridLayout->addWidget(m_companyEdit, 20, 1, 1, 3);

    m_openLast = new QCheckBox(w);
    m_openLast->setObjectName("m_openLast");

    gridLayout->addWidget(m_openLast, 14, 0, 1, 4);

    m_projectCount = new SiVAL::Gui::SpinWidget(w);
    m_projectCount->setObjectName("m_projectCount");

    gridLayout->addWidget(m_projectCount, 15, 2, 1, 1);

    m_selLang = new SiVAL::Gui::Label(w);
    m_selLang->setObjectName("m_selLang");
    m_selLang->setStyleSheet(QString::fromUtf8("margin-left: 16px;"));

    gridLayout->addWidget(m_selLang, 4, 0, 1, 2);

    horizontalLine = new QFrame(w);
    horizontalLine->setObjectName("horizontalLine");
    horizontalLine->setMinimumSize(QSize(0, 0));
    horizontalLine->setFrameShape(QFrame::Shape::HLine);
    horizontalLine->setFrameShadow(QFrame::Shadow::Sunken);

    gridLayout->addWidget(horizontalLine, 2, 0, 1, 3);

    line_4 = new QFrame(w);
    line_4->setObjectName("line_4");
    line_4->setFrameShape(QFrame::Shape::HLine);
    line_4->setFrameShadow(QFrame::Shadow::Sunken);

    gridLayout->addWidget(line_4, 17, 0, 1, 3);

    m_license = new SiVAL::Gui::Label(w);
    m_license->setObjectName("m_license");

    gridLayout->addWidget(m_license, 21, 0, 1, 1);

    m_themeLight = new QWidget(w);
    m_themeLight->setObjectName("m_themeLight");
    m_themeLight->setMinimumSize(QSize(0, 40));
    m_themeLight->setMaximumSize(QSize(16777215, 40));

    gridLayout->addWidget(m_themeLight, 8, 1, 1, 1);

    m_language = new SiVAL::Gui::Label(w);
    m_language->setObjectName("m_language");

    gridLayout->addWidget(m_language, 1, 0, 1, 4);

    gridLayout->setColumnStretch(0, 1);
    gridLayout->setColumnStretch(1, 1);
    gridLayout->setColumnStretch(2, 1);

    retranslate(w);

    setWidget(w);
    setWidgetResizable(true);
}

/**************************************************************************************************/
/**
 *
 */
SettingsGeneral::~SettingsGeneral() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SettingsGeneral::retranslate(QWidget *w) {
    w->setWindowTitle(QCoreApplication::translate("w", "Form", nullptr));
    m_settingsLang->setText(QCoreApplication::translate("w", "Use System Settings", nullptr));
    m_splashScreen->setText(QCoreApplication::translate("w", "Show splash screen", nullptr));
    m_company->setText(QCoreApplication::translate("w", "Company", nullptr));
    m_author->setText(QCoreApplication::translate("w", "Author", nullptr));
    m_appearance->setText(QCoreApplication::translate("w", "Appearance", nullptr));
    m_licenseUrl->setText(QCoreApplication::translate("w", "License Url", nullptr));
    m_minute->setText(QCoreApplication::translate("w", "minutes", nullptr));
    m_autoSave->setText(QCoreApplication::translate("w", "Auto Save (every)", nullptr));
    m_themeSel->setText(QCoreApplication::translate("w", "Choose the colour for SiVAL", nullptr));
    m_project->setText(QCoreApplication::translate("w", "Project", nullptr));
    m_startup->setText(QCoreApplication::translate("w", "Startup", nullptr));
    m_lang_app->setText(QCoreApplication::translate("w", "Language and Appearance", nullptr));
    m_recProCount->setText(QCoreApplication::translate("w", "Number of recent projects", nullptr));
    m_openLast->setText(QCoreApplication::translate("w", "Open last Project", nullptr));
    m_selLang->setText(QCoreApplication::translate("w", "Choose the language for the application.", nullptr));
    m_license->setText(QCoreApplication::translate("w", "License", nullptr));
    m_language->setText(QCoreApplication::translate("w", "Language", nullptr));
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
