/*
 * SiVAL Gui
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
#include "sivalgui/view.hpp"
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

namespace SiVAL {
namespace Gui {
//// begin public member methods
View::View()
    :QObject() {
    m_mainWidget = nullptr;
    m_menuBar = nullptr;
    m_navBarButton = nullptr;
    m_navBarPanel = nullptr;
    m_centerPanel = nullptr;
}

View::~View() {
}

QWidget* View::mainWidget() {
    return m_mainWidget;
}

QWidget* View::menuBar() {
    return m_menuBar;
}

NavigationButton* View::navigationButton(QWidget *parent) {
    QString name = objectName() + QString("Button");
    if(m_navBarButton == nullptr) {
        m_navBarButton = new NavigationButton(parent);
        m_navBarButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        m_navBarButton->setObjectName(name);
        m_navBarButton->setMinimumSize(80, 60);
        m_navBarButton->setMaximumSize(80, 60);
        m_navBarButton->setIconSize(QSize(32, 32));
        m_navBarButton->setText(m_name);
    }
    return m_navBarButton;
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
//// end protected slots

//// begin private slots
//// end private slots
}
}
