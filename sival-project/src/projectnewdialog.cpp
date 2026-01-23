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
#include <QDir>
#include <QFileDialog>
#include <QJsonObject>
#include <QUuid>
//// end system includes

//// begin project specific includes
#include "projectnewdialog.hpp"
#include "sivalcore/documents/projectdocument.hpp"
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
ProjectNewDialog::ProjectNewDialog(QWidget *parent)
    :SiVAL::Gui::OverlayDialog(parent) {


    setupUi(m_centerWidget);

    m_authorEdit->setText(sSettings()->author());
    m_volumeEdit->setValue(25);
    textChanged(QString());
}

/**************************************************************************************************/
/**
 *
 */
ProjectNewDialog::~ProjectNewDialog() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void ProjectNewDialog::setupUi(QWidget *ProjectNewDialog) {
    ProjectNewDialog->setObjectName("dialogCenterWidget");

    ProjectNewDialog->resize(1042, 526);
    ProjectNewDialog->setStyleSheet(QString::fromUtf8(""));
    verticalLayout = new QVBoxLayout(ProjectNewDialog);
    verticalLayout->setObjectName("verticalLayout");
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    // m_header = new SiVAL::Gui::HeaderLabel(ProjectNewDialog);
    // m_header->setObjectName("m_header");
    // verticalLayout->addWidget(m_header);

    m_headerInfo = new SiVAL::Gui::Label(ProjectNewDialog);
    m_headerInfo->setObjectName("dialogHeaderInfo");

    verticalLayout->addWidget(m_headerInfo);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    verticalLayout->addItem(verticalSpacer);

    gridLayout = new QGridLayout();
    gridLayout->setObjectName("gridLayout");
    m_volume = new SiVAL::Gui::Label(ProjectNewDialog);
    m_volume->setObjectName("m_volume");

    gridLayout->addWidget(m_volume, 3, 0, 1, 1);

    m_projectName = new QLineEdit(ProjectNewDialog);
    m_projectName->setObjectName("m_projectName");
    m_projectName->setMinimumSize(QSize(0, 32));
    // m_projectName->setStyleSheet(QString::fromUtf8("background-color:#ffffff; color: #606060;"));
    connect(m_projectName, &QLineEdit::textChanged, this, &ProjectNewDialog::textChanged);

    gridLayout->addWidget(m_projectName, 0, 1, 1, 2);

    m_authorEdit = new QLineEdit(ProjectNewDialog);
    m_authorEdit->setObjectName("m_authorEdit");
    m_authorEdit->setMinimumSize(QSize(0, 32));
    m_authorEdit->setText(sSettings()->author());
    // m_authorEdit->setStyleSheet(QString::fromUtf8("background-color:#ffffff; color: #606060;"));

    gridLayout->addWidget(m_authorEdit, 1, 1, 1, 2);

    m_infoLabel = new SiVAL::Gui::Label(ProjectNewDialog);
    m_infoLabel->setObjectName("m_infoLabel");

    gridLayout->addWidget(m_infoLabel, 8, 1, 1, 1);

    m_selection = new SiVAL::Gui::Label(ProjectNewDialog);
    m_selection->setObjectName("m_selection");

    gridLayout->addWidget(m_selection, 6, 0, 1, 1);

    m_project = new SiVAL::Gui::Label(ProjectNewDialog);
    m_project->setObjectName("m_project");

    gridLayout->addWidget(m_project, 0, 0, 1, 1);

    m_author = new SiVAL::Gui::Label(ProjectNewDialog);
    m_author->setObjectName("m_author");

    gridLayout->addWidget(m_author, 1, 0, 1, 1);

    m_volumeEdit = new SiVAL::Gui::SpinWidget(ProjectNewDialog);
    m_volumeEdit->setObjectName("m_volumeEdit");
    m_volumeEdit->setMinimumSize(QSize(0, 32));
    m_volumeEdit->setStyleSheet(QString::fromUtf8("background-color:#ffffff; color: #606060;"));

    gridLayout->addWidget(m_volumeEdit, 3, 1, 1, 2);

    m_warningLabel = new QLabel(ProjectNewDialog);
    m_warningLabel->setObjectName("m_warningLabel");
    m_warningLabel->setMinimumSize(QSize(16, 16));
    m_warningLabel->setMaximumSize(QSize(16, 16));
    m_warningLabel->setPixmap(QPixmap(":/sival/" + sSettings()->theme() + "/warning.svg"));
    m_warningLabel->setScaledContents(true);
    m_warningLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

    gridLayout->addWidget(m_warningLabel, 8, 0, 1, 1);

    verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    gridLayout->addItem(verticalSpacer_3, 8, 2, 1, 1);

    verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    gridLayout->addItem(verticalSpacer_4, 4, 1, 1, 1);

    m_projectPath = new QLineEdit(ProjectNewDialog);
    m_projectPath->setObjectName("m_projectPath");
    m_projectPath->setMinimumSize(QSize(0, 32));
    m_projectPath->setText(sSettings()->projectPath());
    m_projectPath->setReadOnly(true);
    // m_projectPath->setStyleSheet(QString::fromUtf8("background-color:#ffffff; color: #606060;"));

    gridLayout->addWidget(m_projectPath, 6, 1, 1, 1);

    m_projectFolder = new QPushButton(ProjectNewDialog);
    m_projectFolder->setObjectName("m_projectFolder");
    m_projectFolder->setMinimumSize(QSize(0, 32));
    connect(m_projectFolder, &QPushButton::clicked, this, &ProjectNewDialog::openFolder);
    gridLayout->addWidget(m_projectFolder, 6, 2, 1, 1);

    verticalLayout->addLayout(gridLayout);

    verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    verticalLayout->addItem(verticalSpacer_2);

    retranslateUi(ProjectNewDialog);

    connect(m_pAccept, &QPushButton::clicked, this, &ProjectNewDialog::createNewProject);
}

