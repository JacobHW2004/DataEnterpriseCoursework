#pragma once
#ifndef STANAG_4607_REFERENCE_TIME_H
#define STANAG_4607_REFERENCE_TIME_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents reference time data used by the STANAG 4607 format
		class Stanag4607_ReferenceTime
		{
		private:
			uint16_t year{ 0 };
			uint8_t month{ 0 };
			uint8_t day{ 0 };

		public:
			Stanag4607_ReferenceTime() = default;

			Stanag4607_ReferenceTime(uint16_t year, uint8_t month, uint8_t day) :
				year(year),
				month(month),
				day(day) {}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(year, "year");
				archive.Serialise(month, "month");
				archive.Serialise(day, "day");
			}

			//Getters & Setters

			uint16_t getYear() const
			{
				return year;
			}

			void setYear(uint16_t year)
			{
				this->year = year;
			}

			uint8_t getMonth() const
			{
				return month;
			}

			void setMonth(uint8_t month)
			{
				this->month = month;
			}

			uint8_t getDay() const
			{
				return day;
			}

			void setDay(uint8_t day)
			{
				this->day = day;
			}

			LCA_TOPIC("Stanag4607_ReferenceTime", 1, 0);
		};
	}
}
#endif