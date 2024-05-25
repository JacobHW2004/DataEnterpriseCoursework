#ifndef MAINTENANCE_DATA_RETRIEVAL_H
#define MAINTENANCE_DATA_RETRIEVAL_H

#include <cstdint>
#include <cstring>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WarmUP
    {
      enum class DATA_TYPE_REQUEST_ENUM : uint8_t
      {
        CONFIGURATION_DATA,
        FAILURE_DATA,
        EVENT_DATA,
        RECONFIGURATION_STATUS
      };
      /**
       * @brief Maintenance Data Retrieval topic
       */
      class MaintenanceDataRetrieval
      {
        public:
        
        /**
         * @brief Set the HARDWARE_PART_NO field of MaintenanceDataRetrieval
         */
        inline void setDataTypeRequest(const DATA_TYPE_REQUEST_ENUM& aField) noexcept
        {
          DATA_TYPE_REQUEST = aField;
        }
        /**
         * @brief Get the HARDWARE_PART_NO field of MaintenanceDataRetrieval
         */
        inline DATA_TYPE_REQUEST_ENUM getDataTypeRequest() const noexcept
        {
          return DATA_TYPE_REQUEST;
        }
        /**
         * @brief MaintenanceDataRetrieval template Serialise method
         */           
        template <class T>
        void Serialise(T &archive)
        {
          archive.Serialise(DATA_TYPE_REQUEST, "DATA_TYPE_REQUEST");
        }
        /**
         * @brief MaintenanceDataRetrieval == operator
         */           
        bool operator==(const MaintenanceDataRetrieval &other) const
        {
          return (DATA_TYPE_REQUEST == other.DATA_TYPE_REQUEST); 
                 
        }
        /**
         * @brief MaintenanceDataRetrieval != operator
         */           
        bool operator!=(const MaintenanceDataRetrieval &other) const
        {
          return !(*this == other);
        }
        LCA_TOPIC("MaintenanceDataRetrieval", 1, 0)
        private:
        DATA_TYPE_REQUEST_ENUM DATA_TYPE_REQUEST{DATA_TYPE_REQUEST_ENUM::CONFIGURATION_DATA};
      };
    }
  }
}

#endif