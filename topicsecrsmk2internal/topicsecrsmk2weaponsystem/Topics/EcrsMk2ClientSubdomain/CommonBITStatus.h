#ifndef COMMON_BIT_STATUS_H
#define COMMON_BIT_STATUS_H

#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WarmUP
    {
      enum class PBIT_STATUS_ENUM : uint8_t
      {
        WAIT_PBIT,
        PBIT_IN_PROGRESS,
        PBIT_COMPLETE_NO_FAIL,
        PBIT_COMPLETE_CRITICAL_FAIL,
        PBIT_COMPLETE_NO_CRITICAL_FAIL,
        PBIT_INHIBIT_CANC_NO_FAIL,
        PBIT_INHIBIT_CANC_CRITICAL_FAIL,
        PBIT_INHIBIT_CANC_NO_CRITICAL_FAIL
      };    
      enum class FAILURE_ID_IDENTIFICATION_CODE_ENUM : uint8_t
      {
        NO_TEST_FAILURE,
        TEST_1,
        TEST_2,
        TEST_3,
        TEST_4
      };
      enum class CRITICAL_FAULT_FLAG_ENUM : uint8_t
      {
        NON_CRITICAL_FAULT,
        CRITICAL_FAULT
      };
    }
  }
}

#endif