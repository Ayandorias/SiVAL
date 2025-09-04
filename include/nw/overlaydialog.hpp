#ifndef HEADER_GUARD_AetheriumArchivar_aaOverlayDialog_HPP
#define HEADER_GUARD_AetheriumArchivar_aaOverlayDialog_HPP

/*^
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QVariant>
#include <QIcon>
#include <QApplication>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>
//// end includes

//// begin specific includes
//// end specific includes

//// begin using namespaces
// namespace Ui
// {
// class OverlayDialog;
// }
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace NW {
/**
    * class OverlayDialog
    *
    * @brief
    *
    */
class OverlayDialog : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit OverlayDialog(QWidget *parent = nullptr);
    /// Destructor
    virtual ~OverlayDialog();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    void setupUi(QWidget *OverlayDialog);
    void retranslateUi(QWidget *OverlayDialog);
    //// end private member methods

    //// begin public member
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_8;
    QWidget *m_pDialog;
    QVBoxLayout *verticalLayout;
    QWidget *m_pTitleBar;
    QHBoxLayout *m_pTitleBarLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *m_pLabel;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *m_pClose;
    QWidget *m_pCenterWidget;
    QHBoxLayout *m_pButtonBar;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *m_pPrevButton;
    QPushButton *m_pNextButton;
    QPushButton *m_pAccept;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    //// end private member

    //// begin public slots
public slots:
    virtual void cancel();
    //// end public slots

    //// begin protected slots
protected slots:
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    void accepted();
    //// end signals
};
} // namespace NW
#endif // HEADER_GUARD_AetheriumArchivar$_aaOverlayDialog$_HPP



