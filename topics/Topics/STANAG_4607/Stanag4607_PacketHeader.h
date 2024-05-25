#pragma once
#ifndef STANAG_4607_PACKET_HEADER_H
#define STANAG_4607_PACKET_HEADER_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Stanag4607_PacketSecurity.h"
#include <cstdint>
#include <vector>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents the packet header defined in the STANAG 4607 Standard (AP50093411 Issue 5)
		class Stanag4607_PacketHeader
		{
		private:
			std::vector<uint8_t> versionId{ 0, 0 }; //2 Alphanumeric characters
			uint32_t packetSize{ 0 };
			std::vector<uint8_t> nationality{ 0, 0 }; //2 Alphanumeric characters
			Stanag4607_PacketSecurity packetSecurity{};
			uint8_t exerciseIndicator{ 0 }; //Enumerated value
			std::vector<uint8_t> platformId{ 0,0,0,0,0,0,0,0,0,0 }; // 10 Alphanumeric characters
			uint32_t missionId{ 0 };
			uint32_t jobId{ 0 };

		public:	
			Stanag4607_PacketHeader() = default;

			Stanag4607_PacketHeader(const std::vector<uint8_t>& versionId, uint32_t packetSize, const std::vector<uint8_t>& nationality, Stanag4607_PacketSecurity packetSecurity,
				uint8_t exerciseIndicator, const std::vector<uint8_t>& platformId, uint32_t missionId, uint32_t jobId) :
				versionId(versionId),
				packetSize(packetSize),
				nationality(nationality),
				packetSecurity(packetSecurity),
				exerciseIndicator(exerciseIndicator),
				platformId(platformId),
				missionId(missionId),
				jobId(jobId) {}

			template<class T>
			void Serialise(T& archive) 
			{
				archive.Serialise(versionId, "char", "versionId");
				archive.Serialise(packetSize, "packetSize");
				archive.Serialise(nationality, "char", "nationality");
				archive.Serialise(packetSecurity, "packetSecurity");
				archive.Serialise(exerciseIndicator, "exerciseIndicator");
				archive.Serialise(platformId, "Id", "platformId");
				archive.Serialise(missionId, "missionId");
				archive.Serialise(jobId, "jobId");
			}

			//Getters and Setters

			std::vector<uint8_t> getVersionId() const
			{
				return versionId;
			}

			void setVersionId(const std::vector<uint8_t>& versionId)
			{
				this->versionId = versionId;
			}

			uint32_t getPacketSize() const
			{
				return packetSize;
			}

			void setPacketSize(uint32_t packetSize)
			{
				this->packetSize = packetSize;
			}

			std::vector<uint8_t> getNationality() const
			{
				return nationality;
			}

			void setNationality(const std::vector<uint8_t>& nationality)
			{
				this->nationality = nationality;
			}

			Stanag4607_PacketSecurity getPacketSecurity() const
			{
				return packetSecurity;
			}

			void setPacketSecurity(Stanag4607_PacketSecurity packetSecurity)
			{
				this->packetSecurity = packetSecurity;
			}

			uint8_t getExerciseIndicator() const
			{ 
				return exerciseIndicator;
			}

			void setExerciseIndicator(uint8_t exerciseIndicator)
			{
				this->exerciseIndicator = exerciseIndicator;
			}

			std::vector<uint8_t> getPlatformId() const
			{  
				return platformId;
			}

			void setPlatformId(const std::vector<uint8_t>& platformId)
			{
				this->platformId = platformId;
			}

			uint32_t getMissionId() const
			{ 
				return missionId;
			}

			void setMissionId(uint32_t missionId)
			{
				this->missionId = missionId;
			}

			uint32_t getJobId() const
			{ 
				return jobId;
			}

			void setJobId(uint32_t jobId)
			{
				this->jobId = jobId;
			}

			LCA_TOPIC("Stanag4607_PacketHeader", 1, 0);
		};
	}
}
#endif