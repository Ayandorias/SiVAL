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
#include <QHBoxLayout>
#include <QFile>
#include <QApplication>

#include <iostream>
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

namespace SiVAL::PM {
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

    setWidget(w);
    setWidgetResizable(true);

    int row = 0;

    gridLayout = new QGridLayout(w);
    gridLayout->setObjectName("gridLayout");

    // m_lang_app = new SiVAL::Gui::HeaderLabel(w);
    // m_lang_app->setObjectName("m_lang_app");

    // gridLayout->addWidget(m_lang_app, row++, 0, 1, 4);
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // m_language = new SiVAL::Gui::Label(w);
    // m_language->setObjectName("m_language");

    // gridLayout->addWidget(m_language, row++, 0, 1, 4);
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // SiVAL::Gui::Line *line = new SiVAL::Gui::Line(w);
    // gridLayout->addWidget(line, row++, 0, 1, 4);
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // m_settingsLang = new QCheckBox(w);
    // m_settingsLang->setObjectName("m_settingsLang");

    // gridLayout->addWidget(m_settingsLang, row++, 0, 1, 4);
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // m_selLang = new SiVAL::Gui::Label(w);
    // m_selLang->setObjectName("m_selLang");
    // m_selLang->setStyleSheet(QString::fromUtf8("margin-left: 16px;"));

    // gridLayout->addWidget(m_selLang, row, 0, 1, 2);

    // comboBox = new QComboBox(w);
    // comboBox->setObjectName("comboBox");
    // comboBox->setMinimumHeight(28);
    // comboBox->setItemDelegate(new QStyledItemDelegate(comboBox));

    // gridLayout->addWidget(comboBox, row++, 2, 1, 2);
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_appearance = new SiVAL::Gui::HeaderLabel(w);
    m_appearance->setObjectName("m_appearance");

