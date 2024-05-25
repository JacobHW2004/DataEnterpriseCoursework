#ifndef AIR_SEARCH_CUED_AIRCRAFT_REFERENCED_COMMAND_TOPIC_H
#define AIR_SEARCH_CUED_AIRCRAFT_REFERENCED_COMMAND_TOPIC_H

#include <string>

#include "AirSearchCuedCommand.h"
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
         * @brief this topic is a strongly typed one to one mapping of Radar Command 2 - message AC36-RADAR-HAT-MESS-1 (ASC - Aircraft Referenced variant only) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         * @todo add doxygen to each attribute describing its units.
         * @todo add doxygen to each attribute describing its ICD message counter part
         */

        class AirSearchCuedAircraftReferencedCommandTopic : public AirSearchCuedCommand,
                                                            public Common::VolumeAircraftReferenced
        {

        public:

          /**
           * @brief default constructor, sets all values to ICD defaults
           */
          AirSearchCuedAircraftReferencedCommandTopic() : AirSearchCuedCommand{},
                                                          Common::VolumeAircraftReferenced{}
          {
          }

          void setToIcdDefault() noexcept override
          {
            AirSearchCuedCommand::setToIcdDefault();
            Common::VolumeAircraftReferenced::setToIcdDefault();
          }

          /**
           * @brief equality operator
           * @returns true if the field in other contain the same values, false otherwise
           */
          bool operator==(const AirSearchCuedAircraftReferencedCommandTopic& other) const
          {
            return
              AirSearchCuedCommand::operator==(other) &&
              Common::VolumeAircraftReferenced::operator==(other);
          }

          /**
           * @brief inequality operator
           * @returns the negative of the equality operator
           */
          bool operator!=(const AirSearchCuedAircraftReferencedCommandTopic &other) const
          {
            return !(*this == other);
          }

          /**
           * @brief Serialise function required for communications
           */
          template <class T>
          void Serialise(T &archive)
          {
            Common::WeaponSystemTaskType RDRC_ASC_TASK_TYPE = getTaskType();

            // Generic AirSearch params
            double doubleRDRC_ASC_IKTV_MIN_POS_X{RDRC_ASC_IKTV_MIN_POS_X()};
            double doubleRDRC_ASC_IKTV_MIN_POS_Z{RDRC_ASC_IKTV_MIN_POS_Z()};
            double doubleRDRC_ASC_IKTV_DES_POS_X{RDRC_ASC_IKTV_DES_POS_X()};
            double doubleRDRC_ASC_IKTV_DES_POS_Z{RDRC_ASC_IKTV_DES_POS_Z()};
            double doubleRDRC_ASC_IKTV_MIN_VEL_X{RDRC_ASC_IKTV_MIN_VEL_X()};
            double doubleRDRC_ASC_IKTV_MIN_VEL_Z{RDRC_ASC_IKTV_MIN_VEL_Z()};
            double doubleRDRC_ASC_IKTV_DES_VEL_X{RDRC_ASC_IKTV_DES_VEL_X()};
            double doubleRDRC_ASC_IKTV_DES_VEL_Z{RDRC_ASC_IKTV_DES_VEL_Z()};
            double doubleRDRC_ASC_ASS_RCS{RDRC_ASC_ASS_RCS()};
            double doubleRDRC_ASC_ASS_VEL{RDRC_ASC_ASS_VEL()};

            // Volume params
            double doubleRDRC_ASC_AC_AZ_CNTR{RDRX_ASX_AC_AZ_CNTR()};
            double doubleRDRC_ASC_AC_EL_CNTR{RDRX_ASX_AC_EL_CNTR()};
            double doubleRDRC_ASC_AC_AZ_HALF{RDRX_ASX_AC_AZ_HALF()};
            double doubleRDRC_ASC_AC_EL_HALF{RDRX_ASX_AC_EL_HALF()};
            double doubleRDRC_ASC_AC_SLT_MIN{RDRX_ASX_AC_SLT_MIN()};
            double doubleRDRC_ASC_AC_SLT_MAX{RDRX_ASX_AC_SLT_MAX()};

            archive.Serialise(TASK_IDENT, "RDRC_ASC_TASK_IDENT");
            archive.Serialise(CMD, "RDRC_ASC_CMD");
            archive.Serialise(RDRC_ASC_TASK_TYPE, "RDRC_ASC_TASK_TYPE");
            archive.Serialise(TV_PRIORITY, "RDRC_ASC_TV_PRIORITY");
            archive.Serialise(RDRC_ASC_TV_MIN_PCT, "RDRC_ASC_TV_MIN_PCT");
            archive.Serialise(RDRC_ASC_TV_DES_PCT, "RDRC_ASC_TV_DES_PCT");
            archive.Serialise(RDRC_ASC_PAT_T, "RDRC_ASC_PAT_T");
            archive.Serialise(RDRC_ASC_PAT_FS, "RDRC_ASC_PAT_FS");
            archive.Serialise(RDRC_ASC_PAT_D, "RDRC_ASC_PAT_D");
            archive.Serialise(RDRC_ASC_PAT_I, "RDRC_ASC_PAT_I");
            archive.Serialise(RDRC_ASC_TXDISC, "RDRC_ASC_TXDISC");
            archive.Serialise(RDRC_ASC_ENABLE_KTV_OVERRIDE, "RDRC_ASC_ENABLE_KTV_OVERRIDE");
            archive.Serialise(RDRC_ASC_SPATIAL, "RDRC_ASC_SPATIAL");

            // Volume params
            archive.Serialise(RDRX_ASX_AC_STABTYPE, "RDRC_ASC_AC_STABTYPE");
            archive.Serialise(doubleRDRC_ASC_AC_AZ_CNTR, "RDRC_ASC_AC_AZ_CNTR");
            archive.Serialise(doubleRDRC_ASC_AC_EL_CNTR, "RDRC_ASC_AC_EL_CNTR");
            archive.Serialise(doubleRDRC_ASC_AC_AZ_HALF, "RDRC_ASC_AC_AZ_HALF");
            archive.Serialise(doubleRDRC_ASC_AC_EL_HALF, "RDRC_ASC_AC_EL_HALF");
            archive.Serialise(doubleRDRC_ASC_AC_SLT_MIN, "RDRC_ASC_AC_SLT_MIN");
            archive.Serialise(doubleRDRC_ASC_AC_SLT_MAX, "RDRC_ASC_AC_SLT_MAX");
            
            archive.Serialise(RDRC_ASC_IKTV_PRIORITY, "RDRC_ASC_IKTV_PRIORITY");
            archive.Serialise(doubleRDRC_ASC_IKTV_MIN_POS_X, "doubleRDRC_ASC_IKTV_MIN_POS_X");
            archive.Serialise(doubleRDRC_ASC_IKTV_MIN_POS_Z, "doubleRDRC_ASC_IKTV_MIN_POS_Z");
            archive.Serialise(RDRC_ASC_IKTV_MIN_RAP_ATT, "RDRC_ASC_IKTV_MIN_RAP_ATT");
            archive.Serialise(doubleRDRC_ASC_IKTV_MIN_VEL_X, "doubleRDRC_ASC_IKTV_MIN_VEL_X");
            archive.Serialise(doubleRDRC_ASC_IKTV_MIN_VEL_Z, "doubleRDRC_ASC_IKTV_MIN_VEL_Z");
            archive.Serialise(doubleRDRC_ASC_IKTV_DES_POS_X, "doubleRDRC_ASC_IKTV_DES_POS_X");
            archive.Serialise(doubleRDRC_ASC_IKTV_DES_POS_Z, "doubleRDRC_ASC_IKTV_DES_POS_Z");
            archive.Serialise(RDRC_ASC_IKTV_DES_RAP_ATT, "RDRC_ASC_IKTV_DES_RAP_ATT");
            archive.Serialise(doubleRDRC_ASC_IKTV_DES_VEL_X, "doubleRDRC_ASC_IKTV_DES_VEL_X");
            archive.Serialise(doubleRDRC_ASC_IKTV_DES_VEL_Z, "doubleRDRC_ASC_IKTV_DES_VEL_Z");
            archive.Serialise(RDRC_ASC_IKTV_PROACT, "RDRC_ASC_IKTV_PROACT");
            archive.Serialise(doubleRDRC_ASC_ASS_RCS, "doubleRDRC_ASC_ASS_RCS");
            archive.Serialise(RDRC_ASC_ASS_TYPE, "RDRC_ASC_ASS_TYPE");
            archive.Serialise(doubleRDRC_ASC_ASS_VEL, "doubleRDRC_ASC_ASS_VEL");
            archive.Serialise(RDRC_ASC_ASS_HEMIS, "RDRC_ASC_ASS_HEMIS");
            archive.Serialise(RDRC_ASC_ENHD_CTRL, "RDRC_ASC_ENHD_CTRL");
            archive.Serialise(RDRC_ASC_REQD_RES1, "RDRC_ASC_REQD_RES1");
            archive.Serialise(RDRC_ASC_REQD_RES2, "RDRC_ASC_REQD_RES2");
            archive.Serialise(TDI, "RDRC_ASC_TDI");

            // Volume params
            RDRX_ASX_AC_AZ_CNTR = doubleRDRC_ASC_AC_AZ_CNTR;
            RDRX_ASX_AC_EL_CNTR = doubleRDRC_ASC_AC_EL_CNTR;
            RDRX_ASX_AC_AZ_HALF = doubleRDRC_ASC_AC_AZ_HALF;
            RDRX_ASX_AC_EL_HALF = doubleRDRC_ASC_AC_EL_HALF;
            RDRX_ASX_AC_SLT_MIN = doubleRDRC_ASC_AC_SLT_MIN;
            RDRX_ASX_AC_SLT_MAX = doubleRDRC_ASC_AC_SLT_MAX;

            // Generic AirSearch params
            RDRC_ASC_IKTV_MIN_POS_X = doubleRDRC_ASC_IKTV_MIN_POS_X;
            RDRC_ASC_IKTV_MIN_POS_Z = doubleRDRC_ASC_IKTV_MIN_POS_Z;
            RDRC_ASC_IKTV_DES_POS_X = doubleRDRC_ASC_IKTV_DES_POS_X;
            RDRC_ASC_IKTV_DES_POS_Z = doubleRDRC_ASC_IKTV_DES_POS_Z;
            RDRC_ASC_IKTV_MIN_VEL_X = doubleRDRC_ASC_IKTV_MIN_VEL_X;
            RDRC_ASC_IKTV_MIN_VEL_Z = doubleRDRC_ASC_IKTV_MIN_VEL_Z;
            RDRC_ASC_IKTV_DES_VEL_X = doubleRDRC_ASC_IKTV_DES_VEL_X;
            RDRC_ASC_IKTV_DES_VEL_Z = doubleRDRC_ASC_IKTV_DES_VEL_Z;
            RDRC_ASC_ASS_RCS = doubleRDRC_ASC_ASS_RCS;
            RDRC_ASC_ASS_VEL = doubleRDRC_ASC_ASS_VEL;
          }

          LCA_TOPIC("AirSearchCuedAircraftReferencedCommandTopic", 1, 0)
        };

      } // namepsace AirSearch
    }   // namespace WeaponSystem
  }     // namepsace EcrsMK2
} // namepsace Topics

#endif