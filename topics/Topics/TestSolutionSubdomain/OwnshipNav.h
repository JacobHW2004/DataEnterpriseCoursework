#ifndef OWNSHIP_NAV_TOPIC_H
#define OWNSHIP_NAV_TOPIC_H

#include <array>
#include <chrono>

#include "Fabric/Utils/LCA_Macros.h"
#include "SpatialData.h"

namespace Topics
{
	namespace TestSolutionTopics
	{
		class OwnshipNav
		{
		public:
			std::chrono::system_clock::time_point mTimeStamp{ std::chrono::system_clock::duration::zero() };
			SpatialData spatialData {};
            
			OwnshipNav() {};

			template<class T>
			void Serialise(T& archive)
			{
				// Convert the timestamp into something serialisable
				uint64_t mTimeStamp_serialisable{ static_cast<uint64_t>(mTimeStamp.time_since_epoch().count()) };

				archive.Serialise(mTimeStamp_serialisable, "mTimeStamp");
                spatialData.Serialise(archive);

				// Deserialise the serialised timestamp and repopulate the member variable
				std::chrono::system_clock::duration const durationSinceLastEpoch(mTimeStamp_serialisable);
				std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
				mTimeStamp = timePointSinceLastEpoch;

			}

			LCA_TOPIC("OwnshipNav", 1, 0)
		};
		
	}
}
#endif