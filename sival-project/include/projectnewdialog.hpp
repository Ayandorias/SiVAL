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
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QPushButton>
#include "sivalgui/headerlabel.hpp"
#include "sivalgui/label.hpp"
#include <sivalgui/overlaydialog.hpp>
#include <sivalgui/spinwidget.hpp>
//// end system includes

//// begin project specific includes

//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL::PM {
/**
 * class ProjectNewDialog
 *
 * @brief
 *
 */
class ProjectNewDialog : public SiVAL::Gui::OverlayDialog
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectNewDialog(const QString &title, const QString &projectname, int volume, QWidget *parent = nullptr);
    /// Destructor
    virtual ~ProjectNewDialog();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void retranslateUi(QWidget *ProjectNewDialog);
    void setupUi(QWidget *ProjectNewDialog);
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QVBoxLayout *verticalLayout;
    // SiVAL::Gui::HeaderLabel *m_header;
    SiVAL::Gui::Label *m_headerInfo;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    SiVAL::Gui::Label *m_volume;
    QLineEdit *m_projectName;
    QLineEdit *m_authorEdit;
    SiVAL::Gui::Label *m_infoLabel;
    SiVAL::Gui::Label *m_selection;
    SiVAL::Gui::Label *m_project;
    SiVAL::Gui::Label *m_author;
    SiVAL::Gui::SpinWidget *m_volumeEdit;
    QLabel *m_warningLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *m_projectPath;
    QPushButton *m_projectFolder;
    QSpacerItem *verticalSpacer_2;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void createNewProject();
    void openFolder();
    void textChanged(const QString &text);
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void newProject(const QString &filePath);
    //// end signals
};
}
