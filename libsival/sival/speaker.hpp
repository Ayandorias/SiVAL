#ifndef HEADER_GUARD_SiVAL_speaker_HPP
#define HEADER_GUARD_SiVAL_speaker_HPP

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <string>
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

namespace SiVAL {
/**
 * @brief The Speaker class contains the speaker to simulate.
 *
 * The speaker class contains all needed information to simulate and create graphs.
 */
class Speaker
{
    //// begin public member methods
public:
    explicit Speaker(const std::string &file);
    virtual ~Speaker();
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
    std::string fileName;
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

};
}
#endif // HEADER_GUARD_SiVAL_speaker_HPP
