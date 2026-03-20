#ifndef FILELISTVIEW_H
#define FILELISTVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QString>

namespace SiVAL::Gui {

class FileListView : public QWidget {
    Q_OBJECT

public:
    explicit FileListView(QWidget *parent = nullptr);

    // Die Funktion zum Laden und Filtern
    void loadDirectory(const QString &path, const QString &extension = "sivalprj");

signals:
    // Signal bei Auswahl der gesuchten Datei
    void fileSelected(const QString &filePath);

private:
    void clearLayout();
    void addEntryButton(const QString &label, const QString &icon, const QString &path, bool isDir);

    QVBoxLayout *layout;
    QString currentExtension;
};

}
#endif