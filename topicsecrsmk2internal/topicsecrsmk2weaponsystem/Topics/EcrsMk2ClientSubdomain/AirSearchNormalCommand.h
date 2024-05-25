#ifndef AIR_SEARCH_NORMAL_COMMAND_TYPES_H
#define AIR_SEARCH_NORMAL_COMMAND_TYPES_H

#include <memory>
#include <string>

#include "Command.h"
#include "CommonAirSearchValues.h"
#include "CommonWeaponSystemValues.h"
#include "NSIKnot.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "SIMeterSquared.h"

namespace Topics
{
  namespace EcrsMK2
  {

    namespace WeaponSystem
    {

      namespace AirSearch
      {

        class AirSearchNormalCommand : public Common::Command
        {
        protected:
          AirSearchNormalCommand() : Common::Command{}
          {
          }

        public:
          uint8_t RDRC_ASN_X_TV_MIN_PCT{IcdDefaultsAs::TV_MIN_PCT_DEFAULT};

          uint8_t RDRC_ASN_X_TV_DES_PCT{IcdDefaultsAs::TV_DES_PCT_DEFAULT};

          Search::PAT_T_ENUM RDRC_ASN_X_PAT_T{IcdDefaultsAs::PAT_T_DEFAULT};

          AirSearch::PAT_FS_ENUM RDRC_ASN_X_PAT_FS{IcdDefaultsAs::PAT_FS_DEFAULT};

          Search::PAT_D_ENUM RDRC_ASN_X_PAT_D{IcdDefaultsAs::PAT_D_DEFAULT};

          Search::PAT_I_ENUM RDRC_ASN_X_PAT_I{IcdDefaultsAs::PAT_I_DEFAULT};

          Common::TXDISC_ENUM RDRC_ASN_X_TXDISC{IcdDefaults::TXDISC_DEFAULT};

          AirSearch::ASN_X_VOL_SCAN_TYPE_ENUM RDRC_ASN_X_SCAN_TYPE{IcdDefaultsAs::ASN_X_VOL_SCAN_TYPE_DEFAULT};

          AirSearch::ASN_X_START_POINT_ENUM RDRC_ASN_X_START_POINT{IcdDefaultsAs::ASN_X_START_POINT_DEFAULT};

          SPATIAL_ENUM RDRC_ASN_X_SPATIAL{IcdDefaultsAs::SPATIAL_DEFAULT};

          uint16_t RDRC_ASN_X_IKTV_PRIORITY{IcdDefaults::IKTV_PRIORITY_DEFAULT};

          SI::SIMeter RDRC_ASN_X_IKTV_MIN_POS_X{IcdDefaults::IKTV_MIN_POS_X_DEFAULT};

          SI::SIMeter RDRC_ASN_X_IKTV_MIN_POS_Z{IcdDefaults::IKTV_MIN_POS_Z_DEFAULT};

          Common::IKTV_RAP_ATT_ENUM RDRC_ASN_X_IKTV_MIN_RAP_ATT{IcdDefaults::IKTV_MIN_RAP_ATT_DEFAULT};

          SI::SIMeterPerSecond RDRC_ASN_X_IKTV_MIN_VEL_X{IcdDefaults::IKTV_MIN_VEL_X_DEFAULT};

          SI::SIMeterPerSecond RDRC_ASN_X_IKTV_MIN_VEL_Z{IcdDefaults::IKTV_MIN_VEL_Z_DEFAULT};

          SI::SIMeter RDRC_ASN_X_IKTV_DES_POS_X{IcdDefaults::IKTV_DES_POS_X_DEFAULT};

          SI::SIMeter RDRC_ASN_X_IKTV_DES_POS_Z{IcdDefaults::IKTV_DES_POS_Z_DEFAULT};

          Common::IKTV_RAP_ATT_ENUM RDRC_ASN_X_IKTV_DES_RAP_ATT{IcdDefaults::IKTV_DES_RAP_ATT_DEFAULT};

          SI::SIMeterPerSecond RDRC_ASN_X_IKTV_DES_VEL_X{IcdDefaults::IKTV_DES_VEL_X_DEFAULT};

          SI::SIMeterPerSecond RDRC_ASN_X_IKTV_DES_VEL_Z{IcdDefaults::IKTV_DES_VEL_Z_DEFAULT};

          bool RDRC_ASN_X_IKTV_PROACT{IcdDefaults::IKTV_PROACT_DEFAULT};

