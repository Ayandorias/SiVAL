#pragma once

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QVBoxLayout>
#include <QWidget>
//// end system includes

//// begin project specific includes
#include <sivalgui/headerlabel.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL::Gui {
/**
 * class FileSystemPanel
 *
 * @brief
 *
 */
class FileSystemPanel : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit FileSystemPanel(QWidget *parent = nullptr);
    /// Destructor
    virtual ~FileSystemPanel();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    void addDriveButton(const QString &label, const QString &icon, const QString &path);
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    HeaderLabel *m_favorite;
    HeaderLabel *m_storage;
    HeaderLabel *m_user;
    QVBoxLayout *layout;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void handleButtonClick();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void driveSelected(const QString &path);
    //// end signals
};
}