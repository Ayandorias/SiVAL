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
//// begin system includes
#include <QWidget>
#include <sivalgui/framebarbutton.hpp>
#include <sivalgui/overlaydialog.hpp>
//// end system includes

//// begin project specific includes
#include <sivalgui/gui_global.hpp>
//// end project specific includes

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

namespace SiVAL {
  /**
   * class Assistant
   *
   * @brief
   *
   */
  class SIVAL_GUI_EXPORT Assistant : public SiVAL::OverlayDialog
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
      SiVAL::FrameBarButton *m_pNext;
      SiVAL::FrameBarButton *m_pPrevious;
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
#endif // HEADER_GUARD_Nebenwelten$_Assistant$_HPP
