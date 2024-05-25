#pragma once
#ifndef STANAG_4607_SCALE_FACTOR_H
#define STANAG_4607_SCALE_FACTOR_H

#include "Fabric/Utils/LCA_Macros.h"
#include "BA32_Angle.h"
#include "SA32_Angle.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents dwell area data used by the STANAG 4607 Format
		class Stanag4607_ScaleFactor
		{
		private:
			SA32_Angle latScale{};
			BA32_Angle longScale{};

		public:
			Stanag4607_ScaleFactor() = default;

			Stanag4607_ScaleFactor(SA32_Angle latScale, BA32_Angle longScale) :
				latScale(latScale),
				longScale(longScale){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(latScale, "latScale");
				archive.Serialise(longScale, "longScale");
			}

			//Getters & Setters

			SA32_Angle getLatScale() const
			{
				return latScale;
			}

			void setLatScale(SA32_Angle latScale)
			{
				this->latScale = latScale;
			}

			BA32_Angle getLongScale() const
			{
				return longScale;
			}

			void setLongScale(BA32_Angle longScale)
			{
				this->longScale = longScale;
			}

			LCA_TOPIC("Stanag4607_ScaleFactor", 1, 0);
		};	
	}
}
#endif