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
#include "settingsabout.hpp"
#include "version.hpp"
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
SettingsAbout::SettingsAbout(QWidget *parent)
    :SiVAL::Gui::NavigationPanel(parent) {

    QWidget *w = new QWidget();
    setWidget(w);
    setWidgetResizable(true);


    if (w->objectName().isEmpty())
        w->setObjectName("w");
    w->resize(981, 863);
    gridLayout = new QGridLayout(w);
    gridLayout->setObjectName("gridLayout");
    gridLayout->setVerticalSpacing(6);
    m_bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    gridLayout->addItem(m_bottomSpacer, 11, 1, 1, 1);

    m_version = new QLabel(w);
    m_version->setObjectName("m_version");
    m_version->setMinimumSize(QSize(0, 0));
    m_version->setMaximumSize(QSize(16777215, 16777215));

    gridLayout->addWidget(m_version, 2, 2, 1, 1);

    m_topSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    gridLayout->addItem(m_topSpacer, 0, 1, 1, 1);

    verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);

    m_logo = new QLabel(w);
    m_logo->setObjectName("m_logo");
    m_logo->setMinimumSize(QSize(64, 64));
    m_logo->setMaximumSize(QSize(64, 64));
    m_logo->setPixmap(QPixmap(QString::fromUtf8(":/sival/logo/speaker.svg")));
    m_logo->setScaledContents(true);
    m_logo->setAlignment(Qt::AlignmentFlag::AlignCenter);

    gridLayout->addWidget(m_logo, 1, 1, 4, 1);

    verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    gridLayout->addItem(verticalSpacer, 7, 1, 1, 1);

    m_license = new QLabel(w);
    m_license->setObjectName("m_license");
    m_license->setMinimumSize(QSize(0, 0));
    m_license->setMaximumSize(QSize(16777215, 16777215));
    m_license->setOpenExternalLinks(true);
    m_license->setTextFormat(Qt::RichText);

    gridLayout->addWidget(m_license, 4, 2, 1, 1);

    m_leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    gridLayout->addItem(m_leftSpacer, 0, 0, 1, 1);

    m_copyright = new QLabel(w);
    m_copyright->setObjectName("m_copyright");
    m_copyright->setMinimumSize(QSize(0, 0));
    m_copyright->setMaximumSize(QSize(16777215, 16777215));

    gridLayout->addWidget(m_copyright, 3, 2, 1, 1);

    m_systemInfoBox = new QGroupBox(w);
    m_systemInfoBox->setObjectName("m_systemInfoBox");
    m_systemInfoBox->setFlat(true);
    gridLayout_2 = new QGridLayout(m_systemInfoBox);
    gridLayout_2->setObjectName("gridLayout_2");
    m_revisionInfo = new QLabel(m_systemInfoBox);
    m_revisionInfo->setObjectName("m_revisionInfo");

    gridLayout_2->addWidget(m_revisionInfo, 0, 1, 1, 1);

    m_qtVersion = new QLabel(m_systemInfoBox);
    m_qtVersion->setObjectName("m_qtVersion");
    m_qtVersion->setMinimumSize(QSize(150, 0));
    m_qtVersion->setMaximumSize(QSize(150, 16777215));
    m_qtVersion->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

    gridLayout_2->addWidget(m_qtVersion, 3, 0, 1, 1);

    m_revision = new QLabel(m_systemInfoBox);
    m_revision->setObjectName("m_revision");
    m_revision->setMinimumSize(QSize(150, 0));
    m_revision->setMaximumSize(QSize(150, 16777215));
    m_revision->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

    gridLayout_2->addWidget(m_revision, 0, 0, 1, 1);

    m_buildDate = new QLabel(m_systemInfoBox);
    m_buildDate->setObjectName("m_buildDate");
    m_buildDate->setMinimumSize(QSize(150, 0));
    m_buildDate->setMaximumSize(QSize(150, 16777215));
    m_buildDate->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

    gridLayout_2->addWidget(m_buildDate, 1, 0, 1, 1);

    m_compiler = new QLabel(m_systemInfoBox);
    m_compiler->setObjectName("m_compiler");
    m_compiler->setMinimumSize(QSize(150, 0));
    m_compiler->setMaximumSize(QSize(150, 16777215));
    m_compiler->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

    gridLayout_2->addWidget(m_compiler, 2, 0, 1, 1);

    m_system = new QLabel(m_systemInfoBox);
    m_system->setObjectName("m_system");
    m_system->setMinimumSize(QSize(150, 0));
    m_system->setMaximumSize(QSize(150, 16777215));
    m_system->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

    gridLayout_2->addWidget(m_system, 4, 0, 1, 1);

    m_buildDateInfo = new QLabel(m_systemInfoBox);
    m_buildDateInfo->setObjectName("m_buildDateInfo");

    gridLayout_2->addWidget(m_buildDateInfo, 1, 1, 1, 1);

    m_compilerInfo = new QLabel(m_systemInfoBox);
    m_compilerInfo->setObjectName("m_compilerInfo");

    gridLayout_2->addWidget(m_compilerInfo, 2, 1, 1, 1);

    m_qtVersionInfo = new QLabel(m_systemInfoBox);
    m_qtVersionInfo->setObjectName("m_qtVersionInfo");

    gridLayout_2->addWidget(m_qtVersionInfo, 3, 1, 1, 1);

    m_SystemInfo = new QLabel(m_systemInfoBox);
    m_SystemInfo->setObjectName("m_SystemInfo");

    gridLayout_2->addWidget(m_SystemInfo, 4, 1, 1, 1);


    gridLayout->addWidget(m_systemInfoBox, 8, 1, 1, 2);

    verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    gridLayout->addItem(verticalSpacer_3, 9, 1, 1, 1);

    m_title = new QLabel(w);
    m_title->setObjectName("titleAbout");
    m_title->setMinimumSize(QSize(0, 0));
    m_title->setMaximumSize(QSize(16777215, 16777215));
    m_title->setText(QCoreApplication::translate("w", "SiVAL", nullptr));

    gridLayout->addWidget(m_title, 1, 2, 1, 1);

    line = new QFrame(w);
    line->setObjectName("line");
    line->setFrameShape(QFrame::Shape::HLine);
    line->setFrameShadow(QFrame::Shadow::Sunken);


    gridLayout->addWidget(line, 6, 1, 1, 2);

    frame = new QFrame(w);
    frame->setObjectName("additional_info");
    frame->setFrameShape(QFrame::Shape::Box);
    frame->setFrameShadow(QFrame::Shadow::Raised);
    verticalLayout = new QVBoxLayout(frame);
    verticalLayout->setObjectName("verticalLayout");
    m_library = new QLabel(frame);
    m_library->setObjectName("libraryAbout");

    verticalLayout->addWidget(m_library);

    m_libQt = new QLabel(frame);
    m_libQt->setObjectName("libQt");
    m_libQt->setOpenExternalLinks(true);
    m_libQt->setTextFormat(Qt::RichText);

    verticalLayout->addWidget(m_libQt);

    m_libSival = new QLabel(frame);
    m_libSival->setObjectName("libSival");
    m_libSival->setOpenExternalLinks(true);
    m_libSival->setTextFormat(Qt::RichText);

    verticalLayout->addWidget(m_libSival);

    m_libLohmann = new QLabel(frame);
    m_libLohmann->setObjectName("libLohmann");
    m_libLohmann->setOpenExternalLinks(true);
    m_libLohmann->setTextFormat(Qt::RichText);

    verticalLayout->addWidget(m_libLohmann);

    verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    verticalLayout->addItem(verticalSpacer_4);

    m_assets = new QLabel(frame);
    m_assets->setObjectName("assetsAbout");

    verticalLayout->addWidget(m_assets);


    gridLayout->addWidget(frame, 10, 1, 1, 2);

    m_rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    gridLayout->addItem(m_rightSpacer, 0, 3, 1, 1);

    gridLayout->setColumnStretch(0, 1);
    gridLayout->setColumnStretch(1, 1);
    gridLayout->setColumnStretch(2, 1);
    gridLayout->setColumnStretch(3, 1);
    gridLayout->setColumnMinimumWidth(2, 500);

    retranslate(w);
}

