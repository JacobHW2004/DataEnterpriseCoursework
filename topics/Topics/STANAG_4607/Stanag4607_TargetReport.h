#pragma once
#ifndef STANAG_4607_TARGET_REPORT_H
#define STANAG_4607_TARGET_REPORT_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Stanag4607_TargetLocation.h"
#include "Stanag4607_TargetMeasurementUncertainty.h"
#include "Stanag4607_TargetTruthTag.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents target reports used by the STANAG 4607 data format
		class Stanag4607_TargetReport
		{
		private:
			uint16_t mtiReportIndex{ 0 };
			Stanag4607_TargetLocation targetLocation{};
			int16_t targetVelocityLOSComponent{ 0 };
			int16_t targetWrapVelocity{ 0 };
			uint8_t targetSNR{ 0 };
			uint8_t targetClassification{ 0 };
			uint8_t targetClassProbability{ 0 };
			Stanag4607_TargetMeasurementUncertainty targetMeasurementUncertainty{};
			Stanag4607_TargetTruthTag targetTruthTag{};
			int8_t targetRadarCrossSection{ 0 };

		public:
			Stanag4607_TargetReport() = default;

			Stanag4607_TargetReport(uint16_t mtiReportIndex, Stanag4607_TargetLocation targetLocation, int16_t targetVelocityLOSComponent, int16_t targetWrapVelocity, 
				uint8_t targetSNR, uint8_t targetClassification, uint8_t targetClassProbability, Stanag4607_TargetMeasurementUncertainty targetMeasurementUncertainty, 
				Stanag4607_TargetTruthTag targetTruthTag, int8_t targetRadarCrossSection) :
				mtiReportIndex(mtiReportIndex),
				targetLocation(targetLocation),
				targetVelocityLOSComponent(targetVelocityLOSComponent),
				targetWrapVelocity(targetWrapVelocity),
				targetSNR(targetSNR),
				targetClassification(targetClassification),
				targetClassProbability(targetClassProbability),
				targetMeasurementUncertainty(targetMeasurementUncertainty),
				targetTruthTag(targetTruthTag),
				targetRadarCrossSection(targetRadarCrossSection){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(mtiReportIndex, "mtiReportIndex");
				archive.Serialise(targetLocation, "targetLocation");
				archive.Serialise(targetVelocityLOSComponent, "targetVelocityLOSComponent");
				archive.Serialise(targetWrapVelocity, "targetWrapVelocity");
				archive.Serialise(targetSNR, "targetSNR");
				archive.Serialise(targetClassification, "targetClassification");
				archive.Serialise(targetClassProbability, "targetClassProbability");
				archive.Serialise(targetMeasurementUncertainty, "targetMeasurementUncertainty");
				archive.Serialise(targetTruthTag, "targetTruthTag");
				archive.Serialise(targetRadarCrossSection, "targetRadarCrossSection");

			}

			//Getters & Setters

			uint16_t getMtiReportIndex() const
			{
				return mtiReportIndex;
			}

			void setMtiReportIndex(uint16_t mtiReportIndex)
			{
				this->mtiReportIndex = mtiReportIndex;
			}

			Stanag4607_TargetLocation getTargetLocation() const
			{
				return targetLocation;
			}

			void setTargetLocation(Stanag4607_TargetLocation targetLocation)
			{
				this->targetLocation = targetLocation;
			}

			int16_t getTargetVelocityLOSComponent() const
			{
				return targetVelocityLOSComponent;
			}

			void setTargetVelocityLOSComponent(int16_t targetVelocityLOSComponent)
			{
				this->targetVelocityLOSComponent = targetVelocityLOSComponent;
			}

			int16_t getTargetWrapVelocity() const
			{
				return targetWrapVelocity;
			}

			void setTargetWrapVelocity(int16_t targetWrapVelocity)
			{
				this->targetWrapVelocity = targetWrapVelocity;
			}

			uint8_t getTargetSNR() const
			{
				return targetSNR;
			}

			void setTargetSNR(uint8_t targetSNR)
			{
				this->targetSNR = targetSNR;
			}

			uint8_t getTargetClassification() const
			{
				return targetClassification;
			}

			void setTargetClassification(uint8_t targetClassification)
			{
				this->targetClassification = targetClassification;
			}

			uint8_t getTargetClassProbability() const
			{
				return targetClassProbability;
			}

			void setTargetClassProbability(uint8_t targetClassProbability)
			{
				this->targetClassProbability = targetClassProbability;
			}

			Stanag4607_TargetMeasurementUncertainty getTargetMeasurementUncertainty() const
			{
				return targetMeasurementUncertainty;
			}

			void setTargetMeasurementUncertainty(Stanag4607_TargetMeasurementUncertainty targetMeasurementUncertainty)
			{
				this->targetMeasurementUncertainty = targetMeasurementUncertainty;
			}

			Stanag4607_TargetTruthTag getTargetTruthTag() const
			{
				return targetTruthTag;
			}

			void setTargetTruthTag(Stanag4607_TargetTruthTag targetTruthTag)
			{
				this->targetTruthTag = targetTruthTag;
			}

			int8_t getTargetRadarCrossSection() const
			{
				return targetRadarCrossSection;
			}

			void setTargetRadarCrossSection(int8_t targetRadarCrossSection)
			{
				this->targetRadarCrossSection = targetRadarCrossSection;
			}

			LCA_TOPIC("Stanag4607_TargetReport", 1, 0);
		};	
	}
}
#endif