          SI::SIMeterSquared RDRC_ASN_X_ASS_RCS{ASS_RCS_DEFAULT};

          ASS_TYPE_ENUM RDRC_ASN_X_ASS_TYPE{ASS_TYPE_DEFAULT};

          NSI::NSIKnot RDRC_ASN_X_ASS_VEL{ASS_VEL_DEFAULT};

          ASS_HEMIS_ENUM RDRC_ASN_X_ASS_HEMIS{ASS_HEMIS_DEFAULT};

          ENHD_CTRL_ENUM RDRC_ASN_X_ENHD_CTRL{IcdDefaultsAs::RDRC_ASC_ENHD_CTRL_DEFAULT};

          float RDRC_ASN_X_REQD_RES1{IcdDefaultsAs::REQD_RES1_DEFAULT};

          float RDRC_ASN_X_REQD_RES2{IcdDefaultsAs::REQD_RES2_DEFAULT};

          Common::WeaponSystemTaskType getTaskType() const noexcept override
          {
            return Common::WeaponSystemTaskType::AIR_SEARCH_NORMAL;
          }

          void setToIcdDefault() noexcept override
          {
            Command::setToIcdDefault();
            RDRC_ASN_X_TV_MIN_PCT = IcdDefaultsAs::TV_MIN_PCT_DEFAULT;
            RDRC_ASN_X_TV_DES_PCT = IcdDefaultsAs::TV_DES_PCT_DEFAULT;
            RDRC_ASN_X_PAT_T = IcdDefaultsAs::PAT_T_DEFAULT;
            RDRC_ASN_X_PAT_FS = IcdDefaultsAs::PAT_FS_DEFAULT;
            RDRC_ASN_X_PAT_D = IcdDefaultsAs::PAT_D_DEFAULT;
            RDRC_ASN_X_PAT_I = IcdDefaultsAs::PAT_I_DEFAULT;
            RDRC_ASN_X_TXDISC = IcdDefaults::TXDISC_DEFAULT;
            RDRC_ASN_X_SCAN_TYPE = IcdDefaultsAs::ASN_X_VOL_SCAN_TYPE_DEFAULT;
            RDRC_ASN_X_START_POINT = IcdDefaultsAs::ASN_X_START_POINT_DEFAULT;
            RDRC_ASN_X_SPATIAL = IcdDefaultsAs::SPATIAL_DEFAULT;
            RDRC_ASN_X_IKTV_PRIORITY = IcdDefaults::IKTV_PRIORITY_DEFAULT;
            RDRC_ASN_X_IKTV_MIN_POS_X = IcdDefaults::IKTV_MIN_POS_X_DEFAULT;
            RDRC_ASN_X_IKTV_MIN_POS_Z = IcdDefaults::IKTV_MIN_POS_Z_DEFAULT;
            RDRC_ASN_X_IKTV_MIN_RAP_ATT = IcdDefaults::IKTV_MIN_RAP_ATT_DEFAULT;
            RDRC_ASN_X_IKTV_MIN_VEL_X = IcdDefaults::IKTV_MIN_VEL_X_DEFAULT;
            RDRC_ASN_X_IKTV_MIN_VEL_Z = IcdDefaults::IKTV_MIN_VEL_Z_DEFAULT;
            RDRC_ASN_X_IKTV_DES_POS_X = IcdDefaults::IKTV_DES_POS_X_DEFAULT;
            RDRC_ASN_X_IKTV_DES_POS_Z = IcdDefaults::IKTV_DES_POS_Z_DEFAULT;
            RDRC_ASN_X_IKTV_DES_RAP_ATT = IcdDefaults::IKTV_DES_RAP_ATT_DEFAULT;
            RDRC_ASN_X_IKTV_DES_VEL_X = IcdDefaults::IKTV_DES_VEL_X_DEFAULT;
            RDRC_ASN_X_IKTV_DES_VEL_Z = IcdDefaults::IKTV_DES_VEL_Z_DEFAULT;
            RDRC_ASN_X_IKTV_PROACT = IcdDefaults::IKTV_PROACT_DEFAULT;
            RDRC_ASN_X_ASS_RCS = IcdDefaultsAs::ASS_RCS_DEFAULT;
            RDRC_ASN_X_ASS_TYPE = IcdDefaultsAs::ASS_TYPE_DEFAULT;
            RDRC_ASN_X_ASS_VEL = IcdDefaultsAs::ASS_VEL_DEFAULT;
            RDRC_ASN_X_ASS_HEMIS = IcdDefaultsAs::ASS_HEMIS_DEFAULT;
            RDRC_ASN_X_ENHD_CTRL = IcdDefaultsAs::RDRC_ASC_ENHD_CTRL_DEFAULT;
            RDRC_ASN_X_REQD_RES1 = IcdDefaultsAs::REQD_RES1_DEFAULT;
            RDRC_ASN_X_REQD_RES2 = IcdDefaultsAs::REQD_RES2_DEFAULT;
          }

