#ifndef HEADER_GUARD_Nebenwelten_Date_HPP
#define HEADER_GUARD_Nebenwelten_Date_HPP

/*
 * Nebenwelten$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QObject>
//// end includes

//// begin specific includes
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
     * class Date
     *
     * @brief
     *
     */
    class Date
    {
        //// begin public member methods
    public:
        /// Constructor
        explicit Date();
        explicit Date(int day, int month, int year);
        explicit Date(quint64 sec);
        /// Destructor
        virtual ~Date();
        int day();
        int month();
        int year();

        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
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
        /// Initialisieren der Grundwerte
        void init();
        /// erechnet das Datum.
        void calculate(int sec);
        //// end private member methods

        //// begin public member
    public:
        //// end public member

        //// begin protected member
    protected:
        //// end protected member

        //// begin private member
    private:
        int SECPERMIN;
        int SECPERHOUR;
        int SECPERDAY;
        int SECPERMONTH;
        int SECPERYEAR;

        int DAYPERWEEK;
        int DAYPERMONTH;
        //// end private member
    };
}
#endif // HEADER_GUARD_Nebenwelten$_Date$_HPP
