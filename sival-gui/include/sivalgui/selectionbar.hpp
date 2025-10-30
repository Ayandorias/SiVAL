#ifndef HEADER_GUARD_AetheriumArchivar_SelectionBar_HPP
#define HEADER_GUARD_AetheriumArchivar_SelectionBar_HPP

/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QWidget>
#include <sivalgui/selectionbutton.hpp>
//// end system includes

//// begin project specific includes
#include <sivalgui/gui_global.hpp>
//// end project specific includes

//// begin using namespaces
namespace Ui {
class SelectionBar;
}
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL {
  /**
   * class SelectionBar
   *
   * @brief
   *
   */
  class SIVAL_GUI_EXPORT SelectionBar : public QWidget
  {
    Q_OBJECT
    //// begin public member methods
  public:
    /// Constructor
    explicit SelectionBar(QWidget *parent = nullptr);
    /// Destructor
    virtual ~SelectionBar();
    void addButton(const QString &label, bool checked = false);
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
    Ui::SelectionBar *m_ui;
    QHBoxLayout *m_pLayout;
    QButtonGroup *btnGroup;
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
    void changed(int index);
    //// end signals
  };
}
#endif // HEADER_GUARD_AetheriumArchivar$_SelectionBar$_HPP
