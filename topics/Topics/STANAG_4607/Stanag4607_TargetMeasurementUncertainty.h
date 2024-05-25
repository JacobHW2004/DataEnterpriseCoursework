#pragma once
#ifndef STANAG_4607_TARGET_MEASUREMENT_UNCERTAINTY_H
#define STANAG_4607_TARGET_MEASUREMENT_UNCERTAINTY_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents bounding data used by the STANAG 4607 format
		class Stanag4607_TargetMeasurementUncertainty
		{
		private:
			uint16_t slantRange{ 0 };
			uint16_t crossRange{ 0 };
			uint8_t height{ 0 };
			uint16_t targetRadialVelocity{ 0 };

		public:
			Stanag4607_TargetMeasurementUncertainty() = default;

			Stanag4607_TargetMeasurementUncertainty(uint16_t slantRange, uint16_t crossRange, uint8_t height, uint16_t targetRadialVelocity) :
				slantRange(slantRange),
				crossRange(crossRange),
				height(height),
				targetRadialVelocity(targetRadialVelocity){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(slantRange, "slantRange");
				archive.Serialise(crossRange, "crossRange");
				archive.Serialise(height, "height");
				archive.Serialise(targetRadialVelocity, "targetRadialVelocity");
			}

			//Getters & Setters

			uint16_t getSlantRange() const
			{
				return slantRange;
			}

			void setSlantRange(uint16_t slantRange)
			{
				this->slantRange = slantRange;
			}

			uint16_t getCrossRange() const
			{
				return crossRange;
			}

			void setCrossRange(uint16_t crossRange)
			{
				this->crossRange = crossRange;
			}

			uint8_t getHeight() const
			{
				return height;
			}

			void setHeight(uint8_t height)
			{
				this->height = height;
			}

			uint16_t getTargetRadialVelocity() const
			{
				return targetRadialVelocity;
			}

			void setTargetRadialVelocity(uint16_t targetRadialVelocity)
			{
				this->targetRadialVelocity = targetRadialVelocity;
			}	

			LCA_TOPIC("Stanag4607_TargetMeasurementUncertainty", 1, 0);
		};	
	}
}
#endif