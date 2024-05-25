#ifndef CYCLIC_MAINTENANCE_MESSAGE_H
#define CYCLIC_MAINTENANCE_MESSAGE_H

#include <cstdint>
#include "SIHour.h"
#include "SIMilliSecond.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
	namespace EcrsMK2
	{
		namespace WarmUP
		{
			enum class RADAR29_IPU_HAT_STATTAG_ENUM : uint16_t
			{
				INVALID,
				VALID = 0x8033
			};
			/* 2.5, 12.5, 22.5, 32.5, 42.5, 52.5 */
			enum class LRI_DATABUS_IDENT_ENUM : uint8_t
			{
				RADAR,
				AVIONICS,
				ATTACK,
				COCKPIT,
				DASS,
				UCS,
				FCS,
				WEAPONS
			};

			enum class BC_DETECTED_FAILURE_ENUM : uint8_t
			{
				NO_BC_DETECTED_FAILURE,
				BC_DETECTED_FAILURE
			};

			enum class EQUIP_IDENT_ENUM : uint8_t
			{
				SINGLE_LRI,
				LRI1,
				LRI2,
				LRI3,
				LRI4,
				LRI5,
				LRI6,
				SPARE
			};
			/* 3.0, 13.0, 23.0, 33.0, 43.0, 53.0 */
			enum class SRI_LRI_IDENTIFIER_ENUM : uint8_t
			{
				LRI_LEVEL,
				SRI_LEVEL
			};

			enum LRI_HW_IDENTIFICATION_ENUM : uint8_t
			{
				E_SCAN_ANTENNA_RADAR = 0xB1,
				E_SCAN_PROCESSOR_RADAR = 0xB2,
				E_SCAN_AAU_RADAR = 0xB3,
				E_SCAN_APSC_RADAR = 0xB4,
				E_SCAN_RECEIVER_RADAR = 0xB5,
				M_SCAN_SCANNER_RADAR = 0xF2,
				M_SCAN_PROCESSOR_RADAR = 0xF3,
				M_SCAN_TX_AUX_UNIT_RADAR = 0xF4,
				M_SCAN_TX_PWR_AMP_RADAR = 0xF5,
				M_SCAN_RECEIVER_RADAR = 0xF6,
				M_SCAN_WG_UNIT_RADAR = 0xF7
			};

			enum class BIT_IDENT_ENUM : uint8_t
			{
				NO_FAIL,
				PBIT,
				IBIT,
				APSW,
				CBIT
			};

			enum class LRI_NO_ENUM : uint8_t
			{
				RESERVED,
				ITEM_1_ANTENNA_SCANNER,
				ITEM_2_PROCESSOR,
				ITEM_3_TAU_AAU,
				ITEM_4_TPA_APSC,
				ITEM_5_RECEIVER,
				ITEM_6_WGU,
				IFF_INTERROGATOR = 0xB
			};

			enum class E_RDR_LIVE_STATUS_ENUM : uint8_t
			{
				UNKNOWN,
				SPARE_0,
				BUS_HEALTH_TEST_OR_IBIT_IN_PROGRESS,
				SPARE_1,
				TEST_FAILED,
				TEST_PASSED = 0x0E,
				SPARE_2 = 0x0f
			};

			enum class RADAR_HEALTHFILE_DWNLD_STATUS_ENUM : uint8_t
			{
				NOT_REQUESTED,
				INVALID_REQUES,
				DWNLD_IN_PROGRESS,
				DWNLD_COMPLETE
			};
			enum class RADAR_LIVE_RT_STATUS_IMPLTD_ENUM : uint8_t
			{
				IMPLEMENTED,
				SPARE,
				NOT_IMPLEMENTED
			};

			using AFFECTED_ITEM_t = uint8_t;
			using AFFECTED_SRI_t = uint8_t;
			/**
			 * @brief System Maintenance Block type
			 */
			class SystemMaintenanceBlock
			{
			public:
				/**
				 * @brief Set the PROC_RT_ADDRESS field of SystemMaintenanceBlock
				 */
				inline void setProcRTAddr(const uint8_t &aField) noexcept
				{
					PROC_RT_ADDRESS = aField;
				}
				/**
				 * @brief Get the PROC_RT_ADDRESS field of SystemMaintenanceBlock
				 */
				inline uint8_t getProcRTAddr() const noexcept
				{
					return PROC_RT_ADDRESS;
				}
				/**
				 * @brief Set the LRI_DATABUS_IDENT field of SystemMaintenanceBlock
				 */
				inline void setLRIDatabusIdent(const LRI_DATABUS_IDENT_ENUM &aField) noexcept
				{
					LRI_DATABUS_IDENT = aField;
				}
				/**
				 * @brief Get the LRI_DATABUS_IDENT field of SystemMaintenanceBlock
				 */
				inline LRI_DATABUS_IDENT_ENUM getLRIDatabusIdent() const noexcept
				{
					return LRI_DATABUS_IDENT;
				}
				/**
				 * @brief Set the BC_DETECTED_FAILURE field of SystemMaintenanceBlock
				 */
				inline void setBCDetectedFail(const BC_DETECTED_FAILURE_ENUM &aField) noexcept
				{
					BC_DETECTED_FAILURE = aField;
				}
				/**
				 * @brief Get the BC_DETECTED_FAILURE field of SystemMaintenanceBlock
				 */
				inline BC_DETECTED_FAILURE_ENUM getBCDetectedFail() const noexcept
				{
					return BC_DETECTED_FAILURE;
				}
				/**
				 * @brief Set the EQUIP_IDENT field of SystemMaintenanceBlock
				 */
				inline void setEquipIdent(const EQUIP_IDENT_ENUM &aField) noexcept
				{
					EQUIP_IDENT = aField;
				}
				/**
				 * @brief Get the EQUIP_IDENT field of SystemMaintenanceBlock
				 */
				inline EQUIP_IDENT_ENUM getEquipIdent() const noexcept
				{
					return EQUIP_IDENT;
				}
				/**
				 * @brief Set the SYS_REPORT_COUNT field of SystemMaintenanceBlock
				 */
				inline void setSysReportCount(const uint8_t &aField) noexcept
				{
					SYS_REPORT_COUNT = aField;
				}
				/**
				 * @brief Get the SYS_REPORT_COUNT field of SystemMaintenanceBlock
				 */
				inline uint8_t getSysReportCount() const noexcept
				{
					return SYS_REPORT_COUNT;
				}
				/**
				 * @brief Set the SRI_LRI_IDENTIFIER field of SystemMaintenanceBlock
				 */
				inline void setSRILRIIdent(const SRI_LRI_IDENTIFIER_ENUM &aField) noexcept
				{
					SRI_LRI_IDENTIFIER = aField;
				}
				/**
				 * @brief Get the SRI_LRI_IDENTIFIER field of SystemMaintenanceBlock
				 */
				inline SRI_LRI_IDENTIFIER_ENUM getSRILRIIdent() const noexcept
				{
					return SRI_LRI_IDENTIFIER;
				}
				/**
				 * @brief Set the AFFECTED_ITEM_1 field of SystemMaintenanceBlock
				 */
				inline void setAffectedItem1(const AFFECTED_ITEM_t &aField) noexcept
				{
					AFFECTED_ITEM_1 = aField;
				}
				/**
				 * @brief Get the AFFECTED_ITEM_1 field of SystemMaintenanceBlock
				 */
				inline AFFECTED_ITEM_t getAffectedItem1() const noexcept
				{
					return AFFECTED_ITEM_1;
				}
				/**
				 * @brief Set the AFFECTED_ITEM_2 field of SystemMaintenanceBlock
				 */
				inline void setAffectedItem2(const AFFECTED_ITEM_t &aField) noexcept
				{
					AFFECTED_ITEM_2 = aField;
				}
				/**
				 * @brief Get the AFFECTED_ITEM_2 field of SystemMaintenanceBlock
				 */
				inline AFFECTED_ITEM_t getAffectedItem2() const noexcept
				{
					return AFFECTED_ITEM_2;
				}
				/**
				 * @brief Set the AFFECTED_ITEM_2 field of SystemMaintenanceBlock
				 */
				inline void setAffectedItem3(const AFFECTED_ITEM_t &aField) noexcept
				{
					AFFECTED_ITEM_3 = aField;
				}
				/**
				 * @brief Get the AFFECTED_ITEM_2 field of SystemMaintenanceBlock
				 */
				inline AFFECTED_ITEM_t getAffectedItem3() const noexcept
				{
					return AFFECTED_ITEM_3;
				}
				/**
				 * @brief Set the LRI_ETI field of SystemMaintenanceBlock
				 */
				inline void setLRIEti(const SI::SIHour &aField) noexcept
				{
					LRI_ETI = aField;
				}
				/**
				 * @brief Get the LRI_ETI field of SystemMaintenanceBlock
				 */
				inline SI::SIHour getLRIEti() const noexcept
				{
					return LRI_ETI;
				}
				/**
				 * @brief Set the LRI_SERIAL_NUMBER field of SystemMaintenanceBlock
				 */
				inline void setLRISerialNumber(const uint16_t &aField) noexcept
				{
					LRI_SERIAL_NUMBER = aField;
				}
				/**
				 * @brief Get the LRI_SERIAL_NUMBER field of SystemMaintenanceBlock
				 */
				inline uint16_t getLRISerialNumber() const noexcept
				{
					return LRI_SERIAL_NUMBER;
				}
				/**
				 * @brief Set the LRI_HW_IDENTIFICATION field of SystemMaintenanceBlock
				 */
				inline void setLRIHwIdent(const LRI_HW_IDENTIFICATION_ENUM &aField) noexcept
				{
					LRI_HW_IDENTIFICATION = aField;
				}
				/**
				 * @brief Get the LRI_HW_IDENTIFICATION field of SystemMaintenanceBlock
				 */
				inline LRI_HW_IDENTIFICATION_ENUM getLRILRIHwIdent() const noexcept
				{
					return LRI_HW_IDENTIFICATION;
				}
				/**
				 * @brief Set the LRI_HW_VERSION field of SystemMaintenanceBlock
				 */
				inline void setLRIHwVersion(const uint8_t &aField) noexcept
				{
					LRI_HW_VERSION = aField;
				}
				/**
				 * @brief Get the LRI_HW_VERSION field of SystemMaintenanceBlock
				 */
				inline uint8_t getLRIHwVersion() const noexcept
				{
					return LRI_HW_VERSION;
				}
				/**
				 * @brief Set the LRI_SW_VERSION_1 field of SystemMaintenanceBlock
				 */
				inline void setLRISwVersion1(const uint8_t &aField) noexcept
				{
					LRI_SW_VERSION_1 = aField;
				}
				/**
				 * @brief Get the LRI_HW_VERSION_1 field of SystemMaintenanceBlock
				 */
				inline uint8_t getLRISwVersion1() const noexcept
				{
					return LRI_SW_VERSION_1;
				}
				/**
				 * @brief Set the LRI_SW_VERSION_2 field of SystemMaintenanceBlock
				 */
				inline void setLRISwVersion2(const uint8_t &aField) noexcept
				{
					LRI_SW_VERSION_2 = aField;
				}
				/**
				 * @brief Get the LRI_HW_VERSION_2 field of SystemMaintenanceBlock
				 */
				inline uint8_t getLRISwVersion2() const noexcept
				{
					return LRI_SW_VERSION_2;
				}
				/**
				 * @brief Set the BIT_IDENT field of SystemMaintenanceBlock
				 */
				inline void setBITIdent(const BIT_IDENT_ENUM &aField) noexcept
				{
					BIT_IDENT = aField;
				}
				/**
				 * @brief Get the BIT_IDENT field of SystemMaintenanceBlock
				 */
				inline BIT_IDENT_ENUM getBITIdent() const noexcept
				{
					return BIT_IDENT;
				}
				/**
				 * @brief Set the FAILURE_IDENTIFICATION_CODE field of SystemMaintenanceBlock
				 */
				inline void setFailureIdentCode(const uint16_t &aField) noexcept
				{
					FAILURE_IDENTIFICATION_CODE = aField;
				}
				/**
				 * @brief Get the FAILURE_IDENTIFICATION_CODE field of SystemMaintenanceBlock
				 */
				inline uint16_t getFailureIdentCode() const noexcept
				{
					return FAILURE_IDENTIFICATION_CODE;
				}
				/**
				 * @brief Set the TIME_OF_OCCURRENCE field of SystemMaintenanceBlock
				 */
				inline void setTimeOfOccurrence(const SI::SIMilliSecond &aField) noexcept
				{
					TIME_OF_OCCURRENCE = aField;
				}
				/**
				 * @brief Get the TIME_OF_OCCURRENCE field of SystemMaintenanceBlock
				 */
				inline SI::SIMilliSecond getTimeOfOccurrence() const noexcept
				{
					return TIME_OF_OCCURRENCE;
				}
				/**
				 * @brief Set the ADDITIONAL_DATA_1 field of SystemMaintenanceBlock
				 */
				inline void setAdditionalData1(const uint16_t &aField) noexcept
				{
					ADDITIONAL_DATA_1 = aField;
				}
				/**
				 * @brief Get the ADDITIONAL_DATA_1 field of SystemMaintenanceBlock
				 */
				inline uint16_t getAdditionalData1() const noexcept
				{
					return ADDITIONAL_DATA_1;
				}
				/**
				 * @brief Set the ADDITIONAL_DATA_2 field of SystemMaintenanceBlock
				 */
				inline void setAdditionalData2(const uint16_t &aField) noexcept
				{
					ADDITIONAL_DATA_2 = aField;
				}
				/**
				 * @brief Get the ADDITIONAL_DATA_2 field of SystemMaintenanceBlock
				 */
				inline uint16_t getAdditionalData2() const noexcept
				{
					return ADDITIONAL_DATA_2;
				}
				/**
				 * @brief SystemMaintenanceBlock template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					double lriEti {LRI_ETI()};
					double timeOfOccurance {TIME_OF_OCCURRENCE()};
					archive.Serialise(PROC_RT_ADDRESS, "PROC_RT_ADDRESS");
					archive.Serialise(LRI_DATABUS_IDENT, "LRI_DATABUS_IDENT");
					archive.Serialise(BC_DETECTED_FAILURE, "BC_DETECTED_FAILURE");
					archive.Serialise(EQUIP_IDENT, "EQUIP_IDENT");
					archive.Serialise(SYS_REPORT_COUNT, "SYS_REPORT_COUNT");
					archive.Serialise(SRI_LRI_IDENTIFIER, "SRI_LRI_IDENTIFIER");
					archive.Serialise(AFFECTED_ITEM_1, "AFFECTED_ITEM_1");
					archive.Serialise(AFFECTED_ITEM_2, "AFFECTED_ITEM_2");
					archive.Serialise(AFFECTED_ITEM_3, "AFFECTED_ITEM_3");
					archive.Serialise(lriEti, "LRI_ETI");
					archive.Serialise(LRI_SERIAL_NUMBER, "LRI_SERIAL_NUMBER");
					archive.Serialise(LRI_HW_IDENTIFICATION, "LRI_HW_IDENTIFICATION");
					archive.Serialise(LRI_HW_VERSION, "LRI_HW_VERSION");
					archive.Serialise(LRI_SW_VERSION_1, "LRI_SW_VERSION_1");
					archive.Serialise(LRI_SW_VERSION_2, "LRI_SW_VERSION_2");
					archive.Serialise(BIT_IDENT, "BIT_IDENT");
					archive.Serialise(FAILURE_IDENTIFICATION_CODE, "FAILURE_IDENTIFICATION_CODE");
					archive.Serialise(timeOfOccurance, "TIME_OF_OCCURRENCE");
					archive.Serialise(ADDITIONAL_DATA_1, "ADDITIONAL_DATA_1");
					archive.Serialise(ADDITIONAL_DATA_2, "ADDITIONAL_DATA_2");
					LRI_ETI = lriEti;
					TIME_OF_OCCURRENCE = timeOfOccurance;
				}
				/**
				 * @brief SystemMaintenanceBlock equality operator
				 */
				bool operator==(const SystemMaintenanceBlock &other) const
				{
					return (PROC_RT_ADDRESS == other.PROC_RT_ADDRESS &&
							LRI_DATABUS_IDENT == other.LRI_DATABUS_IDENT &&
							BC_DETECTED_FAILURE == other.BC_DETECTED_FAILURE &&
							EQUIP_IDENT == other.EQUIP_IDENT &&
							SYS_REPORT_COUNT == other.SYS_REPORT_COUNT &&
							SRI_LRI_IDENTIFIER == other.SRI_LRI_IDENTIFIER &&
							AFFECTED_ITEM_1 == other.AFFECTED_ITEM_1 &&
							AFFECTED_ITEM_2 == other.AFFECTED_ITEM_2 &&
							AFFECTED_ITEM_3 == other.AFFECTED_ITEM_3 &&
							LRI_ETI == other.LRI_ETI &&
							LRI_SERIAL_NUMBER == other.LRI_SERIAL_NUMBER &&
							LRI_HW_IDENTIFICATION == other.LRI_HW_IDENTIFICATION &&
							LRI_HW_VERSION == other.LRI_HW_VERSION &&
							LRI_SW_VERSION_1 == other.LRI_SW_VERSION_1 &&
							LRI_SW_VERSION_2 == other.LRI_SW_VERSION_2 &&
							BIT_IDENT == other.BIT_IDENT &&
							FAILURE_IDENTIFICATION_CODE == other.FAILURE_IDENTIFICATION_CODE &&
							TIME_OF_OCCURRENCE == other.TIME_OF_OCCURRENCE &&
							ADDITIONAL_DATA_1 == other.ADDITIONAL_DATA_1 &&
							ADDITIONAL_DATA_2 == other.ADDITIONAL_DATA_2);
				}
				/**
				 * @brief SystemMaintenanceBlock inequality operator
				 */
				bool operator!=(const SystemMaintenanceBlock &other) const
				{
					return !(*this == other);
				}

			private:
				uint8_t PROC_RT_ADDRESS{0};
				LRI_DATABUS_IDENT_ENUM LRI_DATABUS_IDENT{LRI_DATABUS_IDENT_ENUM::RADAR};
				BC_DETECTED_FAILURE_ENUM BC_DETECTED_FAILURE{BC_DETECTED_FAILURE_ENUM::NO_BC_DETECTED_FAILURE};
				EQUIP_IDENT_ENUM EQUIP_IDENT{EQUIP_IDENT_ENUM::SINGLE_LRI};
				uint8_t SYS_REPORT_COUNT{0};
				SRI_LRI_IDENTIFIER_ENUM SRI_LRI_IDENTIFIER{SRI_LRI_IDENTIFIER_ENUM::LRI_LEVEL};
				AFFECTED_ITEM_t AFFECTED_ITEM_1{0};
				AFFECTED_ITEM_t AFFECTED_ITEM_2{0};
				AFFECTED_ITEM_t AFFECTED_ITEM_3{0};
				SI::SIHour LRI_ETI; /* Resolution 15 minutes */
				uint16_t LRI_SERIAL_NUMBER{0};
				LRI_HW_IDENTIFICATION_ENUM LRI_HW_IDENTIFICATION{LRI_HW_IDENTIFICATION_ENUM::E_SCAN_PROCESSOR_RADAR};
				uint8_t LRI_HW_VERSION{0};
				uint8_t LRI_SW_VERSION_1{0};
				uint8_t LRI_SW_VERSION_2{0};
				BIT_IDENT_ENUM BIT_IDENT{BIT_IDENT_ENUM::NO_FAIL};
				uint16_t FAILURE_IDENTIFICATION_CODE{0};
				SI::SIMilliSecond TIME_OF_OCCURRENCE; /* Resolution 80 times */
				uint16_t ADDITIONAL_DATA_1{0};
				uint16_t ADDITIONAL_DATA_2{0};
			};
			/**
			 * @brief LRI Maintenance Block type
			 */
			class LRIMaintenanceBlock
			{
			public:
				/**
				 * @brief Set the LRI_NO field of LRIMaintenanceBlock
				 */
				inline void setLRINo(const LRI_NO_ENUM &aField) noexcept
				{
					LRI_NO = aField;
				}
				/**
				 * @brief Get the LRI_NO field of LRIMaintenanceBlock
				 */
				inline LRI_NO_ENUM getLRINo() const noexcept
				{
					return LRI_NO;
				}
				/**
				 * @brief Set the LRI_DATABUS_IDENT field of LRIMaintenanceBlock
				 */
				inline void setLRIDatabusIdent(const LRI_DATABUS_IDENT_ENUM &aField) noexcept
				{
					LRI_DATABUS_IDENT = aField;
				}
				/**
				 * @brief Get the LRI_DATABUS_IDENT field of LRIMaintenanceBlock
				 */
				inline LRI_DATABUS_IDENT_ENUM getLRIDatabusIdent() const noexcept
				{
					return LRI_DATABUS_IDENT;
				}
				/**
				 * @brief Set the EQUIP_IDENT field of LRIMaintenanceBlock
				 */
				inline void setEquipIdent(const EQUIP_IDENT_ENUM &aField) noexcept
				{
					EQUIP_IDENT = aField;
				}
				/**
				 * @brief Get the EQUIP_IDENT field of LRIMaintenanceBlock
				 */
				inline EQUIP_IDENT_ENUM getEquipIdent() const noexcept
				{
					return EQUIP_IDENT;
				}
				/**
				 * @brief Set the LRI_REPORT_COUNT field of LRIMaintenanceBlock
				 */
				inline void setLRIReportCount(const uint8_t &aField) noexcept
				{
					LRI_REPORT_COUNT = aField;
				}
				/**
				 * @brief Get the LRI_REPORT_COUNT field of LRIMaintenanceBlock
				 */
				inline uint8_t getLRIReportCount() const noexcept
				{
					return LRI_REPORT_COUNT;
				}
				/**
				 * @brief Set the SRI_LRI_IDENTIFIER field of LRIMaintenanceBlock
				 */
				inline void setSRILRIIdent(const SRI_LRI_IDENTIFIER_ENUM &aField) noexcept
				{
					SRI_LRI_IDENTIFIER = aField;
				}
				/**
				 * @brief Get the SRI_LRI_IDENTIFIER field of LRIMaintenanceBlock
				 */
				inline SRI_LRI_IDENTIFIER_ENUM getSRILRIIdent() const noexcept
				{
					return SRI_LRI_IDENTIFIER;
				}
				/**
				 * @brief Set the AFFECTED_SRI_1 field of LRIMaintenanceBlock
				 */
				inline void setAffectedSRI1(const AFFECTED_SRI_t &aField) noexcept
				{
					AFFECTED_SRI_1 = aField;
				}
				/**
				 * @brief Get the AFFECTED_SRI_1 field of LRIMaintenanceBlock
				 */
				inline AFFECTED_SRI_t getAffectedSRI1() const noexcept
				{
					return AFFECTED_SRI_1;
				}
				/**
				 * @brief Set the AFFECTED_SRI_2 field of LRIMaintenanceBlock
				 */
				inline void setAffectedSRI2(const AFFECTED_SRI_t &aField) noexcept
				{
					AFFECTED_SRI_2 = aField;
				}
				/**
				 * @brief Get the AFFECTED_SRI_2 field of LRIMaintenanceBlock
				 */
				inline AFFECTED_SRI_t getAffectedSRI2() const noexcept
				{
					return AFFECTED_SRI_2;
				}
				/**
				 * @brief Set the AFFECTED_SRI_3 field of LRIMaintenanceBlock
				 */
				inline void setAffectedSRI3(const AFFECTED_SRI_t &aField) noexcept
				{
					AFFECTED_SRI_3 = aField;
				}
				/**
				 * @brief Get the AFFECTED_SRI_3 field of LRIMaintenanceBlock
				 */
				inline AFFECTED_SRI_t getAffectedSRI3() const noexcept
				{
					return AFFECTED_SRI_3;
				}
				/**
				 * @brief Set the LRI_ETI field of LRIMaintenanceBlock
				 */
				inline void setLRIEti(const SI::SIHour &aField) noexcept
				{
					LRI_ETI = aField;
				}
				/**
				 * @brief Get the LRI_ETI field of LRIMaintenanceBlock
				 */
				inline SI::SIHour getLRIEti() const noexcept
				{
					return LRI_ETI;
				}
				/**
				 * @brief Set the LRI_SERIAL_NUMBER field of LRIMaintenanceBlock
				 */
				inline void setLRISerialNumber(const uint16_t &aField) noexcept
				{
					LRI_SERIAL_NUMBER = aField;
				}
				/**
				 * @brief Get the LRI_SERIAL_NUMBER field of LRIMaintenanceBlock
				 */
				inline uint16_t getLRISerialNumbur() const noexcept
				{
					return LRI_SERIAL_NUMBER;
				}
				/**
				 * @brief Set the LRI_HW_IDENTIFICATION field of LRIMaintenanceBlock
				 */
				inline void setLRIHwIdent(const LRI_HW_IDENTIFICATION_ENUM &aField) noexcept
				{
					LRI_HW_IDENTIFICATION = aField;
				}
				/**
				 * @brief Get the LRI_HW_IDENTIFICATION field of LRIMaintenanceBlock
				 */
				inline LRI_HW_IDENTIFICATION_ENUM getLRIHwIdent() const noexcept
				{
					return LRI_HW_IDENTIFICATION;
				}
				/**
				 * @brief Set the LRI_HW_VERSION field of LRIMaintenanceBlock
				 */
				inline void setLRIHwVersion(const uint8_t &aField) noexcept
				{
					LRI_HW_VERSION = aField;
				}
				/**
				 * @brief Get the LRI_HW_VERSION field of LRIMaintenanceBlock
				 */
				inline uint8_t getLRIHwVersion() const noexcept
				{
					return LRI_HW_VERSION;
				}
				/**
				 * @brief Set the LRI_SW_VERSION_1 field of LRIMaintenanceBlock
				 */
				inline void setLRISwVersion1(const uint8_t &aField) noexcept
				{
					LRI_SW_VERSION_1 = aField;
				}
				/**
				 * @brief Get the LRI_SW_VERSION_1 field of LRIMaintenanceBlock
				 */
				inline uint8_t getLRISwVersion1() const noexcept
				{
					return LRI_SW_VERSION_1;
				}
				/**
				 * @brief Set the LRI_SW_VERSION_2 field of LRIMaintenanceBlock
				 */
				inline void setLRISwVersion2(const uint8_t &aField) noexcept
				{
					LRI_SW_VERSION_2 = aField;
				}
				/**
				 * @brief Get the LRI_SW_VERSION_2 field of LRIMaintenanceBlock
				 */
				inline uint8_t getLRISwVersion2() const noexcept
				{
					return LRI_SW_VERSION_2;
				}
				/**
				 * @brief Set the BIT_IDENT field of LRIMaintenanceBlock
				 */
				inline void setBITIdent(const BIT_IDENT_ENUM &aField) noexcept
				{
					BIT_IDENT = aField;
				}
				/**
				 * @brief Get the BIT_IDENT field of LRIMaintenanceBlock
				 */
				inline BIT_IDENT_ENUM getBITIdent() const noexcept
				{
					return BIT_IDENT;
				}
				/**
				 * @brief Set the FAILURE_IDENTIFICATION_CODE field of LRIMaintenanceBlock
				 */
				inline void setFailIdentCode(const uint16_t &aField) noexcept
				{
					FAILURE_IDENTIFICATION_CODE = aField;
				}
				/**
				 * @brief Get the FAILURE_IDENTIFICATION_CODE field of LRIMaintenanceBlock
				 */
				inline uint16_t getFailIdentCode() const noexcept
				{
					return FAILURE_IDENTIFICATION_CODE;
				}
				/**
				 * @brief Set the TIME_OF_OCCURRENCE field of LRIMaintenanceBlock
				 */
				inline void setTimeOfOccurrence(const SI::SIMilliSecond &aField) noexcept
				{
					TIME_OF_OCCURRENCE = aField;
				}
				/**
				 * @brief Get the TIME_OF_OCCURRENCE field of LRIMaintenanceBlock
				 */
				inline SI::SIMilliSecond getTimeOfOccurrence() const noexcept
				{
					return TIME_OF_OCCURRENCE;
				}
				/**
				 * @brief Set the ADDITIONAL_DATA_1 field of LRIMaintenanceBlock
				 */
				inline void setAdditionalData1(const uint16_t &aField) noexcept
				{
					ADDITIONAL_DATA_1 = aField;
				}
				/**
				 * @brief Get the ADDITIONAL_DATA_1 field of LRIMaintenanceBlock
				 */
				inline uint16_t getAdditionalData1() const noexcept
				{
					return ADDITIONAL_DATA_1;
				}
				/**
				 * @brief Set the ADDITIONAL_DATA_2 field of LRIMaintenanceBlock
				 */
				inline void setAdditionalData2(const uint16_t &aField) noexcept
				{
					ADDITIONAL_DATA_2 = aField;
				}
				/**
				 * @brief Get the ADDITIONAL_DATA_2 field of LRIMaintenanceBlock
				 */
				inline uint16_t getAdditionalData2() const noexcept
				{
					return ADDITIONAL_DATA_2;
				}
				/**
				 * @brief LRIMaintenanceBlock template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					double lriEti {LRI_ETI()};
					double timeOfOccurance {TIME_OF_OCCURRENCE()};
					archive.Serialise(LRI_NO, "LRI_NO");
					archive.Serialise(LRI_DATABUS_IDENT, "LRI_DATABUS_IDENT");
					archive.Serialise(EQUIP_IDENT, "EQUIP_IDENT");
					archive.Serialise(LRI_REPORT_COUNT, "LRI_REPORT_COUNT");
					archive.Serialise(SRI_LRI_IDENTIFIER, "SRI_LRI_IDENTIFIER");
					archive.Serialise(AFFECTED_SRI_1, "AFFECTED_ITEM_1");
					archive.Serialise(AFFECTED_SRI_2, "AFFECTED_ITEM_2");
					archive.Serialise(AFFECTED_SRI_3, "AFFECTED_ITEM_3");
					archive.Serialise(lriEti, "LRI_ETI");
					archive.Serialise(LRI_SERIAL_NUMBER, "LRI_SERIAL_NUMBER");
					archive.Serialise(LRI_HW_IDENTIFICATION, "LRI_HW_IDENTIFICATION");
					archive.Serialise(LRI_HW_VERSION, "LRI_HW_VERSION");
					archive.Serialise(LRI_SW_VERSION_1, "LRI_SW_VERSION_1");
					archive.Serialise(LRI_SW_VERSION_2, "LRI_SW_VERSION_2");
					archive.Serialise(BIT_IDENT, "BIT_IDENT");
					archive.Serialise(FAILURE_IDENTIFICATION_CODE, "FAILURE_IDENTIFICATION_CODE");
					archive.Serialise(timeOfOccurance, "TIME_OF_OCCURRENCE");
					archive.Serialise(ADDITIONAL_DATA_1, "ADDITIONAL_DATA_1");
					archive.Serialise(ADDITIONAL_DATA_2, "ADDITIONAL_DATA_2");
					LRI_ETI = lriEti;
					TIME_OF_OCCURRENCE = timeOfOccurance;
				}
				/**
				 * @brief LRIMaintenanceBlock equality operator
				 */
				bool operator==(const LRIMaintenanceBlock &other) const
				{
					return (LRI_NO == other.LRI_NO &&
							LRI_DATABUS_IDENT == other.LRI_DATABUS_IDENT &&
							EQUIP_IDENT == other.EQUIP_IDENT &&
							LRI_REPORT_COUNT == other.LRI_REPORT_COUNT &&
							SRI_LRI_IDENTIFIER == other.SRI_LRI_IDENTIFIER &&
							AFFECTED_SRI_1 == other.AFFECTED_SRI_1 &&
							AFFECTED_SRI_2 == other.AFFECTED_SRI_2 &&
							AFFECTED_SRI_3 == other.AFFECTED_SRI_3 &&
							LRI_ETI == other.LRI_ETI &&
							LRI_SERIAL_NUMBER == other.LRI_SERIAL_NUMBER &&
							LRI_HW_IDENTIFICATION == other.LRI_HW_IDENTIFICATION &&
							LRI_HW_VERSION == other.LRI_HW_VERSION &&
							LRI_SW_VERSION_1 == other.LRI_SW_VERSION_1 &&
							LRI_SW_VERSION_2 == other.LRI_SW_VERSION_2 &&
							BIT_IDENT == other.BIT_IDENT &&
							FAILURE_IDENTIFICATION_CODE == other.FAILURE_IDENTIFICATION_CODE &&
							TIME_OF_OCCURRENCE == other.TIME_OF_OCCURRENCE &&
							ADDITIONAL_DATA_1 == other.ADDITIONAL_DATA_1 &&
							ADDITIONAL_DATA_2 == other.ADDITIONAL_DATA_2);
				}
				/**
				 * @brief LRIMaintenanceBlock inequality operator
				 */
				bool operator!=(const LRIMaintenanceBlock &other) const
				{
					return !(*this == other);
				}

			private:
				LRI_NO_ENUM LRI_NO{LRI_NO_ENUM::RESERVED};
				LRI_DATABUS_IDENT_ENUM LRI_DATABUS_IDENT{LRI_DATABUS_IDENT_ENUM::RADAR};
				EQUIP_IDENT_ENUM EQUIP_IDENT{EQUIP_IDENT_ENUM::SINGLE_LRI};
				uint8_t LRI_REPORT_COUNT{0};
				SRI_LRI_IDENTIFIER_ENUM SRI_LRI_IDENTIFIER{SRI_LRI_IDENTIFIER_ENUM::LRI_LEVEL};
				AFFECTED_SRI_t AFFECTED_SRI_1{0};
				AFFECTED_SRI_t AFFECTED_SRI_2{0};
				AFFECTED_SRI_t AFFECTED_SRI_3{0};
				SI::SIHour LRI_ETI{0.0}; /* Resolution 15 minutes */
				uint16_t LRI_SERIAL_NUMBER{0};
				LRI_HW_IDENTIFICATION_ENUM LRI_HW_IDENTIFICATION{LRI_HW_IDENTIFICATION_ENUM::E_SCAN_PROCESSOR_RADAR};
				uint8_t LRI_HW_VERSION{0};
				uint8_t LRI_SW_VERSION_1{0};
				uint8_t LRI_SW_VERSION_2{0};
				BIT_IDENT_ENUM BIT_IDENT{BIT_IDENT_ENUM::NO_FAIL};
				uint16_t FAILURE_IDENTIFICATION_CODE{0};
				SI::SIMilliSecond TIME_OF_OCCURRENCE{0.0}; /* Resolution 80 times */
				uint16_t ADDITIONAL_DATA_1{0};
				uint16_t ADDITIONAL_DATA_2{0};
			};
			/**
			 * @brief Health Monitor Block type
			 */
			class HealthMonitorBlock
			{
			public:
				/**
				 * @brief Set the E_RXR_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline void setRxRLiveStatus(const E_RDR_LIVE_STATUS_ENUM &aField) noexcept
				{
					E_RXR_RDR_LIVE_STATUS = aField;
				}
				/**
				 * @brief Get the E_RXR_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline E_RDR_LIVE_STATUS_ENUM getRxRLiveStatus() const noexcept
				{
					return E_RXR_RDR_LIVE_STATUS;
				}
				/**
				 * @brief Set the E_IFF_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline void setIFFLiveStatus(const E_RDR_LIVE_STATUS_ENUM &aField) noexcept
				{
					E_IFF_RDR_LIVE_STATUS = aField;
				}
				/**
				 * @brief Get the E_IFF_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline E_RDR_LIVE_STATUS_ENUM getIFFLiveStatus() const noexcept
				{
					return E_IFF_RDR_LIVE_STATUS;
				}
				/**
				 * @brief Set the E_ANT_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline void setANTLiveStatus(const E_RDR_LIVE_STATUS_ENUM &aField) noexcept
				{
					E_ANT_RDR_LIVE_STATUS = aField;
				}
				/**
				 * @brief Get the E_ANT_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline E_RDR_LIVE_STATUS_ENUM getANTLiveStatus() const noexcept
				{
					return E_ANT_RDR_LIVE_STATUS;
				}
				/**
				 * @brief Set the E_AAU_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline void setAAULiveStatus(const E_RDR_LIVE_STATUS_ENUM &aField) noexcept
				{
					E_AAU_RDR_LIVE_STATUS = aField;
				}
				/**
				 * @brief Get the E_AAU_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline E_RDR_LIVE_STATUS_ENUM getAAULiveStatus() const noexcept
				{
					return E_AAU_RDR_LIVE_STATUS;
				}
				/**
				 * @brief Set the E_APSC_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline void setAPSCLiveStatus(const E_RDR_LIVE_STATUS_ENUM &aField) noexcept
				{
					E_APSC_RDR_LIVE_STATUS = aField;
				}
				/**
				 * @brief Get the E_APSC_RDR_LIVE_STATUS field of HealthMonitorBlock
				 */
				inline E_RDR_LIVE_STATUS_ENUM getAPSCLiveStatus() const noexcept
				{
					return E_APSC_RDR_LIVE_STATUS;
				}
				/**
				 * @brief Set the RADAR_HEALTHFILE_DWNLD_STATUS field of HealthMonitorBlock
				 */
				inline void setHealthDownStatus(const RADAR_HEALTHFILE_DWNLD_STATUS_ENUM &aField) noexcept
				{
					RADAR_HEALTHFILE_DWNLD_STATUS = aField;
				}
				/**
				 * @brief Get the RADAR_HEALTHFILE_DWNLD_STATUS field of HealthMonitorBlock
				 */
				inline RADAR_HEALTHFILE_DWNLD_STATUS_ENUM getHealthDownStatus() const noexcept
				{
					return RADAR_HEALTHFILE_DWNLD_STATUS;
				}
				/**
				 * @brief Set the RADAR_LIVE_RT_STATUS_IMPLTD field of HealthMonitorBlock
				 */
				inline void setLiveRTStatus(const RADAR_LIVE_RT_STATUS_IMPLTD_ENUM &aField) noexcept
				{
					RADAR_LIVE_RT_STATUS_IMPLTD = aField;
				}
				/**
				 * @brief Get the RADAR_LIVE_RT_STATUS_IMPLTD field of HealthMonitorBlock
				 */
				inline RADAR_LIVE_RT_STATUS_IMPLTD_ENUM getLiveRTStatus() const noexcept
				{
					return RADAR_LIVE_RT_STATUS_IMPLTD;
				}
				/**
				 * @brief HealthMonitorBlock template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					archive.Serialise(RESERVED_RT_1, "RESERVED_RT_1");
					archive.Serialise(RESERVED_RT_2, "RESERVED_RT_2");
					archive.Serialise(RESERVED_RT_3, "RESERVED_RT_3");
					archive.Serialise(RESERVED_RT_4, "RESERVED_RT_4");
					archive.Serialise(E_RXR_RDR_LIVE_STATUS, "E_RXR_RDR_LIVE_STATUS");
					archive.Serialise(E_IFF_RDR_LIVE_STATUS, "E_IFF_RDR_LIVE_STATUS");
					archive.Serialise(E_ANT_RDR_LIVE_STATUS, "E_ANT_RDR_LIVE_STATUS");
					archive.Serialise(E_AAU_RDR_LIVE_STATUS, "E_AAU_RDR_LIVE_STATUS");
					archive.Serialise(E_APSC_RDR_LIVE_STATUS, "E_APSC_RDR_LIVE_STATUS");
					archive.Serialise(RADAR_HEALTHFILE_DWNLD_STATUS, "RADAR_HEALTHFILE_DWNLD_STATUS");
					archive.Serialise(RADAR_LIVE_RT_STATUS_IMPLTD, "RADAR_LIVE_RT_STATUS_IMPLTD");
				}
				/**
				 * @brief HealthMonitorBlock equality operator
				 */
				bool operator==(const HealthMonitorBlock &other) const
				{
					return (RESERVED_RT_1 == other.RESERVED_RT_1 &&
							RESERVED_RT_2 == other.RESERVED_RT_2 &&
							RESERVED_RT_3 == other.RESERVED_RT_3 &&
							RESERVED_RT_4 == other.RESERVED_RT_4 &&
							E_RXR_RDR_LIVE_STATUS == other.E_RXR_RDR_LIVE_STATUS &&
							E_IFF_RDR_LIVE_STATUS == other.E_IFF_RDR_LIVE_STATUS &&
							E_ANT_RDR_LIVE_STATUS == other.E_ANT_RDR_LIVE_STATUS &&
							E_APSC_RDR_LIVE_STATUS == other.E_APSC_RDR_LIVE_STATUS &&
							RADAR_HEALTHFILE_DWNLD_STATUS == other.RADAR_HEALTHFILE_DWNLD_STATUS &&
							RADAR_LIVE_RT_STATUS_IMPLTD == other.RADAR_LIVE_RT_STATUS_IMPLTD);
				}
				/**
				 * @brief HealthMonitorBlock inequality operator
				 */
				bool operator!=(const HealthMonitorBlock &other) const
				{
					return !(*this == other);
				}

			private:
				uint8_t RESERVED_RT_1{0};
				uint8_t RESERVED_RT_2{0};
				uint8_t RESERVED_RT_3{0};
				uint8_t RESERVED_RT_4{0};
				E_RDR_LIVE_STATUS_ENUM E_RXR_RDR_LIVE_STATUS{E_RDR_LIVE_STATUS_ENUM::UNKNOWN};
				E_RDR_LIVE_STATUS_ENUM E_IFF_RDR_LIVE_STATUS{E_RDR_LIVE_STATUS_ENUM::UNKNOWN};
				E_RDR_LIVE_STATUS_ENUM E_ANT_RDR_LIVE_STATUS{E_RDR_LIVE_STATUS_ENUM::UNKNOWN};
				E_RDR_LIVE_STATUS_ENUM E_AAU_RDR_LIVE_STATUS{E_RDR_LIVE_STATUS_ENUM::UNKNOWN};
				E_RDR_LIVE_STATUS_ENUM E_APSC_RDR_LIVE_STATUS{E_RDR_LIVE_STATUS_ENUM::UNKNOWN};
				RADAR_HEALTHFILE_DWNLD_STATUS_ENUM RADAR_HEALTHFILE_DWNLD_STATUS{RADAR_HEALTHFILE_DWNLD_STATUS_ENUM::NOT_REQUESTED};
				RADAR_LIVE_RT_STATUS_IMPLTD_ENUM RADAR_LIVE_RT_STATUS_IMPLTD{RADAR_LIVE_RT_STATUS_IMPLTD_ENUM::IMPLEMENTED};
			};
			/**
			 * @brief Cyclic Maintenace Message topic
			 */
			class CyclicMaintenaceMessage
			{
			public:
				/**
				 * @brief Set the RADAR_LIVE_RT_STATUS_IMPLTD field of CyclicMaintenaceMessage
				 */
				inline void setStaticTag(const RADAR29_IPU_HAT_STATTAG_ENUM &aField) noexcept
				{
					RADAR29_IPU_HAT_STATTAG = aField;
				}
				/**
				 * @brief Get the RADAR_LIVE_RT_STATUS_IMPLTD field of CyclicMaintenaceMessage
				 */
				inline RADAR29_IPU_HAT_STATTAG_ENUM getStaticTag() const noexcept
				{
					return RADAR29_IPU_HAT_STATTAG;
				}
				/**
				 * @brief Set the RADAR29_IPU_HAT_DYNTAG field of CyclicMaintenaceMessage
				 */
				inline void setDynamicTag(const uint8_t &aField) noexcept
				{
					RADAR29_IPU_HAT_DYNTAG = aField;
				}
				/**
				 * @brief Get the RADAR29_IPU_HAT_DYNTAG field of CyclicMaintenaceMessage
				 */
				inline uint8_t getDynamicTag() const noexcept
				{
					return RADAR29_IPU_HAT_DYNTAG;
				}
				/**
				 * @brief Set the SYSTEM field of CyclicMaintenaceMessage
				 */
				inline void setMaintenanceBlock(const SystemMaintenanceBlock &aField) noexcept
				{
					SYSTEM = aField;
				}
				/**
				 * @brief Get the SYSTEM field of CyclicMaintenaceMessage
				 */
				inline SystemMaintenanceBlock getMaintenanceBlock() const noexcept
				{
					return SYSTEM;
				}
				/**
				 * @brief Set the PROCESSOR field of CyclicMaintenaceMessage
				 */
				inline void setPxMaintenanceBlock(const LRIMaintenanceBlock &aField) noexcept
				{
					PROCESSOR = aField;
				}
				/**
				 * @brief Get the PROCESSOR field of CyclicMaintenaceMessage
				 */
				inline LRIMaintenanceBlock getPxMaintenanceBlock() const noexcept
				{
					return PROCESSOR;
				}
				/**
				 * @brief Set the ANTENNA field of CyclicMaintenaceMessage
				 */
				inline void setANTMaintenanceBlock(const LRIMaintenanceBlock &aField) noexcept
				{
					ANTENNA = aField;
				}
				/**
				 * @brief Get the ANTENNA field of CyclicMaintenaceMessage
				 */
				inline LRIMaintenanceBlock getANTMaintenanceBlock() const noexcept
				{
					return ANTENNA;
				}
				/**
				 * @brief Set the APSC field of CyclicMaintenaceMessage
				 */
				inline void setAPSCMaintenanceBlock(const LRIMaintenanceBlock &aField) noexcept
				{
					APSC = aField;
				}
				/**
				 * @brief Get the APSC field of CyclicMaintenaceMessage
				 */
				inline LRIMaintenanceBlock getAPSCMaintenanceBlock() const noexcept
				{
					return APSC;
				}
				/**
				 * @brief Set the RECEIVER field of CyclicMaintenaceMessage
				 */
				inline void setRxRMaintenanceBlock(const LRIMaintenanceBlock &aField) noexcept
				{
					RECEIVER = aField;
				}
				/**
				 * @brief Get the RECEIVER field of CyclicMaintenaceMessage
				 */
				inline LRIMaintenanceBlock getRxRMaintenanceBlock() const noexcept
				{
					return RECEIVER;
				}
				/**
				 * @brief Set the AAU field of CyclicMaintenaceMessage
				 */
				inline void setAAUMaintenanceBlock(const LRIMaintenanceBlock &aField) noexcept
				{
					AAU = aField;
				}
				/**
				 * @brief Get the AAU field of CyclicMaintenaceMessage
				 */
				inline LRIMaintenanceBlock getAAUMaintenanceBlock() const noexcept
				{
					return AAU;
				}
				/**
				 * @brief Set the RADAR_BUS field of CyclicMaintenaceMessage
				 */
				inline void setRadarBusMaintenanceBlock(const LRIMaintenanceBlock &aField) noexcept
				{
					RADAR_BUS = aField;
				}
				/**
				 * @brief Get the RADAR_BUS field of CyclicMaintenaceMessage
				 */
				inline LRIMaintenanceBlock getRadarBusMaintenanceBlock() const noexcept
				{
					return RADAR_BUS;
				}
				/**
				 * @brief CyclicMaintenaceMessage template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					archive.Serialise(RADAR29_IPU_HAT_STATTAG, "RADAR29_IPU_HAT_STATTAG");
					archive.Serialise(RADAR29_IPU_HAT_DYNTAG, "RADAR29_IPU_HAT_DYNTAG");
					SYSTEM.Serialise(archive);
					PROCESSOR.Serialise(archive);
					ANTENNA.Serialise(archive);
					APSC.Serialise(archive);
					AAU.Serialise(archive);
					RADAR_BUS.Serialise(archive);
				}
				/**
				 * @brief CyclicMaintenaceMessage equality operator
				 */
				bool operator==(const CyclicMaintenaceMessage &other) const
				{
					return (RADAR29_IPU_HAT_STATTAG == other.RADAR29_IPU_HAT_STATTAG &&
							RADAR29_IPU_HAT_DYNTAG == other.RADAR29_IPU_HAT_DYNTAG &&
							SYSTEM == other.SYSTEM &&
							PROCESSOR == other.PROCESSOR &&
							ANTENNA == other.ANTENNA &&
							APSC == other.APSC &&
							AAU == other.AAU &&
							RADAR_BUS == other.RADAR_BUS);
				}
				/**
				 * @brief CyclicMaintenaceMessage inequality operator
				 */
				bool operator!=(const CyclicMaintenaceMessage &other) const
				{
					return !(*this == other);
				}
				LCA_TOPIC("CyclicMaintenanceMessage", 1, 0)
			private:
				RADAR29_IPU_HAT_STATTAG_ENUM RADAR29_IPU_HAT_STATTAG{RADAR29_IPU_HAT_STATTAG_ENUM::INVALID};
				uint8_t RADAR29_IPU_HAT_DYNTAG{0};
				SystemMaintenanceBlock SYSTEM;
				LRIMaintenanceBlock PROCESSOR;
				LRIMaintenanceBlock ANTENNA;
				LRIMaintenanceBlock APSC;
				LRIMaintenanceBlock RECEIVER;
				LRIMaintenanceBlock AAU;
				LRIMaintenanceBlock RADAR_BUS;
			};
		}
	}
}

#endif