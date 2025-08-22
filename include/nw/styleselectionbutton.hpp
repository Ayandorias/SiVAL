#pragma once

#ifndef HEADER_GUARD_AetheriumArchivar_StyleSelectionButton_HPP
#define HEADER_GUARD_AetheriumArchivar_StyleSelectionButton_HPP

/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
//// end includes

//// begin specific includes
#include "nw/style.hpp"
//// end specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace NW {
    /**
     * class StyleSelectionButton
     *
     * @brief
     *
     */
    class StyleSelectionButton : public NW::Style
    {
        //// begin public member methods
    public:
        /// Constructor
        explicit StyleSelectionButton();
        /// Destructor
        virtual ~StyleSelectionButton();
        QString styleSheet() override;
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
#endif // HEADER_GUARD_AetheriumArchivar$_StyleSelectionButton$_HPP
