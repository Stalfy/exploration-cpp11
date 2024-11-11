#ifndef SERVICES_PING_SERVICE_HXX_
#define SERVICES_PING_SERVICE_HXX_

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

#include "ManagedThreadService.hxx"

// ############################################################################
// Usings
// ############################################################################

// ############################################################################
// Class
// ############################################################################

namespace exploration {
namespace services {

class DECLSPEC PingService final : ManagedThreadService
{
    public:
        // Constructors
        PingService();

        // Destructors
        ~PingService();

        // Functions
        void starting() override;
        void start() override;
        void started() override;
        void stopping() override;
        void stop() override;
        void stopped() override;
};

}}

#endif