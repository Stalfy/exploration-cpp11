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
    exploration::hosting::Greeter greeter;
    greeter.greet("World");

    std::cout << "Send a termination signal to exit." << std::endl;

    std::unique_lock<std::mutex> lk(exploration::hosting::_lifecycle::lifecycleMutex);
    exploration::hosting::_lifecycle::lifecycleConditionVariable.wait(lk, [this]{ return exploration::hosting::_lifecycle::terminationRequested; });

    std::cout << "Bye" << std::endl;
}
