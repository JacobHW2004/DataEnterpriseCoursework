#ifndef MCRx_BIT_STATUS_H
#define MCRx_BIT_STATUS_H

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
			enum class MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM : uint8_t
			{
				BACK_PLANE_ASSEMBLY,
				PSU,
				CONTROLLER_ASSEMBLY,
				TX_ASSEMBLY,
				PLL_ASSEMBLY,
				RFIF_ASSEMBLY,
				DIGITAL_SYNTH_ASSEMBLY,
				SIGNAL_POWER_INTERFACE,
				NB_CONVERTER_ASSEMBLY,
				WB_CONVERTER_ASSEMBLY
			};
			/**
			 * @brief MCRx BIT Status topic
			 */
			class MCRxBITStatus
			{
			public:
				/**
				 * @brief Set the MCRx_PBIT_STATUS field of MCRxBITStatus
				 */
				inline void setPBITStatus(const PBIT_STATUS_ENUM &aField) noexcept
				{
					MCRx_PBIT_STATUS = aField;
				}
				/**
				 * @brief Get the MCRx_PBIT_STATUS field of MCRxBITStatus
				 */
				inline PBIT_STATUS_ENUM getPBITStatus() const noexcept
				{
					return MCRx_PBIT_STATUS;
				}
				/**
				 * @brief Set the MCRx_FAILURE_ID_IDENTIFICATION_CODE field of MCRxBITStatus
				 */
				inline void setFailureIdCode(const FAILURE_ID_IDENTIFICATION_CODE_ENUM &aField) noexcept
				{
					MCRx_FAILURE_ID_IDENTIFICATION_CODE = aField;
				}
				/**
				 * @brief Get the MCRx_FAILURE_ID_IDENTIFICATION_CODE field of MCRxBITStatus
				 */
				inline FAILURE_ID_IDENTIFICATION_CODE_ENUM getFailureIdCode() const noexcept
				{
					return MCRx_FAILURE_ID_IDENTIFICATION_CODE;
				}
				/**
				 * @brief Set the MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG field of MCRxBITStatus
				 */
				inline void setFaultFlag(const CRITICAL_FAULT_FLAG_ENUM &aField) noexcept
				{
					MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG = aField;
				}
				/**
				 * @brief Get the MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG field of MCRxBITStatus
				 */
				inline CRITICAL_FAULT_FLAG_ENUM getFaultFlag() const noexcept
				{
					return MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG;
				}
				/**
				 * @brief Set the MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM field of MCRxBITStatus
				 */
				inline void set1LikelyFailSubSys(const MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM field of MCRxBITStatus
				 */
				inline MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get1LikelyFailSubSys() const noexcept
				{
					return MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM field of MCRxBITStatus
				 */
				inline void set2LikelyFailSubSys(const MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					MCRx_2ND_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the APSC_2ND_MOST_LIKELY_FAILED_SUBSYSTEM field of MCRxBITStatus
				 */
				inline MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get2LikelyFailSubSys() const noexcept
				{
					return MCRx_2ND_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM field of MCRxBITStatus
				 */
				inline void set3LikelyFailSubSys(const MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM &aField) noexcept
				{
					MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM = aField;
				}
				/**
				 * @brief Get the MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM field of MCRxBITStatus
				 */
				inline MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM get3LikelyFailSubSys() const noexcept
				{
					return MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM;
				}
				/**
				 * @brief Set the MCRx_RADAR_TIME_TAG_SEC field of MCRxBITStatus
				 */
				inline void setTimeTag(const SI::SISecond &aField) noexcept
				{
					MCRx_RADAR_TIME_TAG_SEC = aField;
				}
				/**
				 * @brief Get the MCRx_RADAR_TIME_TAG_SEC field of MCRxBITStatus
				 */
				inline SI::SISecond getTimeTagSec() const noexcept
				{
					return MCRx_RADAR_TIME_TAG_SEC;
				}
				/**
				 * @brief Set the MCRx_RADAR_TIME_TAG_NANOSEC field of MCRxBITStatus
				 */
				inline void setTimeTag(const SI::SINanoSecond &aField) noexcept
				{
					MCRx_RADAR_TIME_TAG_NANOSEC = aField;
				}
				/**
				 * @brief Get the MCRx_RADAR_TIME_TAG_NANOSEC field of MCRxBITStatus
				 */
				inline SI::SINanoSecond getTimeTagNanoSec() const noexcept
				{
					return MCRx_RADAR_TIME_TAG_NANOSEC;
				}
				/**
				 * @brief MCRxBITStatus template Serialise method
				 */
				template <class T>
				void Serialise(T &archive)
				{
					double timeTagSec{MCRx_RADAR_TIME_TAG_SEC()};
					double timeTagNanoSec{MCRx_RADAR_TIME_TAG_NANOSEC()};
					archive.Serialise(MCRx_PBIT_STATUS, "MCRx_PBIT_STATUS");
					archive.Serialise(MCRx_FAILURE_ID_IDENTIFICATION_CODE, "MCRx_FAILURE_ID_IDENTIFICATION_CODE");
					archive.Serialise(MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG, "MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG");
					archive.Serialise(MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM, "MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(MCRx_2ND_MOST_LIKELY_FAILED_SUBSYSTEM, "MCRx_2ND_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM, "MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM");
					archive.Serialise(timeTagSec, "MCRx_RADAR_TIME_TAG_SEC");
					archive.Serialise(timeTagNanoSec, "MCRx_RADAR_TIME_TAG_NANOSEC");
					MCRx_RADAR_TIME_TAG_SEC = timeTagSec;
					MCRx_RADAR_TIME_TAG_NANOSEC = timeTagNanoSec;
				}
				/**
				 * @brief MCRxBITStatus equality operator
				 */
				bool operator!=(const MCRxBITStatus &other) const
				{
					return !(*this == other);
				}
				/**
				 * @brief MCRxBITStatus equality operator
				 */
				bool operator==(const MCRxBITStatus &other) const
				{
					return (MCRx_PBIT_STATUS == other.MCRx_PBIT_STATUS &&
							MCRx_FAILURE_ID_IDENTIFICATION_CODE == other.MCRx_FAILURE_ID_IDENTIFICATION_CODE &&
							MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG == other.MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG &&
							MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM == other.MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM &&
							MCRx_2ND_MOST_LIKELY_FAILED_SUBSYSTEM == other.MCRx_2ND_MOST_LIKELY_FAILED_SUBSYSTEM &&
							MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM == other.MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM &&
							MCRx_RADAR_TIME_TAG_SEC == other.MCRx_RADAR_TIME_TAG_SEC &&
							MCRx_RADAR_TIME_TAG_NANOSEC == other.MCRx_RADAR_TIME_TAG_NANOSEC);
				}
				LCA_TOPIC("MCRxBITStatus", 1, 0)
			private:
				PBIT_STATUS_ENUM MCRx_PBIT_STATUS{PBIT_STATUS_ENUM::WAIT_PBIT};
				FAILURE_ID_IDENTIFICATION_CODE_ENUM MCRx_FAILURE_ID_IDENTIFICATION_CODE{FAILURE_ID_IDENTIFICATION_CODE_ENUM::NO_TEST_FAILURE};
				CRITICAL_FAULT_FLAG_ENUM MCRx_NON_CRITICAL_CRITICAL_FAULT_FLAG{CRITICAL_FAULT_FLAG_ENUM::NON_CRITICAL_FAULT};
				MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM MCRx_1ST_MOST_LIKELY_FAILED_SUBSYSTEM{MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::BACK_PLANE_ASSEMBLY};
				MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM MCRx_2ND_MOST_LIKELY_FAILED_SUBSYSTEM{MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::BACK_PLANE_ASSEMBLY};
				MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM MCRx_3RD_MOST_LIKELY_FAILED_SUBSYSTEM{MCRx_MOST_LIKELY_FAILED_SUBSYSTEM_ENUM::BACK_PLANE_ASSEMBLY};
				SI::SISecond MCRx_RADAR_TIME_TAG_SEC;
				SI::SINanoSecond MCRx_RADAR_TIME_TAG_NANOSEC;
			};

		}
	}
}

#endif