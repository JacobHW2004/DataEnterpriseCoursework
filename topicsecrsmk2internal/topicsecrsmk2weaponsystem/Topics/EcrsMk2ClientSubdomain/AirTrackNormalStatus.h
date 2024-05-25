#ifndef AIR_TRACK_NORMAL_STATUS_H
#define AIR_TRACK_NORMAL_STATUS_H

#include <memory>
#include <string>

#include "CommonAirTrackValues.h"
#include "CommonWeaponSystemValues.h"
#include "Fabric/Utils/LCA_Macros.h"
#include "FloatEqualityChecker.h"
#include "Status.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {
      namespace AirTrack
      {

        // Rapid Track revisits
        enum class RDRS_ATN_TXX_RAP_ATT_STATUS_ENUM : uint8_t
        {
          NOT_RAPID = 0x00,
          RAPID = 0x01
        };

        // Indicates that the radar is currenty performing or has performed a rapid
        // response against the associated track
        enum class RDRS_ATN_TXX_RAPID_RESP_STS_ENUM : uint8_t
        {
          NOT_RAPID = 0x00,
          RAPID = 0x01
        };

        // Recommends Air track is deleted
        enum class RDRS_ATN_TXX_REC_TRK_DEL_ENUM : uint8_t
        {
          INVALID = 0x00,
          NO_DEL = 0x01,
          PAE = 0x02,
          TDEL = 0x03,
          QDEL = 0x04
        };

        // Indicates NCI dwells are being carried out
        enum class RDRS_ATN_TXX_NCI_STATUS_ENUM : uint8_t
        {
          NONE_REQUESTED = 0x00,
          IN_PROGRESS = 0x01,
          PENDING = 0x02,
          COMPLETE = 0x03
        };

        // Indicates NCI employed against the Track
        enum class RDRS_ATN_TXX_NCI_TECHNIQUE_ENUM : uint8_t
        {
          NCI_TECH_1 = 0x00,
          NCI_TECH_2 = 0x01,
          NCI_TECH_3 = 0x02,
          NCI_TECH_4 = 0x03
        };

        // Indicates if PAE employed against the Track or the PAE
        // technique being used
        enum class RDRS_ATN_TXX_PAE_STATUS_ENUM : uint8_t
        {
          INVALID = 0x00,
          NO_PAE = 0x01,
          MAN_PAE = 0x02,
          AUTO_HIGH_PAE = 0x03,
          AUTO_LOW_PAE = 0x04
        };

        // Indicates whether the radar is performing track recovery
        // against the associated the Air Track
        enum class RDRS_ATN_TXX_PERF_TRK_RECOVERY_ENUM : uint8_t
        {
          NO_ACTION = 0x00,
          RECOVERY = 0x01
        };

        // Indicates whether the radar has enabled track transitions
        // from Clear to Jam
        enum class RDRS_ATN_TXX_CLR_TO_JAM_STS_ENUM : uint8_t
        {
          DISABLE = 0x00,
          ENABLE = 0x01
        };

        // Indicates whether the radar has enabled track transitions
        // from Jam to Clear
        enum class RDRS_ATN_TXX_JAM_TO_CLR_STS_ENUM : uint8_t
        {
          DISABLE = 0x00,
          ENABLE = 0x01
        };

        //____________________DEFAULT_MESSAGE_VALUES____________________//
        // Default values are defined within the ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02

        static constexpr uint8_t RDRS_ATN_TXX_ACHIEVED_POSREF_DEFAULT{0};
        static constexpr RDRS_ATN_TXX_RAP_ATT_STATUS_ENUM RDRS_ATN_TXX_RAP_ATT_STATUS_DEFAULT{RDRS_ATN_TXX_RAP_ATT_STATUS_ENUM::NOT_RAPID};
        static constexpr uint8_t RDRS_ATN_TXX_ACHIEVED_VELREF_DEFAULT{0};
        static constexpr float RDRS_ATN_TXX_RES_REP_ACTUAL_DEFAULT{0.0F};
        static constexpr float RDRS_ATN_TXX_RES_REP_PRED_DES_DEFAULT{0.0F};
        static constexpr float RDRS_ATN_TXX_RES_REP_PRED_MIN_DEFAULT{0.0F};
        static constexpr float RDRS_ATN_TXX_RES_ANT_ACTUAL_DEFAULT{0.0F};
        static constexpr float RDRS_ATN_TXX_RES_ANT_PRED_DES_DEFAULT{0.0F};
        static constexpr float RDRS_ATN_TXX_RES_ANT_PRED_MIN_DEFAULT{0.0F};
        static constexpr RDRS_ATN_TXX_REC_TRK_DEL_ENUM RDRS_ATN_TXX_REC_TRK_DEL_DEFAULT{RDRS_ATN_TXX_REC_TRK_DEL_ENUM::INVALID};
        static constexpr RDRS_ATN_TXX_NCI_STATUS_ENUM RDRS_ATN_TXX_NCI_STATUS_DEFAULT{RDRS_ATN_TXX_NCI_STATUS_ENUM::NONE_REQUESTED};
        static constexpr RDRS_ATN_TXX_NCI_TECHNIQUE_ENUM RDRS_ATN_TXX_NCI_TECHNIQUE_DEFAULT{RDRS_ATN_TXX_NCI_TECHNIQUE_ENUM::NCI_TECH_1};
        static constexpr RDRS_ATN_TXX_PAE_STATUS_ENUM RDRS_ATN_TXX_PAE_STATUS_DEFAULT{RDRS_ATN_TXX_PAE_STATUS_ENUM::INVALID};
        static constexpr RDRS_ATN_TXX_PERF_TRK_RECOVERY_ENUM RDRS_ATN_TXX_PERF_TRK_RECOVERY_DEFAULT{RDRS_ATN_TXX_PERF_TRK_RECOVERY_ENUM::NO_ACTION};
        static constexpr RDRS_ATN_TXX_CLR_TO_JAM_STS_ENUM RDRS_ATN_TXX_CLR_TO_JAM_STS_DEFAULT{RDRS_ATN_TXX_CLR_TO_JAM_STS_ENUM::ENABLE};
        static constexpr RDRS_ATN_TXX_JAM_TO_CLR_STS_ENUM RDRS_ATN_TXX_JAM_TO_CLR_STS_DEFAULT{RDRS_ATN_TXX_JAM_TO_CLR_STS_ENUM::ENABLE};
        static constexpr RDRS_ATN_TXX_RAPID_RESP_STS_ENUM RDRS_ATN_TXX_RAPID_RESP_STS_DEFAULT{RDRS_ATN_TXX_RAPID_RESP_STS_ENUM::NOT_RAPID};

        //_______________________________________________________________//

        /**
         * @brief this topic is a strongly typed one to one mapping of Radar Status 2 - RADAR21-BRD-HAT-MESS-1 (ATN) from
         * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
         * DRL No:  1.17
         * Issue: A
         */
        class AirTrackNormalStatus : public Common::Status
        {

          uint8_t RDRS_ATN_TXX_ACHIEVED_POSREF{};
          RDRS_ATN_TXX_RAP_ATT_STATUS_ENUM RDRS_ATN_TXX_RAP_ATT_STATUS{};
          uint8_t RDRS_ATN_TXX_ACHIEVED_VELREF{};
          float RDRS_ATN_TXX_RES_REP_ACTUAL{};
          float RDRS_ATN_TXX_RES_REP_PRED_DES{};
          float RDRS_ATN_TXX_RES_REP_PRED_MIN{};
          float RDRS_ATN_TXX_RES_ANT_ACTUAL{};
          float RDRS_ATN_TXX_RES_ANT_PRED_DES{};
          float RDRS_ATN_TXX_RES_ANT_PRED_MIN{};
          RDRS_ATN_TXX_REC_TRK_DEL_ENUM RDRS_ATN_TXX_REC_TRK_DEL{};
          RDRS_ATN_TXX_NCI_STATUS_ENUM RDRS_ATN_TXX_NCI_STATUS{};
          RDRS_ATN_TXX_NCI_TECHNIQUE_ENUM RDRS_ATN_TXX_NCI_TECHNIQUE{};
          RDRS_ATN_TXX_PAE_STATUS_ENUM RDRS_ATN_TXX_PAE_STATUS{};
          Common::TXDISC_ENUM RDRS_ATN_TXX_TXDISC{};
          RDRS_ATN_TXX_PERF_TRK_RECOVERY_ENUM RDRS_ATN_TXX_PERF_TRK_RECOVERY{};
          RDRS_ATN_TXX_CLR_TO_JAM_STS_ENUM RDRS_ATN_TXX_CLR_TO_JAM_STS{};
          RDRS_ATN_TXX_JAM_TO_CLR_STS_ENUM RDRS_ATN_TXX_JAM_TO_CLR_STS{};
          RDRX_ATN_TXX_TYPE_TRANS_CTRL_ENUM RDRS_ATN_TXX_TRANS_CTRL_STS{};
          RDRS_ATN_TXX_RAPID_RESP_STS_ENUM RDRS_ATN_TXX_RAPID_RESP_STS{};

        public:

          //___________FIELD_GETTERS______________//

          /**
           * @brief getter for the RDRS_ATN_TXX_ACHIEVED_POSREF
           * @returns the RDRS_ATN_TXX_ACHIEVED_POSREF
           */
          inline uint8_t get_RDRS_ATN_TXX_ACHIEVED_POSREF() const {
            return RDRS_ATN_TXX_ACHIEVED_POSREF;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_RAP_ATT_STATUS
           * @returns the RDRS_ATN_TXX_RAP_ATT_STATUS
           */
          inline RDRS_ATN_TXX_RAP_ATT_STATUS_ENUM get_RDRS_ATN_TXX_RAP_ATT_STATUS() const {
            return RDRS_ATN_TXX_RAP_ATT_STATUS;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_ACHIEVED_VELREF
           * @returns the RDRS_ATN_TXX_ACHIEVED_VELREF
           */
          inline uint8_t get_RDRS_ATN_TXX_ACHIEVED_VELREF() const {
            return RDRS_ATN_TXX_ACHIEVED_VELREF;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_RES_REP_ACTUAL
           * @returns the RDRS_ATN_TXX_RES_REP_ACTUAL
           */
          inline float get_RDRS_ATN_TXX_RES_REP_ACTUAL() const {
            return RDRS_ATN_TXX_RES_REP_ACTUAL;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_RES_REP_PRED_DES
           * @returns the RDRS_ATN_TXX_RES_REP_PRED_DES
           */
          inline float get_RDRS_ATN_TXX_RES_REP_PRED_DES() const {
            return RDRS_ATN_TXX_RES_REP_PRED_DES;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_RES_REP_PRED_MIN
           * @returns the RDRS_ATN_TXX_RES_REP_PRED_MIN
           */
          inline float get_RDRS_ATN_TXX_RES_REP_PRED_MIN() const {
            return RDRS_ATN_TXX_RES_REP_PRED_MIN;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_RES_ANT_ACTUAL
           * @returns the RDRS_ATN_TXX_RES_ANT_ACTUAL
           */
          inline float get_RDRS_ATN_TXX_RES_ANT_ACTUAL() const {
            return RDRS_ATN_TXX_RES_ANT_ACTUAL;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_RES_ANT_PRED_DES
           * @returns the RDRS_ATN_TXX_RES_ANT_PRED_DES
           */
          inline float get_RDRS_ATN_TXX_RES_ANT_PRED_DES() const {
            return RDRS_ATN_TXX_RES_ANT_PRED_DES;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_RES_ANT_PRED_MIN
           * @returns the RDRS_ATN_TXX_RES_ANT_PRED_MIN
           */
          inline float get_RDRS_ATN_TXX_RES_ANT_PRED_MIN() const {
            return RDRS_ATN_TXX_RES_ANT_PRED_MIN;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_REC_TRK_DEL
           * @returns the RDRS_ATN_TXX_REC_TRK_DEL
           */
          inline RDRS_ATN_TXX_REC_TRK_DEL_ENUM get_RDRS_ATN_TXX_REC_TRK_DEL() const {
            return RDRS_ATN_TXX_REC_TRK_DEL;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_NCI_STATUS
           * @returns the RDRS_ATN_TXX_NCI_STATUS
           */
          inline RDRS_ATN_TXX_NCI_STATUS_ENUM get_RDRS_ATN_TXX_NCI_STATUS() const {
            return RDRS_ATN_TXX_NCI_STATUS;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_NCI_TECHNIQUE
           * @returns the RDRS_ATN_TXX_NCI_TECHNIQUE
           */
          inline RDRS_ATN_TXX_NCI_TECHNIQUE_ENUM get_RDRS_ATN_TXX_NCI_TECHNIQUE() const {
            return RDRS_ATN_TXX_NCI_TECHNIQUE;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_PAE_STATUS
           * @returns the RDRS_ATN_TXX_PAE_STATUS
           */
          inline RDRS_ATN_TXX_PAE_STATUS_ENUM get_RDRS_ATN_TXX_PAE_STATUS() const {
            return RDRS_ATN_TXX_PAE_STATUS;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_TXDISC
           * @returns the RDRS_ATN_TXX_TXDISC
           */
          inline Common::TXDISC_ENUM get_RDRS_ATN_TXX_TXDISC() const {
            return RDRS_ATN_TXX_TXDISC;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_PERF_TRK_RECOVERY
           * @returns the RDRS_ATN_TXX_PERF_TRK_RECOVERY
           */
          inline RDRS_ATN_TXX_PERF_TRK_RECOVERY_ENUM get_RDRS_ATN_TXX_PERF_TRK_RECOVERY() const {
            return RDRS_ATN_TXX_PERF_TRK_RECOVERY;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_CLR_TO_JAM_STS
           * @returns the RDRS_ATN_TXX_CLR_TO_JAM_STS
           */
          inline RDRS_ATN_TXX_CLR_TO_JAM_STS_ENUM get_RDRS_ATN_TXX_CLR_TO_JAM_STS() const {
            return RDRS_ATN_TXX_CLR_TO_JAM_STS;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_JAM_TO_CLR_STS
           * @returns the RDRS_ATN_TXX_JAM_TO_CLR_STS
           */
          inline RDRS_ATN_TXX_JAM_TO_CLR_STS_ENUM get_RDRS_ATN_TXX_JAM_TO_CLR_STS() const {
            return RDRS_ATN_TXX_JAM_TO_CLR_STS;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_TRANS_CTRL_STS
           * @returns the RDRS_ATN_TXX_TRANS_CTRL_STS
           */
          inline RDRX_ATN_TXX_TYPE_TRANS_CTRL_ENUM get_RDRS_ATN_TXX_TRANS_CTRL_STS() const {
            return RDRS_ATN_TXX_TRANS_CTRL_STS;
          }

          /**
           * @brief getter for the RDRS_ATN_TXX_RAPID_RESP_STS
           * @returns the RDRS_ATN_TXX_RAPID_RESP_STS
           */
          inline RDRS_ATN_TXX_RAPID_RESP_STS_ENUM get_RDRS_ATN_TXX_RAPID_RESP_STS() const {
            return RDRS_ATN_TXX_RAPID_RESP_STS;
          }

          //______________________________________//

          void setTaskType(const Common::CommandValidity &validity) noexcept override
          {
            if(validity == Common::CommandValidity::VALID)
            {
              TASK_TYPE = Common::WeaponSystemTaskType::AIR_TRACK_NORMAL;
            }
            else
            {
              TASK_TYPE = Common::WeaponSystemTaskType::INVALID_TYPE;
            }
          }
          
          //___________FIELD_SETTERS______________//

          virtual void setToIcdDefault() noexcept override
          {
            Status::setToIcdDefault();
            RDRS_ATN_TXX_ACHIEVED_POSREF = RDRS_ATN_TXX_ACHIEVED_POSREF_DEFAULT;
            RDRS_ATN_TXX_RAP_ATT_STATUS = RDRS_ATN_TXX_RAP_ATT_STATUS_DEFAULT;
            RDRS_ATN_TXX_ACHIEVED_VELREF = RDRS_ATN_TXX_ACHIEVED_VELREF_DEFAULT;
            RDRS_ATN_TXX_RES_REP_ACTUAL = RDRS_ATN_TXX_RES_REP_ACTUAL_DEFAULT;
            RDRS_ATN_TXX_RES_REP_PRED_DES = RDRS_ATN_TXX_RES_REP_PRED_DES_DEFAULT;
            RDRS_ATN_TXX_RES_REP_PRED_MIN = RDRS_ATN_TXX_RES_REP_PRED_MIN_DEFAULT;
            RDRS_ATN_TXX_RES_ANT_ACTUAL = RDRS_ATN_TXX_RES_ANT_ACTUAL_DEFAULT;
            RDRS_ATN_TXX_RES_ANT_PRED_DES = RDRS_ATN_TXX_RES_ANT_PRED_DES_DEFAULT;
            RDRS_ATN_TXX_RES_ANT_PRED_MIN = RDRS_ATN_TXX_RES_ANT_PRED_MIN_DEFAULT;
            RDRS_ATN_TXX_REC_TRK_DEL = RDRS_ATN_TXX_REC_TRK_DEL_DEFAULT;
            RDRS_ATN_TXX_NCI_STATUS = RDRS_ATN_TXX_NCI_STATUS_DEFAULT;
            RDRS_ATN_TXX_NCI_TECHNIQUE = RDRS_ATN_TXX_NCI_TECHNIQUE_DEFAULT;
            RDRS_ATN_TXX_PAE_STATUS = RDRS_ATN_TXX_PAE_STATUS_DEFAULT;
            RDRS_ATN_TXX_TXDISC = IcdDefaults::TXDISC_DEFAULT;
            RDRS_ATN_TXX_PERF_TRK_RECOVERY = RDRS_ATN_TXX_PERF_TRK_RECOVERY_DEFAULT;
            RDRS_ATN_TXX_CLR_TO_JAM_STS = RDRS_ATN_TXX_CLR_TO_JAM_STS_DEFAULT;
            RDRS_ATN_TXX_JAM_TO_CLR_STS = RDRS_ATN_TXX_JAM_TO_CLR_STS_DEFAULT;
            RDRS_ATN_TXX_TRANS_CTRL_STS = RDRX_ATN_TXX_TYPE_TRANS_CTRL_DEFAULT;
            RDRS_ATN_TXX_RAPID_RESP_STS = RDRS_ATN_TXX_RAPID_RESP_STS_DEFAULT;
          }

          Common::WeaponSystemTaskType getTaskType() const noexcept override
          {
            if(TASK_TYPE == Common::WeaponSystemTaskType::AIR_TRACK_NORMAL)
            {
              return Common::WeaponSystemTaskType::AIR_TRACK_NORMAL;
            }
            else
            {
              return Common::WeaponSystemTaskType::INVALID_TYPE;
            }
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_ACHIEVED_POSREF
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_ACHIEVED_POSREF(uint8_t arg) {
            RDRS_ATN_TXX_ACHIEVED_POSREF = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_RAP_ATT_STATUS
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_RAP_ATT_STATUS(RDRS_ATN_TXX_RAP_ATT_STATUS_ENUM arg) {
            RDRS_ATN_TXX_RAP_ATT_STATUS = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_ACHIEVED_VELREF
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_ACHIEVED_VELREF(uint8_t arg) {
            RDRS_ATN_TXX_ACHIEVED_VELREF = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_RES_REP_ACTUAL
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_RES_REP_ACTUAL(float arg) {
            RDRS_ATN_TXX_RES_REP_ACTUAL = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_RES_REP_PRED_DES
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_RES_REP_PRED_DES(float arg) {
            RDRS_ATN_TXX_RES_REP_PRED_DES = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_RES_REP_PRED_MIN
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_RES_REP_PRED_MIN(float arg) {
            RDRS_ATN_TXX_RES_REP_PRED_MIN = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_RES_ANT_ACTUAL
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_RES_ANT_ACTUAL(float arg) {
            RDRS_ATN_TXX_RES_ANT_ACTUAL = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_RES_ANT_PRED_DES
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_RES_ANT_PRED_DES(float arg) {
            RDRS_ATN_TXX_RES_ANT_PRED_DES = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_RES_ANT_PRED_MIN
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_RES_ANT_PRED_MIN(float arg) {
            RDRS_ATN_TXX_RES_ANT_PRED_MIN = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_REC_TRK_DEL
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_REC_TRK_DEL(RDRS_ATN_TXX_REC_TRK_DEL_ENUM arg) {
            RDRS_ATN_TXX_REC_TRK_DEL = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_NCI_STATUS
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_NCI_STATUS(RDRS_ATN_TXX_NCI_STATUS_ENUM arg) {
            RDRS_ATN_TXX_NCI_STATUS = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_NCI_TECHNIQUE
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_NCI_TECHNIQUE(RDRS_ATN_TXX_NCI_TECHNIQUE_ENUM arg) {
            RDRS_ATN_TXX_NCI_TECHNIQUE = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_PAE_STATUS
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_PAE_STATUS(RDRS_ATN_TXX_PAE_STATUS_ENUM arg) {
            RDRS_ATN_TXX_PAE_STATUS = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_TXDISC
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_TXDISC(Common::TXDISC_ENUM arg) {
            RDRS_ATN_TXX_TXDISC = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_PERF_TRK_RECOVERY
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_PERF_TRK_RECOVERY(RDRS_ATN_TXX_PERF_TRK_RECOVERY_ENUM arg) {
            RDRS_ATN_TXX_PERF_TRK_RECOVERY = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_CLR_TO_JAM_STS
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_CLR_TO_JAM_STS(RDRS_ATN_TXX_CLR_TO_JAM_STS_ENUM arg) {
            RDRS_ATN_TXX_CLR_TO_JAM_STS = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_JAM_TO_CLR_STS
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_JAM_TO_CLR_STS(RDRS_ATN_TXX_JAM_TO_CLR_STS_ENUM arg) {
            RDRS_ATN_TXX_JAM_TO_CLR_STS = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_TRANS_CTRL_STS
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_TRANS_CTRL_STS(RDRX_ATN_TXX_TYPE_TRANS_CTRL_ENUM arg) {
            RDRS_ATN_TXX_TRANS_CTRL_STS = arg;
          }

          /**
           * @brief setter for the RDRS_ATN_TXX_RAPID_RESP_STS
           * @param arg : the value to be set
           */
          inline void set_RDRS_ATN_TXX_RAPID_RESP_STS(RDRS_ATN_TXX_RAPID_RESP_STS_ENUM arg) {
            RDRS_ATN_TXX_RAPID_RESP_STS = arg;
          }


          //______________________________________//

          /**
           * @brief equality operator
           * @returns true if other contains the same values, false otherwise
           */
          bool operator==(const AirTrackNormalStatus& other) const 
          {
            return Status::operator==(other) &&
                   RDRS_ATN_TXX_ACHIEVED_POSREF == other.RDRS_ATN_TXX_ACHIEVED_POSREF &&
                   RDRS_ATN_TXX_RAP_ATT_STATUS == other.RDRS_ATN_TXX_RAP_ATT_STATUS &&
                   RDRS_ATN_TXX_ACHIEVED_VELREF == other.RDRS_ATN_TXX_ACHIEVED_VELREF &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ATN_TXX_RES_REP_ACTUAL, other.RDRS_ATN_TXX_RES_REP_ACTUAL) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ATN_TXX_RES_REP_PRED_DES, other.RDRS_ATN_TXX_RES_REP_PRED_DES) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ATN_TXX_RES_REP_PRED_MIN, other.RDRS_ATN_TXX_RES_REP_PRED_MIN) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ATN_TXX_RES_ANT_ACTUAL, other.RDRS_ATN_TXX_RES_ANT_ACTUAL) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ATN_TXX_RES_ANT_PRED_DES, other.RDRS_ATN_TXX_RES_ANT_PRED_DES) &&
                   SI::floatEqualityChecker::AlmostEqual(RDRS_ATN_TXX_RES_ANT_PRED_MIN, other.RDRS_ATN_TXX_RES_ANT_PRED_MIN) &&
                   RDRS_ATN_TXX_REC_TRK_DEL == other.RDRS_ATN_TXX_REC_TRK_DEL &&
                   RDRS_ATN_TXX_NCI_STATUS == other.RDRS_ATN_TXX_NCI_STATUS &&
                   RDRS_ATN_TXX_NCI_TECHNIQUE == other.RDRS_ATN_TXX_NCI_TECHNIQUE &&
                   RDRS_ATN_TXX_PAE_STATUS == other.RDRS_ATN_TXX_PAE_STATUS &&
                   RDRS_ATN_TXX_TXDISC == other.RDRS_ATN_TXX_TXDISC &&
                   RDRS_ATN_TXX_PERF_TRK_RECOVERY == other.RDRS_ATN_TXX_PERF_TRK_RECOVERY &&
                   RDRS_ATN_TXX_CLR_TO_JAM_STS == other.RDRS_ATN_TXX_CLR_TO_JAM_STS &&
                   RDRS_ATN_TXX_JAM_TO_CLR_STS == other.RDRS_ATN_TXX_JAM_TO_CLR_STS &&
                   RDRS_ATN_TXX_TRANS_CTRL_STS == other.RDRS_ATN_TXX_TRANS_CTRL_STS &&
                   RDRS_ATN_TXX_RAPID_RESP_STS == other.RDRS_ATN_TXX_RAPID_RESP_STS;
          }

          bool operator!=(const AirTrackNormalStatus &other) const
          {
            return !(*this == other);
          }

          /**
           * @brief Serialise function required for communications
           */
          template <class T>
          void Serialise(T &archive)
          {
            archive.Serialise(TASK_IDENT, "RDRS_TRK_TXX_TASK_IDENT");
            archive.Serialise(TASK_TYPE, "RDRS_TRK_TXX_TASK_TYPE");
            archive.Serialise(COND_MOD_STATUS, "RDRS_TRK_TXX_COND_MOD_STATUS");
            archive.Serialise(COND_STATE, "RDRS_TRK_TXX_COND_STATE");
            archive.Serialise(COND_SUSP_DETAIL, "RDRS_TRK_TXX_COND_SUSP_DETAIL");
            archive.Serialise(COND_MOD_TDI, "RDRS_TRK_TXX_COND_MOD_TDI");
            archive.Serialise(COND_REJECT_DETAIL, "RDRS_TRK_TXX_COND_REJECT_DETAIL");
            archive.Serialise(RDRS_ATN_TXX_ACHIEVED_POSREF, "RDRS_ATN_TXX_ACHIEVED_POSREF");
            archive.Serialise(RDRS_ATN_TXX_RAP_ATT_STATUS, "RDRS_ATN_TXX_RAP_ATT_STATUS");
            archive.Serialise(RDRS_ATN_TXX_ACHIEVED_VELREF, "RDRS_ATN_TXX_ACHIEVED_VELREF");
            archive.Serialise(RDRS_ATN_TXX_RES_REP_ACTUAL, "RDRS_ATN_TXX_RES_REP_ACTUAL");
            archive.Serialise(RDRS_ATN_TXX_RES_REP_PRED_DES, "RDRS_ATN_TXX_RES_REP_PRED_DES");
            archive.Serialise(RDRS_ATN_TXX_RES_REP_PRED_MIN, "RDRS_ATN_TXX_RES_REP_PRED_MIN");
            archive.Serialise(RDRS_ATN_TXX_RES_ANT_ACTUAL, "RDRS_ATN_TXX_RES_REP_ANT_ACTUAL");
            archive.Serialise(RDRS_ATN_TXX_RES_ANT_PRED_DES, "RDRS_ATN_TXX_RES_REP_ANT_PRED_DES");
            archive.Serialise(RDRS_ATN_TXX_RES_ANT_PRED_MIN, "RDRS_ATN_TXX_RES_REP_ANT_PRED_MIN");
            archive.Serialise(RDRS_ATN_TXX_REC_TRK_DEL, "RDRS_ATN_TXX_REC_TRK_DEL");
            archive.Serialise(RDRS_ATN_TXX_NCI_STATUS, "RDRS_ATN_TXX_NCI_STATUS");
            archive.Serialise(RDRS_ATN_TXX_NCI_TECHNIQUE, "RDRS_ATN_TXX_NCI_TECHNIQUE");
            archive.Serialise(RDRS_ATN_TXX_PAE_STATUS, "RDRS_ATN_TXX_PAE_STATUS");
            archive.Serialise(RDRS_ATN_TXX_TXDISC, "RDRS_ATN_TXX_TXDISC");
            archive.Serialise(RDRS_ATN_TXX_PERF_TRK_RECOVERY, "RDRS_ATN_TXX_PERF_TRK_RECOVERY");
            archive.Serialise(RDRS_ATN_TXX_CLR_TO_JAM_STS, "RDRS_ATN_TXX_CLR_TO_JAM_STS");
            archive.Serialise(RDRS_ATN_TXX_JAM_TO_CLR_STS, "RDRS_ATN_TXX_JAM_TO_CLR_STS");
            archive.Serialise(RDRS_ATN_TXX_TRANS_CTRL_STS, "RDRS_ATN_TXX_TRANS_CTRL_STS");
            archive.Serialise(RDRS_ATN_TXX_RAPID_RESP_STS, "RDRS_ATN_TXX_RAPID_RESP_STS");
            archive.Serialise(ACTUAL_TDI, "RDRS_TRK_TXX_TDI");
          }

          LCA_TOPIC("AirTrackNormalStatus", 1, 0)
        };

      } // namespace AirTrack
    }   // namespace WeaponSystem
  }     // namespace EcrsMK2

} // namespace Topics

#endif