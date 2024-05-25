
#ifndef TIME_STAMPED_DWELL_H
#define TIME_STAMPED_DWELL_H
#include "Fabric/Utils/LCA_Macros.h"
#include "Dwell.h"

#include <cstdint>
#include <chrono>

namespace Topics
{
	namespace TestSolutionTopics
	{
		struct TimeStampedDwell
		{
			std::chrono::time_point<std::chrono::system_clock> dwellCentreTime{};
			Dwell dwell{};

			/**
			* @brief Serialise function required for communications
			*/
			template <class T>
			void Serialise(T& archive) {

				//convert the timestamp to something we can serialise
				std::uint64_t timeSinceEpoch{ static_cast<std::uint64_t>(dwellCentreTime.time_since_epoch().count()) };
				archive.Serialise(timeSinceEpoch, "dwellCentreTime");

				//deserialise the time into a timestamp
				std::chrono::system_clock::duration const durationSinceLastEpoch(timeSinceEpoch);
				std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch); //create a new time point so it can be initialised with the serialised time value
				dwellCentreTime = timePointSinceLastEpoch;

				archive.Serialise(dwell, "dwell");
			}
			LCA_TOPIC("TimeStampedDwell", 1, 0)

		}; // struct TimeStampedDwell

	} // namespace TestSolutionTopics

} // namespace Topics

#endif

