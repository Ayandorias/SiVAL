/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <QHBoxLayout>
#include <QPushButton>
//// end includes

//// begin specific includes
#include "nw/selectionbar.hpp"
//// end specific includes

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

//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
NW::SelectionBar::SelectionBar(QWidget *parent)
:QWidget(parent) {//}, m_ui(new Ui::SelectionBar) {
   // m_ui->setupUi(this);

    // QWidget {\n	background-color: #fff;\n}\n\nQPushButton {\n	background-color: #f00;\n}
    setMinimumHeight(64);
    setMaximumHeight(64);

    m_pLayout = new QHBoxLayout(this);

    QSpacerItem *horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    m_pLayout->addItem(horizontalSpacer);

    horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    m_pLayout->addItem(horizontalSpacer);

    setLayout(m_pLayout);


    btnGroup = new QButtonGroup(this);
    btnGroup->setExclusive(true);
    connect(btnGroup, &QButtonGroup::buttonClicked, this, &NW::SelectionBar::selection);
}

/**************************************************************************************************/
/**
 *
 */
NW::SelectionBar::~SelectionBar() {
}

void NW::SelectionBar::addButton(const QString &label, bool checked) {
    NW::SelectionButton *btn = new NW::SelectionButton(label, this);
    btn->setCheckable(true);
    btn->setMinimumHeight(48);
    btn->setMaximumHeight(48);
    btn->setChecked(checked);;
    int count = m_pLayout->count();
    m_pLayout->insertWidget(count - 1, btn);
    btnGroup->addButton(btn);
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
void NW::SelectionBar::selection(QAbstractButton *btn) {
    int index = 0;
    for(QAbstractButton *button : btnGroup->buttons()) {
        if(button->isChecked()) {
            emit changed(index);
            break;
        }
        index++;
    }
}
//// end protected slots

//// begin private slots
//// end private slots
