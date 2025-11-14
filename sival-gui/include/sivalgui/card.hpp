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
* @brief
*
*/
class SIVAL_GUI_EXPORT Card : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor infoColor READ getInfoColor WRITE setInfoColor)

    //// begin public member methods
public:
    /// Constructor
    explicit Card(const QString &title, const QString &info, QWidget *parent);
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
    QString infoText;
    QString m_sTitle;
    bool m_bChecvron;
    bool m_bHovered;
    bool m_bPressed;

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
    void clicked();
    //// end signals
};
}
}
