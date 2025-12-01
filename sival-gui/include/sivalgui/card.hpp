#pragma once

/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QPaintEvent>
#include <QSvgRenderer>
#include <QWidget>
//// end system includes

//// begin project specific includes
#include <sivalgui/global.hpp>
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
namespace Gui {
/**
* class Card
*
* @brief Card ist die Basisklasse der Anzeigeelement in der Anwendung.
*
*/
class SIVAL_GUI_EXPORT Card : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor infoColor READ getInfoColor WRITE setInfoColor)

    //// begin public member methods
public:
    /**
     * @brief Card Der Konstruktor.
     *
     * Er erstellt ein Element mit folgenden Eigenschaften.
     * @param title Den Title der angezeigt werden soll
     * @param parent Das Elternfenster in dem das Element angezeigt werden kann.
     */
    explicit Card(QWidget *parent = nullptr);
    /// Destructor
    virtual ~Card();
    QString info();
    void setChevron(bool enable);
    void setIcon(const QString &icon);
    void setInfo(const QString &info);
    void setTitle(const QString &title);


    // Getter/Setter für die Eigenschaft
    void setInfoColor(const QColor &color);
    QColor getInfoColor() const;
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void enterEvent(QEnterEvent * event) override;
    void leaveEvent(QEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
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
    QString m_infoText;
    QString m_sTitle;
    bool m_bChecvron;
    bool m_bHovered;
    bool m_bPressed;
    int m_margin = 0;

    QColor m_infoColor = QColor("black"); // Standardwert!
    QSvgRenderer *m_pIconRenderer;
    QSvgRenderer *m_pChevronRenderer;
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
    void infoText(const QString &text);
    void clicked();
    void doubleClicked(SiVAL::Gui::Card *card);
    //// end signals
};
}
}
