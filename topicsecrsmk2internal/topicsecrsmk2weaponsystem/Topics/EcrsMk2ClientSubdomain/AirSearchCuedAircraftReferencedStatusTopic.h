#ifndef AIR_SEARCH_CUED_AIRCRAFT_REFERENCED_STATUS_TOPIC_H
#define AIR_SEARCH_CUED_AIRCRAFT_REFERENCED_STATUS_TOPIC_H

#include <string>

#include "AirSearchCuedStatus.h"
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
         * @brief this topic is a strongly typed one to one mapping of Radar Status 1 - (ASC - status Aircraft Referenced variant only) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         * @todo add doxygen to each attribute describing its units.
         * @todo add doxygen to each attribute describing its ICD message counter part
         */
        class AirSearchCuedAircraftReferencedStatusTopic : public AirSearchCuedStatus,
                                                           public Common::VolumeAircraftReferenced
        {

        public:

          /**
           * @brief default constructor, sets all values to ICD defaults
           */
          AirSearchCuedAircraftReferencedStatusTopic() : AirSearchCuedStatus{},
                                                         Common::VolumeAircraftReferenced{}
          {
          }

          void setToIcdDefault() noexcept override
          {
            AirSearchCuedStatus::setToIcdDefault();
            Common::VolumeAircraftReferenced::setToIcdDefault();
          }

          /**
           * @brief equality operator
           * @returns true if the field in other contain the same values, false otherwise
           */
          bool operator==(const AirSearchCuedAircraftReferencedStatusTopic& other) const
          {
            return
              AirSearchCuedStatus::operator==(other) &&
              Common::VolumeAircraftReferenced::operator==(other);
          }

          /**
           * @brief inequality operator
           * @returns the negative of the equality operator
           */
          bool operator!=(const AirSearchCuedAircraftReferencedStatusTopic& other) const
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
            double doubleRDRS_ASC_AC_AZ_CNTR{RDRX_ASX_AC_AZ_CNTR()};
            double doubleRDRS_ASC_AC_EL_CNTR{RDRX_ASX_AC_EL_CNTR()};
            double doubleRDRS_ASC_AC_AZ_HALF{RDRX_ASX_AC_AZ_HALF()};
            double doubleRDRS_ASC_AC_EL_HALF{RDRX_ASX_AC_EL_HALF()};
            double doubleRDRS_ASC_AC_SLT_MIN{RDRX_ASX_AC_SLT_MIN()};
            double doubleRDRS_ASC_AC_SLT_MAX{RDRX_ASX_AC_SLT_MAX()};

            // Generic AirSearch params
            double doubleRDRS_ASC_TIME_TO_COMP_ITER{RDRS_ASC_TIME_TO_COMP_ITER()};
            double doubleRDRS_ASC_ASS_RCS{RDRS_ASC_ASS_RCS()};
            double doubleRDRS_ASC_ASS_VEL{RDRS_ASC_ASS_VEL()};

            archive.Serialise(TASK_IDENT, "RDRS_ASC_TASK_IDENT");
            archive.Serialise(TASK_TYPE, "RDRS_ASC_TASK_TYPE");
            archive.Serialise(COND_MOD_STATUS, "RDRS_ASC_COND_MOD_STATUS");
            archive.Serialise(COND_STATE, "RDRS_ASC_COND_STATE");
            archive.Serialise(COND_SUSP_DETAIL, "RDRS_ASC_COND_SUSP_DETAIL");
            archive.Serialise(COND_MOD_TDI, "RDRS_ASC_COND_MOD_TDI");
            archive.Serialise(COND_REJECT_DETAIL, "RDRS_ASC_COND_REJECT_DETAIL");
            archive.Serialise(RDRS_ASC_ACHIEVED_PCT, "RDRS_ASC_ACHIEVED_PCT");
            archive.Serialise(RDRS_ASC_RES_REP_ACTUAL, "RDRS_ASC_RES_REP_ACTUAL");
            archive.Serialise(RDRS_ASC_RES_REP_PRED_DES, "RDRS_ASC_RES_REP_PRED_DES");
            archive.Serialise(RDRS_ASC_RES_REP_PRED_MIN, "RDRS_ASC_RES_REP_PRED_MIN");
            archive.Serialise(RDRS_ASC_RES_ANT_ACTUAL, "RDRS_ASC_RES_ANT_ACTUAL");
            archive.Serialise(RDRS_ASC_RES_ANT_PRED_DES, "RDRS_ASC_RES_ANT_PRED_DES");
            archive.Serialise(RDRS_ASC_RES_ANT_PRED_MIN, "RDRS_ASC_RES_ANT_PRED_MIN");
            archive.Serialise(RDRS_ASC_TXDISC, "RDRS_ASC_TXDISC");
            archive.Serialise(RDRS_ASC_SPATIAL, "RDRS_ASC_SPATIAL");

            // Volume params
            archive.Serialise(RDRX_ASX_AC_STABTYPE, "RDRS_ASC_AC_STABTYPE");
            archive.Serialise(doubleRDRS_ASC_AC_AZ_CNTR, "RDRS_ASC_AC_AZ_CNTR");
            archive.Serialise(doubleRDRS_ASC_AC_EL_CNTR, "RDRS_ASC_AC_EL_CNTR");
            archive.Serialise(doubleRDRS_ASC_AC_AZ_HALF, "RDRS_ASC_AC_AZ_HALF");
            archive.Serialise(doubleRDRS_ASC_AC_EL_HALF, "RDRS_ASC_AC_EL_HALF");
            archive.Serialise(doubleRDRS_ASC_AC_SLT_MIN, "RDRS_ASC_AC_SLT_MIN");
            archive.Serialise(doubleRDRS_ASC_AC_SLT_MAX, "RDRS_ASC_AC_SLT_MAX");

            archive.Serialise(RDRS_ASC_RATIO_DMD_ACT, "RDRS_ASC_RATIO_DMD_ACT");
            archive.Serialise(RDRS_ASC_PROG_ACT_VOL, "RDRS_ASC_PROG_ACT_VOL");
            archive.Serialise(doubleRDRS_ASC_TIME_TO_COMP_ITER, "RDRS_ASC_TIME_TO_COMP_ITER");
            archive.Serialise(RDRS_ASC_FRAME_COUNT, "RDRS_ASC_FRAME_COUNT");
            archive.Serialise(doubleRDRS_ASC_ASS_RCS, "RDRS_ASC_ASS_RCS");
            archive.Serialise(RDRS_ASC_ASS_TYPE, "RDRS_ASC_ASS_TYPE");
            archive.Serialise(doubleRDRS_ASC_ASS_VEL, "RDRS_ASC_ASS_VEL");
            archive.Serialise(RDRS_ASC_ASS_HEMIS, "RDRS_ASC_ASS_HEMIS");
            archive.Serialise(ACTUAL_TDI, "RDRS_ASC_TDI");

            RDRS_ASC_TIME_TO_COMP_ITER = doubleRDRS_ASC_TIME_TO_COMP_ITER;
            RDRS_ASC_ASS_RCS = doubleRDRS_ASC_ASS_RCS;
            RDRS_ASC_ASS_VEL = doubleRDRS_ASC_ASS_VEL;

            // Volume params
            RDRX_ASX_AC_AZ_CNTR = doubleRDRS_ASC_AC_AZ_CNTR;
            RDRX_ASX_AC_EL_CNTR = doubleRDRS_ASC_AC_EL_CNTR;
            RDRX_ASX_AC_AZ_HALF = doubleRDRS_ASC_AC_AZ_HALF;
            RDRX_ASX_AC_EL_HALF = doubleRDRS_ASC_AC_EL_HALF;
            RDRX_ASX_AC_SLT_MIN = doubleRDRS_ASC_AC_SLT_MIN;
            RDRX_ASX_AC_SLT_MAX = doubleRDRS_ASC_AC_SLT_MAX;
          }

          LCA_TOPIC("AirSearchCuedAircraftReferencedStatusTopic", 1, 0)
        };

      } // namespace AirSearchCued
    }   // namespace WeaponSystem
  }     // namespace EcrsMK2
} // namespace Topics

#endif