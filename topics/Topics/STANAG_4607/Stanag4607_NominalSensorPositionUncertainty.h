#pragma once
#ifndef STANAG_4607_NOMINAL_SENSOR_POSITION_UNCERTAINTY_H
#define STANAG_4607_NOMINAL_SENSOR_POSITION_UNCERTAINTY_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents nominal sensor position uncertainty data used by the STANAG 4607 Format
		class Stanag4607_NominalSensorPositionUncertainty
		{

		private:
			uint16_t alongTrack{ 0 };
			uint16_t crossTrack{ 0 };
			uint16_t altitude{ 0 };
			uint8_t trackHeading{ 0 };
			uint16_t sensorSpeed{ 0 };

		public:		
			Stanag4607_NominalSensorPositionUncertainty() = default;

			Stanag4607_NominalSensorPositionUncertainty(uint16_t alongTrack, uint16_t crossTrack, uint16_t altitude, uint8_t trackHeading, uint16_t sensorSpeed) :
				alongTrack(alongTrack),
				crossTrack(crossTrack),
				altitude(altitude),
				trackHeading(trackHeading),
				sensorSpeed(sensorSpeed) {}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(alongTrack, "alongTrack");
				archive.Serialise(crossTrack, "crossTrack");
				archive.Serialise(altitude, "altitude");
				archive.Serialise(trackHeading, "trackHeading");
				archive.Serialise(sensorSpeed, "sensorSpeed");
			}

			//Getters & Setters

			uint16_t getAlongTrack() const
			{ 
				return alongTrack;
			}

			void setAlongTrack(uint16_t alongTrack)
			{
				this->alongTrack = alongTrack;
			}
			
			uint16_t getCrossTrack() const
			{
				return crossTrack;
			}

			void setCrossTrack(uint16_t crossTrack)
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

			uint8_t getTrackHeading() const
			{
				return trackHeading;
			}

			void setTrackHeading(uint8_t trackHeading)
			{
				this->trackHeading = trackHeading;
			}

			uint16_t getSensorSpeed() const
			{
				return sensorSpeed;
			}

			void setSensorSpeed(uint16_t sensorSpeed)
			{
				this->sensorSpeed = sensorSpeed;
			}

			LCA_TOPIC("Stanag4607_NominalSensorPositionUncertainty", 1, 0);
		};
	}
}
#endif