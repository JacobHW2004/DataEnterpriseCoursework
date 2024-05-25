#ifndef CONFIGURATION_DATA_H
#define CONFIGURATION_DATA_H

#include <cstdint>
#include <array>
#include "Fabric/Utils/LCA_Macros.h"
#include "SIMinute.h"

namespace Topics
{
	namespace EcrsMK2
	{
		namespace WarmUP
		{
			enum class CONFIG_CONSISTENCY_ENUM : uint8_t
			{
				CONSISTENCY,
				INCONSISTENCY
			};
			enum class CONFIGURATION_DATA_FIELDS_LEN_ENUM
			{
				PART_NO = 3
			};
			/**
			 * @brief LRI-SRI Configuration data type
			 */
			class ConfigurationDataType
			{
			public:
				/**
				 * @brief Set the HARDWARE_PART_NO field of ConfigurationDataType
				 */
				inline void setHardwarePartNo(const uint32_t &aField) noexcept
				{
					HARDWARE_PART_NO = aField;
				}
				/**
				 * @brief Get the HARDWARE_PART_NO field of ConfigurationDataType
				 */
				inline uint32_t getHardwarePartNo() const noexcept
				{
					return HARDWARE_PART_NO;
				}
				/**
				 * @brief Set the HARDWARE_BUILD_STATE field of ConfigurationDataType
				 */
				inline void setHardwareBuildState(const uint8_t &aField) noexcept
				{
					HARDWARE_BUILD_STATE = aField;
				}
				/**
				 * @brief Get the HARDWARE_BUILD_STATE field of ConfigurationDataType
				 */
				inline uint8_t getHardwareBuildState() const noexcept
				{
					return HARDWARE_BUILD_STATE;
				}
				/**
				 * @brief Set the SERIAL_NO field of ConfigurationDataType
				 */
				inline void setSerialNo(const uint16_t &aField) noexcept
				{
					SERIAL_NO = aField;
				}
				/**
				 * @brief Get the SERIAL_NO field of ConfigurationDataType
				 */
				inline uint16_t getSerialNo() const noexcept
				{
					return SERIAL_NO;
				}
				/**
				 * @brief Set the SOFTWARE_PART_NO field of ConfigurationDataType
				 */
				inline void setSwPartNo(const uint32_t &aField) noexcept
				{
					SOFTWARE_PART_NO = aField;
				}
				/**
				 * @brief Get the SOFTWARE_PART_NO field of ConfigurationDataType
				 */
				inline uint32_t getSwPartlNo() const noexcept
				{
					return SOFTWARE_PART_NO;
				}
				/**
				 * @brief Set the SOFTWARE_PART_NO_VERSION field of ConfigurationDataType
				 */
				inline void setSwPartNoVer(const uint8_t &aField) noexcept
				{
					SOFTWARE_PART_NO_VERSION = aField;
				}
				/**
				 * @brief Get the SOFTWARE_PART_NO_VERSION field of ConfigurationDataType
				 */
				inline uint8_t getSwPartlNoVer() const noexcept
				{
					return SOFTWARE_PART_NO_VERSION;
				}
				/**
				 * @brief Set the SOFTWARE_CONFIG_INCONSISTENCY field of ConfigurationDataType
				 */
				inline void setSwCfgInconsistency(const CONFIG_CONSISTENCY_ENUM &aField) noexcept
				{
					SOFTWARE_CONFIG_INCONSISTENCY = aField;
				}
				/**
				 * @brief Get the SOFTWARE_CONFIG_INCONSISTENCY field of ConfigurationDataType
				 */
				inline CONFIG_CONSISTENCY_ENUM getSwCfgInconsistency() const noexcept
				{
					return SOFTWARE_CONFIG_INCONSISTENCY;
				}
				/**
				 * @brief Set the FIRMWARE_VERSION_NO field of ConfigurationDataType
				 */
				inline void setFwVerNo(const uint8_t &aField) noexcept
				{
					FIRMWARE_VERSION_NO = aField;
				}
				/**
				 * @brief Get the FIRMWARE_VERSION_NO field of ConfigurationDataType
				 */
				inline uint8_t getFwVerNo() const noexcept
				{
					return FIRMWARE_VERSION_NO;
				}
				/**
				 * @brief Set the FIRMWARE_REVISION_NO field of ConfigurationDataType
				 */
				inline void setFwRevNo(const uint8_t &aField) noexcept
				{
					FIRMWARE_VERSION_NO = aField;
				}
				/**
				 * @brief Get the FIRMWARE_REVISION_NO field of ConfigurationDataType
				 */
				inline uint8_t getFwRevNo() const noexcept
				{
					return FIRMWARE_VERSION_NO;
				}
				/**
				 * @brief Set the FIRMWARE_RELEASE_DATE_DAY field of ConfigurationDataType
				 */
				inline void setFwReleaseDay(const uint8_t &aField) noexcept
				{
					FIRMWARE_RELEASE_DATE_DAY = aField;
				}
				/**
				 * @brief Get the FIRMWARE_RELEASE_DATE_DAY field of ConfigurationDataType
				 */
				inline uint8_t getFwReleaseDay() const noexcept
				{
					return FIRMWARE_RELEASE_DATE_DAY;
				}
				/**
				 * @brief Set the FIRMWARE_RELEASE_DATE_MONTH field of ConfigurationDataType
				 */
				inline void setFwReleaseMonth(const uint8_t &aField) noexcept
				{
					FIRMWARE_RELEASE_DATE_MONTH = aField;
				}
				/**
				 * @brief Get the FIRMWARE_RELEASE_DATE_MONTH field of ConfigurationDataType
				 */
				inline uint8_t getFwReleaseMonth() const noexcept
				{
					return FIRMWARE_RELEASE_DATE_MONTH;
				}
				/**
				 * @brief Set the FIRMWARE_RELEASE_DATE_YEAR field of ConfigurationDataType
				 */
				inline void setFwReleaseYear(const uint8_t &aField) noexcept
				{
					FIRMWARE_RELEASE_DATE_YEAR = aField;
				}
				/**
				 * @brief Get the FIRMWARE_RELEASE_DATE_YEAR field of ConfigurationDataType
				 */
				inline uint8_t getFwReleaseYear() const noexcept
				{
					return FIRMWARE_RELEASE_DATE_YEAR;
				}
				/**
				 * @brief Set the ELAPSED_TIME_INDICATOR field of ConfigurationDataType
				 */
				inline void setETI(const SI::SIMinute &aField) noexcept
				{
					ELAPSED_TIME_INDICATOR = aField;
				}
				/**
				 * @brief Get the ELAPSED_TIME_INDICATOR field of ConfigurationDataType
				 */
				inline SI::SIMinute getETI() const noexcept
				{
					return ELAPSED_TIME_INDICATOR;
				}
				/**
				 * @brief Set the HARDWARE_MOD_NO field of ConfigurationDataType
				 */
				inline void setHwModNo(const uint8_t &aField) noexcept
				{
					HARDWARE_MOD_NO = aField;
				}
				/**
				 * @brief Get the HARDWARE_MOD_NO field of ConfigurationDataType
				 */
				inline uint8_t getHwModNo() const noexcept
				{
					return HARDWARE_MOD_NO;
				}
				/**
				 * @brief Set the REPAIR_COUNT field of ConfigurationDataType
				 */
				inline void setRepairCount(const uint8_t &aField) noexcept
				{
					REPAIR_COUNT = aField;
				}
				/**
				 * @brief Get the REPAIR_COUNT field of ConfigurationDataType
				 */
				inline uint8_t getRepairCount() const noexcept
				{
					return REPAIR_COUNT;
				}
				/**
				 * @brief ConfigurationDataType template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					double eclipsedTime {ELAPSED_TIME_INDICATOR()};
					archive.Serialise(HARDWARE_PART_NO, "HARDWARE_PART_NO");
					archive.Serialise(HARDWARE_BUILD_STATE, "HARDWARE_BUILD_STATE");
					archive.Serialise(SERIAL_NO, "SERIAL_NO");
					archive.Serialise(SOFTWARE_PART_NO, "SOFTWARE_PART_NO");
					archive.Serialise(SOFTWARE_PART_NO_VERSION, "SOFTWARE_PART_NO_VERSION");
					archive.Serialise(SOFTWARE_CONFIG_INCONSISTENCY, "SOFTWARE_CONFIG_INCONSISTENCY");
					archive.Serialise(FIRMWARE_VERSION_NO, "FIRMWARE_VERSION_NO");
					archive.Serialise(FIRMWARE_REVISION_NO, "FIRMWARE_REVISION_NO");
					archive.Serialise(FIRMWARE_RELEASE_DATE_DAY, "FIRMWARE_RELEASE_DATE_DAY");
					archive.Serialise(FIRMWARE_RELEASE_DATE_MONTH, "FIRMWARE_RELEASE_DATE_MONTH");
					archive.Serialise(FIRMWARE_RELEASE_DATE_YEAR, "FIRMWARE_RELEASE_DATE_YEAR");
					archive.Serialise(eclipsedTime, "ELAPSED_TIME_INDICATOR");
					archive.Serialise(HARDWARE_MOD_NO, "HARDWARE_MOD_NO");
					archive.Serialise(REPAIR_COUNT, "REPAIR_COUNT");
					ELAPSED_TIME_INDICATOR = eclipsedTime;
				}
				/**
				 * @brief ConfigurationDataType equality operator
				 */
				bool operator==(const ConfigurationDataType &other) const
				{
					return (HARDWARE_PART_NO == other.HARDWARE_PART_NO &&
							HARDWARE_BUILD_STATE == other.HARDWARE_BUILD_STATE &&
							SERIAL_NO == other.SERIAL_NO &&
							SOFTWARE_PART_NO == other.SOFTWARE_PART_NO &&
							SOFTWARE_PART_NO_VERSION == other.SOFTWARE_PART_NO_VERSION &&
							SOFTWARE_CONFIG_INCONSISTENCY == other.SOFTWARE_CONFIG_INCONSISTENCY &&
							FIRMWARE_VERSION_NO == other.FIRMWARE_VERSION_NO &&
							FIRMWARE_REVISION_NO == other.FIRMWARE_REVISION_NO &&
							FIRMWARE_RELEASE_DATE_DAY == other.FIRMWARE_RELEASE_DATE_DAY &&
							FIRMWARE_RELEASE_DATE_MONTH == other.FIRMWARE_RELEASE_DATE_MONTH &&
							FIRMWARE_RELEASE_DATE_YEAR == other.FIRMWARE_RELEASE_DATE_YEAR &&
							ELAPSED_TIME_INDICATOR == other.ELAPSED_TIME_INDICATOR &&
							HARDWARE_MOD_NO == other.HARDWARE_MOD_NO &&
							REPAIR_COUNT == other.REPAIR_COUNT);
				}
				/**
				 * @brief ConfigurationDataType inequality operator
				 */
				bool operator!=(const ConfigurationDataType &other) const
				{
					return !(*this == other);
				}

