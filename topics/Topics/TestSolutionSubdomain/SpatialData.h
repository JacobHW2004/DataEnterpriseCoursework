#ifndef SPATIAL_DATA_H
#define SPATIAL_DATA_H

#include <array>
#include "Acceleration.h"
#include "Attitude.h"
#include "Position.h"
#include "Velocity.h"
#include "LatitudeLongitudeAltitude.h"

#include "Fabric/Utils/LCA_Macros.h"


namespace Topics
{
	// @brief Spatial Data for entities loaded from a scenario file
	namespace TestSolutionTopics
	{
		class SpatialData
		{
		public:
			Position position{};
			Velocity velocity{};
			Acceleration acceleration{};
			Attitude attitude{};
			LatitudeLongitudeAltitude latLongAlt{};

			SpatialData() {};

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(position, "position");
				archive.Serialise(velocity, "velocity");
				archive.Serialise(acceleration, "acceleration");
				archive.Serialise(attitude, "attitude");
				archive.Serialise(latLongAlt, "latLongAlt");
			}

			// True if the acceleration, position, velocity, attitude, latitude, longitude and altitude are all equal
			bool operator== (const SpatialData& s) const
			{
				return (acceleration == s.acceleration &&
					position == s.position &&
					velocity == s.velocity &&
					attitude.bank == s.attitude.bank &&
					attitude.heading == s.attitude.heading &&
					attitude.pitch == s.attitude.pitch &&
					attitude.frameOfReference == s.attitude.frameOfReference &&
					latLongAlt.latitude == s.latLongAlt.latitude &&
					latLongAlt.longitude == s.latLongAlt.longitude &&
					latLongAlt.altitude == s.latLongAlt.altitude);
			}

			// True if the acceleration, position, velocity, attitude, latitude, longitude and altitude are not all equal
			bool operator!= (const SpatialData& s) const
			{
				return !(*this == s);
			}

			LCA_TOPIC("SpatialData", 1, 0)
		};
	}
}
#endif
