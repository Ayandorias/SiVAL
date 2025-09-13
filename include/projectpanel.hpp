#ifndef HEADER_GUARD_SiVAL_ProjectPanel_HPP
#define HEADER_GUARD_SiVAL_ProjectPanel_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QJsonDocument>
#include <QJsonObject>
#include <QWidget>
//// end includes

//// begin specific includes
#include "projectdocument.hpp"
//// end specific includes

//// begin using namespaces
namespace Ui {
class ProjektPanel;
}
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class ProjectPanel
 *
 * @brief
 *
 */
class ProjectPanel : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectPanel(QWidget *parent = nullptr);
    /// Destructor
    virtual ~ProjectPanel();
    ///
    void addEnclosure(SpeakerDocument *doc);
    ///
    void open(const QString &projectfile);
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
    void checkButtons();
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    ProjectDocument *m_pProjectDocument;
    Ui::ProjektPanel *ui;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    ///
    void save();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void newEnclosure();
    void newProject();
    void openProject();
    void projectChanged(ProjectDocument *doc);
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_ProjectPanel_HPP
