#ifndef NAV_COMPUTER_NMAVIGATION_DATA_MESSAGE_TOPIC_H
#define NAV_COMPUTER_NMAVIGATION_DATA_MESSAGE_TOPIC_H

#include "Fabric/Utils/LCA_Macros.h"
#include "SIDegree.h"
#include "SIMeterPerSecondSquared.h"
#include "SIMeterPerSecond.h"
#include "SIMeter.h"
#include "SISquareMeter.h"
#include "FloatEqualityChecker.h"

#include <cstdint>
#include <string>

namespace Topics {

    // Task actions
    enum class TCN_CHANNEL_TYPE_ENUM : std::uint8_t {
        Y = 0x00,
        X = 0x01
    };

    enum class IN_DATA_DEGRADED_ENUM : std::uint8_t {
        NOT_DEGRADED = 0x00,
        DEGRADED = 0x01
    };
    
    enum class BANK_UNCERTAINTY_ENUM : std::uint8_t{
        INVALID = 0x00,
        STATE_1 = 0x01,
        STATE_2 = 0x02,
        STATE_3 = 0x03
    };

    enum class INCLINATION_UNCERTAINTY_ENUM : std::uint8_t{
        INVALID = 0x00,
        STATE_1 = 0x01,
        STATE_2 = 0x02,
        STATE_3 = 0x03
    };

    enum class TRUE_HDG_UNCERTAINTY_ENUM : std::uint8_t{
        STATE_2 = 0x00,
        STATE_1 = 0x01
    };

    enum class MMR_ACTIVE_NC_ENUM : std::uint8_t{
        STANDBY = 0x00,
        ACTIVE = 0x0F
    };

    enum class BEST_NAVIGATION_MODE_ENUM : std::uint8_t{
        SPARE = 0x00,
        MODE1 = 0x01,
        MODE2 = 0x02,
        MODE3 = 0x03,
        MODE4 = 0x04,
        MODE5 = 0x05,
        MODE6 = 0x06,
        MODE7 = 0x07,
        MODE8 = 0x08,
        NO_MODE = 0x0F
    };

    enum class TACAN_STEALTH_SELECTED_ENUM : std::uint8_t{
        NOT_SELECTED = 0x00,
        SELECTED = 0x01
    };

    enum class SAR_NAV_SOURCE_ENUM : std::uint8_t{
        NC91 = 0x00,
        GPS72 = 0x01
    };

    enum class BEST_PRESENT_POSITION_COV_DVAL_ENUM : std::uint8_t{
        INVALID_DEFAULT = 0x00,
        VALID = 0x01,
        HORIZONTAL_ONLY = 0x02,
        INVALID = 0x03
    };

    enum class BEST_VELOCITY_COV_DVAL_ENUM : std::uint8_t{
        INVALID_DEFAULT = 0x00,
        VALID = 0x01,
        HORIZONTAL_ONLY = 0x02,
        INVALID = 0x03
    };


    /**
    * @brief this topic is a strongly typed one to one mapping of Navigation Data - message NC91-BRD-HAT-MESS-1 (NAV Computer Navigation Data Message) from
    * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
    * DRL No:  1.17
    * Issue: A
    */
    struct NAVComputerNavigationDataMessage {

    public:

        //___________DEFAULT_MESSAGE_VALUES______________//
        // Default values are defined within the ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02

