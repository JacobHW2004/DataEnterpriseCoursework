#ifndef AIR_TRACK_NORMAL_COMMAND_H
#define AIR_TRACK_NORMAL_COMMAND_H

#include <memory>
#include <string>

#include "Command.h"
#include "CommonAirTrackValues.h"
#include "CommonWeaponSystemValues.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "NSINauticalMile.h"
#include "SIDegree.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"

namespace Topics
{
  namespace EcrsMK2
  {

    namespace WeaponSystem
    {

      namespace AirTrack
      {

        // NCI_REPORT_TECH Technique
        enum class RDRC_ATN_TXX_NCI_REPORT_TECH_ENUM : uint8_t
        {
          NO_NCI_REPORT_TECH = 0x00,
          NCI_REPORT_TECH_TECH_1 = 0x01,
          NCI_REPORT_TECH_TECH_2 = 0x02,
          NCI_REPORT_TECH_TECH_3 = 0x03,
          NCI_REPORT_TECH_TECH_4 = 0x04
        };

        enum class RDRC_ATN_TXX_NCI_REPORT_TYPE_ENUM : uint8_t
        {
          CORRELATION = 0x00,
          LIKELIHOOD = 0x01
        };

        enum class RDRC_ATN_TXX_NCI_ENUM : uint8_t
        {
          NO_NCI = 0x00,
          NCI = 0x01,
        };

        enum class RDRC_ATN_TXX_GUN_TARGET_ENUM : uint8_t
        {
          NO_GUN = 0x00,
          GUN = 0x01
        };

        enum class RDRC_ATN_TXX_VALIDITY_ENUM : uint8_t
        {
          INVALID = 0x00,
          VALID = 0x01
        };

        // Allows radar to initiate manual PAE against the associated track
        enum class RDRC_ATN_TXX_MAN_PAE_ENUM : uint8_t
        {
          NO_ACTION = 0x00,
          SELECT = 0x01
        };

        // Disable enable toggle
        enum class RDRC_ATN_TXX_ALLOWED_ENUM : uint8_t
        {
          ALLOWED = 0x00,
          INHIBITED = 0x01
        };

        /**
         * @brief this topic is a strongly typed one to one mapping of Radar Command 2 - message AC36-RADAR-HAT-MESS-1 (ATN) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         */
        class AirTrackNormalCommand : public Common::Command
        {
        public:
          //___________DEFAULT_MESSAGE_VALUES______________//
          // Default values are defined within the ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02

