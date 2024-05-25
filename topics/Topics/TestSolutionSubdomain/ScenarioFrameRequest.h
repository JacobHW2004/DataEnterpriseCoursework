#ifndef SCENARIO_FRAME_REQUEST_TOPIC_H
#define SCENARIO_FRAME_REQUEST_TOPIC_H

#include <chrono>
#include <string>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

#include "ResponseCode.h"
#include "ScenarioFrame.h"

namespace Topics
{
	// @brief Response information for scenario loaded from file
	namespace TestSolutionTopics
	{
		class ScenarioFrameRequest
		{
		private:
			//None

		public:
			ScenarioFrame scenarioFrame{};
			std::string responseMessage{ "" };
			ResponseCode responseCode{ ResponseCode::RequestUnsupported };

			ScenarioFrameRequest() {};

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(scenarioFrame, "scenarioFrame");
				archive.Serialise(responseMessage, "responseMessage");
				archive.Serialise(responseCode, "responseCode");

			}
			LCA_TOPIC("ScenarioFrameRequest", 1, 0)

		};
	}
}
#endif