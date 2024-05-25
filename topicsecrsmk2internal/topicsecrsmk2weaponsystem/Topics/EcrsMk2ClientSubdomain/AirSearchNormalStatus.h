#ifndef AIR_SEARCH_NORMAL_STATUS_TYPES_H
#define AIR_SEARCH_NORMAL_STATUS_TYPES_H

#include <memory>
#include <string>

#include "CommonAirSearchValues.h"
#include "CommonWeaponSystemValues.h"
#include "FloatEqualityChecker.h"
#include "SISecond.h"
#include "Status.h"
#include "SIMeterSquared.h"
#include "NSIKnot.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {

      namespace AirSearch
      {

        class AirSearchNormalStatus : public Common::Status
        {
        protected:
          AirSearchNormalStatus() : Common::Status{}
          {
          }

        public:
          uint8_t RDRS_ASN_X_ACHIEVED_PCT{IcdDefaultsAs::ACHIEVED_PCT_DEFAULT}; // Percentage

          float RDRS_ASN_X_RES_REP_ACTUAL{IcdDefaultsAs::RES_REP_ACTUAL_DEFAULT}; // Percentage

          float RDRS_ASN_X_RES_REP_PRED_DES{IcdDefaultsAs::RES_REP_PRED_DES_DEFAULT}; // Percentage

          float RDRS_ASN_X_RES_REP_PRED_MIN{IcdDefaultsAs::RES_REP_PRED_MIN_DEFAULT}; // Percentage

          float RDRS_ASN_X_RES_ANT_ACTUAL{IcdDefaultsAs::RES_ANT_ACTUAL_DEFAULT}; // Percentage

          float RDRS_ASN_X_RES_ANT_PRED_DES{IcdDefaultsAs::RES_ANT_PRED_DES_DEFAULT}; // Percentage

          float RDRS_ASN_X_RES_ANT_PRED_MIN{IcdDefaultsAs::RES_ANT_PRED_MIN_DEFAULT}; // Percentage

          Common::TXDISC_ENUM RDRS_ASN_X_TXDISC{IcdDefaults::TXDISC_DEFAULT};

          ASN_X_VOL_SCAN_TYPE_ENUM RDRS_ASN_X_VOL_SCAN_TYPE{IcdDefaultsAs::ASN_X_VOL_SCAN_TYPE_DEFAULT};

          ASN_X_START_POINT_ENUM RDRS_ASN_X_START_POINT{IcdDefaultsAs::ASN_X_START_POINT_DEFAULT};

          SPATIAL_ENUM RDRS_ASN_X_SPATIAL{IcdDefaultsAs::SPATIAL_DEFAULT};

          uint8_t RDRS_ASN_X_RATIO_DMD_ACT{IcdDefaultsAs::RATIO_DMD_ACT_DEFAULT}; // Percentage

          uint8_t RDRS_ASN_X_PROG_ACT_VOL{IcdDefaultsAs::PROG_ACT_VOL_DEFAULT}; // Percentage

          SI::SISecond RDRS_ASN_X_TIME_TO_COMP_ITER{IcdDefaultsAs::TIME_TO_COMP_ITER_DEFAULT};

          uint8_t RDRS_ASN_X_FRAME_COUNT{IcdDefaults::FRAME_COUNT_DEFAULT};

          SI::SIMeterSquared RDRS_ASN_X_ASS_RCS{IcdDefaultsAs::ASS_RCS_DEFAULT};

          ASS_TYPE_ENUM RDRS_ASN_X_ASS_TYPE{IcdDefaultsAs::ASS_TYPE_DEFAULT};

          NSI::NSIKnot RDRS_ASN_X_ASS_VEL{IcdDefaultsAs::ASS_VEL_DEFAULT};

          ASS_HEMIS_ENUM RDRS_ASN_X_ASS_HEMIS{IcdDefaultsAs::ASS_HEMIS_DEFAULT};

          void setTaskType(const Common::CommandValidity &validity) noexcept override
          {
            TASK_TYPE = (validity == Common::CommandValidity::VALID) ? Common::WeaponSystemTaskType::AIR_SEARCH_NORMAL : Common::WeaponSystemTaskType::INVALID_TYPE;
          }

          virtual void setToIcdDefault() noexcept override
          {
            Status::setToIcdDefault();
            RDRS_ASN_X_ACHIEVED_PCT = IcdDefaultsAs::ACHIEVED_PCT_DEFAULT;
            RDRS_ASN_X_RES_REP_ACTUAL = IcdDefaultsAs::RES_REP_ACTUAL_DEFAULT;
            RDRS_ASN_X_RES_REP_PRED_DES = IcdDefaultsAs::RES_REP_PRED_DES_DEFAULT;
            RDRS_ASN_X_RES_REP_PRED_MIN = IcdDefaultsAs::RES_REP_PRED_MIN_DEFAULT;
            RDRS_ASN_X_RES_ANT_ACTUAL = IcdDefaultsAs::RES_ANT_ACTUAL_DEFAULT;
            RDRS_ASN_X_RES_ANT_PRED_DES = IcdDefaultsAs::RES_ANT_PRED_DES_DEFAULT;
            RDRS_ASN_X_RES_ANT_PRED_MIN = IcdDefaultsAs::RES_ANT_PRED_MIN_DEFAULT;
            RDRS_ASN_X_TXDISC = IcdDefaults::TXDISC_DEFAULT;
            RDRS_ASN_X_VOL_SCAN_TYPE = IcdDefaultsAs::ASN_X_VOL_SCAN_TYPE_DEFAULT;
            RDRS_ASN_X_START_POINT = IcdDefaultsAs::ASN_X_START_POINT_DEFAULT;
            RDRS_ASN_X_SPATIAL = IcdDefaultsAs::SPATIAL_DEFAULT;
            RDRS_ASN_X_RATIO_DMD_ACT = IcdDefaultsAs::RATIO_DMD_ACT_DEFAULT;
            RDRS_ASN_X_PROG_ACT_VOL = IcdDefaultsAs::PROG_ACT_VOL_DEFAULT;
            RDRS_ASN_X_TIME_TO_COMP_ITER = IcdDefaultsAs::TIME_TO_COMP_ITER_DEFAULT;
            RDRS_ASN_X_FRAME_COUNT = IcdDefaults::FRAME_COUNT_DEFAULT;
            RDRS_ASN_X_ASS_RCS = IcdDefaultsAs::ASS_RCS_DEFAULT;
            RDRS_ASN_X_ASS_TYPE = IcdDefaultsAs::ASS_TYPE_DEFAULT;
            RDRS_ASN_X_ASS_VEL = IcdDefaultsAs::ASS_VEL_DEFAULT;
            RDRS_ASN_X_ASS_HEMIS = IcdDefaultsAs::ASS_HEMIS_DEFAULT;
          }

        protected:
          /**
           * @brief equality operator
           * @returns true if other contains the same values, false otherwise
           */
          bool operator==(const AirSearchNormalStatus& other) const
          {
            return Status::operator==(other) &&
                   RDRS_ASN_X_ACHIEVED_PCT == other.RDRS_ASN_X_ACHIEVED_PCT &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASN_X_RES_REP_ACTUAL, other.RDRS_ASN_X_RES_REP_ACTUAL) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASN_X_RES_REP_PRED_DES, other.RDRS_ASN_X_RES_REP_PRED_DES) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASN_X_RES_REP_PRED_MIN, other.RDRS_ASN_X_RES_REP_PRED_MIN) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASN_X_RES_ANT_ACTUAL, other.RDRS_ASN_X_RES_ANT_ACTUAL) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASN_X_RES_ANT_PRED_DES, other.RDRS_ASN_X_RES_ANT_PRED_DES) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASN_X_RES_ANT_PRED_MIN, other.RDRS_ASN_X_RES_ANT_PRED_MIN) &&
                   RDRS_ASN_X_TXDISC == other.RDRS_ASN_X_TXDISC &&
                   RDRS_ASN_X_VOL_SCAN_TYPE == other.RDRS_ASN_X_VOL_SCAN_TYPE &&
                   RDRS_ASN_X_START_POINT == other.RDRS_ASN_X_START_POINT &&
                   RDRS_ASN_X_SPATIAL == other.RDRS_ASN_X_SPATIAL &&
                   RDRS_ASN_X_RATIO_DMD_ACT == other.RDRS_ASN_X_RATIO_DMD_ACT &&
                   RDRS_ASN_X_PROG_ACT_VOL == other.RDRS_ASN_X_PROG_ACT_VOL &&
                   RDRS_ASN_X_TIME_TO_COMP_ITER == other.RDRS_ASN_X_TIME_TO_COMP_ITER &&
                   RDRS_ASN_X_FRAME_COUNT == other.RDRS_ASN_X_FRAME_COUNT &&
                   RDRS_ASN_X_ASS_RCS == other.RDRS_ASN_X_ASS_RCS &&
                   RDRS_ASN_X_ASS_TYPE == other.RDRS_ASN_X_ASS_TYPE &&
                   RDRS_ASN_X_ASS_VEL == other.RDRS_ASN_X_ASS_VEL &&
                   RDRS_ASN_X_ASS_HEMIS == other.RDRS_ASN_X_ASS_HEMIS;
          }
        };
      }
    }
  }
} // namespace topics

#endif