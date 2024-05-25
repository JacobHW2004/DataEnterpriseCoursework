#ifndef AIR_SEARCH_NORMAL_GEO_REFERENCED_STATUS_TOPIC_H
#define AIR_SEARCH_NORMAL_GEO_REFERENCED_STATUS_TOPIC_H

#include <string>

#include "AirSearchNormalStatus.h"
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
         * @brief this topic is a strongly typed one to one mapping of Radar Status 2 - RADAR21-BRD-HAT-MESS-1 (ASN - status Geographically Referenced variant only) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         * @todo add doxygen to each attribute describing its units.
         * @todo add doxygen to each attribute describing its ICD message counter part
         */
        class AirSearchNormalGeoReferencedStatusTopic : public AirSearchNormalStatus,
                                                        public Common::VolumeGeoReferenced
        {

        public:

          AirSearchNormalGeoReferencedStatusTopic() : AirSearchNormalStatus{},
                                                      Common::VolumeGeoReferenced{}
          {
          }

          void setToIcdDefault() noexcept override
          {
            AirSearchNormalStatus::setToIcdDefault();
            Common::VolumeGeoReferenced::setToIcdDefault();
          }

          bool operator==(const AirSearchNormalGeoReferencedStatusTopic& other) const
          {
            return
              AirSearchNormalStatus::operator==(other) &&
              Common::VolumeGeoReferenced::operator==(other);
          }

          bool operator!=(const AirSearchNormalGeoReferencedStatusTopic &other) const
          {
            return !(*this == other);
          }

          /**
           * @brief Serialise function required for communications
           * @todo Bools don't serialise
           */
          template <class T>
          void Serialise(T &archive)
          {
            double doubleRDRS_ASN_X_GEO_LAT{RDRX_ASX_GEO_LAT()};
            double doubleRDRS_ASN_X_GEO_LON{RDRX_ASX_GEO_LON()};
            double doubleRDRS_ASN_X_GEO_ALT{RDRX_ASX_GEO_ALT()};
            double doubleRDRS_ASN_X_GEO_AZ_LEFT{RDRX_ASX_GEO_AZ_LEFT()};
            double doubleRDRS_ASN_X_GEO_AZ_RIGHT{RDRX_ASX_GEO_AZ_RIGHT()};
            double doubleRDRS_ASN_X_GEO_EL_UPPER{RDRX_ASX_GEO_EL_UPPER()};
            double doubleRDRS_ASN_X_GEO_EL_LOWER{RDRX_ASX_GEO_EL_LOWER()};
            double doubleRDRS_ASN_X_GEO_RNG_EXT_HALF{RDRX_ASX_GEO_RNG_EXT_HALF()};
            
            double doubleRDRS_ASN_X_TIME_TO_COMP_ITER{RDRS_ASN_X_TIME_TO_COMP_ITER()};
            double doubleRDRS_ASN_X_ASS_RCS{RDRS_ASN_X_ASS_RCS()};
            double doubleRDRS_ASN_ASS_VEL{RDRS_ASN_X_ASS_VEL()};

            archive.Serialise(TASK_IDENT, "RDRS_SN_X_TASK_IDENT");
            archive.Serialise(TASK_TYPE, "RDRS_SN_X_TASK_TYPE");
            archive.Serialise(COND_MOD_STATUS, "RDRS_SN_X_COND_MOD_STATUS");
            archive.Serialise(COND_STATE, "RDRS_SN_X_COND_STATE");
            archive.Serialise(COND_SUSP_DETAIL, "RDRS_SN_X_COND_SUSP_DETAIL");
            archive.Serialise(COND_MOD_TDI, "RDRS_SN_X_COND_MOD_TDI");
            archive.Serialise(COND_REJECT_DETAIL, "RDRS_SN_X_COND_REJECT_DETAIL");
            archive.Serialise(RDRS_ASN_X_ACHIEVED_PCT, "RDRS_ASN_X_ACHIEVED_PCT");
            archive.Serialise(RDRS_ASN_X_RES_REP_ACTUAL, "RDRS_ASN_X_RES_REP_ACTUAL");
            archive.Serialise(RDRS_ASN_X_RES_REP_PRED_DES, "RDRS_ASN_X_RES_REP_PRED_DES");
            archive.Serialise(RDRS_ASN_X_RES_REP_PRED_MIN, "RDRS_ASN_X_RES_REP_PRED_MIN");
            archive.Serialise(RDRS_ASN_X_RES_ANT_ACTUAL, "RDRS_ASN_X_RES_ANT_ACTUAL");
            archive.Serialise(RDRS_ASN_X_RES_ANT_PRED_DES, "RDRS_ASN_X_RES_ANT_PRED_DES");
            archive.Serialise(RDRS_ASN_X_RES_ANT_PRED_MIN, "RDRS_ASN_X_RES_ANT_PRED_MIN");
            archive.Serialise(RDRS_ASN_X_TXDISC, "RDRS_ASN_X_TXDISC");
            archive.Serialise(RDRS_ASN_X_VOL_SCAN_TYPE, "RDRS_ASN_X_VOL_SCAN_TYPE");
            archive.Serialise(RDRS_ASN_X_START_POINT, "RDRS_ASN_X_START_POINT");
            archive.Serialise(RDRS_ASN_X_SPATIAL, "RDRS_ASN_X_SPATIAL");

            // Volume params            
            archive.Serialise(doubleRDRS_ASN_X_GEO_LAT, "RDRS_ASN_X_GEO_LAT");
            archive.Serialise(doubleRDRS_ASN_X_GEO_LON, "RDRS_ASN_X_GEO_LON");
            archive.Serialise(doubleRDRS_ASN_X_GEO_ALT, "RDRS_ASN_X_GEO_ALT");
            archive.Serialise(doubleRDRS_ASN_X_GEO_AZ_LEFT, "RDRS_ASN_X_GEO_AZ_LEFT");
            archive.Serialise(doubleRDRS_ASN_X_GEO_AZ_RIGHT, "RDRS_ASN_X_GEO_AZ_RIGHT");
            archive.Serialise(doubleRDRS_ASN_X_GEO_EL_UPPER, "RDRS_ASN_X_GEO_EL_UPPER");
            archive.Serialise(doubleRDRS_ASN_X_GEO_EL_LOWER, "RDRS_ASN_X_GEO_EL_LOWER");
            archive.Serialise(doubleRDRS_ASN_X_GEO_RNG_EXT_HALF, "RDRS_ASN_X_GEO_RNG_EXT_HALF");

            archive.Serialise(RDRS_ASN_X_RATIO_DMD_ACT, "RDRS_ASN_X_RATIO_DMD_ACT");
            archive.Serialise(RDRS_ASN_X_PROG_ACT_VOL, "RDRS_ASN_X_PROG_ACT_VOL");
            archive.Serialise(doubleRDRS_ASN_X_TIME_TO_COMP_ITER, "RDRS_ASN_X_TIME_TO_COMP_ITER");
            archive.Serialise(RDRS_ASN_X_FRAME_COUNT, "RDRS_ASN_X_FRAME_COUNT");
            archive.Serialise(doubleRDRS_ASN_X_ASS_RCS, "RDRS_ASN_X_ASS_RCS");
            archive.Serialise(RDRS_ASN_X_ASS_TYPE, "RDRS_ASN_X_ASS_TYPE");
            archive.Serialise(doubleRDRS_ASN_ASS_VEL, "RDRS_ASN_X_ASS_VEL");
            archive.Serialise(RDRS_ASN_X_ASS_HEMIS, "RDRS_ASN_X_ASS_HEMIS");
            archive.Serialise(ACTUAL_TDI, "RDRS_SN_X_TDI");

            RDRX_ASX_GEO_LAT = doubleRDRS_ASN_X_GEO_LAT;
            RDRX_ASX_GEO_LON = doubleRDRS_ASN_X_GEO_LON;
            RDRX_ASX_GEO_ALT = doubleRDRS_ASN_X_GEO_ALT;
            RDRX_ASX_GEO_AZ_LEFT = doubleRDRS_ASN_X_GEO_AZ_LEFT;
            RDRX_ASX_GEO_AZ_RIGHT = doubleRDRS_ASN_X_GEO_AZ_RIGHT;
            RDRX_ASX_GEO_EL_UPPER = doubleRDRS_ASN_X_GEO_EL_UPPER;
            RDRX_ASX_GEO_EL_LOWER = doubleRDRS_ASN_X_GEO_EL_LOWER;
            RDRX_ASX_GEO_RNG_EXT_HALF = doubleRDRS_ASN_X_GEO_RNG_EXT_HALF;

            RDRS_ASN_X_TIME_TO_COMP_ITER = doubleRDRS_ASN_X_TIME_TO_COMP_ITER;
            RDRS_ASN_X_ASS_RCS = doubleRDRS_ASN_X_ASS_RCS;
            RDRS_ASN_X_ASS_VEL = doubleRDRS_ASN_ASS_VEL;
          }
          LCA_TOPIC("AirSearchNormalGeoReferencedStatusTopic", 1, 0)
        };

      }
    }
  }

} // namespace Topics

#endif