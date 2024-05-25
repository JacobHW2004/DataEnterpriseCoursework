#ifndef AIR_SEARCH_NORMAL_GEO_REFERENCED_COMMAND_TOPIC_H
#define AIR_SEARCH_NORMAL_GEO_REFERENCED_COMMAND_TOPIC_H

#include "AirSearchNormalCommand.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "VolumeGeoReferenced.h"

namespace Topics
{

  namespace EcrsMK2
  {

    namespace WeaponSystem
    {
      namespace AirSearch
      {
        /**
         * @brief this topic is a strongly typed one to one mapping of Radar Command 2 - message AC36-RADAR-HAT-MESS-1 (ASN - Geographical Referenced variant only) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         * @todo add doxygen to each attribute describing its units.
         * @todo add doxygen to each attribute describing its ICD message counter part
         */
        class AirSearchNormalGeoReferencedCommandTopic : public AirSearchNormalCommand,
                                                         public Common::VolumeGeoReferenced
        {

        public:

          AirSearchNormalGeoReferencedCommandTopic() : AirSearchNormalCommand{},
                                                       Common::VolumeGeoReferenced{}
          {
          }

          void setToIcdDefault() noexcept override
          {
            AirSearchNormalCommand::setToIcdDefault();
            Common::VolumeGeoReferenced::setToIcdDefault();
          }

          bool operator==(const AirSearchNormalGeoReferencedCommandTopic& other) const
          {
            return
              AirSearchNormalCommand::operator==(other) &&
              Common::VolumeGeoReferenced::operator==(other);
          }

          bool operator!=(const AirSearchNormalGeoReferencedCommandTopic &other) const
          {
            return !(*this == other);
          }

          /**
           * @brief Serialise function required for communications
           * @todo serialise the fields in this topic.
           */
          template <class T>
          void Serialise(T &archive)
          {
            Common::WeaponSystemTaskType RDRC_SN_X_TASK_TYPE = getTaskType();
            
            // Volume params
            double doubleRDRC_ASN_X_GEO_LAT{RDRX_ASX_GEO_LAT()};
            double doubleRDRC_ASN_X_GEO_LON{RDRX_ASX_GEO_LON()};
            double doubleRDRC_ASN_X_GEO_ALT{RDRX_ASX_GEO_ALT()};
            double doubleRDRC_ASN_X_GEO_AZ_LEFT{RDRX_ASX_GEO_AZ_LEFT()};
            double doubleRDRC_ASN_X_GEO_AZ_RIGHT{RDRX_ASX_GEO_AZ_RIGHT()};
            double doubleRDRC_ASN_X_GEO_EL_UPPER{RDRX_ASX_GEO_EL_UPPER()};
            double doubleRDRC_ASN_X_GEO_EL_LOWER{RDRX_ASX_GEO_EL_LOWER()};
            double doubleRDRC_ASN_X_GEO_RNG_EXT_HALF{RDRX_ASX_GEO_RNG_EXT_HALF()};

            // Generic AirSearch params
            double doubleRDRC_ASN_X_IKTV_MIN_POS_X{RDRC_ASN_X_IKTV_MIN_POS_X()};
            double doubleRDRC_ASN_X_IKTV_MIN_POS_Z{RDRC_ASN_X_IKTV_MIN_POS_Z()};
            double doubleRDRC_ASN_X_IKTV_DES_POS_X{RDRC_ASN_X_IKTV_DES_POS_X()};
            double doubleRDRC_ASN_X_IKTV_DES_POS_Z{RDRC_ASN_X_IKTV_DES_POS_Z()};
            double doubleRDRC_ASN_X_IKTV_MIN_VEL_X{RDRC_ASN_X_IKTV_MIN_VEL_X()};
            double doubleRDRC_ASN_X_IKTV_MIN_VEL_Z{RDRC_ASN_X_IKTV_MIN_VEL_Z()};
            double doubleRDRC_ASN_X_IKTV_DES_VEL_X{RDRC_ASN_X_IKTV_DES_VEL_X()};
            double doubleRDRC_ASN_X_IKTV_DES_VEL_Z{RDRC_ASN_X_IKTV_DES_VEL_Z()};
            double doubleRDRC_ASN_X_ASS_RCS{RDRC_ASN_X_ASS_RCS()};
            double doubleRDRC_ASN_X_ASS_VEL{RDRC_ASN_X_ASS_VEL()};

            archive.Serialise(TASK_IDENT, "RDRC_SN_X_TASK_IDENT");
            archive.Serialise(CMD, "RDRC_SN_X_CMD");
            archive.Serialise(RDRC_SN_X_TASK_TYPE, "RDRC_SN_X_TASK_TYPE");
            archive.Serialise(TV_PRIORITY, "RDRC_ASN_X_TV_PRIORITY");
            archive.Serialise(RDRC_ASN_X_TV_MIN_PCT, "RDRC_ASN_X_TV_MIN_PCT");
            archive.Serialise(RDRC_ASN_X_TV_DES_PCT, "RDRC_ASN_X_TV_DES_PCT");
            archive.Serialise(RDRC_ASN_X_PAT_T, "RDRC_ASN_X_PAT_T");
            archive.Serialise(RDRC_ASN_X_PAT_FS, "RDRC_ASN_X_PAT_FS");
            archive.Serialise(RDRC_ASN_X_PAT_D, "RDRC_ASN_X_PAT_D");
            archive.Serialise(RDRC_ASN_X_PAT_I, "RDRC_ASN_X_PAT_I");
            archive.Serialise(RDRC_ASN_X_TXDISC, "RDRC_ASN_X_TXDISC");
            archive.Serialise(RDRC_ASN_X_SCAN_TYPE, "RDRC_ASN_X_SCAN_TYPE");
            archive.Serialise(RDRC_ASN_X_START_POINT, "RDRC_ASN_X_START_POINT");
            archive.Serialise(RDRC_ASN_X_SPATIAL, "RDRC_ASN_X_SPATIAL");

            // Volume params
            archive.Serialise(doubleRDRC_ASN_X_GEO_LAT, "RDRC_ASN_X_GEO_LAT");
            archive.Serialise(doubleRDRC_ASN_X_GEO_LON, "RDRC_ASN_X_GEO_LON");
            archive.Serialise(doubleRDRC_ASN_X_GEO_ALT, "RDRC_ASN_X_GEO_ALT");
            archive.Serialise(doubleRDRC_ASN_X_GEO_AZ_LEFT, "RDRC_ASN_X_GEO_AZ_LEFT");
            archive.Serialise(doubleRDRC_ASN_X_GEO_AZ_RIGHT, "RDRC_ASN_X_GEO_AZ_RIGHT");
            archive.Serialise(doubleRDRC_ASN_X_GEO_EL_UPPER, "RDRC_ASN_X_GEO_EL_UPPER");
            archive.Serialise(doubleRDRC_ASN_X_GEO_EL_LOWER, "RDRC_ASN_X_GEO_EL_LOWER");
            archive.Serialise(doubleRDRC_ASN_X_GEO_RNG_EXT_HALF, "RDRC_ASN_X_GEO_RNG_EXT_HALF");
            
            archive.Serialise(RDRC_ASN_X_IKTV_PRIORITY, "RDRC_ASN_X_IKTV_PRIORITY");
            archive.Serialise(doubleRDRC_ASN_X_IKTV_MIN_POS_X, "RDRC_ASN_X_IKTV_MIN_POS_X");
            archive.Serialise(doubleRDRC_ASN_X_IKTV_MIN_POS_Z, "RDRC_ASN_X_IKTV_MIN_POS_Z");
            archive.Serialise(RDRC_ASN_X_IKTV_MIN_RAP_ATT, "RDRC_ASN_X_IKTV_MIN_RAP_ATT");
            archive.Serialise(doubleRDRC_ASN_X_IKTV_MIN_VEL_X, "doubleRDRC_ASN_X_IKTV_MIN_VEL_X");
            archive.Serialise(doubleRDRC_ASN_X_IKTV_MIN_VEL_Z, "doubleRDRC_ASN_X_IKTV_MIN_VEL_Z");
            archive.Serialise(doubleRDRC_ASN_X_IKTV_DES_POS_X, "doubleRDRC_ASN_X_IKTV_DES_POS_X");
            archive.Serialise(doubleRDRC_ASN_X_IKTV_DES_POS_Z, "doubleRDRC_ASN_X_IKTV_DES_POS_Z");
            archive.Serialise(RDRC_ASN_X_IKTV_DES_RAP_ATT, "RDRC_ASN_X_IKTV_DES_RAP_ATT");
            archive.Serialise(doubleRDRC_ASN_X_IKTV_DES_VEL_X, "doubleRDRC_ASN_X_IKTV_DES_VEL_X");
            archive.Serialise(doubleRDRC_ASN_X_IKTV_DES_VEL_Z, "doubleRDRC_ASN_X_IKTV_DES_VEL_Z");
            archive.Serialise(RDRC_ASN_X_IKTV_PROACT, "RDRC_ASN_X_IKTV_PROACT");
            archive.Serialise(doubleRDRC_ASN_X_ASS_RCS, "doubleRDRC_ASN_X_ASS_RCS");
            archive.Serialise(RDRC_ASN_X_ASS_TYPE, "RDRC_ASN_X_ASS_TYPE");
            archive.Serialise(doubleRDRC_ASN_X_ASS_VEL, "doubleRDRC_ASN_X_ASS_VEL");
            archive.Serialise(RDRC_ASN_X_ASS_HEMIS, "RDRC_ASN_X_ASS_HEMIS");
            archive.Serialise(RDRC_ASN_X_ENHD_CTRL, "RDRC_ASN_X_ENHD_CTRL");
            archive.Serialise(RDRC_ASN_X_REQD_RES1, "RDRC_ASN_X_REQD_RES1");
            archive.Serialise(RDRC_ASN_X_REQD_RES2, "RDRC_ASN_X_REQD_RES2");
            archive.Serialise(TDI, "RDRC_SN_X_TDI");

            // Volume params
            RDRX_ASX_GEO_LAT = doubleRDRC_ASN_X_GEO_LAT;
            RDRX_ASX_GEO_LON = doubleRDRC_ASN_X_GEO_LON;
            RDRX_ASX_GEO_ALT = doubleRDRC_ASN_X_GEO_ALT;
            RDRX_ASX_GEO_AZ_LEFT = doubleRDRC_ASN_X_GEO_AZ_LEFT;
            RDRX_ASX_GEO_AZ_RIGHT = doubleRDRC_ASN_X_GEO_AZ_RIGHT;
            RDRX_ASX_GEO_EL_UPPER = doubleRDRC_ASN_X_GEO_EL_UPPER;
            RDRX_ASX_GEO_EL_LOWER = doubleRDRC_ASN_X_GEO_EL_LOWER;
            RDRX_ASX_GEO_RNG_EXT_HALF = doubleRDRC_ASN_X_GEO_RNG_EXT_HALF;

            RDRC_ASN_X_IKTV_MIN_POS_X = doubleRDRC_ASN_X_IKTV_MIN_POS_X;
            RDRC_ASN_X_IKTV_MIN_POS_Z = doubleRDRC_ASN_X_IKTV_MIN_POS_Z;
            RDRC_ASN_X_IKTV_DES_POS_X = doubleRDRC_ASN_X_IKTV_DES_POS_X;
            RDRC_ASN_X_IKTV_DES_POS_Z = doubleRDRC_ASN_X_IKTV_DES_POS_Z;
            RDRC_ASN_X_IKTV_MIN_VEL_X = doubleRDRC_ASN_X_IKTV_MIN_VEL_X;
            RDRC_ASN_X_IKTV_MIN_VEL_Z = doubleRDRC_ASN_X_IKTV_MIN_VEL_Z;
            RDRC_ASN_X_IKTV_DES_VEL_X = doubleRDRC_ASN_X_IKTV_DES_VEL_X;
            RDRC_ASN_X_IKTV_DES_VEL_Z = doubleRDRC_ASN_X_IKTV_DES_VEL_Z;
            RDRC_ASN_X_ASS_RCS = doubleRDRC_ASN_X_ASS_RCS;
            RDRC_ASN_X_ASS_VEL = doubleRDRC_ASN_X_ASS_VEL;
          }

          LCA_TOPIC("AirSearchNormalGeoReferencedCommandTopic", 1, 0)
        };
      }
    }
  }
} // namespace Topics

#endif