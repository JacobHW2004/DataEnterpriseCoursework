#ifndef SEARCH_NORMAL_ELECTRONIC_STATUS_TOPIC_H
#define SEARCH_NORMAL_ELECTRONIC_STATUS_TOPIC_H
#include <string>
#include <stdint.h>
#include "Fabric/Utils/LCA_Macros.h"
#include "Status.h"
#include "VolumeArea.h"
#include "SurfaceSearchNormalElectronic.h"

namespace Topics 
{
    namespace EcrsMK2
    {
        namespace WeaponSystem
        {
            namespace SurfaceSearch
            {

                enum class RDRS_ESSN_X_ACT_SPATIAL_ENUM : uint8_t {
                    RDRS_SPAT_ESSC_AIRCRAFT = 0x00,
                    RDRS_SPAT_ESSC_GEO = 0x01,
                    RDRS_SPAT_ESSC_INVALID = 0x02,
                    RDRS_SPAT_ESSC_RIDE_SSC = 0x03,
                    RDRS_SPAT_ESSC_RIDE_SAC = 0x04,
                };


                enum class EMPLOYED_ENUM : uint8_t {
                    NOT_FULLY_EMPLOYED_IN_RSS = 0x00,
                    FULLY_EMPLOYED_IN_RSS = 0x01
                };

