#pragma once
#ifndef SA32_ANGLE_H
#define SA32_ANGLE_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>
#include <cmath>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents a signed angle in 32 bit format
		class SA32_Angle
		{
		private:
			int32_t value{ 0 };

			int32_t toSA32(double val) {
				int32_t retVal = val * (64.0/45.0) * pow(2, 24);
				return retVal;
			}

		public:	
			SA32_Angle() = default;

			SA32_Angle(std::int32_t value) :
				value(value) {}

			SA32_Angle(double value) :
				value(toSA32(value)) {}

			double toDouble() const
			{
				double retVal = double(value) * (45.0 / 32.0) * (1 / pow(2, 25));
				return retVal;
			}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(value, "value");			
			}

			LCA_TOPIC("SA32_Angle", 1, 0);	
		};
	}
}
#endif