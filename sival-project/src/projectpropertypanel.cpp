#include "projectpropertypanel.hpp"
#include "ui_projectpropertypanel.h"


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
#include <QDateTime>
#include <QDesktopServices>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QVector>
//// end system includes

//// begin project specific includes
#include <sivalcore/documents/speakerdocument.hpp>
#include "projectpropertypanel.hpp"
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
ProjectPropertyPanel::ProjectPropertyPanel(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::ProjectPropertyPanel) {
    m_projectDocument = nullptr;
    ui->setupUi(this);

    ui->m_openButton->setIcon(QIcon(":/sival/" + sSettings()->theme() + "/open.svg"));
    ui->m_openButton->setIconSize(QSize(24, 24));
    connect(ui->m_openButton, &QPushButton::clicked, this, &ProjectPropertyPanel::openDocumentLocation);
}

/**************************************************************************************************/
/**
 *
 */
ProjectPropertyPanel::~ProjectPropertyPanel() {
    delete ui;
}

void ProjectPropertyPanel::update(SiVAL::Core::ProjectDocument *doc) {
    while (QLayoutItem* item = ui->m_SpeakerSpecLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    m_speakerList.clear();

    m_projectDocument = doc;

    ui->m_fileName->setText(m_projectDocument->filename());
    QFileInfo info(doc->filename());
    QString filesize;
    double size = info.size();

    filesize = QString("%1 Byte").arg(size);
    if(size > 1024) {
        size /= 1024;
        filesize = QString("%1 kB").arg(size);
    } else if(size > 1024) {
        size /= 1024;
        filesize = QString("%1 MB").arg(size);
    }
    ui->m_sizeValue->setText(filesize);

    QDateTime birth = info.birthTime(QTimeZone::UTC);
    ui->m_birthDate->setText(birth.toString("dd.MM.yyyy hh:mm.ss"));
    ui->m_lastModified->setText(info.lastModified(QTimeZone::UTC).toString("dd.MM.yyyy hh:mm.ss"));
    ui->m_lastRead->setText(info.lastRead(QTimeZone::UTC).toString("dd.MM.yyyy hh:mm.ss"));

    ui->m_author->setText(doc->author());

    QVector<SiVAL::Core::SpeakerDocument*> list = doc->speakerList();
    for(int i = 0; i < list.count(); ++i) {
        SiVAL::Gui::SpeakerSpecification *spec = new SiVAL::Gui::SpeakerSpecification(list.at(i), this);
        ui->m_SpeakerSpecLayout->addWidget(spec);
        m_speakerList.append(spec);
    }

    QSpacerItem *verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    ui->m_SpeakerSpecLayout->addItem(verticalSpacer_5);
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
void ProjectPropertyPanel::openDocumentLocation() {
    QFileInfo fileInfo(m_projectDocument->filename());
    QString folderPath = fileInfo.absolutePath();
    QDesktopServices::openUrl(QUrl::fromLocalFile(folderPath));
}
//// end protected slots

//// begin private slots
//// end private slots
}
