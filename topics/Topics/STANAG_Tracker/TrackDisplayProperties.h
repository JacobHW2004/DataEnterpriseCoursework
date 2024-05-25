#pragma once
#ifndef STANAG_TRACKER_TRACK_DISPLAY_PROPERTIES_H
#define STANAG_TRACKER_TRACK_DISPLAY_PROPERTIES_H

#include "Fabric/Utils/LCA_Macros.h"
#include "TargetVelocityVector.h"
#include "TargetPositionVector.h"
#include <cstdint>
#include <vector>

namespace Topics{
	namespace StanagTrackerTopics {
		//Represents Track Display Properties as per the STANAG Tracker ICD AP50109688
		class TrackDisplayProperties
		{
		private:
			uint8_t trackAssociationStatus{ 0 };
			uint16_t identity{ 0 };
			std::vector<uint8_t> text{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //15 Alphanumeric Characters
			uint16_t dimension{ 0 };
			uint16_t function{ 0 };
			uint16_t useTrackAsSceneCentre{ 0 };
			int8_t targetRcs{ 0 };
			int8_t targetSnr{ 0 };
			uint8_t trackQuality{ 0 };
			TargetPositionVector targetPositionVector;
			TargetVelocityVector targetVelocityVector;

		public:
			TrackDisplayProperties() = default;

			TrackDisplayProperties(uint8_t trackAssociationStatus, uint16_t identity, const std::vector<uint8_t>& text, uint16_t dimension, uint16_t function, uint16_t useTrackAsSceneCentre,
				int8_t targetRcs, int8_t targetSnr, uint8_t trackQuality, TargetPositionVector targetPositionVector, TargetVelocityVector targetVelocityVector) :
				trackAssociationStatus(trackAssociationStatus),
				identity(identity),
				text(text),
				dimension(dimension),
				function(function),
				useTrackAsSceneCentre(useTrackAsSceneCentre),
				targetRcs(targetRcs),
				targetSnr(targetSnr),
				trackQuality(trackQuality),
				targetPositionVector(targetPositionVector),
				targetVelocityVector(targetVelocityVector){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(trackAssociationStatus, "trackAssociationStatus");
				archive.Serialise(identity, "identity");
				archive.Serialise(text, "char", "text");
				archive.Serialise(dimension, "dimension");
				archive.Serialise(function, "function");
				archive.Serialise(useTrackAsSceneCentre, "useTrackAsSceneCentre");
				archive.Serialise(targetRcs, "targetRcs");
				archive.Serialise(targetSnr, "targetSnr");
				archive.Serialise(trackQuality, "trackQuality");
				archive.Serialise(targetPositionVector, "targetPositionVector");
				archive.Serialise(targetVelocityVector, "targetVelocityVector");
			}

			//Getters
			uint8_t getTrackAssociationStatus() const
			{ 
				return trackAssociationStatus;
			}

			uint16_t getIdentity() const
			{
				return identity;
			}

			const std::vector<uint8_t>& getText() const
			{
				return text;
			}

			uint16_t getDimension() const
			{
				return dimension;
			}

			uint16_t getFunction() const
			{
				return function;
			}

			uint16_t getUseTrackAsSceneCentre() const
			{
				return useTrackAsSceneCentre;
			}

			int8_t getTargetRcs() const
			{
				return targetRcs;
			}

			int8_t getTargetSnr() const
			{
				return targetSnr;
			}

			uint8_t getTrackQuality() const
			{
				return trackQuality;
			}

			const TargetPositionVector& getTargetPositionVector() const
			{
				return targetPositionVector;
			}
			
			const TargetVelocityVector& getTargetVelocityVector() const
			{
				return targetVelocityVector;
			}			

			LCA_TOPIC("Topics::StanagTrackerTopics::TrackDisplayProperties", 1, 0);
		};	
	}
}
#endif