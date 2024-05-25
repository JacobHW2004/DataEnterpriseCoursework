#ifndef SCENARIO_INFO_REQUEST_H
#define SCENARIO_INFO_REQUEST_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
	// @brief Requestor topic to get Scenario Replay current state. Responds with ScenarioStateResponse.
	namespace TestSolutionTopics
	{
		class ScenarioInfoRequest
		{
		private:
			//None

		public:
			ScenarioInfoRequest() {}

			template<class T>
			void Serialise(T& archive) {}

			LCA_TOPIC("ScenarioInfoRequest", 1, 0)

		};
	}
}
#endif