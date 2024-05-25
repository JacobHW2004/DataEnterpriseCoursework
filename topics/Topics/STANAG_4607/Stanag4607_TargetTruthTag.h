#pragma once
#ifndef STANAG_4607_TARGET_TRUTH_TAG_H
#define STANAG_4607_TARGET_TRUTH_TAG_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents bounding data used by the STANAG 4607 format
		class Stanag4607_TargetTruthTag
		{
		private:
			uint8_t application{ 0 };
			uint32_t entity{ 0 };

		public:
			Stanag4607_TargetTruthTag() = default;

			Stanag4607_TargetTruthTag(uint8_t application, uint32_t entity) :
				application(application),
				entity(entity){}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(application, "application");
				archive.Serialise(entity, "entity");
			}

			//Getters & Setters

			uint8_t getApplication() const
			{
				return application;
			}

			void setApplication(uint8_t application)
			{
				this->application = application;
			}

			uint32_t getEntity() const
			{
				return entity;
			}

			void setEntity(uint32_t entity)
			{
				this->entity = entity;
			}	

			LCA_TOPIC("Stanag4607_TargetTruthTag", 1, 0);
		};	
	}
}
#endif