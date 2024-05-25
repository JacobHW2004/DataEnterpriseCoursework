#pragma once
#ifndef STANAG_TRACKER_TRACK_H
#define STANAG_TRACKER_TRACK_H

#include "Fabric/Utils/LCA_Macros.h"
#include "TrackDisplayProperties.h"
#include <cstdint>

namespace Topics{
	namespace StanagTrackerTopics {

		//Represents Track data in the STANAG Tracker Track list as defined in the STANAG Tracker ICD AP50109688
		class Track
		{
		private:
			uint16_t trackId{ 0 };
			uint16_t trackerChannel{ 0 };
			TrackDisplayProperties trackDisplayProperties;

		public:
			Track() = default;

			Track(uint16_t trackId, uint16_t trackerChannel, TrackDisplayProperties trackDisplayProperties):
				trackId(trackId),
				trackerChannel(trackerChannel),
				trackDisplayProperties(trackDisplayProperties) {}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(trackId, "trackId");
				archive.Serialise(trackerChannel, "trackeChannel");
				archive.Serialise(trackDisplayProperties, "trackDisplayProperties");
			}

			//Getters
			uint16_t getTrackId() const
			{
				return trackId;
			}

			uint16_t getTrackerChannel() const
			{
				return trackerChannel;
			}

			const TrackDisplayProperties& getTrackDisplayProperties() const
			{
				return trackDisplayProperties;
			}

			LCA_TOPIC("Topics::StanagTrackerTopics::Track", 1, 0);
		};	
	}
}
#endif