#ifndef SCENARIO_INFO_RESPONSE_H
#define SCENARIO_INFO_RESPONSE_H

#include <chrono>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
	// @brief Response information from ScenarioInfoRequest
	namespace TestSolutionTopics
	{
		class ScenarioInfoResponse
		{
		private:
			//None

		public:

			std::string scenarioName{ "None Loaded" };
			std::chrono::system_clock::time_point startTime{};
			std::chrono::milliseconds scenarioLength{ 0 };
			unsigned int numFrames{ 0 };
			unsigned int numTargets{ 0 };

			ScenarioInfoResponse() {};

			template<class T>
			void Serialise(T& archive)
			{
				// Convert start time to something serialisable
				uint64_t startTimeSerialisable{ static_cast<uint64_t>(startTime.time_since_epoch().count()) };
				uint64_t lengthSerialisable{ static_cast<uint64_t>(scenarioLength.count()) };

				archive.Serialise(scenarioName, "scenarioName");
				archive.Serialise(startTimeSerialisable, "startTimeSerialisable");
				archive.Serialise(lengthSerialisable, "lengthSerialisable");
				archive.Serialise(numFrames, "numFrames");
				archive.Serialise(numTargets, "numTargets");


				// Deserialise the serialised start time repopulate the member variable
				std::chrono::system_clock::duration const durationSinceLastEpoch(startTimeSerialisable);
				std::chrono::system_clock::time_point const timePointSinceLastEpoch(durationSinceLastEpoch);
				startTime = timePointSinceLastEpoch;
				scenarioLength = std::chrono::milliseconds{ lengthSerialisable };
			}

			LCA_TOPIC("ScenarioInfoResponse", 1, 0)
		};
	}
}
#endif