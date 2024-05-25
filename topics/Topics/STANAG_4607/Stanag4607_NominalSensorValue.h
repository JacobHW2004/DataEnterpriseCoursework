#pragma once
#ifndef STANAG_4607_NOMINAL_SENSOR_VALUE_H
#define STANAG_4607_NOMINAL_SENSOR_VALUE_H

#include "Fabric/Utils/LCA_Macros.h"
#include "BA16_Angle.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents nominal sensor value data used by the STANAG 4607 Format
		class Stanag4607_NominalSensorValue
		{
		private:
			uint16_t slantRangeSD{ 0 };
			BA16_Angle crossRangeSD{};
			uint16_t targetLOSComponentSD{ 0 };
			uint8_t minumumDetectableVelocity{ 0 };
			uint8_t detectionProbability{ 0 };
			uint8_t falseAlarmDensity{ 0 };

		public:
			Stanag4607_NominalSensorValue() = default;

			Stanag4607_NominalSensorValue(uint16_t slantRangeSD, BA16_Angle crossRangeSD, uint16_t targetLOSComponentSD, 
				uint8_t MinumumDetectableVelocity, uint8_t detectionProbability, uint8_t falseAlarmDensity) :
				slantRangeSD(slantRangeSD),
				crossRangeSD(crossRangeSD),
				targetLOSComponentSD(targetLOSComponentSD),
				minumumDetectableVelocity(MinumumDetectableVelocity),
				detectionProbability(detectionProbability),
				falseAlarmDensity(falseAlarmDensity){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(slantRangeSD, "slantRangeSD");
				archive.Serialise(crossRangeSD, "crossRangeSD");
				archive.Serialise(targetLOSComponentSD, "targetLOSComponentSD");
				archive.Serialise(minumumDetectableVelocity, "MinumumDetectableVelocity");
				archive.Serialise(detectionProbability, "detectionProbability");
				archive.Serialise(falseAlarmDensity, "falseAlarmDensity");
			}

			//Getters & Setters

			uint16_t getSlantRangeSD() const
			{
				return slantRangeSD;
			}

			void setSlantRangeSD(uint16_t slantRangeSD)
			{
				this->slantRangeSD = slantRangeSD;
			}

			BA16_Angle getCrossRangeSD() const
			{
				return crossRangeSD;
			}

			void setCrossRangeSD(BA16_Angle crossRangeSD)
			{
				this->crossRangeSD = crossRangeSD;
			}

			uint16_t getTargetLOSComponentSD() const
			{
				return targetLOSComponentSD;
			}

			void setTargetLOSComponentSD(uint16_t targetLOSComponentSD)
			{
				this->targetLOSComponentSD = targetLOSComponentSD;
			}

			uint8_t getMinimumDetectableVelocity() const
			{
				return minumumDetectableVelocity;
			}

			void setMinimumDetectableVelocity(uint8_t minumumDetectableVelocity)
			{
				this->minumumDetectableVelocity = minumumDetectableVelocity;
			}

			uint8_t getDetectionProbability() const
			{
				return detectionProbability;
			}

			void setDetectionProbability(uint8_t detectionProbability)
			{
				this->detectionProbability = detectionProbability;
			}

			uint8_t getFalseAlarmDensity() const
			{
				return falseAlarmDensity;
			}

			void setFalseAlarmDensity(uint8_t falseAlarmDensity)
			{
				this->falseAlarmDensity = falseAlarmDensity;
			}

			LCA_TOPIC("Stanag4607_NominalSensorValue", 1, 0);
		};	
	}
}
#endif