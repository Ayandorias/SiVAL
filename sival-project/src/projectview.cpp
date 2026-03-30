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
#include <QStyle>
#include <iostream>
//// end system includes

//// begin project specific includes
#include "projectview.hpp"
#include <sival.hpp>
#include <sivalgui/cardlist.hpp>
#include <sivalgui/enclosurecard.hpp>
#include <sivalgui/line.hpp>
#include <sivalgui/section.hpp>
#include <sivalgui/sectioncard.hpp>
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
ProjectView::ProjectView()
    :Gui::View() {
}

/**************************************************************************************************/
/**
 *
 */
ProjectView::~ProjectView() {
}

Gui::NavigationPanel* ProjectView::navigationPanel() {
    if(m_navBarPanel == nullptr) {

        Gui::CardList *l = new Gui::CardList();

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        m_save = new SiVAL::Gui::ToolButton(l);
        m_save->setObjectName("projectSave");
        m_save->setMinimumSize(QSize(36, 36));
        m_save->setMaximumSize(QSize(36, 36));
        connect(m_save, &SiVAL::Gui::ToolButton::clicked, this, &ProjectView::save);

        horizontalLayout->addWidget(m_save);

        // m_close = new SiVAL::Gui::ToolButton(l);
        // m_close->setObjectName("projectClose");
        // m_close->setMinimumSize(QSize(36, 36));
        // m_close->setMaximumSize(QSize(36, 36));

        // horizontalLayout->addWidget(m_close);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);
        l->addLayout(horizontalLayout);

        SiVAL::Gui::Line *line = new SiVAL::Gui::Line(l);
        l->addCard(line);


        m_enclosure = new SiVAL::Gui::Card(nullptr);
        m_enclosure->setIcon(":/sival/" + sSettings()->theme() + "/enclosure-fill.svg");
        m_enclosure->setMinimumHeight(40);
        m_enclosure->setMaximumHeight(40);
        connect(m_enclosure, &SiVAL::Gui::Card::clicked, this, &ProjectView::enclosure);
        l->addCard(m_enclosure);

        m_properties = new SiVAL::Gui::Card(nullptr);
        m_properties->setIcon(":/sival/" + sSettings()->theme() + "/project_properties.svg");
        m_properties->setMinimumHeight(40);
        m_properties->setMaximumHeight(40);
        connect(m_properties, &SiVAL::Gui::Card::clicked, this, &ProjectView::properties);
        l->addCard(m_properties);

        m_navBarPanel = l;

        retranslate();
    }
    return m_navBarPanel;
}
QWidget* ProjectView::centerPanel() {
    if(m_centerPanel == nullptr) {
        ProjectPanel *panel = new ProjectPanel();
        m_centerPanel = panel;
    }
    return m_centerPanel;
}
void ProjectView::setProjectDocument(SiVAL::Core::ProjectDocument *doc) {
    m_projectDoc = doc;
    connect(m_projectDoc, &SiVAL::Core::ProjectDocument::changed, this, &ProjectView::projectChanged);
    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->setCurrentIndex(static_cast<int>(SiVAL::ProjectPanel::Enclosure));
    p->update(doc);
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void ProjectView::retranslate() {
    if(m_navBarPanel != nullptr) {
        m_enclosure->setTitle(tr("Speaker"));
        m_properties->setTitle(tr("Properties"));
        // m_information->setTitle(tr("Information"));
    }
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void ProjectView::enclosure() {
    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->setCurrentIndex(static_cast<int>(SiVAL::ProjectPanel::Enclosure));
}
void ProjectView::information() {
    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->setCurrentIndex(static_cast<int>(SiVAL::ProjectPanel::Enclosure));

}
void ProjectView::projectChanged() {
    m_save->setObjectName("projectSaveChanges");
    m_save->style()->unpolish(m_save);
    m_save->style()->polish(m_save);
    m_save->update();
}
void ProjectView::properties() {
    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->setCurrentIndex(static_cast<int>(SiVAL::ProjectPanel::Properties));
}
void ProjectView::save() {
    std::cout << "Projekt wird gespeichert" << std::endl;
    m_projectDoc->save();

    ProjectPanel *p = qobject_cast<SiVAL::PM::ProjectPanel*>(m_centerPanel);
    p->update(m_projectDoc);
}
//// end protected slots

//// begin private slots
//// end private slots
}


















































// /********************************************************************************
// ** Form generated from reading UI file 'designertkbqqe.ui'
// **
// ** Created by: Qt User Interface Compiler version 6.10.2
// **
// ** WARNING! All changes made in this file will be lost when recompiling UI file!
// ********************************************************************************/

// #ifndef DESIGNERTKBQQE_H
// #define DESIGNERTKBQQE_H

// #include <QtCore/QVariant>
// #include <QtWidgets/QApplication>
// #include <QtWidgets/QHBoxLayout>
// #include <QtWidgets/QSpacerItem>
// #include <QtWidgets/QToolButton>
// #include <QtWidgets/QWidget>

// QT_BEGIN_NAMESPACE

// class Ui_Form
// {
// public:
//     QHBoxLayout *horizontalLayout;
//     QToolButton *m_save;
//     QToolButton *m_close;
//     QSpacerItem *horizontalSpacer;

//     void setupUi(QWidget *Form)
//     {
//         if (Form->objectName().isEmpty())
//             Form->setObjectName("Form");
//         Form->resize(400, 300);
//         horizontalLayout = new QHBoxLayout(Form);
//         horizontalLayout->setSpacing(0);
//         horizontalLayout->setObjectName("horizontalLayout");
//         horizontalLayout->setContentsMargins(0, 0, 0, 0);
//         m_save = new QToolButton(Form);
//         m_save->setObjectName("m_save");
//         m_save->setMinimumSize(QSize(32, 32));
//         m_save->setMaximumSize(QSize(32, 32));

//         horizontalLayout->addWidget(m_save);

//         m_close = new QToolButton(Form);
//         m_close->setObjectName("m_close");
//         m_close->setMinimumSize(QSize(32, 32));
//         m_close->setMaximumSize(QSize(32, 32));

//         horizontalLayout->addWidget(m_close);

//         horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

//         horizontalLayout->addItem(horizontalSpacer);


//         retranslateUi(Form);

//         QMetaObject::connectSlotsByName(Form);
//     } // setupUi

//     void retranslateUi(QWidget *Form)
//     {
//         Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
//         m_save->setText(QCoreApplication::translate("Form", "...", nullptr));
//         m_close->setText(QCoreApplication::translate("Form", "...", nullptr));
//     } // retranslateUi

// };

// namespace Ui {
// class Form: public Ui_Form {};
// } // namespace Ui

// QT_END_NAMESPACE

// #endif // DESIGNERTKBQQE_H

