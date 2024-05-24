#include "CommandCheckerMessaging.h"
#include "CommandChecker.h"
#include "CommandCheckerResponder.h"


//-------LCA Stuff
#include "Container/ContainerContextInstance.h"

namespace CommandCheckerLCA{
	LCA_COMPONENT_VERSION(1, 0)

	/**
	 * @file
	 * @defgroup WeaponSystemTaskRouter
	 * @brief Component entry point for WeaponSystemTaskRouter.
	 * The Weapon System Task Router exists to support the routing of multiple Weapon System Tasks in the system.
	 * @sub AirSearchNormalAircraftReferencedCommandTopic
	 * @sub AirSearchNormalAircraftReferencedStatusTopic
	 * @pub AsnarCommandForProxy
	 * @pub AirSearchNormalAircraftReferencedStatusTopic
	 * @request ProxyMappingRequestResponse
	 */
	void _EXPORT run(std::shared_ptr<lca::container::ContainerContextInstance>& context) 
	{

		CommandCheckerMessaging commandCheckerMessaging{context};
		std::shared_ptr<CommandChecker> const commandCheckerComponentPtr{ std::make_shared<CommandChecker>(commandCheckerMessaging) };

		CommandCheckerResponder commandCheckerResponder{ context, commandCheckerComponentPtr };

		while (!(context->isShuttingDown()))
		{

			commandCheckerMessaging.waitForMessages();
		}
	}
} // namespace WeaponSystemTaskRouterLCA


