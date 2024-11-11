#ifndef SERVICES_MANAGED_LIFECYCLE_SERVICE_HXX_
#define SERVICES_MANAGED_LIFECYCLE_SERVICE_HXX_

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

// ############################################################################
// Usings
// ############################################################################

// ############################################################################
// Class
// ############################################################################

namespace exploration {
namespace services {

class DECLSPEC ManagedLifecycleService
{
    public:
        // Destructors
        virtual ~ManagedLifecycleService() {}

        // Functions
        virtual void starting() = 0;
        virtual void start() = 0;
        virtual void started() = 0;
        virtual void stopping() = 0;
        virtual void stop() = 0;
        virtual void stopped() = 0;
};

}}

#endif