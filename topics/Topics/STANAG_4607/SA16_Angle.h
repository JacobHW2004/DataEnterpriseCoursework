#pragma once
#ifndef SA16_ANGLE_H
#define SA16_ANGLE_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>
#include <cmath>
namespace Topics{
	namespace Stanag4607Topics {
		//Represents a signed angle in 16 bit format.
		class SA16_Angle
		{
		private:
			int16_t value{ 0 };

			int16_t toSA16(double val) {
				int16_t retVal = val * (64.0/45.0) * pow(2, 8);
				return retVal;
			}

		public:		
			SA16_Angle() = default;

			SA16_Angle(std::int16_t value) :
				value(value) {}

			SA16_Angle(double value) :
				value(toSA16(value)) {}

			double toDouble() const
			{
				double retVal = double(value) * (45.0 / 32.0) * (1 / pow(2, 9));
				return retVal;
			}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(value, "value");			
			}

			LCA_TOPIC("SA16_Angle", 1, 0);	
		};
	}
}
#endif