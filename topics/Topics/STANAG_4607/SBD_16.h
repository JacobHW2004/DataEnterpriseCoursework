#pragma once
#ifndef SBD_16_H
#define SBD_16_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>
#include <cmath>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents a decimal number in 16 bit signed binary decimal format.
		class SBD_16
		{
		private:
			int16_t toSBD16(double val)
			{
				int16_t     result;   // return value
				int16_t     sign;     // sign of value
				uint32_t    temp;     // temp variable

				// recover the magnitude and record the input sign
				sign = 0;
				if (val < 0.0)
				{
					val = (-val);
					sign = 0x8000U; //0b10000...
				}

				// compute the packed sign magnitude value
				val = (val * 128.0) + 0.5;
				temp = static_cast<uint32_t>(val);
				result = static_cast<int16_t>(temp & 0x7FFFU);

				// Set Sign Bit if negative
				result = static_cast<int16_t>(result | sign);
				return result;
			}

		public:	
			int16_t value{ 0 };

			SBD_16() = default;

			SBD_16(std::int16_t value) :
				value(value) {}

			SBD_16(double value) :
				value(toSBD16(value)) {}

			double toDouble()
			{
				uint16_t mag_val;
				uint16_t sign;
				double scaled_val;

				/* Extract the sign bit. */
				sign = (value & 0x8000) >> 15;

				/* Find the magnitude by masking the top bit. */
				mag_val = (value & 0x7FFF);

				/* Calculate the scaled value. */
				if (sign == 1)
				{
					scaled_val = -mag_val / 128.0;
				}
				else
				{
					scaled_val = mag_val / 128.0;
				}

				return scaled_val;
			}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(value, "value");			
			}

			LCA_TOPIC("SBD_16", 1, 0);	
		};
	}
}
#endif