void ProjectNewDialog::retranslateUi(QWidget *ProjectNewDialog) {
    ProjectNewDialog->setWindowTitle(QCoreApplication::translate("ProjectNewDialog", "Form", nullptr));
    m_headerInfo->setText(QCoreApplication::translate("ProjectNewDialog", "Generates an  Enclosure Project for your Speaker.", nullptr));
    m_volume->setText(QCoreApplication::translate("ProjectNewDialog", " Volume (l):", nullptr));
    m_projectName->setPlaceholderText(QCoreApplication::translate("ProjectNewDialog", "Projectname", nullptr));
    m_infoLabel->setText(QCoreApplication::translate("ProjectNewDialog", "A Folder with the project name already excist.", nullptr));
    m_selection->setText(QCoreApplication::translate("ProjectNewDialog", "Select Project Folder: ", nullptr));
    m_project->setText(QCoreApplication::translate("ProjectNewDialog", "Name:", nullptr));
    m_author->setText(QCoreApplication::translate("ProjectNewDialog", "Author:", nullptr));
    // m_volumeEdit->setPlaceholderText(QCoreApplication::translate("ProjectNewDialog", "25", nullptr));
    m_warningLabel->setText(QString());
    m_projectFolder->setText(QCoreApplication::translate("ProjectNewDialog", "Ausw\303\244hlen...", nullptr));

    m_pAccept->setText(QCoreApplication::translate("OverlayDialog", "Create", nullptr));

    m_pLabel->setText(QCoreApplication::translate("OverlayDialog", "Enclosure Project Settings", nullptr));
} // retranslateUi
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void ProjectNewDialog::createNewProject() {
    QDir dir;
    QString filepath;
    QString projectname = m_projectName->text();
    QString path = m_projectPath->text() + QString("/") + projectname;

    QDateTime now = QDateTime::currentDateTime();
    QString formattedDateTime = now.toString("yyyy-MM-dd HH:mm:ss");

    filepath = path + QString("/") + projectname + QString(".sivalprj");
    SiVAL::Core::ProjectDocument *doc = SiVAL::Core::ProjectDocument::create(filepath);
    doc->setVersion(1.0);
    doc->setProjectId(QUuid::createUuid().toString(QUuid::WithoutBraces));
    doc->setProjectName(projectname);
    doc->setCreateDate(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    doc->setAuthor(m_authorEdit->text());
    doc->setDescription(QString());
    doc->setGrossVolume(m_volumeEdit->value(), QString("l"));
    doc->save();
    delete doc;
    emit newProject(filepath);
    close();
}

void ProjectNewDialog::openFolder() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                        | QFileDialog::DontResolveSymlinks);

    m_projectPath->setText(dir);
    textChanged(m_projectName->text());
}
void ProjectNewDialog::textChanged(const QString &text) {
    QDir dir;
    QString path = m_projectPath->text() + QString("/") + text;

    if(dir.exists(path)) {
        m_warningLabel->show();
        m_infoLabel->show();
        m_pAccept->setDisabled(true);
    } else {
        m_warningLabel->hide();
        m_infoLabel->hide();
        m_pAccept->setDisabled(false);
    }
}
//// end protected slots

//// begin private slots
//// end private slots
}