          static constexpr bool RDRC_ATN_TXX_INHIBIT_IKTV_DEFAULT{false};
          static constexpr RDRC_ATN_TXX_NCI_REPORT_TECH_ENUM RDRC_ATN_TXX_NCI_REPORT_TECH_DEFAULT{RDRC_ATN_TXX_NCI_REPORT_TECH_ENUM::NO_NCI_REPORT_TECH};
          static constexpr RDRC_ATN_TXX_NCI_REPORT_TYPE_ENUM RDRC_ATN_TXX_NCI_REPORT_TYPE_DEFAULT{RDRC_ATN_TXX_NCI_REPORT_TYPE_ENUM::CORRELATION};
          static constexpr RDRC_ATN_TXX_NCI_ENUM RDRC_ATN_TXX_NCI_JEM_DEFAULT{RDRC_ATN_TXX_NCI_ENUM::NO_NCI};
          static constexpr RDRC_ATN_TXX_NCI_ENUM RDRC_ATN_TXX_NCI_RDI_DEFAULT{RDRC_ATN_TXX_NCI_ENUM::NO_NCI};
          static constexpr RDRC_ATN_TXX_NCI_ENUM RDRC_ATN_TXX_NCI_HRR_DEFAULT{RDRC_ATN_TXX_NCI_ENUM::NO_NCI};
          static constexpr RDRC_ATN_TXX_NCI_ENUM RDRC_ATN_TXX_NCI_TECH4_DEFAULT{RDRC_ATN_TXX_NCI_ENUM::NO_NCI};
          static constexpr RDRC_ATN_TXX_GUN_TARGET_ENUM RDRC_ATN_TXX_GUN_TARGET_DEFAULT{RDRC_ATN_TXX_GUN_TARGET_ENUM::NO_GUN};
          static constexpr RDRC_ATN_TXX_VALIDITY_ENUM RDRC_ATN_TXX_TGT_AID_VALID_DEFAULT{RDRC_ATN_TXX_VALIDITY_ENUM::INVALID};
          static constexpr RDRC_ATN_TXX_VALIDITY_ENUM RDRC_ATN_TXX_TRK_SUP_VALID_DEFAULT{RDRC_ATN_TXX_VALIDITY_ENUM::INVALID};
          static constexpr RDRC_ATN_TXX_VALIDITY_ENUM RDRC_ATN_TXX_WIND_VEC_VALID_DEFAULT{RDRC_ATN_TXX_VALIDITY_ENUM::INVALID};
          static constexpr double RDRC_ATN_TXX_TGT_AID_AZ_DEFAULT{0.0};
          static constexpr double RDRC_ATN_TXX_TGT_AID_EL_DEFAULT{0.0};
          static constexpr double RDRC_ATN_TXX_TGT_AID_RNG_DEFAULT{0.0};
          static constexpr uint16_t RDRC_ATN_TXX_TRK_SUP_VALUE_DEFAULT{0};
          static constexpr uint16_t RDRC_ATN_TXX_WIND_VEC_VALUE_DEFAULT{0};
          static constexpr RDRC_ATN_TXX_MAN_PAE_ENUM RDRC_ATN_TXX_MAN_PAE_DEFAULT{RDRC_ATN_TXX_MAN_PAE_ENUM::NO_ACTION};
          static constexpr bool RDRC_ATN_TXX_INHIB_SPARE_RES_DEFAULT{false};
          static constexpr RDRC_ATN_TXX_ALLOWED_ENUM RDRC_ATN_TXX_CLEAR_TO_JAM_DEFAULT{RDRC_ATN_TXX_ALLOWED_ENUM::ALLOWED};
          static constexpr RDRC_ATN_TXX_ALLOWED_ENUM RDRC_ATN_TXX_JAM_TO_CLEAR_DEFAULT{RDRC_ATN_TXX_ALLOWED_ENUM::ALLOWED};
          static constexpr uint16_t RDRC_ATN_TXX_TRK_IDENTIFIER_DEFAULT{0};
          static constexpr uint8_t RDRC_ATN_TXX_RESERVED_DEFAULT{0};

          //______________________________________________//

          SI::SIMeter RDRC_ATN_TXX_KTV_MIN_POS_X{IcdDefaults::IKTV_MIN_POS_X_DEFAULT};

          SI::SIMeter RDRC_ATN_TXX_KTV_MIN_POS_Z{IcdDefaults::IKTV_MIN_POS_Z_DEFAULT};

          Common::IKTV_RAP_ATT_ENUM RDRC_ATN_TXX_KTV_MIN_RAP_ATT{};

          SI::SIMeterPerSecond RDRC_ATN_TXX_KTV_MIN_VEL_X{IcdDefaults::IKTV_MIN_VEL_X_DEFAULT};

          SI::SIMeterPerSecond RDRC_ATN_TXX_KTV_MIN_VEL_Z{IcdDefaults::IKTV_MIN_VEL_Z_DEFAULT};

          SI::SIMeter RDRC_ATN_TXX_KTV_DES_POS_X{IcdDefaults::IKTV_DES_POS_X_DEFAULT};

          SI::SIMeter RDRC_ATN_TXX_KTV_DES_POS_Z{IcdDefaults::IKTV_DES_POS_Z_DEFAULT};

          Common::IKTV_RAP_ATT_ENUM RDRC_ATN_TXX_KTV_DES_RAP_ATT{IcdDefaults::IKTV_DES_RAP_ATT_DEFAULT};

          SI::SIMeterPerSecond RDRC_ATN_TXX_KTV_DES_VEL_X{IcdDefaults::IKTV_DES_VEL_X_DEFAULT};

