#ifndef HEADER_GUARD_SiVAL_HomePanel_HPP
#define HEADER_GUARD_SiVAL_HomePanel_HPP

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
//// end system includes

//// begin project specific includes
//// end project specific includes

//// begin using namespaces
namespace Ui {
class HomePanel;
}
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class HomePanel
 *
 * @brief
 *
 */
class HomePanel : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit HomePanel(QWidget *parent = nullptr);
    /// Destructor
    virtual ~HomePanel();
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
    Ui::HomePanel *ui;
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
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
    void newProject();
    void openProject();
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_HomePanel_HPP
