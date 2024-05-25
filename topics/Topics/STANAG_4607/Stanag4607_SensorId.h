#pragma once
#ifndef STANAG_4607_SENSOR_ID_H
#define STANAG_4607_SENSOR_ID_H

#include "Fabric/Utils/LCA_Macros.h"
#include <vector>
#include <cstdint>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents sensor id data used by the STANAG 4607 format
		class Stanag4607_SensorId
		{
		private:
			uint8_t type{ 0 };
			std::vector<uint8_t> model{ 0, 0, 0, 0, 0, 0 }; //6 Alphanumeric Characters

		public:
			Stanag4607_SensorId() = default;

			Stanag4607_SensorId(uint8_t type, const std::vector<uint8_t>& model) :
				type(type),
				model(model) {}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(type, "type");
				archive.Serialise(model, "char", "model");
			}

			//Getters & Setters

			uint8_t getType() const
			{
				return type;
			}

			void setType(uint8_t type)
			{
				this->type = type;
			}

			std::vector<uint8_t> getModel() const
			{
				return model;
			}

			void setModel(const std::vector<uint8_t>& model)
			{
				this->model = model;
			}

			LCA_TOPIC("Stanag4607_SensorId", 1, 0);
		};	
	}
}
#endif