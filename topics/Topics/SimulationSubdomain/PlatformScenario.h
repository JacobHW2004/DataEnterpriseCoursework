// PlatformScenario.h - Defines the Platform Scenario Topic
#ifndef PLATFORM_SCENARIO_TOPIC_H
#define PLATFORM_SCENARIO_TOPIC_H

#include "Fabric/Utils/LCA_Macros.h"

#include "KinematicData.h"
namespace Topics {
	namespace SimulationTopics 
	{
		class PlatformScenario {

		private:

			KinematicData platformData;

		public:
			PlatformScenario() :
				platformData{  }
			{}

			PlatformScenario(const KinematicData& structPlatformData) :
				platformData{ structPlatformData }
			{}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(platformData.positionX,     "positionX");
				archive.Serialise(platformData.positionY,     "positionY");
				archive.Serialise(platformData.positionZ,     "positionZ");
				archive.Serialise(platformData.velocityX,     "velocityX");
				archive.Serialise(platformData.velocityY,     "velocityY");
				archive.Serialise(platformData.velocityZ,     "velocityZ");
				archive.Serialise(platformData.accelerationX, "accelerationX");
				archive.Serialise(platformData.accelerationY, "accelerationY");
				archive.Serialise(platformData.accelerationZ, "accelerationZ");
			}

			const KinematicData& getPlatformData() const
			{
				return platformData;
			}


			LCA_TOPIC("PlatformScenario", 1, 0)
		};
	}
}
#endif
