#ifndef WEAPON_SYSTEM_COMMAND
#define WEAPON_SYSTEM_COMMAND

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

        class Command
        {
        protected:

          /**
           * @brief Default Constructor
           */
          Command()
          {
          }


          /**
           * @brief Unique value of the current task
           */
          std::uint32_t TASK_IDENT{IcdDefaults::TASK_IDENT_DEFAULT};

          /**
           * @brief Represents the specific type of action to be performed by the Nose Radar for the associated Task
           */
          Common::CommandType CMD{IcdDefaults::CMD_DEFAULT};

          /**
           * @brief Represents the relative priority of the associated Task amongst all WS commanded Tasks
           */
          uint16_t TV_PRIORITY{IcdDefaults::TV_PRIORITY_DEFAULT};

          /**
           * @brief Set on task creation and changes every time a modification is made to each unique task
           */
          uint16_t TDI{IcdDefaults::TDI_DEFAULT};

        public:
          /**
           * @brief getter for the Task Identity
           * @returns the Task Identity
           */
          std::uint32_t getUti() const noexcept
          {
            return TASK_IDENT;
          }

          /**
           * @brief setter for the Task Demand Identifier
           * @param taskId : The task id to be set
           */
          void setUti(const std::uint32_t &taskId) noexcept
          {
            TASK_IDENT = taskId;
          }

          /**
           * @brief getter for the Task Identity
           * @returns the Task Identity
           */
          std::uint16_t getTdi() const noexcept
          {
            return TDI;
          }

          /**
           * @brief setter for the Task Demand Identifier
           * @param tdi : the task demand identifier to be set
           */
          void setTdi(const std::uint16_t &tdi) noexcept
          {
            TDI = tdi;
          }

          /**
           * @brief getter for the Specific Command Type
           * @returns the specific command type
           */
          Common::CommandType getSpecificCommandType() const noexcept
          {
            return CMD;
          }

          /**
           * @brief setter for the Specific Command Type
           * @param commandTypeIn : the command type to be set
           */
          void setCommandType(const Common::CommandType &commandTypeIn) noexcept
          {
            CMD = commandTypeIn;
          }

          virtual Common::WeaponSystemTaskType getTaskType() const noexcept 
          {
            return Common::WeaponSystemTaskType::INVALID_TYPE;
          }

          uint16_t getTvPriority() const noexcept
          {
            return TV_PRIORITY;
          }

          void setTvPriority(const uint16_t &prio) noexcept
          {
            TV_PRIORITY = prio;
          }

          virtual void setToIcdDefault() noexcept
          {
            TASK_IDENT = IcdDefaults::TASK_IDENT_DEFAULT;
            CMD = IcdDefaults::CMD_DEFAULT;
            TDI = IcdDefaults::TDI_DEFAULT;
            TV_PRIORITY = IcdDefaults::TV_PRIORITY_DEFAULT;
          }

        protected:
          /**
           * @brief equality operator
           * @returns true if other has the same Command type, false otherwise
           */
          bool operator==(const Command &other) const
          {
            return 
              TASK_IDENT == other.TASK_IDENT &&
              CMD == other.CMD &&
              TDI == other.TDI &&
              TV_PRIORITY == other.TV_PRIORITY &&
              getTaskType() == other.getTaskType();
          }
        };
      }
    }    
  }
};

#endif