#ifndef RAPID_TARGET_ACQUISITION_COMMAND_H
#define RAPID_TARGET_ACQUISITION_COMMAND_H

#include <memory>
#include <string>
#include "Command.h"
#include "CommonAirSearchValues.h"
#include "CommonRTAValues.h"
#include "CommonWeaponSystemValues.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "FloatEqualityChecker.h"
#include "SIMeterPerSecond.h"
#include "SIDegree.h"
#include "VolumeAircraftReferenced.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {
      namespace RapidTargetAcquisition
      {

        // RTA task type discrimination
        enum class RDRC_RTA_RTATYPE_ENUM : uint8_t
        {
          INVALID = 0x00,
          VACQ = 0x01,
          SACQ = 0x02,
          SHACQ = 0x03
        };

        /**
         * @brief this topic is a strongly typed one to one mapping of Radar Command 1 - message AC109-RADAR-HAT-MESS-1 (RTA - Air Search Rapid Target Acquisition Task vairant only) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         */
        class RapidTargetAcquisitionCommand : public Common::Command,
                                              public Common::VolumeAircraftReferenced
        {

          uint8_t RDRC_RTA_TV_MIN_PCT{}; // Percentage
          uint8_t RDRC_RTA_TV_DES_PCT{}; // Percentage
          RDRX_RTA_CNTR_SOURCE_ENUM RDRC_RTA_CNTR_SOURCE{};
          RDRX_RTA_SUSPEND_DISC_ENUM RDRC_RTA_SUSPEND_DISC{};
          RDRC_RTA_RTATYPE_ENUM RDRC_RTA_RTATYPE{};
          RDRX_RTA_SPATIAL_ENUM RDRC_RTA_SPATIAL{};
          uint16_t RDRC_RTA_IKTV_PRIORITY{};
          SI::SIMeter RDRC_RTA_IKTV_MIN_POS_X{IcdDefaults::IKTV_MIN_POS_X_DEFAULT};
          SI::SIMeter RDRC_RTA_IKTV_MIN_POS_Z{IcdDefaults::IKTV_MIN_POS_Z_DEFAULT};
          Common::IKTV_RAP_ATT_ENUM RDRC_RTA_IKTV_MIN_RAP_ATT{};
          SI::SIMeterPerSecond RDRC_RTA_IKTV_MIN_VEL_X{IcdDefaults::IKTV_MIN_VEL_X_DEFAULT};
          SI::SIMeterPerSecond RDRC_RTA_IKTV_MIN_VEL_Z{IcdDefaults::IKTV_MIN_VEL_Z_DEFAULT};
          SI::SIMeter RDRC_RTA_IKTV_DES_POS_X{IcdDefaults::IKTV_DES_POS_X_DEFAULT};
          SI::SIMeter RDRC_RTA_IKTV_DES_POS_Z{IcdDefaults::IKTV_DES_POS_Z_DEFAULT};
          Common::IKTV_RAP_ATT_ENUM RDRC_RTA_IKTV_DES_RAP_ATT{};
          SI::SIMeterPerSecond RDRC_RTA_IKTV_DES_VEL_X{IcdDefaults::IKTV_DES_VEL_X_DEFAULT};
          SI::SIMeterPerSecond RDRC_RTA_IKTV_DES_VEL_Z{IcdDefaults::IKTV_DES_VEL_Z_DEFAULT};
          bool RDRC_RTA_IKTV_PROACT{};

        public:

          //___________DEFAULT_MESSAGE_VALUES______________//
          // Default values are defined within the ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
          static constexpr RDRX_RTA_SUSPEND_DISC_ENUM RDRC_RTA_SUSPEND_DISC_DEFAULT{RDRX_RTA_SUSPEND_DISC_ENUM::CONTINUE};
          static constexpr RDRC_RTA_RTATYPE_ENUM RDRC_RTA_RTATYPE_DEFAULT{RDRC_RTA_RTATYPE_ENUM::INVALID};
          //______________________________________________//

          RapidTargetAcquisitionCommand() : Common::Command{},
                                            Common::VolumeAircraftReferenced{}
          {
          }

          virtual Common::WeaponSystemTaskType getTaskType() const noexcept override
          {
            return Common::WeaponSystemTaskType::AIR_SEARCH_RAPID_TARGET_ACQUISITION;
          }

          //___________FIELD_GETTERS______________//

          /**
           * @brief getter for the RDRC_RTA_TV_MIN_PCT
           * @returns the RDRC_RTA_TV_MIN_PCT
           */
          inline uint8_t get_RDRC_RTA_TV_MIN_PCT() const {
            return RDRC_RTA_TV_MIN_PCT;
          }

          /**
           * @brief getter for the RDRC_RTA_TV_DES_PCT
           * @returns the RDRC_RTA_TV_DES_PCT
           */
          inline uint8_t get_RDRC_RTA_TV_DES_PCT() const {
            return RDRC_RTA_TV_DES_PCT;
          }

          /**
           * @brief getter for the RDRC_RTA_CNTR_SOURCE
           * @returns the RDRC_RTA_CNTR_SOURCE
           */
          inline RDRX_RTA_CNTR_SOURCE_ENUM get_RDRC_RTA_CNTR_SOURCE() const {
            return RDRC_RTA_CNTR_SOURCE;
          }

          /**
           * @brief getter for the RDRC_RTA_SUSPEND_DISC
           * @returns the RDRC_RTA_SUSPEND_DISC
           */
          inline RDRX_RTA_SUSPEND_DISC_ENUM get_RDRC_RTA_SUSPEND_DISC() const {
            return RDRC_RTA_SUSPEND_DISC;
          }
          
          /**
           * @brief getter for the RDRC_RTA_RTATYPE
           * @returns the RDRC_RTA_RTATYPE
           */          
          inline RDRC_RTA_RTATYPE_ENUM get_RDRC_RTA_RTATYPE() const {
            return RDRC_RTA_RTATYPE;
          }

          /**
           * @brief getter for the RDRC_RTA_SPATIAL
           * @returns the RDRC_RTA_SPATIAL
           */
          inline RDRX_RTA_SPATIAL_ENUM get_RDRC_RTA_SPATIAL() const {
            return RDRC_RTA_SPATIAL;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_PRIORITY
           * @returns the RDRC_RTA_IKTV_PRIORITY
           */
          inline uint16_t get_RDRC_RTA_IKTV_PRIORITY() const {
            return RDRC_RTA_IKTV_PRIORITY;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_MIN_POS_X
           * @returns the RDRC_RTA_IKTV_MIN_POS_X
           */
          inline SI::SIMeter get_RDRC_RTA_IKTV_MIN_POS_X() const {
            return RDRC_RTA_IKTV_MIN_POS_X;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_MIN_POS_Z
           * @returns the RDRC_RTA_IKTV_MIN_POS_Z
           */
          inline SI::SIMeter get_RDRC_RTA_IKTV_MIN_POS_Z() const {
            return RDRC_RTA_IKTV_MIN_POS_Z;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_MIN_RAP_ATT
           * @returns the RDRC_RTA_IKTV_MIN_RAP_ATT
           */
          inline Common::IKTV_RAP_ATT_ENUM get_RDRC_RTA_IKTV_MIN_RAP_ATT() const {
            return RDRC_RTA_IKTV_MIN_RAP_ATT;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_MIN_VEL_X
           * @returns the RDRC_RTA_IKTV_MIN_VEL_X
           */
          inline SI::SIMeterPerSecond get_RDRC_RTA_IKTV_MIN_VEL_X() const {
            return RDRC_RTA_IKTV_MIN_VEL_X;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_MIN_VEL_Z
           * @returns the RDRC_RTA_IKTV_MIN_VEL_Z
           */
          inline SI::SIMeterPerSecond get_RDRC_RTA_IKTV_MIN_VEL_Z() const {
            return RDRC_RTA_IKTV_MIN_VEL_Z;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_DES_POS_X
           * @returns the RDRC_RTA_IKTV_DES_POS_X
           */
          inline SI::SIMeter get_RDRC_RTA_IKTV_DES_POS_X() const {
            return RDRC_RTA_IKTV_DES_POS_X;
          } 

          /**
           * @brief getter for the RDRC_RTA_IKTV_DES_POS_Z
           * @returns the RDRC_RTA_IKTV_DES_POS_Z
           */
          inline SI::SIMeter get_RDRC_RTA_IKTV_DES_POS_Z() const {
            return RDRC_RTA_IKTV_DES_POS_Z;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_DES_RAP_ATT
           * @returns the RDRC_RTA_IKTV_DES_RAP_ATT
           */
          inline Common::IKTV_RAP_ATT_ENUM get_RDRC_RTA_IKTV_DES_RAP_ATT() const {
            return RDRC_RTA_IKTV_DES_RAP_ATT;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_DES_VEL_X
           * @returns the RDRC_RTA_IKTV_DES_VEL_X
           */
          inline SI::SIMeterPerSecond get_RDRC_RTA_IKTV_DES_VEL_X() const {
            return RDRC_RTA_IKTV_DES_VEL_X;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_DES_VEL_Z
           * @returns the RDRC_RTA_IKTV_DES_VEL_Z
           */
          inline SI::SIMeterPerSecond get_RDRC_RTA_IKTV_DES_VEL_Z() const {
            return RDRC_RTA_IKTV_DES_VEL_Z;
          }

          /**
           * @brief getter for the RDRC_RTA_IKTV_PROACT
           * @returns the RDRC_RTA_IKTV_PROACT
           */
          inline bool get_RDRC_RTA_IKTV_PROACT() const {
            return RDRC_RTA_IKTV_PROACT;
          }

          //______________________________________//


          //___________FIELD_SETTERS______________//

          void setToIcdDefault() noexcept override
          {
            Command::setToIcdDefault();
            Common::VolumeAircraftReferenced::setToIcdDefault();
            RDRC_RTA_TV_MIN_PCT = IcdDefaultsAs::TV_MIN_PCT_DEFAULT;
            RDRC_RTA_TV_DES_PCT = IcdDefaultsAs::TV_DES_PCT_DEFAULT;
            RDRC_RTA_CNTR_SOURCE = IcdDefaultsRta::RDRX_RTA_CNTR_SOURCE_DEFAULT;
            RDRC_RTA_SUSPEND_DISC = RDRC_RTA_SUSPEND_DISC_DEFAULT;
            RDRC_RTA_RTATYPE = RDRC_RTA_RTATYPE_DEFAULT;
            RDRC_RTA_SPATIAL = IcdDefaultsRta::RDRX_RTA_SPATIAL_DEFAULT;
            RDRC_RTA_IKTV_PRIORITY = IcdDefaults::IKTV_PRIORITY_DEFAULT;
            RDRC_RTA_IKTV_MIN_POS_X = IcdDefaults::IKTV_MIN_POS_X_DEFAULT;
            RDRC_RTA_IKTV_MIN_POS_Z = IcdDefaults::IKTV_MIN_POS_Z_DEFAULT;
            RDRC_RTA_IKTV_MIN_RAP_ATT = IcdDefaults::IKTV_MIN_RAP_ATT_DEFAULT;
            RDRC_RTA_IKTV_MIN_VEL_X = IcdDefaults::IKTV_MIN_VEL_X_DEFAULT;
            RDRC_RTA_IKTV_MIN_VEL_Z = IcdDefaults::IKTV_MIN_VEL_Z_DEFAULT;
            RDRC_RTA_IKTV_DES_POS_X = IcdDefaults::IKTV_DES_POS_X_DEFAULT;
            RDRC_RTA_IKTV_DES_POS_Z = IcdDefaults::IKTV_DES_POS_Z_DEFAULT;
            RDRC_RTA_IKTV_DES_RAP_ATT = IcdDefaults::IKTV_DES_RAP_ATT_DEFAULT;
            RDRC_RTA_IKTV_DES_VEL_X = IcdDefaults::IKTV_DES_VEL_X_DEFAULT;
            RDRC_RTA_IKTV_DES_VEL_Z = IcdDefaults::IKTV_DES_VEL_Z_DEFAULT;
            RDRC_RTA_IKTV_PROACT = IcdDefaults::IKTV_PROACT_DEFAULT;
          }

          /**
           * @brief setter for the RDRC_RTA_TV_MIN_PCT
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_TV_MIN_PCT(uint8_t arg) {
            RDRC_RTA_TV_MIN_PCT = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_TV_DES_PCT
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_TV_DES_PCT(uint8_t arg) {
            RDRC_RTA_TV_DES_PCT = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_CNTR_SOURCE
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_CNTR_SOURCE(RDRX_RTA_CNTR_SOURCE_ENUM arg) {
            RDRC_RTA_CNTR_SOURCE = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_SUSPEND_DISC
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_SUSPEND_DISC(RDRX_RTA_SUSPEND_DISC_ENUM arg) {
            RDRC_RTA_SUSPEND_DISC = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_RTATYPE
           * @param arg : the value to be set
           */          
          inline void set_RDRC_RTA_RTATYPE(RDRC_RTA_RTATYPE_ENUM arg) {
            RDRC_RTA_RTATYPE = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_SPATIAL
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_SPATIAL(RDRX_RTA_SPATIAL_ENUM arg) {
            RDRC_RTA_SPATIAL = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_PRIORITY
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_PRIORITY(uint16_t arg) {
            RDRC_RTA_IKTV_PRIORITY = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_MIN_POS_X
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_MIN_POS_X(SI::SIMeter arg) {
            RDRC_RTA_IKTV_MIN_POS_X = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_MIN_POS_Z
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_MIN_POS_Z(SI::SIMeter arg) {
            RDRC_RTA_IKTV_MIN_POS_Z = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_MIN_RAP_ATT
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_MIN_RAP_ATT(Common::IKTV_RAP_ATT_ENUM arg) {
            RDRC_RTA_IKTV_MIN_RAP_ATT = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_MIN_VEL_X
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_MIN_VEL_X(SI::SIMeterPerSecond arg) {
            RDRC_RTA_IKTV_MIN_VEL_X = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_MIN_VEL_Z
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_MIN_VEL_Z(SI::SIMeterPerSecond arg) {
            RDRC_RTA_IKTV_MIN_VEL_Z = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_DES_POS_X
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_DES_POS_X(SI::SIMeter arg) {
            RDRC_RTA_IKTV_DES_POS_X = arg;
          } 

          /**
           * @brief setter for the RDRC_RTA_IKTV_DES_POS_Z
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_DES_POS_Z(SI::SIMeter arg) {
            RDRC_RTA_IKTV_DES_POS_Z = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_DES_RAP_ATT
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_DES_RAP_ATT(Common::IKTV_RAP_ATT_ENUM arg) {
            RDRC_RTA_IKTV_DES_RAP_ATT = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_DES_VEL_X
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_DES_VEL_X(SI::SIMeterPerSecond arg) {
            RDRC_RTA_IKTV_DES_VEL_X = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_DES_VEL_Z
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_DES_VEL_Z(SI::SIMeterPerSecond arg) {
            RDRC_RTA_IKTV_DES_VEL_Z = arg;
          }

          /**
           * @brief setter for the RDRC_RTA_IKTV_PROACT
           * @param arg : the value to be set
           */
          inline void set_RDRC_RTA_IKTV_PROACT(bool arg) {
            RDRC_RTA_IKTV_PROACT = arg;
          }


          //______________________________________//


          /**
           * @brief equality operator
           * @returns true if the field in other contain the same values, false otherwise
           */
          bool operator==(const RapidTargetAcquisitionCommand& other) const
          {
            return Command::operator==(other) &&
                   Common::VolumeAircraftReferenced::operator==(other) &&
                   RDRC_RTA_TV_MIN_PCT == other.RDRC_RTA_TV_MIN_PCT &&
                   RDRC_RTA_TV_DES_PCT == other.RDRC_RTA_TV_DES_PCT &&
                   RDRC_RTA_CNTR_SOURCE == other.RDRC_RTA_CNTR_SOURCE &&
                   RDRC_RTA_SUSPEND_DISC == other.RDRC_RTA_SUSPEND_DISC &&
                   RDRC_RTA_RTATYPE == other.RDRC_RTA_RTATYPE &&
                   RDRC_RTA_SPATIAL == other.RDRC_RTA_SPATIAL &&
                   RDRC_RTA_IKTV_PRIORITY == other.RDRC_RTA_IKTV_PRIORITY &&
                   RDRC_RTA_IKTV_MIN_POS_X == other.RDRC_RTA_IKTV_MIN_POS_X &&
                   RDRC_RTA_IKTV_MIN_POS_Z == other.RDRC_RTA_IKTV_MIN_POS_Z &&
                   RDRC_RTA_IKTV_MIN_RAP_ATT == other.RDRC_RTA_IKTV_MIN_RAP_ATT &&
                   RDRC_RTA_IKTV_MIN_VEL_X == other.RDRC_RTA_IKTV_MIN_VEL_X &&
                   RDRC_RTA_IKTV_MIN_VEL_Z == other.RDRC_RTA_IKTV_MIN_VEL_Z &&
                   RDRC_RTA_IKTV_DES_POS_X == other.RDRC_RTA_IKTV_DES_POS_X &&
                   RDRC_RTA_IKTV_DES_POS_Z == other.RDRC_RTA_IKTV_DES_POS_Z &&
                   RDRC_RTA_IKTV_DES_RAP_ATT == other.RDRC_RTA_IKTV_DES_RAP_ATT &&
                   RDRC_RTA_IKTV_DES_VEL_X == other.RDRC_RTA_IKTV_DES_VEL_X &&
                   RDRC_RTA_IKTV_DES_VEL_Z == other.RDRC_RTA_IKTV_DES_VEL_Z &&
                   RDRC_RTA_IKTV_PROACT == other.RDRC_RTA_IKTV_PROACT;
          }

          bool operator!=(const RapidTargetAcquisitionCommand &other) const
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
            Common::WeaponSystemTaskType RDRC_RTA_TASK_TYPE = getTaskType();

            // Volume params
            double doubleRDRC_RTA_AC_AZ_CNTR{RDRX_ASX_AC_AZ_CNTR()};
            double doubleRDRC_RTA_AC_EL_CNTR{RDRX_ASX_AC_EL_CNTR()};
            double doubleRDRC_RTA_AC_AZ_HALF{RDRX_ASX_AC_AZ_HALF()};
            double doubleRDRC_RTA_AC_EL_HALF{RDRX_ASX_AC_EL_HALF()};
            double doubleRDRC_RTA_AC_SLT_MIN{RDRX_ASX_AC_SLT_MIN()};
            double doubleRDRC_RTA_AC_SLT_MAX{RDRX_ASX_AC_SLT_MAX()};            

            // generic
            double doubleRDRC_RTA_IKTV_MIN_POS_X{RDRC_RTA_IKTV_MIN_POS_X()};
            double doubleRDRC_RTA_IKTV_MIN_POS_Z{RDRC_RTA_IKTV_MIN_POS_Z()};
            double doubleRDRC_RTA_IKTV_DES_POS_X{RDRC_RTA_IKTV_DES_POS_X()};
            double doubleRDRC_RTA_IKTV_DES_POS_Z{RDRC_RTA_IKTV_DES_POS_Z()};
            double doubleRDRC_RTA_IKTV_MIN_VEL_X{RDRC_RTA_IKTV_MIN_VEL_X()};
            double doubleRDRC_RTA_IKTV_MIN_VEL_Z{RDRC_RTA_IKTV_MIN_VEL_Z()};
            double doubleRDRC_RTA_IKTV_DES_VEL_X{RDRC_RTA_IKTV_DES_VEL_X()};
            double doubleRDRC_RTA_IKTV_DES_VEL_Z{RDRC_RTA_IKTV_DES_VEL_Z()};

            archive.Serialise(TASK_IDENT, "RDRC_RTA_TASK_IDENT");
            archive.Serialise(CMD, "RDRC_RTA_CMD");
            archive.Serialise(RDRC_RTA_TASK_TYPE, "RDRC_RTA_TASK_TYPE");
            archive.Serialise(TV_PRIORITY, "RDRC_RTA_TV_PRIORITY");
            archive.Serialise(RDRC_RTA_TV_MIN_PCT, "RDRC_RTA_TV_MIN_PCT");
            archive.Serialise(RDRC_RTA_TV_DES_PCT, "RDRC_RTA_TV_DES_PCT");
            archive.Serialise(RDRC_RTA_CNTR_SOURCE, "RDRC_RTA_CNTR_SOURCE");
            archive.Serialise(RDRC_RTA_SUSPEND_DISC, "RDRC_RTA_SUSPEND_DISC");
            archive.Serialise(RDRC_RTA_RTATYPE, "RDRC_RTA_RTATYPE");
            archive.Serialise(RDRC_RTA_SPATIAL, "RDRC_RTA_SPATIAL");

            // Volume params
            archive.Serialise(RDRX_ASX_AC_STABTYPE, "RDRC_RTA_AC_STABTYPE");
            archive.Serialise(doubleRDRC_RTA_AC_AZ_CNTR, "RDRC_RTA_AC_AZ_CNTR");
            archive.Serialise(doubleRDRC_RTA_AC_EL_CNTR, "RDRC_RTA_AC_EL_CNTR");
            archive.Serialise(doubleRDRC_RTA_AC_AZ_HALF, "RDRC_RTA_AC_AZ_HALF");
            archive.Serialise(doubleRDRC_RTA_AC_EL_HALF, "RDRC_RTA_AC_EL_HALF");
            archive.Serialise(doubleRDRC_RTA_AC_SLT_MIN, "RDRC_RTA_AC_SLT_MIN");
            archive.Serialise(doubleRDRC_RTA_AC_SLT_MAX, "RDRC_RTA_AC_SLT_MAX");
            
            archive.Serialise(RDRC_RTA_IKTV_PRIORITY, "RDRC_RTA_IKTV_PRIORITY");
            archive.Serialise(doubleRDRC_RTA_IKTV_MIN_POS_X, "doubleRDRC_RTA_IKTV_MIN_POS_X");
            archive.Serialise(doubleRDRC_RTA_IKTV_MIN_POS_Z, "doubleRDRC_RTA_IKTV_MIN_POS_Z");
            archive.Serialise(RDRC_RTA_IKTV_MIN_RAP_ATT, "RDRC_RTA_IKTV_MIN_RAP_ATT");
            archive.Serialise(doubleRDRC_RTA_IKTV_MIN_VEL_X, "doubleRDRC_RTA_IKTV_MIN_VEL_X");
            archive.Serialise(doubleRDRC_RTA_IKTV_MIN_VEL_Z, "doubleRDRC_RTA_IKTV_MIN_VEL_Z");
            archive.Serialise(doubleRDRC_RTA_IKTV_DES_POS_X, "doubleRDRC_RTA_IKTV_DES_POS_X");
            archive.Serialise(doubleRDRC_RTA_IKTV_DES_POS_Z, "doubleRDRC_RTA_IKTV_DES_POS_Z");
            archive.Serialise(RDRC_RTA_IKTV_DES_RAP_ATT, "RDRC_RTA_IKTV_DES_RAP_ATT");
            archive.Serialise(doubleRDRC_RTA_IKTV_DES_VEL_X, "doubleRDRC_RTA_IKTV_DES_VEL_X");
            archive.Serialise(doubleRDRC_RTA_IKTV_DES_VEL_Z, "doubleRDRC_RTA_IKTV_DES_VEL_Z");
            archive.Serialise(RDRC_RTA_IKTV_PROACT, "RDRC_RTA_IKTV_PROACT");
            archive.Serialise(TDI, "RDRC_RTA_TDI");

            // Volume params
            RDRX_ASX_AC_AZ_CNTR = doubleRDRC_RTA_AC_AZ_CNTR;
            RDRX_ASX_AC_EL_CNTR = doubleRDRC_RTA_AC_EL_CNTR;
            RDRX_ASX_AC_AZ_HALF = doubleRDRC_RTA_AC_AZ_HALF;
            RDRX_ASX_AC_EL_HALF = doubleRDRC_RTA_AC_EL_HALF;
            RDRX_ASX_AC_SLT_MIN = doubleRDRC_RTA_AC_SLT_MIN;
            RDRX_ASX_AC_SLT_MAX = doubleRDRC_RTA_AC_SLT_MAX;

            // generic
            RDRC_RTA_IKTV_MIN_POS_X = doubleRDRC_RTA_IKTV_MIN_POS_X;
            RDRC_RTA_IKTV_MIN_POS_Z = doubleRDRC_RTA_IKTV_MIN_POS_Z;
            RDRC_RTA_IKTV_DES_POS_X = doubleRDRC_RTA_IKTV_DES_POS_X;
            RDRC_RTA_IKTV_DES_POS_Z = doubleRDRC_RTA_IKTV_DES_POS_Z;
            RDRC_RTA_IKTV_MIN_VEL_X = doubleRDRC_RTA_IKTV_MIN_VEL_X;
            RDRC_RTA_IKTV_MIN_VEL_Z = doubleRDRC_RTA_IKTV_MIN_VEL_Z;
            RDRC_RTA_IKTV_DES_VEL_X = doubleRDRC_RTA_IKTV_DES_VEL_X;
            RDRC_RTA_IKTV_DES_VEL_Z = doubleRDRC_RTA_IKTV_DES_VEL_Z;
          }

          LCA_TOPIC("RapidTargetAcquisitionCommand", 1, 0)
        };
      } // namespace RapidTargetAcquisition
    }   // namespace WeaponSystem
  }     // namespace EcrsMK2
}       // namespace Topics

#endif