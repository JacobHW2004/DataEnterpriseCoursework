#ifndef SCENARIO_LOAD_REQUEST_H
#define SCENARIO_LOAD_REQUEST_H

#include "Fabric/Utils/LCA_Macros.h"
#include <string>
namespace Topics
{
	namespace TestSolutionTopics
	{
		class ScenarioLoadRequest
		{
		private:
			// None

		public:
            std::string path{};
			std::string fileName{};

			ScenarioLoadRequest() = default;

			ScenarioLoadRequest(const std::string& path, const std::string& fileName)
			: path(path), 
			  fileName(fileName)
			{}

			template<class T>
			void Serialise(T& archive)
			{
                archive.Serialise(path,             "path");
                archive.Serialise(fileName,			"fileName");
			}

			LCA_TOPIC("ScenarioLoadRequest", 1, 0)
		};
	}
}
#endif //SCENARIO_LOAD_REQUEST_H