          SI::SIMeterPerSecond RDRC_ATN_TXX_KTV_DES_VEL_Z{IcdDefaults::IKTV_DES_VEL_Z_DEFAULT};

          bool RDRC_ATN_TXX_KTV_PROACT{};

          bool RDRC_ATN_TXX_INHIBIT_IKTV{};

          RDRC_ATN_TXX_NCI_REPORT_TECH_ENUM RDRC_ATN_TXX_NCI_REPORT_TECH{RDRC_ATN_TXX_NCI_REPORT_TECH_DEFAULT};

          RDRC_ATN_TXX_NCI_REPORT_TYPE_ENUM RDRC_ATN_TXX_NCI_REPORT_TYPE{RDRC_ATN_TXX_NCI_REPORT_TYPE_DEFAULT};

          RDRC_ATN_TXX_NCI_ENUM RDRC_ATN_TXX_NCI_JEM{RDRC_ATN_TXX_NCI_JEM_DEFAULT};

          RDRC_ATN_TXX_NCI_ENUM RDRC_ATN_TXX_NCI_RDI{RDRC_ATN_TXX_NCI_RDI_DEFAULT};

          RDRC_ATN_TXX_NCI_ENUM RDRC_ATN_TXX_NCI_HRR{RDRC_ATN_TXX_NCI_HRR_DEFAULT};

          RDRC_ATN_TXX_NCI_ENUM RDRC_ATN_TXX_NCI_TECH4{RDRC_ATN_TXX_NCI_TECH4_DEFAULT};

          RDRC_ATN_TXX_GUN_TARGET_ENUM RDRC_ATN_TXX_GUN_TARGET{RDRC_ATN_TXX_GUN_TARGET_DEFAULT};

          RDRC_ATN_TXX_VALIDITY_ENUM RDRC_ATN_TXX_TGT_AID_VALID{RDRC_ATN_TXX_TGT_AID_VALID_DEFAULT};

          RDRC_ATN_TXX_VALIDITY_ENUM RDRC_ATN_TXX_TRK_SUP_VALID{RDRC_ATN_TXX_TRK_SUP_VALID_DEFAULT};

          RDRC_ATN_TXX_VALIDITY_ENUM RDRC_ATN_TXX_WIND_VEC_VALID{RDRC_ATN_TXX_WIND_VEC_VALID_DEFAULT};

          SI::SIDegree RDRC_ATN_TXX_TGT_AID_AZ{RDRC_ATN_TXX_TGT_AID_AZ_DEFAULT};

          SI::SIDegree RDRC_ATN_TXX_TGT_AID_EL{RDRC_ATN_TXX_TGT_AID_EL_DEFAULT};

          NSI::NSINauticalMile RDRC_ATN_TXX_TGT_AID_RNG{RDRC_ATN_TXX_TGT_AID_RNG_DEFAULT};

          uint16_t RDRC_ATN_TXX_TRK_SUP_VALUE{RDRC_ATN_TXX_TRK_SUP_VALUE_DEFAULT};

          uint16_t RDRC_ATN_TXX_WIND_VEC_VALUE{RDRC_ATN_TXX_WIND_VEC_VALUE_DEFAULT};

          RDRC_ATN_TXX_MAN_PAE_ENUM RDRC_ATN_TXX_MAN_PAE{};

          Common::TXDISC_ENUM RDRC_ATN_TXX_TXDISC{};

          bool RDRC_ATN_TXX_INHIB_SPARE_RES{};

          RDRC_ATN_TXX_ALLOWED_ENUM RDRC_ATN_TXX_CLEAR_TO_JAM{RDRC_ATN_TXX_CLEAR_TO_JAM_DEFAULT};

          RDRC_ATN_TXX_ALLOWED_ENUM RDRC_ATN_TXX_JAM_TO_CLEAR{RDRC_ATN_TXX_JAM_TO_CLEAR_DEFAULT};

          RDRX_ATN_TXX_TYPE_TRANS_CTRL_ENUM RDRC_ATN_TXX_TYPE_TRANS_CTRL{};

