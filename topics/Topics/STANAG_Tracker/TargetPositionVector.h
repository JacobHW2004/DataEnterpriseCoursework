#pragma once
#ifndef STANAG_TRACKER_TARGET_POSITION_VECTOR_H
#define STANAG_TRACKER_TARGET_POSITION_VECTOR_H

#include "Fabric/Utils/LCA_Macros.h"
#include "../STANAG_4607/BA32_Angle.h"
#include "../STANAG_4607/SA32_Angle.h"
#include <cstdint>

namespace Topics{
	namespace StanagTrackerTopics {
		
		//Topic to Represent Target Position Vector within STANAG Tracker Track List
		class TargetPositionVector
		{
		private:
			Topics::Stanag4607Topics::SA32_Angle latitude;
			Topics::Stanag4607Topics::BA32_Angle longitude;
			int16_t geodeticHeight{ 0 };

		public:
			TargetPositionVector() = default;

			TargetPositionVector(Topics::Stanag4607Topics::SA32_Angle latitude, Topics::Stanag4607Topics::BA32_Angle longitude, int16_t geodeticHeight):
				latitude(latitude),
				longitude(longitude),
				geodeticHeight(geodeticHeight){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(latitude, "latitude");
				archive.Serialise(longitude, "longitude");
				archive.Serialise(geodeticHeight, "geodeticHeight");
			}

			//Getters
			const Topics::Stanag4607Topics::SA32_Angle& getLatitude() const
			{
				return latitude;
			}

			const Topics::Stanag4607Topics::BA32_Angle& getLongitude() const
			{
				return longitude;
			}
			
			int16_t getGeodeticHeight() const
			{
				return geodeticHeight;
			}

			LCA_TOPIC("Topics::StanagTrackerTopics::TargetPositionVector", 1, 0);
		};	
	}
}
#endif