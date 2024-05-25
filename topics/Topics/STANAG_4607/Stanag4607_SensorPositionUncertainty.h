#pragma once
#ifndef STANAG_4607_SENSOR_POSITION_UNCERTAINTY_H
#define STANAG_4607_SENSOR_POSITION_UNCERTAINTY_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents bounding data used by the STANAG 4607 format
		class Stanag4607_SensorPositionUncertainty
		{
		private:
			uint32_t alongTrack{ 0 };
			uint32_t crossTrack{ 0 };
			uint16_t altitude{ 0 };
		public:
			Stanag4607_SensorPositionUncertainty() = default;

			Stanag4607_SensorPositionUncertainty(uint32_t alongTrack, uint32_t crossTrack, uint16_t altitude) :
				alongTrack(alongTrack),
				crossTrack(crossTrack),
				altitude(altitude) {}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(alongTrack, "alongtrack");
				archive.Serialise(crossTrack, "crossTrack");
				archive.Serialise(altitude, "altitude");
			}

			//Getters & Setters

			uint32_t getAlongTrack() const
			{
				return alongTrack;
			}

			void setAlongTrack(uint32_t alongTrack)
			{
				this->alongTrack = alongTrack;
			}

			uint32_t getCrossTrack() const
			{
				return crossTrack;
			}

			void setCrossTrack(uint32_t crossTrack)
			{
				this->crossTrack = crossTrack;
			}

			uint16_t getAltitude() const
			{
				return altitude;
			}

			void setAltitude(uint16_t altitude)
			{
				this->altitude = altitude;
			}

			LCA_TOPIC("Stanag4607_SensorPositionUncertainty", 1, 0);
		};	
	}
}
#endif