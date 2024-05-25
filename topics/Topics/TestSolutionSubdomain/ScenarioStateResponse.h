#ifndef SCENARIO_STATE_RESPONSE_H
#define SCENARIO_STATE_RESPONSE_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
	// @brief Response information from ScenarioStateRequest
	namespace TestSolutionTopics
	{
		class ScenarioStateResponse
		{
		private:
			//None

		public:

			/*
			Enum Name | Description
			--------- | ----------------------------------------------
			Error     | Player in an error state it cant get out of
			Idle      | Player started, no scenario loaded
			NotReady  | Player not ready to be interacted with
			Ready     | Scenario loaded, ready to be played or cleared
			Playing   | Scenario playing
			*/
			enum class State : std::uint8_t
			{
				Error,
				Idle,
				NotReady,
				Ready,
				Playing
			};

			State state{ State::Error };

			ScenarioStateResponse() = default;

			ScenarioStateResponse(State scenarioState) : state{ scenarioState } {};

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(state, "state");
			}

			LCA_TOPIC("ScenarioStateResponse", 1, 0)

		};
	}
}
#endif