          uint16_t RDRC_ATN_TXX_TRK_IDENTIFIER{};

          uint8_t RDRC_ATN_TXX_RESERVED{};

          virtual Common::WeaponSystemTaskType getTaskType() const noexcept override
          {
            return Common::WeaponSystemTaskType::AIR_TRACK_NORMAL;
          }

          void setToIcdDefault() noexcept override
          {
            Command::setToIcdDefault();
            RDRC_ATN_TXX_KTV_MIN_POS_X = IcdDefaults::IKTV_MIN_POS_X_DEFAULT;
            RDRC_ATN_TXX_KTV_MIN_POS_Z = IcdDefaults::IKTV_MIN_POS_Z_DEFAULT;
            RDRC_ATN_TXX_KTV_MIN_RAP_ATT = IcdDefaults::IKTV_MIN_RAP_ATT_DEFAULT;
            RDRC_ATN_TXX_KTV_MIN_VEL_X = IcdDefaults::IKTV_MIN_VEL_X_DEFAULT;
            RDRC_ATN_TXX_KTV_MIN_VEL_Z = IcdDefaults::IKTV_MIN_VEL_Z_DEFAULT;
            RDRC_ATN_TXX_KTV_DES_POS_X = IcdDefaults::IKTV_DES_POS_X_DEFAULT;
            RDRC_ATN_TXX_KTV_DES_POS_Z = IcdDefaults::IKTV_DES_POS_Z_DEFAULT;
            RDRC_ATN_TXX_KTV_DES_RAP_ATT = IcdDefaults::IKTV_DES_RAP_ATT_DEFAULT;
            RDRC_ATN_TXX_KTV_DES_VEL_X = IcdDefaults::IKTV_DES_VEL_X_DEFAULT;
            RDRC_ATN_TXX_KTV_DES_VEL_Z = IcdDefaults::IKTV_DES_VEL_Z_DEFAULT;
            RDRC_ATN_TXX_KTV_PROACT = IcdDefaults::IKTV_PROACT_DEFAULT;
            RDRC_ATN_TXX_INHIBIT_IKTV = RDRC_ATN_TXX_INHIBIT_IKTV_DEFAULT;
            RDRC_ATN_TXX_NCI_REPORT_TECH = RDRC_ATN_TXX_NCI_REPORT_TECH_DEFAULT;
            RDRC_ATN_TXX_NCI_REPORT_TYPE = RDRC_ATN_TXX_NCI_REPORT_TYPE_DEFAULT;
            RDRC_ATN_TXX_NCI_JEM = RDRC_ATN_TXX_NCI_JEM_DEFAULT;
            RDRC_ATN_TXX_NCI_RDI = RDRC_ATN_TXX_NCI_RDI_DEFAULT;
            RDRC_ATN_TXX_NCI_HRR = RDRC_ATN_TXX_NCI_HRR_DEFAULT;
            RDRC_ATN_TXX_NCI_TECH4 = RDRC_ATN_TXX_NCI_TECH4_DEFAULT;
            RDRC_ATN_TXX_GUN_TARGET = RDRC_ATN_TXX_GUN_TARGET_DEFAULT;
            RDRC_ATN_TXX_TGT_AID_VALID = RDRC_ATN_TXX_TGT_AID_VALID_DEFAULT;
            RDRC_ATN_TXX_TRK_SUP_VALID = RDRC_ATN_TXX_TRK_SUP_VALID_DEFAULT;
            RDRC_ATN_TXX_WIND_VEC_VALID = RDRC_ATN_TXX_WIND_VEC_VALID_DEFAULT;
            RDRC_ATN_TXX_TGT_AID_AZ = RDRC_ATN_TXX_TGT_AID_AZ_DEFAULT;
            RDRC_ATN_TXX_TGT_AID_EL = RDRC_ATN_TXX_TGT_AID_EL_DEFAULT;
            RDRC_ATN_TXX_TGT_AID_RNG = RDRC_ATN_TXX_TGT_AID_RNG_DEFAULT;
            RDRC_ATN_TXX_TRK_SUP_VALUE = RDRC_ATN_TXX_TRK_SUP_VALUE_DEFAULT;
            RDRC_ATN_TXX_WIND_VEC_VALUE = RDRC_ATN_TXX_WIND_VEC_VALUE_DEFAULT;
            RDRC_ATN_TXX_MAN_PAE = RDRC_ATN_TXX_MAN_PAE_DEFAULT;
            RDRC_ATN_TXX_TXDISC = IcdDefaults::TXDISC_DEFAULT;
            RDRC_ATN_TXX_INHIB_SPARE_RES = RDRC_ATN_TXX_INHIB_SPARE_RES_DEFAULT;
            RDRC_ATN_TXX_CLEAR_TO_JAM = RDRC_ATN_TXX_CLEAR_TO_JAM_DEFAULT;
            RDRC_ATN_TXX_JAM_TO_CLEAR = RDRC_ATN_TXX_JAM_TO_CLEAR_DEFAULT;
            RDRC_ATN_TXX_TYPE_TRANS_CTRL = RDRX_ATN_TXX_TYPE_TRANS_CTRL_DEFAULT;
            RDRC_ATN_TXX_TRK_IDENTIFIER = RDRC_ATN_TXX_TRK_IDENTIFIER_DEFAULT;
            RDRC_ATN_TXX_RESERVED = RDRC_ATN_TXX_RESERVED_DEFAULT;
          }

