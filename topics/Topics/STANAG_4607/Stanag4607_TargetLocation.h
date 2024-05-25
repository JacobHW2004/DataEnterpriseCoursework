#pragma once
#ifndef STANAG_4607_TARGET_LOCATION_H
#define STANAG_4607_TARGET_LOCATION_H

#include "Fabric/Utils/LCA_Macros.h"
#include "BA32_Angle.h"
#include "SA32_Angle.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents target location data used by the STANAG 4607 format
		class Stanag4607_TargetLocation
		{
		private:
			SA32_Angle hiResLatitude{};
			BA32_Angle hiResLongitude{};
			int16_t deltaLat{ 0 };
			int16_t deltaLong{ 0 };
			int16_t geodeticHeight{ 0 };

		public:
			Stanag4607_TargetLocation() = default;

			Stanag4607_TargetLocation(SA32_Angle hiResLatitude, BA32_Angle hiResLongitude, int16_t deltaLat, int16_t deltaLong, int16_t geodeticHeight) :
				hiResLatitude(hiResLatitude),
				hiResLongitude(hiResLongitude),
				deltaLat(deltaLat),
				deltaLong(deltaLong),
				geodeticHeight(geodeticHeight){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(hiResLatitude, "hiResLatitude");
				archive.Serialise(hiResLongitude, "hiResLongitude");
				archive.Serialise(deltaLat, "deltaLat");
				archive.Serialise(deltaLong, "deltaLong");
				archive.Serialise(geodeticHeight, "geodeticHeight");			
			}

			//Getters & Setters

			SA32_Angle getHiResLatitude() const
			{
				return hiResLatitude;
			}

			void setHiResLatitude(SA32_Angle hiResLatitude)
			{
				this->hiResLatitude = hiResLatitude;
			}

			BA32_Angle getHiResLongitude() const
			{
				return hiResLongitude;
			}

			void setHiResLongitude(BA32_Angle hiResLongitude)
			{
				this->hiResLongitude = hiResLongitude;
			}

			int16_t getDeltaLat() const
			{
				return deltaLat;
			}

			void setDeltaLat(int16_t deltaLat)
			{
				this->deltaLat = deltaLat;
			}

			int16_t getDeltaLong() const
			{
				return deltaLong;
			}

			void setDeltaLong(int16_t deltaLong)
			{
				this->deltaLong = deltaLong;
			}

			int16_t getGeodeticHeight() const
			{
				return geodeticHeight;
			}

			void setGeodeticHeight(int16_t geodeticHeight)
			{
				this->geodeticHeight = geodeticHeight;
			}

			LCA_TOPIC("Stanag4607_TargetLocation", 1, 0);
		};	
	}
}
#endif