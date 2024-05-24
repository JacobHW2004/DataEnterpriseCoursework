#ifndef I_COMMAND_CHECKER_MESSAGING
#define I_COMMAND_CHECKER_MESSAGING

#include <string>

namespace CommandCheckerLCA {

/**
*    @ingroup WeaponSystemTaskRouter
*    Interface For Weapon System Task Router Messaging LCA layer
*/
class ICommandCheckerMessaging
{

public:

    /* Virtual Destructor */
    virtual ~ICommandCheckerMessaging() noexcept = default;

    /* Default Constructor */
    ICommandCheckerMessaging() noexcept = default;

    /* Deleted Copy Constructor */
    ICommandCheckerMessaging(ICommandCheckerMessaging const&) = delete;

    /* Deleted Move Constructor */
    ICommandCheckerMessaging(ICommandCheckerMessaging&&) = delete;

    /* Deleted Copy Assignment */
    ICommandCheckerMessaging& operator=(ICommandCheckerMessaging const&) = delete;

    /* Deleted Move Assignment */
    ICommandCheckerMessaging& operator=(ICommandCheckerMessaging&&) = delete;

	/**
	 * @brief Logs a string to the LCA fabric
	 * @param logString The string to be logged
	 * @return none
	 */
	virtual void logError(std::string const aLogString) = 0;

};

} // namespace WeaponSystemTaskRouterLCA

#endif