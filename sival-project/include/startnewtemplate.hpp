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
#include <QWidget>
#include <QHBoxLayout>
#include <QSpacerItem>
//// end system includes

//// begin project specific includes
#include <sival.hpp>
#include <sivalgui/startitem.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
namespace Ui {
class StartNewTemplate;
}
//// end extern declaration

namespace SiVAL {
/**
 * class StartNewTemplate
 *
 * @brief
 *
 */
class StartNewTemplate : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit StartNewTemplate(QWidget *parent = nullptr);
    /// Destructor
    virtual ~StartNewTemplate();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    void retranslateUi();
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
    // Ui::StartNewTemplate *ui;
    QHBoxLayout *m_layout;
    QSpacerItem *m_spacer;
    SiVAL::Gui::StartItem *m_bookShelf;
    SiVAL::Gui::StartItem *m_floorStand;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void newProject ();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void createNewProject(SiVAL::ProjectNew prj);
    //// end signal
};
}