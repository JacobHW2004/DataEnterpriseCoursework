#ifndef COMMON_WEAPONSYSTEM_VALUES
#define COMMON_WEAPONSYSTEM_VALUES

#include <stdint.h>
#include <string>

namespace Topics
{
  namespace EcrsMK2
  {     
    namespace WeaponSystem
    {
    #define IcdDefaults Topics::EcrsMK2::WeaponSystem::Common

      namespace Common
      {
        /**
         * @brief General enumeration for TransactionType. values of the enum matches RDRC_SN_X_CMD values within ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         */
        enum class CommandType : uint8_t
        {
          NO_TASK = 0x00,
          CREATE_TASK = 0x05,
          MODIFY_TASK = 0x0A,
          MAINTAIN_TASK = 0x13,
          SUSPEND_TASK = 0x16,
          RESUME_TASK = 0x19,
          DELETE_TASK = 0x1F
        };

        static std::string commandTypeToString(CommandType commandType)
        {
          std::string result {""};
          switch (commandType)
          {
            case Common::CommandType::CREATE_TASK :
              result = "Create";
              break;
            case Common::CommandType::RESUME_TASK :
              result = "Resume";
              break;
            case Common::CommandType::DELETE_TASK :
              result = "Deletion";
              break;
            case Common::CommandType::SUSPEND_TASK : 
              result = "Suspend";
              break;
            case Common::CommandType::MAINTAIN_TASK :
              result = "Maintain";
              break;
            case Common::CommandType::MODIFY_TASK :
              result = "Modify";
              break;
            default :
              result = "No Task";
              break;
          }
          return result;
        }

        // Task types
        enum class WeaponSystemTaskType : uint8_t
        {
          INVALID_TYPE = 0x00,
          AIR_SEARCH_NORMAL = 0x01,
          AIR_SEARCH_RAPID_TARGET_ACQUISITION = 0x03,
          SURFACE_SEARCH_NORMAL = 0x04,
          AIR_TRACK_NORMAL = 0x07,
          SURFACE_TRACK_NORMAL = 0x09,
          ELECT_AIR_SEARCH_NORMAL = 0x15,
          AIR_SEARCH_CUED = 0x16,
          ELECT_SURFACE_SEARCH_NORMAL = 0x17,
          SURFACE_SEARCH_CUED = 0x18
        };

        enum class ModificationStatus : uint8_t
        {
          NOT_COMMANDED = 0x00,
          ACCEPTED = 0x01,
          REJECTED = 0x02
        };

        /**
         * @brief enumeration for Task Detailed Suspension Condition
         */
        enum class SuspensionDetail : uint8_t
        {
          SUSPEND_NON_SPECIFIC = 0x00,
          SUSPEND_TASK_CTRL = 0x01,
          SUSPEND_CONCURRENCY = 0x02,
          SUSPEND_RTA_SELF = 0x03,
          SUSPEND_STEALTH = 0x04,
          SUSPEND_LRI_RESET = 0x05,
          SUSPEND_SUBSYS_RESET = 0x05,
          SUSPEND_COMPLETE_SUCCESSFUL = 0x06,
          SUSPEND_COMPLETE_UNSUCCESSFUL = 0x07,
          SUSPEND_FAULT_CONDITION = 0x08,
          SUSPEND_WEIGHT_ON_WHEELS = 0x09,
          SUSPEND_VISIDENT_SELF = 0x0A,
          SUSPEND_EA_PLAN_REACT_SELF = 0x0B,
          SUSPEND_EA_CEASE_SELF = 0x0C
        };

        /**
         * @brief General enumeration for TransactionState. values of the enum matches RDRS_SN_X_COND_STATE values within ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         */
        enum class CondState : uint8_t
        {
          NO_TASK = 0x00,
          ELIGIBLE = 0x05,
          INELIGIBLE = 0x0A,
          SUSPENDED = 0x13,
          REJECT_CREATION = 0x16,
          DELETED = 0x19
        };

        enum class CommandValidity
        {
          INVALID,
          VALID
        };

        // Transmit discrimination characteristic
        enum class TXDISC_ENUM : uint8_t
        {
          PASSIVE = 0x00,
          ACTIVE = 0x01
        };

