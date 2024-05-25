#pragma once
#ifndef STANAG_4607_PLATFORM_LOCATION_SEGMENT_H
#define STANAG_4607_PLATFORM_LOCATION_SEGMENT_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Stanag4607_PlatformPosition.h"
#include "BA16_Angle.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents the platform location segment defined in the STANAG 4607 Standard (AP50093411 Issue 5)
		class Stanag4607_PlatformLocationSegment
		{
		private:
			uint32_t locationTime{ 0 };
			Stanag4607_PlatformPosition platformPosition{};
			BA16_Angle platformTrack{};
			uint32_t platformSpeed{ 0 };
			int8_t platformVerticalVelocity{ 0 };
			
		public:
			Stanag4607_PlatformLocationSegment() = default;

			Stanag4607_PlatformLocationSegment(uint32_t locationTime, Stanag4607_PlatformPosition platformPosition, BA16_Angle platformTrack, uint32_t platformSpeed, int8_t platformVerticalVelocity) :
				locationTime(locationTime),
				platformPosition(platformPosition),
				platformTrack(platformTrack),
				platformSpeed(platformSpeed),
				platformVerticalVelocity(platformVerticalVelocity){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(locationTime, "locationTime");
				archive.Serialise(platformPosition, "platformPosition");
				archive.Serialise(platformTrack, "platformTrack");
				archive.Serialise(platformSpeed, "platformSpeed");
				archive.Serialise(platformVerticalVelocity, "platformVerticalVelocity");
			}

			//Getters & Setters

			uint32_t getLocationTime() const
			{
				return locationTime;
			}

			void setLocationTime(uint32_t locationTime)
			{
				this->locationTime = locationTime;
			}

			Stanag4607_PlatformPosition getPlatformPosition() const
			{
				return platformPosition;
			}

			void setPlatformPosition(Stanag4607_PlatformPosition platformPosition)
			{
				this->platformPosition = platformPosition;
			}

			BA16_Angle getPlatformTrack() const
			{
				return platformTrack;
			}

			void setPlatformTrack(BA16_Angle platformTrack)
			{
				this->platformTrack = platformTrack;
			}

			uint32_t getPlatformSpeed()
			{
				return platformSpeed;
			}

			void setPlatformSpeed(uint32_t platformSpeed)
			{
				this->platformSpeed = platformSpeed;
			}

			int8_t getPlatformVerticalVelocity() const
			{ 
				return platformVerticalVelocity;
			}

			void setPlatformVerticalVelocity(int8_t platformVerticalVelocity)
			{
				this->platformVerticalVelocity = platformVerticalVelocity;
			}

			LCA_TOPIC("Stanag4607_PlatformLocationSegment", 1, 0);
		};
	}
}
#endif