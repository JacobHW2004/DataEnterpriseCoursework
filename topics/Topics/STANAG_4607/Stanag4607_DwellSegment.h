#pragma once
#ifndef STANAG_4607_DWELL_SEGMENT_H
#define STANAG_4607_DWELL_SEGMENT_H

#include "Fabric/Utils/LCA_Macros.h"
#include "BA16_Angle.h"
#include "Stanag4607_PlatformOrientation.h"
#include "Stanag4607_DwellArea.h"
#include "Stanag4607_SensorPosition.h"
#include "Stanag4607_TargetReport.h"
#include "Stanag4607_ScaleFactor.h"
#include "Stanag4607_SensorPositionUncertainty.h"
#include "Stanag4607_SensorOrientation.h"
#include <cstdint>
#include <vector>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents the dwell segment defined in the STANAG 4607 Standard (AP50093411 Issue 5)
		class Stanag4607_DwellSegment
		{
		private:
			uint64_t existenceMask{ 0 }; //64 Bits of Flags
			uint16_t revisitIndex{ 0 };
			uint16_t dwellIndex{ 0 };
			uint8_t lastDwellOfRevisit{ 0 }; //8 Bit Flag Val
			uint16_t targetReportCount{ 0 };
			uint32_t dwellTime{ 0 };
			Stanag4607_SensorPosition sensorPosition{};
			Stanag4607_ScaleFactor scaleFactor{};
			Stanag4607_SensorPositionUncertainty sensorPositionUncertainty{};
			BA16_Angle sensorTrack{};
			uint32_t sensorSpeed{ 0 };
			int8_t sensorVerticalVelocity{ 0 };
			uint8_t sensorTrackUncertainty{ 0 };
			uint16_t sensorSpeedUncertainty{ 0 };
			Stanag4607_PlatformOrientation platformOrientation{};
			uint16_t sensorVerticalVelocityUncertainty{ 0 };		
			Stanag4607_DwellArea dwellArea{};
			Stanag4607_SensorOrientation sensorOrientation{};
			uint8_t minimumDetectableVelocity{ 0 };
			std::vector<Stanag4607_TargetReport> targetReports{};	
		
		public:
			Stanag4607_DwellSegment() = default;

			Stanag4607_DwellSegment(uint64_t existenceMask, uint16_t revisitIndex, uint16_t dwellIndex, uint8_t lastDwellOfRevisit, uint16_t targetReportCount,	uint32_t dwellTime, 
				Stanag4607_SensorPosition sensorPosition, Stanag4607_ScaleFactor scaleFactor, Stanag4607_SensorPositionUncertainty sensorPositionUncertainty, BA16_Angle sensorTrack, 
				uint32_t sensorSpeed, int8_t sensorVerticalVelocity, uint8_t sensorTrackUncertainty, uint16_t sensorSpeedUncertainty, uint16_t sensorVerticalVelocityUncertainty, 
				Stanag4607_PlatformOrientation platformOrientation, Stanag4607_DwellArea dwellArea, Stanag4607_SensorOrientation sensorOrientation, uint8_t minimumDetectableVelocity, 
				const std::vector<Stanag4607_TargetReport>& targetReports) :
				existenceMask(existenceMask),
				revisitIndex(revisitIndex),
				dwellIndex(dwellIndex),
				lastDwellOfRevisit(lastDwellOfRevisit),
				targetReportCount(targetReportCount),
				dwellTime(dwellTime),
				sensorPosition(sensorPosition),
				scaleFactor(scaleFactor),
				sensorPositionUncertainty(sensorPositionUncertainty),
				sensorTrack(sensorTrack),
				sensorSpeed(sensorSpeed),
				sensorVerticalVelocity(sensorVerticalVelocity),
				sensorTrackUncertainty(sensorTrackUncertainty),
				sensorSpeedUncertainty(sensorSpeedUncertainty),
				platformOrientation(platformOrientation),
				sensorVerticalVelocityUncertainty(sensorVerticalVelocityUncertainty),
				dwellArea(dwellArea),
				sensorOrientation(sensorOrientation),
				minimumDetectableVelocity(minimumDetectableVelocity),
				targetReports(targetReports) {}

			template<class T>
			void Serialise(T& archive)
			{
				archive.Serialise(existenceMask, "existenceMask");
				archive.Serialise(revisitIndex, "revisitIndex");
				archive.Serialise(dwellIndex, "dwellIndex");
				archive.Serialise(lastDwellOfRevisit, "lastDwellOfRevisit");
				archive.Serialise(targetReportCount, "targetReportCount");
				archive.Serialise(dwellTime, "dwellTime");
				archive.Serialise(sensorPosition, "sensorPosition");
				archive.Serialise(scaleFactor, "scaleFactor");
				archive.Serialise(sensorPositionUncertainty, "sensorPositionUncertainty");
				archive.Serialise(sensorTrack, "sensorTrack");
				archive.Serialise(sensorSpeed, "sensorSpeed");
				archive.Serialise(sensorVerticalVelocity, "sensorVerticalVelocity");
				archive.Serialise(sensorTrackUncertainty, "sensorTrackUncertainty");
				archive.Serialise(sensorSpeedUncertainty, "sensorSpeedUncertainty");
				archive.Serialise(sensorVerticalVelocityUncertainty, "sensorVerticalVelocityUncertainty");
				archive.Serialise(platformOrientation, "platformOrientation");
				archive.Serialise(dwellArea, "dwellArea");
				archive.Serialise(sensorOrientation, "sensorOrientation");
				archive.Serialise(minimumDetectableVelocity, "minimumDetectableVelocity");
				archive.Serialise(targetReports, "targetReport", "TargetReports");
			}

			//Getters & Setters

			uint64_t getExistenceMask() const
			{
				return existenceMask;
			}

			void setExistenceMask(uint64_t existenceMask)
			{
				this->existenceMask = existenceMask;
			}

			uint16_t getRevisitIndex() const
			{
				return revisitIndex;
			}

			void setRevisitIndex(uint16_t revisitIndex)
			{
				this->revisitIndex = revisitIndex;
			}

			uint16_t getDwellIndex() const
			{
				return dwellIndex;
			}

			void setDwellIndex(uint16_t dwellIndex)
			{
				this->dwellIndex = dwellIndex;
			}

			uint8_t getLastDwellOfRevisit() const
			{
				return lastDwellOfRevisit;
			}

			void setLastDwellOfRevisit(uint8_t lastDwellOfRevisit)
			{
				this->lastDwellOfRevisit = lastDwellOfRevisit;
			}

			uint16_t getTargetReportCount() const
			{
				return targetReportCount;
			}

			void setTargetReportCount(uint16_t targetReportCount)
			{
				this->targetReportCount = targetReportCount;
			}

			uint32_t getDwellTime() const
			{
				return dwellTime;
			}

			void setDwellTime(uint32_t dwellTime)
			{
				this->dwellTime = dwellTime;
			}

			Stanag4607_SensorPosition getSensorPosition() const
			{
				return sensorPosition;
			}

			void setSensorPosition(Stanag4607_SensorPosition sensorPosition)
			{
				this->sensorPosition = sensorPosition;
			}

			Stanag4607_ScaleFactor getScaleFactor() const
			{
				return scaleFactor;
			}

			void setScaleFactor(Stanag4607_ScaleFactor scaleFactor)
			{
				this->scaleFactor = scaleFactor;
			}

			Stanag4607_SensorPositionUncertainty getSensorPositionUncertainty() const
			{
				return sensorPositionUncertainty;
			}

			void setSensorPositionUncertainty(Stanag4607_SensorPositionUncertainty sensorPositionUncertainty)
			{
				this->sensorPositionUncertainty = sensorPositionUncertainty;
			}

			BA16_Angle getSensorTrack() const
			{
				return sensorTrack;
			}

			void setSensorTrack(BA16_Angle sensorTrack)
			{
				this->sensorTrack = sensorTrack;
			}

			uint32_t getSensorSpeed() const
			{
				return sensorSpeed;
			}

			void setSensorSpeed(uint32_t sensorSpeed)
			{
				this->sensorSpeed = sensorSpeed;
			}

			int8_t getSensorVerticalVelocity() const
			{
				return sensorVerticalVelocity;
			}

			void setSensorVerticalVelocity(int8_t sensorVerticalVelocity)
			{
				this->sensorVerticalVelocity = sensorVerticalVelocity;
			}

			uint8_t getSensorTrackUncertainty() const
			{
				return sensorTrackUncertainty;
			}

			void setSensorTrackUncertainty(uint8_t sensorTrackUncertainty)
			{
				this->sensorTrackUncertainty = sensorTrackUncertainty;
			}

			uint16_t getSensorSpeedUncertainty() const
			{
				return sensorSpeedUncertainty;
			}

			void setSensorSpeedUncertainty(uint16_t sensorSpeedUncertainty)
			{
				this->sensorSpeedUncertainty = sensorSpeedUncertainty;
			}

			uint16_t getSensorVerticalVelocityUncertainty() const
			{
				return sensorVerticalVelocityUncertainty;
			}

			void setSensorVerticalVelocityUncertainty(uint16_t sensorVerticalVelocityUncertainty)
			{
				this->sensorVerticalVelocityUncertainty = sensorVerticalVelocityUncertainty;
			}

			Stanag4607_PlatformOrientation getPlatformOrientation() const
			{
				return platformOrientation;
			}

			void setPlatformOrientation(Stanag4607_PlatformOrientation platformOrientation)
			{
				this->platformOrientation = platformOrientation;
			}

			Stanag4607_DwellArea getDwellArea() const
			{
				return dwellArea;
			}

			void setDwellArea(Stanag4607_DwellArea dwellArea)
			{
				this->dwellArea = dwellArea;
			}

			Stanag4607_SensorOrientation getSensorOrientation() const
			{
				return sensorOrientation;
			}

			void setSensorOrientation(Stanag4607_SensorOrientation sensorOrientation)
			{
				this->sensorOrientation = sensorOrientation;
			}

			uint8_t getMinimumDetectableVelocity() const
			{  
				return minimumDetectableVelocity;		
			}

			void setMinimumDetectableVelocity(uint8_t minimumDetectableVelocity)
			{
				this->minimumDetectableVelocity = minimumDetectableVelocity;
			}

			std::vector<Stanag4607_TargetReport> getTargetReports() const
			{
				return targetReports;
			}

			void setTargetReports(const std::vector<Stanag4607_TargetReport>& targetReports)
			{
				this->targetReports = targetReports;
			}

			LCA_TOPIC("Stanag4607_DwellSegment", 1, 0);
		};
	}
}
#endif