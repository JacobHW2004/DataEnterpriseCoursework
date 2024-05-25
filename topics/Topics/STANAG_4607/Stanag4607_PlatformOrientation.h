#pragma once
#ifndef STANAG_4607_PLATFORM_ORIENTATION_H
#define STANAG_4607_PLATFORM_ORIENTATION_H

#include "Fabric/Utils/LCA_Macros.h"
#include "BA16_Angle.h"
#include "SA16_Angle.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents platform orientation data used by the STANAG 4607 Format
		class Stanag4607_PlatformOrientation
		{
		private:
			BA16_Angle heading{};
			SA16_Angle pitch{};
			SA16_Angle roll{};

		public:
			Stanag4607_PlatformOrientation() = default;

			Stanag4607_PlatformOrientation(BA16_Angle heading, SA16_Angle pitch, SA16_Angle roll) :
				heading(heading),
				pitch(pitch),
				roll(roll) {}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(heading, "heading");
				archive.Serialise(pitch, "pitch");
				archive.Serialise(roll, "roll");
			}

			//Getters & Setters

			BA16_Angle getHeading() const
			{
				return heading;
			}

			void setHeading(BA16_Angle heading)
			{
				this->heading = heading;
			}

			SA16_Angle getPitch() const
			{
				return pitch;
			}

			void setPitch(SA16_Angle pitch)
			{
				this->pitch = pitch;
			}

			SA16_Angle getRoll() const
			{
				return roll;
			}

			void setRoll(SA16_Angle roll)
			{
				this->roll = roll;
			}

			LCA_TOPIC("Stanag4607_PlatformOrientation", 1, 0);
		};	
	}
}
#endif