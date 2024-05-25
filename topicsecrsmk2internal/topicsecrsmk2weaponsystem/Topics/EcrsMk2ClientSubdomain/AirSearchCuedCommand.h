#ifndef AIR_SEARCH_CUED_COMMAND_H
#define AIR_SEARCH_CUED_COMMAND_H

#include <memory>
#include <string>

#include "Command.h"
#include "CommonAirSearchValues.h"
#include "CommonWeaponSystemValues.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
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

        /**
         * @brief enumeration for enabling ktv override
         */
        enum class RDRC_ASC_ENABLE_KTV_OVERRIDE_ENUM : uint8_t
        {
          OVERRIDE_TV = 0x00,
          NOT_OVERRIDE_TV = 0x01
        };

        class AirSearchCuedCommand : public Common::Command
        {
        protected:

          // Default values are defined within the ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
          /**
           * @brief Default Message Values
           */
          static constexpr RDRC_ASC_ENABLE_KTV_OVERRIDE_ENUM RDRC_ASC_ENABLE_KTV_OVERRIDE_DEFAULT{RDRC_ASC_ENABLE_KTV_OVERRIDE_ENUM::OVERRIDE_TV};
          //______________________________________________//

          /**
           * @brief Minimum Quality and represents the proportion of the search rate to be achieved by the Nose Radar
           */
          uint8_t RDRC_ASC_TV_MIN_PCT{IcdDefaultsAs::TV_MIN_PCT_DEFAULT};

          /**
           * @brief Desired Quality and represents the proportion of the search rate to be achieved by the Nose Radar
           */
          uint8_t RDRC_ASC_TV_DES_PCT{IcdDefaultsAs::TV_DES_PCT_DEFAULT};

          /**
           * @brief The command for the Air Search Subject PAT T
           */
          Search::PAT_T_ENUM RDRC_ASC_PAT_T{IcdDefaultsAs::PAT_T_DEFAULT};

          /**
           * @brief The command for the Air Search Subject PAT FS
           */
          PAT_FS_ENUM RDRC_ASC_PAT_FS{IcdDefaultsAs::PAT_FS_DEFAULT};

          /**
           * @brief The command for the Air Search Subject PAT D
           */
          Search::PAT_D_ENUM RDRC_ASC_PAT_D{IcdDefaultsAs::PAT_D_DEFAULT};

          /**
           * @brief The command for the Air Search Subject PAT I
           */
          Search::PAT_I_ENUM RDRC_ASC_PAT_I{IcdDefaultsAs::PAT_I_DEFAULT};

          /**
           * @brief Command for the Transmit Discrimination
           */
          Common::TXDISC_ENUM RDRC_ASC_TXDISC{IcdDefaults::TXDISC_DEFAULT};

          /**
           * @brief Command for overriding kinematic TV of existing tracks
           */
          RDRC_ASC_ENABLE_KTV_OVERRIDE_ENUM RDRC_ASC_ENABLE_KTV_OVERRIDE{RDRC_ASC_ENABLE_KTV_OVERRIDE_DEFAULT};

          /**
           * @brief Represents the demanded Dimension Type and indicates which position reference is to be used for the associated Search
           */
          SPATIAL_ENUM RDRC_ASC_SPATIAL{IcdDefaultsAs::SPATIAL_DEFAULT};

          /**
           * @brief Represents the relative priority of the associated Task amongst all WS commanded Tasks
           */
          uint16_t RDRC_ASC_IKTV_PRIORITY{IcdDefaults::IKTV_PRIORITY_DEFAULT};

          /**
           * @brief The Initial Minimum Positional Quality to be applied by the Radar to Confirmed Tracks
           */
          SI::SIMeter RDRC_ASC_IKTV_MIN_POS_X{IcdDefaults::IKTV_MIN_POS_X_DEFAULT};

          /**
           * @brief The Initial Minimum Positional Quality to be applied by the Radar to Confirmed Tracks
           */
          SI::SIMeter RDRC_ASC_IKTV_MIN_POS_Z{IcdDefaults::IKTV_MIN_POS_Z_DEFAULT};

          /**
           * @brief Set to RAPID and the demanded Minimum Track Quality is higher than the current Track Quality
           */
          Common::IKTV_RAP_ATT_ENUM RDRC_ASC_IKTV_MIN_RAP_ATT{IcdDefaults::IKTV_MIN_RAP_ATT_DEFAULT};

          /**
           * @brief The Initial Minimum Velocity Quality to be applied by the Radar to Confirmed Tracks
           */
          SI::SIMeterPerSecond RDRC_ASC_IKTV_MIN_VEL_X{IcdDefaults::IKTV_MIN_VEL_X_DEFAULT};

          /**
           * @brief The Initial Minimum Velocity Quality to be applied by the Radar to Confirmed Tracks
           */
          SI::SIMeterPerSecond RDRC_ASC_IKTV_MIN_VEL_Z{IcdDefaults::IKTV_MIN_VEL_Z_DEFAULT};

          /**
           * @brief The Initial Desired Positional Quality to be applied by the Radar to Confirmed Tracks
           */
          SI::SIMeter RDRC_ASC_IKTV_DES_POS_X{IcdDefaults::IKTV_DES_POS_X_DEFAULT};

          /**
           * @brief The Initial Desired Positional Quality to be applied by the Radar to Confirmed Tracks
           */
          SI::SIMeter RDRC_ASC_IKTV_DES_POS_Z{IcdDefaults::IKTV_DES_POS_Z_DEFAULT};

          /**
           * @brief Provides adaptive track revisits as necessary to rapidly converge to the demanded Desired Track Quality in as short a time as possible
           */
          Common::IKTV_RAP_ATT_ENUM RDRC_ASC_IKTV_DES_RAP_ATT{IcdDefaults::IKTV_DES_RAP_ATT_DEFAULT};

          /**
           * @brief Selects the Initial Desired Velocity Quality to be applied by the Radar to Confirmed Tracks
           */
          SI::SIMeterPerSecond RDRC_ASC_IKTV_DES_VEL_X{IcdDefaults::IKTV_DES_VEL_X_DEFAULT};

          /**
           * @brief Selects the Initial Desired Velocity Quality to be applied by the Radar to Confirmed Tracks
           */
          SI::SIMeterPerSecond RDRC_ASC_IKTV_DES_VEL_Z{IcdDefaults::IKTV_DES_VEL_Z_DEFAULT};

          /**
           * @brief Part of the Initial Track Task Value and represents a proactive behaviour by the Nose Radar to attempt to prevent the loss of a Track even though it may be attempting to evade
           */
          bool RDRC_ASC_IKTV_PROACT{IcdDefaults::IKTV_PROACT_DEFAULT};

          /**
           * @brief The command for the Air Search Subject target Size in order to optimise detection of targets
           */
          SI::SIMeterSquared RDRC_ASC_ASS_RCS{IcdDefaultsAs::ASS_RCS_DEFAULT};

          /**
           * @brief The command for the Air Search Subject Track Type set to optimise detection of targets
           */
          ASS_TYPE_ENUM RDRC_ASC_ASS_TYPE{IcdDefaultsAs::ASS_TYPE_DEFAULT};

          /**
           * @brief The command for the Air Search Subject Track Velocity set to optimise detection of targets
           */
          NSI::NSIKnot RDRC_ASC_ASS_VEL{IcdDefaultsAs::ASS_VEL_DEFAULT};

          /**
           * @brief The command for the Air Search Subject, specifically for Track Hemisphere
           */
          ASS_HEMIS_ENUM RDRC_ASC_ASS_HEMIS{IcdDefaultsAs::ASS_HEMIS_DEFAULT};

          /**
           * @brief The command for the Air Search Subject, specifically for Enhanced control
           */
          ENHD_CTRL_ENUM RDRC_ASC_ENHD_CTRL{IcdDefaultsAs::RDRC_ASC_ENHD_CTRL_DEFAULT};

          /**
           * @brief The command for the Air Search Subject reserve 1
           */
          float RDRC_ASC_REQD_RES1{IcdDefaultsAs::REQD_RES1_DEFAULT};

          /**
           * @brief The command for the Air Search Subject reserve 2
           */
          float RDRC_ASC_REQD_RES2{IcdDefaultsAs::REQD_RES2_DEFAULT};

        public:

          /**
           * @brief Default Constructor
           */
          AirSearchCuedCommand() : Common::Command{}
          {
          }


          /**
           * @brief getter for the Task Type
           * @returns the Task Type
           */
          Common::WeaponSystemTaskType
          getTaskType() const noexcept override
          {
            return Common::WeaponSystemTaskType::AIR_SEARCH_CUED;
          }

          /**
           * @brief getter for the Minimum Achieved Quality
           * @returns the Task Minimum Achieved Quality
           */
          const uint8_t getMinimumQuality() const
          {
            return RDRC_ASC_TV_MIN_PCT;
          }

          /**
           * @brief getter for the Desired Quality
           * @returns the Task Desired Quality
           */
          const uint8_t getDesiredQuality() const
          {
            return RDRC_ASC_TV_DES_PCT;
          }

          /**
           * @brief getter for Pat T
           * @returns the Task Pat T
           */
          const Search::PAT_T_ENUM getPatT() const
          {
            return RDRC_ASC_PAT_T;
          }

          /**
           * @brief getter for Pat Fs
           * @returns the Task Pat Fs
           */
          const PAT_FS_ENUM getPatFs() const
          {
            return RDRC_ASC_PAT_FS;
          }

          /**
           * @brief getter for Pat D
           * @returns the Task Pat D
           */
          const Search::PAT_D_ENUM getPatD() const
          {
            return RDRC_ASC_PAT_D;
          }

          /**
           * @brief getter for the Pat I
           * @returns the Task Pat I
           */
          const Search::PAT_I_ENUM getPatI() const
          {
            return RDRC_ASC_PAT_I;
          }

          /**
           * @brief getter for the Transmit Descrimination
           * @returns the Transmit Descrimination
           */
          const Common::TXDISC_ENUM getTransmitDiscrimination() const
          {
            return RDRC_ASC_TXDISC;
          }

          /**
           * @brief getter for the ktv override enabler
           * @returns the override toggle
           */
          const RDRC_ASC_ENABLE_KTV_OVERRIDE_ENUM getEnableKtvOverride() const
          {
            return RDRC_ASC_ENABLE_KTV_OVERRIDE;
          }

          /**
           * @brief getter for the Relative Priority
           * @returns the Relative Priority
           */
          const uint16_t getRelativePriority() const
          {
            return RDRC_ASC_IKTV_PRIORITY;
          }

          /**
           * @brief getter for the Demension Type
           * @returns the Demension Type
           */
          const SPATIAL_ENUM getSpatialValue() const
          {
            return RDRC_ASC_SPATIAL;
          }

          /**
           * @brief getter for the Initial Minimum Positional Quality
           * @returns the Initial Minimum Positional Quality
           */
          const SI::SIMeter getInitialMinPositionalQualityX() const
          {
            return RDRC_ASC_IKTV_MIN_POS_X;
          }

          /**
           * @brief getter for the Initial Minimum Positional Quality
           * @returns the Initial Minimum Positional Quality
           */
          const SI::SIMeter getInitialMinPositionalQualityZ() const
          {
            return RDRC_ASC_IKTV_MIN_POS_Z;
          }

          /**
           * @brief getter for the Rapid Minimum Track Quality
           * @returns the Rapid Minimum Track Quality
           */
          const Common::IKTV_RAP_ATT_ENUM getRapidMinTrackQuality() const
          {
            return RDRC_ASC_IKTV_MIN_RAP_ATT;
          }

          /**
           * @brief getter for the Initial Minimum Velocity Quality
           * @returns the Initial Minimum Velocity Quality
           */
          const SI::SIMeterPerSecond getInitialMinVelocityQualityX() const
          {
            return RDRC_ASC_IKTV_MIN_VEL_X;
          }

          /**
           * @brief getter for the Initial Minimum Velocity Quality
           * @returns the Initial Minimum Velocity Quality
           */
          const SI::SIMeterPerSecond getInitialMinVelocityQualityZ() const
          {
            return RDRC_ASC_IKTV_MIN_VEL_Z;
          }

          /**
           * @brief getter for the Initial Desired Positional Quality
           * @returns the Initial Desired Positional Quality
           */
          const SI::SIMeter getInitialDesiredPositionQualityX() const
          {
            return RDRC_ASC_IKTV_DES_POS_X;
          }

          /**
           * @brief getter for the Initial Desired Positional Quality
           * @returns the Initial Desired Positional Quality
           */
          const SI::SIMeter getInitialDesiredPositionQualityZ() const
          {
            return RDRC_ASC_IKTV_DES_POS_Z;
          }

          /**
           * @brief getter for the Desired Rapid Track Quality
           * @returns the Desired Rapid Track Quality
           */
          const Common::IKTV_RAP_ATT_ENUM getRapidDesiredTrackQuality() const
          {
            return RDRC_ASC_IKTV_DES_RAP_ATT;
          }

          /**
           * @brief getter for the Initial Desired Velocity Quality
           * @returns the Initial Desired Velocity Quality
           */
          const SI::SIMeterPerSecond getInitialDesiredVelocityQualityX() const
          {
            return RDRC_ASC_IKTV_DES_VEL_X;
          }

          /**
           * @brief getter for the Initial Desired Velocity Quality
           * @returns the Initial Desired Velocity Quality
           */
          const SI::SIMeterPerSecond getInitialDesiredVelocityQualityZ() const
          {
            return RDRC_ASC_IKTV_DES_VEL_Z;
          }

          /**
           * @brief getter for the Initial Track Value
           * @returns the Initial Track Value
           */
          const bool getInitialTrackValue() const
          {
            return RDRC_ASC_IKTV_PROACT;
          }

          /**
           * @brief getter for the Air Search Subject Target Size
           * @returns the Air Search Subject Target Size
           */
          const SI::SIMeterSquared getASSTargetSize() const
          {
            return RDRC_ASC_ASS_RCS;
          }

          /**
           * @brief getter for the Air Search Subject Track Type
           * @returns the Air Search Subject Track Type
           */
          const ASS_TYPE_ENUM getASSTrackType() const
          {
            return RDRC_ASC_ASS_TYPE;
          }

          /**
           * @brief getter for the Air Search Subject Velocity
           * @returns the Air Search Subject Velocity
           */
          const NSI::NSIKnot getASSTrackVelocity() const
          {
            return RDRC_ASC_ASS_VEL;
          }

          /**
           * @brief getter for the Air Search Subject Hemisphere
           * @returns the Air Search Subject Hemisphere
           */
          const ASS_HEMIS_ENUM getASSTrackHemisphere() const
          {
            return RDRC_ASC_ASS_HEMIS;
          }

          /**
           * @brief getter for the Enhd Control
           * @returns the Enhd Control
           */
          const ENHD_CTRL_ENUM getEnhdCtrl() const
          {
            return RDRC_ASC_ENHD_CTRL;
          }
          /**
           * @brief getter for the ReqdRes1
           * @returns the ReqdRes1
           */
          const float getReqdRes1() const
          {
            return RDRC_ASC_REQD_RES1;
          }
          /**
           * @brief getter for the ReqdRes2
           * @returns the ReqdRes2
           */
          const float getReqdRes2() const
          {
            return RDRC_ASC_REQD_RES2;
          }

          void setToIcdDefault() noexcept override
          {
            Command::setToIcdDefault();
            RDRC_ASC_TV_MIN_PCT = IcdDefaultsAs::TV_MIN_PCT_DEFAULT;
            RDRC_ASC_TV_DES_PCT = IcdDefaultsAs::TV_DES_PCT_DEFAULT;
            RDRC_ASC_PAT_T = IcdDefaultsAs::PAT_T_DEFAULT;
            RDRC_ASC_PAT_FS = IcdDefaultsAs::PAT_FS_DEFAULT;
            RDRC_ASC_PAT_D = IcdDefaultsAs::PAT_D_DEFAULT;
            RDRC_ASC_PAT_I = IcdDefaultsAs::PAT_I_DEFAULT;
            RDRC_ASC_TXDISC = IcdDefaults::TXDISC_DEFAULT;
            RDRC_ASC_ENABLE_KTV_OVERRIDE = RDRC_ASC_ENABLE_KTV_OVERRIDE_DEFAULT;
            RDRC_ASC_SPATIAL = IcdDefaultsAs::SPATIAL_DEFAULT;
            RDRC_ASC_IKTV_PRIORITY = IcdDefaults::IKTV_PRIORITY_DEFAULT;
            RDRC_ASC_IKTV_MIN_POS_X = IcdDefaults::IKTV_MIN_POS_X_DEFAULT;
            RDRC_ASC_IKTV_MIN_POS_Z = IcdDefaults::IKTV_MIN_POS_Z_DEFAULT;
            RDRC_ASC_IKTV_MIN_RAP_ATT = IcdDefaults::IKTV_MIN_RAP_ATT_DEFAULT;
            RDRC_ASC_IKTV_MIN_VEL_X = IcdDefaults::IKTV_MIN_VEL_X_DEFAULT;
            RDRC_ASC_IKTV_MIN_VEL_Z = IcdDefaults::IKTV_MIN_VEL_Z_DEFAULT;
            RDRC_ASC_IKTV_DES_POS_X = IcdDefaults::IKTV_DES_POS_X_DEFAULT;
            RDRC_ASC_IKTV_DES_POS_Z = IcdDefaults::IKTV_DES_POS_Z_DEFAULT;
            RDRC_ASC_IKTV_DES_RAP_ATT = IcdDefaults::IKTV_DES_RAP_ATT_DEFAULT;
            RDRC_ASC_IKTV_DES_VEL_X = IcdDefaults::IKTV_DES_VEL_X_DEFAULT;
            RDRC_ASC_IKTV_DES_VEL_Z = IcdDefaults::IKTV_DES_VEL_Z_DEFAULT;
            RDRC_ASC_IKTV_PROACT = IcdDefaults::IKTV_PROACT_DEFAULT;
            RDRC_ASC_ASS_RCS = IcdDefaultsAs::ASS_RCS_DEFAULT;
            RDRC_ASC_ASS_TYPE = IcdDefaultsAs::ASS_TYPE_DEFAULT;
            RDRC_ASC_ASS_VEL = IcdDefaultsAs::ASS_VEL_DEFAULT;
            RDRC_ASC_ASS_HEMIS = IcdDefaultsAs::ASS_HEMIS_DEFAULT;
            RDRC_ASC_ENHD_CTRL = IcdDefaultsAs::RDRC_ASC_ENHD_CTRL_DEFAULT;
            RDRC_ASC_REQD_RES1 = IcdDefaultsAs::REQD_RES1_DEFAULT;
            RDRC_ASC_REQD_RES2 = IcdDefaultsAs::REQD_RES2_DEFAULT;
          }

          /**
           * @brief setter for the Task Minimum Quality
           * @param minimumQuality : the minimum quality to be set
           */
          const void setMinimumQuality(const uint8_t &minimumQuality)
          {
            RDRC_ASC_TV_MIN_PCT = minimumQuality;
          }

          /**
           * @brief setter for the Task Desired Minimum Quality
           * @param desiredQuality : the desired quality to be set
           */
          const void setDesiredQuality(const uint8_t &desiredQuality)
          {
            RDRC_ASC_TV_DES_PCT = desiredQuality;
          }

          /**
           * @brief setter for the patT
           * @param patT : the patT to be set
           */
          const void setPatT(const Search::PAT_T_ENUM &patT)
          {
            RDRC_ASC_PAT_T = patT;
          }

          /**
           * @brief setter for the patFs
           * @param patFs : the patFs to be set
           */
          const void setPatFs(const PAT_FS_ENUM &patFs)
          {
            RDRC_ASC_PAT_FS = patFs;
          }

          /**
           * @brief setter for the patD
           * @param patD : the patD to be set
           */
          const void setPatD(const Search::PAT_D_ENUM &patD)
          {
            RDRC_ASC_PAT_D = patD;
          }

          /**
           * @brief setter for the patI
           * @param patI : the patI to be set
           */
          const void setPatI(const Search::PAT_I_ENUM &patI)
          {
            RDRC_ASC_PAT_I = patI;
          }

          /**
           * @brief setter for the Transmit Discrimination
           * @param transmitDiscrimination : the transmit discrimination to be set
           */
          const void setTransmitDiscrimination(const Common::TXDISC_ENUM &transmitDiscrimination)
          {
            RDRC_ASC_TXDISC = transmitDiscrimination;
          }

          /**
           * @brief setter for the kinematic tv override
           * @param ktvOverride : the override toggle to be set
           */
          const void setEnableKtvOverride(const RDRC_ASC_ENABLE_KTV_OVERRIDE_ENUM &ktvOverride)
          {
            RDRC_ASC_ENABLE_KTV_OVERRIDE = ktvOverride;
          }

          /**
           * @brief setter for the Spacial Dimension Value
           * @param spacialValue : the spacial dimension value to be set
           */
          const void setSpacialValue(const SPATIAL_ENUM &spacialValue)
          {
            RDRC_ASC_SPATIAL = spacialValue;
          }

          /**
           * @brief setter for the Relative Priority
           * @param relativePriority : the relative priority to be set
           */
          const void setRelativePriority(const uint16_t &relativePriority)
          {
            RDRC_ASC_IKTV_PRIORITY = relativePriority;
          }

          /**
           * @brief setter for Minimum Positional Quality
           * @param minPositionalQuality : the minimum positional quality to be set
           */
          const void setInitialMinPositionalQualityX(const SI::SIMeter &minPositionalQuality)
          {
            RDRC_ASC_IKTV_MIN_POS_X = minPositionalQuality;
          }

          /**
           * @brief setter for Minimum Positional Quality
           * @param minPositionalQuality : the minimum positional quality to be set
           */
          const void setInitialMinPositionalQualityZ(const SI::SIMeter &minPositionalQuality)
          {
            RDRC_ASC_IKTV_MIN_POS_Z = minPositionalQuality;
          }

          /**
           * @brief setter for the Rapid Minimum Track Quality
           * @param minTrackQuality : the minimum track quality to be set
           */
          const void setRapidMinTrackQuality(const Common::IKTV_RAP_ATT_ENUM &minTrackQuality)
          {
            RDRC_ASC_IKTV_MIN_RAP_ATT = minTrackQuality;
          }

          /**
           * @brief setter for the Initial Minimum Velocity Quality
           * @param minVelocityQuality : the initial minimum quality to be set
           */
          const void setInitialMinVelocityQualityX(const SI::SIMeterPerSecond minVelocityQuality)
          {
            RDRC_ASC_IKTV_MIN_VEL_X = minVelocityQuality;
          }

          /**
           * @brief setter for the Initial Minimum Velocity Quality
           * @param minVelocityQuality : the initial minimum quality to be set
           */
          const void setInitialMinVelocityQualityZ(const SI::SIMeterPerSecond minVelocityQuality)
          {
            RDRC_ASC_IKTV_MIN_VEL_Z = minVelocityQuality;
          }

          /**
           * @brief setter for the Desired Position Quality
           * @param desiredPositionQuality : the desired position quality to be set
           */
          const void setInitialDesiredPositionQualityX(const SI::SIMeter &desiredPositionQuality)
          {
            RDRC_ASC_IKTV_DES_POS_X = desiredPositionQuality;
          }

          /**
           * @brief setter for the Desired Position Quality
           * @param desiredPositionQuality : the desired position quality to be set
           */
          const void setInitialDesiredPositionQualityZ(const SI::SIMeter &desiredPositionQuality)
          {
            RDRC_ASC_IKTV_DES_POS_Z = desiredPositionQuality;
          }

          /**
           * @brief setter for the Desired Track Quality
           * @param desiredTrackQuality : the desired track quality to be set
           */
          const void setRapidDesiredTrackQuality(const Common::IKTV_RAP_ATT_ENUM &desiredTrackQuality)
          {
            RDRC_ASC_IKTV_DES_RAP_ATT = desiredTrackQuality;
          }

          /**
           * @brief setter for the Desired Velocity Quality
           * @param desiredVelocityQuality : the desired velocity quality to be set
           */
          const void setInitialDesiredVelocityQualityX(const SI::SIMeterPerSecond &desiredVelocityQuality)
          {
            RDRC_ASC_IKTV_DES_VEL_X = desiredVelocityQuality;
          }

          /**
           * @brief setter for the Desired Velocity Quality
           * @param desiredVelocityQuality : the desired velocity quality to be set
           */
          const void setInitialDesiredVelocityQualityZ(const SI::SIMeterPerSecond &desiredVelocityQuality)
          {
            RDRC_ASC_IKTV_DES_VEL_Z = desiredVelocityQuality;
          }

          /**
           * @brief setter for the initial track value
           * @param initialTrackValue : the initial track value to be set
           */
          const void setInitialTrackValue(const bool &initialTrackValue)
          {
            RDRC_ASC_IKTV_PROACT = initialTrackValue;
          }

          /**
           * @brief setter for Air Search Subject Target Size
           * @param targetSize : the target size value to be set
           */
          const void setASSTargetSize(const SI::SIMeterSquared &targetSize)
          {
            RDRC_ASC_ASS_RCS = targetSize;
          }

          /**
           * @brief setter for the Air Search Subject Track Type
           * @param trackType : the track type to be set
           */
          const void setASSTrackType(const ASS_TYPE_ENUM &trackType)
          {
            RDRC_ASC_ASS_TYPE = trackType;
          }

          /**
           * @brief setter for the Air Search Subject Track Velocity
           * @param trackVelocity : the track velocity to be set
           */
          const void setASSTrackVelocity(const NSI::NSIKnot &trackVelocity)
          {
            RDRC_ASC_ASS_VEL = trackVelocity;
          }

          /**
           * @brief setter for the Air Search Subject Track Hemisphere
           * @param trackHemisphere : the track hemisphere to be set
           */
          const void setASSTrackHemisphere(const ASS_HEMIS_ENUM &trackHemisphere)
          {
            RDRC_ASC_ASS_HEMIS = trackHemisphere;
          }

          /**
           * @brief setter for the enhdCtrl
           * @param enhdCtrl : the enhdCtrl
           */
          const void setEnhdCtrl(const ENHD_CTRL_ENUM &enhdCtrl)
          {
            RDRC_ASC_ENHD_CTRL = enhdCtrl;
          }

          /**
           * @brief setter for the ReqdRes1
           * @param ReqdRes1 : the ReqdRes1 to be set
           */
          const void setReqdRes1(const float &ReqdRes1)
          {
            RDRC_ASC_REQD_RES1 = ReqdRes1;
          }

          /**
           * @brief setter for the ReqdRes1
           * @param ReqdRes2 : the ReqdRes1 to be set
           */
          const void setReqdRes2(const float &ReqdRes2)
          {
            RDRC_ASC_REQD_RES2 = ReqdRes2;
          }

        protected:
          /**
           * @brief equality operator
           * @returns true if the field in other contain the same values, false otherwise
           */
          bool operator==(const AirSearchCuedCommand& other) const
          {
            return Command::operator==(other) &&
                   RDRC_ASC_TV_MIN_PCT == other.RDRC_ASC_TV_MIN_PCT &&
                   RDRC_ASC_TV_DES_PCT == other.RDRC_ASC_TV_DES_PCT &&
                   RDRC_ASC_PAT_T == other.RDRC_ASC_PAT_T &&
                   RDRC_ASC_PAT_FS == other.RDRC_ASC_PAT_FS &&
                   RDRC_ASC_PAT_D == other.RDRC_ASC_PAT_D &&
                   RDRC_ASC_PAT_I == other.RDRC_ASC_PAT_I &&
                   RDRC_ASC_TXDISC == other.RDRC_ASC_TXDISC &&
                   RDRC_ASC_ENABLE_KTV_OVERRIDE == other.RDRC_ASC_ENABLE_KTV_OVERRIDE &&
                   RDRC_ASC_SPATIAL == other.RDRC_ASC_SPATIAL &&
                   RDRC_ASC_IKTV_PRIORITY == other.RDRC_ASC_IKTV_PRIORITY &&
                   RDRC_ASC_IKTV_MIN_POS_X == other.RDRC_ASC_IKTV_MIN_POS_X &&
                   RDRC_ASC_IKTV_MIN_POS_Z == other.RDRC_ASC_IKTV_MIN_POS_Z &&
                   RDRC_ASC_IKTV_MIN_RAP_ATT == other.RDRC_ASC_IKTV_MIN_RAP_ATT &&
                   RDRC_ASC_IKTV_MIN_VEL_X == other.RDRC_ASC_IKTV_MIN_VEL_X &&
                   RDRC_ASC_IKTV_MIN_VEL_Z == other.RDRC_ASC_IKTV_MIN_VEL_Z &&
                   RDRC_ASC_IKTV_DES_POS_X == other.RDRC_ASC_IKTV_DES_POS_X &&
                   RDRC_ASC_IKTV_DES_POS_Z == other.RDRC_ASC_IKTV_DES_POS_Z &&
                   RDRC_ASC_IKTV_DES_RAP_ATT == other.RDRC_ASC_IKTV_DES_RAP_ATT &&
                   RDRC_ASC_IKTV_DES_VEL_X == other.RDRC_ASC_IKTV_DES_VEL_X &&
                   RDRC_ASC_IKTV_DES_VEL_Z == other.RDRC_ASC_IKTV_DES_VEL_Z &&
                   RDRC_ASC_IKTV_PROACT == other.RDRC_ASC_IKTV_PROACT &&
                   RDRC_ASC_ASS_RCS == other.RDRC_ASC_ASS_RCS &&
                   RDRC_ASC_ASS_TYPE == other.RDRC_ASC_ASS_TYPE &&
                   RDRC_ASC_ASS_VEL == other.RDRC_ASC_ASS_VEL &&
                   RDRC_ASC_ASS_HEMIS == other.RDRC_ASC_ASS_HEMIS &&
                   RDRC_ASC_ENHD_CTRL == other.RDRC_ASC_ENHD_CTRL &&
                   RDRC_ASC_REQD_RES1 == other.RDRC_ASC_REQD_RES1 &&
                   RDRC_ASC_REQD_RES2 == other.RDRC_ASC_REQD_RES2;
          }
        };

      }
    }
  }
} // namespace Topics
#endif