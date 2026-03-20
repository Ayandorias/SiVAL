/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDir>
#include <QFileInfo>
//// end includes

//// begin system includes
#include <iostream>
//// end system includes

//// begin project specific includes
#include "startopen.hpp"
#include "ui_startopen.h"
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
StartOpen::StartOpen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartOpen) {
    ui->setupUi(this);

    connect(ui->m_FileSystem, &SiVAL::Gui::FileSystemPanel::driveSelected, this, &StartOpen::driveSelected);
    connect(ui->m_FileListView, &SiVAL::Gui::FileListView::fileSelected, this, &StartOpen::openProject);
    ui->m_FileListView->loadDirectory("/home/heresy");
}

/**************************************************************************************************/
/**
 *
 */
StartOpen::~StartOpen() {
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
void StartOpen::driveSelected(const QString &filepath) {
    std::cout << " ich will hier was machen, aber ich weiß nicht ob das klappt" << std::endl;

    QFileInfo info(filepath);
    if(info.isDir()) {
        if(QDir(filepath).exists()) {
            ui->m_FileListView->loadDirectory(filepath);
        }
    } else if(info.isFile()) {
        emit openProject(filepath);
    }
}
//// end protected slots

//// begin private slots
//// end private slots
}
