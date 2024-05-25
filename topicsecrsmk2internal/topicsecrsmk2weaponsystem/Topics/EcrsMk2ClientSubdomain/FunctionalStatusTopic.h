#ifndef FUNCTIONALSTATUSTOPIC_H
#define FUNCTIONALSTATUSTOPIC_H

#include "Fabric/Utils/LCA_Macros.h"


namespace Topics {

    namespace EcrsMK2
    {
        namespace WarmUP
        {
            enum class RDRS_F_RADAR_VARIANT_ENUM : uint8_t
            {
                INVALID,
                MSCAN_TBM = 0x30,
                ESCAN_MK0 = 0x83,
                ESCAN_MK1 = 0x8C,
                ESCAN_MK2 = 0xB0
            };
            enum class RDRS_F_PRIMARY_STATE_ENUM : uint8_t
            {
                INVALID,
                WARM_UP=0x3,
                OPERATE=0x5,
                STANDBY=0x9,
                ALERT_STANDBY=0xC,
                FORCED_STANDBY=0xF,
                MD_SWITCH=0xF,
                SHUTDOWN_IN_PROGRESS=0x14,
                SHUTDOWN_WAITING_FOR_REPO=0x17,
                SHUTDOWN_UNSUCCESSFUL=0x18,
                SHUTDOWN_SUCCESSFUL=0x1B,
                IBIT_IN_PROGRESS=0x1D,
                IBIT_CANCELLING=0x1E
            };
            enum class RDRS_F_PBIT_IBIT_REDUCED_FUNC_ENUM : uint8_t
            {
                FULL,
                REDUCED
            };
        }
    }


    /**
    * @brief this topic is a strongly typed one to one mapping of Functional Status from Radar Status 2
    * This is currently an MVP solution to allow integration with the Weapon System Simulator
    */
    struct FunctionalStatusTopic {

