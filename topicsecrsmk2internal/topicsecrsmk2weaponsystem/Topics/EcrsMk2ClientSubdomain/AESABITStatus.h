#ifndef AESA_BIT_STATUS_H
#define AESA_BIT_STATUS_H

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
			enum class AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM : uint8_t
			{
				TBD
			};
			/**
			 * @brief AESA BIT Status topic
			 */
			class AESABITStatus
			{
			public:
				/**
				 * @brief Set the AESA_PBIT_STATUS field of AESABITStatus
				 */
				inline void setPBITStatus(const PBIT_STATUS_ENUM &aField) noexcept
				{
					AESA_PBIT_STATUS = aField;
				}
				/**
				 * @brief Get the AESA_PBIT_STATUS field of AESABITStatus
				 */
				inline PBIT_STATUS_ENUM getPBITStatus() const noexcept
				{
					return AESA_PBIT_STATUS;
				}
				/**
				 * @brief Set the AESA_FAILURE_ID_IDENTIFICATION_CODE field of AESABITStatus
				 */
				inline void setFailureIdCode(const FAILURE_ID_IDENTIFICATION_CODE_ENUM &aField) noexcept
				{
					AESA_FAILURE_ID_IDENTIFICATION_CODE = aField;
				}
				/**
				 * @brief Get the AESA_FAILURE_ID_IDENTIFICATION_CODE field of AESABITStatus
				 */
				inline FAILURE_ID_IDENTIFICATION_CODE_ENUM getFailureIdCode() const noexcept
				{
					return AESA_FAILURE_ID_IDENTIFICATION_CODE;
				}
				/**
				 * @brief Set the AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG field of AESABITStatus
				 */
				inline void setFaultFlag(const CRITICAL_FAULT_FLAG_ENUM &aField) noexcept
				{
					AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG = aField;
				}
				/**
				 * @brief Get the AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG field of AESABITStatus
				 */
				inline CRITICAL_FAULT_FLAG_ENUM getFaultFlag() const noexcept
				{
					return AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG;
				}
				/**
				 * @brief Set the AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM field of AESABITStatus
				 */
				inline void set1LikelyFailSubSys(const AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM field of AESABITStatus
				 */
				inline AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get1LikelyFailSubSys() const noexcept
				{
					return AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM field of AESABITStatus
				 */
				inline void set2LikelyFailSubSys(const AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM field of AESABITStatus
				 */
				inline AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get2LikelyFailSubSys() const noexcept
				{
					return AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM field of AESABITStatus
				 */
				inline void set3LikelyFailSubSys(const AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM field of AESABITStatus
				 */
				inline AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get3LikelyFailSubSys() const noexcept
				{
					return AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the AESA_RADAR_TIME_TAG_SEC field of AESABITStatus
				 */
				inline void setTimeTag(const SI::SISecond &aField) noexcept
				{
					AESA_RADAR_TIME_TAG_SEC = aField;
				}
				/**
				 * @brief Get the AESA_RADAR_TIME_TAG_SEC field of AESABITStatus
				 */
				inline SI::SISecond getTimeTagSec() const noexcept
				{
					return AESA_RADAR_TIME_TAG_SEC;
				}
				/**
				 * @brief Set the AESA_RADAR_TIME_TAG_NANOSEC field of AESABITStatus
				 */
				inline void setTimeTag(const SI::SINanoSecond &aField) noexcept
				{
					AESA_RADAR_TIME_TAG_NANOSEC = aField;
				}
				/**
				 * @brief Get the AESA_RADAR_TIME_TAG_NANOSEC field of AESABITStatus
				 */
				inline SI::SINanoSecond getTimeTagNanoSec() const noexcept
				{
					return AESA_RADAR_TIME_TAG_NANOSEC;
				}
				/**
				 * @brief AESABITStatus template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					double timeTagSec{AESA_RADAR_TIME_TAG_SEC()};
					double timeTagNanoSec{AESA_RADAR_TIME_TAG_NANOSEC()};
					archive.Serialise(AESA_PBIT_STATUS, "AESA_PBIT_STATUS");
					archive.Serialise(AESA_FAILURE_ID_IDENTIFICATION_CODE, "AESA_FAILURE_ID_IDENTIFICATION_CODE");
					archive.Serialise(AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG, "AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG");
					archive.Serialise(AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM, "AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM, "AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM, "AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(timeTagSec, "AESA_RADAR_TIME_TAG_SEC");
					archive.Serialise(timeTagNanoSec, "AESA_RADAR_TIME_TAG_NANOSEC");
					AESA_RADAR_TIME_TAG_SEC = timeTagSec;
					AESA_RADAR_TIME_TAG_NANOSEC = timeTagNanoSec;
				}
				/**
				 * @brief AESABITStatus inequality operator
				 */
				bool operator!=(const AESABITStatus &other) const
				{
					return !(*this == other);
				}
				/**
				 * @brief AESABITStatus equality operator
				 */
				bool operator==(const AESABITStatus &other) const
				{
					return (AESA_PBIT_STATUS == other.AESA_PBIT_STATUS &&
							AESA_FAILURE_ID_IDENTIFICATION_CODE == other.AESA_FAILURE_ID_IDENTIFICATION_CODE &&
							AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG == other.AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG &&
							AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM == other.AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM &&
							AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM == other.AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM &&
							AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM == other.AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM &&
							AESA_RADAR_TIME_TAG_SEC == other.AESA_RADAR_TIME_TAG_SEC &&
							AESA_RADAR_TIME_TAG_NANOSEC == other.AESA_RADAR_TIME_TAG_NANOSEC);
				}
				LCA_TOPIC("AESABITStatus", 1, 0)
			private:
				PBIT_STATUS_ENUM AESA_PBIT_STATUS{PBIT_STATUS_ENUM::WAIT_PBIT};
				FAILURE_ID_IDENTIFICATION_CODE_ENUM AESA_FAILURE_ID_IDENTIFICATION_CODE{FAILURE_ID_IDENTIFICATION_CODE_ENUM::NO_TEST_FAILURE};
				CRITICAL_FAULT_FLAG_ENUM AESA_NON_CRITICAL_CRITICAL_FAULT_FLAG{CRITICAL_FAULT_FLAG_ENUM::NON_CRITICAL_FAULT};
				AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM AESA_1ST_MOST_LIKELY_FAILED_SUBSYSTEM{AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::TBD};
				AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM AESA_2ND_MOST_LIKELY_FAILED_SUBSYSTEM{AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::TBD};
				AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM AESA_3RD_MOST_LIKELY_FAILED_SUBSYSTEM{AESA_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::TBD};
				SI::SISecond AESA_RADAR_TIME_TAG_SEC;
				SI::SINanoSecond AESA_RADAR_TIME_TAG_NANOSEC;
			};
		}
	}
}

#endif