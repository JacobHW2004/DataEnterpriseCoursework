#ifndef SCENARIO_CONTROL_RESPONSE_H
#define SCENARIO_CONTROL_RESPONSE_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
	// @brief Response information for scenario loaded from file
	namespace TestSolutionTopics
	{
		class ScenarioControlResponse
		{
		private:
			//None

		public:

			/*
			Enum Name     | Description                                                         | Response to
			------------- | ------------------------------------------------------------------- | ----------------------
			NoError       | Control requested sucessful                                         | None, Play, Stop, Clear
			NoFileLoaded  | Requested control couldn't be handled, no file loaded               | Play, Clear
			NotReady      | Requested control couldn't be handled, system busy                  | Play, Stop, Clear
			NotPlaying    | Request control couldn't be handled, scenario not currently playing | Stop
			UnknownError  | Error with requested control, not covered by previous errors        | None, Play, Stop, Clear
			*/
			enum class ErrorCode : std::uint8_t
			{
				NoError,
				NoFileLoaded,
				NotReady,
				NotPlaying,
				UnknownError
			};

			ErrorCode errorCode{ ErrorCode::UnknownError };

			std::string errorMessage{ "No Message" };

			ScenarioControlResponse() = default;

			ScenarioControlResponse(ErrorCode setErrorCode) : errorCode{ setErrorCode } {};

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(errorCode, "errorCode");
				archive.Serialise(errorMessage, "errorMessage");
			}
			LCA_TOPIC("ScenarioControlResponse", 1, 0)

		};
	}
}
#endif