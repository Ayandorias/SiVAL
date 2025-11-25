#pragma once

/*
 * SiVAL GUI
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QHBoxLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QWidget>
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

namespace SiVAL::Gui {
/**
 * class SpinWidget
 *
 * @brief
 *
 */
class SpinWidget : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SpinWidget(QWidget *parent = nullptr);
    /// Destructor
    virtual ~SpinWidget();
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
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QToolButton *m_minus;
    QToolButton *m_plus;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void decrement();
    void increment();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void valueChanged(int val);
    //// end signals
};
}
