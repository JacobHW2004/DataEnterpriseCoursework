#ifndef SEARCH_NORMAL_ELECTRONIC_COMMAND_TOPIC_H
#define SEARCH_NORMAL_ELECTRONIC_COMMAND_TOPIC_H

#include <string>
#include <array>
#include "Fabric/Utils/LCA_Macros.h"
#include "CommonWeaponSystemValues.h"
#include "CommonSearchValues.h"
#include "CommonAirSearchValues.h"
#include "SIDegree.h"
#include "Command.h"
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
                

                enum class RDRC_ESSN_X_K_RAP_ATT_ENUM : uint8_t {
                    NOT_RAPID = 0x00,
                    RAPID = 0x01
                };
                
                //___________DEFAULT_MESSAGE_VALUES______________//
                // Default values are defined within the ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
                static constexpr int8_t RDRC_ESSN_X_TV_MIN_PCT_DEFAULT { 0 };
                static constexpr int8_t RDRC_ESSN_X_TV_DES_PCT_DEFAULT { 0 };
                static constexpr uint16_t RDRC_ESN_CMD_PAYLOAD_SIZE_IN_16BIT_WORDS{ 16U };
                static constexpr VALIDITY_ENUM RDRC_ESSN_X_POI_VALID_DEFAULT {VALIDITY_ENUM::INVALID};
                static constexpr uint16_t RDRC_ESSN_X_UN_K_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_UN_K_MIN_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_UN_K_MIN_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_UN_K_MIN_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_UN_K_DES_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_UN_K_DES_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_UN_K_DES_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_AU_K_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_AU_K_MIN_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_AU_K_MIN_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_AU_K_MIN_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_AU_K_DES_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_AU_K_DES_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_AU_K_DES_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_AL_K_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_AL_K_MIN_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_AL_K_MIN_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_AL_K_MIN_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_AL_K_DES_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_AL_K_DES_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_AL_K_DES_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_SU_K_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_SU_K_MIN_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_SU_K_MIN_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_SU_K_MIN_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_SU_K_DES_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_SU_K_DES_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_SU_K_DES_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_SL_K_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_SL_K_MIN_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_SL_K_MIN_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_SL_K_MIN_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID }; 
                static constexpr uint16_t RDRC_ESSN_X_SL_K_DES_POS_X_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_SL_K_DES_POS_Z_DEFAULT { 0 }; 
                static constexpr RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_SL_K_DES_RAP_ATT_DEFAULT { RDRC_ESSN_X_K_RAP_ATT_ENUM::NOT_RAPID };
                static constexpr uint16_t RDRC_ESSN_X_UN_E_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_UN_E_MIN_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_UN_E_DES_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_AU_E_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_AU_E_MIN_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_AU_E_DES_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_AL_E_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_AL_E_MIN_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_AL_E_DES_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_SU_E_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_SU_E_MIN_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_SU_E_DES_DEFAULT { 0 }; 
                static constexpr uint16_t RDRC_ESSN_X_SL_E_PRIORITY_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_SL_E_MIN_DEFAULT { 0 }; 
                static constexpr uint8_t RDRC_ESSN_X_SL_E_DES_DEFAULT { 0 };
                static constexpr double RDRC_ESSN_X_POI_BEARING_DEFAULT {0};
                static constexpr double RDRC_ESSN_X_POI_RANGE_DEFAULT {0};

                /**
                * @brief this topic is a strongly typed one to one mapping of Radar Command 2 - message AC36-RADAR-HAT-MESS-1 (ESN - Aircraft Referenced vairant only) from
                * ECRS MK II INTERFACE CONTROL DOCUMENT PART 2. Report No:  AP50131645_02
                * DRL No:  1.17
                * Issue: A
                */
                class SearchNormalElectronicCommandTopic : public Common::Command,
                                                            public Common::VolumeArea,
                                                            public SurfaceSearchNormalElectronic {

                public:
                    
                    int8_t RDRC_ESSN_X_TV_MIN_PCT{RDRC_ESSN_X_TV_MIN_PCT_DEFAULT};

                    int8_t RDRC_ESSN_X_TV_DES_PCT{RDRC_ESSN_X_TV_DES_PCT_DEFAULT};

                    uint16_t RDRC_ESSN_X_UN_K_PRIORITY {RDRC_ESSN_X_UN_K_PRIORITY_DEFAULT};

                    VALIDITY_ENUM RDRC_ESSN_X_POI_VALID {RDRC_ESSN_X_POI_VALID_DEFAULT};

                    uint16_t RDRC_ESSN_X_UN_K_MIN_POS_X {RDRC_ESSN_X_UN_K_MIN_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_UN_K_MIN_POS_Z {RDRC_ESSN_X_UN_K_MIN_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_UN_K_MIN_RAP_ATT {RDRC_ESSN_X_UN_K_MIN_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_UN_K_DES_POS_X {RDRC_ESSN_X_UN_K_DES_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_UN_K_DES_POS_Z {RDRC_ESSN_X_UN_K_DES_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_UN_K_DES_RAP_ATT {RDRC_ESSN_X_UN_K_DES_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_AU_K_PRIORITY {RDRC_ESSN_X_AU_K_PRIORITY_DEFAULT};

                    uint16_t RDRC_ESSN_X_AU_K_MIN_POS_X {RDRC_ESSN_X_AU_K_MIN_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_AU_K_MIN_POS_Z {RDRC_ESSN_X_AU_K_MIN_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_AU_K_MIN_RAP_ATT {RDRC_ESSN_X_AU_K_MIN_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_AU_K_DES_POS_X {RDRC_ESSN_X_AU_K_DES_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_AU_K_DES_POS_Z {RDRC_ESSN_X_AU_K_DES_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_AU_K_DES_RAP_ATT {RDRC_ESSN_X_AU_K_DES_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_AL_K_PRIORITY {RDRC_ESSN_X_AL_K_PRIORITY_DEFAULT};

                    uint16_t RDRC_ESSN_X_AL_K_MIN_POS_X {RDRC_ESSN_X_AL_K_MIN_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_AL_K_MIN_POS_Z {RDRC_ESSN_X_AL_K_MIN_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_AL_K_MIN_RAP_ATT {RDRC_ESSN_X_AL_K_MIN_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_AL_K_DES_POS_X {RDRC_ESSN_X_AL_K_DES_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_AL_K_DES_POS_Z {RDRC_ESSN_X_AL_K_DES_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_AL_K_DES_RAP_ATT {RDRC_ESSN_X_AL_K_DES_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_SU_K_PRIORITY {RDRC_ESSN_X_SU_K_PRIORITY_DEFAULT};

                    uint16_t RDRC_ESSN_X_SU_K_MIN_POS_X {RDRC_ESSN_X_SU_K_MIN_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_SU_K_MIN_POS_Z {RDRC_ESSN_X_SU_K_MIN_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_SU_K_MIN_RAP_ATT {RDRC_ESSN_X_SU_K_MIN_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_SU_K_DES_POS_X {RDRC_ESSN_X_SU_K_DES_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_SU_K_DES_POS_Z {RDRC_ESSN_X_SU_K_DES_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_SU_K_DES_RAP_ATT {RDRC_ESSN_X_SU_K_DES_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_SL_K_PRIORITY {RDRC_ESSN_X_SL_K_PRIORITY_DEFAULT};

                    uint16_t RDRC_ESSN_X_SL_K_MIN_POS_X {RDRC_ESSN_X_SL_K_MIN_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_SL_K_MIN_POS_Z {RDRC_ESSN_X_SL_K_MIN_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_SL_K_MIN_RAP_ATT {RDRC_ESSN_X_SL_K_MIN_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_SL_K_DES_POS_X {RDRC_ESSN_X_SL_K_DES_POS_X_DEFAULT};

                    uint16_t RDRC_ESSN_X_SL_K_DES_POS_Z {RDRC_ESSN_X_SL_K_DES_POS_Z_DEFAULT};

                    RDRC_ESSN_X_K_RAP_ATT_ENUM RDRC_ESSN_X_SL_K_DES_RAP_ATT {RDRC_ESSN_X_SL_K_DES_RAP_ATT_DEFAULT};

                    uint16_t RDRC_ESSN_X_UN_E_PRIORITY {RDRC_ESSN_X_UN_E_PRIORITY_DEFAULT};

                    uint8_t RDRC_ESSN_X_UN_E_MIN {RDRC_ESSN_X_UN_E_MIN_DEFAULT};

                    uint8_t RDRC_ESSN_X_UN_E_DES {RDRC_ESSN_X_UN_E_DES_DEFAULT};

                    uint16_t RDRC_ESSN_X_AU_E_PRIORITY {RDRC_ESSN_X_AU_E_PRIORITY_DEFAULT};

                    uint8_t RDRC_ESSN_X_AU_E_MIN {RDRC_ESSN_X_AU_E_MIN_DEFAULT};

                    uint8_t RDRC_ESSN_X_AU_E_DES {RDRC_ESSN_X_AU_E_DES_DEFAULT};

                    uint16_t RDRC_ESSN_X_AL_E_PRIORITY {RDRC_ESSN_X_AL_E_PRIORITY_DEFAULT};

                    uint8_t RDRC_ESSN_X_AL_E_MIN {RDRC_ESSN_X_AL_E_MIN_DEFAULT};

                    uint8_t RDRC_ESSN_X_AL_E_DES {RDRC_ESSN_X_AL_E_DES_DEFAULT};

                    uint16_t RDRC_ESSN_X_SU_E_PRIORITY {RDRC_ESSN_X_SU_E_PRIORITY_DEFAULT};

                    uint8_t RDRC_ESSN_X_SU_E_MIN {RDRC_ESSN_X_SU_E_MIN_DEFAULT};

                    uint8_t RDRC_ESSN_X_SU_E_DES {RDRC_ESSN_X_SU_E_DES_DEFAULT};

                    uint16_t RDRC_ESSN_X_SL_E_PRIORITY {RDRC_ESSN_X_SL_E_PRIORITY_DEFAULT};

                    uint8_t RDRC_ESSN_X_SL_E_MIN {RDRC_ESSN_X_SL_E_MIN_DEFAULT};

                    uint8_t RDRC_ESSN_X_SL_E_DES {RDRC_ESSN_X_SL_E_DES_DEFAULT};

                    double RDRC_ESSN_X_POI_BEARING {RDRC_ESSN_X_POI_BEARING_DEFAULT};

                    double RDRC_ESSN_X_POI_RANGE {RDRC_ESSN_X_POI_RANGE_DEFAULT};

                    Common::WeaponSystemTaskType getTaskType() const noexcept override
                    {
                        return Common::WeaponSystemTaskType::ELECT_SURFACE_SEARCH_NORMAL;
                    }

                    bool operator==(const SearchNormalElectronicCommandTopic& other) const
                    {
                        return RDRC_ESSN_X_TV_MIN_PCT == other.RDRC_ESSN_X_TV_MIN_PCT &&
                                RDRC_ESSN_X_TV_DES_PCT == other.RDRC_ESSN_X_TV_DES_PCT &&
                                RDRC_ESSN_X_UN_K_PRIORITY == other.RDRC_ESSN_X_UN_K_PRIORITY &&
                                RDRC_ESSN_X_UN_K_MIN_POS_X == other.RDRC_ESSN_X_UN_K_MIN_POS_X &&
                                RDRC_ESSN_X_UN_K_MIN_POS_Z == other.RDRC_ESSN_X_UN_K_MIN_POS_Z &&
                                RDRC_ESSN_X_UN_K_MIN_RAP_ATT == other.RDRC_ESSN_X_UN_K_MIN_RAP_ATT &&
                                RDRC_ESSN_X_UN_K_DES_POS_X == other.RDRC_ESSN_X_UN_K_DES_POS_X &&
                                RDRC_ESSN_X_AU_K_PRIORITY == other.RDRC_ESSN_X_AU_K_PRIORITY &&
                                RDRC_ESSN_X_AU_K_MIN_POS_X == other.RDRC_ESSN_X_AU_K_MIN_POS_X &&
                                RDRC_ESSN_X_AU_K_MIN_POS_Z == other.RDRC_ESSN_X_AU_K_MIN_POS_Z &&
                                RDRC_ESSN_X_AU_K_MIN_RAP_ATT == other.RDRC_ESSN_X_AU_K_MIN_RAP_ATT &&
                                RDRC_ESSN_X_AU_K_DES_POS_X == other.RDRC_ESSN_X_AU_K_DES_POS_X &&
                                RDRC_ESSN_X_AU_K_DES_POS_Z == other.RDRC_ESSN_X_AU_K_DES_POS_Z &&
                                RDRC_ESSN_X_AU_K_DES_RAP_ATT == other.RDRC_ESSN_X_AU_K_DES_RAP_ATT &&
                                RDRC_ESSN_X_AL_K_PRIORITY == other.RDRC_ESSN_X_AL_K_PRIORITY &&
                                RDRC_ESSN_X_AL_K_MIN_POS_X == other.RDRC_ESSN_X_AL_K_MIN_POS_X &&
                                RDRC_ESSN_X_AL_K_MIN_POS_Z == other.RDRC_ESSN_X_AL_K_MIN_POS_Z &&
                                RDRC_ESSN_X_AL_K_MIN_RAP_ATT == other.RDRC_ESSN_X_AL_K_MIN_RAP_ATT &&
                                RDRC_ESSN_X_AL_K_DES_POS_X == other.RDRC_ESSN_X_AL_K_DES_POS_X &&
                                RDRC_ESSN_X_AL_K_DES_POS_Z == other.RDRC_ESSN_X_AL_K_DES_POS_Z &&
                                RDRC_ESSN_X_AL_K_DES_RAP_ATT == other.RDRC_ESSN_X_AL_K_DES_RAP_ATT &&
                                RDRC_ESSN_X_SU_K_PRIORITY == other.RDRC_ESSN_X_SU_K_PRIORITY &&
                                RDRC_ESSN_X_SU_K_MIN_POS_X == other.RDRC_ESSN_X_SU_K_MIN_POS_X &&
                                RDRC_ESSN_X_SU_K_MIN_POS_Z == other.RDRC_ESSN_X_SU_K_MIN_POS_Z &&
                                RDRC_ESSN_X_SU_K_MIN_RAP_ATT == other.RDRC_ESSN_X_SU_K_MIN_RAP_ATT &&
                                RDRC_ESSN_X_SU_K_DES_POS_X == other.RDRC_ESSN_X_SU_K_DES_POS_X &&
                                RDRC_ESSN_X_SU_K_DES_POS_Z == other.RDRC_ESSN_X_SU_K_DES_POS_Z &&
                                RDRC_ESSN_X_SU_K_DES_RAP_ATT == other.RDRC_ESSN_X_SU_K_DES_RAP_ATT &&
                                RDRC_ESSN_X_SL_K_PRIORITY == other.RDRC_ESSN_X_SL_K_PRIORITY &&
                                RDRC_ESSN_X_SL_K_MIN_POS_X == other.RDRC_ESSN_X_SL_K_MIN_POS_X &&
                                RDRC_ESSN_X_SL_K_MIN_POS_Z == other.RDRC_ESSN_X_SL_K_MIN_POS_Z &&
                                RDRC_ESSN_X_SL_K_MIN_RAP_ATT == other.RDRC_ESSN_X_SL_K_MIN_RAP_ATT &&
                                RDRC_ESSN_X_SL_K_DES_POS_X == other.RDRC_ESSN_X_SL_K_DES_POS_X &&
                                RDRC_ESSN_X_SL_K_DES_POS_Z == other.RDRC_ESSN_X_SL_K_DES_POS_Z &&
                                RDRC_ESSN_X_SL_K_DES_RAP_ATT == other.RDRC_ESSN_X_SL_K_DES_RAP_ATT &&
                                RDRC_ESSN_X_UN_E_PRIORITY == other.RDRC_ESSN_X_UN_E_PRIORITY &&
                                RDRC_ESSN_X_UN_E_MIN == other.RDRC_ESSN_X_UN_E_MIN &&
                                RDRC_ESSN_X_UN_E_DES == other.RDRC_ESSN_X_UN_E_DES &&
                                RDRC_ESSN_X_AU_E_PRIORITY == other.RDRC_ESSN_X_AU_E_PRIORITY &&
                                RDRC_ESSN_X_AU_E_MIN == other.RDRC_ESSN_X_AU_E_MIN &&
                                RDRC_ESSN_X_AU_E_DES == other.RDRC_ESSN_X_AU_E_DES &&
                                RDRC_ESSN_X_AL_E_PRIORITY == other.RDRC_ESSN_X_AL_E_PRIORITY &&
                                RDRC_ESSN_X_AL_E_MIN == other.RDRC_ESSN_X_AL_E_MIN &&
                                RDRC_ESSN_X_AL_E_DES == other.RDRC_ESSN_X_AL_E_DES &&
                                RDRC_ESSN_X_SU_E_PRIORITY == other.RDRC_ESSN_X_SU_E_PRIORITY &&
                                RDRC_ESSN_X_SU_E_MIN == other.RDRC_ESSN_X_SU_E_MIN &&
                                RDRC_ESSN_X_SU_E_DES == other.RDRC_ESSN_X_SU_E_DES &&
                                RDRC_ESSN_X_SL_E_PRIORITY == other.RDRC_ESSN_X_SL_E_PRIORITY &&
                                RDRC_ESSN_X_SL_E_MIN == other.RDRC_ESSN_X_SL_E_MIN &&
                                RDRC_ESSN_X_SL_E_DES == other.RDRC_ESSN_X_SL_E_DES &&
                                RDRC_ESSN_X_POI_BEARING == other.RDRC_ESSN_X_POI_BEARING &&
                                RDRC_ESSN_X_POI_RANGE == other.RDRC_ESSN_X_POI_RANGE &&
                                SurfaceSearchNormalElectronic::operator== (other) &&
                                VolumeArea::operator== (other) &&
                                Command::operator == (other);
                    }

                    bool operator!=(const SearchNormalElectronicCommandTopic& other) const
                    {
                        return !(*this == other);
                    }

                    /**
                    * @brief Serialise function required for communications
                    */
                    template <class T>
                    void Serialise(T& archive) {
                        double AZ_CNTR {CenterLine()};
                        double AZ_HALF {AzHalfwidth()};
                        double PLAN_MIN {PlanMin()};
                        double PLAN_MAX {PlanMax()};
                        archive.Serialise(RDRC_ESSN_X_TV_MIN_PCT, "RDRC_ESSN_X_TV_MIN_PCT"); 
                        archive.Serialise(RDRC_ESSN_X_TV_DES_PCT, "RDRC_ESSN_X_TV_DES_PCT"); 
                        archive.Serialise(PAT_T, "PAT_T"); 
                        archive.Serialise(PAT_D, "PAT_D"); 
                        archive.Serialise(PAT_I, "PAT_I"); 
                        archive.Serialise(ON_DETECT_TRACKING, "ON_DETECT_TRACKING"); 
                        archive.Serialise(ON_UNLISTED_REALM, "ON_UNLISTED_REALM"); 
                        archive.Serialise(RSS_SOURCE, "RSS_SOURCE"); 
                        archive.Serialise(RSS_REF, "RSS_REF"); 
                        archive.Serialise(RDRC_ESSN_X_POI_VALID, "RDRC_ESSN_X_POI_VALID"); 
                        archive.Serialise(SPATIAL, "SPATIAL"); 
                        archive.Serialise(AXISTYPE, "AXISTYPE"); 
                        archive.Serialise(AZ_CNTR, "RDRC_ESSN_AC_AZ_CNTR"); 
                        archive.Serialise(AZ_HALF, "RDRC_ESSN_AC_AZ_HALF"); 
                        archive.Serialise(PLAN_MIN, "RDRC_ESSN_AC_PLAN_MIN"); 
                        archive.Serialise(PLAN_MAX, "RDRC_ESSN_AC_PLAN_MAX"); 
                        archive.Serialise(RDRC_ESSN_X_UN_K_PRIORITY, "RDRC_ESSN_X_UN_K_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_UN_K_MIN_POS_X, "RDRC_ESSN_X_UN_K_MIN_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_UN_K_MIN_POS_Z, "RDRC_ESSN_X_UN_K_MIN_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_UN_K_MIN_RAP_ATT, "RDRC_ESSN_X_UN_K_MIN_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_UN_K_DES_POS_X, "RDRC_ESSN_X_UN_K_DES_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_AU_K_PRIORITY, "RDRC_ESSN_X_AU_K_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_AU_K_MIN_POS_X, "RDRC_ESSN_X_AU_K_MIN_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_AU_K_MIN_POS_Z, "RDRC_ESSN_X_AU_K_MIN_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_AU_K_MIN_RAP_ATT, "RDRC_ESSN_X_AU_K_MIN_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_AU_K_DES_POS_X, "RDRC_ESSN_X_AU_K_DES_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_AU_K_DES_POS_Z, "RDRC_ESSN_X_AU_K_DES_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_AU_K_DES_RAP_ATT, "RDRC_ESSN_X_AU_K_DES_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_AL_K_PRIORITY, "RDRC_ESSN_X_AL_K_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_AL_K_MIN_POS_X, "RDRC_ESSN_X_AL_K_MIN_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_AL_K_MIN_POS_Z, "RDRC_ESSN_X_AL_K_MIN_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_AL_K_MIN_RAP_ATT, "RDRC_ESSN_X_AL_K_MIN_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_AL_K_DES_POS_X, "RDRC_ESSN_X_AL_K_DES_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_AL_K_DES_POS_Z, "RDRC_ESSN_X_AL_K_DES_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_AL_K_DES_RAP_ATT, "RDRC_ESSN_X_AL_K_DES_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_SU_K_PRIORITY, "RDRC_ESSN_X_SU_K_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_SU_K_MIN_POS_X, "RDRC_ESSN_X_SU_K_MIN_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_SU_K_MIN_POS_Z, "RDRC_ESSN_X_SU_K_MIN_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_SU_K_MIN_RAP_ATT, "RDRC_ESSN_X_SU_K_MIN_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_SU_K_DES_POS_X, "RDRC_ESSN_X_SU_K_DES_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_SU_K_DES_POS_Z, "RDRC_ESSN_X_SU_K_DES_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_SU_K_DES_RAP_ATT, "RDRC_ESSN_X_SU_K_DES_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_SL_K_PRIORITY, "RDRC_ESSN_X_SL_K_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_SL_K_MIN_POS_X, "RDRC_ESSN_X_SL_K_MIN_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_SL_K_MIN_POS_Z, "RDRC_ESSN_X_SL_K_MIN_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_SL_K_MIN_RAP_ATT, "RDRC_ESSN_X_SL_K_MIN_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_SL_K_DES_POS_X, "RDRC_ESSN_X_SL_K_DES_POS_X"); 
                        archive.Serialise(RDRC_ESSN_X_SL_K_DES_POS_Z, "RDRC_ESSN_X_SL_K_DES_POS_Z"); 
                        archive.Serialise(RDRC_ESSN_X_SL_K_DES_RAP_ATT, "RDRC_ESSN_X_SL_K_DES_RAP_ATT"); 
                        archive.Serialise(RDRC_ESSN_X_UN_E_PRIORITY, "RDRC_ESSN_X_UN_E_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_UN_E_MIN, "RDRC_ESSN_X_UN_E_MIN"); 
                        archive.Serialise(RDRC_ESSN_X_UN_E_DES, "RDRC_ESSN_X_UN_E_DES"); 
                        archive.Serialise(RDRC_ESSN_X_AU_E_PRIORITY, "RDRC_ESSN_X_AU_E_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_AU_E_MIN, "RDRC_ESSN_X_AU_E_MIN"); 
                        archive.Serialise(RDRC_ESSN_X_AU_E_DES, "RDRC_ESSN_X_AU_E_DES"); 
                        archive.Serialise(RDRC_ESSN_X_AL_E_PRIORITY, "RDRC_ESSN_X_AL_E_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_AL_E_MIN, "RDRC_ESSN_X_AL_E_MIN"); 
                        archive.Serialise(RDRC_ESSN_X_AL_E_DES, "RDRC_ESSN_X_AL_E_DES"); 
                        archive.Serialise(RDRC_ESSN_X_SU_E_PRIORITY, "RDRC_ESSN_X_SU_E_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_SU_E_MIN, "RDRC_ESSN_X_SU_E_MIN"); 
                        archive.Serialise(RDRC_ESSN_X_SU_E_DES, "RDRC_ESSN_X_SU_E_DES"); 
                        archive.Serialise(RDRC_ESSN_X_SL_E_PRIORITY, "RDRC_ESSN_X_SL_E_PRIORITY"); 
                        archive.Serialise(RDRC_ESSN_X_SL_E_MIN, "RDRC_ESSN_X_SL_E_MIN"); 
                        archive.Serialise(RDRC_ESSN_X_SL_E_DES, "RDRC_ESSN_X_SL_E_DES"); 
                        archive.Serialise(INDEX_VALID, "INDEX_VALID"); 
                        archive.Serialise(NO_ES, "NO_ES"); 
                        archive.Serialise(ES_SEARCHING, "ES_SEARCHING"); 
                        archive.Serialise(ES_TRACKING, "ES_TRACKING"); 
                        archive.Serialise(ES_JAMMING, "ES_JAMMING"); 
                        archive.Serialise(ES_MISSILE, "ES_MISSILE"); 
                        archive.Serialise(TYPE_INDEX, "TYPE_INDEX"); 
                        archive.Serialise(RDRC_ESSN_X_POI_BEARING, "RDRC_ESSN_X_POI_BEARING"); 
                        archive.Serialise(RDRC_ESSN_X_POI_RANGE, "RDRC_ESSN_X_POI_RANGE"); 
                        archive.Serialise(TASK_IDENT, "TASK_IDENT"); 
                        archive.Serialise(CMD, "CMD"); 
                        archive.Serialise(TV_PRIORITY, "TV_PRIORITY"); 
                        archive.Serialise(TDI, "TDI"); 

                        CenterLine = AZ_CNTR; 
                        AzHalfwidth = AZ_HALF; 
                        PlanMin = PLAN_MIN; 
                        PlanMax = PLAN_MAX; 
                        
                    }

                    LCA_TOPIC("SearchNormalElectronicCommandTopic", 1, 0)

                };
            } // namespace SurfaceSearch
        } // namespace WeaponSystem
    } // namespace EcrsMK2
}  // namespace Topics

#endif