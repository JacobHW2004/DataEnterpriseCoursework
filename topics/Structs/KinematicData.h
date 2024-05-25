#ifndef KINEMATIC_DATA_H
#define KINEMATIC_DATA_H
namespace Topics {
	namespace SimulationTopics
	{
		struct KinematicData
		{
			float  positionX{ 0.0F };
			float  positionY{ 0.0F };
			float  positionZ{ 0.0F };
			float  velocityX{ 0.0F };
			float  velocityY{ 0.0F };
			float  velocityZ{ 0.0F };
			float  accelerationX{ 0.0F };
			float  accelerationY{ 0.0F };
			float  accelerationZ{ 0.0F };
		};
	}
}
#endif