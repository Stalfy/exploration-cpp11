// ############################################################################
// Header link
// ############################################################################
#include "ApplicationHost.hxx"
using exploration::hosting::ApplicationHost;

// ############################################################################
// Private Namespace
// ############################################################################

namespace exploration::hosting::_lifecycle {
    // Variables
    bool terminationRequested;
    std::condition_variable lifecycleConditionVariable;
    std::mutex lifecycleMutex;

    // Functions
    void onTerminationSignal(int signal) {
      std::lock_guard<std::mutex> lk(lifecycleMutex);
      if (!terminationRequested)
      {
        terminationRequested = true;
        lifecycleConditionVariable.notify_all();
      }
    }
}

// ############################################################################
// Constructors
// ############################################################################
ApplicationHost::ApplicationHost() {
  signal(SIGINT, exploration::hosting::_lifecycle::onTerminationSignal);
  signal(SIGTERM, exploration::hosting::_lifecycle::onTerminationSignal);
  signal(SIGBREAK, exploration::hosting::_lifecycle::onTerminationSignal);
  signal(SIGABRT, exploration::hosting::_lifecycle::onTerminationSignal);
  signal(SIGABRT2, exploration::hosting::_lifecycle::onTerminationSignal);
}

// ############################################################################
// Destructors
// ############################################################################
ApplicationHost::~ApplicationHost() {}

// ############################################################################
// Functions
// ############################################################################

// ----------------------------------------------------------------------------
// Public Functions
// ----------------------------------------------------------------------------
void ApplicationHost::run() {
    Greeter greeter;
    greeter.greet("World");

    dependency_injection::InstancesManager manager;
    services::PingService pingService = manager.borrowPingService();

    pingService.starting();
    pingService.start();
    pingService.started();

    std::unique_lock<std::mutex> lk(_lifecycle::lifecycleMutex);
    std::cout << "Send a termination signal to exit." << std::endl;
    _lifecycle::lifecycleConditionVariable.wait(lk, [this]{ return _lifecycle::terminationRequested; });

    pingService.stopping();
    pingService.stop();
    pingService.stopped();

    std::cout << "Bye" << std::endl;
}
