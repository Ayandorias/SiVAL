#ifndef HEADER_GUARD_SiVAL_HomeWidget_HPP
#define HEADER_GUARD_SiVAL_HomeWidget_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QJsonObject>
#include <QWidget>
//// end system includes

//// begin project specific includes

//// end project specific includes

//// begin using namespaces
namespace Ui {
class HomeWidget;
}
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

/**
 * class HomeWidget
 *
 * @brief
 *
 */
class HomeWidget : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit HomeWidget(QWidget *parent = nullptr);
    /// Destructor
    virtual ~HomeWidget();
    void createRecent(QJsonObject prj);
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
    Ui::HomeWidget *ui;
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
    void openProject(const QString &filepath);
    //// end signals
};
#endif // HEADER_GUARD_SiVAL_HomeWidget_HPP
