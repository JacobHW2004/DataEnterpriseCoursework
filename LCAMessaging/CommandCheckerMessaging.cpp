#include "CommandCheckerMessaging.h"

namespace  CommandCheckerLCA {

    CommandCheckerMessaging::CommandCheckerMessaging(const std::shared_ptr<lca::container::ContainerContextInstance>& contextIn) noexcept :
        ICommandCheckerMessaging{},
        mSleeper{},
        mContextInstance{ contextIn }
    {}

    void CommandCheckerMessaging::waitForMessages() noexcept
    {
        constexpr std::uint32_t SLEEPER_TIMEOUT{ 5U };
        mSleeper.waitWithTimeout(std::chrono::milliseconds(SLEEPER_TIMEOUT));
    }
    void CommandCheckerMessaging::logError(std::string const aLogString)
    {
        LOG_ERROR((std::shared_ptr<lca::container::ContainerContextInstance>(mContextInstance))->getLogger(), aLogString)
    }

}