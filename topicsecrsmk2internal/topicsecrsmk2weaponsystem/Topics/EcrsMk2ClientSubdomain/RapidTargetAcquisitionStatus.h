#ifndef RAPID_TARGET_ACQUISITION_STATUS_H
#define RAPID_TARGET_ACQUISITION_STATUS_H

#include <memory>
#include <string>
#include "CommonAirSearchValues.h"
#include "CommonRTAValues.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "FloatEqualityChecker.h"
#include "SIDegree.h"
#include "SISecond.h"
#include "Status.h"
#include "VolumeAircraftReferenced.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {    
      namespace RapidTargetAcquisition
      {

        //  Task modification status
        enum class RDRS_RTA_COND_MOD_STATUS_ENUM : uint8_t
        {
          NOT_COMMANDED = 0x00,
          ACCEPTED = 0x01,
          REJECTED = 0x02,
        };

        //____________________DEFAULT_MESSAGE_VALUES____________________//
        // Default values are defined within the ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02

        static constexpr uint8_t RDRS_RTA_ACHIEVED_PCT_DEFAULT{0};
        static constexpr float RDRS_RTA_RES_REP_ACTUAL_DEFAULT{0.0F};
        static constexpr float RDRS_RTA_RES_REP_PRED_DES_DEFAULT{0.0F};
        static constexpr float RDRS_RTA_RES_REP_PRED_MIN_DEFAULT{0.0F};
        static constexpr float RDRS_RTA_RES_ANT_ACTUAL_DEFAULT{0.0F};
        static constexpr float RDRS_RTA_RES_ANT_PRED_DES_DEFAULT{0.0F};
        static constexpr float RDRS_RTA_RES_ANT_PRED_MIN_DEFAULT{0.0F};
        static constexpr bool RDRS_RTA_RADAR_TRK_SUSP_DEFAULT{false};
        static constexpr RDRX_RTA_SUSPEND_DISC_ENUM RDRS_RTA_SUSPEND_DISC_RB_DEFAULT{RDRX_RTA_SUSPEND_DISC_ENUM::CONTINUE};
        static constexpr double RDRS_RTA_AZ_CL_DMD_RB_DEFAULT{0.0};
        static constexpr double RDRS_RTA_EL_CL_DMD_RB_DEFAULT{0.0};
        static constexpr uint8_t RDRS_RTA_RATIO_DMD_ACT_DEFAULT{0};
        static constexpr uint8_t RDRS_RTA_PROG_ACT_VOL_DEFAULT{0};
        static constexpr double RDRS_RTA_TIME_TO_COMP_ITER_DEFAULT{0.0};

        //_______________________________________________________________//

        /**
         * @brief this topic is a strongly typed one to one mapping of Radar Status 1 - RADAR101-BRD-HAT-MESS-1 (RTA - Air Search Rapid Target Acquisition Task Status vairant only) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         */
        class RapidTargetAcquisitionStatus : public Common::Status,
                                             public Common::VolumeAircraftReferenced
        {

          uint8_t RDRS_RTA_ACHIEVED_PCT{}; // Percentage
          float RDRS_RTA_RES_REP_ACTUAL{}; // Percentage
          float RDRS_RTA_RES_REP_PRED_DES{}; // Percentage
          float RDRS_RTA_RES_REP_PRED_MIN{}; // Percentage
          float RDRS_RTA_RES_ANT_ACTUAL{}; // Percentage
          float RDRS_RTA_RES_ANT_PRED_DES{}; // Percentage
          float RDRS_RTA_RES_ANT_PRED_MIN{}; // Percentage
          RDRX_RTA_CNTR_SOURCE_ENUM RDRS_RTA_CNTR_SOURCE{};
          bool RDRS_RTA_RADAR_TRK_SUSP{};
          RDRX_RTA_SUSPEND_DISC_ENUM RDRS_RTA_SUSPEND_DISC_RB{};
          RDRX_RTA_SPATIAL_ENUM RDRS_RTA_SPATIAL{};
          SI::SIDegree RDRS_RTA_AZ_CL_DMD_RB{};
          SI::SIDegree RDRS_RTA_EL_CL_DMD_RB{};
          uint8_t RDRS_RTA_RATIO_DMD_ACT{}; // Percentage
          uint8_t RDRS_RTA_PROG_ACT_VOL{}; // Percentage
          SI::SISecond RDRS_RTA_TIME_TO_COMP_ITER{};
          uint8_t RDRS_RTA_FRAME_COUNT{};

        public:

          RapidTargetAcquisitionStatus() : Common::Status{},
                                           Common::VolumeAircraftReferenced{}
          {
          }

          //___________FIELD_GETTERS______________//

          /**
           * @brief getter for the RDRS_RTA_ACHIEVED_PCT
           * @returns the RDRS_RTA_ACHIEVED_PCT
           */
          inline uint8_t get_RDRS_RTA_ACHIEVED_PCT() const {
            return RDRS_RTA_ACHIEVED_PCT;
          }

          /**
           * @brief getter for the RDRS_RTA_RES_REP_ACTUAL
           * @returns the RDRS_RTA_RES_REP_ACTUAL
           */
          inline float get_RDRS_RTA_RES_REP_ACTUAL() const {
            return RDRS_RTA_RES_REP_ACTUAL;
          }

          /**
           * @brief getter for the RDRS_RTA_RES_REP_PRED_DES
           * @returns the RDRS_RTA_RES_REP_PRED_DES
           */
          inline float get_RDRS_RTA_RES_REP_PRED_DES() const {
            return RDRS_RTA_RES_REP_PRED_DES;
          }

          /**
           * @brief getter for the RDRS_RTA_RES_REP_PRED_MIN
           * @returns the RDRS_RTA_RES_REP_PRED_MIN
           */
          inline float get_RDRS_RTA_RES_REP_PRED_MIN() const {
            return RDRS_RTA_RES_REP_PRED_MIN;
          }

          /**
           * @brief getter for the RDRS_RTA_RES_ANT_ACTUAL
           * @returns the RDRS_RTA_RES_ANT_ACTUAL
           */
          inline float get_RDRS_RTA_RES_ANT_ACTUAL() const { 
            return RDRS_RTA_RES_ANT_ACTUAL;
          }

          /**
           * @brief getter for the RDRS_RTA_RES_ANT_PRED_DES
           * @returns the RDRS_RTA_RES_ANT_PRED_DES
           */
          inline float get_RDRS_RTA_RES_ANT_PRED_DES() const {
            return RDRS_RTA_RES_ANT_PRED_DES;
          }

          /**
           * @brief getter for the RDRS_RTA_RES_ANT_PRED_MIN
           * @returns the RDRS_RTA_RES_ANT_PRED_MIN
           */
          inline float get_RDRS_RTA_RES_ANT_PRED_MIN() const {
            return RDRS_RTA_RES_ANT_PRED_MIN;
          }

          /**
           * @brief getter for the RDRS_RTA_CNTR_SOURCE
           * @returns the RDRS_RTA_CNTR_SOURCE
           */
          inline RDRX_RTA_CNTR_SOURCE_ENUM get_RDRS_RTA_CNTR_SOURCE() const {
            return RDRS_RTA_CNTR_SOURCE;
          }

          /**
           * @brief getter for the RDRS_RTA_RADAR_TRK_SUSP
           * @returns the RDRS_RTA_RADAR_TRK_SUSP
           */
          inline bool get_RDRS_RTA_RADAR_TRK_SUSP() const {
            return RDRS_RTA_RADAR_TRK_SUSP;
          }

          /**
           * @brief getter for the RDRS_RTA_SUSPEND_DISC_RB
           * @returns the RDRS_RTA_SUSPEND_DISC_RB
           */
          inline RDRX_RTA_SUSPEND_DISC_ENUM get_RDRS_RTA_SUSPEND_DISC_RB() const {
            return RDRS_RTA_SUSPEND_DISC_RB;
          }

          /**
           * @brief getter for the RDRS_RTA_SPATIAL
           * @returns the RDRS_RTA_SPATIAL
           */
          inline RDRX_RTA_SPATIAL_ENUM get_RDRS_RTA_SPATIAL() const {
            return RDRS_RTA_SPATIAL;
          }

          /**
           * @brief getter for the RDRS_RTA_AZ_CL_DMD_RB
           * @returns the RDRS_RTA_AZ_CL_DMD_RB
           */
          inline SI::SIDegree get_RDRS_RTA_AZ_CL_DMD_RB() const {
            return RDRS_RTA_AZ_CL_DMD_RB;
          }

          /**
           * @brief getter for the RDRS_RTA_EL_CL_DMD_RB
           * @returns the RDRS_RTA_EL_CL_DMD_RB
           */
          inline SI::SIDegree get_RDRS_RTA_EL_CL_DMD_RB() const {
            return RDRS_RTA_EL_CL_DMD_RB;
          }

          /**
           * @brief getter for the RDRS_RTA_RATIO_DMD_ACT
           * @returns the RDRS_RTA_RATIO_DMD_ACT
           */
          inline uint8_t get_RDRS_RTA_RATIO_DMD_ACT() const {
            return RDRS_RTA_RATIO_DMD_ACT;
          } 

          /**
           * @brief getter for the RDRS_RTA_PROG_ACT_VOL
           * @returns the RDRS_RTA_PROG_ACT_VOL
           */
          inline uint8_t get_RDRS_RTA_PROG_ACT_VOL() const {
            return RDRS_RTA_PROG_ACT_VOL;
          }

          /**
           * @brief getter for the RDRS_RTA_TIME_TO_COMP_ITER
           * @returns the RDRS_RTA_TIME_TO_COMP_ITER
           */
          inline SI::SISecond get_RDRS_RTA_TIME_TO_COMP_ITER() const {
            return RDRS_RTA_TIME_TO_COMP_ITER;
          }

          /**
           * @brief getter for the RDRS_RTA_FRAME_COUNT
           * @returns the RDRS_RTA_FRAME_COUNT
           */
          inline uint8_t get_RDRS_RTA_FRAME_COUNT() const {
            return RDRS_RTA_FRAME_COUNT;
          }

          //______________________________________//

          const void setTaskDemandIdentifierModification(const uint16_t &tdiModification) noexcept = delete;


          //___________FIELD_SETTERS______________//

          virtual void setToIcdDefault() noexcept override
          {
            Status::setToIcdDefault();
            Common::VolumeAircraftReferenced::setToIcdDefault();
            RDRS_RTA_ACHIEVED_PCT = RDRS_RTA_ACHIEVED_PCT_DEFAULT;
            RDRS_RTA_RES_REP_ACTUAL = RDRS_RTA_RES_REP_ACTUAL_DEFAULT;
            RDRS_RTA_RES_REP_PRED_DES = RDRS_RTA_RES_REP_PRED_DES_DEFAULT;
            RDRS_RTA_RES_REP_PRED_MIN = RDRS_RTA_RES_REP_PRED_MIN_DEFAULT;
            RDRS_RTA_RES_ANT_ACTUAL = RDRS_RTA_RES_ANT_ACTUAL_DEFAULT;
            RDRS_RTA_RES_ANT_PRED_DES = RDRS_RTA_RES_ANT_PRED_DES_DEFAULT;
            RDRS_RTA_RES_ANT_PRED_MIN = RDRS_RTA_RES_ANT_PRED_MIN_DEFAULT;
            RDRS_RTA_CNTR_SOURCE = IcdDefaultsRta::RDRX_RTA_CNTR_SOURCE_DEFAULT;
            RDRS_RTA_RADAR_TRK_SUSP = RDRS_RTA_RADAR_TRK_SUSP_DEFAULT;
            RDRS_RTA_SUSPEND_DISC_RB = RDRS_RTA_SUSPEND_DISC_RB_DEFAULT;
            RDRS_RTA_SPATIAL = IcdDefaultsRta::RDRX_RTA_SPATIAL_DEFAULT;
            RDRS_RTA_AZ_CL_DMD_RB = SI::SIDegree(RDRS_RTA_AZ_CL_DMD_RB_DEFAULT);
            RDRS_RTA_EL_CL_DMD_RB = SI::SIDegree(RDRS_RTA_EL_CL_DMD_RB_DEFAULT);
            RDRS_RTA_RATIO_DMD_ACT = RDRS_RTA_RATIO_DMD_ACT_DEFAULT;
            RDRS_RTA_PROG_ACT_VOL = RDRS_RTA_PROG_ACT_VOL_DEFAULT;
            RDRS_RTA_TIME_TO_COMP_ITER = SI::SISecond(RDRS_RTA_TIME_TO_COMP_ITER_DEFAULT);
            RDRS_RTA_FRAME_COUNT = IcdDefaults::FRAME_COUNT_DEFAULT;
          }

          /**
           * @brief setter for the Task Type
           * @param validity: the task validity to be set (valid/invalid)
           */
          void setTaskType(const Common::CommandValidity &validity) noexcept override
          {
            TASK_TYPE = (validity == Common::CommandValidity::VALID) ?
              Common::WeaponSystemTaskType::AIR_SEARCH_RAPID_TARGET_ACQUISITION : Common::WeaponSystemTaskType::INVALID_TYPE;
          }

          /**
           * @brief setter for the RDRS_RTA_ACHIEVED_PCT
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_ACHIEVED_PCT(uint8_t arg) {
            RDRS_RTA_ACHIEVED_PCT = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_RES_REP_ACTUAL
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_RES_REP_ACTUAL(float arg) {
            RDRS_RTA_RES_REP_ACTUAL = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_RES_REP_PRED_DES
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_RES_REP_PRED_DES(float arg) {
            RDRS_RTA_RES_REP_PRED_DES = arg;
          }
          
          /**
           * @brief setter for the RDRS_RTA_RES_REP_PRED_MIN
           * @param arg : the value to be set
           */          
          inline void set_RDRS_RTA_RES_REP_PRED_MIN(float arg) {
            RDRS_RTA_RES_REP_PRED_MIN = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_RES_ANT_ACTUAL
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_RES_ANT_ACTUAL(float arg) { 
            RDRS_RTA_RES_ANT_ACTUAL = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_RES_ANT_PRED_DES
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_RES_ANT_PRED_DES(float arg) {
            RDRS_RTA_RES_ANT_PRED_DES = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_RES_ANT_PRED_MIN
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_RES_ANT_PRED_MIN(float arg) {
            RDRS_RTA_RES_ANT_PRED_MIN = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_CNTR_SOURCE
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_CNTR_SOURCE(RDRX_RTA_CNTR_SOURCE_ENUM arg) {
            RDRS_RTA_CNTR_SOURCE = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_RADAR_TRK_SUSP
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_RADAR_TRK_SUSP(bool arg) {
            RDRS_RTA_RADAR_TRK_SUSP = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_SUSPEND_DISC_RB
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_SUSPEND_DISC_RB(RDRX_RTA_SUSPEND_DISC_ENUM arg) {
            RDRS_RTA_SUSPEND_DISC_RB = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_SPATIAL
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_SPATIAL(RDRX_RTA_SPATIAL_ENUM arg) {
            RDRS_RTA_SPATIAL = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_AZ_CL_DMD_RB
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_AZ_CL_DMD_RB(SI::SIDegree arg) {
            RDRS_RTA_AZ_CL_DMD_RB = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_EL_CL_DMD_RB
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_EL_CL_DMD_RB(SI::SIDegree arg) {
            RDRS_RTA_EL_CL_DMD_RB = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_RATIO_DMD_ACT
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_RATIO_DMD_ACT(uint8_t arg) {
            RDRS_RTA_RATIO_DMD_ACT = arg;
          } 

          /**
           * @brief setter for the RDRS_RTA_PROG_ACT_VOL
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_PROG_ACT_VOL(uint8_t arg) {
            RDRS_RTA_PROG_ACT_VOL = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_TIME_TO_COMP_ITER
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_TIME_TO_COMP_ITER(SI::SISecond arg) {
            RDRS_RTA_TIME_TO_COMP_ITER = arg;
          }

          /**
           * @brief setter for the RDRS_RTA_FRAME_COUNT
           * @param arg : the value to be set
           */
          inline void set_RDRS_RTA_FRAME_COUNT(uint8_t arg) {
            RDRS_RTA_FRAME_COUNT = arg;
          }

          //______________________________________//

          /**
           * @brief equality operator
           * @returns true if other contains the same values, false otherwise
           */
          bool operator==(const RapidTargetAcquisitionStatus& other) const
          {
            return
              Status::operator==(other) &&
              Common::VolumeAircraftReferenced::operator==(other) &&
              RDRS_RTA_ACHIEVED_PCT == other.RDRS_RTA_ACHIEVED_PCT &&
              SI::floatEqualityChecker::AlmostEqual(RDRS_RTA_RES_REP_ACTUAL, other.RDRS_RTA_RES_REP_ACTUAL) &&
              SI::floatEqualityChecker::AlmostEqual(RDRS_RTA_RES_REP_PRED_DES, other.RDRS_RTA_RES_REP_PRED_DES) &&
              SI::floatEqualityChecker::AlmostEqual(RDRS_RTA_RES_REP_PRED_MIN, other.RDRS_RTA_RES_REP_PRED_MIN) &&
              SI::floatEqualityChecker::AlmostEqual(RDRS_RTA_RES_ANT_ACTUAL, other.RDRS_RTA_RES_ANT_ACTUAL) &&
              SI::floatEqualityChecker::AlmostEqual(RDRS_RTA_RES_ANT_PRED_DES, other.RDRS_RTA_RES_ANT_PRED_DES) &&
              SI::floatEqualityChecker::AlmostEqual(RDRS_RTA_RES_ANT_PRED_MIN, other.RDRS_RTA_RES_ANT_PRED_MIN) &&
              RDRS_RTA_CNTR_SOURCE == other.RDRS_RTA_CNTR_SOURCE &&
              RDRS_RTA_RADAR_TRK_SUSP == other.RDRS_RTA_RADAR_TRK_SUSP &&
              RDRS_RTA_SUSPEND_DISC_RB == other.RDRS_RTA_SUSPEND_DISC_RB &&
              RDRS_RTA_SPATIAL == other.RDRS_RTA_SPATIAL &&
              RDRS_RTA_AZ_CL_DMD_RB == other.RDRS_RTA_AZ_CL_DMD_RB &&
              RDRS_RTA_EL_CL_DMD_RB == other.RDRS_RTA_EL_CL_DMD_RB &&
              RDRS_RTA_RATIO_DMD_ACT == other.RDRS_RTA_RATIO_DMD_ACT &&
              RDRS_RTA_PROG_ACT_VOL == other.RDRS_RTA_PROG_ACT_VOL &&
              RDRS_RTA_TIME_TO_COMP_ITER == other.RDRS_RTA_TIME_TO_COMP_ITER &&
              RDRS_RTA_FRAME_COUNT == other.RDRS_RTA_FRAME_COUNT;
          }

          bool operator!=(const RapidTargetAcquisitionStatus &other) const
          {
            return !(*this == other);
          }

          /**
           * @brief Serialise function required for communications
           */
          template <class T>
          void Serialise(T &archive)
          {
            // Volume params
            double doubleRDRS_RTA_AC_AZ_CNTR{RDRX_ASX_AC_AZ_CNTR()};
            double doubleRDRS_RTA_AC_EL_CNTR{RDRX_ASX_AC_EL_CNTR()};
            double doubleRDRS_RTA_AC_AZ_HALF{RDRX_ASX_AC_AZ_HALF()};
            double doubleRDRS_RTA_AC_EL_HALF{RDRX_ASX_AC_EL_HALF()};
            double doubleRDRS_RTA_AC_SLT_MIN{RDRX_ASX_AC_SLT_MIN()};
            double doubleRDRS_RTA_AC_SLT_MAX{RDRX_ASX_AC_SLT_MAX()};

            double doubleRDRS_RTA_AZ_CL_DMD_RB{RDRS_RTA_AZ_CL_DMD_RB()};
            double doubleRDRS_RTA_EL_CL_DMD_RB{RDRS_RTA_EL_CL_DMD_RB()};
            double doubleRDRS_RTA_TIME_TO_COMP_ITER{RDRS_RTA_TIME_TO_COMP_ITER()};

            archive.Serialise(TASK_IDENT, "RDRS_RTA_TASK_IDENT");
            archive.Serialise(TASK_TYPE, "RDRS_RTA_TASK_TYPE");
            archive.Serialise(COND_MOD_STATUS, "RDRS_RTA_COND_MOD_STATUS");
            archive.Serialise(COND_STATE, "RDRS_RTA_COND_STATE");
            archive.Serialise(COND_SUSP_DETAIL, "RDRS_RTA_COND_SUSP_DETAIL");
            archive.Serialise(COND_MOD_TDI, "RDRS_RTA_COND_MOD_TDI");
            archive.Serialise(COND_REJECT_DETAIL, "RDRS_RTA_COND_REJECT_DETAIL");
            archive.Serialise(RDRS_RTA_ACHIEVED_PCT, "RDRS_RTA_ACHIEVED_PCT");
            archive.Serialise(RDRS_RTA_RES_REP_ACTUAL, "RDRS_RTA_RES_REP_ACTUAL");
            archive.Serialise(RDRS_RTA_RES_REP_PRED_DES, "RDRS_RTA_RES_REP_PRED_DES");
            archive.Serialise(RDRS_RTA_RES_REP_PRED_MIN, "RDRS_RTA_RES_REP_PRED_MIN");
            archive.Serialise(RDRS_RTA_RES_ANT_ACTUAL, "RDRS_RTA_RES_ANT_ACTUAL");
            archive.Serialise(RDRS_RTA_RES_ANT_PRED_DES, "RDRS_RTA_RES_ANT_PRED_DES");
            archive.Serialise(RDRS_RTA_RES_ANT_PRED_MIN, "RDRS_RTA_RES_ANT_PRED_MIN");
            archive.Serialise(RDRS_RTA_CNTR_SOURCE, "RDRS_RTA_CNTR_SOURCE");
            archive.Serialise(RDRS_RTA_RADAR_TRK_SUSP, "RDRS_RTA_RADAR_TRK_SUSP");
            archive.Serialise(RDRS_RTA_SUSPEND_DISC_RB, "RDRS_RTA_SUSPEND_DISC_RB");
            archive.Serialise(RDRS_RTA_SPATIAL, "RDRS_RTA_SPATIAL");
            
            // Volume params
            archive.Serialise(RDRX_ASX_AC_STABTYPE, "RDRS_RTA_AC_STABTYPE");
            archive.Serialise(doubleRDRS_RTA_AC_AZ_CNTR, "RDRS_RTA_AC_AZ_CNTR");
            archive.Serialise(doubleRDRS_RTA_AC_EL_CNTR, "RDRS_RTA_AC_EL_CNTR");
            archive.Serialise(doubleRDRS_RTA_AC_AZ_HALF, "RDRS_RTA_AC_AZ_HALF");
            archive.Serialise(doubleRDRS_RTA_AC_EL_HALF, "RDRS_RTA_AC_EL_HALF");
            archive.Serialise(doubleRDRS_RTA_AC_SLT_MIN, "RDRS_RTA_AC_SLT_MIN");
            archive.Serialise(doubleRDRS_RTA_AC_SLT_MAX, "RDRS_RTA_AC_SLT_MAX");
            
            archive.Serialise(doubleRDRS_RTA_AZ_CL_DMD_RB, "RDRS_RTA_AZ_CL_DMD_RB");
            archive.Serialise(doubleRDRS_RTA_EL_CL_DMD_RB, "RDRS_RTA_EL_CL_DMD_RB");
            archive.Serialise(RDRS_RTA_RATIO_DMD_ACT, "RDRS_RTA_RATIO_DMD_ACT");
            archive.Serialise(RDRS_RTA_PROG_ACT_VOL, "RDRS_RTA_PROG_ACT_VOL");
            archive.Serialise(doubleRDRS_RTA_TIME_TO_COMP_ITER, "RDRS_RTA_TIME_TO_COMP_ITER");
            archive.Serialise(RDRS_RTA_FRAME_COUNT, "RDRS_RTA_FRAME_COUNT");
            archive.Serialise(ACTUAL_TDI, "RDRS_RTA_ACTUAL_TDI");

            RDRX_ASX_AC_AZ_CNTR = doubleRDRS_RTA_AC_AZ_CNTR;
            RDRX_ASX_AC_EL_CNTR = doubleRDRS_RTA_AC_EL_CNTR;
            RDRX_ASX_AC_AZ_HALF = doubleRDRS_RTA_AC_AZ_HALF;
            RDRX_ASX_AC_EL_HALF = doubleRDRS_RTA_AC_EL_HALF;
            RDRX_ASX_AC_SLT_MIN = doubleRDRS_RTA_AC_SLT_MIN;
            RDRX_ASX_AC_SLT_MAX = doubleRDRS_RTA_AC_SLT_MAX;

            RDRS_RTA_AZ_CL_DMD_RB = doubleRDRS_RTA_AZ_CL_DMD_RB;
            RDRS_RTA_EL_CL_DMD_RB = doubleRDRS_RTA_EL_CL_DMD_RB;
            RDRS_RTA_TIME_TO_COMP_ITER = doubleRDRS_RTA_TIME_TO_COMP_ITER;
          }
          LCA_TOPIC("RapidTargetAcquisitionStatus", 1, 0)
        };
      } // namespace RapidTargetAcquisition
    }   // namespace WeaponSystem
  }     // namespace EcrsMK2
}       // namespace Topics

#endif