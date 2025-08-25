#ifndef HEADER_GUARD_AetheriumArchivar_Card_HPP
#define HEADER_GUARD_AetheriumArchivar_Card_HPP

/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QPaintEvent>
#include <QSvgRenderer>
#include <QWidget>
//// end includes

//// begin specific includes
//// end specific includes

//// begin using namespaces
namespace Ui {
class Card;
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
   * class Card
   *
   * @brief
   *
   */
  class Card : public QWidget
  {
    Q_OBJECT
    //// begin public member methods
  public:
    /// Constructor
    explicit Card(QWidget *parent);
    explicit Card(const QString &title, const QString &info, QWidget *parent);
    /// Destructor
    virtual ~Card();
    void setChecvron(bool enable);
    void setIcon(const QString &icon);
    void setInfo(const QString &info);
    void setTitle(const QString &title);
    //// end public member methods

    //// begin public member methods (internal use only)
  public:
    //// end public member methods (internal use only)

    //// begin protected member methods
  protected:
    void enterEvent(QEnterEvent * event) override;
    void leaveEvent(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    //// end protected member methods

    //// begin protected member methods (internal use only)
  protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
  private:
    void init();
    //// end private member methods

    //// begin public member
  public:
    //// end public member

    //// begin protected member
  protected:
    QString m_sInfoText;
    QString m_sTitle;
    bool m_bChecvron;
    //// end protected member

    //// begin private member
  private:
    Ui::Card *ui;
    QSvgRenderer *m_pIconRenderer;
    QSvgRenderer *m_pChevronRenderer;
    bool m_bPressed;
    bool m_bHovered;
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
    void clicked();
    //// end signals
  };
}
#endif // HEADER_GUARD_AetheriumArchivar$_Card$_HPP
