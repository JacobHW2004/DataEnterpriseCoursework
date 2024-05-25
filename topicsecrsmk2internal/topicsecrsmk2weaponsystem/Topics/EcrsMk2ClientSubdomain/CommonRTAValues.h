#ifndef COMMON_RTA_VALUES
#define COMMON_RTA_VALUES

#include <stdint.h>

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {
      #define IcdDefaultsRta Topics::EcrsMK2::WeaponSystem::RapidTargetAcquisition
      namespace RapidTargetAcquisition
      {
        
        // Represents the actual source of pointing angle currently in use
        enum class RDRX_RTA_CNTR_SOURCE_ENUM : uint8_t
        {
          INVALID = 0x00,
          AC = 0x01,
          HEA = 0x02
        };
        // Dimension Type
        enum class RDRX_RTA_SPATIAL_ENUM : uint8_t
        {
          RDRX_AIR_SEARCH_RTA_INVALID = 0x00,
          RDRX_AIR_SEARCH_RTA_AIRCRAFT = 0x01,
        };

        // Suspend discrimination
        enum class RDRX_RTA_SUSPEND_DISC_ENUM : uint8_t
        {
          CONTINUE = 0x00,
          SUSPEND = 0x01
        };
        
        /**
         * @brief Default Message Values
         */
        static constexpr RDRX_RTA_CNTR_SOURCE_ENUM RDRX_RTA_CNTR_SOURCE_DEFAULT{RDRX_RTA_CNTR_SOURCE_ENUM::INVALID};
        static constexpr RDRX_RTA_SPATIAL_ENUM RDRX_RTA_SPATIAL_DEFAULT{RDRX_RTA_SPATIAL_ENUM::RDRX_AIR_SEARCH_RTA_INVALID};
        //_______________________________________________________________//
        
      }
      
    }
  }
}
#endif