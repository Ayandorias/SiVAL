/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
#include <iostream>
//// end includes

//// begin specific includes
#include "nw/overlaydialog.hpp"
#include "ui_overlaydialog.h"
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
NW::OverlayDialog::OverlayDialog(QWidget *parent)
:QWidget(parent), m_pUi(new Ui::OverlayDialog()) {
    m_pUi->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setGeometry(0, 0, parent->width(), parent->height());

    connect(m_pUi->m_pClose, &QToolButton::clicked, this, &NW::OverlayDialog::cancel);

}

/**************************************************************************************************/
/**
 *
 */
NW::OverlayDialog::~OverlayDialog() {
    delete m_pUi;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
bool NW::OverlayDialog::eventFilter(QObject *obj, QEvent *event) {
    std::cout << "Größenanpassung" <<std::endl;
    // Prüfen, ob das Event vom Parent-Widget kommt
    if (obj == parentWidget()) {
        // --- 1. Auf Größen- und Positionsänderungen reagieren ---
        if (event->type() == QEvent::Resize) {
            if (parentWidget()) { // Sicherheitsüberprüfung
                // Setze die Geometrie des Overlays exakt auf die Geometrie des Parents
                setGeometry(parentWidget()->rect());
                // Die Zentrierung des m_contentWidget innerhalb des Overlays
                // wird automatisch durch das QVBoxLayout 'overlayLayout' gehandhabt,
                // da es an 'this' (dem OverlayDialog) gesetzt ist und 'this' sich anpasst.
            }
        }
    }
    // Für alle anderen Objekte oder Event-Typen, die nicht von uns gefiltert werden,
    // das Event an die Basisklasse weitergeben.
    return QWidget::eventFilter(obj, event);
}
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
void NW::OverlayDialog::cancel() {
    close();
}
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
