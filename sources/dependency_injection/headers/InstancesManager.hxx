#ifndef DI_INSTANCES_MANAGER_HXX_
#define DI_INSTANCES_MANAGER_HXX_

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

#include "PingService.hxx"

// ############################################################################
// Usings
// ############################################################################

// ############################################################################
// Class
// ############################################################################

namespace exploration {
namespace dependency_injection {

namespace _nested_classes {
    class Singletons {
        public:
            // Constructors
            Singletons();

            // Destructors
            ~Singletons();

            // Members
            services::PingService pingService;
    };
}

class DECLSPEC InstancesManager
{

    public:
        // Constructors
        InstancesManager();

        // Destructors
        ~InstancesManager();
    
        // Functions
        services::PingService borrowPingService();

    private:
        _nested_classes::Singletons _singletons;
};

}}

#endif