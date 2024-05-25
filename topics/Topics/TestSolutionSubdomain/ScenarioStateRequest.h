#ifndef SCENARIO_STATE_REQUEST_H
#define SCENARIO_STATE_REQUEST_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
	// @brief Requestor topic to get Scenario Replay current state. Responds with ScenarioStateResponse.
	namespace TestSolutionTopics
	{
		class ScenarioStateRequest
		{
		private:
			//None

		public:
			ScenarioStateRequest() = default;

			template<class T>
			void Serialise(T& archive) {}

			LCA_TOPIC("ScenarioStateRequest", 1, 0)

		};
	}
}
#endif