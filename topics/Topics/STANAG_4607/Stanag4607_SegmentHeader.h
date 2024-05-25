#pragma once
#ifndef STANAG_4607_SEGMENT_HEADER_H
#define STANAG_4607_SEGMENT_HEADER_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents the segment header defined in the STANAG 4607 Standard (AP50093411 Issue 5)
		class Stanag4607_SegmentHeader
		{
		public:
			uint8_t segmentType{ 0 };
			uint32_t segmentSize{ 0 };

			Stanag4607_SegmentHeader() = default;
			Stanag4607_SegmentHeader(uint8_t segmentType, uint32_t segmentSize) :
				segmentType(segmentType),
				segmentSize(segmentSize) {}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(segmentType, "versionId");
				archive.Serialise(segmentSize, "packetSize");
			}

			//Getters & Setters

			uint8_t getSegmentType() const
			{
				return segmentType;
			}

			void setSegmentType(uint8_t segmentType)
			{
				this->segmentType = segmentType;
			}

			uint32_t getSegmentSize() const
			{
				return segmentSize;
			}

			void setSegmentSize(uint32_t segmentSize)
			{
				this->segmentSize = segmentSize;
			}

			LCA_TOPIC("Stanag4607_SegmentHeader", 1, 0);
		};
	}
}
#endif