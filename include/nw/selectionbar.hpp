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
//// begin includes
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QWidget>
//// end includes

//// begin specific includes
#include "nw/selectionbutton.hpp"
//// end specific includes

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

namespace NW {
  /**
   * class SelectionBar
   *
   * @brief
   *
   */
  class SelectionBar : public QWidget
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
