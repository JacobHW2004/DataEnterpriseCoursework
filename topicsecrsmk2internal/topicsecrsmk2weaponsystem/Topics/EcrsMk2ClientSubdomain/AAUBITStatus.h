#ifndef AAU_BIT_STATUS_H
#define AAU_BIT_STATUS_H

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
			enum class AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM : uint8_t
			{
				TBD
			};
			/**
			 * @brief AAU BIT Status topic
			 */
			class AAUBITStatus
			{
			public:
				/**
				 * @brief Set the AAU_PBIT_STATUS field of AAUBITStatus
				 */
				inline void setPBITStatus(const PBIT_STATUS_ENUM &aField) noexcept
				{
					AAU_PBIT_STATUS = aField;
				}
				/**
				 * @brief Get the AAU_PBIT_STATUS field of AAUBITStatus
				 */
				inline PBIT_STATUS_ENUM getPBITStatus() const noexcept
				{
					return AAU_PBIT_STATUS;
				}
				/**
				 * @brief Set the AAU_FAILURE_ID_IDENTIFICATION_CODE field of AAUBITStatus
				 */
				inline void setFailureIdCode(const FAILURE_ID_IDENTIFICATION_CODE_ENUM &aField) noexcept
				{
					AAU_FAILURE_ID_IDENTIFICATION_CODE = aField;
				}
				/**
				 * @brief Get the AAU_FAILURE_ID_IDENTIFICATION_CODE field of AAUBITStatus
				 */
				inline FAILURE_ID_IDENTIFICATION_CODE_ENUM getFailureIdCode() const noexcept
				{
					return AAU_FAILURE_ID_IDENTIFICATION_CODE;
				}
				/**
				 * @brief Set the AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG field of AAUBITStatus
				 */
				inline void setFaultFlag(const CRITICAL_FAULT_FLAG_ENUM &aField) noexcept
				{
					AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG = aField;
				}
				/**
				 * @brief Get the AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG field of AAUBITStatus
				 */
				inline CRITICAL_FAULT_FLAG_ENUM getFaultFlag() const noexcept
				{
					return AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG;
				}
				/**
				 * @brief Set the AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM field of AAUBITStatus
				 */
				inline void set1LikelyFailSubSys(const AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM field of AAUBITStatus
				 */
				inline AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get1LikelyFailSubSys() const noexcept
				{
					return AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM field of AAUBITStatus
				 */
				inline void set2LikelyFailSubSys(const AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM field of AAUBITStatus
				 */
				inline AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get2LikelyFailSubSys() const noexcept
				{
					return AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM field of AAUBITStatus
				 */
				inline void set3LikelyFailSubSys(const AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM field of AAUBITStatus
				 */
				inline AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get3LikelyFailSubSys() const noexcept
				{
					return AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the AAU_RADAR_TIME_TAG_SEC field of AAUBITStatus
				 */
				inline void setTimeTag(const SI::SISecond &aField) noexcept
				{
					AAU_RADAR_TIME_TAG_SEC = aField;
				}
				/**
				 * @brief Get the AAU_RADAR_TIME_TAG_SEC field of AAUBITStatus
				 */
				inline SI::SISecond getTimeTagSec() const noexcept
				{
					return AAU_RADAR_TIME_TAG_SEC;
				}
				/**
				 * @brief Set the AAU_RADAR_TIME_TAG_NANOSEC field of AAUBITStatus
				 */
				inline void setTimeTag(const SI::SINanoSecond &aField) noexcept
				{
					AAU_RADAR_TIME_TAG_NANOSEC = aField;
				}
				/**
				 * @brief Get the AAU_RADAR_TIME_TAG_NANOSEC field of AAUBITStatus
				 */
				inline SI::SINanoSecond getTimeTagNanoSec() const noexcept
				{
					return AAU_RADAR_TIME_TAG_NANOSEC;
				}
				/**
				 * @brief AAUBITStatus template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					double timeTagSec {AAU_RADAR_TIME_TAG_SEC()};
					double timeTagNanoSec {AAU_RADAR_TIME_TAG_NANOSEC()};
					archive.Serialise(AAU_PBIT_STATUS, "AAU_PBIT_STATUS");
					archive.Serialise(AAU_FAILURE_ID_IDENTIFICATION_CODE, "AAU_FAILURE_ID_IDENTIFICATION_CODE");
					archive.Serialise(AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG, "AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG");
					archive.Serialise(AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM, "AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM, "AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM, "AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(timeTagSec, "AAU_RADAR_TIME_TAG_SEC");
					archive.Serialise(timeTagNanoSec, "AAU_RADAR_TIME_TAG_NANOSEC");
					AAU_RADAR_TIME_TAG_SEC = timeTagSec;
					AAU_RADAR_TIME_TAG_NANOSEC = timeTagNanoSec;
				}
				/**
				 * @brief AAUBITStatus inequality operator
				 */
				bool operator!=(const AAUBITStatus &other) const
				{
					return !(*this == other);
				}
				/**
				 * @brief AAUBITStatus equality operator
				 */
				bool operator==(const AAUBITStatus &other) const
				{
					return (AAU_PBIT_STATUS == other.AAU_PBIT_STATUS &&
							AAU_FAILURE_ID_IDENTIFICATION_CODE == other.AAU_FAILURE_ID_IDENTIFICATION_CODE &&
							AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG == other.AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG &&
							AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM == other.AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM &&
							AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM == other.AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM &&
							AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM == other.AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM &&
							AAU_RADAR_TIME_TAG_SEC == other.AAU_RADAR_TIME_TAG_SEC &&
							AAU_RADAR_TIME_TAG_NANOSEC == other.AAU_RADAR_TIME_TAG_NANOSEC);
				}
				LCA_TOPIC("AAUBITStatus", 1, 0)
			private:
				PBIT_STATUS_ENUM AAU_PBIT_STATUS{PBIT_STATUS_ENUM::WAIT_PBIT};
				FAILURE_ID_IDENTIFICATION_CODE_ENUM AAU_FAILURE_ID_IDENTIFICATION_CODE{FAILURE_ID_IDENTIFICATION_CODE_ENUM::NO_TEST_FAILURE};
				CRITICAL_FAULT_FLAG_ENUM AAU_NON_CRITICAL_CRITICAL_FAULT_FLAG{CRITICAL_FAULT_FLAG_ENUM::NON_CRITICAL_FAULT};
				AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM AAU_1ST_MOST_LIKELY_FAILED_SUBSYSTEM{AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::TBD};
				AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM AAU_2ND_MOST_LIKELY_FAILED_SUBSYSTEM{AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::TBD};
				AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM AAU_3RD_MOST_LIKELY_FAILED_SUBSYSTEM{AAU_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::TBD};
				SI::SISecond AAU_RADAR_TIME_TAG_SEC{0.0};
				SI::SINanoSecond AAU_RADAR_TIME_TAG_NANOSEC{0.0};
			};
		}
	}
}

#endif