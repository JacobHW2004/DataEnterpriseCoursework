#ifndef COMMON_AIRSEARCH_VALUES
#define COMMON_AIRSEARCH_VALUES

#include <stdint.h>
#include "CommonSearchValues.h"

namespace Topics
{
	namespace EcrsMK2
	{
		namespace WeaponSystem
		{
#define IcdDefaultsAs Topics::EcrsMK2::WeaponSystem::AirSearch
			namespace AirSearch
			{

				/**
				 * @brief enumeration for PAT FS
				 */
				enum class PAT_FS_ENUM : uint8_t
				{
					AUTO = 0x00,
					PATFS1 = 0x01,
					PATFS2 = 0x02,
					PATFS3 = 0x03,
					PATFS4 = 0x04,
					PATFS5 = 0x05,
					PATFS6 = 0x06,
					PATFS7 = 0x07
				};

				// Dimension type
				enum class SPATIAL_ENUM : uint8_t
				{
					AIRCRAFT = 0x00,
					GEO = 0x01,
					GEOBOX = 0x02,
					RIDE = 0x03
				};

				// ASS track type characteristic
				enum class ASS_TYPE_ENUM : uint8_t
				{
					NO_OPTIMISATION = 0x00,
					ROTARY = 0x01,
					FIXED_WING_PROP = 0x02,
					FIXED_WING_JET = 0x03
				};

				// ASS track hemisphere characteristic
				enum class ASS_HEMIS_ENUM : uint8_t
				{
					NO_OPTIMISATION = 0x00,
					OPENING = 0x01,
					CLOSING = 0x02
				};

				// Task volume scan type
				enum class ASN_X_VOL_SCAN_TYPE_ENUM : uint8_t
				{
					INVALID = 0x00,
					NOMINAL = 0x01,
					QUICK = 0x02
				};

				// Task search start point
				enum class ASN_X_START_POINT_ENUM : uint8_t
				{
					FIXED = 0x00,
					VARIABLE = 0x01,
				};

				/**
				 * @brief enumeration for Enhanced control
				 */
				enum class ENHD_CTRL_ENUM : uint8_t
				{
					PRE_DEFINED = 0x00,
					USE_REQD_RESERVED1 = 0x01,
					USE_REQD_RESERVED2 = 0x02 // ASN-only
				};
				/**
				 * @brief Default Message Values
				 */
				static constexpr Search::PAT_T_ENUM PAT_T_DEFAULT{Search::PAT_T_ENUM::AUTO};
				static constexpr PAT_FS_ENUM PAT_FS_DEFAULT{PAT_FS_ENUM::AUTO};
				static constexpr Search::PAT_D_ENUM PAT_D_DEFAULT{Search::PAT_D_ENUM::AUTO};
				static constexpr Search::PAT_I_ENUM PAT_I_DEFAULT{Search::PAT_I_ENUM::AUTO};
				static constexpr SPATIAL_ENUM SPATIAL_DEFAULT{SPATIAL_ENUM::AIRCRAFT};
				static constexpr uint8_t TV_MIN_PCT_DEFAULT{0};
				static constexpr uint8_t TV_DES_PCT_DEFAULT{0};
				static constexpr double ASS_RCS_DEFAULT{0.0};
				static constexpr ASS_TYPE_ENUM ASS_TYPE_DEFAULT{ASS_TYPE_ENUM::NO_OPTIMISATION};
				static constexpr double ASS_VEL_DEFAULT{0.0};
				static constexpr ASS_HEMIS_ENUM ASS_HEMIS_DEFAULT{ASS_HEMIS_ENUM::NO_OPTIMISATION};
				static constexpr ENHD_CTRL_ENUM RDRC_ASC_ENHD_CTRL_DEFAULT{ENHD_CTRL_ENUM::PRE_DEFINED};
				static constexpr float REQD_RES1_DEFAULT{0.0};
				static constexpr float REQD_RES2_DEFAULT{0.0};
				static constexpr uint8_t ACHIEVED_PCT_DEFAULT{0};
				static constexpr float RES_REP_ACTUAL_DEFAULT{0.0F};
				static constexpr float RES_REP_PRED_DES_DEFAULT{0.0F};
				static constexpr float RES_REP_PRED_MIN_DEFAULT{0.0F};
				static constexpr float RES_ANT_ACTUAL_DEFAULT{0.0F};
				static constexpr float RES_ANT_PRED_DES_DEFAULT{0.0F};
				static constexpr float RES_ANT_PRED_MIN_DEFAULT{0.0F};
				static constexpr uint8_t RATIO_DMD_ACT_DEFAULT{0};
				static constexpr uint8_t PROG_ACT_VOL_DEFAULT{0};
				static constexpr double TIME_TO_COMP_ITER_DEFAULT{0.0};
				//______________________________________________//

				/**
				 * @brief AirSearch Normal Specific Parameters
				 */
				static constexpr ASN_X_VOL_SCAN_TYPE_ENUM ASN_X_VOL_SCAN_TYPE_DEFAULT{ASN_X_VOL_SCAN_TYPE_ENUM::NOMINAL};
				static constexpr ASN_X_START_POINT_ENUM ASN_X_START_POINT_DEFAULT{ASN_X_START_POINT_ENUM::FIXED};
				//_______________________________________________________________//

				/**
				 * @brief Geographically Referenced specific parameters
				 */
				static constexpr double ASN_X_GEO_LAT_DEFAULT{0.0};
				static constexpr double ASN_X_GEO_LON_DEFAULT{0.0};
				static constexpr int32_t ASN_X_GEO_ALT_DEFAULT{0};
				static constexpr double ASN_X_GEO_AZ_LEFT_DEFAULT{0.0};
				static constexpr double ASN_X_GEO_AZ_RIGHT_DEFAULT{0.0};
				static constexpr double ASN_X_GEO_EL_UPPER_DEFAULT{0.0};
				static constexpr double ASN_X_GEO_EL_LOWER_DEFAULT{0.0};
				static constexpr float ASN_X_GEO_RNG_EXT_HALF_DEFAULT{0.0F};
				//______________________________________________//
			}
		}
	}
}

#endif