#pragma once
#ifndef BA16_ANGLE_H
#define BA16_ANGLE_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>
#include <vector>
#include <cmath>
namespace Topics{
	namespace Stanag4607Topics {
		//Represents an unsigned angle in 16 bit binary format
		class BA16_Angle
		{
		private:
			uint16_t value{ 0 };

			uint16_t toBA16(double val) {
				uint16_t retVal = val * (64.0/45.0) * pow(2, 7);
				return retVal;
			}

		public:
			BA16_Angle() = default;

			BA16_Angle(std::uint16_t value) :
				value(value) {}

			BA16_Angle(double value) : 
				value(toBA16(value)) {}

			double toDouble() const
			{
				double retVal = double(value) * (45.0/32.0) * (1 / pow(2, 8));
				return retVal;
			}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(value, "value");			
			}

			LCA_TOPIC("BA16_Angle", 1, 0);	
		};
	}
}
#endif