#pragma once
#ifndef STANAG_4607_PACKET_SECURITY_H
#define STANAG_4607_PACKET_SECURITY_H

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>
#include <vector>

namespace Topics{
	namespace Stanag4607Topics {
		//Represents packet security data used in the STANAG 4607 format
		class Stanag4607_PacketSecurity
		{
		private:
			uint8_t classification{ 0 };
			std::vector<uint8_t> classSystem{ 0, 0 }; //2 Alphanumeric Characters
			uint16_t code{ 0 };

		public:
			Stanag4607_PacketSecurity() = default;

			Stanag4607_PacketSecurity(uint8_t classification, const std::vector<uint8_t>& classSystem, uint16_t code) :
				classification(classification),
				classSystem(classSystem),
				code(code) {}

			template <class T>
			void Serialise(T& archive)
			{
				archive.Serialise(classification, "classification");
				archive.Serialise(classSystem,"char", "classSystem");
				archive.Serialise(code, "code");
			}

			//Getters & Setters

			uint8_t getClassification() const
			{
				return classification;
			}

			void setClassification(uint8_t classification)
			{
				this->classification = classification;
			}

			std::vector<uint8_t> getClassSystem() const
			{
				return classSystem;
			}

			void setClassSystem(std::vector<uint8_t>& classSystem)
			{
				this->classSystem = classSystem;
			}

			uint16_t getCode() const
			{
				return code;
			}

			void setCode(uint16_t code)
			{
				this->code = code;
			}

			LCA_TOPIC("Stanag4607_PacketSecurity", 1, 0);
		};	
	}
}
#endif