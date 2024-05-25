#pragma once
#ifndef STANAG_TRACKER_TRACK_LIST_H
#define STANAG_TRACKER_TRACK_LIST_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Track.h"
#include <cstdint>
#include <vector>

namespace Topics{
	namespace StanagTrackerTopics {

		//Represents the STANAG Tracker Track list as defined in the STANAG Tracker ICD AP50109688
		class TrackList
		{
		private:
			uint16_t commandId{ 0 };
			uint16_t messageSize{ 0 };
			int64_t timestamp{ 0 };
			uint16_t messageNumber{ 0 };
			uint16_t numberOfTracks{ 0 };
			std::vector<Track> tracks{};

		public:
			TrackList() = default;

			TrackList(uint16_t commandId, uint16_t messageSize, uint64_t timestamp, uint16_t messageNumber, uint16_t numberOfTracks, const std::vector<Track>& tracks):
				commandId(commandId),
				messageSize(messageSize),
				timestamp(timestamp),
				messageNumber(messageNumber),
				numberOfTracks(numberOfTracks),
				tracks(tracks){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(commandId, "commandID");
				archive.Serialise(messageSize, "messageSize");
				archive.Serialise(timestamp, "timestamp");
				archive.Serialise(messageNumber, "messageNumber");
				archive.Serialise(numberOfTracks, "numberOfTracks");
				archive.Serialise(tracks, "track", "tracks");
			}

			//Getters
			uint16_t getCommandId() const
			{
				return commandId;
			}

			uint16_t getMessageSize() const
			{
				return messageSize;
			}

			uint64_t getTimestamp() const
			{
				return timestamp;
			}

			uint16_t getMessageNumber() const
			{
				return messageNumber;
			}

			uint16_t getNumberOfTracks() const
			{
				return numberOfTracks;
			}

			const std::vector<Track>& getTracks() const
			{
				return tracks;
			}

			LCA_TOPIC("Topics::StanagTrackerTopics::TrackList", 1, 0);
		};	
	}
}
#endif