        // positional quality rapid track revisits
        enum class IKTV_RAP_ATT_ENUM : uint8_t
        {
          NOT_RAPID = 0x00,
          RAPID = 0x01
        };

        /**
         * @brief enumeration for the Coordinate System for Search Volume
         */
        enum class AC_STABTYPE_ENUM : uint8_t
        {
          INVALID = 0x00,
          HORIZON_PR = 0x01,
          HORIZON_R = 0x02,
          AIRCRAFT_STABILISED = 0x03,
          NORTH_REFERENCED = 0x04
        };

        /**
         * @brief Default Message Values
         */
        static constexpr uint32_t TASK_IDENT_DEFAULT{0};
        static constexpr CommandType CMD_DEFAULT{CommandType::NO_TASK};
        static constexpr WeaponSystemTaskType TASK_TYPE_DEFAULT{WeaponSystemTaskType::INVALID_TYPE};
        static constexpr uint16_t TV_PRIORITY_DEFAULT{0};
        static constexpr TXDISC_ENUM TXDISC_DEFAULT{TXDISC_ENUM::ACTIVE};
        static constexpr uint32_t IKTV_PRIORITY_DEFAULT{0};
        static constexpr double IKTV_MIN_POS_X_DEFAULT{0.0};
        static constexpr double IKTV_MIN_POS_Z_DEFAULT{0.0};
        static constexpr IKTV_RAP_ATT_ENUM IKTV_MIN_RAP_ATT_DEFAULT{IKTV_RAP_ATT_ENUM::NOT_RAPID};
        static constexpr double IKTV_MIN_VEL_X_DEFAULT{0.0};
        static constexpr double IKTV_MIN_VEL_Z_DEFAULT{0.0};
        static constexpr double IKTV_DES_POS_X_DEFAULT{0.0};
        static constexpr double IKTV_DES_POS_Z_DEFAULT{0.0};
        static constexpr IKTV_RAP_ATT_ENUM IKTV_DES_RAP_ATT_DEFAULT{IKTV_RAP_ATT_ENUM::NOT_RAPID};
        static constexpr double IKTV_DES_VEL_X_DEFAULT{0.0};
        static constexpr double IKTV_DES_VEL_Z_DEFAULT{0.0};
        static constexpr bool IKTV_PROACT_DEFAULT{false};
        static constexpr uint16_t TDI_DEFAULT{0};
        static constexpr ModificationStatus COND_MOD_STATUS_DEFAULT{ModificationStatus::NOT_COMMANDED};
        static constexpr CondState COND_STATE_DEFAULT{CondState::NO_TASK};
        static constexpr SuspensionDetail COND_SUSP_DETAIL_DEFAULT{SuspensionDetail::SUSPEND_NON_SPECIFIC};
        static constexpr uint16_t COND_MOD_TDI_DEFAULT{0};
        static constexpr uint16_t COND_REJECT_DETAIL_DEFAULT{0};
        static constexpr uint8_t FRAME_COUNT_DEFAULT{0};
        //______________________________________________//

        /**
         * @brief Aircraft Referenced Specific Parameters
         */
        static constexpr AC_STABTYPE_ENUM AC_STABTYPE_DEFAULT{AC_STABTYPE_ENUM::HORIZON_PR};
        static constexpr double AC_AZ_CNTR_DEFAULT{0.0};
        static constexpr double AC_EL_CNTR_DEFAULT{0.0};
        static constexpr double AC_AZ_HALF_DEFAULT{0.0};
        static constexpr double AC_EL_HALF_DEFAULT{0.0};
        static constexpr float AC_SLT_MIN_DEFAULT{0.0F};
        static constexpr float AC_SLT_MAX_DEFAULT{0.0F};
        //_______________________________________________________________//

        /**
         * @brief Area Specific Parameters
         */
        static constexpr double CENTER_LINE_DEFAULT { 0.0 };
        static constexpr double AZ_HALF_DEFAULT { 0.0 };
        static constexpr double PLAN_MIN_DEFAULT { 0.0 };
        static constexpr double PLAN_MAX_DEFAULT { 0.0 };

      };    
    };
  };
};

#endif
