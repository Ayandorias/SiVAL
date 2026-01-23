/*
 * SiVAL GUI
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
//// end system includes

//// begin project specific includes
#include "sivalgui/spinwidget.hpp"
#include <limits>
#include <iostream>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin static definitions
//// end static definitions

//// begin static functions
//// end static functions

namespace SiVAL::Gui {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
SpinWidget::SpinWidget(QWidget *parent)
    :QWidget(parent) {

    int m_maximum = std::numeric_limits<int>::max();
    int m_minimum = std::numeric_limits<int>::min();

    setMinimumSize(QSize(0, 32));
    setMaximumSize(QSize(16777215, 32));
    horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName("horizontalLayout");
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    m_lineEdit = new QLineEdit(this);
    m_lineEdit->setObjectName("lineEdit");
    m_lineEdit->setMinimumHeight(32);
    m_lineEdit->setMaximumHeight(32);
    m_validator = new QIntValidator(0, 1000, this);
    m_lineEdit->setValidator(m_validator);

    horizontalLayout->addWidget(m_lineEdit);

    m_minus = new QToolButton(this);
    m_minus->setMinimumSize(32, 32);
    m_minus->setMaximumSize(32, 32);
    m_minus->setObjectName("spinMinus");
    connect(m_minus, &QToolButton::clicked, this, &SiVAL::Gui::SpinWidget::decrement);

    horizontalLayout->addWidget(m_minus);

    m_plus = new QToolButton(this);
    m_plus->setMinimumSize(32, 32);
    m_plus->setMaximumSize(32, 32);
    m_plus->setObjectName("spinPlus");
    connect(m_plus, &QToolButton::clicked, this, &SiVAL::Gui::SpinWidget::increment);
    horizontalLayout->addWidget(m_plus);
}

/**************************************************************************************************/
/**
 *
 */
SpinWidget::~SpinWidget() {
}

void SpinWidget::setMaximum(int max) {
    m_validator->setTop(max);
}
void SpinWidget::setMinimum(int min) {
    m_validator->setBottom(min);
}

double SpinWidget::value() {
    return m_lineEdit->text().toDouble();
}

void SpinWidget::setValue(double value) {
    m_lineEdit->setText(QString::number(value));
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
void SpinWidget::decrement() {
    int val = 0;
    const QValidator *valid = m_lineEdit->validator();
    const QIntValidator *intVal = qobject_cast<const QIntValidator*>(valid);

    if (intVal) {
        // 3. Nun sind die Werte lesbar
        int min = intVal->bottom();
        int val = m_lineEdit->text().toInt();
        if(--val < min) {
            val = min;
        }
        m_lineEdit->setText(QString::number(val));
    }

    emit valueChanged(val);
}

void SpinWidget::increment() {
    int val = 0;
    const QValidator *valid = m_lineEdit->validator();
    const QIntValidator *intVal = qobject_cast<const QIntValidator*>(valid);

    if (intVal) {
        // 3. Nun sind die Werte lesbar
        int max = intVal->top();
        int val = m_lineEdit->text().toInt();
        if(++val > max) {
            val = max;
        }
        m_lineEdit->setText(QString::number(val));
    }

    emit valueChanged(val);
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
}
