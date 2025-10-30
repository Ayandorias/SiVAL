#ifndef HEADER_GUARD_AetheriumArchivar_Style_HPP
#define HEADER_GUARD_AetheriumArchivar_Style_HPP

/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QPainter>
#include <QString>
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
   * class Style
   *
   * @brief
   *
   */
  class SIVAL_GUI_EXPORT Style
  {
    //// begin public member methods
  public:
    /// Constructor
    explicit Style();
    /// Destructor
    virtual ~Style();
    ///
    virtual QString styleSheet();
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
    QString m_sBgColor;
    QString m_sBgColorHover;
    QString m_sBgColorChecked;
    QString m_sBgColorCheckedHover;
    QString m_sBgColorPressed;

    QString m_sFgColor;
    QString m_sFgColorHover;
    QString m_sFgColorChecked;
    QString m_sFgColorCheckedHover;
    QString m_sFgColorPressed;

    QString m_sBorderColor;
    QString m_sBorderColorHover;
    QString m_sBorderColorChecked;
    QString m_sBorderColorCheckedHover;
    QString m_sBorderColorPressed;
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
#endif // HEADER_GUARD_AetheriumArchivar$_Style$_HPP
