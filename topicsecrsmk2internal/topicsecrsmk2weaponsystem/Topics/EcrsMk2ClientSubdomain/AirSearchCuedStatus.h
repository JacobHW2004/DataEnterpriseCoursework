#ifndef AIR_SEARCH_CUED_STATUS_H
#define AIR_SEARCH_CUED_STATUS_H

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

        class AirSearchCuedStatus : public Common::Status
        {
        protected:

          /**
           * @brief The actual quality achieved by the Search Task and represents the proportion of the search rate being achieved
           */
          uint8_t RDRS_ASC_ACHIEVED_PCT{IcdDefaultsAs::ACHIEVED_PCT_DEFAULT}; // Percentage

          /**
           * @brief The actual proportion of the total available Nose Radar resource specific to the Repositioner
           */
          float RDRS_ASC_RES_REP_ACTUAL{IcdDefaultsAs::RES_REP_ACTUAL_DEFAULT}; // Percentage

          /**
           * @brief The predicted amount of Nose Radar resource required to perform the search task to the desired quality specific to the Repositioner
           */
          float RDRS_ASC_RES_REP_PRED_DES{IcdDefaultsAs::RES_REP_PRED_DES_DEFAULT}; // Percentage

          /**
           * @brief The predicted amount of Nose Radar resource required to perform the search task to the minimum quality specific to the Repositioner
           */
          float RDRS_ASC_RES_REP_PRED_MIN{IcdDefaultsAs::RES_REP_PRED_MIN_DEFAULT}; // Percentage

          /**
           * @brief  the actual proportion of the total available Nose Radar resource specific to the Antenna and RF
           */
          float RDRS_ASC_RES_ANT_ACTUAL{IcdDefaultsAs::RES_ANT_ACTUAL_DEFAULT}; // Percentage

          /**
           * @brief The predicted amount of Nose Radar resource specific to the Antenna and RF
           */
          float RDRS_ASC_RES_ANT_PRED_DES{IcdDefaultsAs::RES_ANT_PRED_DES_DEFAULT}; // Percentage

          /**
           * @brief The actual proportion of the total available Nose Radar resource specific to the Antenna and RF
           */
          float RDRS_ASC_RES_ANT_PRED_MIN{IcdDefaultsAs::RES_ANT_PRED_MIN_DEFAULT}; // Percentage

          /**
           * @brief The status ringback for the transmit discrimination
           */
          Common::TXDISC_ENUM RDRS_ASC_TXDISC{IcdDefaults::TXDISC_DEFAULT};

          /**
           * @brief Represents the actual Dimension Type
           */
          SPATIAL_ENUM RDRS_ASC_SPATIAL{IcdDefaultsAs::SPATIAL_DEFAULT};

          /**
           * @brief Represents the actual volume coverage as a percentage where 100% represents the demanded volume
           */
          uint8_t RDRS_ASC_RATIO_DMD_ACT{IcdDefaultsAs::RATIO_DMD_ACT_DEFAULT}; // Percentage

          /**
           * @brief Represents the current progress through the actual search volume
           */
          uint8_t RDRS_ASC_PROG_ACT_VOL{IcdDefaultsAs::PROG_ACT_VOL_DEFAULT}; // Percentage

          /**
           * @brief Indicates the predicted time to complete the current iteration of the search volume
           */
          SI::SISecond RDRS_ASC_TIME_TO_COMP_ITER{IcdDefaultsAs::TIME_TO_COMP_ITER_DEFAULT};

          /**
           * @brief Wraparound counter for the number of frames (volumes/areas) that the Nose Radar has completed
           */
          uint8_t RDRS_ASC_FRAME_COUNT{IcdDefaults::FRAME_COUNT_DEFAULT};

          /**
           * @brief the status ringback for the Air Search Subject target Size in order to optimise detection of targets
           */
          SI::SIMeterSquared RDRS_ASC_ASS_RCS{IcdDefaultsAs::ASS_RCS_DEFAULT};

          /**
           * @brief The status ringback for the Air Search Subject Track Type set to optimise detection of targets
           */
          ASS_TYPE_ENUM RDRS_ASC_ASS_TYPE{IcdDefaultsAs::ASS_TYPE_DEFAULT};

          /**
           * @brief The status ringback for the Air Search Subject Track Velocity set to optimise detection of targets
           */
          NSI::NSIKnot RDRS_ASC_ASS_VEL{IcdDefaultsAs::ASS_VEL_DEFAULT};

          /**
           * @brief The status ringback for the Air Search Subject, specifically for Track Hemisphere
           */
          ASS_HEMIS_ENUM RDRS_ASC_ASS_HEMIS{IcdDefaultsAs::ASS_HEMIS_DEFAULT};

        public:
          /**
           * @brief Default Constructor
           */
          AirSearchCuedStatus() : Common::Status{}
          {
          }


          /**
           * @brief getter for the Task Quality Achieved
           * @returns the Task Quality Achieved
           */
          const uint8_t getTaskQualityAchieved() const
          {
            return RDRS_ASC_ACHIEVED_PCT; // Percentage
          }

          /**
           * @brief getter for the Actual Repositioner Resource
           * @returns the Actual Repositioner Resource
           */
          const float getActualRepositionerResource() const
          {
            return RDRS_ASC_RES_REP_ACTUAL; // Percentage
          }

          /**
           * @brief getter for the Predicted Repositioner Resource Desired
           * @returns the Predicted Repositioner Resource Desired
           */
          const float getPredictedRepositionerResourceDesired() const
          {
            return RDRS_ASC_RES_REP_PRED_DES; // Percentage
          }

          /**
           * @brief getter for the Predicted Repositioner Resource Minimum
           * @returns the Predicted Repositioner Resource Minimum
           */
          const float getPredictedRepositionerResourceMinimum() const
          {
            return RDRS_ASC_RES_REP_PRED_MIN; // Percentage
          }

          /**
           * @brief getter for the Actual Antenna Resource
           * @returns the Actual Antenna Resource
           */
          const float getActualAntennaResource() const
          {
            return RDRS_ASC_RES_ANT_ACTUAL; // Percentage
          }

          /**
           * @brief getter for the Predicted Antenna Resource Desired
           * @returns the Predicted Antenna Resource Desired
           */
          const float getPredictedAntennaResourceDesired() const
          {
            return RDRS_ASC_RES_ANT_PRED_DES; // Percentage
          }

          /**
           * @brief getter for the Predicted Antenna Resource Minimum
           * @returns the Predicted Antenna Resource Minimum
           */
          const float getPredictedAntennaResourceMinimum() const
          {
            return RDRS_ASC_RES_ANT_PRED_MIN; // Percentage
          }

          /**
           * @brief getter for the Transmit Discrimination
           * @returns the Transmit Discrimination
           */
          const Common::TXDISC_ENUM getTransmitDiscrimination() const
          {
            return RDRS_ASC_TXDISC;
          }

          /**
           * @brief getter for the Spacial Dimension Type
           * @returns the Spacial Dimension Type
           */
          const SPATIAL_ENUM getSpacialDimension() const
          {
            return RDRS_ASC_SPATIAL;
          }

          /**
           * @brief getter for the Actual Volume Coverage
           * @returns the Actual Volume Coverage
           */
          const uint8_t getActualVolumeCoverage() const
          {
            return RDRS_ASC_RATIO_DMD_ACT; // Percentage
          }

          /**
           * @brief getter for the Actual Progress through Volume Search
           * @returns the Actual Progress through Volume Search
           */
          const uint8_t getActualProgressThroughVolumeSearch() const
          {
            return RDRS_ASC_PROG_ACT_VOL; // Percentage
          }

          /**
           * @brief getter for the Predicted Time to complete Volume Search
           * @returns the Predicted Time to complete Volume Search
           */
          const SI::SISecond getPredictedTimeToCompleteVolumeSearch() const
          {
            return RDRS_ASC_TIME_TO_COMP_ITER;
          }

          /**
           * @brief getter for the Frame Count
           * @returns the Frame Count
           */
          const uint8_t getFrameCount() const
          {
            return RDRS_ASC_FRAME_COUNT;
          }

          /**
           * @brief getter for the Air Search Subject Target Size
           * @returns the Air Search Subject Target Size
           */
          const SI::SIMeterSquared getTargetSize() const
          {
            return RDRS_ASC_ASS_RCS;
          }

          /**
           * @brief getter for the Air Search Subject Target Type
           * @returns the Air Search Subject Target Type
           */
          const ASS_TYPE_ENUM getTargetType() const
          {
            return RDRS_ASC_ASS_TYPE;
          }

          /**
           * @brief getter for the Air Search Subject Target Velocity
           * @returns the Air Search Subject Target Velocity
           */
          const NSI::NSIKnot getTargetVelocity() const
          {
            return RDRS_ASC_ASS_VEL;
          }

          /**
           * @brief getter for the Air Search Subject Target Hemisphere
           * @returns the Air Search Subject Target Hemisphere
           */
          const ASS_HEMIS_ENUM getTargetHemisphere() const
          {
            return RDRS_ASC_ASS_HEMIS;
          }

           /**
           * @brief setter for the Task Type
           * @param validity: the task validity to be set (valid/invalid)
           */
          void setTaskType(const Common::CommandValidity &validity) noexcept override
          {
            TASK_TYPE = (validity == Common::CommandValidity::VALID) ?
              Common::WeaponSystemTaskType::AIR_SEARCH_CUED : Common::WeaponSystemTaskType::INVALID_TYPE;
          }

          /**
           * @brief setter for the Task Quality Achieved
           * @param taskQualityAchieved : the Task Quality Achieved to be set
           */
          const void setTaskQualityAchieved(const uint8_t &taskQualityAchieved)
          {
            RDRS_ASC_ACHIEVED_PCT = taskQualityAchieved; // Percentage
          }

          /**
           * @brief setter for the Actual Repositioner Resource
           * @param actualRepositionerResource : the Actual Repositioner Resource to be set
           */
          const void setActualRepositionerResource(const float &actualRepositionerResource)
          {
            RDRS_ASC_RES_REP_ACTUAL = actualRepositionerResource; // Percentage
          }

          /**
           * @brief setter for the Predicted Repositioner Resource Desired
           * @param predictedRepositionerResourceDesired : the Predicted Repositioner Resource Desired to be set
           */
          const void setPredictedRepositionerResourceDesired(const float &predictedRepositionerResourceDesired)
          {
            RDRS_ASC_RES_REP_PRED_DES = predictedRepositionerResourceDesired; // Percentage
          }

          /**
           * @brief setter for the Predicted Repositioner Resource Minimum
           * @param predictedRepositionerResourceMinimum : the Predicted Repositioner Resource Minimum to be set
           */
          const void setPredictedRepositionerResourceMinimum(const float &predictedRepositionerResourceMinimum)
          {
            RDRS_ASC_RES_REP_PRED_MIN = predictedRepositionerResourceMinimum; // Percentage
          }

          /**
           * @brief setter for the Actual Antenna Resource
           * @param actualAntennaResource : the Actual Antenna Resource to be set
           */
          const void setActualAntennaResource(const float &actualAntennaResource)
          {
            RDRS_ASC_RES_ANT_ACTUAL = actualAntennaResource; // Percentage
          }

          /**
           * @brief setter for the Predicted Antenna Resource Desired
           * @param predictedAntennaResourceDesired : the Predicted Antenna Resource Desired to be set
           */
          const void setPredictedAntennaResourceDesired(const float &predictedAntennaResourceDesired)
          {
            RDRS_ASC_RES_ANT_PRED_DES = predictedAntennaResourceDesired; // Percentage
          }

          /**
           * @brief setter for the Predicted Antenna Resource Minimum
           * @param predictedAntennaResourceMinimum : the Predicted Antenna Resource Minimum to be set
           */
          const void setPredictedAntennaResourceMinimum(const float &predictedAntennaResourceMinimum)
          {
            RDRS_ASC_RES_ANT_PRED_MIN = predictedAntennaResourceMinimum; // Percentage
          }

          /**
           * @brief setter for the Transmit Discrimination
           * @param transmitDiscrimination : the Transmit Discrimination to be set
           */
          const void setTransmitDiscrimination(const Common::TXDISC_ENUM &transmitDiscrimination)
          {
            RDRS_ASC_TXDISC = transmitDiscrimination;
          }

          /**
           * @brief setter for the Spacial Dimension
           * @param spacialDimension : the Spacial Dimension to be set
           */
          const void setSpacialDimension(const SPATIAL_ENUM &spacialDimension)
          {
            RDRS_ASC_SPATIAL = spacialDimension;
          }

          /**
           * @brief setter for the Actual Volume Coverage
           * @param actualVolumeCoverage : the Actual Volume Coverage to be set
           */
          const void setActualVolumeCoverage(const uint8_t &actualVolumeCoverage)
          {
            RDRS_ASC_RATIO_DMD_ACT = actualVolumeCoverage; // Percentage
          }

          /**
           * @brief setter for the Actual Progress through Volume Search
           * @param actualProgessVolumeSearch : the Actual Progress through Volume Search to be set
           */
          const void setActualProgressThroughVolumeSearch(const uint8_t &actualProgessVolumeSearch)
          {
            RDRS_ASC_PROG_ACT_VOL = actualProgessVolumeSearch; // Percentage
          }

          /**
           * @brief setter for the Predicted Time to complete Volume Search
           * @param predictedTimeVolumeSearch : the Predicted Time to complete Volume Search to be set
           */
          const void setPredictedTimeToCompleteVolumeSearch(const SI::SISecond &predictedTimeVolumeSearch)
          {
            RDRS_ASC_TIME_TO_COMP_ITER = predictedTimeVolumeSearch;
          }

          /**
           * @brief setter for the Frame Count
           * @param frameCount : the Frame Count to be set
           */
          const void setFrameCount(const uint8_t &frameCount)
          {
            RDRS_ASC_FRAME_COUNT = frameCount;
          }

          /**
           * @brief setter for the Air Search Subject Target Size
           * @param targetSize : the Air Search Subject Target Size to be set
           */
          const void setTargetSize(const SI::SIMeterSquared &targetSize)
          {
            RDRS_ASC_ASS_RCS = targetSize;
          }

          /**
           * @brief setter for the Air Search Subject Target Type
           * @param targetType : the Air Search Subject Target Type to be set
           */
          const void setTargetType(const ASS_TYPE_ENUM &targetType)
          {
            RDRS_ASC_ASS_TYPE = targetType;
          }

          /**
           * @brief setter for the Air Search Subject Target Velocity
           * @param targetVelocity : the Air Search Subject Target Velocity to be set
           */
          const void setTargetVelocity(const NSI::NSIKnot &targetVelocity)
          {
            RDRS_ASC_ASS_VEL = targetVelocity;
          }

          /**
           * @brief setter for the Air Search Subject Target Hemisphere
           * @param targetHemisphere : the Air Search Subject Target Hemisphere to be set
           */
          const void setTargetHemisphere(const ASS_HEMIS_ENUM &targetHemisphere)
          {
            RDRS_ASC_ASS_HEMIS = targetHemisphere;
          }

          virtual void setToIcdDefault() noexcept override
          {
            Status::setToIcdDefault();
            RDRS_ASC_ACHIEVED_PCT = IcdDefaultsAs::ACHIEVED_PCT_DEFAULT;
            RDRS_ASC_RES_REP_ACTUAL = IcdDefaultsAs::RES_REP_ACTUAL_DEFAULT;
            RDRS_ASC_RES_REP_PRED_DES = IcdDefaultsAs::RES_REP_PRED_DES_DEFAULT;
            RDRS_ASC_RES_REP_PRED_MIN = IcdDefaultsAs::RES_REP_PRED_MIN_DEFAULT;
            RDRS_ASC_RES_ANT_ACTUAL = IcdDefaultsAs::RES_ANT_ACTUAL_DEFAULT;
            RDRS_ASC_RES_ANT_PRED_DES = IcdDefaultsAs::RES_ANT_PRED_DES_DEFAULT;
            RDRS_ASC_RES_ANT_PRED_MIN = IcdDefaultsAs::RES_ANT_PRED_MIN_DEFAULT;
            RDRS_ASC_TXDISC = IcdDefaults::TXDISC_DEFAULT;
            RDRS_ASC_SPATIAL = IcdDefaultsAs::SPATIAL_DEFAULT;
            RDRS_ASC_RATIO_DMD_ACT = IcdDefaultsAs::RATIO_DMD_ACT_DEFAULT;
            RDRS_ASC_PROG_ACT_VOL = IcdDefaultsAs::PROG_ACT_VOL_DEFAULT;
            RDRS_ASC_TIME_TO_COMP_ITER = IcdDefaultsAs::TIME_TO_COMP_ITER_DEFAULT;
            RDRS_ASC_FRAME_COUNT = IcdDefaults::FRAME_COUNT_DEFAULT;
            RDRS_ASC_ASS_RCS = IcdDefaultsAs::ASS_RCS_DEFAULT;
            RDRS_ASC_ASS_TYPE = IcdDefaultsAs::ASS_TYPE_DEFAULT;
            RDRS_ASC_ASS_VEL = IcdDefaultsAs::ASS_VEL_DEFAULT;
            RDRS_ASC_ASS_HEMIS = IcdDefaultsAs::ASS_HEMIS_DEFAULT;
          }

        protected:
          /**
           * @brief equality operator
           * @returns true if other contains the same values, false otherwise
           */
          bool operator==(const AirSearchCuedStatus& other) const
          {
            return Status::operator==(other) &&
                   RDRS_ASC_ACHIEVED_PCT == other.RDRS_ASC_ACHIEVED_PCT &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASC_RES_REP_ACTUAL, other.RDRS_ASC_RES_REP_ACTUAL) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASC_RES_REP_PRED_DES, other.RDRS_ASC_RES_REP_PRED_DES) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASC_RES_REP_PRED_MIN, other.RDRS_ASC_RES_REP_PRED_MIN) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASC_RES_ANT_ACTUAL, other.RDRS_ASC_RES_ANT_ACTUAL) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASC_RES_ANT_PRED_DES, other.RDRS_ASC_RES_ANT_PRED_DES) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ASC_RES_ANT_PRED_MIN, other.RDRS_ASC_RES_ANT_PRED_MIN) &&
                   RDRS_ASC_TXDISC == other.RDRS_ASC_TXDISC &&
                   RDRS_ASC_SPATIAL == other.RDRS_ASC_SPATIAL &&
                   RDRS_ASC_RATIO_DMD_ACT == other.RDRS_ASC_RATIO_DMD_ACT &&
                   RDRS_ASC_PROG_ACT_VOL == other.RDRS_ASC_PROG_ACT_VOL &&
                   RDRS_ASC_TIME_TO_COMP_ITER == other.RDRS_ASC_TIME_TO_COMP_ITER &&
                   RDRS_ASC_FRAME_COUNT == other.RDRS_ASC_FRAME_COUNT &&
                   RDRS_ASC_ASS_RCS == other.RDRS_ASC_ASS_RCS &&
                   RDRS_ASC_ASS_TYPE == other.RDRS_ASC_ASS_TYPE &&
                   RDRS_ASC_ASS_VEL == other.RDRS_ASC_ASS_VEL &&
                   RDRS_ASC_ASS_HEMIS == other.RDRS_ASC_ASS_HEMIS;
          }
        };
      } // namespace AirSearch
    }   // namespace WeaponSystem
  }     // namespace EcrsMK2
} // namespace Topics

#endif