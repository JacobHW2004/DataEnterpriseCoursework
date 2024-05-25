#ifndef VOLUME_AIRCRAFT_REFERENCED
#define VOLUME_AIRCRAFT_REFERENCED

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

        class VolumeAircraftReferenced
        {
        protected:
          /**
           * @brief Represents the demanded coordinate system applied to the whole Search Volume
           */
          Common::AC_STABTYPE_ENUM RDRX_ASX_AC_STABTYPE{IcdDefaults::AC_STABTYPE_DEFAULT};

          /**
           * @brief Represents the demanded scan centre Azimuth
           */
          SI::SIDegree RDRX_ASX_AC_AZ_CNTR{IcdDefaults::AC_AZ_CNTR_DEFAULT};

          /**
           * @brief Represents the demanded scan centre Elevation
           */
          SI::SIDegree RDRX_ASX_AC_EL_CNTR{IcdDefaults::AC_EL_CNTR_DEFAULT};

          /**
           * @brief Represents the demanded Azimuth half width of the demanded search volume
           */
          SI::SIDegree RDRX_ASX_AC_AZ_HALF{IcdDefaults::AC_AZ_HALF_DEFAULT};

          /**
           * @brief Represents the demanded Elevation half height of the demanded search volume
           */
          SI::SIDegree RDRX_ASX_AC_EL_HALF{IcdDefaults::AC_EL_HALF_DEFAULT};

          /**
           * @brief represents the demanded slant range to the near edge of the associated search volume
           */
          NSI::NSINauticalMile RDRX_ASX_AC_SLT_MIN{IcdDefaults::AC_SLT_MIN_DEFAULT};

          /**
           * @brief represents the demanded slant range to the far edge of the associated search volume
           */
          NSI::NSINauticalMile RDRX_ASX_AC_SLT_MAX{IcdDefaults::AC_SLT_MAX_DEFAULT};

        public:

          /**
           * @brief default constructor, sets all values to ICD defaults
           */
          VolumeAircraftReferenced()
          {
          }

          /**
           * @brief getter for the coordinate system
           * @returns the coordinate system
           */
          const Common::AC_STABTYPE_ENUM getDemandedCoordSystem() const
          {
            return RDRX_ASX_AC_STABTYPE;
          }

          /**
           * @brief getter for the Scan Centre Azimuth
           * @returns the scan centre azimuth
           */
          const SI::SIDegree getScanCentreAzimuth() const
          {
            return RDRX_ASX_AC_AZ_CNTR;
          }

          /**
           * @brief getter for the Scan Centre Elevation
           * @returns the scan centre elevation
           */
          const SI::SIDegree getScanCentreElevation() const
          {
            return RDRX_ASX_AC_EL_CNTR;
          }

          /**
           * @brief getter for the Azimuth Halfwidth
           * @returns the azimuth halfwidth
           */
          const SI::SIDegree getAzimuthHalfWidth() const
          {
            return RDRX_ASX_AC_AZ_HALF;
          }

          /**
           * @brief getter for the Elevation Halfwidth
           * @returns the elevation halfwidth
           */
          const SI::SIDegree getElevationHalfWidth() const
          {
            return RDRX_ASX_AC_EL_HALF;
          }

          /**
           * @brief getter for the Slant Range Near Edge
           * @returns the slant range near edge
           */
          const NSI::NSINauticalMile getSlantRangeNearEdge() const
          {
            return RDRX_ASX_AC_SLT_MIN;
          }

          /**
           * @brief getter for the Slant Range Far Edge
           * @returns the slant range far edge
           */
          const NSI::NSINauticalMile getSlantRangeFarEdge() const
          {
            return RDRX_ASX_AC_SLT_MAX;
          }

          /**
           * @brief setter for the coordinate system
           * @param coordSystem : the coordinate system to be set
           */
          const void setCoordSystem(const Common::AC_STABTYPE_ENUM& coordSystem)
          {
            RDRX_ASX_AC_STABTYPE = coordSystem;
          }

          /**
           * @brief setter for the Scan Centre Azimuth
           * @param centreAzimuth : the centre azimuth value to be set
           */
          const void setScanCentreAzimuth(const SI::SIDegree &centreAzimuth)
          {
            RDRX_ASX_AC_AZ_CNTR = centreAzimuth;
          }

          /**
           * @brief setter for the Scan Centre Elevation
           * @param centreElevation : the centre elevation to be set
           */
          const void setScanCentreElevation(const SI::SIDegree &centreElevation)
          {
            RDRX_ASX_AC_EL_CNTR = centreElevation;
          }

          /**
           * @brief setter for the Azimuth Halfwidth
           * @param azimuthHalfwidth : the azimuth haldwidth to be set
           */
          const void setAzimuthHalfWidth(const SI::SIDegree &azimuthHalfwidth)
          {
            RDRX_ASX_AC_AZ_HALF = azimuthHalfwidth;
          }

          /**
           * @brief setter for the Elevation Halfwidth
           * @param elevationHalfwidth : the elevation halfwidth to be set
           */
          const void setElevationHalfWidth(const SI::SIDegree &elevationHalfwidth)
          {
            RDRX_ASX_AC_EL_HALF = elevationHalfwidth;
          }

          /**
           * @brief setter for the Slant Range Near Edge
           * @param slantRangeNearEdge : the slant range near edge to be set
           */
          const void setSlantRangeNearEdge(const NSI::NSINauticalMile &slantRangeNearEdge)
          {
            RDRX_ASX_AC_SLT_MIN = slantRangeNearEdge;
          }

          /**
           * @brief setter for the Slant Range Far Edge
           * @param slantRangeFarEdge : the slant range far edge to be set
           */
          const void setSlantRangeFarEdge(const NSI::NSINauticalMile &slantRangeFarEdge)
          {
            RDRX_ASX_AC_SLT_MAX = slantRangeFarEdge;
          }

          void setToIcdDefault() noexcept 
          {
            RDRX_ASX_AC_STABTYPE = IcdDefaults::AC_STABTYPE_DEFAULT;
            RDRX_ASX_AC_EL_CNTR = IcdDefaults::AC_EL_CNTR_DEFAULT;
            RDRX_ASX_AC_AZ_CNTR = IcdDefaults::AC_AZ_CNTR_DEFAULT;
            RDRX_ASX_AC_EL_HALF = IcdDefaults::AC_EL_HALF_DEFAULT;
            RDRX_ASX_AC_AZ_HALF = IcdDefaults::AC_AZ_HALF_DEFAULT;
            RDRX_ASX_AC_SLT_MAX = IcdDefaults::AC_SLT_MAX_DEFAULT;
            RDRX_ASX_AC_SLT_MIN = IcdDefaults::AC_SLT_MIN_DEFAULT;
          }

          /**
           * @brief equality operator
           * @returns true if the field in other contain the same values, false otherwise
           */
          bool operator==(const VolumeAircraftReferenced& other) const
          {
            return 
              RDRX_ASX_AC_STABTYPE == other.RDRX_ASX_AC_STABTYPE &&
              RDRX_ASX_AC_AZ_CNTR == other.RDRX_ASX_AC_AZ_CNTR &&
              RDRX_ASX_AC_EL_CNTR == other.RDRX_ASX_AC_EL_CNTR &&
              RDRX_ASX_AC_AZ_HALF == other.RDRX_ASX_AC_AZ_HALF &&
              RDRX_ASX_AC_EL_HALF == other.RDRX_ASX_AC_EL_HALF &&
              SI::floatEqualityChecker::AlmostEqual(RDRX_ASX_AC_SLT_MIN(), other.RDRX_ASX_AC_SLT_MIN()) &&
              SI::floatEqualityChecker::AlmostEqual(RDRX_ASX_AC_SLT_MAX(), other.RDRX_ASX_AC_SLT_MAX());
          }

          template <class T>
          void Serialise(T &archive)
          {
            double azCtr = RDRX_ASX_AC_AZ_CNTR();
            double elCtr = RDRX_ASX_AC_EL_CNTR();
            double azHalf = RDRX_ASX_AC_AZ_HALF();
            double elHalf = RDRX_ASX_AC_EL_HALF();
            double sltMin = RDRX_ASX_AC_SLT_MIN();
            double sltMax = RDRX_ASX_AC_SLT_MAX();

            archive.Serialise(RDRX_ASX_AC_STABTYPE,"RDRX_ASX_AC_STABTYPE");
            archive.Serialise(azCtr, "azCtr");
            archive.Serialise(elCtr, "elCtr");
            archive.Serialise(azHalf, "azHalf");
            archive.Serialise(elHalf, "elHalf");
            archive.Serialise(sltMin, "sltMin");
            archive.Serialise(sltMax, "sltMax");
            
            RDRX_ASX_AC_AZ_CNTR = azCtr;
            RDRX_ASX_AC_EL_CNTR = elCtr;
            RDRX_ASX_AC_AZ_HALF = azHalf;
            RDRX_ASX_AC_EL_HALF = elHalf;
            RDRX_ASX_AC_SLT_MIN = sltMin;
            RDRX_ASX_AC_SLT_MAX = sltMax;
          }
          
          LCA_TOPIC("VolumeAircraftReferenced", 1, 0)
        };

      }
    }
  }
}

#endif
