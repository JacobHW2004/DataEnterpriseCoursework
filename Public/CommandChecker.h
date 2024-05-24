#ifndef COMMAND_CHECKER_H
#define COMMAND_CHECKER_H

#include "ICommandCheckerMessaging.h"

// Topics
#include "CommandValidityResponse.h"
#include "CommandValidityRequest.h"

namespace CommandCheckerLCA {

/**
 * @ingroup WeaponSystemTaskRouter
 * The Weapon System Task Router exists to support the routing of multiple weapon system tasks in the system.
 * ## Responsibilities
 * + Provide the API for the component
 * + Routing of Tasks coming from the Weapon System
 * + Maintaining Mapping between UTI and Proxies
 * + Validation and Rejection  of UTIs
 */
class CommandChecker final
{
  private:
    ICommandCheckerMessaging& mCommandCheckerMessaging;
    /**
    * @brief Checks that the volume contains valid values
    * @return true if valid, false otherwise
    */
  public:
    CommandChecker(ICommandCheckerMessaging& mCommandCheckerMessaging) noexcept;

    Topics::CommandValidityResponse ValidateVolumeParameters(const Topics::EcrsMK2::WeaponSystem::Common::VolumeAircraftReferenced& vol, const Topics::EcrsMK2::WeaponSystem::Common::WeaponSystemTaskType taskType);

};

} // namespace WeaponSystemTaskRouterLCA

#endif