        static constexpr double BEST_BANK_DEFAULT {0.0};
        static constexpr double BEST_BODY_LINEAR_ACCEL_X_DEFAULT {0.0};
        static constexpr double BEST_BODY_LINEAR_ACCEL_Y_DEFAULT {0.0};
        static constexpr double BEST_BODY_LINEAR_ACCEL_Z_DEFAULT {0.0};
        static constexpr double BEST_INCLINATION_DEFAULT {0.0};
        static constexpr float BEST_ROLL_RATE_DEFAULT {0.0F};
        static constexpr float BEST_PITCH_RATE_DEFAULT {0.0F};
        static constexpr float BEST_YAW_RATE_DEFAULT {0.0F};
        static constexpr double BEST_TRUE_HEADING_DEFAULT {0.0};
        static constexpr std::uint8_t TCN_CHANNEL_NO_DEFAULT {1};
        static constexpr TCN_CHANNEL_TYPE_ENUM TCN_CHANNEL_TYPE_DEFAULT {TCN_CHANNEL_TYPE_ENUM::Y}; // ICD doesn't define a default, set to Y
        static constexpr double BEST_LATITUDE_NC_DEFAULT {0.0};
        static constexpr double BEST_LONGITUDE_NC_DEFAULT {0.0};
        static constexpr float BEST_NC_TIME_TAG_ALTITUDE_DEFAULT {0.0F};
        static constexpr float BEST_NC_TIME_TAG_ACCEL_DEFAULT {0.0F};
        static constexpr IN_DATA_DEGRADED_ENUM IN_DATA_DEGRADED_DEFAULT {IN_DATA_DEGRADED_ENUM::NOT_DEGRADED};
        static constexpr bool BEST_BANK_DVAL_DEFAULT {false};
        static constexpr bool BEST_BODY_ACCEL_DVAL_DEFAULT {false};
        static constexpr bool BEST_INCLINATION_DVAL_DEFAULT {false};
        static constexpr bool BEST_LINEAR_VEL_DVAL_DEFAULT {false};
        static constexpr bool BEST_AIR_AXS_ROT_RTS_DVAL_DEFAULT {false};
        static constexpr bool BEST_TRUE_ALTITUDE_DVAL_DEFAULT {false}; 
        static constexpr bool BEST_TRUE_HEADING_DVAL_DEFAULT {false};
        static constexpr bool BEST_VELOCITY_EAST_DVAL_DEFAULT {false};
        static constexpr bool BEST_VELOCITY_NORTH_DVAL_DEFAULT {false};
        static constexpr bool BEST_VERT_VELOCITY_DVAL_DEFAULT {false};
        static constexpr bool BEST_PRESENT_POSITION_DVAL_DEFAULT {false};
        static constexpr bool BEST_WIND_DVAL_DEFAULT {false};
        static constexpr bool BEST_GROUNDSPEED_DVAL_DEFAULT {false};
        static constexpr bool BEST_ALTITUDE_AB_ELLIPS_DVAL_DEFAULT {false};
        static constexpr float BEST_WIND_SPEED_DEFAULT {0.0F};
        static constexpr double BEST_WIND_DIRECTION_DEFAULT {0.0};
        static constexpr double BEST_GROUNDSPEED_DEFAULT {0.0}; // ICD doesn't define a default, set to zero
        static constexpr BANK_UNCERTAINTY_ENUM BANK_UNCERTAINTY_DEFAULT {BANK_UNCERTAINTY_ENUM::STATE_2};
        static constexpr INCLINATION_UNCERTAINTY_ENUM INCLINATION_UNCERTAINTY_DEFAULT {INCLINATION_UNCERTAINTY_ENUM::STATE_2};
        static constexpr TRUE_HDG_UNCERTAINTY_ENUM TRUE_HDG_UNCERTAINTY_DEFAULT {TRUE_HDG_UNCERTAINTY_ENUM::STATE_2};
        static constexpr MMR_ACTIVE_NC_ENUM MMR_ACTIVE_NC_DEFAULT {MMR_ACTIVE_NC_ENUM::STANDBY};
        static constexpr BEST_NAVIGATION_MODE_ENUM BEST_NAVIGATION_MODE_DEFAULT {BEST_NAVIGATION_MODE_ENUM::NO_MODE}; // ICD doesn't define a default, setting to NO-MODE
        static constexpr TACAN_STEALTH_SELECTED_ENUM TACAN_STEALTH_SELECTED_DEFAULT {TACAN_STEALTH_SELECTED_ENUM::NOT_SELECTED};
        static constexpr double ESTIMATED_ALT_ERROR_DEFAULT {0.0};
        static constexpr float ESTIMATED_POS_ERROR_NC_DEFAULT {0.0F};
        static constexpr double BEST_LINEAR_X_VELOCITY_NC_DEFAULT {0.0};
        static constexpr double BEST_LINEAR_Y_VELOCITY_NC_DEFAULT {0.0};
        static constexpr double BEST_LINEAR_Z_VELOCITY_NC_DEFAULT {0.0};
        static constexpr double BEST_VELOCITY_EAST_NC_DEFAULT {0.0};
        static constexpr double BEST_VELOCITY_NORTH_NC_DEFAULT {0.0}; 
        static constexpr double BEST_VERTICAL_VELOCITY_NC_DEFAULT {0.0};
        static constexpr float BEST_TRUE_ALTITUDE_NC_DEFAULT {0.0F}; 
        static constexpr float BEST_ALTITUDE_ABOVE_ELLIPSOID_DEFAULT {0.0F}; 
        static constexpr double BEST_POSITION_COVARIANCE_XX_DEFAULT {0.0}; 
        static constexpr double BEST_POSITION_COVARIANCE_YY_DEFAULT {0.0}; 
        static constexpr double BEST_POSITION_COVARIANCE_ZZ_DEFAULT {0.0}; 
        static constexpr double BEST_POSITION_COVARIANCE_XY_DEFAULT {0.0}; 
        static constexpr double BEST_POSITION_COVARIANCE_XZ_DEFAULT {0.0}; 
        static constexpr double BEST_POSITION_COVARIANCE_YZ_DEFAULT {0.0}; 
        static constexpr float BEST_VELOCITY_COVARIANCE_XX_DEFAULT {0.0F}; 
        static constexpr float BEST_VELOCITY_COVARIANCE_YY_DEFAULT {0.0F}; 
        static constexpr float BEST_VELOCITY_COVARIANCE_ZZ_DEFAULT {0.0F}; 
        static constexpr float BEST_VELOCITY_COVARIANCE_XY_DEFAULT {0.0F}; 
        static constexpr float BEST_VELOCITY_COVARIANCE_XZ_DEFAULT {0.0F}; 
        static constexpr float BEST_VELOCITY_COVARIANCE_YZ_DEFAULT {0.0F}; 
        static constexpr bool POS_FLAG_DEFAULT {false};
        static constexpr bool ALTITUDE_FLAG_DEFAULT {false};
        static constexpr bool HORIZ_VEL_FLAG_DEFAULT {false};
        static constexpr bool VERT_VEL_FLAG_DEFAULT {false};
        static constexpr bool COST_VEL_FLAG_DEFAULT {false};
        static constexpr bool COST_HDG_ATT_FLAG_DEFAULT {false};
        static constexpr bool LIN_ACC_FLAG_DEFAULT {false};
        static constexpr bool MACH_N_FLAG_DEFAULT {false};
        static constexpr bool INS_AIDED_FLAG_DEFAULT {false};
        static constexpr bool CONT_LIN_ACC_FLAG_DEFAULT {false};
        static constexpr bool ANGULAR_RATES_FLAG_DEFAULT {false};
        static constexpr bool CONT_MACH_N_FLAG_DEFAULT {false};
        static constexpr bool INS_AIDED_10MIN_FLAG_DEFAULT {false};
        static constexpr bool FOM1_FLAG_DEFAULT {false};
        static constexpr bool MASTER_NAV_FLAG_1_DEFAULT {false};
        static constexpr bool MASTER_NAV_FLAG_2_DEFAULT {false};
        static constexpr bool MASTER_NAV_FLAG_3_DEFAULT {false};
        static constexpr bool MASTER_NAV_FLAG_4_DEFAULT {false};
        static constexpr bool MASTER_NAV_FLAG_5_DEFAULT {false};
        static constexpr float MN_FLAGS_TIME_TAG_DEFAULT {0.0F};
        static constexpr float GPS_FLAGS_TIME_TAG_DEFAULT {0.0F};
        static constexpr float FCS_FLAGS_TIME_TAG_DEFAULT {0.0F};
        static constexpr SAR_NAV_SOURCE_ENUM SAR_NAV_SOURCE_DEFAULT {SAR_NAV_SOURCE_ENUM::NC91};  // ICD doesn't define a default, set to NC91
        static constexpr BEST_PRESENT_POSITION_COV_DVAL_ENUM BEST_PRESENT_POSITION_COV_DVAL_DEFAULT {BEST_PRESENT_POSITION_COV_DVAL_ENUM::INVALID_DEFAULT};
        static constexpr BEST_VELOCITY_COV_DVAL_ENUM BEST_VELOCITY_COV_DVAL_DEFAULT {BEST_VELOCITY_COV_DVAL_ENUM::INVALID_DEFAULT};
        static constexpr float BEST_NC_TIME_TAG_ANGLES_DEFAULT {0.0F};
        static constexpr float BEST_NC_TIME_TAG_VEL_GEOD_DEFAULT {0.0F}; 
        static constexpr float BEST_NC_TIME_TAG_VEL_LINEAR_DEFAULT {0.0F}; 
        static constexpr std::uint64_t BEST_NC_TIME_TAG_PP_DEFAULT {0}; 

