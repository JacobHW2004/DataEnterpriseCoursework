#ifndef BIT_COMMAND_H
#define BIT_COMMAND_H

#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WarmUP
    {
      enum class BIT_COMMAND_ENUM : uint8_t
      {
        UNCOMMANDED,
        FULL_POWER_UP=1,
        FULL_PBIT=1,
        FAST_POWER_UP=2,
        PBIT_INHIBIT_CANCEL=2
      };
      /**
       * @brief Power UP BIT Command topic
       */
      class BITCommand
      {
        public:
        /**
         * @brief Set the BIT_COMMAND field of BIT command
         */
        inline void setBITCmd(const BIT_COMMAND_ENUM& aField) noexcept
        {
          BIT_COMMAND = aField;
        }
        /**
         * @brief Get the BIT_COMMAND field of BIT command
         */
        inline BIT_COMMAND_ENUM getBITCmd() const noexcept
        {
          return BIT_COMMAND;
        }
        /**
         * @brief BITCommand template Serialise method
         */        
        template <class T>
        void Serialise(T &archive)
        {
          archive.Serialise(BIT_COMMAND, "BIT_COMMAND");
        }
        /**
         * @brief BITCommand inequality operator
         */        
        inline bool operator!=(const BITCommand &other) const
        {
          return !(*this == other);
        }
        /**
         * @brief BITCommand equality operator
         */
        inline bool operator==(const BITCommand &other) const
        {
          return (BIT_COMMAND == other.BIT_COMMAND);
        }
        LCA_TOPIC("BITCommand", 1, 0)
        private:
        BIT_COMMAND_ENUM BIT_COMMAND{BIT_COMMAND_ENUM::UNCOMMANDED};
      };
      
    }
  }
}

#endif