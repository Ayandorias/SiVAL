/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QDir>
#include <QPushButton>
#include <QStandardPaths>
#include <QStorageInfo>
//// end includes

//// begin system includes
#include <iostream>
//// end system includes

//// begin project specific includes
#include <sivalcore/sivalglobal.hpp>
#include <sivalgui/filesystemcard.hpp>
#include "sivalgui/filesystempanel.hpp"
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

namespace SiVAL::Gui {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
FileSystemPanel::FileSystemPanel(QWidget *parent)
    :QWidget(parent) {
    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    m_storage = new SiVAL::Gui::HeaderLabel(this);
    m_storage->setObjectName("storagePanel");
    m_storage->setMinimumSize(QSize(0, 40));
    m_storage->setMaximumSize(QSize(16777215, 40));
    m_storage->setText(tr("Storage Location"));
    layout->addWidget(m_storage);

    // 1. Physische Laufwerke filtern (kein System-Müll)
    const QSet<QString> ignoreFs = {"tmpfs", "devtmpfs", "squashfs", "debugfs", "proc", "sysfs"};

    for (const QStorageInfo &storage : QStorageInfo::mountedVolumes()) {
        if (!storage.isValid() || !storage.isReady() || storage.isReadOnly()) continue;

        QString path = storage.rootPath();
        QString fsType = storage.fileSystemType();

        // Filter für Schwachsinnige Pfade (EFI, Run, Tmp, etc.)
        if (path.startsWith("/run") || path.startsWith("/tmp") ||
            path.startsWith("/boot") || path.startsWith("/dev") ||
            path.startsWith("/sys") || path.startsWith("/proc")) {
            continue;
        }

        if (ignoreFs.contains(fsType)) continue;

        QString name = storage.displayName();
        if (path == "/") name = "System";

        addDriveButton(name, ":/sival/" + sSettings()->theme() + "/device-hdd.svg", path);
    }

    // Abstandshalter zwischen Laufwerken und Ordnern

    m_user = new SiVAL::Gui::HeaderLabel(this);
    m_user->setObjectName("userPanel");
    m_user->setMinimumSize(QSize(0, 40));
    m_user->setMaximumSize(QSize(16777215, 40));
    m_user->setText(tr("User Profile:"));
    layout->addWidget(m_user);

    // 2. Deine explizit gewünschten Standardverzeichnisse
    struct PathDef { QString label; QStandardPaths::StandardLocation loc; QString icon; };
    QList<PathDef> targets = {
        {tr("Home"),      QStandardPaths::HomeLocation, ":/sival/" + sSettings()->theme() + "/home.svg"},
        {tr("Documents"), QStandardPaths::DocumentsLocation, ":/sival/" + sSettings()->theme() + "/new.svg"},
        {tr("Downloads"), QStandardPaths::DownloadLocation, ":/sival/" + sSettings()->theme() + "/download.svg"},
        {tr("Music"),     QStandardPaths::MusicLocation, ":/sival/" + sSettings()->theme() + "/music.svg"},
        {tr("Pictures"),  QStandardPaths::PicturesLocation, ":/sival/" + sSettings()->theme() + "/buildings.svg"},
        {tr("Videos"),    QStandardPaths::MoviesLocation, ":/sival/" + sSettings()->theme() + "/camera.svg"}
    };

    for (const auto &t : targets) {
        QString path = QStandardPaths::writableLocation(t.loc);
        if (!path.isEmpty() && QDir(path).exists()) {
            addDriveButton(t.label, t.icon, path);
        }
    }

    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

    m_favorite = new SiVAL::Gui::HeaderLabel(this);
    m_favorite->setObjectName("favoritePanel");
    m_favorite->setMinimumSize(QSize(0, 40));
    m_favorite->setMaximumSize(QSize(16777215, 40));
    m_favorite->setText(tr("Last Projects"));
    layout->addWidget(m_favorite);

    QStringList list = sSettings()->lastProjects();
    for(int i = 0; i < list.size(); i++) {
        // if(QDir(list.at(i)).exists()) {
            addDriveButton(list.at(i), ":/sival/" + sSettings()->theme() + "/projects.svg", list.at(i));
        // }
    }

    layout->addItem(spacer);

    layout->addStretch();
}

/**************************************************************************************************/
/**
 *
 */
FileSystemPanel::~FileSystemPanel() {
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
void FileSystemPanel::addDriveButton(const QString &label, const QString &icon, const QString &path) {
    SiVAL::Gui::FileSystemCard *btn = new SiVAL::Gui::FileSystemCard(this);//QPushButton(label, this);
    btn->setTitle(label);
    // btn->setStyleSheet("background-color: #f00;");
    btn->setIcon(icon);
    btn->setMinimumHeight(40);
    btn->setMaximumHeight(40);
    // Der Pfad wird als "User Property" im Button gespeichert
    btn->setProperty("path", path);

    connect(btn, &SiVAL::Gui::Card::clicked, this, &FileSystemPanel::handleButtonClick);
    layout->addWidget(btn);
}
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void FileSystemPanel::handleButtonClick() {
    if (auto *btn = qobject_cast<SiVAL::Gui::Card*>(sender())) {
        emit driveSelected(btn->property("path").toString());
    }
}
//// end protected slots

//// begin private slots
//// end private slots
}