/**************************************************************************************************/
/**
 *
 */
SettingsAbout::~SettingsAbout() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SettingsAbout::retranslate(QWidget *w) {
    m_version->setText(QCoreApplication::translate("w", "Version: ", nullptr) + SiVAL::Version::getFullString());
    m_copyright->setText(tr("%1 since 2025 by").arg(QChar(0x00A9)) + QString(" Bruno Pierucki"));
    m_license->setText(tr("Licensed under the <a href='https://www.gnu.org/licenses/gpl-3.0.html'>GPLv3</a>"));
    m_revisionInfo->setText(SiVAL::Version::getRevision());
    m_buildDateInfo->setText(SiVAL::Version::getTimestamp());
    m_compilerInfo->setText(SiVAL::Version::getCompiler());
    QString versionInfo = tr("Runtime: %1 (Built against: %2)")
                              .arg(qVersion())
                              .arg(QT_VERSION_STR);
    m_qtVersionInfo->setText(versionInfo);
    m_SystemInfo->setText(SiVAL::Version::getFullSystemString());

    m_library->setText(QCoreApplication::translate("w", "Libraries", nullptr));
    m_libQt->setText(tr("<a href='https://www.qt.io/'>Qt</a> built version <a href='https://doc.qt.io/qt-6/'>%1</a>").arg(QT_VERSION_STR));
    m_libSival->setText(tr("<a href='http:///www.sival-software.org'>libSiVAL</a> <a href='https://www.gnu.org/licenses/lgpl-3.0.html'>LGPL3</a>"));
    m_libLohmann->setText(tr("<a href='https://github.com/nlohmann/json'>nlohmann/json</a> <a href='https://opensource.org/licenses/MIT'>(MIT)</a>"));




    m_systemInfoBox->setTitle(QCoreApplication::translate("w", "Systeminformation", nullptr));
    m_qtVersion->setText(QCoreApplication::translate("w", "Qt Version:", nullptr));
    m_revision->setText(QCoreApplication::translate("w", "Revision:", nullptr));
    m_buildDate->setText(QCoreApplication::translate("w", "Build on:", nullptr));
    m_compiler->setText(QCoreApplication::translate("w", "Compiler:", nullptr));
    m_system->setText(QCoreApplication::translate("w", "System:", nullptr));
    m_assets->setText(QCoreApplication::translate("w", "Assets", nullptr));
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
