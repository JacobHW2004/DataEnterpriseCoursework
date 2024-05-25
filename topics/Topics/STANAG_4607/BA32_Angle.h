#pragma once
#ifndef BA32_ANGLE_H
#define BA32_ANGLE_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>
#include <cmath>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents an unsigned angle in 32 bit binary format
		class BA32_Angle
		{
		private:
			uint32_t value{ 0 };

			uint32_t toBA32(double val) {
				uint32_t retVal = val * (64.0 / 45.0) * pow(2, 23);
				return retVal;
			}

		public:
			BA32_Angle() = default;

			BA32_Angle(std::uint32_t value) :
				value(value) {}

			BA32_Angle(double value) :
				value(toBA32(value)) {}

			double toDouble() const
			{
				double retVal = double(value) * (45.0 / 32.0) * (1 / pow(2, 24));
				return retVal;
			}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(value, "value");			
			}

			LCA_TOPIC("BA32_Angle", 1, 0);	
		};
	}
}
#endif