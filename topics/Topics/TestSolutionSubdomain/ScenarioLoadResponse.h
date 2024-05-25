#ifndef SCENARIO_LOAD_RESPONSE_H
#define SCENARIO_LOAD_RESPONSE_H

#include "Fabric/Utils/LCA_Macros.h"
#include <string>

namespace Topics
{
	namespace TestSolutionTopics
	{
		class ScenarioLoadResponse
		{
		private:
			// None

		public:

			/*
			Enum Name     | Description
			------------- | ----------------------------------------------------------
			NoError       | File load successful and file valid
			FileNotFound  | The requested file was not found at the location
			FileInvalid   | The requested file was found but is not in valid struture
			UnknownError  | An error occured not captured by above errors
			*/
			enum class ErrorCode : std::uint8_t
			{
				NoError,
				FileNotFound,
				FileInvalid,
				UnknownError
			};

			ErrorCode errorCode{ ErrorCode::NoError };
			std::string errorMessage{ "No Message" };

			ScenarioLoadResponse() = default;

			template<class T>
			void Serialise(T& archive)
			{
                archive.Serialise(errorCode, "errorCode");
				archive.Serialise(errorMessage, "errorMessage");
			}

			LCA_TOPIC("ScenarioLoadResponse", 1, 0)
		};
	}
}
#endif//SCENARIO_LOAD_RESPONSE_H