			private:
				uint32_t HARDWARE_PART_NO{0};
				uint8_t HARDWARE_BUILD_STATE{0};
				uint16_t SERIAL_NO{0};
				uint32_t SOFTWARE_PART_NO{0};
				uint8_t SOFTWARE_PART_NO_VERSION{0};
				CONFIG_CONSISTENCY_ENUM SOFTWARE_CONFIG_INCONSISTENCY{CONFIG_CONSISTENCY_ENUM::CONSISTENCY};
				uint8_t FIRMWARE_VERSION_NO{0};
				uint8_t FIRMWARE_REVISION_NO{0};
				uint8_t FIRMWARE_RELEASE_DATE_DAY{0};
				uint8_t FIRMWARE_RELEASE_DATE_MONTH{0};
				uint8_t FIRMWARE_RELEASE_DATE_YEAR{0};
				SI::SIMinute ELAPSED_TIME_INDICATOR{0.0}; // ETI
				uint8_t HARDWARE_MOD_NO{0};
				uint8_t REPAIR_COUNT{0};
			};
			/**
			 * @brief LRI-SRI Configuration data topic
			 */
			class ConfigurationData
			{
			public:
				/**
				 * @brief Set the LRI_CONFIG_DATA field of ConfigurationData
				 */
				inline void setLRICfgData(const ConfigurationDataType &aField) noexcept
				{
					LRI_CONFIG_DATA = aField;
				}
				/**
				 * @brief Get the LRI_CONFIG_DATA field of ConfigurationData
				 */
				inline ConfigurationDataType getLRICfgData() const noexcept
				{
					return LRI_CONFIG_DATA;
				}
				/**
				 * @brief Set the SRI_CONFIG_DATA field of ConfigurationData
				 */
				inline void setSRICfgData(const ConfigurationDataType &aField, uint32_t idx) noexcept
				{
					if (idx < SRI_CONFIG_DATA.size())
					{
						SRI_CONFIG_DATA[idx] = aField;
					}
				}
				/**
				 * @brief Get the SRI_CONFIG_DATA field of ConfigurationData
				 */
				inline bool getSRICfgData(ConfigurationDataType &aField, uint32_t idx) const noexcept
				{
					if (idx < SRI_CONFIG_DATA.size())
					{
						aField = SRI_CONFIG_DATA[idx];
						return true;
					}
					return false;
				}
				/**
				 * @brief ConfigurationData template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					LRI_CONFIG_DATA.Serialise(archive);
					for (ConfigurationDataType &item : SRI_CONFIG_DATA)
					{
						item.Serialise(archive);
					}
				}
				/**
				 * @brief ConfigurationData equality operator
				 */
				bool operator==(const ConfigurationData &other) const
				{
					bool sriConfigDataEqual = true;
					for (uint32_t i = 0; i < SRI_NUM && sriConfigDataEqual == true; ++i)
					{
						if (SRI_CONFIG_DATA[i] != other.SRI_CONFIG_DATA[i])
						{
							sriConfigDataEqual = false;
							break;
						}
					}
					return (sriConfigDataEqual && (LRI_CONFIG_DATA == other.LRI_CONFIG_DATA));
				}
				/**
				 * @brief ConfigurationData inequality operator
				 */
				bool operator!=(const ConfigurationData &other) const
				{
					return !(*this == other);
				}
				LCA_TOPIC("ConfigurationData", 1, 0)
			private:
				static constexpr uint32_t SRI_NUM = 21;
				ConfigurationDataType LRI_CONFIG_DATA;
				std::array<ConfigurationDataType, SRI_NUM> SRI_CONFIG_DATA;
			};
		}
	}
}

#endif