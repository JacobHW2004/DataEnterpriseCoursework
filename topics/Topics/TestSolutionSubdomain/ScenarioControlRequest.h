#ifndef SCENARIO_CONTROL_REQUEST_H
#define SCENARIO_CONTROL_REQUEST_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
	// @brief Request a control made to data replay. Responds with ScenarioControlResponse
	namespace TestSolutionTopics
	{
		class ScenarioControlRequest
		{
		private:
			//None

		public:
			enum class Command : std::uint8_t
			{
				None,
				Play,
				Stop,
				Clear
			};

			Command command{ Command::None };

			ScenarioControlRequest() = default;

			ScenarioControlRequest(Command cmd) : command{ cmd } {}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(command, "command");
			}
			LCA_TOPIC("ScenarioControlRequest", 1, 0)

		};
	}
}
#endif