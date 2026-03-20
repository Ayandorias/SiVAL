#include "sivalgui/filelistview.hpp"
#include <QPushButton>
#include <QDir>
#include <QFileInfo>
#include <sivalgui/filesystemcard.hpp>
#include <iostream>

namespace SiVAL::Gui {

FileListView::FileListView(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(2);
    layout->setAlignment(Qt::AlignTop);
}

void FileListView::clearLayout() {
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
}

void FileListView::loadDirectory(const QString &path, const QString &extension) {
    clearLayout();

    std::cout << "Lade VErzeichnis" << std::endl;
    currentExtension = extension;
    QDir dir(path);

    if (!dir.exists()) return;

    // Ordner (ohne . und ..)
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    dir.setSorting(QDir::Name | QDir::IgnoreCase);
    for (const QFileInfo &info : dir.entryInfoList()) {
        addEntryButton(info.fileName(), ":/sival/" + sSettings()->theme() + "/folder.svg", info.absoluteFilePath(), true);
    }

    // Dateien (gefiltert)
    dir.setFilter(QDir::Files);
    dir.setNameFilters({"*." + extension});
    for (const QFileInfo &info : dir.entryInfoList()) {
        addEntryButton(info.fileName(), ":/sival/" + sSettings()->theme() + "/projects.svg", info.absoluteFilePath(), false);
    }
}

void FileListView::addEntryButton(const QString &label, const QString &icon, const QString &path, bool isDir) {
    auto *btn = new SiVAL::Gui::FileSystemCard(this);//QPushButton(label, this);
    btn->setMinimumHeight(40);
    btn->setMaximumHeight(40);
    btn->setTitle(label);
    btn->setIcon(icon);

    if (isDir) {
        connect(btn, &SiVAL::Gui::Card::doubleClicked, this, [this, path]() {
            this->loadDirectory(path, this->currentExtension);
        });
    } else {
        connect(btn, &SiVAL::Gui::Card::doubleClicked, this, [this, path]() {
            emit fileSelected(path);
        });
    }

    layout->addWidget(btn);
}
}