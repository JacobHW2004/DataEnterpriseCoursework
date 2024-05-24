#ifndef COMMAND_CHECKER_CONSTANTS_H
#define COMMAND_CHECKER_CONSTANTS_H

#include <cstdint>

namespace CommandCheckerConstants
{
    /*
    * Constants defined by Software
    */

    //Invalid Proxy Id
    constexpr uint32_t INVALID_PROXY_ID{ 0 };

} //namespace WeaponSystemTaskRouterConstants

namespace CommandCheckerLCA {
    
    /**
    *  @brief enum to represent rejection codes
    */
    enum class RejectionCode : int32_t
    {
        NONE = 0,
        SEARCH_NORMAL_TASKS_EXCEEDED = 0,
        TASK_IDENT_INVALID = 0,
        ASX_VOLUME_DIMENSION_PARAM_OUT_OF_RANGE = 0,
        INVALID_MOD_SCAN_START_POINT = 0,
        INVALID_TDI = 0,
        AREA_DIMENSION_OUT_OF_RANGE = 0,
        OUTWITH_AREA_INSTRUMENTED_COVERAGE = 0
    };

} 
#endif