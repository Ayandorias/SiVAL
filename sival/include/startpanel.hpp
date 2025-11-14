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
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
//// end system includes

//// begin project specific includes
#include <startitem.hpp>
#include <sivalgui/label.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL {
/**
 * class StartPanel
 *
 * @brief
 *
 */
class StartPanel : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit StartPanel(QWidget *parent = nullptr);
    /// Destructor
    virtual ~StartPanel();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    void retranslateUI();
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;

    StartItem *m_newBlank;
    Gui::Label *m_newLabel;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
