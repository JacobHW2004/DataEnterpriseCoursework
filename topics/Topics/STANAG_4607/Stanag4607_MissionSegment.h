#pragma once
#ifndef STANAG_4607_MISSION_SEGMENT_H
#define STANAG_4607_MISSION_SEGMENT_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Stanag4607_ReferenceTime.h"
#include <cstdint>
#include <vector>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents the mission segment defined in the STANAG 4607 Standard (AP50093411 Issue 5)
		class Stanag4607_MissionSegment
		{
		private:
			std::vector<uint8_t> missionPlan{ 0,0,0,0,0,0,0,0,0,0,0,0 }; //12 Alphanumeric Characters
			std::vector<uint8_t> flightPlan{ 0,0,0,0,0,0,0,0,0,0,0,0 }; //12 Alphanumeric Characters
			uint8_t platformType{ 0 }; //Enumerated type
			std::vector<std::uint8_t> platformConfiguration{ 0,0,0,0,0,0,0,0,0,0 }; // 10 Alphanumeric Characters
			Stanag4607_ReferenceTime referenceTime{};

		public:
			Stanag4607_MissionSegment() = default;

			Stanag4607_MissionSegment(const std::vector<uint8_t>& missionPlan , const std::vector<uint8_t>& flightPlan, uint8_t platformType,
				const std::vector<uint8_t>& platformConfiguration, Stanag4607_ReferenceTime referenceTime) :
				missionPlan(missionPlan),
				flightPlan(flightPlan),
				platformType(platformType),
				platformConfiguration(platformConfiguration),
				referenceTime(referenceTime) {}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(missionPlan, "char", "missionPlan");
				archive.Serialise(flightPlan, "char", "flightPlan");
				archive.Serialise(platformType, "platformType");
				archive.Serialise(platformConfiguration, "char", "platformConfiguration");
				archive.Serialise(referenceTime, "referenceTime");
			}

			//Getters & Setters
			std::vector<uint8_t> getMissionPlan() const
			{ 
				return missionPlan;
			}

			void setMissionPlan(const std::vector<uint8_t>& missionPlan)
			{
				this->missionPlan = missionPlan;
			}

			std::vector<uint8_t> getFlightPlan() const
			{
				return flightPlan;
			}

			void setFlightPlan(const std::vector<uint8_t>& flightPlan)
			{
				this->flightPlan = flightPlan;
			}

			uint8_t getPlatformType() const
			{ 
				return platformType;
			}

			void setPlatformType(uint8_t platformType)
			{
				this->platformType = platformType;
			}

			std::vector<std::uint8_t> getPlatformConfiguration() const
			{
				return platformConfiguration;
			}

			void setPlatformConfiguration(const std::vector<std::uint8_t>& platformConfiguration)
			{
				this->platformConfiguration = platformConfiguration;
			}

			Stanag4607_ReferenceTime getReferenceTime() const
			{
				return referenceTime;
			}

			void setReferenceTime(Stanag4607_ReferenceTime referenceTime)
			{
				this->referenceTime = referenceTime;
			}

			LCA_TOPIC("Stanag4607_MissionSegment", 1, 0);
		};
	}
}
#endif