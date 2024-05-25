// TargetScenario.h - Defines the Target Scenario Topic
#ifndef TARGET_SCENARIO_TOPIC_H
#define TARGET_SCENARIO_TOPIC_H

#include "Fabric/Utils/LCA_Macros.h"
#include "KinematicData.h"
#include <array>
namespace Topics {
	namespace SimulationTopics
	{
		class TargetScenario {

		public:
			static constexpr uint8_t MAXIMUM_NUMBER_OF_TARGETS{ 20 };

			TargetScenario() {	}


			TargetScenario(const uint8_t& numberOfTargets, const std::array<KinematicData, MAXIMUM_NUMBER_OF_TARGETS>& targetList) :
				numTargets(numberOfTargets), targets(targetList)
			{
			}


			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(numTargets, "numTargets");

				for (uint8_t target = 0; target < MAXIMUM_NUMBER_OF_TARGETS; target++)
				{
					archive.Serialise(targets[target].positionX,     "positionX[" + std::to_string(target) + "]");
					archive.Serialise(targets[target].positionY,     "positionY[" + std::to_string(target) + "]");
					archive.Serialise(targets[target].positionZ,     "positionZ[" + std::to_string(target) + "]");
					archive.Serialise(targets[target].velocityX,     "velocityX[" + std::to_string(target) + "]");
					archive.Serialise(targets[target].velocityY,     "velocityY[" + std::to_string(target) + "]");
					archive.Serialise(targets[target].velocityZ,     "velocityZ[" + std::to_string(target) + "]");
					archive.Serialise(targets[target].accelerationX, "accelerationX[" + std::to_string(target) + "]");
					archive.Serialise(targets[target].accelerationY, "accelerationY[" + std::to_string(target) + "]");
					archive.Serialise(targets[target].accelerationZ, "accelerationZ[" + std::to_string(target) + "]");
				}
			}


			const uint8_t & getNumTargets() const
			{
				return numTargets;
			};

			const std::array<KinematicData, MAXIMUM_NUMBER_OF_TARGETS> & getTargets() const
			{
				return targets;
			};

			const void setTargets(std::array<KinematicData, MAXIMUM_NUMBER_OF_TARGETS> targetsIn)
			{
				this->targets = targetsIn;
			};

			const void setNumTargets(uint8_t numberOfTargets)
			{
				this->numTargets = numberOfTargets;
			};


			LCA_TOPIC("TargetScenario", 1, 0)

		private:
			uint8_t numTargets{ 0 };
			std::array<KinematicData, MAXIMUM_NUMBER_OF_TARGETS> targets{};
		};
	}
}
#endif
