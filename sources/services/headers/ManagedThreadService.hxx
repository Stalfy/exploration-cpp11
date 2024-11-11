#ifndef SERVICES_MANAGED_THREAD_SERVICE_HXX_
#define SERVICES_MANAGED_THREAD_SERVICE_HXX_

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

#include "ManagedLifecycleService.hxx"

// ############################################################################
// Usings
// ############################################################################

// ############################################################################
// Class
// ############################################################################

namespace exploration {
namespace services {

class DECLSPEC ManagedThreadService : ManagedLifecycleService
{
    public:
        // Destructors
        virtual ~ManagedThreadService() {}
};

}}

#endif