          /**
           * @brief equality operator
           * @returns true if the field in other contain the same values, false otherwise
           */
          bool operator==(const AirTrackNormalCommand& other) const
          {
            return Command::operator==(other) &&
                   RDRC_ATN_TXX_KTV_MIN_POS_X == other.RDRC_ATN_TXX_KTV_MIN_POS_X &&
                   RDRC_ATN_TXX_KTV_MIN_POS_Z == other.RDRC_ATN_TXX_KTV_MIN_POS_Z &&
                   RDRC_ATN_TXX_KTV_MIN_RAP_ATT == other.RDRC_ATN_TXX_KTV_MIN_RAP_ATT &&
                   RDRC_ATN_TXX_KTV_MIN_VEL_X == other.RDRC_ATN_TXX_KTV_MIN_VEL_X &&
                   RDRC_ATN_TXX_KTV_MIN_VEL_Z == other.RDRC_ATN_TXX_KTV_MIN_VEL_Z &&
                   RDRC_ATN_TXX_KTV_DES_POS_X == other.RDRC_ATN_TXX_KTV_DES_POS_X &&
                   RDRC_ATN_TXX_KTV_DES_POS_Z == other.RDRC_ATN_TXX_KTV_DES_POS_Z &&
                   RDRC_ATN_TXX_KTV_DES_RAP_ATT == other.RDRC_ATN_TXX_KTV_DES_RAP_ATT &&
                   RDRC_ATN_TXX_KTV_DES_VEL_X == other.RDRC_ATN_TXX_KTV_DES_VEL_X &&
                   RDRC_ATN_TXX_KTV_DES_VEL_Z == other.RDRC_ATN_TXX_KTV_DES_VEL_Z &&
                   RDRC_ATN_TXX_KTV_PROACT == other.RDRC_ATN_TXX_KTV_PROACT &&
                   RDRC_ATN_TXX_INHIBIT_IKTV == other.RDRC_ATN_TXX_INHIBIT_IKTV &&
                   RDRC_ATN_TXX_NCI_REPORT_TECH == other.RDRC_ATN_TXX_NCI_REPORT_TECH &&
                   RDRC_ATN_TXX_NCI_REPORT_TYPE == other.RDRC_ATN_TXX_NCI_REPORT_TYPE &&
                   RDRC_ATN_TXX_NCI_JEM == other.RDRC_ATN_TXX_NCI_JEM &&
                   RDRC_ATN_TXX_NCI_RDI == other.RDRC_ATN_TXX_NCI_RDI &&
                   RDRC_ATN_TXX_NCI_HRR == other.RDRC_ATN_TXX_NCI_HRR &&
                   RDRC_ATN_TXX_NCI_TECH4 == other.RDRC_ATN_TXX_NCI_TECH4 &&
                   RDRC_ATN_TXX_GUN_TARGET == other.RDRC_ATN_TXX_GUN_TARGET &&
                   RDRC_ATN_TXX_TGT_AID_VALID == other.RDRC_ATN_TXX_TGT_AID_VALID &&
                   RDRC_ATN_TXX_TRK_SUP_VALID == other.RDRC_ATN_TXX_TRK_SUP_VALID &&
                   RDRC_ATN_TXX_WIND_VEC_VALID == other.RDRC_ATN_TXX_WIND_VEC_VALID &&
                   RDRC_ATN_TXX_TGT_AID_AZ == other.RDRC_ATN_TXX_TGT_AID_AZ &&
                   RDRC_ATN_TXX_TGT_AID_EL == other.RDRC_ATN_TXX_TGT_AID_EL &&
                   RDRC_ATN_TXX_TGT_AID_RNG == other.RDRC_ATN_TXX_TGT_AID_RNG &&
                   RDRC_ATN_TXX_TRK_SUP_VALUE == other.RDRC_ATN_TXX_TRK_SUP_VALUE &&
                   RDRC_ATN_TXX_WIND_VEC_VALUE == other.RDRC_ATN_TXX_WIND_VEC_VALUE &&
                   RDRC_ATN_TXX_MAN_PAE == other.RDRC_ATN_TXX_MAN_PAE &&
                   RDRC_ATN_TXX_TXDISC == other.RDRC_ATN_TXX_TXDISC &&
                   RDRC_ATN_TXX_INHIB_SPARE_RES == other.RDRC_ATN_TXX_INHIB_SPARE_RES &&
                   RDRC_ATN_TXX_CLEAR_TO_JAM == other.RDRC_ATN_TXX_CLEAR_TO_JAM &&
                   RDRC_ATN_TXX_JAM_TO_CLEAR == other.RDRC_ATN_TXX_JAM_TO_CLEAR &&
                   RDRC_ATN_TXX_TYPE_TRANS_CTRL == other.RDRC_ATN_TXX_TYPE_TRANS_CTRL &&
                   RDRC_ATN_TXX_TRK_IDENTIFIER == other.RDRC_ATN_TXX_TRK_IDENTIFIER &&
                   RDRC_ATN_TXX_RESERVED == other.RDRC_ATN_TXX_RESERVED;
          }

