#pragma once
#ifndef STANAG_TRACKER_TARGET_VELOCITY_VECTOR_H
#define STANAG_TRACKER_TARGET_VELOCITY_VECTOR_H

#include "Fabric/Utils/LCA_Macros.h"
#include "../STANAG_4607/BA32_Angle.h"
#include <cstdint>

namespace Topics{
	namespace StanagTrackerTopics {

		//Topic to Represent Target Velocity Vector within STANAG Tracker Track List
		class TargetVelocityVector
		{
		private:
			uint16_t speed{ 0 };
			Topics::Stanag4607Topics::BA32_Angle bearing;

		public:
			TargetVelocityVector() = default;

			TargetVelocityVector(uint16_t speed, Topics::Stanag4607Topics::BA32_Angle bearing):
				speed(speed),
				bearing(bearing){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(speed, "speed");
				archive.Serialise(bearing, "bearing");
			}

			//Getters
			int16_t getSpeed() const
			{
				return speed;
			}

			const Topics::Stanag4607Topics::BA32_Angle& getBearing() const
			{
				return bearing;
			}	

			LCA_TOPIC("Topics::StanagTrackerTopics::TargetVelocityVector", 1, 0);
		};	
	}
}
#endif