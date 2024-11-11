// ############################################################################
// Header link
// ############################################################################
#include "PingService.hxx"
using exploration::services::PingService;

// ############################################################################
// Constructors
// ############################################################################
PingService::PingService() {}

// ############################################################################
// Destructors
// ############################################################################
PingService::~PingService() {}

// ############################################################################
// Functions
// ############################################################################

// ----------------------------------------------------------------------------
// Public Functions
// ----------------------------------------------------------------------------
void PingService::starting() {
    std::cout << "starting" << std::endl;
}

void PingService::start() {
    std::cout << "start" << std::endl;
}

void PingService::started() {
    std::cout << "started" << std::endl;
}

void PingService::stopping() {
    std::cout << "stopping" << std::endl;
}

void PingService::stop() {
    std::cout << "stop" << std::endl;
}

void PingService::stopped() {
    std::cout << "stopped" << std::endl;
}
