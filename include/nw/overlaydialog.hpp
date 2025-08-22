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
#include <QWidget>
//// end includes

//// begin specific includes
//// end specific includes

//// begin using namespaces
namespace Ui
{
class OverlayDialog;
}
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
    //// end private member methods

    //// begin public member
public:
    Ui::OverlayDialog *m_pUi;
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



