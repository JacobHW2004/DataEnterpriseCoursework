#ifndef AIR_SEARCH_NORMAL_AIRCRAFT_REFERENCED_STATUS_TOPIC_H
#define AIR_SEARCH_NORMAL_AIRCRAFT_REFERENCED_STATUS_TOPIC_H

#include <string>

#include "AirSearchNormalStatus.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "VolumeAircraftReferenced.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {

      namespace AirSearch
      {
        /**
         * @brief this topic is a strongly typed one to one mapping of Radar Status 2 - RADAR21-BRD-HAT-MESS-1 (ASN - status Aircraft Referenced variant only) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         * @todo add doxygen to each attribute describing its units.
         * @todo add doxygen to each attribute describing its ICD message counter part
         */
        class AirSearchNormalAircraftReferencedStatusTopic : public AirSearchNormalStatus,
                                                             public Common::VolumeAircraftReferenced
        {

        public:

          AirSearchNormalAircraftReferencedStatusTopic() : AirSearchNormalStatus{},
                                                           Common::VolumeAircraftReferenced{}
          {
          }

          void setToIcdDefault() noexcept override
          {
            AirSearchNormalStatus::setToIcdDefault();
            Common::VolumeAircraftReferenced::setToIcdDefault();
          }

          bool operator==(const AirSearchNormalAircraftReferencedStatusTopic& other) const
          {
            return
              AirSearchNormalStatus::operator==(other) &&
              Common::VolumeAircraftReferenced::operator==(other);
          }

          bool operator!=(const AirSearchNormalAircraftReferencedStatusTopic &other) const
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
     
            // Volume params
            double doubleRDRS_ASN_X_AC_AZ_CNTR{RDRX_ASX_AC_AZ_CNTR()};
            double doubleRDRS_ASN_X_AC_EL_CNTR{RDRX_ASX_AC_EL_CNTR()};
            double doubleRDRS_ASN_X_AC_AZ_HALF{RDRX_ASX_AC_AZ_HALF()};
            double doubleRDRS_ASN_X_AC_EL_HALF{RDRX_ASX_AC_EL_HALF()};
            double doubleRDRS_ASN_X_AC_SLT_MIN{RDRX_ASX_AC_SLT_MIN()};
            double doubleRDRS_ASN_X_AC_SLT_MAX{RDRX_ASX_AC_SLT_MAX()};          


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
            archive.Serialise(RDRX_ASX_AC_STABTYPE, "RDRS_ASN_X_AC_STABTYPE");
            archive.Serialise(doubleRDRS_ASN_X_AC_AZ_CNTR, "RDRS_ASN_X_AC_AZ_CNTR");
            archive.Serialise(doubleRDRS_ASN_X_AC_EL_CNTR, "RDRS_ASN_X_AC_EL_CNTR");
            archive.Serialise(doubleRDRS_ASN_X_AC_AZ_HALF, "RDRS_ASN_X_AC_AZ_HALF");
            archive.Serialise(doubleRDRS_ASN_X_AC_EL_HALF, "RDRS_ASN_X_AC_EL_HALF");
            archive.Serialise(doubleRDRS_ASN_X_AC_SLT_MIN, "RDRS_ASN_X_AC_SLT_MIN");
            archive.Serialise(doubleRDRS_ASN_X_AC_SLT_MAX, "RDRS_ASN_X_AC_SLT_MAX");

            archive.Serialise(RDRS_ASN_X_RATIO_DMD_ACT, "RDRS_ASN_X_RATIO_DMD_ACT");
            archive.Serialise(RDRS_ASN_X_PROG_ACT_VOL, "RDRS_ASN_X_PROG_ACT_VOL");
            archive.Serialise(doubleRDRS_ASN_X_TIME_TO_COMP_ITER, "RDRS_ASN_X_TIME_TO_COMP_ITER");
            archive.Serialise(RDRS_ASN_X_FRAME_COUNT, "RDRS_ASN_X_FRAME_COUNT");
            archive.Serialise(doubleRDRS_ASN_X_ASS_RCS, "RDRS_ASN_X_ASS_RCS");
            archive.Serialise(RDRS_ASN_X_ASS_TYPE, "RDRS_ASN_X_ASS_TYPE");
            archive.Serialise(doubleRDRS_ASN_ASS_VEL, "RDRS_ASN_X_ASS_VEL");
            archive.Serialise(RDRS_ASN_X_ASS_HEMIS, "RDRS_ASN_X_ASS_HEMIS");
            archive.Serialise(ACTUAL_TDI, "RDRS_SN_X_TDI");

            // Volume params
            RDRX_ASX_AC_AZ_CNTR = doubleRDRS_ASN_X_AC_AZ_CNTR;
            RDRX_ASX_AC_EL_CNTR = doubleRDRS_ASN_X_AC_EL_CNTR;
            RDRX_ASX_AC_AZ_HALF = doubleRDRS_ASN_X_AC_AZ_HALF;
            RDRX_ASX_AC_EL_HALF = doubleRDRS_ASN_X_AC_EL_HALF;
            RDRX_ASX_AC_SLT_MIN = doubleRDRS_ASN_X_AC_SLT_MIN;
            RDRX_ASX_AC_SLT_MAX = doubleRDRS_ASN_X_AC_SLT_MAX;
            RDRS_ASN_X_ASS_RCS = doubleRDRS_ASN_X_ASS_RCS;
            RDRS_ASN_X_ASS_VEL = doubleRDRS_ASN_ASS_VEL;

            RDRS_ASN_X_TIME_TO_COMP_ITER = doubleRDRS_ASN_X_TIME_TO_COMP_ITER;
          }
          LCA_TOPIC("AirSearchNormalAircraftReferencedStatusTopic", 2, 0)
        };
      } // namespace AirSearchCued
    } // namespace WeaponSystem
  } // namespace EcrsMK2
} // namespace Topics

#endif