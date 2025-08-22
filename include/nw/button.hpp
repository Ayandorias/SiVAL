#ifndef HEADER_GUARD_AtheriumArchivar_Button_HPP
#define HEADER_GUARD_AtheriumArchivar_Button_HPP

/*
 * AtheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QPushButton>
//// end includes

//// begin specific includes
#include "nw/style.hpp"
//// end specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace NW {
  /**
   * class Button
   *
   * @brief
   *
   */
  class Button : public QPushButton
  {
    Q_OBJECT
    //// begin public member methods
  public:
    /// Constructor
    explicit Button(const QString &label, NW::Style *style, QWidget *parent = nullptr);
    ///
    explicit Button(QWidget *parent = nullptr);
    /// Destructor
    virtual ~Button();
    int id();
    void setId(int id);
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
    NW::Style *m_pStyle;
    int m_Id;
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
    //// end signals
  };
}
#endif // HEADER_GUARD_AtheriumArchivar$_Button$_HPP
