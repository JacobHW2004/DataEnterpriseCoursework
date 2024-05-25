#ifndef WEAPON_SYSTEM_STATUS
#define WEAPON_SYSTEM_STATUS

#include <cstdint>
#include "CommonWeaponSystemValues.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {
      namespace Common
      {

        class Status
        {
        protected:

          /**
           * @brief Default Constructor
           */
          Status()
          {
          }

          /**
           * @brief Unique value of the current task
           */
          uint32_t TASK_IDENT { TASK_IDENT_DEFAULT};

          /**
           * @brief Current Task Type
            */
          WeaponSystemTaskType TASK_TYPE{ TASK_TYPE_DEFAULT };

          /**
           * @brief Provides the Task Modification Status
            */
          ModificationStatus COND_MOD_STATUS{ COND_MOD_STATUS_DEFAULT };

          /**
           * @brief Represents the current operational condition of the associated Task reported by the Nose Radar
            */
          CondState COND_STATE{ COND_STATE_DEFAULT };

          /**
           * @brief Represents the current detailed suspension condition of the associated Task reported by the Nose Radar
            */
          SuspensionDetail COND_SUSP_DETAIL{ COND_SUSP_DETAIL_DEFAULT };

          /**
           * @brief Contains the Task Demand Identifier value of the last Modification which has been accepted or rejected
            */
          uint16_t COND_MOD_TDI{ COND_MOD_TDI_DEFAULT };

          /**
           * @brief Provides the indication of the cause of the Task Rejection in the case of both creation and modification
            */
          uint16_t COND_REJECT_DETAIL{ COND_REJECT_DETAIL_DEFAULT };

          uint16_t ACTUAL_TDI{ TDI_DEFAULT };

        public:

          std::uint32_t getUti() const noexcept {
            return TASK_IDENT;  
          }

          void setUti(const std::uint32_t& uti) noexcept {
            TASK_IDENT = uti;
          }

          virtual WeaponSystemTaskType getTaskType() const noexcept {
            return TASK_TYPE;  
          }

          virtual void setTaskType(const Common::CommandValidity& validity) noexcept = 0;

          ModificationStatus getTaskModification() const noexcept {
            return COND_MOD_STATUS;
          }

          void setTaskModification(const ModificationStatus& modStatus) noexcept {
            COND_MOD_STATUS = modStatus;
          }

          CondState getTaskOperationalCondition() const noexcept {
            return COND_STATE;
          }

          void setTaskOperationalCondition(const CondState& condState) noexcept {
            COND_STATE = condState;
          }

          SuspensionDetail getTaskSuspensionCondition() const noexcept {
            return COND_SUSP_DETAIL;
          }

          void setTaskSuspensionCondition(const SuspensionDetail& suspensionDetail) noexcept {
            COND_SUSP_DETAIL = suspensionDetail;
          }
          
          /**
           * @brief getter for the Task Demand Identifier Modification
           * @returns the Task Demand Identifier Modification
           */
          const uint16_t getTaskDemandIdentifierModification() const {
            return COND_MOD_TDI;
          }

          /**
           * @brief setter for the Task Demand Identifier Modification
           * @param tdiModification : the Task Demand Identifier Modification to be set
           */
          const void setTaskDemandIdentifierModification(const uint16_t &tdiModification) {
            COND_MOD_TDI = tdiModification;
          }

          std::uint16_t getTaskRejectionDetail() const noexcept {
            return COND_REJECT_DETAIL;
          }

          void setTaskRejectionDetail(const std::uint16_t& taskRejectionDetail) noexcept {
            COND_REJECT_DETAIL = taskRejectionDetail;
          }

          uint16_t getActualTdi() const noexcept {
            return ACTUAL_TDI;
          }

          void setActualTdi(const uint16_t& tdi) noexcept {
            ACTUAL_TDI = tdi;
          }

          virtual void setToIcdDefault() noexcept {
            TASK_IDENT = TASK_IDENT_DEFAULT;
            TASK_TYPE = TASK_TYPE_DEFAULT;
            COND_MOD_STATUS = COND_MOD_STATUS_DEFAULT;
            COND_STATE = COND_STATE_DEFAULT;
            COND_SUSP_DETAIL = COND_SUSP_DETAIL_DEFAULT;
            COND_MOD_TDI = COND_MOD_TDI_DEFAULT;
            COND_REJECT_DETAIL = COND_REJECT_DETAIL_DEFAULT;
            ACTUAL_TDI = TDI_DEFAULT;
          }

        protected:
          /**
          * @brief equality operator
          * @returns true if other contains the same values, false otherwise
          */
          bool operator==(const Status& other) const
          {
            return 
              TASK_IDENT == other.TASK_IDENT &&
              TASK_TYPE == other.TASK_TYPE &&
              COND_MOD_STATUS == other.COND_MOD_STATUS &&
              COND_STATE == other.COND_STATE &&
              COND_SUSP_DETAIL == other.COND_SUSP_DETAIL &&
              COND_MOD_TDI == other.COND_MOD_TDI &&
              COND_REJECT_DETAIL == other.COND_REJECT_DETAIL &&
              ACTUAL_TDI == other.ACTUAL_TDI;
          }
        };
      }
    }
  }
};

#endif