        protected:
          /**
           * @brief equality operator
           * @returns true if the field in other contain the same values, false otherwise
           */
          bool operator==(const AirSearchNormalCommand& other) const 
          {
            return Command::operator==(other) &&
                   RDRC_ASN_X_TV_MIN_PCT == other.RDRC_ASN_X_TV_MIN_PCT &&
                   RDRC_ASN_X_TV_DES_PCT == other.RDRC_ASN_X_TV_DES_PCT &&
                   RDRC_ASN_X_PAT_T == other.RDRC_ASN_X_PAT_T &&
                   RDRC_ASN_X_PAT_FS == other.RDRC_ASN_X_PAT_FS &&
                   RDRC_ASN_X_PAT_D == other.RDRC_ASN_X_PAT_D &&
                   RDRC_ASN_X_PAT_I == other.RDRC_ASN_X_PAT_I &&
                   RDRC_ASN_X_TXDISC == other.RDRC_ASN_X_TXDISC &&
                   RDRC_ASN_X_SCAN_TYPE == other.RDRC_ASN_X_SCAN_TYPE &&
                   RDRC_ASN_X_START_POINT == other.RDRC_ASN_X_START_POINT &&
                   RDRC_ASN_X_SPATIAL == other.RDRC_ASN_X_SPATIAL &&
                   RDRC_ASN_X_IKTV_PRIORITY == other.RDRC_ASN_X_IKTV_PRIORITY &&
                   RDRC_ASN_X_IKTV_MIN_POS_X == other.RDRC_ASN_X_IKTV_MIN_POS_X &&
                   RDRC_ASN_X_IKTV_MIN_POS_Z == other.RDRC_ASN_X_IKTV_MIN_POS_Z &&
                   RDRC_ASN_X_IKTV_MIN_RAP_ATT == other.RDRC_ASN_X_IKTV_MIN_RAP_ATT &&
                   RDRC_ASN_X_IKTV_MIN_VEL_X == other.RDRC_ASN_X_IKTV_MIN_VEL_X &&
                   RDRC_ASN_X_IKTV_MIN_VEL_Z == other.RDRC_ASN_X_IKTV_MIN_VEL_Z &&
                   RDRC_ASN_X_IKTV_DES_POS_X == other.RDRC_ASN_X_IKTV_DES_POS_X &&
                   RDRC_ASN_X_IKTV_DES_POS_Z == other.RDRC_ASN_X_IKTV_DES_POS_Z &&
                   RDRC_ASN_X_IKTV_DES_RAP_ATT == other.RDRC_ASN_X_IKTV_DES_RAP_ATT &&
                   RDRC_ASN_X_IKTV_DES_VEL_X == other.RDRC_ASN_X_IKTV_DES_VEL_X &&
                   RDRC_ASN_X_IKTV_DES_VEL_Z == other.RDRC_ASN_X_IKTV_DES_VEL_Z &&
                   RDRC_ASN_X_IKTV_PROACT == other.RDRC_ASN_X_IKTV_PROACT &&
                   RDRC_ASN_X_ASS_RCS == other.RDRC_ASN_X_ASS_RCS &&
                   RDRC_ASN_X_ASS_TYPE == other.RDRC_ASN_X_ASS_TYPE &&
                   RDRC_ASN_X_ASS_VEL == other.RDRC_ASN_X_ASS_VEL &&
                   RDRC_ASN_X_ASS_HEMIS == other.RDRC_ASN_X_ASS_HEMIS &&
                   RDRC_ASN_X_ENHD_CTRL == other.RDRC_ASN_X_ENHD_CTRL &&
                   RDRC_ASN_X_REQD_RES1 == other.RDRC_ASN_X_REQD_RES1 &&
                   RDRC_ASN_X_REQD_RES2 == other.RDRC_ASN_X_REQD_RES2;
          }
        };
      }
    }
  }
} // namespace Topics

#endif
