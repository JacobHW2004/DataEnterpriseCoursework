#pragma once
#ifndef STANAG_4607_DWELL_AREA_H
#define STANAG_4607_DWELL_AREA_H

#include "Fabric/Utils/LCA_Macros.h"
#include "BA32_Angle.h"
#include "SA32_Angle.h"
#include "BA16_Angle.h"
#include "SBD_16.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents dwell area data used by the STANAG 4607 Format
		class Stanag4607_DwellArea
		{
		private:
			SA32_Angle centerLatitude{};
			BA32_Angle centerLongitude{};
			SBD_16 rangeHalfExtent{};
			BA16_Angle dwellAngleHalfExtent{};

		public:
			Stanag4607_DwellArea() = default;

			Stanag4607_DwellArea(SA32_Angle centerLatitude, BA32_Angle centerLongitude, SBD_16 rangeHalfExtent, BA16_Angle dwellAngleHalfExtent) :
				centerLatitude(centerLatitude),
				centerLongitude(centerLongitude),
				rangeHalfExtent(rangeHalfExtent),
				dwellAngleHalfExtent(dwellAngleHalfExtent){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(centerLatitude, "centerLatitude");
				archive.Serialise(centerLongitude, "centerLongitude");
				archive.Serialise(rangeHalfExtent, "rangeHalfExtent");
				archive.Serialise(dwellAngleHalfExtent, "dwellAngleHalfExtent");
			}

			//Getters & Setters

			SA32_Angle getCenterLatitude() const
			{
				return centerLatitude;
			}

			void setCenterLatitude(SA32_Angle centerLatitude)
			{
				this->centerLatitude = centerLatitude;
			}

			BA32_Angle getCenterLongitude() const
			{
				return centerLongitude;
			}

			void setCenterLongitude(BA32_Angle centerLongitude)
			{
				this->centerLongitude = centerLongitude;
			}

			SBD_16 getRangeHalfExtent() const
			{
				return rangeHalfExtent;
			}

			void setRangeHalfExtent(SBD_16 rangeHalfExtent)
			{
				this->rangeHalfExtent = rangeHalfExtent;
			}

			BA16_Angle getDwellAngleHalfExtent() const
			{
				return dwellAngleHalfExtent;
			}

			void setDwellAngleHalfExtent(BA16_Angle dwellAngleHalfExtent)
			{
				this->dwellAngleHalfExtent = dwellAngleHalfExtent;
			}

			LCA_TOPIC("Stanag4607_DwellArea", 1, 0);
		};	
	}
}
#endif