          bool operator!=(const AirTrackNormalCommand &other) const
          {
            return !(*this == other);
          }

          /**
           * @brief Serialise function required for communications
           */
          template <class T>
          void Serialise(T &archive)
          {
            Common::WeaponSystemTaskType RDRC_TRK_TXX_TASK_TYPE = getTaskType();
            double doubleRDRC_ATN_TXX_KTV_MIN_POS_X{RDRC_ATN_TXX_KTV_MIN_POS_X()};
            double doubleRDRC_ATN_TXX_KTV_MIN_POS_Z{RDRC_ATN_TXX_KTV_MIN_POS_Z()};
            double doubleRDRC_ATN_TXX_KTV_DES_POS_X{RDRC_ATN_TXX_KTV_DES_POS_X()};
            double doubleRDRC_ATN_TXX_KTV_DES_POS_Z{RDRC_ATN_TXX_KTV_DES_POS_Z()};
            double doubleRDRC_ATN_TXX_KTV_MIN_VEL_X{RDRC_ATN_TXX_KTV_MIN_VEL_X()};
            double doubleRDRC_ATN_TXX_KTV_MIN_VEL_Z{RDRC_ATN_TXX_KTV_MIN_VEL_Z()};
            double doubleRDRC_ATN_TXX_KTV_DES_VEL_X{RDRC_ATN_TXX_KTV_DES_VEL_X()};
            double doubleRDRC_ATN_TXX_KTV_DES_VEL_Z{RDRC_ATN_TXX_KTV_DES_VEL_Z()};
            double doubleRDRC_ATN_TXX_TGT_AID_AZ{RDRC_ATN_TXX_TGT_AID_AZ()};
            double doubleRDRC_ATN_TXX_TGT_AID_EL{RDRC_ATN_TXX_TGT_AID_EL()};
            double doubleRDRC_ATN_TXX_TGT_AID_RNG{RDRC_ATN_TXX_TGT_AID_RNG()};

            archive.Serialise(TASK_IDENT, "RDRC_TRK_TXX_TASK_IDENT");
            archive.Serialise(CMD, "RDRC_TRK_TXX_CMD");
            archive.Serialise(RDRC_TRK_TXX_TASK_TYPE, "RDRC_TRK_TXX_TASK_TYPE");
            archive.Serialise(TV_PRIORITY, "RDRC_ATN_TXX_KTV_PRIORITY");
            archive.Serialise(doubleRDRC_ATN_TXX_KTV_MIN_POS_X, "doubleRDRC_ATN_TXX_KTV_MIN_POS_X");
            archive.Serialise(doubleRDRC_ATN_TXX_KTV_MIN_POS_Z, "doubleRDRC_ATN_TXX_KTV_MIN_POS_Z");
            archive.Serialise(RDRC_ATN_TXX_KTV_MIN_RAP_ATT, "RDRC_ATN_TXX_KTV_MIN_RAP_ATT");
            archive.Serialise(doubleRDRC_ATN_TXX_KTV_MIN_VEL_X, "doubleRDRC_ATN_TXX_KTV_MIN_VEL_X");
            archive.Serialise(doubleRDRC_ATN_TXX_KTV_MIN_VEL_Z, "doubleRDRC_ATN_TXX_KTV_MIN_VEL_Z");
            archive.Serialise(doubleRDRC_ATN_TXX_KTV_DES_POS_X, "doubleRDRC_ATN_TXX_KTV_DES_POS_X");
            archive.Serialise(doubleRDRC_ATN_TXX_KTV_DES_POS_Z, "doubleRDRC_ATN_TXX_KTV_DES_POS_Z");
            archive.Serialise(RDRC_ATN_TXX_KTV_DES_RAP_ATT, "RDRC_ATN_TXX_KTV_DES_RAP_ATT");
            archive.Serialise(doubleRDRC_ATN_TXX_KTV_DES_VEL_X, "doubleRDRC_ATN_TXX_KTV_DES_VEL_X");
            archive.Serialise(doubleRDRC_ATN_TXX_KTV_DES_VEL_Z, "doubleRDRC_ATN_TXX_KTV_DES_VEL_Z");
            archive.Serialise(RDRC_ATN_TXX_KTV_PROACT, "RDRC_ATN_TXX_KTV_PROACT");
            archive.Serialise(RDRC_ATN_TXX_INHIBIT_IKTV, "RDRC_ATN_TXX_INHIBIT_IKTV");
            archive.Serialise(RDRC_ATN_TXX_NCI_REPORT_TECH, "RDRC_ATN_TXX_NCI_REPORT_TECH");
            archive.Serialise(RDRC_ATN_TXX_NCI_REPORT_TYPE, "RDRC_ATN_TXX_NCI_REPORT_TYPE");
            archive.Serialise(RDRC_ATN_TXX_NCI_JEM, "RDRC_ATN_TXX_NCI_JEM");
            archive.Serialise(RDRC_ATN_TXX_NCI_RDI, "RDRC_ATN_TXX_NCI_RDI");
            archive.Serialise(RDRC_ATN_TXX_NCI_HRR, "RDRC_ATN_TXX_NCI_HRR");
            archive.Serialise(RDRC_ATN_TXX_NCI_TECH4, "RDRC_ATN_TXX_NCI_TECH4");
            archive.Serialise(RDRC_ATN_TXX_MAN_PAE, "RDRC_ATN_TXX_MAN_PAE");
            archive.Serialise(RDRC_ATN_TXX_GUN_TARGET, "RDRC_ATN_TXX_GUN_TARGET");
            archive.Serialise(RDRC_ATN_TXX_TGT_AID_VALID, "RDRC_ATN_TXX_TGT_AID_VALID");
            archive.Serialise(RDRC_ATN_TXX_TRK_SUP_VALID, "RDRC_ATN_TXX_TRK_SUP_VALID");
            archive.Serialise(RDRC_ATN_TXX_WIND_VEC_VALID, "RDRC_ATN_TXX_WIND_VEC_VALID");
            archive.Serialise(doubleRDRC_ATN_TXX_TGT_AID_AZ, "doubleRDRC_ATN_TXX_TGT_AID_AZ");
            archive.Serialise(doubleRDRC_ATN_TXX_TGT_AID_EL, "doubleRDRC_ATN_TXX_TGT_AID_EL");
            archive.Serialise(doubleRDRC_ATN_TXX_TGT_AID_RNG, "doubleRDRC_ATN_TXX_TGT_AID_RNG");
            archive.Serialise(RDRC_ATN_TXX_TRK_SUP_VALUE, "RDRC_ATN_TXX_TRK_SUP_VALUE");
            archive.Serialise(RDRC_ATN_TXX_WIND_VEC_VALUE, "RDRC_ATN_TXX_WIND_VEC_VALUE");
            archive.Serialise(RDRC_ATN_TXX_TXDISC, "RDRC_ATN_TXX_TXDISC");
            archive.Serialise(RDRC_ATN_TXX_INHIB_SPARE_RES, "RDRC_ATN_TXX_INHIB_SPARE_RES");
            archive.Serialise(RDRC_ATN_TXX_CLEAR_TO_JAM, "RDRC_ATN_TXX_CLEAR_TO_JAM");
            archive.Serialise(RDRC_ATN_TXX_JAM_TO_CLEAR, "RDRC_ATN_TXX_JAM_TO_CLEAR");
            archive.Serialise(RDRC_ATN_TXX_TYPE_TRANS_CTRL, "RDRC_ATN_TXX_TYPE_TRANS_CTRL");
            archive.Serialise(RDRC_ATN_TXX_TRK_IDENTIFIER, "RDRC_ATN_TXX_TRK_IDENTIFIER");
            archive.Serialise(RDRC_ATN_TXX_RESERVED, "RDRC_ATN_TXX_RESERVED");
            archive.Serialise(TDI, "RDRC_TRK_TXX_TDI");

            RDRC_ATN_TXX_KTV_MIN_POS_X = doubleRDRC_ATN_TXX_KTV_MIN_POS_X;
            RDRC_ATN_TXX_KTV_MIN_POS_Z = doubleRDRC_ATN_TXX_KTV_MIN_POS_Z;
            RDRC_ATN_TXX_KTV_DES_POS_X = doubleRDRC_ATN_TXX_KTV_DES_POS_X;
            RDRC_ATN_TXX_KTV_DES_POS_Z = doubleRDRC_ATN_TXX_KTV_DES_POS_Z;
            RDRC_ATN_TXX_KTV_MIN_VEL_X = doubleRDRC_ATN_TXX_KTV_MIN_VEL_X;
            RDRC_ATN_TXX_KTV_MIN_VEL_Z = doubleRDRC_ATN_TXX_KTV_MIN_VEL_Z;
            RDRC_ATN_TXX_KTV_DES_VEL_X = doubleRDRC_ATN_TXX_KTV_DES_VEL_X;
            RDRC_ATN_TXX_KTV_DES_VEL_Z = doubleRDRC_ATN_TXX_KTV_DES_VEL_Z;
            RDRC_ATN_TXX_TGT_AID_AZ = doubleRDRC_ATN_TXX_TGT_AID_AZ;
            RDRC_ATN_TXX_TGT_AID_EL = doubleRDRC_ATN_TXX_TGT_AID_EL;
            RDRC_ATN_TXX_TGT_AID_RNG = doubleRDRC_ATN_TXX_TGT_AID_RNG;
          }

          LCA_TOPIC("AirTrackNormalCommand", 1, 0)
        };

      } // namespace AirTrack
    }
  }
} // namespace Topics

#endif