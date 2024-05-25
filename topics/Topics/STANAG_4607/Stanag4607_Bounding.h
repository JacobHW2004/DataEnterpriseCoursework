#pragma once
#ifndef STANAG_4607_BOUNDING_H
#define STANAG_4607_BOUNDING_H

#include "Fabric/Utils/LCA_Macros.h"
#include "BA32_Angle.h"
#include "SA32_Angle.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents bounding data used by the STANAG 4607 format
		class Stanag4607_Bounding
		{
		private:
			SA32_Angle ptALatitude{};
			BA32_Angle ptALongitude{};
			SA32_Angle ptBLatitude{};
			BA32_Angle ptBLongitude{};
			SA32_Angle ptCLatitude{};
			BA32_Angle ptCLongitude{};
			SA32_Angle ptDLatitude{};
			BA32_Angle ptDLongitude{};

		public:
			Stanag4607_Bounding() = default;

			Stanag4607_Bounding(SA32_Angle ptALatitude, BA32_Angle ptALongitude, SA32_Angle ptBLatitude, BA32_Angle ptBLongitude,
				SA32_Angle ptCLatitude, BA32_Angle ptCLongitude, SA32_Angle ptDLatitude, BA32_Angle ptDLongitude) :
				ptALatitude(ptALatitude),
				ptALongitude(ptALongitude),
				ptBLatitude(ptBLatitude),
				ptBLongitude(ptBLongitude),
				ptCLatitude(ptCLatitude),
				ptCLongitude(ptCLongitude),
				ptDLatitude(ptDLatitude),
				ptDLongitude(ptDLongitude) {}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(ptALatitude, "ptALatitude");
				archive.Serialise(ptALongitude, "ptALongitude");
				archive.Serialise(ptBLatitude, "ptBLatitude");
				archive.Serialise(ptBLongitude, "ptBLongitude");
				archive.Serialise(ptCLatitude, "ptCLatitude");
				archive.Serialise(ptCLongitude, "ptCLongitude");
				archive.Serialise(ptDLatitude, "ptDLatitude");
				archive.Serialise(ptDLongitude, "ptDLongitude");
			}

			//Getters & Setters

			SA32_Angle getPtALatitude() const
			{
				return ptALatitude;
			}

			void setPtALatitude(SA32_Angle latitude)
			{
				ptALatitude = latitude;
			}

			BA32_Angle getPtALongitude() const
			{
				return ptALongitude;
			}

			void setPtALongitude(BA32_Angle longitude)
			{
				ptALongitude = longitude;
			}

			SA32_Angle getPtBLatitude() const
			{
				return ptBLatitude;
			}

			void setPtBLatitude(SA32_Angle latitude)
			{
				ptBLatitude = latitude;
			}

			BA32_Angle getPtBLongitude() const
			{
				return ptBLongitude;
			}

			void setPtBLongitude(BA32_Angle longitude)
			{
				ptBLongitude = longitude;
			}
			
			SA32_Angle getPtCLatitude() const
			{
				return ptCLatitude;
			}

			void setPtCLatitude(SA32_Angle latitude)
			{
				ptCLatitude = latitude;
			}

			BA32_Angle getPtCLongitude() const
			{
				return ptCLongitude;
			}

			void setPtCLongitude(BA32_Angle longitude)
			{
				ptCLongitude = longitude;
			}

			SA32_Angle getPtDLatitude() const
			{
				return ptDLatitude;
			}

			void setPtDLatitude(SA32_Angle latitude)
			{
				ptDLatitude = latitude;
			}

			BA32_Angle getPtDLongitude() const
			{
				return ptDLongitude;
			}

			void setPtDLongitude(BA32_Angle longitude)
			{
				ptDLongitude = longitude;
			}

			LCA_TOPIC("Stanag4607_Bounding", 1, 0);
		};	
	}
}
#endif