#ifndef APSC_BIT_STATUS_H
#define APSC_BIT_STATUS_H

#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "CommonBITStatus.h"
#include "SISecond.h"
#include "SINanoSecond.h"

namespace Topics
{
	namespace EcrsMK2
	{
		namespace WarmUP
		{
			enum class APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM
			{
				CHASSIS_SRI,
				DC_DC_CONVERTER_1,
				DC_DC_CONVERTER_2,
				DC_DC_CONVERTER_3,
				DC_DC_CONVERTER_4,
				DC_DC_CONVERTER_5,
				DC_DC_CONVERTER_6,
				DC_DC_CONVERTER_7,
				DC_DC_CONVERTER_8,
				DC_DC_CONVERTER_9,
				DC_DC_CONVERTER_10,
				AUX_DC_DC_CONVERTER_SRI,
				LOW_VOLTAGE_CAPACITOR_SRI,
				DIRTY_BOX,
				AC_DC_CONTROLLER,
				AC_DC_BUCK_CONTROLLER,
				ACTIVE_RECTIFIER,
				AC_DC_CAPACITOR_BANK,
				AC_DC_MONITORING,
				AC_DC_POER_CONTROLLER,
				MDU_SRI,
				CONTROOLER
			};
			/**
			 * @brief APSC BIT Status topic
			 */
			class APSCBITStatus
			{
			public:
				/**
				 * @brief Set the APSC_PBIT_STATUS field of APSCBITStatus
				 */
				inline void setPBITStatus(const PBIT_STATUS_ENUM &aField) noexcept
				{
					APSC_PBIT_STATUS = aField;
				}
				/**
				 * @brief Get the APSC_PBIT_STATUS field of APSCBITStatus
				 */
				inline PBIT_STATUS_ENUM getPBITStatus() const noexcept
				{
					return APSC_PBIT_STATUS;
				}
				/**
				 * @brief Set the APSC_FAILURE_ID_IDENTIFICATION_CODE field of APSCBITStatus
				 */
				inline void setFailureIdCode(const FAILURE_ID_IDENTIFICATION_CODE_ENUM &aField) noexcept
				{
					APSC_FAILURE_ID_IDENTIFICATION_CODE = aField;
				}
				/**
				 * @brief Get the APSC_FAILURE_ID_IDENTIFICATION_CODE field of APSCBITStatus
				 */
				inline FAILURE_ID_IDENTIFICATION_CODE_ENUM getFailureIdCode() const noexcept
				{
					return APSC_FAILURE_ID_IDENTIFICATION_CODE;
				}
				/**
				 * @brief Set the APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG field of APSCBITStatus
				 */
				inline void setFaultFlag(const CRITICAL_FAULT_FLAG_ENUM &aField) noexcept
				{
					APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG = aField;
				}
				/**
				 * @brief Get the APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG field of APSCBITStatus
				 */
				inline CRITICAL_FAULT_FLAG_ENUM getFaultFlag() const noexcept
				{
					return APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG;
				}
				/**
				 * @brief Set the APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM field of APSCBITStatus
				 */
				inline void set1LikelyFailSubSys(const APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM field of APSCBITStatus
				 */
				inline APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get1LikelyFailSubSys() const noexcept
				{
					return APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM field of APSCBITStatus
				 */
				inline void set2LikelyFailSubSys(const APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM field of APSCBITStatus
				 */
				inline APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get2LikelyFailSubSys() const noexcept
				{
					return APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM field of APSCBITStatus
				 */
				inline void set3LikelyFailSubSys(const APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM field of APSCBITStatus
				 */
				inline APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get3LikelyFailSubSys() const noexcept
				{
					return APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the AAU_RADAR_TIME_TAG_SEC field of APSCBITStatus
				 */
				inline void setTimeTag(const SI::SISecond &aField) noexcept
				{
					APSC_RADAR_TIME_TAG_SEC = aField;
				}
				/**
				 * @brief Get the AAU_RADAR_TIME_TAG_SEC field of APSCBITStatus
				 */
				inline SI::SISecond getTimeTagSec() const noexcept
				{
					return APSC_RADAR_TIME_TAG_SEC;
				}
				/**
				 * @brief Set the AAU_RADAR_TIME_TAG_NANOSEC field of APSCBITStatus
				 */
				inline void setTimeTag(const SI::SINanoSecond &aField) noexcept
				{
					APSC_RADAR_TIME_TAG_NANOSEC = aField;
				}
				/**
				 * @brief Get the AAU_RADAR_TIME_TAG_NANOSEC field of APSCBITStatus
				 */
				inline SI::SINanoSecond getTimeTagNanoSec() const noexcept
				{
					return APSC_RADAR_TIME_TAG_NANOSEC;
				}
				/**
				 * @brief APSCBITStatus template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					double timeTagSec{APSC_RADAR_TIME_TAG_SEC()};
					double timeTagNanoSec{APSC_RADAR_TIME_TAG_NANOSEC()};
					archive.Serialise(APSC_PBIT_STATUS, "APSC_PBIT_STATUS");
					archive.Serialise(APSC_FAILURE_ID_IDENTIFICATION_CODE, "APSC_FAILURE_ID_IDENTIFICATION_CODE");
					archive.Serialise(APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG, "APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG");
					archive.Serialise(APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM, "APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM, "APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM, "APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(timeTagSec, "APSC_RADAR_TIME_TAG_SEC");
					archive.Serialise(timeTagNanoSec, "APSC_RADAR_TIME_TAG_NANOSEC");
					APSC_RADAR_TIME_TAG_SEC = timeTagSec;
					APSC_RADAR_TIME_TAG_NANOSEC = timeTagNanoSec;
				}
				/**
				 * @brief APSCBITStatus inequality operator
				 */
				bool operator!=(const APSCBITStatus &other) const
				{
					return !(*this == other);
				}
				/**
				 * @brief APSCBITStatus equality operator
				 */
				bool operator==(const APSCBITStatus &other) const
				{
					return (APSC_PBIT_STATUS == other.APSC_PBIT_STATUS &&
							APSC_FAILURE_ID_IDENTIFICATION_CODE == other.APSC_FAILURE_ID_IDENTIFICATION_CODE &&
							APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG == other.APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG &&
							APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM == other.APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM &&
							APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM == other.APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM &&
							APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM == other.APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM &&
							APSC_RADAR_TIME_TAG_SEC == other.APSC_RADAR_TIME_TAG_SEC &&
							APSC_RADAR_TIME_TAG_NANOSEC == other.APSC_RADAR_TIME_TAG_NANOSEC);
				}
				LCA_TOPIC("APSCBITStatus", 1, 0)
			private:
				PBIT_STATUS_ENUM APSC_PBIT_STATUS{PBIT_STATUS_ENUM::WAIT_PBIT};
				FAILURE_ID_IDENTIFICATION_CODE_ENUM APSC_FAILURE_ID_IDENTIFICATION_CODE{FAILURE_ID_IDENTIFICATION_CODE_ENUM::NO_TEST_FAILURE};
				CRITICAL_FAULT_FLAG_ENUM APSC_NON_CRITICAL_CRITICAL_FAULT_FLAG{CRITICAL_FAULT_FLAG_ENUM::NON_CRITICAL_FAULT};
				APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM APSC_1ST_MOST_LIKELY_FAILED_SUBSYSTEM{APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::CHASSIS_SRI};
				APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM{APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::CHASSIS_SRI};
				APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM APSC_3RD_MOST_LIKELY_FAILED_SUBSYSTEM{APSC_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::CHASSIS_SRI};
				SI::SISecond APSC_RADAR_TIME_TAG_SEC;
				SI::SINanoSecond APSC_RADAR_TIME_TAG_NANOSEC;
			};
		}
	}
}

#endif