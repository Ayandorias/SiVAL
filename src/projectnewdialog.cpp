/*
 * SiVAL
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDateTime>
#include <QDir>
#include <QDoubleValidator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include <QUuid>

#include <iostream>
//// end includes

//// begin specific includes
#include "projectnewdialog.hpp"
#include "ui_projectnewdialog.h"
// #include "ui_overlaydialog.h"
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
ProjectNewDialog::ProjectNewDialog(QWidget *parent)
    :NW::OverlayDialog(parent)
    , ui(new Ui::ProjectNewDialog)
    {
        ui->setupUi(m_pCenterWidget);

        m_pLabel->setText(tr("SiVAL Enclosure Project"));

        setAttribute(Qt::WA_DeleteOnClose);
        setGeometry(0, 0, parent->width(), parent->height());

        ui->m_pInfoLabel->hide();
        ui->m_pWarningLabel->hide();
        m_pAccept->setText(tr("Erstellen"));

        m_pPrevButton->hide();
        m_pNextButton->hide();

        m_pAccept->setDisabled(true);

        QStringList m_List = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
        for(int i = 0; i < m_List.size(); i++) {
            std::cout << m_List.at(i).toStdString() << std::endl;
        }
        ui->m_pProjectPath->setText(m_List.at(0));


        QDoubleValidator *validator = new QDoubleValidator(0, 99999, 2, ui->m_pVolume);
        ui->m_pVolume->setValidator(validator);

        connect(ui->m_pProjectName, &QLineEdit::textChanged, this, &ProjectNewDialog::textChanged);
        connect(m_pAccept, &QPushButton::clicked, this, &ProjectNewDialog::createNewProject);
}

/**************************************************************************************************/
/**
 *
 */
ProjectNewDialog::~ProjectNewDialog() {
    delete ui;
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
/**
 * @brief ProjectNewDialog::createNewProject
 */
void ProjectNewDialog::createNewProject() {
    QDir dir;
    QString filepath;
    QString projectname = ui->m_pProjectName->text();
    QString path = ui->m_pProjectPath->text() + QString("/") + projectname;

    if(dir.mkpath(path)) {
        QJsonObject obj;

        QDateTime now = QDateTime::currentDateTime();
        QString formattedDateTime = now.toString("yyyy-MM-dd HH:mm:ss");

        obj["version"] = 1.0,
        obj["project_id"] = QUuid::createUuid().toString(QUuid::WithoutBraces);
        obj["project_name"] = projectname;
        obj["created_at"] = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        obj["author"] = ui->m_pAuthor->text();
        obj["description"] = QString();
        obj["total_volume_m3"] = ui->m_pVolume->text().toDouble();

        filepath = path + QString("/") + projectname + QString(".sivalpr");
        QFile file(filepath);
        QJsonDocument newDoc(obj);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            qCritical() << "Fehler: Datei konnte nicht zum Schreiben geöffnet werden.";
            return;
        }

        file.write(newDoc.toJson(QJsonDocument::Indented));
        file.close();

    }
    emit newProject(filepath);
    close();
}
/**
 * @brief ProjectNewDialog::textChanged
 * @param text
 */
void ProjectNewDialog::textChanged(const QString &text) {
    QDir dir;
    QString path = ui->m_pProjectPath->text() + QString("/") + text;
    if(dir.exists(path)) {
        ui->m_pWarningLabel->show();
        ui->m_pInfoLabel->show();
        m_pAccept->setDisabled(true);
    } else {
        ui->m_pWarningLabel->hide();
        ui->m_pInfoLabel->hide();
        m_pAccept->setDisabled(false);
    }
}
//// end protected slots

//// begin private slots
//// end private slots
