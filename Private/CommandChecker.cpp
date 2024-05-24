#include "CommandChecker.h"
#include "CommandCheckerConstants.h"

namespace CommandCheckerLCA
{

	CommandChecker::CommandChecker(ICommandCheckerMessaging& aCommandCheckerMessagingIn) noexcept : 
		mCommandCheckerMessaging(aCommandCheckerMessagingIn)
	{}

    Topics::CommandValidityResponse CommandChecker::ValidateVolumeParameters(
			const Topics::EcrsMK2::WeaponSystem::Common::VolumeAircraftReferenced& vol, 
			const Topics::EcrsMK2::WeaponSystem::Common::WeaponSystemTaskType taskType)
	{
		Topics::CommandValidityResponse res { };

		static const double kMaxAzimuthHalfwidthAsn{0};	  // AirSearchNormal
		static const double kMaxElevationHalfwidthAsn{0}; // AirSearchNormal
		static const double kMaxAzimuthHalfwidthAsc{0};	  // AirSearchCued
		static const double kMaxElevationHalfwidthAsc{0};  // AirSearchCued

		switch (taskType)
		{
		case Topics::EcrsMK2::WeaponSystem::Common::WeaponSystemTaskType::AIR_SEARCH_NORMAL:
			if (vol.getAzimuthHalfWidth()() > kMaxAzimuthHalfwidthAsn ||
				vol.getElevationHalfWidth()() > kMaxElevationHalfwidthAsn)
			{
				//TODO
			}
			break;
		case Topics::EcrsMK2::WeaponSystem::Common::WeaponSystemTaskType::AIR_SEARCH_CUED:
			if (vol.getAzimuthHalfWidth()() > kMaxAzimuthHalfwidthAsc ||
				vol.getElevationHalfWidth()() > kMaxElevationHalfwidthAsc)
			{
				//TODO
			}
			break;
		default:
			//TODO
			break;
		}

		return res;
	}
} // namespace commandChecker
