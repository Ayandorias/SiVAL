#ifndef HEADER_GUARD_Nebenwelten_Assistant_HPP
#define HEADER_GUARD_Nebenwelten_Assistant_HPP

/*
 * Nebenwelten$
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
#include "nw/framebarbutton.hpp"
#include "nw/overlaydialog.hpp"
//// end specific includes

//// begin using namespaces
namespace Ui
{
  class Assistant;
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
   * class Assistant
   *
   * @brief
   *
   */
  class Assistant : public NW::OverlayDialog
  {
    Q_OBJECT
    //// begin public member methods
  public:
    /// Constructor
    explicit Assistant(QWidget *parent = nullptr);
    /// Destructor
    virtual ~Assistant();
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
    Ui::Assistant *m_pCenterUI;
    //// end protected member

    //// begin private member
  private:
    NW::FrameBarButton *m_pNext;
    NW::FrameBarButton *m_pPrevious;
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
#endif // HEADER_GUARD_Nebenwelten$_Assistant$_HPP
