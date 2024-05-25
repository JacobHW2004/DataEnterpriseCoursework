#pragma once
#ifndef STANAG_4607_JOB_DEFINITION_SEGMENT_H
#define STANAG_4607_JOB_DEFINITION_SEGMENT_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>
#include "Stanag4607_SensorId.h"
#include "Stanag4607_Bounding.h"
#include "Stanag4607_NominalSensorPositionUncertainty.h"
#include "Stanag4607_NominalSensorValue.h"

namespace Topics{
	namespace Stanag4607Topics {
		//Represents the job definition segment defined in the STANAG 4607 Standard (AP50093411 Issue 5)
		class Stanag4607_JobDefinitionSegment
		{
		private:
			uint32_t jobId{ 0 };
			Stanag4607_SensorId sensorId{};
			uint8_t targetFilteringFlag{ 0 }; //8 Bit flag val
			uint8_t radarPriority{ 0 };
			Stanag4607_Bounding bounding{};
			uint8_t radarMode{ 0 }; //Enumerated value
			uint16_t nominalRevisitInterval{ 0 };
			Stanag4607_NominalSensorPositionUncertainty nominalSensorPositionUncertainty{};
			Stanag4607_NominalSensorValue nominalSensorValue{};
			uint8_t terrainElevationModelUsed{ 0 };
			uint8_t geoidModelUsed{ 0 };

		public:
			Stanag4607_JobDefinitionSegment() = default;

			Stanag4607_JobDefinitionSegment(uint32_t jobId, Stanag4607_SensorId sensorId, uint8_t targetFilteringFlag, uint8_t radarPriority, Stanag4607_Bounding bounding, uint8_t radarMode, uint16_t nominalRevisitInterval,
				Stanag4607_NominalSensorPositionUncertainty nominalSensorPositionUncertainty, Stanag4607_NominalSensorValue nominalSensorValue, uint8_t terrainElevationModelUsed, uint8_t geoidModelUsed) :
				jobId(jobId),
				sensorId(sensorId),
				targetFilteringFlag(targetFilteringFlag),
				radarPriority(radarPriority),
				bounding(bounding),
				radarMode(radarMode),
				nominalRevisitInterval(nominalRevisitInterval),
				nominalSensorPositionUncertainty(nominalSensorPositionUncertainty),
				nominalSensorValue(nominalSensorValue),
				terrainElevationModelUsed(terrainElevationModelUsed),
				geoidModelUsed(geoidModelUsed){}

			template<class T>
			void Serialise(T& archive) 
			{
				archive.Serialise(jobId, "jobId");
				archive.Serialise(sensorId, "sensorId");
				archive.Serialise(targetFilteringFlag, "targetFilteringFlag");
				archive.Serialise(radarPriority, "radarPriority");
				archive.Serialise(bounding, "bounding");
				archive.Serialise(radarMode, "radarMode");
				archive.Serialise(nominalRevisitInterval, "nominalRevisitInterval");
				archive.Serialise(nominalSensorPositionUncertainty, "nominalSensorPositionUncertainty");
				archive.Serialise(nominalSensorValue, "nominalSensorValue");
				archive.Serialise(terrainElevationModelUsed, "terrainElevationModelUsed");
				archive.Serialise(geoidModelUsed, "geoidModelUsed");
			}

			uint32_t getJobId() const
			{
				return jobId;
			}

			void setJobId(uint32_t jobId)
			{
				this->jobId = jobId;
			}

			Stanag4607_SensorId getSensorId() const
			{
				return sensorId;
			}

			void setSensorId(Stanag4607_SensorId sensorId)
			{
				this->sensorId = sensorId;
			}

			uint8_t getTargetFilteringFlag() const
			{
				return targetFilteringFlag;
			}

			void setTargetFilteringFlag(uint8_t targetFilteringFlag)
			{
				this->targetFilteringFlag = targetFilteringFlag;
			}

			uint8_t getRadarPriority() const
			{ 
				return radarPriority;
			}

			void setRadarPriority(uint8_t radarPriority)
			{
				this->radarPriority = radarPriority;
			}

			Stanag4607_Bounding getBounding() const
			{
				return bounding;
			}

			void setBounding(Stanag4607_Bounding bounding)
			{
				this->bounding = bounding;
			}

			uint8_t getRadarMode() const
			{ 
				return radarMode;
			}

			void setRadarMode(uint8_t radarMode)
			{
				this->radarMode = radarMode;
			}

			uint16_t getNominalRevisitInterval() const
			{ 
				return nominalRevisitInterval;
			}

			void setNominalRevisitInterval(uint16_t nominalRevisitInterval)
			{
				this->nominalRevisitInterval = nominalRevisitInterval;
			}

			Stanag4607_NominalSensorPositionUncertainty getNominalSensorPositionUncertainty() const
			{
				return nominalSensorPositionUncertainty;
			}

			void setNominalSensorPositionUncertainty(Stanag4607_NominalSensorPositionUncertainty nominalSensorPositionUncertainty)
			{
				this->nominalSensorPositionUncertainty = nominalSensorPositionUncertainty;
			}

			Stanag4607_NominalSensorValue getNominalSensorValue() const
			{
				return nominalSensorValue;
			}

			void setNominalSensorValue(Stanag4607_NominalSensorValue nominalSensorValue)
			{
				this->nominalSensorValue = nominalSensorValue;
			}

			uint8_t getTerrainElevationModelUsed() const
			{
				return terrainElevationModelUsed;
			}

			void setTerrainElevationModelUsed(uint8_t terrainElevationModelUsed)
			{
				this->terrainElevationModelUsed = terrainElevationModelUsed;
			}

			uint8_t getGeoidModelUsed() const
			{
				return geoidModelUsed;
			}

			void setGeoidModelUsed(uint8_t geoidModelUsed)
			{
				this->geoidModelUsed = geoidModelUsed;
			}

			LCA_TOPIC("Stanag4607_JobDefinitionSegment", 1, 0);
		};
	}
}
#endif