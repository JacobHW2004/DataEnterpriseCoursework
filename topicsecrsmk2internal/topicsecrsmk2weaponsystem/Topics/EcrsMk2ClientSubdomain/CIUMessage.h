#ifndef CIU_MESSAGE_H
#define CIU_MESSAGE_H

#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WarmUP
    {

      enum class OVERRIDE_ENUM : uint8_t
      {
        NOT_OVRD,
        OVERRIDE
      };

      enum class AI_SECURE_DATA_ERASE_DMD_ENUM : uint8_t
      {
        NO_ERASE,
        RADAR_IFF_INT_FULL_ERASE = 0x0A
      };

      enum class FLIGHT_TEST_MODE_ENABLE_ENUM : uint8_t
      {
        FLIGHT_TEST_OFF,
        FLIGHT_TEST_ON
      };

      enum class FLIGHT_TEST_PROFILE_ENUM : uint8_t
      {
        PROFILE_1,
        PROFILE_2,
        PROFILE_3,
        PROFILE_4,
        PROFILE_5,
        PROFILE_6,
        PROFILE_7,
        PROFILE_8,
        PROFILE_9,
        PROFILE_10,
        SPARE
      };

      enum class PBIT_TYPE_REQUEST_ENUM : uint8_t
      {
        NORMAL,
        QUICK_PBIT,
        PBIT_INHIBIT_AND_CANCEL,
        SPARE
      };

      enum class FAST_RESP_PBIT_ENUM : uint8_t
      {
        NOT_FAST,
        FAST
      };

      enum class FLIGHT_TEST_FUNCTION_ENUM : uint8_t
      {
        FUNCTION_1_A,
        FUNCTION_2_B,
        FUNCTION_3_C,
        FUNCTION_4_D,
        FUNCTION_5_E,
        FUNCTION_6_F,
        FUNCTION_7_G,
        FUNCTION_8_H,
        FUNCTION_9_J,
        FUNCTION_10_K,
        FUNCTION_11_L,
        FUNCTION_12_M,
        FUNCTION_13_N,
        FUNCTION_14_P,
        FUNCTION_15_Q,
        SPARE
      };

      enum class RESET_CMD_ENUM : uint8_t
      {
        NOT_RESET,
        RESET = 3
      };

      using RADAR_THERMAL_OVRD_SELC_ENUM = OVERRIDE_ENUM;
      using BELOW_CP_OVRD_SELC_ENUM = OVERRIDE_ENUM;
      using SS01_RESET_CMD_ENUM = RESET_CMD_ENUM;
      using SS02_RESET_CMD_ENUM = RESET_CMD_ENUM;
      using SS03_RESET_CMD_ENUM = RESET_CMD_ENUM;
      using SS04_RESET_CMD_ENUM = RESET_CMD_ENUM;
      /**
       * @brief Cockpit Interface Unit Message topic
       */
      class CIUMessage
      {
        public:
        /**
         * @brief Set the AI_SECURE_DATA_ERASE_DMD field of Cockpit Interface Unit message
         */
        inline void setSecureDataErase(const AI_SECURE_DATA_ERASE_DMD_ENUM& aField) noexcept
        {
          AI_SECURE_DATA_ERASE_DMD = aField;
        }
        /**
         * @brief Set the FLIGHT_TEST_MODE_ENABLE field of Cockpit Interface Unit message
         */
        inline void setFlightTestModeEnable(const FLIGHT_TEST_MODE_ENABLE_ENUM& aField) noexcept
        {
          FLIGHT_TEST_MODE_ENABLE = aField;
        }
        /**
         * @brief Set the FLIGHT_TEST_FUNCTION field of Cockpit Interface Unit message
         */
        inline void setFlightFunction(const FLIGHT_TEST_FUNCTION_ENUM& aField) noexcept
        {
          FLIGHT_TEST_FUNCTION = aField;
        }
        /**
         * @brief Set the RADAR_THERMAL_OVRD_SELC field of Cockpit Interface Unit message
         */
        inline void setRadarThermalOvrd(const RADAR_THERMAL_OVRD_SELC_ENUM& aField) noexcept
        {
          RADAR_THERMAL_OVRD_SELC = aField;
        }
        /**
         * @brief Set the FLIGHT_TEST_PROFILE field of Cockpit Interface Unit message
         */
        inline void setFlighTestProfile(const FLIGHT_TEST_PROFILE_ENUM& aField) noexcept
        {
          FLIGHT_TEST_PROFILE = aField;
        }
        /**
         * @brief Set the FLIGHT_TEST_MODE_SET field of Cockpit Interface Unit message
         */
        inline void setFlighTestMode(bool aField) noexcept
        {
          FLIGHT_TEST_MODE_SET = aField;
        }
        /**
         * @brief Set the PBIT_TYPE_REQUEST field of Cockpit Interface Unit message
         */
        inline void setPBITTypeRequest(const PBIT_TYPE_REQUEST_ENUM& aField) noexcept
        {
          PBIT_TYPE_REQUEST = aField;
        }
        /**
         * @brief Set the SS01_RESET_CMD field of Cockpit Interface Unit message
         */
        inline void setSS01Reset(const SS01_RESET_CMD_ENUM& aField) noexcept
        {
          SS01_RESET_CMD = aField;
        }
        /**
         * @brief Set the SS02_RESET_CMD field of Cockpit Interface Unit message
         */
        inline void setSS02Reset(const SS02_RESET_CMD_ENUM& aField) noexcept
        {
          SS02_RESET_CMD = aField;
        }
        /**
         * @brief Set the SS03_RESET_CMD field of Cockpit Interface Unit message
         */
        inline void setSS03Reset(const SS03_RESET_CMD_ENUM& aField) noexcept
        {
          SS03_RESET_CMD = aField;
        }
        /**
         * @brief Set the SS04_RESET_CMD field of Cockpit Interface Unit message
         */
        inline void setSS04Reset(const SS04_RESET_CMD_ENUM& aField) noexcept
        {
          SS04_RESET_CMD = aField;
        }
        /**
         * @brief Get the AI_SECURE_DATA_ERASE_DMD field of Cockpit Interface Unit message
         */
        inline AI_SECURE_DATA_ERASE_DMD_ENUM getSecureDataErase() const noexcept
        {
          return AI_SECURE_DATA_ERASE_DMD;
        }
        /**
         * @brief Get the FLIGHT_TEST_MODE_ENABLE field of Cockpit Interface Unit message
         */
        inline FLIGHT_TEST_MODE_ENABLE_ENUM setFlightTestModeEnable() const noexcept
        {
          return FLIGHT_TEST_MODE_ENABLE;
        }
        /**
         * @brief Get the FLIGHT_TEST_FUNCTION field of Cockpit Interface Unit message
         */
        inline FLIGHT_TEST_FUNCTION_ENUM getFlightFunction() const noexcept
        {
          return FLIGHT_TEST_FUNCTION;
        }
        /**
         * @brief Get the RADAR_THERMAL_OVRD_SELC field of Cockpit Interface Unit message
         */
        inline RADAR_THERMAL_OVRD_SELC_ENUM setRadarThermalOvrd() const noexcept
        {
          return RADAR_THERMAL_OVRD_SELC;
        }
        /**
         * @brief Get the FLIGHT_TEST_PROFILE field of Cockpit Interface Unit message
         */
        inline FLIGHT_TEST_PROFILE_ENUM getFlighTestProfile() const noexcept
        {
          return FLIGHT_TEST_PROFILE;
        }
        /**
         * @brief Set the FLIGHT_TEST_MODE_SET field of Cockpit Interface Unit message
         */
        inline bool getFlighTestMode() const noexcept
        {
          return FLIGHT_TEST_MODE_SET;
        }
        /**
         * @brief Get the PBIT_TYPE_REQUEST field of Cockpit Interface Unit message
         */
        inline PBIT_TYPE_REQUEST_ENUM getPBITTypeRequest() const noexcept
        {
          return PBIT_TYPE_REQUEST;
        }
        /**
         * @brief Get the SS01_RESET_CMD field of Cockpit Interface Unit message
         */
        inline SS01_RESET_CMD_ENUM setSS01Reset() const noexcept
        {
          return SS01_RESET_CMD;
        }
        /**
         * @brief Get the SS02_RESET_CMD field of Cockpit Interface Unit message
         */
        inline SS02_RESET_CMD_ENUM getSS02Reset() const noexcept
        {
          return SS02_RESET_CMD;
        }
        /**
         * @brief Set the SS03_RESET_CMD field of Cockpit Interface Unit message
         */
        inline SS03_RESET_CMD_ENUM getSS03Reset() const noexcept
        {
          return SS03_RESET_CMD;
        }
        /**
         * @brief Get the SS04_RESET_CMD field of Cockpit Interface Unit message
         */
        inline SS04_RESET_CMD_ENUM setSS04Reset() const noexcept
        {
          return SS04_RESET_CMD;
        }
        /**
         * @brief CIUMessage equality operator
         */
        inline bool operator==(const CIUMessage &other) const
        {
          return (AI_SECURE_DATA_ERASE_DMD == other.AI_SECURE_DATA_ERASE_DMD &&
                  FLIGHT_TEST_MODE_ENABLE == other.FLIGHT_TEST_MODE_ENABLE &&
                  FLIGHT_TEST_FUNCTION == other.FLIGHT_TEST_FUNCTION &&
                  RADAR_THERMAL_OVRD_SELC == other.RADAR_THERMAL_OVRD_SELC &&
                  FLIGHT_TEST_PROFILE == other.FLIGHT_TEST_PROFILE &&
                  FLIGHT_TEST_MODE_SET == other.FLIGHT_TEST_MODE_SET &&
                  PBIT_TYPE_REQUEST == other.PBIT_TYPE_REQUEST &&
                  SS01_RESET_CMD == other.SS01_RESET_CMD &&
                  SS02_RESET_CMD == other.SS02_RESET_CMD &&
                  SS03_RESET_CMD == other.SS03_RESET_CMD &&
                  SS04_RESET_CMD == other.SS04_RESET_CMD);
        }
        /**
         * @brief CIUMessage inequality operator
         */
        inline bool operator!=(const CIUMessage &other) const
        {
          return !(*this == other);
        }
        /**
         * @brief CIUMessage template Serialise method
         */
        template <class T>
        void Serialise(T &archive)
        {
          archive.Serialise(AI_SECURE_DATA_ERASE_DMD, "AI_SECURE_DATA_ERASE_DMD");
          archive.Serialise(FLIGHT_TEST_MODE_ENABLE, "FLIGHT_TEST_MODE_ENABLE");
          archive.Serialise(FLIGHT_TEST_FUNCTION, "FLIGHT_TEST_FUNCTION");
          archive.Serialise(RADAR_THERMAL_OVRD_SELC, "RADAR_THERMAL_OVRD_SELC");
          archive.Serialise(FLIGHT_TEST_PROFILE, "FLIGHT_TEST_PROFILE");
          archive.Serialise(FLIGHT_TEST_MODE_SET, "FLIGHT_TEST_MODE_SET");
          archive.Serialise(PBIT_TYPE_REQUEST, "PBIT_TYPE_REQUEST");
          archive.Serialise(SS01_RESET_CMD, "SS01_RESET_CMD");
          archive.Serialise(SS02_RESET_CMD, "SS02_RESET_CMD");
          archive.Serialise(SS03_RESET_CMD, "SS03_RESET_CMD");
          archive.Serialise(SS04_RESET_CMD, "SS04_RESET_CMD");
        }
        LCA_TOPIC("CIUMessage", 1, 0)
        private:
        AI_SECURE_DATA_ERASE_DMD_ENUM AI_SECURE_DATA_ERASE_DMD{AI_SECURE_DATA_ERASE_DMD_ENUM::NO_ERASE};
        FLIGHT_TEST_MODE_ENABLE_ENUM FLIGHT_TEST_MODE_ENABLE{FLIGHT_TEST_MODE_ENABLE_ENUM::FLIGHT_TEST_OFF};
        FLIGHT_TEST_FUNCTION_ENUM FLIGHT_TEST_FUNCTION{FLIGHT_TEST_FUNCTION_ENUM::FUNCTION_1_A};
        RADAR_THERMAL_OVRD_SELC_ENUM RADAR_THERMAL_OVRD_SELC{RADAR_THERMAL_OVRD_SELC_ENUM::NOT_OVRD};
        FLIGHT_TEST_PROFILE_ENUM FLIGHT_TEST_PROFILE{FLIGHT_TEST_PROFILE_ENUM::PROFILE_1};
        bool FLIGHT_TEST_MODE_SET{false};
        PBIT_TYPE_REQUEST_ENUM PBIT_TYPE_REQUEST{PBIT_TYPE_REQUEST_ENUM::NORMAL};
        SS01_RESET_CMD_ENUM SS01_RESET_CMD{SS01_RESET_CMD_ENUM::NOT_RESET};
        SS02_RESET_CMD_ENUM SS02_RESET_CMD{SS02_RESET_CMD_ENUM::NOT_RESET};
        SS03_RESET_CMD_ENUM SS03_RESET_CMD{SS03_RESET_CMD_ENUM::NOT_RESET};
        SS04_RESET_CMD_ENUM SS04_RESET_CMD{SS04_RESET_CMD_ENUM::NOT_RESET};
      };
    }
  }
}

#endif