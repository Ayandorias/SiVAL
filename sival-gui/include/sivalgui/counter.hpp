#ifndef HEADER_GUARD_Nebenwelten_Counter_HPP
#define HEADER_GUARD_Nebenwelten_Counter_HPP

/*
 * Nebenwelten$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QString>
#include <QSvgRenderer>
#include <QWidget>
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
     * class Counter
     *
     * @brief
     *
     */
    class SIVAL_GUI_EXPORT Counter : public QWidget
    {
        Q_OBJECT
        //// begin public member methods
    public:
        /// Constructor
        explicit Counter(QWidget *parent = nullptr);
        /// Destructor
        virtual ~Counter();

        int maximum();
        int minimum();
        void setMaximum(int value);
        void setMinimum(int value);
        void setValue(int value);
        int value();
        //// end public member methods

        //// begin public member methods (internal use only)
    public:
        //// end public member methods (internal use only)

        //// begin protected member methods
    protected:
        void leaveEvent(QEvent * event) override;
        void mousePressEvent(QMouseEvent * event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
        void paintEvent(QPaintEvent *event) override;
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
        bool button;
        int m_iPaddingRight;
        int m_iPaddingLeft;
        int m_iIconWidth;
        int m_iIconHeight;
        int m_iValue;
        int m_iMaximumValue;
        int m_iMinimumValue;
        QSvgRenderer *m_pRightIcon;
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
        void incremented();
        void valueChanged(int value);
        //// end signals
    };
}
#endif // HEADER_GUARD_Nebenwelten$_SpinBox$_HPP
