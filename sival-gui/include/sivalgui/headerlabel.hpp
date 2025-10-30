#pragma once

#ifndef HEADER_GUARD_AetheriumArchivar_HeaderLabel_HPP
#define HEADER_GUARD_AetheriumArchivar_HeaderLabel_HPP

/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <sivalgui/label.hpp>
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
     * class HeaderLabel
     *
     * @brief
     *
     */
    class SIVAL_GUI_EXPORT HeaderLabel : public SiVAL::Label
    {
        Q_OBJECT
        //// begin public member methods
    public:
        /// Constructor
        explicit HeaderLabel(QWidget *parent = nullptr);
        /// Destructor
        virtual ~HeaderLabel();
        //// end public member methods

        //// begin public member methods (internal use only)
    public:
        //// end public member methods (internal use only)

        //// begin protected member methods
    protected:
        //// end protected member methods

        //// begin protected member methods (internal use only)
    protected:
        void setStyleSheet() override;
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
#endif // HEADER_GUARD_AetheriumArchivar$_HeaderLabel$_HPP



