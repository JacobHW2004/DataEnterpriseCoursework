#ifndef SSNE_DEFITIONS
#define SSNE_DEFITIONS

#include <stdint.h>
#include "CommonAirSearchValues.h"

namespace Topics
{
    namespace EcrsMK2
    {
        namespace WeaponSystem
        {
            namespace SurfaceSearch
            {
                //in status
                enum class ON_DETECT_TRACKING_ENUM : uint8_t {
                    TRACK_EVERYTHING = 0x00,
                    TRACK_UNKNOWN_OR_LISTED = 0x01,
                    TRACK_ONLY_KNOWN = 0x02,
                    TRACK_ONLY_LISTED = 0x03
                };

                //in status
                enum class ON_UNLISTED_REALM_ENUM : uint8_t {
                    REALM_ONLY = 0x00,
                    REALM_EVERYTHING = 0x01
                };

                //in status
                enum class RSS_SOURCE_ENUM : uint8_t {
                    PREDEFINED_RSS = 0x00,
                    DYNAMICALLY_CALCULATED_RSS = 0x01
                };
                
                enum class VALIDITY_ENUM : uint8_t {
                    INVALID = 0x00,
                    VALID = 0x00
                };

                
                enum class AXISTYPE_ENUM : uint8_t {
                    INVALID = 0x00,
                    NORTH = 0x01,
                    HEADING = 0x02,
                    TRACK = 0x03
                };

                
                static constexpr ON_DETECT_TRACKING_ENUM ON_DETECT_TRACKING_DEFAULT{ON_DETECT_TRACKING_ENUM::TRACK_EVERYTHING};
                static constexpr ON_UNLISTED_REALM_ENUM ON_UNLISTED_REALM_DEFAULT{ON_UNLISTED_REALM_ENUM::REALM_ONLY};
                static constexpr RSS_SOURCE_ENUM RSS_SOURCE_DEFAULT{RSS_SOURCE_ENUM::PREDEFINED_RSS};
                static constexpr int8_t RSS_REF_DEFAULT { 0 };
                static constexpr bool NO_ES_DEFAULT {false};
                static constexpr bool ES_SEARCHING_DEFAULT {false};
                static constexpr bool ES_TRACKING_DEFAULT {false};
                static constexpr bool ES_JAMMING_DEFAULT {false};
                static constexpr bool ES_MISSILE_DEFAULT {false};
                static constexpr uint16_t TYPE_INDEX_DEFAULT {0};
                static constexpr AirSearch::SPATIAL_ENUM SPATIAL_DEFAULT {AirSearch::SPATIAL_ENUM::AIRCRAFT};
                static constexpr AXISTYPE_ENUM AXISTYPE_DEFAULT {AXISTYPE_ENUM::NORTH };
                static constexpr Search::PAT_T_ENUM PAT_T_DEFAULT {Search::PAT_T_ENUM::AUTO};
                static constexpr Search::PAT_D_ENUM PAT_D_DEFAULT {Search::PAT_D_ENUM::AUTO};
                static constexpr Search::PAT_I_ENUM PAT_I_DEFAULT {Search::PAT_I_ENUM::AUTO};
                static constexpr VALIDITY_ENUM INDEX_VALID_DEFAULT { VALIDITY_ENUM::INVALID };

                class SurfaceSearchNormalElectronic
                {
                    public:

						bool operator==(const SurfaceSearchNormalElectronic& other) const noexcept
						{
							return this->RSS_REF == other.RSS_REF &&
                                    this->SPATIAL == other.SPATIAL &&
                                    this->PAT_T == other.PAT_T &&
                                    this->PAT_D == other.PAT_D &&
                                    this->PAT_I == other.PAT_I &&
                                    this->ON_DETECT_TRACKING == other.ON_DETECT_TRACKING &&
                                    this->ON_UNLISTED_REALM == other.ON_UNLISTED_REALM &&
                                    this->RSS_SOURCE == other.RSS_SOURCE &&
                                    this->NO_ES == other.NO_ES &&
                                    this->ES_SEARCHING == other.ES_SEARCHING &&
                                    this->ES_TRACKING == other.ES_TRACKING &&
                                    this->ES_JAMMING == other.ES_JAMMING &&
                                    this->ES_MISSILE == other.ES_MISSILE &&
                                    this->INDEX_VALID == other.INDEX_VALID &&
                                    this->TYPE_INDEX == other.TYPE_INDEX;
						}

						bool operator!=(const SurfaceSearchNormalElectronic& other) const
						{
							return !(*this == other);
						}

                        int8_t RSS_REF{RSS_REF_DEFAULT};

                        AirSearch::SPATIAL_ENUM SPATIAL{SPATIAL_DEFAULT};

                        Search::PAT_T_ENUM PAT_T {PAT_T_DEFAULT};

                        Search::PAT_D_ENUM PAT_D {PAT_D_DEFAULT};
                        
                        Search::PAT_I_ENUM PAT_I {PAT_I_DEFAULT};

						ON_DETECT_TRACKING_ENUM ON_DETECT_TRACKING{ON_DETECT_TRACKING_DEFAULT};

						ON_UNLISTED_REALM_ENUM ON_UNLISTED_REALM{ON_UNLISTED_REALM_DEFAULT};

						RSS_SOURCE_ENUM RSS_SOURCE{RSS_SOURCE_DEFAULT};
                        
                        /// @brief EMXX in the status
                        bool NO_ES {NO_ES_DEFAULT};

                        bool ES_SEARCHING {ES_SEARCHING_DEFAULT};

                        bool ES_TRACKING {ES_TRACKING_DEFAULT};

                        bool ES_JAMMING {ES_JAMMING_DEFAULT};

                        bool ES_MISSILE {ES_MISSILE_DEFAULT};

                        uint16_t TYPE_INDEX {TYPE_INDEX_DEFAULT};
                        
                        AXISTYPE_ENUM AXISTYPE { AXISTYPE_DEFAULT };

                        VALIDITY_ENUM INDEX_VALID { INDEX_VALID_DEFAULT };
                };
            } // namespace Surface Search
        } // namespace WeaponSystem
    } // namespace EcrsMk2
} // namespace Topics

#endif
