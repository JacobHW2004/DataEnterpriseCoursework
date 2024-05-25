// ScenarioFrameTopic.h - TBD
#ifndef SCENARIO_FRAME_TOPIC_H
#define SCENARIO_FRAME_TOPIC_H

#include <chrono>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

#include "SpatialData.h"

namespace Topics
{
	// @brief Entity information loaded from a scenario file
	namespace TestSolutionTopics
	{
		class ScenarioFrame
		{
		private:
			// None

		public:
			std::chrono::system_clock::time_point timeStamp{ std::chrono::system_clock::duration::zero() };
			SpatialData platformData{};
			std::vector<SpatialData> targetData{};

			ScenarioFrame() {};

			template<class T>
			void Serialise(T& archive)
			{
				// Convert the timestamp to something serialisable
				uint64_t timeStampSerialisable{ static_cast<uint64_t>(timeStamp.time_since_epoch().count()) };

				archive.Serialise(timeStampSerialisable, "timeStampSerialisable");
				archive.Serialise(platformData, "platformData");
				archive.Serialise(targetData, "targetData", "targetDataVector");

				// Deserialise the serialised timestamp repopulate the member variable
				std::chrono::system_clock::duration const durationSinceLastEpoch(timeStampSerialisable);
				std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
				timeStamp = timePointSinceLastEpoch;
			}

			LCA_TOPIC("ScenarioFrame", 1, 0)
		};
	}
}
#endif