        uint8_t RDRS_F_RADAR_VARIANT{ 0 };
        uint8_t RDRS_F_PRIMARY_STATE{ 0 };
        uint8_t RDRS_F_WOW_STATUS{ 0 };
        uint8_t RDRS_F_WOW_INPUT{ 0 };
        uint8_t RDRS_F_WOW_INTERAL{ 0 };
        uint8_t RDRS_F_FSB_RECOVERABLE{ 0 };
        uint16_t RDRS_F_FORCED_STBY_CODE{ 0 };
        uint8_t RDRS_F_WS_CMD_ERROR{ 0 };
        uint8_t RDRS_F_STBY_NO_COOL_STATUS{ 0 };
        uint8_t RDRS_F_LIQUID_COOLING_RB{ 0 };
        uint8_t RDRS_F_RADAR_ALERT_ACK{ 0 };
        uint8_t RDRS_F_RADAR_SD_PRE_WRN{ 0 };
        uint8_t RDRS_F_RADAR_THERM_OVRD_STATE{ 0 };
        uint8_t RDRS_F_RDRS_F_CP_THRESHOLD{ 0 };
        uint8_t RDRS_F_CP_OVERRIDE_RB{ 0 };
        uint8_t RDRS_F_BELOW_DERATING_STATE{ 0 };
        uint8_t RDRS_F_LOADSHED_CMD_STS{ 0 };
        uint8_t RDRS_F_POWER_RESTRICTION{ 0 };
        uint8_t RDRS_F_SHUTDOWN_STATE{ 0 };
        uint8_t RDRS_F_ANT_RESET_STATE{ 0 };
        uint8_t RDRS_F_AAU_RESET_STATE{ 0 };
        uint8_t RDRS_F_APSC_RESET_STATE{ 0 };
        uint8_t RDRS_F_RXR_RESET_STATE{ 0 };
        uint8_t RDRS_F_RADAR_RXR_OT{ 0 };
        uint8_t RDRS_F_RADAR_APSC_OT{ 0 };
        uint8_t RDRS_F_RADAR_AAU_OT{ 0 };
        uint8_t RDRS_F_RADAR_PXR_OT{ 0 };
        uint8_t RDRS_F_RADAR_ANT_OT{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_01{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_02{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_03{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_04{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_05{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_06{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_07{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_08{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_09{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_10{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_11{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_12{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_13{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_14{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_15{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_16{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_17{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_18{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_19{ 0 };
        uint8_t RDRS_F_CAP_GS_TASK_20{ 0 };
        uint8_t RDRS_F_CAP_GS_FUNC_01{ 0 };
        uint8_t RDRS_F_CAP_GS_FUNC_02{ 0 };
        uint8_t RDRS_F_CAP_GS_FUNC_03{ 0 };
        uint8_t RDRS_F_CAP_GS_FUNC_04{ 0 };
        uint8_t RDRS_F_CAP_GS_FUNC_05{ 0 };
        uint8_t RDRS_F_CAP_GS_FUNC_06{ 0 };
        uint8_t RDRS_F_CAP_GS_FUNC_07{ 0 };
        uint8_t RDRS_F_RECONFIG_REQUEST{ 0 };
        uint8_t RDRS_F_SNG_EVENT_UPSET_REC_REQ{ 0 };
        uint8_t RDRS_F_PBIT_IBIT_REDUCED_FUNC{ 0 };
        uint8_t RDRS_F_TYPE_REQUEST_RB{ 0 };
        uint8_t RDRS_F_PBIT_TYPE_REQUEST{ 0 };
        uint8_t RDRS_F_FAST_RESP_PBIT_RB{ 0 };
        uint8_t RDRS_F_FAST_RESP_PBIT_STS{ 0 };
        uint8_t RDRS_F_PBIT_SUSPENDED{ 0 };
        uint8_t PBIT_SUSP_FAIL_DET{ 0 };
        uint8_t RDRS_F_WARM_UP_RUN_TIME{ 0 };
        uint8_t RDRS_F_VIDEO_SYNC_STS_PBIT{ 0 };
        uint8_t RDRS_F_RDR_PBIT_RESULT{ 0 };
        uint8_t RDRS_F_RDR_CBIT_RESULT{ 0 };
        uint8_t RDRS_F_VIDEO_SYNC_STS{ 0 };
        uint8_t RDRS_F_IBIT_TYPE_REQUEST_RB{ 0 };
        uint8_t RDRS_F_IBIT_TYPE_REQUEST_STS{ 0 };
        uint8_t RDRS_F_IBIT_RESULT{ 0 };
        uint8_t RDRS_F_VIDEO_SYNC_STS_IBIT{ 0 };
        uint8_t RDRS_F_RDR_PBIT_IDENT{ 0 };
        uint16_t RDRS_F_RDR_FAILURE_IDENT_CODE3{ 0 };
        uint8_t RDRS_F_BIT_FAILED_ITEM_ID_1{ 0 };
        uint8_t RDRS_F_BIT_FAILED_ITEM_ID_2{ 0 };
        uint8_t RDRS_F_BIT_FAILED_ITEM_ID_3{ 0 };
        uint8_t RDRS_F_VIS_CAL_TEST{ 0 };
        uint8_t RDRS_F_VIS_CBIT_TEST{ 0 };
        uint8_t RDRS_F_SIP_CHKSUM_ERROR_TEST{ 0 };
        uint8_t RDRS_F_COP_SYNTHETIC_TGT_TEST{ 0 };
        uint8_t RDRS_F_DAP_VELOCITY_VAL_TEST{ 0 };
        uint8_t RDRS_F_DAP_FORMAT_CONV_TEST{ 0 };
        uint8_t RDRS_F_DAP_TGT_QUALITY_TEST{ 0 };
        uint8_t RDRS_F_DAP_OUTPUT_CHKSUM_TEST{ 0 };
        uint8_t RDRS_F_SIP_TGT_CHKSUM_TEST{ 0 };
        uint8_t RDRS_F_CORE_TRANSMISSION_TEST{ 0 };
        uint8_t RDRS_F_SIP_MD_BLOCK_CHKSUM_TEST{ 0 };
        uint8_t RDRS_F_RADAR_GLOBAL_PASS_SELC{ 0 };
        uint8_t RDRS_F_RADAR_STEALTH_STATE{ 0 };
        uint8_t RDRS_F_ANT_POS_OVRD_STATE{ 0 };
        uint16_t RDRS_F_ANT_PARK_POS_RB{ 0 };
        uint8_t RDRS_F_TDEL_S_ACTUAL{ 0 };
        uint8_t RDRS_F_TDEL_A_ACTUAL{ 0 };
        uint8_t RDRS_F_MAX_PMTD_SURFACE_TRKS{ 0 };
        uint8_t RDRS_F_DEL_RADAR_TRACKS{ 0 };
        uint8_t RDRS_F_TRK_DEL_RULES_SEA_STS{ 0 };
        uint8_t RDRS_F_TRK_DEL_RULES_LAND_STS{ 0 };
        uint8_t RDRS_F_CLTR_NOTCH_STS{ 0 };
        uint16_t RDRS_F_CLTR_NOTCH_WIDTH_ACTUAL{ 0 };
        uint8_t RDRS_F_INHIBIT_REC_STATUS{ 0 };
        uint8_t RDRS_F_CACQ_STATUS{ 0 };
        uint8_t RDRS_F_IFF_TYPE2_OUTPUT_STATUS{ 0 };
        uint8_t RDRS_F_PLOT_DATA_OUTPUT_STATUS{ 0 };
        uint8_t RDRS_F_PLOT_DATA_DET_STATUS{ 0 };
        uint8_t RDRS_F_PLOT_DATA_AGE_SELC{ 0 };
        uint8_t RDRS_F_TIP_INSTALLED{ 0 };
        uint8_t RDRS_F_TIP_CNTL_METHOD_STS{ 0 };
        uint8_t RDRS_F_TIP_REC_DATA_STS{ 0 };
        uint8_t RDRS_F_TIP_DATA_REC_MODE_STS{ 0 };
        uint8_t RDRS_F_TIP_REC_CAP_RESET_STS{ 0 };
        uint8_t RDRS_F_TIP_HEALTH_STS{ 0 };
        uint8_t RDRS_F_TIP_CAPACITY_REMAIN{ 0 };
        uint8_t RDRS_F_RF_AGILITY_STS{ 0 };
        uint8_t RDRS_F_ADAPTIVE_OP_SELECT_STS{ 0 };
        uint8_t RDRS_F_ADAPTIVE_OP_VARIANT_STS{ 0 };
        uint8_t RDRS_F_EPM_ENABLE_STS{ 0 };
        uint8_t RDRS_F_PAE_ENABLE_STS{ 0 };
        uint8_t RDRS_F_SPOKES_ENABLE_STS{ 0 };
        uint8_t RDRS_F_AIR_CLR_TO_JAM_STS{ 0 };
        uint8_t RDRS_F_AIR_JAM_TO_CLR_STS{ 0 };
        uint8_t RDRS_F_SURF_CLR_TO_JAM_STS{ 0 };
        uint8_t RDRS_F_SURF_JAM_TO_CLR_STS{ 0 };
        uint8_t RDRS_F_SIDELOBE_JAMMED{ 0 };
        uint16_t RDRS_F_AUTO_PAE_RES_LIMIT_STS{ 0 };
        uint8_t RDRS_F_KR_RP_STATUS{ 0 };
        uint8_t RDRS_F_PPM_OVRD_STATE{ 0 };
        uint8_t RDRS_F_PPM_VALUE{ 0 };
        uint8_t RDRS_F_RADAR_AS_WP_POSN_UPDATE{ 0 };
        uint32_t RDRS_F_RADAR_AS_WP_LATITUDE{ 0 };
        uint32_t RDRS_F_RADAR_AS_WP_LONGITUDE{ 0 };
        uint8_t RDRS_F_MISSILE_CH_SELC_SLOT1{ 0 };
        uint8_t RDRS_F_MISSILE_CH_SELC_SLOT2{ 0 };
        uint8_t RDRS_F_MISSILE_CH_SELC_SLOT3{ 0 };
        uint8_t RDRS_F_MISSILE_CH_SELC_SLOT4{ 0 };
        uint8_t RDRS_F_MISSILE_CH_SELC_SLOT5{ 0 };
        uint8_t RDRS_F_MISSILE_CH_SELC_SLOT6{ 0 };
        uint8_t RDRS_F_FCS_HARMO_DATA_LIMITED{ 0 };
        uint8_t RDRS_F_FCS_HARMO_DATA_VALID{ 0 };
        uint8_t RDRS_F_HARMO_DATA_STATUS{ 0 };
        uint8_t RDRS_F_HARMO_CHKSUM_STS{ 0 };
        uint8_t RDRS_F_TQ_TABLES_STATUS_VALID{ 0 };
        uint8_t RDRS_F_DEFAULT_TQ_TABLES_STATE{ 0 };
        uint8_t RDRS_F_LOADED_TQ_TABLES_STATE{ 0 };
        uint8_t RDRS_F_DEFAULT_TQ_TABLE_ID{ 0 };
        uint8_t RDRS_F_DEFAULT_TQ_TABLE_VER{ 0 };
        uint32_t RDRS_F_DEFAULT_TQ_TABLE_CRC{ 0 };
        uint8_t RDRS_F_LOADED_TQ_TABLE_ID{ 0 };
        uint8_t RDRS_F_LOADED_TQ_TABLE_VER{ 0 };
        uint32_t RDRS_F_LOADED_TQ_TABLE_CRC{ 0 };
        uint8_t RDRS_F_INVALID_TQ_TABLE_CMD{ 0 };
        uint8_t RDRS_F_TQ_TABLE_IN_USE{ 0 };
        uint8_t RDRS_F_IFF_PERF_TABLE_IN_USE{ 0 };
        uint8_t RDRS_F_NCI_TEMPLATE_IN_USE{ 0 };
        uint8_t RDRS_F_LOADED_IFF_TABLE_ID{ 0 };
        uint8_t RDRS_F_LOADED_IFF_TABLE_VER{ 0 };
        uint8_t RDRS_F_LOADED_NCI_TEMPLATE_ID{ 0 };
        uint8_t RDRS_F_LOADED_NCI_TEMPLATE_VER{ 0 };
        uint8_t RDRS_F_RES_UTIL_CALC_PERIOD_RB{ 0 };
        uint8_t RDRS_F_RES_UTIL_CALC_MODE{ 0 };
        uint32_t RDRS_F_TASK_RNK_OVRD_RB{ 0 };
        uint8_t RDRS_F_GAMMA_TBL_UPDATE_COUNT{ 0 };

        /**
        * @brief Serialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {
        archive.Serialise( RDRS_F_RADAR_VARIANT, "RDRS_F_RADAR_VARIANT");
        archive.Serialise( RDRS_F_PRIMARY_STATE, "RDRS_F_PRIMARY_STATE");
        archive.Serialise( RDRS_F_WOW_STATUS, "RDRS_F_WOW_STATUS");
        archive.Serialise( RDRS_F_WOW_INPUT, "RDRS_F_WOW_INPUT");
        archive.Serialise( RDRS_F_WOW_INTERAL, "RDRS_F_WOW_INTERAL");
        archive.Serialise( RDRS_F_FSB_RECOVERABLE, "RDRS_F_FSB_RECOVERABLE");
        archive.Serialise( RDRS_F_FORCED_STBY_CODE, "RDRS_F_FORCED_STBY_CODE");
        archive.Serialise( RDRS_F_WS_CMD_ERROR, "RDRS_F_WS_CMD_ERROR");
        archive.Serialise( RDRS_F_STBY_NO_COOL_STATUS, "RDRS_F_STBY_NO_COOL_STATUS");
        archive.Serialise( RDRS_F_LIQUID_COOLING_RB, "RDRS_F_LIQUID_COOLING_RB");
        archive.Serialise( RDRS_F_RADAR_ALERT_ACK, "RDRS_F_RADAR_ALERT_ACK");
        archive.Serialise( RDRS_F_RADAR_SD_PRE_WRN, "RDRS_F_RADAR_SD_PRE_WRN");
        archive.Serialise( RDRS_F_RADAR_THERM_OVRD_STATE, "RDRS_F_RADAR_THERM_OVRD_STATE");
        archive.Serialise( RDRS_F_RDRS_F_CP_THRESHOLD, "RDRS_F_RDRS_F_CP_THRESHOLD");
        archive.Serialise( RDRS_F_CP_OVERRIDE_RB, "RDRS_F_CP_OVERRIDE_RB");
        archive.Serialise( RDRS_F_BELOW_DERATING_STATE, "RDRS_F_BELOW_DERATING_STATE");
        archive.Serialise( RDRS_F_LOADSHED_CMD_STS, "RDRS_F_LOADSHED_CMD_STS");
        archive.Serialise( RDRS_F_POWER_RESTRICTION, "RDRS_F_POWER_RESTRICTION");
        archive.Serialise( RDRS_F_SHUTDOWN_STATE, "RDRS_F_SHUTDOWN_STATE");
        archive.Serialise( RDRS_F_ANT_RESET_STATE, "RDRS_F_ANT_RESET_STATE");
        archive.Serialise( RDRS_F_AAU_RESET_STATE, "RDRS_F_AAU_RESET_STATE");
        archive.Serialise( RDRS_F_APSC_RESET_STATE, "RDRS_F_APSC_RESET_STATE");
        archive.Serialise( RDRS_F_RXR_RESET_STATE, "RDRS_F_RXR_RESET_STATE");
        archive.Serialise( RDRS_F_RADAR_RXR_OT, "RDRS_F_RADAR_RXR_OT");
        archive.Serialise( RDRS_F_RADAR_APSC_OT, "RDRS_F_RADAR_APSC_OT");
        archive.Serialise( RDRS_F_RADAR_AAU_OT, "RDRS_F_RADAR_AAU_OT");
        archive.Serialise( RDRS_F_RADAR_PXR_OT, "RDRS_F_RADAR_PXR_OT");
        archive.Serialise( RDRS_F_RADAR_ANT_OT, "RDRS_F_RADAR_ANT_OT");
        archive.Serialise( RDRS_F_CAP_GS_TASK_01, "RDRS_F_CAP_GS_TASK_01");
        archive.Serialise( RDRS_F_CAP_GS_TASK_02, "RDRS_F_CAP_GS_TASK_02");
        archive.Serialise( RDRS_F_CAP_GS_TASK_03, "RDRS_F_CAP_GS_TASK_03");
        archive.Serialise( RDRS_F_CAP_GS_TASK_04, "RDRS_F_CAP_GS_TASK_04");
        archive.Serialise( RDRS_F_CAP_GS_TASK_05, "RDRS_F_CAP_GS_TASK_05");
        archive.Serialise( RDRS_F_CAP_GS_TASK_06, "RDRS_F_CAP_GS_TASK_06");
        archive.Serialise( RDRS_F_CAP_GS_TASK_07, "RDRS_F_CAP_GS_TASK_07");
        archive.Serialise( RDRS_F_CAP_GS_TASK_08, "RDRS_F_CAP_GS_TASK_08");
        archive.Serialise( RDRS_F_CAP_GS_TASK_09, "RDRS_F_CAP_GS_TASK_09");
        archive.Serialise( RDRS_F_CAP_GS_TASK_10, "RDRS_F_CAP_GS_TASK_10");
        archive.Serialise( RDRS_F_CAP_GS_TASK_11, "RDRS_F_CAP_GS_TASK_11");
        archive.Serialise( RDRS_F_CAP_GS_TASK_12, "RDRS_F_CAP_GS_TASK_12");
        archive.Serialise( RDRS_F_CAP_GS_TASK_13, "RDRS_F_CAP_GS_TASK_13");
        archive.Serialise( RDRS_F_CAP_GS_TASK_14, "RDRS_F_CAP_GS_TASK_14");
        archive.Serialise( RDRS_F_CAP_GS_TASK_15, "RDRS_F_CAP_GS_TASK_15");
        archive.Serialise( RDRS_F_CAP_GS_TASK_16, "RDRS_F_CAP_GS_TASK_16");
        archive.Serialise( RDRS_F_CAP_GS_TASK_17, "RDRS_F_CAP_GS_TASK_17");
        archive.Serialise( RDRS_F_CAP_GS_TASK_18, "RDRS_F_CAP_GS_TASK_18");
        archive.Serialise( RDRS_F_CAP_GS_TASK_19, "RDRS_F_CAP_GS_TASK_19");
        archive.Serialise( RDRS_F_CAP_GS_TASK_20, "RDRS_F_CAP_GS_TASK_20");
        archive.Serialise( RDRS_F_CAP_GS_FUNC_01, "RDRS_F_CAP_GS_FUNC_01");
        archive.Serialise( RDRS_F_CAP_GS_FUNC_02, "RDRS_F_CAP_GS_FUNC_02");
        archive.Serialise( RDRS_F_CAP_GS_FUNC_03, "RDRS_F_CAP_GS_FUNC_03");
        archive.Serialise( RDRS_F_CAP_GS_FUNC_04, "RDRS_F_CAP_GS_FUNC_04");
        archive.Serialise( RDRS_F_CAP_GS_FUNC_05, "RDRS_F_CAP_GS_FUNC_05");
        archive.Serialise( RDRS_F_CAP_GS_FUNC_06, "RDRS_F_CAP_GS_FUNC_06");
        archive.Serialise( RDRS_F_CAP_GS_FUNC_07, "RDRS_F_CAP_GS_FUNC_07");
        archive.Serialise( RDRS_F_RECONFIG_REQUEST, "RDRS_F_RECONFIG_REQUEST");
        archive.Serialise( RDRS_F_SNG_EVENT_UPSET_REC_REQ, "RDRS_F_SNG_EVENT_UPSET_REC_REQ");
        archive.Serialise( RDRS_F_PBIT_IBIT_REDUCED_FUNC, "RDRS_F_PBIT_IBIT_REDUCED_FUNC");
        archive.Serialise( RDRS_F_TYPE_REQUEST_RB, "RDRS_F_TYPE_REQUEST_RB");
        archive.Serialise( RDRS_F_PBIT_TYPE_REQUEST, "RDRS_F_PBIT_TYPE_REQUEST");
        archive.Serialise( RDRS_F_FAST_RESP_PBIT_RB, "RDRS_F_FAST_RESP_PBIT_RB");
        archive.Serialise( RDRS_F_FAST_RESP_PBIT_STS, "RDRS_F_FAST_RESP_PBIT_STS");
        archive.Serialise( RDRS_F_PBIT_SUSPENDED, "RDRS_F_PBIT_SUSPENDED");
        archive.Serialise( PBIT_SUSP_FAIL_DET, "PBIT_SUSP_FAIL_DET");
        archive.Serialise( RDRS_F_WARM_UP_RUN_TIME, "RDRS_F_WARM_UP_RUN_TIME");
        archive.Serialise( RDRS_F_VIDEO_SYNC_STS_PBIT, "RDRS_F_VIDEO_SYNC_STS_PBIT");
        archive.Serialise( RDRS_F_RDR_PBIT_RESULT, "RDRS_F_RDR_PBIT_RESULT");
        archive.Serialise( RDRS_F_RDR_CBIT_RESULT, "RDRS_F_RDR_CBIT_RESULT");
        archive.Serialise( RDRS_F_VIDEO_SYNC_STS, "RDRS_F_VIDEO_SYNC_STS");
        archive.Serialise( RDRS_F_IBIT_TYPE_REQUEST_RB, "RDRS_F_IBIT_TYPE_REQUEST_RB");
        archive.Serialise( RDRS_F_IBIT_TYPE_REQUEST_STS, "RDRS_F_IBIT_TYPE_REQUEST_STS");
        archive.Serialise( RDRS_F_IBIT_RESULT, "RDRS_F_IBIT_RESULT");
        archive.Serialise( RDRS_F_VIDEO_SYNC_STS_IBIT, "RDRS_F_VIDEO_SYNC_STS_IBIT");
        archive.Serialise( RDRS_F_RDR_PBIT_IDENT, "RDRS_F_RDR_PBIT_IDENT");
        archive.Serialise( RDRS_F_RDR_FAILURE_IDENT_CODE3, "RDRS_F_RDR_FAILURE_IDENT_CODE3");
        archive.Serialise( RDRS_F_BIT_FAILED_ITEM_ID_1, "RDRS_F_BIT_FAILED_ITEM_ID_1");
        archive.Serialise( RDRS_F_BIT_FAILED_ITEM_ID_2, "RDRS_F_BIT_FAILED_ITEM_ID_2");
        archive.Serialise( RDRS_F_BIT_FAILED_ITEM_ID_3, "RDRS_F_BIT_FAILED_ITEM_ID_3");
        archive.Serialise( RDRS_F_VIS_CAL_TEST, "RDRS_F_VIS_CAL_TEST");
        archive.Serialise( RDRS_F_VIS_CBIT_TEST, "RDRS_F_VIS_CBIT_TEST");
        archive.Serialise( RDRS_F_SIP_CHKSUM_ERROR_TEST, "RDRS_F_SIP_CHKSUM_ERROR_TEST");
        archive.Serialise( RDRS_F_COP_SYNTHETIC_TGT_TEST, "RDRS_F_COP_SYNTHETIC_TGT_TEST");
        archive.Serialise( RDRS_F_DAP_VELOCITY_VAL_TEST, "RDRS_F_DAP_VELOCITY_VAL_TEST");
        archive.Serialise( RDRS_F_DAP_FORMAT_CONV_TEST, "RDRS_F_DAP_FORMAT_CONV_TEST");
        archive.Serialise( RDRS_F_DAP_TGT_QUALITY_TEST, "RDRS_F_DAP_TGT_QUALITY_TEST");
        archive.Serialise( RDRS_F_DAP_OUTPUT_CHKSUM_TEST, "RDRS_F_DAP_OUTPUT_CHKSUM_TEST");
        archive.Serialise( RDRS_F_SIP_TGT_CHKSUM_TEST, "RDRS_F_SIP_TGT_CHKSUM_TEST");
        archive.Serialise( RDRS_F_CORE_TRANSMISSION_TEST, "RDRS_F_CORE_TRANSMISSION_TEST");
        archive.Serialise( RDRS_F_SIP_MD_BLOCK_CHKSUM_TEST, "RDRS_F_SIP_MD_BLOCK_CHKSUM_TEST");
        archive.Serialise( RDRS_F_RADAR_GLOBAL_PASS_SELC, "RDRS_F_RADAR_GLOBAL_PASS_SELC");
        archive.Serialise( RDRS_F_RADAR_STEALTH_STATE, "RDRS_F_RADAR_STEALTH_STATE");
        archive.Serialise( RDRS_F_ANT_POS_OVRD_STATE, "RDRS_F_ANT_POS_OVRD_STATE");
        archive.Serialise( RDRS_F_ANT_PARK_POS_RB, "RDRS_F_ANT_PARK_POS_RB");
        archive.Serialise( RDRS_F_TDEL_S_ACTUAL, "RDRS_F_TDEL_S_ACTUAL");
        archive.Serialise( RDRS_F_TDEL_A_ACTUAL, "RDRS_F_TDEL_A_ACTUAL");
        archive.Serialise( RDRS_F_MAX_PMTD_SURFACE_TRKS, "RDRS_F_MAX_PMTD_SURFACE_TRKS");
        archive.Serialise( RDRS_F_DEL_RADAR_TRACKS, "RDRS_F_DEL_RADAR_TRACKS");
        archive.Serialise( RDRS_F_TRK_DEL_RULES_SEA_STS, "RDRS_F_TRK_DEL_RULES_SEA_STS");
        archive.Serialise( RDRS_F_TRK_DEL_RULES_LAND_STS, "RDRS_F_TRK_DEL_RULES_LAND_STS");
        archive.Serialise( RDRS_F_CLTR_NOTCH_STS, "RDRS_F_CLTR_NOTCH_STS");
        archive.Serialise( RDRS_F_CLTR_NOTCH_WIDTH_ACTUAL, "RDRS_F_CLTR_NOTCH_WIDTH_ACTUAL");
        archive.Serialise( RDRS_F_INHIBIT_REC_STATUS, "RDRS_F_INHIBIT_REC_STATUS");
        archive.Serialise( RDRS_F_CACQ_STATUS, "RDRS_F_CACQ_STATUS");
        archive.Serialise( RDRS_F_IFF_TYPE2_OUTPUT_STATUS, "RDRS_F_IFF_TYPE2_OUTPUT_STATUS");
        archive.Serialise( RDRS_F_PLOT_DATA_OUTPUT_STATUS, "RDRS_F_PLOT_DATA_OUTPUT_STATUS");
        archive.Serialise( RDRS_F_PLOT_DATA_DET_STATUS, "RDRS_F_PLOT_DATA_DET_STATUS");
        archive.Serialise( RDRS_F_PLOT_DATA_AGE_SELC, "RDRS_F_PLOT_DATA_AGE_SELC");
        archive.Serialise( RDRS_F_TIP_INSTALLED, "RDRS_F_TIP_INSTALLED");
        archive.Serialise( RDRS_F_TIP_CNTL_METHOD_STS, "RDRS_F_TIP_CNTL_METHOD_STS");
        archive.Serialise( RDRS_F_TIP_REC_DATA_STS, "RDRS_F_TIP_REC_DATA_STS");
        archive.Serialise( RDRS_F_TIP_DATA_REC_MODE_STS, "RDRS_F_TIP_DATA_REC_MODE_STS");
        archive.Serialise( RDRS_F_TIP_REC_CAP_RESET_STS, "RDRS_F_TIP_REC_CAP_RESET_STS");
        archive.Serialise( RDRS_F_TIP_HEALTH_STS, "RDRS_F_TIP_HEALTH_STS");
        archive.Serialise( RDRS_F_TIP_CAPACITY_REMAIN, "RDRS_F_TIP_CAPACITY_REMAIN");
        archive.Serialise( RDRS_F_RF_AGILITY_STS, "RDRS_F_RF_AGILITY_STS");
        archive.Serialise( RDRS_F_ADAPTIVE_OP_SELECT_STS, "RDRS_F_ADAPTIVE_OP_SELECT_STS");
        archive.Serialise( RDRS_F_ADAPTIVE_OP_VARIANT_STS, "RDRS_F_ADAPTIVE_OP_VARIANT_STS");
        archive.Serialise( RDRS_F_EPM_ENABLE_STS, "RDRS_F_EPM_ENABLE_STS");
        archive.Serialise( RDRS_F_PAE_ENABLE_STS, "RDRS_F_PAE_ENABLE_STS");
        archive.Serialise( RDRS_F_SPOKES_ENABLE_STS, "RDRS_F_SPOKES_ENABLE_STS");
        archive.Serialise( RDRS_F_AIR_CLR_TO_JAM_STS, "RDRS_F_AIR_CLR_TO_JAM_STS");
        archive.Serialise( RDRS_F_AIR_JAM_TO_CLR_STS, "RDRS_F_AIR_JAM_TO_CLR_STS");
        archive.Serialise( RDRS_F_SURF_CLR_TO_JAM_STS, "RDRS_F_SURF_CLR_TO_JAM_STS");
        archive.Serialise( RDRS_F_SURF_JAM_TO_CLR_STS, "RDRS_F_SURF_JAM_TO_CLR_STS");
        archive.Serialise( RDRS_F_SIDELOBE_JAMMED, "RDRS_F_SIDELOBE_JAMMED");
        archive.Serialise( RDRS_F_AUTO_PAE_RES_LIMIT_STS, "RDRS_F_AUTO_PAE_RES_LIMIT_STS");
        archive.Serialise( RDRS_F_KR_RP_STATUS, "RDRS_F_KR_RP_STATUS");
        archive.Serialise( RDRS_F_PPM_OVRD_STATE, "RDRS_F_PPM_OVRD_STATE");
        archive.Serialise( RDRS_F_PPM_VALUE, "RDRS_F_PPM_VALUE");
        archive.Serialise( RDRS_F_RADAR_AS_WP_POSN_UPDATE, "RDRS_F_RADAR_AS_WP_POSN_UPDATE");
        archive.Serialise( RDRS_F_RADAR_AS_WP_LATITUDE, "RDRS_F_RADAR_AS_WP_LATITUDE");
        archive.Serialise( RDRS_F_RADAR_AS_WP_LONGITUDE, "RDRS_F_RADAR_AS_WP_LONGITUDE");
        archive.Serialise( RDRS_F_MISSILE_CH_SELC_SLOT1, "RDRS_F_MISSILE_CH_SELC_SLOT1");
        archive.Serialise( RDRS_F_MISSILE_CH_SELC_SLOT2, "RDRS_F_MISSILE_CH_SELC_SLOT2");
        archive.Serialise( RDRS_F_MISSILE_CH_SELC_SLOT3, "RDRS_F_MISSILE_CH_SELC_SLOT3");
        archive.Serialise( RDRS_F_MISSILE_CH_SELC_SLOT4, "RDRS_F_MISSILE_CH_SELC_SLOT4");
        archive.Serialise( RDRS_F_MISSILE_CH_SELC_SLOT5, "RDRS_F_MISSILE_CH_SELC_SLOT5");
        archive.Serialise( RDRS_F_MISSILE_CH_SELC_SLOT6, "RDRS_F_MISSILE_CH_SELC_SLOT6");
        archive.Serialise( RDRS_F_FCS_HARMO_DATA_LIMITED, "RDRS_F_FCS_HARMO_DATA_LIMITED");
        archive.Serialise( RDRS_F_FCS_HARMO_DATA_VALID, "RDRS_F_FCS_HARMO_DATA_VALID");
        archive.Serialise( RDRS_F_HARMO_DATA_STATUS, "RDRS_F_HARMO_DATA_STATUS");
        archive.Serialise( RDRS_F_HARMO_CHKSUM_STS, "RDRS_F_HARMO_CHKSUM_STS");
        archive.Serialise( RDRS_F_TQ_TABLES_STATUS_VALID, "RDRS_F_TQ_TABLES_STATUS_VALID");
        archive.Serialise( RDRS_F_DEFAULT_TQ_TABLES_STATE, "RDRS_F_DEFAULT_TQ_TABLES_STATE");
        archive.Serialise( RDRS_F_LOADED_TQ_TABLES_STATE, "RDRS_F_LOADED_TQ_TABLES_STATE");
        archive.Serialise( RDRS_F_DEFAULT_TQ_TABLE_ID, "RDRS_F_DEFAULT_TQ_TABLE_ID");
        archive.Serialise( RDRS_F_DEFAULT_TQ_TABLE_VER, "RDRS_F_DEFAULT_TQ_TABLE_VER");
        archive.Serialise( RDRS_F_DEFAULT_TQ_TABLE_CRC, "RDRS_F_DEFAULT_TQ_TABLE_CRC");
        archive.Serialise( RDRS_F_LOADED_TQ_TABLE_ID, "RDRS_F_LOADED_TQ_TABLE_ID");
        archive.Serialise( RDRS_F_LOADED_TQ_TABLE_VER, "RDRS_F_LOADED_TQ_TABLE_VER");
        archive.Serialise( RDRS_F_LOADED_TQ_TABLE_CRC, "RDRS_F_LOADED_TQ_TABLE_CRC");
        archive.Serialise( RDRS_F_INVALID_TQ_TABLE_CMD, "RDRS_F_INVALID_TQ_TABLE_CMD");
        archive.Serialise( RDRS_F_TQ_TABLE_IN_USE, "RDRS_F_TQ_TABLE_IN_USE");
        archive.Serialise( RDRS_F_IFF_PERF_TABLE_IN_USE, "RDRS_F_IFF_PERF_TABLE_IN_USE");
        archive.Serialise( RDRS_F_NCI_TEMPLATE_IN_USE, "RDRS_F_NCI_TEMPLATE_IN_USE");
        archive.Serialise( RDRS_F_LOADED_IFF_TABLE_ID, "RDRS_F_LOADED_IFF_TABLE_ID");
        archive.Serialise( RDRS_F_LOADED_IFF_TABLE_VER, "RDRS_F_LOADED_IFF_TABLE_VER");
        archive.Serialise( RDRS_F_LOADED_NCI_TEMPLATE_ID, "RDRS_F_LOADED_NCI_TEMPLATE_ID");
        archive.Serialise( RDRS_F_LOADED_NCI_TEMPLATE_VER, "RDRS_F_LOADED_NCI_TEMPLATE_VER");
        archive.Serialise( RDRS_F_RES_UTIL_CALC_PERIOD_RB, "RDRS_F_RES_UTIL_CALC_PERIOD_RB");
        archive.Serialise( RDRS_F_RES_UTIL_CALC_MODE, "RDRS_F_RES_UTIL_CALC_MODE");
        archive.Serialise( RDRS_F_TASK_RNK_OVRD_RB, "RDRS_F_TASK_RNK_OVRD_RB");
        archive.Serialise( RDRS_F_GAMMA_TBL_UPDATE_COUNT, "RDRS_F_GAMMA_TBL_UPDATE_COUNT");

            
        }

    LCA_TOPIC("FunctionalStatusTopic", 1, 0)

    };

}  // namespace Topics

#endif