        //______________________________________________//

        SI::SIDegree BEST_BANK{};
        SI::SIMeterPerSecondSquared BEST_BODY_LINEAR_ACCEL_X {};
        SI::SIMeterPerSecondSquared BEST_BODY_LINEAR_ACCEL_Y {};
        SI::SIMeterPerSecondSquared BEST_BODY_LINEAR_ACCEL_Z {};
        SI::SIDegree BEST_INCLINATION {};
        float BEST_ROLL_RATE {}; // degrees/s
        float BEST_PITCH_RATE {}; // degrees/s
        float BEST_YAW_RATE{}; // degrees/s
        SI::SIDegree BEST_TRUE_HEADING{};
        std::uint8_t TCN_CHANNEL_NO{};
        TCN_CHANNEL_TYPE_ENUM TCN_CHANNEL_TYPE{};
        SI::SIDegree BEST_LATITUDE_NC {};
        SI::SIDegree BEST_LONGITUDE_NC {};
        float BEST_NC_TIME_TAG_ALTITUDE{}; //microsecond
        float BEST_NC_TIME_TAG_ACCEL{}; //microsecond
        IN_DATA_DEGRADED_ENUM IN_DATA_DEGRADED{};
        bool BEST_BANK_DVAL {};
        bool BEST_BODY_ACCEL_DVAL {};
        bool BEST_INCLINATION_DVAL {};
        bool BEST_LINEAR_VEL_DVAL {};
        bool BEST_AIR_AXS_ROT_RTS_DVAL{};
        bool BEST_TRUE_ALTITUDE_DVAL {}; 
        bool BEST_TRUE_HEADING_DVAL {};
        bool BEST_VELOCITY_EAST_DVAL {};
        bool BEST_VELOCITY_NORTH_DVAL {};
        bool BEST_VERT_VELOCITY_DVAL {};
        bool BEST_PRESENT_POSITION_DVAL {};
        bool BEST_WIND_DVAL {};
        bool BEST_GROUNDSPEED_DVAL {};
        bool BEST_ALTITUDE_AB_ELLIPS_DVAL {};
        float BEST_WIND_SPEED {}; // knots
        SI::SIDegree BEST_WIND_DIRECTION {};
        SI::SIMeterPerSecond BEST_GROUNDSPEED {};
        BANK_UNCERTAINTY_ENUM BANK_UNCERTAINTY {};
        INCLINATION_UNCERTAINTY_ENUM INCLINATION_UNCERTAINTY {};
        TRUE_HDG_UNCERTAINTY_ENUM TRUE_HDG_UNCERTAINTY {};
        MMR_ACTIVE_NC_ENUM MMR_ACTIVE_NC{};
        BEST_NAVIGATION_MODE_ENUM BEST_NAVIGATION_MODE {};
        TACAN_STEALTH_SELECTED_ENUM TACAN_STEALTH_SELECTED {};
        SI::SIMeter ESTIMATED_ALT_ERROR {};
        float ESTIMATED_POS_ERROR_NC {}; // Nautical Miles
        SI::SIMeterPerSecond BEST_LINEAR_X_VELOCITY_NC {};
        SI::SIMeterPerSecond BEST_LINEAR_Y_VELOCITY_NC {};
        SI::SIMeterPerSecond BEST_LINEAR_Z_VELOCITY_NC {};
        SI::SIMeterPerSecond BEST_VELOCITY_EAST_NC {}; 
        SI::SIMeterPerSecond BEST_VELOCITY_NORTH_NC {}; 
        SI::SIMeterPerSecond BEST_VERTICAL_VELOCITY_NC {}; 
        float BEST_TRUE_ALTITUDE_NC {}; //ft
        float BEST_ALTITUDE_ABOVE_ELLIPSOID{}; //  ft
        SI::SISquareMeter BEST_POSITION_COVARIANCE_XX{};
        SI::SISquareMeter BEST_POSITION_COVARIANCE_YY{};
        SI::SISquareMeter BEST_POSITION_COVARIANCE_ZZ{};
        SI::SISquareMeter BEST_POSITION_COVARIANCE_XY{};
        SI::SISquareMeter BEST_POSITION_COVARIANCE_XZ{};
        SI::SISquareMeter BEST_POSITION_COVARIANCE_YZ{};
        float BEST_VELOCITY_COVARIANCE_XX{};
        float BEST_VELOCITY_COVARIANCE_YY{};
        float BEST_VELOCITY_COVARIANCE_ZZ{};
        float BEST_VELOCITY_COVARIANCE_XY{};
        float BEST_VELOCITY_COVARIANCE_XZ{};
        float BEST_VELOCITY_COVARIANCE_YZ{};
        bool POS_FLAG{};
        bool ALTITUDE_FLAG{};
        bool HORIZ_VEL_FLAG{};
        bool VERT_VEL_FLAG{};
        bool COST_VEL_FLAG{};
        bool COST_HDG_ATT_FLAG{};
        bool LIN_ACC_FLAG{};
        bool MACH_N_FLAG{};
        bool INS_AIDED_FLAG{};
        bool CONT_LIN_ACC_FLAG{};
        bool ANGULAR_RATES_FLAG{};
        bool CONT_MACH_N_FLAG{};
        bool INS_AIDED_10MIN_FLAG{};
        bool FOM1_FLAG{};
        bool MASTER_NAV_FLAG_1{};
        bool MASTER_NAV_FLAG_2{};
        bool MASTER_NAV_FLAG_3{};
        bool MASTER_NAV_FLAG_4{};
        bool MASTER_NAV_FLAG_5{};
        float MN_FLAGS_TIME_TAG{};
        float GPS_FLAGS_TIME_TAG{};
        float FCS_FLAGS_TIME_TAG{};
        SAR_NAV_SOURCE_ENUM SAR_NAV_SOURCE{};
        BEST_PRESENT_POSITION_COV_DVAL_ENUM BEST_PRESENT_POSITION_COV_DVAL{};
        BEST_VELOCITY_COV_DVAL_ENUM BEST_VELOCITY_COV_DVAL{};
        float BEST_NC_TIME_TAG_ANGLES {}; // microseconds
        float BEST_NC_TIME_TAG_VEL_GEOD {}; // microseconds
        float BEST_NC_TIME_TAG_VEL_LINEAR {}; // microseconds
        std::uint64_t BEST_NC_TIME_TAG_PP {}; // count representation of a system_clock timepoint

        

