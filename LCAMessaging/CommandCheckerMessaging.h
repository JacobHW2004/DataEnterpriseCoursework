#ifndef LCA_WS_TASK_ROUTER_MESSAGING
#define LCA_WS_TASK_ROUTER_MESSAGING

//interface include
#include "ICommandCheckerMessaging.h"
#include "CommandChecker.h"

//LCA includes
#include "Container/ContainerContextInstance.h"
#include "Fabric/PubSub/Publisher.h"
#include "Fabric/PubSub/Subscriber.h"
#include "Fabric/RequestResponse/Requestor.h"

//Tool includes
#include "Fabric/Utils/Concurrency/ConcurrentQueue.h"


#include "Sleeper.h"

namespace CommandCheckerLCA {

/**
 * @ingroup CommandChecker
 */
    class CommandCheckerMessaging : public ICommandCheckerMessaging
    {
    private:
        /** @brief Sleeper instance for managing component thread sleeps and wakes */
        ConcurrentUtilities::Sleeper mSleeper;

        /** Context Instance for the Container */
        std::weak_ptr<lca::container::ContainerContextInstance> mContextInstance;

    public:

        /** @brief User-defined constructor taking a pointer to the ContainerContextInstance */
        CommandCheckerMessaging(const std::shared_ptr<lca::container::ContainerContextInstance>& contextIn) noexcept;

        /** @brief User-defined deconstructor */
        ~CommandCheckerMessaging() noexcept override = default;

        // Deleted copy constructor
        CommandCheckerMessaging(CommandCheckerMessaging const&) = delete;

        // Deleted move constructor
        CommandCheckerMessaging(CommandCheckerMessaging const&&) = delete;

        // Deleted copy assignment
        CommandCheckerMessaging& operator=(CommandCheckerMessaging const&) = delete;

        // Deleted move assignment
        CommandCheckerMessaging& operator=(CommandCheckerMessaging const&&) = delete;

        /** @brief Wait until conditions to wake thread are met or until the timeout runs out */
        void waitForMessages() noexcept;

        /** @brief Logging function to output over the LCA */
        void logError(std::string const aLogString) override;
    };

} // namespace CommandCheckerLCA

#endif