#ifndef VOLUME_GEO_REFERENCED
#define VOLUME_GEO_REFERENCED

#include "CommonAirSearchValues.h"
#include "CommonWeaponSystemValues.h"
#include "NSINauticalMile.h"
#include "SIDegree.h"
#include "FloatEqualityChecker.h"

namespace Topics
{
  namespace EcrsMK2
  {
    namespace WeaponSystem
    {

      namespace Common
      {

        class VolumeGeoReferenced
        {
        protected:
          SI::SIDegree RDRX_ASX_GEO_LAT { IcdDefaultsAs::ASN_X_GEO_LAT_DEFAULT };
          SI::SIDegree RDRX_ASX_GEO_LON { IcdDefaultsAs::ASN_X_GEO_LON_DEFAULT };
          NSI::NSIFoot RDRX_ASX_GEO_ALT { IcdDefaultsAs::ASN_X_GEO_ALT_DEFAULT }; 
          SI::SIDegree RDRX_ASX_GEO_AZ_LEFT { IcdDefaultsAs::ASN_X_GEO_AZ_LEFT_DEFAULT };
          SI::SIDegree RDRX_ASX_GEO_AZ_RIGHT { IcdDefaultsAs::ASN_X_GEO_AZ_RIGHT_DEFAULT };
          SI::SIDegree RDRX_ASX_GEO_EL_UPPER { IcdDefaultsAs::ASN_X_GEO_EL_UPPER_DEFAULT };
          SI::SIDegree RDRX_ASX_GEO_EL_LOWER { IcdDefaultsAs::ASN_X_GEO_EL_LOWER_DEFAULT };
          NSI::NSINauticalMile RDRX_ASX_GEO_RNG_EXT_HALF { IcdDefaultsAs::ASN_X_GEO_RNG_EXT_HALF_DEFAULT };

        public:

          SI::SIDegree get_RDRX_ASX_GEO_LAT() const {
            return RDRX_ASX_GEO_LAT;
          }

          SI::SIDegree get_RDRX_ASX_GEO_LON() const {
            return RDRX_ASX_GEO_LON;
          }

          NSI::NSIFoot get_RDRX_ASX_GEO_ALT() const {
            return RDRX_ASX_GEO_ALT;
          }

          SI::SIDegree get_RDRX_ASX_GEO_AZ_LEFT() const {
            return RDRX_ASX_GEO_AZ_LEFT;
          }

          SI::SIDegree get_RDRX_ASX_GEO_AZ_RIGHT() const {
            return RDRX_ASX_GEO_AZ_RIGHT;
          }

          SI::SIDegree get_RDRX_ASX_GEO_EL_UPPER() const {
            return RDRX_ASX_GEO_EL_UPPER;
          }

          SI::SIDegree get_RDRX_ASX_GEO_EL_LOWER() const {
            return RDRX_ASX_GEO_EL_LOWER;
          }

          NSI::NSINauticalMile get_RDRX_ASX_GEO_RNG_EXT_HALF() const {
            return RDRX_ASX_GEO_RNG_EXT_HALF;
          }

          void set_RDRX_ASX_GEO_LAT(const SI::SIDegree& arg) {
            RDRX_ASX_GEO_LAT = arg;
          }

          void set_RDRX_ASX_GEO_LON(const SI::SIDegree& arg) {
            RDRX_ASX_GEO_LON = arg;
          }

          void set_RDRX_ASX_GEO_ALT(const NSI::NSIFoot& arg) {
            RDRX_ASX_GEO_ALT = arg;
          } 

          void set_RDRX_ASX_GEO_AZ_LEFT(const SI::SIDegree& arg) {
            RDRX_ASX_GEO_AZ_LEFT = arg;
          }

          void set_RDRX_ASX_GEO_AZ_RIGHT(const SI::SIDegree& arg) {
            RDRX_ASX_GEO_AZ_RIGHT = arg;
          }

          void set_RDRX_ASX_GEO_EL_UPPER(const SI::SIDegree& arg) {
            RDRX_ASX_GEO_EL_UPPER = arg;
          }

          void set_RDRX_ASX_GEO_EL_LOWER(const SI::SIDegree& arg) {
            RDRX_ASX_GEO_EL_LOWER = arg;
          }

          void set_RDRX_ASX_GEO_RNG_EXT_HALF(const NSI::NSINauticalMile& arg) {
            RDRX_ASX_GEO_RNG_EXT_HALF = arg;
          }

          void setToIcdDefault() noexcept 
          {
            RDRX_ASX_GEO_LAT = SI::SIDegree(IcdDefaultsAs::ASN_X_GEO_LAT_DEFAULT);
            RDRX_ASX_GEO_LON = SI::SIDegree(IcdDefaultsAs::ASN_X_GEO_LON_DEFAULT);
            RDRX_ASX_GEO_ALT = NSI::NSIFoot(IcdDefaultsAs::ASN_X_GEO_ALT_DEFAULT);
            RDRX_ASX_GEO_AZ_LEFT = SI::SIDegree(IcdDefaultsAs::ASN_X_GEO_AZ_LEFT_DEFAULT);
            RDRX_ASX_GEO_AZ_RIGHT = SI::SIDegree(IcdDefaultsAs::ASN_X_GEO_AZ_RIGHT_DEFAULT);
            RDRX_ASX_GEO_EL_UPPER = SI::SIDegree(IcdDefaultsAs::ASN_X_GEO_EL_UPPER_DEFAULT);
            RDRX_ASX_GEO_EL_LOWER = SI::SIDegree(IcdDefaultsAs::ASN_X_GEO_EL_LOWER_DEFAULT);
            RDRX_ASX_GEO_RNG_EXT_HALF = NSI::NSINauticalMile(IcdDefaultsAs::ASN_X_GEO_RNG_EXT_HALF_DEFAULT);

          }

          /**
           * @brief equality operator
           * @returns true if the field in other contain the same values, false otherwise
           */
          bool operator==(const VolumeGeoReferenced& other) const
          {
            return 
              RDRX_ASX_GEO_LAT == other.RDRX_ASX_GEO_LAT &&
              RDRX_ASX_GEO_LON == other.RDRX_ASX_GEO_LON &&
              SI::floatEqualityChecker::AlmostEqual(RDRX_ASX_GEO_ALT(), other.RDRX_ASX_GEO_ALT()) &&
              RDRX_ASX_GEO_AZ_LEFT == other.RDRX_ASX_GEO_AZ_LEFT &&
              RDRX_ASX_GEO_AZ_RIGHT == other.RDRX_ASX_GEO_AZ_RIGHT &&
              RDRX_ASX_GEO_EL_UPPER == other.RDRX_ASX_GEO_EL_UPPER &&
              RDRX_ASX_GEO_EL_LOWER == other.RDRX_ASX_GEO_EL_LOWER &&
              SI::floatEqualityChecker::AlmostEqual(RDRX_ASX_GEO_RNG_EXT_HALF(), other.RDRX_ASX_GEO_RNG_EXT_HALF());
          }


        };
      }
    }
  }
}

#endif