#ifndef HOSTING_GREETER_HXX_
#define HOSTING_GREETER_HXX_

// ############################################################################
// Windows build management
// ############################################################################
#ifdef _WIN32
#  ifdef WINEXPORT_
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else
#  define DECLSPEC
#endif

// ############################################################################
// Includes
// ############################################################################
#include <iostream>
#include <string>

// ############################################################################
// Usings
// ############################################################################

// ############################################################################
// Class
// ############################################################################

namespace exploration {
namespace hosting {

class DECLSPEC Greeter
{
    public:
        // Constructors
        Greeter();

        // Destructors
        ~Greeter();

        // Functions
        void greet(std::string who);
};

}}

#endif