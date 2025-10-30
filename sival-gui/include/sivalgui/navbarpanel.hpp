#ifndef HEADER_GUARD_AetheriumArchivar_NavBarPanel_HPP
#define HEADER_GUARD_AetheriumArchivar_NavBarPanel_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QButtonGroup>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>
//// end system includes

//// begin project specific includes
#include <sivalgui/gui_global.hpp>
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
 * class NavBarPanel
 *
 * @brief
 *
 */
class SIVAL_GUI_EXPORT NavBarPanel : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit NavBarPanel(QWidget *parent = nullptr);
    /// Destructor
    virtual ~NavBarPanel();
    ///
    void addPanel(const QString &icon, const QString &icon_hover, QWidget *panel);
    void appendPanel(const QString &icon, const QString &icon_hover, QWidget *panel);
    void select(int id);
    void toggle(bool checked);
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
    void insertPanel(const QString &icon, const QString &icon_hover, int btn_id, int position, QWidget *panel);
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QButtonGroup *m_pGroup;
    QStackedWidget *m_pPanelStack;
    QVBoxLayout *m_pButtonLayout;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void selection(QAbstractButton *btn);
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void mainMenu();
    void changeCenterView(int id);
    //// end signals
};
}
#endif // HEADER_GUARD_AetheriumArchivar_NavBarPanel_HPP
