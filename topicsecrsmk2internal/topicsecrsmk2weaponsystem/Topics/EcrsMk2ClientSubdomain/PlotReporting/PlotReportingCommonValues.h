#ifndef PLOT_REPORTING_COMMON_VALUES
#define PLOT_REPORTING_COMMON_VALUES

#include <stdint.h>

namespace Topics
{
  namespace PlotReporting
  {

    /**
     * @brief enumeration for the Plot Data Age setting
      */
    enum class PLOT_DATA_AGE_ENUM : uint8_t
    {
      AGE_AUTO       = 0x00,
      AGE_SECONDS_05 = 0x01,
      AGE_SECONDS_10 = 0x02,
      AGE_SECONDS_15 = 0x03
    };

    /**
     * @brief Default Message Values
      */
    static constexpr PLOT_DATA_AGE_ENUM PLOT_DATA_AGE_ENUM_DEFAULT { PLOT_DATA_AGE_ENUM::AGE_AUTO };
    //______________________________________________//


  }
}

#endif