    gridLayout->addWidget(m_appearance, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    line = new SiVAL::Gui::Line(w);

    gridLayout->addWidget(line, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_themeSel = new SiVAL::Gui::Label(w);
    m_themeSel->setObjectName("m_themeSel");

    gridLayout->addWidget(m_themeSel, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    QHBoxLayout *h = new QHBoxLayout();
    m_themeAuto = new SiVAL::Gui::StartItem(w);
    m_themeAuto->setIcon(":/sival/" + sSettings()->theme() + "/theme_light.svg");
    m_themeAuto->setObjectName("m_themeAuto");
    m_themeAuto->setMinimumSize(QSize(200, 200));
    m_themeAuto->setMaximumSize(QSize(200, 200));
    connect(m_themeAuto, &SiVAL::Gui::Card::clicked, this, &SettingsGeneral::themeSelector);

    h->addWidget(m_themeAuto);

    m_themeLight = new SiVAL::Gui::StartItem(w);
    m_themeLight->setIcon(":/sival/" + sSettings()->theme() + "/theme_light.svg");
    m_themeLight->setObjectName("m_themeLight");
    m_themeLight->setMinimumSize(QSize(200, 200));
    m_themeLight->setMaximumSize(QSize(200, 200));
    connect(m_themeLight, &SiVAL::Gui::Card::clicked, this, &SettingsGeneral::themeSelector);

    h->addWidget(m_themeLight);

    m_themeDark = new SiVAL::Gui::StartItem(w);
    m_themeDark->setIcon(":/sival/" + sSettings()->theme() + "/theme_dark.svg");
    m_themeDark->setObjectName("m_themeDark");
    m_themeDark->setMinimumSize(QSize(200, 200));
    m_themeDark->setMaximumSize(QSize(200, 200));
    connect(m_themeDark, &SiVAL::Gui::Card::clicked, this, &SettingsGeneral::themeSelector);

    h->addWidget(m_themeDark);

    gridLayout->addLayout(h, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_startup = new SiVAL::Gui::HeaderLabel(w);
    m_startup->setObjectName("m_startup");

    gridLayout->addWidget(m_startup, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    line = new SiVAL::Gui::Line(w);

    gridLayout->addWidget(line, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_splashScreen = new QCheckBox(w);
    m_splashScreen->setObjectName("m_splashScreen");
    connect(m_splashScreen, &QCheckBox::toggled, this, [this](bool checked) {
        sSettings()->setShowSplashScreen(checked);
    });

    gridLayout->addWidget(m_splashScreen, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    line = new SiVAL::Gui::Line(w);

    gridLayout->addWidget(line, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_openLast = new QCheckBox(w);
    m_openLast->setObjectName("m_openLast");
    connect(m_openLast, &QCheckBox::toggled, this, [this](bool open) {
        sSettings()->setOpenLastProject(open);
    });

    gridLayout->addWidget(m_openLast, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_recProCount = new SiVAL::Gui::Label(w);
    m_recProCount->setObjectName("m_recProCount");

    gridLayout->addWidget(m_recProCount, row, 0, 1, 2);

    m_projectCount = new SiVAL::Gui::SpinWidget(w);
    m_projectCount->setObjectName("m_projectCount");
    m_projectCount->setMinimum(0);
    connect(m_projectCount, &SiVAL::Gui::SpinWidget::valueChanged, this, [this](int value) {
        sSettings()->setLastProjectCount(m_projectCount->value());
    });

    gridLayout->addWidget(m_projectCount, row++, 2, 1, 1);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_project = new SiVAL::Gui::HeaderLabel(w);
    m_project->setObjectName("m_project");

    gridLayout->addWidget(m_project, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    line = new SiVAL::Gui::Line(w);

    gridLayout->addWidget(line, row++, 0, 1, 4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_autoSave = new QCheckBox(w);
    m_autoSave->setObjectName("m_autoSave");
    connect(m_autoSave, &QCheckBox::toggled, this, [this](bool save) {
        sSettings()->setAutoSave(save);
        if(save) {
            m_SaveTime->setDisabled(false);
        } else {
            m_SaveTime->setDisabled(true);
        }
    });

    gridLayout->addWidget(m_autoSave, row, 0, 1, 2);

    m_SaveTime = new SiVAL::Gui::SpinWidget(w);
    m_SaveTime->setObjectName("m_SaveTime");
    m_SaveTime->setMinimum(0);
    connect(m_SaveTime, &SiVAL::Gui::SpinWidget::valueChanged, this, [this](int value) {
        sSettings()->setAutoSaveTime(m_SaveTime->value());
    });

    gridLayout->addWidget(m_SaveTime, row, 2, 1, 1);

    m_minute = new SiVAL::Gui::Label(w);
    m_minute->setObjectName("m_minute");

    gridLayout->addWidget(m_minute, row++, 3, 1, 1);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_author = new SiVAL::Gui::Label(w);
    m_author->setObjectName("m_author");

    gridLayout->addWidget(m_author, row, 0, 1, 1);

    m_authorEdit = new QLineEdit(w);
    m_authorEdit->setObjectName("m_authorEdit");
    m_authorEdit->setMinimumHeight(28);
    connect(m_authorEdit, &QLineEdit::textChanged, this, [this](const QString &value) {
        sSettings()->setAuthor(value);
    });

    gridLayout->addWidget(m_authorEdit, row++, 1, 1, 3);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    m_company = new SiVAL::Gui::Label(w);
    m_company->setObjectName("m_company");

    gridLayout->addWidget(m_company, row, 0, 1, 1);

    m_companyEdit = new QLineEdit(w);
    m_companyEdit->setObjectName("m_companyEdit");
    m_companyEdit->setMinimumHeight(28);
    connect(m_companyEdit, &QLineEdit::textChanged, this, [this](const QString &value) {
        sSettings()->setCompany(value);
    });

    gridLayout->addWidget(m_companyEdit, row++, 1, 1, 3);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // m_license = new SiVAL::Gui::Label(w);
    // m_license->setObjectName("m_license");

    // gridLayout->addWidget(m_license, row, 0, 1, 1);

    // m_licenseBox = new QComboBox(w);
    // m_licenseBox->setObjectName("m_licenseBox");
    // m_licenseBox->setMinimumHeight(28);

    // gridLayout->addWidget(m_licenseBox, row++, 1, 1, 3);
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // m_licenseUrl = new SiVAL::Gui::Label(w);
    // m_licenseUrl->setObjectName("m_licenseUrl");

    // gridLayout->addWidget(m_licenseUrl, row, 0, 1, 1);

    // m_licenseUrlEdit = new QLineEdit(w);
    // m_licenseUrlEdit->setObjectName("m_licenseUrlEdit");
    // m_licenseUrlEdit->setReadOnly(true);
    // m_licenseUrlEdit->setMinimumHeight(28);

    // gridLayout->addWidget(m_licenseUrlEdit, row++, 1, 1, 3);
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // m_onlineHelp = new QCheckBox(w);
    // gridLayout->addWidget(m_onlineHelp, row++, 0, 1, 4);
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // m_localHelp = new SiVAL::Gui::Label(w);
    // m_localHelp->setObjectName("m_localHelp");

    // gridLayout->addWidget(m_localHelp, row, 0, 1, 1);

    // m_helpPath = new QLineEdit(w);
    // m_helpPath->setObjectName("m_licenseUrlEdit");
    // m_helpPath->setReadOnly(true);
    // m_helpPath->setMinimumHeight(28);

    // gridLayout->addWidget(m_helpPath, row, 1, 1, 2);

    // m_selectHelp = new QPushButton("...", w);
    // m_selectHelp->setMinimumHeight(28);
    // m_selectHelp->setMaximumHeight(28);
    // gridLayout->addWidget(m_selectHelp, row++, 3, 1, 1);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    gridLayout->addItem(verticalSpacer, row++, 0, 1, 1);

    gridLayout->setColumnStretch(0, 1);
    gridLayout->setColumnStretch(1, 1);
    gridLayout->setColumnStretch(2, 1);

    retranslate(w);

    updateSettings();
}

/**************************************************************************************************/
/**
 *
 */
SettingsGeneral::~SettingsGeneral() {
}

void SettingsGeneral::updateSettings() {
    QString theme = sSettings()->themeSelect();
    if(theme == "light") {
        m_themeLight->setChecked(true);
    } else if(theme == "dark") {
        m_themeDark->setChecked(true);
    } else if(theme == "auto") {
        m_themeAuto->setChecked(true);
    }

    m_splashScreen->setChecked(sSettings()->showSplashScreen());

    m_openLast->setChecked(sSettings()->openLastProject());

    m_projectCount->setValue(sSettings()->lastProjectCount());

    m_autoSave->setChecked(sSettings()->autoSave());
    if(sSettings()->autoSave()) {
        m_SaveTime->setDisabled(false);
    } else {
        m_SaveTime->setDisabled(true);
    }
    m_SaveTime->setValue(sSettings()->autoSaveTime());

    m_authorEdit->setText(sSettings()->author());
    m_companyEdit->setText(sSettings()->company());
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SettingsGeneral::retranslate(QWidget *w) {
    // m_lang_app->setText(QCoreApplication::translate("w", "Language and Appearance", nullptr));
    // m_language->setText(QCoreApplication::translate("w", "Language", nullptr));
    // m_settingsLang->setText(QCoreApplication::translate("w", "Use System Settings", nullptr));
    // m_selLang->setText(QCoreApplication::translate("w", "Choose the language for the application.", nullptr));

    w->setWindowTitle(QCoreApplication::translate("w", "Form", nullptr));
    m_splashScreen->setText(QCoreApplication::translate("w", "Show splash screen", nullptr));
    m_appearance->setText(QCoreApplication::translate("w", "Appearance", nullptr));
    m_minute->setText(QCoreApplication::translate("w", "minutes", nullptr));
    m_autoSave->setText(QCoreApplication::translate("w", "Auto Save (every)", nullptr));
    m_themeSel->setText(QCoreApplication::translate("w", "User Interface", nullptr));
    m_project->setText(QCoreApplication::translate("w", "Project", nullptr));
    m_startup->setText(QCoreApplication::translate("w", "Startup", nullptr));
    m_recProCount->setText(QCoreApplication::translate("w", "Number of recent projects", nullptr));
    m_openLast->setText(QCoreApplication::translate("w", "Open last Project", nullptr));
    m_author->setText(QCoreApplication::translate("w", "Author", nullptr));
    m_company->setText(QCoreApplication::translate("w", "Company", nullptr));

    // m_license->setText(QCoreApplication::translate("w", "License", nullptr));
    // m_licenseUrl->setText(QCoreApplication::translate("w", "License Url", nullptr));


    // m_onlineHelp->setText(QCoreApplication::translate("w", "Use online help", nullptr));
    // m_localHelp->setText(QCoreApplication::translate("w", "Local help path", nullptr));

    m_themeAuto->setTitle(tr("Automatic"));
    m_themeDark->setTitle(tr("Dark"));
    m_themeLight->setTitle(tr("Light"));
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void SettingsGeneral::themeSelector() {
    QObject *obj = sender();
    m_themeAuto->setChecked(false);
    m_themeDark->setChecked(false);
    m_themeLight->setChecked(false);
    if(obj == m_themeAuto) {
        m_themeAuto->setChecked(true);
        sSettings()->setThemeSelect("auto");
    } else if(obj == m_themeDark) {
        m_themeDark->setChecked(true);
        sSettings()->setThemeSelect("dark");
    } else if(obj == m_themeLight) {
        m_themeLight->setChecked(true);
        sSettings()->setThemeSelect("light");
    }

    // UND die Anwendung kann das Theme laden:
    QFile file(":/sival/" + sSettings()->theme() + "/" + sSettings()->theme() + ".qss");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        qApp->setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }
}
//// end protected slots

//// begin private slots
//// end private slots
}