                static constexpr uint8_t RDRS_ESSN_X_ACHIEVED_PCT_DEFAULT { 0 };
                static constexpr double RDRS_ESSN_X_RES_REP_ACTUAL_DEFAULT { 0 };
                static constexpr double RDRS_ESSN_X_RES_REP_PRED_DES_DEFAULT { 0 };
                static constexpr double RDRS_ESSN_X_RES_REP_PRED_MIN_DEFAULT { 0 };
                static constexpr double RDRS_ESSN_X_RES_ANT_ACTUAL_DEFAULT { 0 };
                static constexpr double RDRS_ESSN_X_RES_ANT_PRED_DES_DEFAULT { 0 };
                static constexpr double RDRS_ESSN_X_RES_ANT_PRED_MIN_DEFAULT { 0 };
                static constexpr uint8_t RDRS_ESSN_X_RSS_REF_DEFAULT{ 0 };
                static constexpr RDRS_ESSN_X_ACT_SPATIAL_ENUM RDRS_ESSN_X_ACT_SPATIAL_DEFAULT { RDRS_ESSN_X_ACT_SPATIAL_ENUM::RDRS_SPAT_ESSC_AIRCRAFT };
                static constexpr bool RDRS_ESSN_X_EMXX_DEFAULT { false };
                static constexpr EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_NO_ES_DEFAULT { EMPLOYED_ENUM::NOT_FULLY_EMPLOYED_IN_RSS };
                static constexpr EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_SEARCHING_DEFAULT { EMPLOYED_ENUM::NOT_FULLY_EMPLOYED_IN_RSS };
                static constexpr EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_TRACKING_DEFAULT { EMPLOYED_ENUM::NOT_FULLY_EMPLOYED_IN_RSS };
                static constexpr EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_JAMMING_DEFAULT { EMPLOYED_ENUM::NOT_FULLY_EMPLOYED_IN_RSS };
                static constexpr EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_MISSILE_DEFAULT { EMPLOYED_ENUM::NOT_FULLY_EMPLOYED_IN_RSS };
                static constexpr uint16_t RDRS_ESSN_X_EMXX_TYPE_INDEX_DEFAULT { 0};
                static constexpr uint8_t RDRS_ESSN_X_DWELL_MEASURE_DEFAULT { 0 };
                static constexpr uint8_t RDRS_ESSN_X_DWELL_DURATION_DEFAULT { 0};
                static constexpr uint8_t RDRS_ESSN_X_RATIO_DMT_ACT_DEFAULT { 0};
                static constexpr uint8_t RDRS_ESSN_X_PROG_ACT_VOL_DEFAULT { 0};
                static constexpr uint8_t RDRS_ESSN_X_TIME_TO_COMP_ITER_DEFAULT { 0};
                static constexpr bool RDRC_ESSN_X_SMALLER_THAN_BEAM_DEFAULT { false };
                static constexpr uint8_t RDRC_ESSN_X_FRAME_COUNT_DEFAULT { false };
                /**
                * @brief this topic is a strongly typed one to one mapping of Radar Status 2 - RADAR21-BRD-HAT-MESS-1 (SNE - status Aircraft Referenced vairant only) from
                * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
                * DRL No:  1.17
                * Issue: A
                */
                class SearchNormalElectronicStatusTopic : public Common::Status,
                                                            public Common::VolumeArea,
                                                            public SurfaceSearchNormalElectronic
                {

                    //____________________DEFAULT_MESSAGE_VALUES____________________//
                    // Default values are defined within the ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
                
                    //_______________________________________________________________//
                    public:

                    uint8_t RDRS_ESSN_X_ACHIEVED_PCT { RDRS_ESSN_X_ACHIEVED_PCT_DEFAULT };
                    double RDRS_ESSN_X_RES_REP_ACTUAL { RDRS_ESSN_X_RES_REP_ACTUAL_DEFAULT };
                    double RDRS_ESSN_X_RES_REP_PRED_DES { RDRS_ESSN_X_RES_REP_PRED_DES_DEFAULT };
                    double RDRS_ESSN_X_RES_REP_PRED_MIN { RDRS_ESSN_X_RES_REP_PRED_MIN_DEFAULT };
                    double RDRS_ESSN_X_RES_ANT_ACTUAL { RDRS_ESSN_X_RES_ANT_ACTUAL_DEFAULT };
                    double RDRS_ESSN_X_RES_ANT_PRED_DES { RDRS_ESSN_X_RES_ANT_PRED_DES_DEFAULT };
                    double RDRS_ESSN_X_RES_ANT_PRED_MIN { RDRS_ESSN_X_RES_ANT_PRED_MIN_DEFAULT };
                    RDRS_ESSN_X_ACT_SPATIAL_ENUM RDRS_ESSN_X_ACT_SPATIAL { RDRS_ESSN_X_ACT_SPATIAL_DEFAULT };
                    EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_NO_ES { RDRS_ESSN_X_EMXX_ACT_NO_ES_DEFAULT };
                    EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_SEARCHING { RDRS_ESSN_X_EMXX_ACT_SEARCHING_DEFAULT };
                    EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_TRACKING { RDRS_ESSN_X_EMXX_ACT_TRACKING_DEFAULT };
                    EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_JAMMING { RDRS_ESSN_X_EMXX_ACT_JAMMING_DEFAULT };
                    EMPLOYED_ENUM RDRS_ESSN_X_EMXX_ACT_MISSILE { RDRS_ESSN_X_EMXX_ACT_MISSILE_DEFAULT };
                    SI::SISecond RDRS_ESSN_X_DWELL_MEASURE { RDRS_ESSN_X_DWELL_MEASURE_DEFAULT };
                    SI::SISecond RDRS_ESSN_X_DWELL_DURATION { RDRS_ESSN_X_DWELL_DURATION_DEFAULT };
                    uint8_t RDRS_ESSN_X_RATIO_DMT_ACT { RDRS_ESSN_X_RATIO_DMT_ACT_DEFAULT };
                    uint8_t RDRS_ESSN_X_PROG_ACT_VOL { RDRS_ESSN_X_PROG_ACT_VOL_DEFAULT };
                    uint8_t RDRS_ESSN_X_TIME_TO_COMP_ITER { RDRS_ESSN_X_TIME_TO_COMP_ITER_DEFAULT };
                    bool RDRC_ESSN_X_SMALLER_THAN_BEAM { RDRC_ESSN_X_SMALLER_THAN_BEAM_DEFAULT };
                    uint8_t RDRC_ESSN_X_FRAME_COUNT { RDRC_ESSN_X_FRAME_COUNT_DEFAULT };


                        bool operator==(const SearchNormalElectronicStatusTopic& other) const {
                            return this->RDRS_ESSN_X_ACHIEVED_PCT == other.RDRS_ESSN_X_ACHIEVED_PCT &&
                                    this->RDRS_ESSN_X_RES_REP_ACTUAL == other.RDRS_ESSN_X_RES_REP_ACTUAL &&
                                    this->RDRS_ESSN_X_RES_REP_PRED_DES == other.RDRS_ESSN_X_RES_REP_PRED_DES &&
                                    this->RDRS_ESSN_X_RES_REP_PRED_MIN == other.RDRS_ESSN_X_RES_REP_PRED_MIN &&
                                    this->RDRS_ESSN_X_RES_ANT_ACTUAL == other.RDRS_ESSN_X_RES_ANT_ACTUAL &&
                                    this->RDRS_ESSN_X_RES_ANT_PRED_DES == other.RDRS_ESSN_X_RES_ANT_PRED_DES &&
                                    this->RDRS_ESSN_X_RES_ANT_PRED_MIN == other.RDRS_ESSN_X_RES_ANT_PRED_MIN &&
                                    this->RDRS_ESSN_X_EMXX_ACT_NO_ES == other.RDRS_ESSN_X_EMXX_ACT_NO_ES &&
                                    this->RDRS_ESSN_X_EMXX_ACT_SEARCHING == other.RDRS_ESSN_X_EMXX_ACT_SEARCHING &&
                                    this->RDRS_ESSN_X_EMXX_ACT_TRACKING == other.RDRS_ESSN_X_EMXX_ACT_TRACKING &&
                                    this->RDRS_ESSN_X_EMXX_ACT_JAMMING == other.RDRS_ESSN_X_EMXX_ACT_JAMMING &&
                                    this->RDRS_ESSN_X_EMXX_ACT_MISSILE == other.RDRS_ESSN_X_EMXX_ACT_MISSILE &&
                                    this->RDRS_ESSN_X_DWELL_MEASURE == other.RDRS_ESSN_X_DWELL_MEASURE &&
                                    this->RDRS_ESSN_X_DWELL_DURATION == other.RDRS_ESSN_X_DWELL_DURATION &&
                                    this->RDRS_ESSN_X_RATIO_DMT_ACT == other.RDRS_ESSN_X_RATIO_DMT_ACT &&
                                    this->RDRS_ESSN_X_PROG_ACT_VOL == other.RDRS_ESSN_X_PROG_ACT_VOL &&
                                    this->RDRS_ESSN_X_TIME_TO_COMP_ITER == other.RDRS_ESSN_X_TIME_TO_COMP_ITER &&
                                    this->RDRC_ESSN_X_SMALLER_THAN_BEAM == other.RDRC_ESSN_X_SMALLER_THAN_BEAM &&
                                    this->RDRC_ESSN_X_FRAME_COUNT == other.RDRC_ESSN_X_FRAME_COUNT &&
                                    SurfaceSearchNormalElectronic::operator== (other) &&
                                    Common::VolumeArea::operator== (other) &&
                                    Common::Status::operator==(other);
                        }

                        bool operator!=(const SearchNormalElectronicStatusTopic& other) const {
                            return !(*this == other);
                        }

                        void setTaskType(const Common::CommandValidity& validity) noexcept override
                        {
                            TASK_TYPE = validity == Common::CommandValidity::VALID ?
                                Topics::EcrsMK2::WeaponSystem::Common::WeaponSystemTaskType::ELECT_SURFACE_SEARCH_NORMAL : Topics::EcrsMK2::WeaponSystem::Common::WeaponSystemTaskType::INVALID_TYPE;
                        }

                        /**
                        * @brief Serialise function required for communications
                        */
                        template <class T>
                        void Serialise(T& archive) 
                        {
                            double AZ_CNTR {CenterLine()};
                            double AZ_HALF {AzHalfwidth()};
                            double PLAN_MIN {PlanMin()};
                            double PLAN_MAX {PlanMax()};
                            double dwellMeasure{RDRS_ESSN_X_DWELL_MEASURE()};
                            double dwellDuration{RDRS_ESSN_X_DWELL_DURATION()};
                            archive.Serialise(RDRS_ESSN_X_ACHIEVED_PCT, "RDRS_ESSN_X_ACHIEVED_PCT");
                            archive.Serialise(RDRS_ESSN_X_RES_REP_ACTUAL, "RDRS_ESSN_X_RES_REP_ACTUAL");
                            archive.Serialise(RDRS_ESSN_X_RES_REP_PRED_DES, "RDRS_ESSN_X_RES_REP_PRED_DES");
                            archive.Serialise(RDRS_ESSN_X_RES_REP_PRED_MIN, "RDRS_ESSN_X_RES_REP_PRED_MIN");
                            archive.Serialise(RDRS_ESSN_X_RES_ANT_ACTUAL, "RDRS_ESSN_X_RES_ANT_ACTUAL");
                            archive.Serialise(RDRS_ESSN_X_RES_ANT_PRED_DES, "RDRS_ESSN_X_RES_ANT_PRED_DES");
                            archive.Serialise(RDRS_ESSN_X_RES_ANT_PRED_MIN, "RDRS_ESSN_X_RES_ANT_PRED_MIN");
                            archive.Serialise(AXISTYPE, "AXISTYPE");
                            archive.Serialise(INDEX_VALID, "INDEX_VALID");
                            archive.Serialise(RDRS_ESSN_X_EMXX_ACT_NO_ES, "RDRS_ESSN_X_EMXX_ACT_NO_ES");
                            archive.Serialise(RDRS_ESSN_X_EMXX_ACT_SEARCHING, "RDRS_ESSN_X_EMXX_ACT_SEARCHING");
                            archive.Serialise(RDRS_ESSN_X_EMXX_ACT_TRACKING, "RDRS_ESSN_X_EMXX_ACT_TRACKING");
                            archive.Serialise(RDRS_ESSN_X_EMXX_ACT_JAMMING, "RDRS_ESSN_X_EMXX_ACT_JAMMING");
                            archive.Serialise(RDRS_ESSN_X_EMXX_ACT_MISSILE, "RDRS_ESSN_X_EMXX_ACT_MISSILE");
                            archive.Serialise(dwellMeasure, "RDRS_ESSN_X_DWELL_MEASURE");
                            archive.Serialise(dwellDuration, "RDRS_ESSN_X_DWELL_DURATION");
                            archive.Serialise(RDRS_ESSN_X_RATIO_DMT_ACT, "RDRS_ESSN_X_RATIO_DMT_ACT");
                            archive.Serialise(RDRS_ESSN_X_PROG_ACT_VOL, "RDRS_ESSN_X_PROG_ACT_VOL");
                            archive.Serialise(RDRS_ESSN_X_TIME_TO_COMP_ITER, "RDRS_ESSN_X_TIME_TO_COMP_ITER");
                            archive.Serialise(RDRC_ESSN_X_SMALLER_THAN_BEAM, "RDRC_ESSN_X_SMALLER_THAN_BEAM");
                            archive.Serialise(RDRC_ESSN_X_FRAME_COUNT, "RDRC_ESSN_X_FRAME_COUNT");
                            archive.Serialise(TASK_IDENT, "TASK_IDENT");
                            archive.Serialise(TASK_TYPE, "TASK_TYPE");
                            archive.Serialise(COND_MOD_STATUS, "COND_MOD_STATUS");
                            archive.Serialise(COND_STATE, "COND_STATE");
                            archive.Serialise(COND_SUSP_DETAIL, "COND_SUSP_DETAIL");
                            archive.Serialise(COND_MOD_TDI, "COND_MOD_TDI");
                            archive.Serialise(COND_REJECT_DETAIL, "COND_REJECT_DETAIL");
                            archive.Serialise(ACTUAL_TDI, "ACTUAL_TDI");
                            archive.Serialise(AZ_CNTR, "RDRC_ESSN_AC_AZ_CNTR"); 
                            archive.Serialise(AZ_HALF, "RDRC_ESSN_AC_AZ_HALF"); 
                            archive.Serialise(PLAN_MIN, "RDRC_ESSN_AC_PLAN_MIN"); 
                            archive.Serialise(PLAN_MAX, "RDRC_ESSN_AC_PLAN_MAX"); 
                            archive.Serialise(RSS_REF, "RSS_REF");
                            archive.Serialise(SPATIAL, "SPATIAL");
                            archive.Serialise(PAT_T, "PAT_T");
                            archive.Serialise(PAT_D, "PAT_D");
                            archive.Serialise(PAT_I, "PAT_I");
                            archive.Serialise(ON_DETECT_TRACKING, "ON_DETECT_TRACKING");
                            archive.Serialise(ON_UNLISTED_REALM, "ON_UNLISTED_REALM");
                            archive.Serialise(RSS_SOURCE, "RSS_SOURCE");
                            archive.Serialise(NO_ES, "NO_ES");
                            archive.Serialise(ES_SEARCHING, "ES_SEARCHING");
                            archive.Serialise(ES_TRACKING, "ES_TRACKING");
                            archive.Serialise(ES_JAMMING, "ES_JAMMING");
                            archive.Serialise(ES_MISSILE, "ES_MISSILE");
                            archive.Serialise(TYPE_INDEX, "TYPE_INDEX");
                            CenterLine = AZ_CNTR; 
                            AzHalfwidth = AZ_HALF; 
                            PlanMin = PLAN_MIN; 
                            PlanMax = PLAN_MAX; 
                            RDRS_ESSN_X_DWELL_MEASURE = dwellMeasure; 
                            RDRS_ESSN_X_DWELL_DURATION = dwellDuration; 
                        }
                        LCA_TOPIC("SearchNormalElectronicStatusTopic", 1, 0)
                };
            } // namespace SurfaceSearch      
        } // namespace WeaponSystem
    } // namespace EcrsMK2
}  // namespace Topics

#endif