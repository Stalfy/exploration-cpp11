#ifndef HOSTING_APPLICATION_HOST_HXX_
#define HOSTING_APPLICATION_HOST_HXX_

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
#include <condition_variable>
#include <iostream>
#include <string>

#include "Greeter.hxx"

// ############################################################################
// Usings
// ############################################################################

// ############################################################################
// Class
// ############################################################################

namespace exploration {
namespace hosting {

class DECLSPEC ApplicationHost
{
    public:
        // Constructors
        ApplicationHost();

        // Destructors
        ~ApplicationHost();

        // Functions
        void run();
};

}}

#endif