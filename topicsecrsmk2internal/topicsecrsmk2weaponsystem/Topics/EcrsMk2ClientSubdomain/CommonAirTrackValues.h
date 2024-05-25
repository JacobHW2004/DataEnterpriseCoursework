#ifndef COMMON_AIRTRACK_VALUES
#define COMMON_AIRTRACK_VALUES

#include <stdint.h>

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {
      namespace AirTrack
      {

        // Determines (in a command) or indicates (in a status)
        // whether Track Type Transitions are enabled (AUTO)
        // or whether the track type is fixed at Jam or Clear
        enum class RDRX_ATN_TXX_TYPE_TRANS_CTRL_ENUM : uint8_t
        {
          INVALID = 0x00,
          AUTO = 0x01,
          SET_JAM = 0x02,
          SET_CLEAR = 0x03
        };

        /**
         * @brief Default Message Values
         */
        static constexpr RDRX_ATN_TXX_TYPE_TRANS_CTRL_ENUM RDRX_ATN_TXX_TYPE_TRANS_CTRL_DEFAULT{RDRX_ATN_TXX_TYPE_TRANS_CTRL_ENUM::AUTO};
        //_______________________________________________________________//        
      }
    }
  }
}
#endif