        bool operator==(const NAVComputerNavigationDataMessage& other) const
        {

        return BEST_BANK == other.BEST_BANK &&
        BEST_BODY_LINEAR_ACCEL_X == other.BEST_BODY_LINEAR_ACCEL_X &&
        BEST_BODY_LINEAR_ACCEL_Y == other.BEST_BODY_LINEAR_ACCEL_Y &&
        BEST_BODY_LINEAR_ACCEL_Z == other.BEST_BODY_LINEAR_ACCEL_Z &&
        BEST_INCLINATION == other.BEST_INCLINATION &&
        SI::floatEqualityChecker::AlmostEqual(BEST_ROLL_RATE, other.BEST_ROLL_RATE) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_PITCH_RATE, other.BEST_PITCH_RATE) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_YAW_RATE, other.BEST_YAW_RATE) &&
        BEST_TRUE_HEADING == other.BEST_TRUE_HEADING &&
        TCN_CHANNEL_NO == other.TCN_CHANNEL_NO &&
        TCN_CHANNEL_TYPE == other.TCN_CHANNEL_TYPE &&
        BEST_LATITUDE_NC == other.BEST_LATITUDE_NC &&
        BEST_LONGITUDE_NC == other.BEST_LONGITUDE_NC &&
        SI::floatEqualityChecker::AlmostEqual(BEST_NC_TIME_TAG_ALTITUDE, other.BEST_NC_TIME_TAG_ALTITUDE) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_NC_TIME_TAG_ACCEL, other.BEST_NC_TIME_TAG_ACCEL) &&
        IN_DATA_DEGRADED == other.IN_DATA_DEGRADED &&
        BEST_BANK_DVAL == other.BEST_BANK_DVAL &&
        BEST_BODY_ACCEL_DVAL == other.BEST_BODY_ACCEL_DVAL &&
        BEST_INCLINATION_DVAL == other.BEST_INCLINATION_DVAL &&
        BEST_LINEAR_VEL_DVAL == other.BEST_LINEAR_VEL_DVAL &&
        BEST_AIR_AXS_ROT_RTS_DVAL == other.BEST_AIR_AXS_ROT_RTS_DVAL &&
        BEST_TRUE_ALTITUDE_DVAL == other.BEST_TRUE_ALTITUDE_DVAL &&
        BEST_TRUE_HEADING_DVAL == other.BEST_TRUE_HEADING_DVAL &&
        BEST_VELOCITY_EAST_DVAL == other.BEST_VELOCITY_EAST_DVAL &&
        BEST_VELOCITY_NORTH_DVAL == other.BEST_VELOCITY_NORTH_DVAL &&
        BEST_VERT_VELOCITY_DVAL == other.BEST_VERT_VELOCITY_DVAL &&
        BEST_PRESENT_POSITION_DVAL == other.BEST_PRESENT_POSITION_DVAL &&
        BEST_WIND_DVAL == other.BEST_WIND_DVAL &&
        BEST_GROUNDSPEED_DVAL == other.BEST_GROUNDSPEED_DVAL &&
        BEST_ALTITUDE_AB_ELLIPS_DVAL == other.BEST_ALTITUDE_AB_ELLIPS_DVAL &&
        SI::floatEqualityChecker::AlmostEqual(BEST_WIND_SPEED, other.BEST_WIND_SPEED) &&
        BEST_WIND_DIRECTION == other.BEST_WIND_DIRECTION &&
        BEST_GROUNDSPEED == other.BEST_GROUNDSPEED &&
        BANK_UNCERTAINTY == other.BANK_UNCERTAINTY &&
        INCLINATION_UNCERTAINTY == other.INCLINATION_UNCERTAINTY &&
        TRUE_HDG_UNCERTAINTY == other.TRUE_HDG_UNCERTAINTY &&
        MMR_ACTIVE_NC == other.MMR_ACTIVE_NC &&
        BEST_NAVIGATION_MODE == other.BEST_NAVIGATION_MODE &&
        TACAN_STEALTH_SELECTED == other.TACAN_STEALTH_SELECTED &&
        ESTIMATED_ALT_ERROR == other.ESTIMATED_ALT_ERROR &&
        SI::floatEqualityChecker::AlmostEqual(ESTIMATED_POS_ERROR_NC, other.ESTIMATED_POS_ERROR_NC) &&
        BEST_LINEAR_X_VELOCITY_NC == other.BEST_LINEAR_X_VELOCITY_NC &&
        BEST_LINEAR_Y_VELOCITY_NC == other.BEST_LINEAR_Y_VELOCITY_NC &&
        BEST_LINEAR_Z_VELOCITY_NC == other.BEST_LINEAR_Z_VELOCITY_NC &&
        BEST_VELOCITY_EAST_NC == other.BEST_VELOCITY_EAST_NC &&
        BEST_VELOCITY_NORTH_NC == other.BEST_VELOCITY_NORTH_NC &&
        BEST_VERTICAL_VELOCITY_NC == other.BEST_VERTICAL_VELOCITY_NC &&
        SI::floatEqualityChecker::AlmostEqual(BEST_TRUE_ALTITUDE_NC, other.BEST_TRUE_ALTITUDE_NC) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_ALTITUDE_ABOVE_ELLIPSOID, other.BEST_ALTITUDE_ABOVE_ELLIPSOID) &&
        BEST_POSITION_COVARIANCE_XX == other.BEST_POSITION_COVARIANCE_XX &&
        BEST_POSITION_COVARIANCE_YY == other.BEST_POSITION_COVARIANCE_YY &&
        BEST_POSITION_COVARIANCE_ZZ == other.BEST_POSITION_COVARIANCE_ZZ &&
        BEST_POSITION_COVARIANCE_XY == other.BEST_POSITION_COVARIANCE_XY &&
        BEST_POSITION_COVARIANCE_XZ == other.BEST_POSITION_COVARIANCE_XZ &&
        BEST_POSITION_COVARIANCE_YZ == other.BEST_POSITION_COVARIANCE_YZ &&
        SI::floatEqualityChecker::AlmostEqual(BEST_VELOCITY_COVARIANCE_XX, other.BEST_VELOCITY_COVARIANCE_XX) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_VELOCITY_COVARIANCE_YY, other.BEST_VELOCITY_COVARIANCE_YY) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_VELOCITY_COVARIANCE_ZZ, other.BEST_VELOCITY_COVARIANCE_ZZ) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_VELOCITY_COVARIANCE_XY, other.BEST_VELOCITY_COVARIANCE_XY) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_VELOCITY_COVARIANCE_XZ, other.BEST_VELOCITY_COVARIANCE_XZ) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_VELOCITY_COVARIANCE_YZ, other.BEST_VELOCITY_COVARIANCE_YZ) &&
        POS_FLAG == other.POS_FLAG &&
        ALTITUDE_FLAG == other.ALTITUDE_FLAG &&
        HORIZ_VEL_FLAG == other.HORIZ_VEL_FLAG &&
        VERT_VEL_FLAG == other.VERT_VEL_FLAG &&
        COST_VEL_FLAG == other.COST_VEL_FLAG &&
        COST_HDG_ATT_FLAG == other.COST_HDG_ATT_FLAG &&
        LIN_ACC_FLAG == other.LIN_ACC_FLAG &&
        MACH_N_FLAG == other.MACH_N_FLAG &&
        INS_AIDED_FLAG == other.INS_AIDED_FLAG &&
        CONT_LIN_ACC_FLAG == other.CONT_LIN_ACC_FLAG &&
        ANGULAR_RATES_FLAG == other.ANGULAR_RATES_FLAG &&
        CONT_MACH_N_FLAG == other.CONT_MACH_N_FLAG &&
        INS_AIDED_10MIN_FLAG == other.INS_AIDED_10MIN_FLAG &&
        FOM1_FLAG == other.FOM1_FLAG &&
        MASTER_NAV_FLAG_1 == other.MASTER_NAV_FLAG_1 &&
        MASTER_NAV_FLAG_2 == other.MASTER_NAV_FLAG_2 &&
        MASTER_NAV_FLAG_3 == other.MASTER_NAV_FLAG_3 &&
        MASTER_NAV_FLAG_4 == other.MASTER_NAV_FLAG_4 &&
        MASTER_NAV_FLAG_5 == other.MASTER_NAV_FLAG_5 &&
        SI::floatEqualityChecker::AlmostEqual(MN_FLAGS_TIME_TAG, other.MN_FLAGS_TIME_TAG) &&
        SI::floatEqualityChecker::AlmostEqual(GPS_FLAGS_TIME_TAG, other.GPS_FLAGS_TIME_TAG) &&
        SI::floatEqualityChecker::AlmostEqual(FCS_FLAGS_TIME_TAG, other.FCS_FLAGS_TIME_TAG) &&
        SAR_NAV_SOURCE == other.SAR_NAV_SOURCE &&
        BEST_PRESENT_POSITION_COV_DVAL == other.BEST_PRESENT_POSITION_COV_DVAL &&
        BEST_VELOCITY_COV_DVAL == other.BEST_VELOCITY_COV_DVAL &&
        SI::floatEqualityChecker::AlmostEqual(BEST_NC_TIME_TAG_ANGLES, other.BEST_NC_TIME_TAG_ANGLES) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_NC_TIME_TAG_VEL_GEOD, other.BEST_NC_TIME_TAG_VEL_GEOD) &&
        SI::floatEqualityChecker::AlmostEqual(BEST_NC_TIME_TAG_VEL_LINEAR, other.BEST_NC_TIME_TAG_VEL_LINEAR) &&
        BEST_NC_TIME_TAG_PP == other.BEST_NC_TIME_TAG_PP;

        }

        bool operator!=(const NAVComputerNavigationDataMessage& other) const
        {
            return !(*this == other);
        }

        /**
        * @brief Serialise function required for communications
        * @todo serialise the fields in this topic.
        */
        template <class T>
        void Serialise(T& archive) {

            double doubleBEST_BANK{ BEST_BANK() };
            double doubleBEST_BODY_LINEAR_ACCEL_X{ BEST_BODY_LINEAR_ACCEL_X() };
            double doubleBEST_BODY_LINEAR_ACCEL_Y{ BEST_BODY_LINEAR_ACCEL_Y() };
            double doubleBEST_BODY_LINEAR_ACCEL_Z{ BEST_BODY_LINEAR_ACCEL_Z() };
            double doubleBEST_INCLINATION{ BEST_INCLINATION() };
            double doubleBEST_TRUE_HEADING{ BEST_TRUE_HEADING() };
            double doubleBEST_LATITUDE_NC{ BEST_LATITUDE_NC() };
            double doubleBEST_LONGITUDE_NC{ BEST_LONGITUDE_NC() };
            double doubleBEST_GROUNDSPEED{ BEST_GROUNDSPEED() };
            double doubleBEST_WIND_DIRECTION{ BEST_WIND_DIRECTION() };
            double doubleESTIMATED_ALT_ERROR{ ESTIMATED_ALT_ERROR() };
            double doubleBEST_LINEAR_X_VELOCITY_NC{ BEST_LINEAR_X_VELOCITY_NC() };
            double doubleBEST_LINEAR_Y_VELOCITY_NC{ BEST_LINEAR_Y_VELOCITY_NC() };
            double doubleBEST_LINEAR_Z_VELOCITY_NC{ BEST_LINEAR_Z_VELOCITY_NC() };
            double doubleBEST_VELOCITY_EAST_NC{ BEST_VELOCITY_EAST_NC() };
            double doubleBEST_VELOCITY_NORTH_NC{ BEST_VELOCITY_NORTH_NC() };
            double doubleBEST_VERTICAL_VELOCITY_NC{ BEST_VERTICAL_VELOCITY_NC() };
            double doubleBEST_POSITION_COVARIANCE_XX{ BEST_POSITION_COVARIANCE_XX() };
            double doubleBEST_POSITION_COVARIANCE_YY{ BEST_POSITION_COVARIANCE_YY() };
            double doubleBEST_POSITION_COVARIANCE_ZZ{ BEST_POSITION_COVARIANCE_ZZ() };
            double doubleBEST_POSITION_COVARIANCE_XY{ BEST_POSITION_COVARIANCE_XY() };
            double doubleBEST_POSITION_COVARIANCE_XZ{ BEST_POSITION_COVARIANCE_XZ() };
            double doubleBEST_POSITION_COVARIANCE_YZ{ BEST_POSITION_COVARIANCE_YZ() };

            archive.Serialise(doubleBEST_BANK, "BEST_BANK");
            archive.Serialise(doubleBEST_BODY_LINEAR_ACCEL_X, "BEST_BODY_LINEAR_ACCEL_X");
            archive.Serialise(doubleBEST_BODY_LINEAR_ACCEL_Y, "BEST_BODY_LINEAR_ACCEL_Y");
            archive.Serialise(doubleBEST_BODY_LINEAR_ACCEL_Z, "BEST_BODY_LINEAR_ACCEL_Z");
            archive.Serialise(doubleBEST_INCLINATION, "BEST_INCLINATION");
            archive.Serialise(BEST_ROLL_RATE, "BEST_ROLL_RATE");
            archive.Serialise(BEST_PITCH_RATE, "BEST_PITCH_RATE");
            archive.Serialise(BEST_YAW_RATE, "BEST_YAW_RATE");
            archive.Serialise(doubleBEST_TRUE_HEADING, "BEST_TRUE_HEADING");
            archive.Serialise(TCN_CHANNEL_NO, "TCN_CHANNEL_NO");
            archive.Serialise(TCN_CHANNEL_TYPE, "TCN_CHANNEL_TYPE");
            archive.Serialise(doubleBEST_LATITUDE_NC, "BEST_LATITUDE_NC");
            archive.Serialise(doubleBEST_LONGITUDE_NC, "BEST_LONGITUDE_NC");
            archive.Serialise(BEST_NC_TIME_TAG_ALTITUDE, "BEST_NC_TIME_TAG_ALTITUDE");
            archive.Serialise(BEST_NC_TIME_TAG_ACCEL, "BEST_NC_TIME_TAG_ACCEL");
            archive.Serialise(IN_DATA_DEGRADED, "IN_DATA_DEGRADED");
            archive.Serialise(BEST_BANK_DVAL, "BEST_BANK_DVAL");
            archive.Serialise(BEST_BODY_ACCEL_DVAL, "BEST_BODY_ACCEL_DVAL");
            archive.Serialise(BEST_INCLINATION_DVAL, "BEST_INCLINATION_DVAL");
            archive.Serialise(BEST_LINEAR_VEL_DVAL, "BEST_LINEAR_VEL_DVAL");
            archive.Serialise(BEST_AIR_AXS_ROT_RTS_DVAL, "BEST_AIR_AXS_ROT_RTS_DVAL");
            archive.Serialise(BEST_TRUE_ALTITUDE_DVAL, "BEST_TRUE_ALTITUDE_DVAL");
            archive.Serialise(BEST_TRUE_HEADING_DVAL, "BEST_TRUE_HEADING_DVAL");
            archive.Serialise(BEST_VELOCITY_EAST_DVAL, "BEST_VELOCITY_EAST_DVAL");
            archive.Serialise(BEST_VELOCITY_NORTH_DVAL, "BEST_VELOCITY_NORTH_DVAL");
            archive.Serialise(BEST_VERT_VELOCITY_DVAL, "BEST_VERT_VELOCITY_DVAL");
            archive.Serialise(BEST_PRESENT_POSITION_DVAL, "BEST_PRESENT_POSITION_DVAL");
            archive.Serialise(BEST_WIND_DVAL, "BEST_WIND_DVAL");
            archive.Serialise(BEST_GROUNDSPEED_DVAL, "BEST_GROUNDSPEED_DVAL");
            archive.Serialise(BEST_ALTITUDE_AB_ELLIPS_DVAL, "BEST_ALTITUDE_AB_ELLIPS_DVAL");
            archive.Serialise(BEST_WIND_SPEED, "BEST_WIND_SPEED");
            archive.Serialise(doubleBEST_WIND_DIRECTION, "BEST_WIND_DIRECTION");
            archive.Serialise(doubleBEST_GROUNDSPEED, "BEST_GROUNDSPEED");
            archive.Serialise(BANK_UNCERTAINTY, "BANK_UNCERTAINTY");
            archive.Serialise(INCLINATION_UNCERTAINTY, "INCLINATION_UNCERTAINTY");
            archive.Serialise(TRUE_HDG_UNCERTAINTY, "TRUE_HDG_UNCERTAINTY");
            archive.Serialise(MMR_ACTIVE_NC, "MMR_ACTIVE_NC");
            archive.Serialise(BEST_NAVIGATION_MODE, "BEST_NAVIGATION_MODE");
            archive.Serialise(TACAN_STEALTH_SELECTED, "TACAN_STEALTH_SELECTED");
            archive.Serialise(doubleESTIMATED_ALT_ERROR, "ESTIMATED_ALT_ERROR");
            archive.Serialise(ESTIMATED_POS_ERROR_NC, "ESTIMATED_POS_ERROR_NC");
            archive.Serialise(doubleBEST_LINEAR_X_VELOCITY_NC, "BEST_LINEAR_X_VELOCITY_NC");
            archive.Serialise(doubleBEST_LINEAR_Y_VELOCITY_NC, "BEST_LINEAR_Y_VELOCITY_NC");
            archive.Serialise(doubleBEST_LINEAR_Z_VELOCITY_NC, "BEST_LINEAR_Z_VELOCITY_NC");
            archive.Serialise(doubleBEST_VELOCITY_EAST_NC, "BEST_VELOCITY_EAST_NC");
            archive.Serialise(doubleBEST_VELOCITY_NORTH_NC, "BEST_VELOCITY_NORTH_NC");
            archive.Serialise(doubleBEST_VERTICAL_VELOCITY_NC, "BEST_VERTICAL_VELOCITY_NC");
            archive.Serialise(BEST_TRUE_ALTITUDE_NC, "BEST_TRUE_ALTITUDE_NC");
            archive.Serialise(BEST_ALTITUDE_ABOVE_ELLIPSOID, "BEST_ALTITUDE_ABOVE_ELLIPSOID");
            archive.Serialise(doubleBEST_POSITION_COVARIANCE_XX, "BEST_POSITION_COVARIANCE_XX");
            archive.Serialise(doubleBEST_POSITION_COVARIANCE_YY, "BEST_POSITION_COVARIANCE_YY");
            archive.Serialise(doubleBEST_POSITION_COVARIANCE_ZZ, "BEST_POSITION_COVARIANCE_ZZ");
            archive.Serialise(doubleBEST_POSITION_COVARIANCE_XY, "BEST_POSITION_COVARIANCE_XY");
            archive.Serialise(doubleBEST_POSITION_COVARIANCE_XZ, "BEST_POSITION_COVARIANCE_XZ");
            archive.Serialise(doubleBEST_POSITION_COVARIANCE_YZ, "BEST_POSITION_COVARIANCE_YZ");
            archive.Serialise(BEST_VELOCITY_COVARIANCE_XX, "BEST_VELOCITY_COVARIANCE_XX");
            archive.Serialise(BEST_VELOCITY_COVARIANCE_YY, "BEST_VELOCITY_COVARIANCE_YY");
            archive.Serialise(BEST_VELOCITY_COVARIANCE_ZZ, "BEST_VELOCITY_COVARIANCE_ZZ");
            archive.Serialise(BEST_VELOCITY_COVARIANCE_XY, "BEST_VELOCITY_COVARIANCE_XY");
            archive.Serialise(BEST_VELOCITY_COVARIANCE_XZ, "BEST_VELOCITY_COVARIANCE_XZ");
            archive.Serialise(BEST_VELOCITY_COVARIANCE_YZ, "BEST_VELOCITY_COVARIANCE_YZ");
            archive.Serialise(POS_FLAG, "POS_FLAG");
            archive.Serialise(ALTITUDE_FLAG, "ALTITUDE_FLAG");
            archive.Serialise(HORIZ_VEL_FLAG, "HORIZ_VEL_FLAG");
            archive.Serialise(VERT_VEL_FLAG, "VERT_VEL_FLAG");
            archive.Serialise(COST_VEL_FLAG, "COST_VEL_FLAG");
            archive.Serialise(COST_HDG_ATT_FLAG, "COST_HDG_ATT_FLAG");
            archive.Serialise(LIN_ACC_FLAG, "LIN_ACC_FLAG");
            archive.Serialise(MACH_N_FLAG, "MACH_N_FLAG");
            archive.Serialise(INS_AIDED_FLAG, "INS_AIDED_FLAG");
            archive.Serialise(CONT_LIN_ACC_FLAG, "CONT_LIN_ACC_FLAG");
            archive.Serialise(ANGULAR_RATES_FLAG, "ANGULAR_RATES_FLAG");
            archive.Serialise(CONT_MACH_N_FLAG, "CONT_MACH_N_FLAG");
            archive.Serialise(INS_AIDED_10MIN_FLAG, "INS_AIDED_10MIN_FLAG");
            archive.Serialise(FOM1_FLAG, "FOM1_FLAG");
            archive.Serialise(MASTER_NAV_FLAG_1, "MASTER_NAV_FLAG_1");
            archive.Serialise(MASTER_NAV_FLAG_2, "MASTER_NAV_FLAG_2");
            archive.Serialise(MASTER_NAV_FLAG_3, "MASTER_NAV_FLAG_3");
            archive.Serialise(MASTER_NAV_FLAG_4, "MASTER_NAV_FLAG_4");
            archive.Serialise(MASTER_NAV_FLAG_5, "MASTER_NAV_FLAG_5");
            archive.Serialise(MN_FLAGS_TIME_TAG, "MN_FLAGS_TIME_TAG");
            archive.Serialise(GPS_FLAGS_TIME_TAG, "GPS_FLAGS_TIME_TAG");
            archive.Serialise(FCS_FLAGS_TIME_TAG, "FCS_FLAGS_TIME_TAG");
            archive.Serialise(SAR_NAV_SOURCE, "SAR_NAV_SOURCE");
            archive.Serialise(BEST_PRESENT_POSITION_COV_DVAL, "BEST_PRESENT_POSITION_COV_DVAL");
            archive.Serialise(BEST_VELOCITY_COV_DVAL, "BEST_VELOCITY_COV_DVAL");
            archive.Serialise(BEST_NC_TIME_TAG_ANGLES, "BEST_NC_TIME_TAG_ANGLES");
            archive.Serialise(BEST_NC_TIME_TAG_VEL_GEOD, "BEST_NC_TIME_TAG_VEL_GEOD");
            archive.Serialise(BEST_NC_TIME_TAG_VEL_LINEAR, "BEST_NC_TIME_TAG_VEL_LINEAR");
            archive.Serialise(BEST_NC_TIME_TAG_PP, "BEST_NC_TIME_TAG_PP");

            BEST_BANK = doubleBEST_BANK;
            BEST_BODY_LINEAR_ACCEL_X = doubleBEST_BODY_LINEAR_ACCEL_X;
            BEST_BODY_LINEAR_ACCEL_Y = doubleBEST_BODY_LINEAR_ACCEL_Y;
            BEST_BODY_LINEAR_ACCEL_Z = doubleBEST_BODY_LINEAR_ACCEL_Z;
            BEST_INCLINATION = doubleBEST_INCLINATION;
            BEST_TRUE_HEADING = doubleBEST_TRUE_HEADING;
            BEST_LATITUDE_NC = doubleBEST_LATITUDE_NC;
            BEST_LONGITUDE_NC = doubleBEST_LONGITUDE_NC;
            BEST_GROUNDSPEED = doubleBEST_GROUNDSPEED;
            BEST_WIND_DIRECTION = doubleBEST_WIND_DIRECTION;
            ESTIMATED_ALT_ERROR = doubleESTIMATED_ALT_ERROR;
            BEST_LINEAR_X_VELOCITY_NC = doubleBEST_LINEAR_X_VELOCITY_NC;
            BEST_LINEAR_Y_VELOCITY_NC = doubleBEST_LINEAR_Y_VELOCITY_NC;
            BEST_LINEAR_Z_VELOCITY_NC = doubleBEST_LINEAR_Z_VELOCITY_NC;
            BEST_VELOCITY_EAST_NC = doubleBEST_VELOCITY_EAST_NC;
            BEST_VELOCITY_NORTH_NC = doubleBEST_VELOCITY_NORTH_NC;
            BEST_VERTICAL_VELOCITY_NC = doubleBEST_VERTICAL_VELOCITY_NC;
            BEST_POSITION_COVARIANCE_XX = doubleBEST_POSITION_COVARIANCE_XX;
            BEST_POSITION_COVARIANCE_YY = doubleBEST_POSITION_COVARIANCE_YY;
            BEST_POSITION_COVARIANCE_ZZ = doubleBEST_POSITION_COVARIANCE_ZZ;
            BEST_POSITION_COVARIANCE_XY = doubleBEST_POSITION_COVARIANCE_XY;
            BEST_POSITION_COVARIANCE_XZ = doubleBEST_POSITION_COVARIANCE_XZ;
            BEST_POSITION_COVARIANCE_YZ = doubleBEST_POSITION_COVARIANCE_YZ;
        }

        LCA_TOPIC("NAVComputerNavigationDataMessage", 2, 0)


    };

}  // namespace Topics

#endif