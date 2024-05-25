#pragma once
#ifndef STANAG_4607_PLATFORM_POSITION_H
#define STANAG_4607_PLATFORM_POSITION_H

#include "Fabric/Utils/LCA_Macros.h"
#include "SA32_Angle.h"
#include "BA32_Angle.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents platform position data used by the STANAG 4607 format
		class Stanag4607_PlatformPosition
		{
		private:
			SA32_Angle latitude{};
			BA32_Angle longitude{};
			int32_t altitude{ 0 };

		public:	
			Stanag4607_PlatformPosition() = default;

			Stanag4607_PlatformPosition(SA32_Angle latitude, BA32_Angle longitude, int32_t altitude) :
				latitude(latitude),
				longitude(longitude),
				altitude(altitude) {}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(latitude, "latitude");
				archive.Serialise(longitude, "longitude");
				archive.Serialise(altitude, "altitude");
			}

			//Getters & Setters

			SA32_Angle getLatitude() const
			{
				return latitude;
			}

			void setLatitude(SA32_Angle latitude)
			{
				this-> latitude = latitude;
			}

			BA32_Angle getLongitude() const
			{
				return longitude;
			}

			void setLongitude(BA32_Angle longitude)
			{
				this->longitude = longitude;
			}

			int32_t getAltitude() const
			{
				return altitude;
			}

			void setAltitude(int32_t altitude)
			{
				this->altitude = altitude;
			}


			LCA_TOPIC("Stanag4607_PlatformPosition", 1, 0);
		};
	}
}
#endif