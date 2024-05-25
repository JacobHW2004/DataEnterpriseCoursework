#ifndef PLOT_DATA_AGE_DEMAND
#define PLOT_DATA_AGE_DEMAND

#include <stdint.h>
#include "PlotReportingCommonValues.h"

namespace Topics
{
  namespace PlotReporting
  {

    /**
     * @brief class containing the Plot Age setting as
     * demanded by the weapon system
      */
    class PlotDataAgeDemand
    {

      /**
      * @brief the field containing the demanded plot data age setting
      */      
      PLOT_DATA_AGE_ENUM RDRC_F_PLOT_DATA_AGE_DMD {};

    public:

      /**
       * @brief default constructor, sets all values to ICD defaults
        */
      PlotDataAgeDemand():
        RDRC_F_PLOT_DATA_AGE_DMD(PLOT_DATA_AGE_ENUM_DEFAULT) { }

      /**
       * @brief getter for the demanded plot data age setting
       * @returns the demanded plot data age setting
       */
      PLOT_DATA_AGE_ENUM getDemandedPlotDataAge() const
      {
        return RDRC_F_PLOT_DATA_AGE_DMD;
      }

      /**
       * @brief setter for the demanded plot data age setting
       * @param demandedAgeSetting the data age setting to be set
       */
      void setDemandedPlotDataAge(PLOT_DATA_AGE_ENUM demandedAgeSetting)
      {
        RDRC_F_PLOT_DATA_AGE_DMD = demandedAgeSetting;
      }

      /**
       * @brief equality operator
        * @returns true if other has the same PlotDataAgeDemand, false otherwise
        */
      bool operator==(const PlotDataAgeDemand& other) const
      {
        return this->RDRC_F_PLOT_DATA_AGE_DMD == other.RDRC_F_PLOT_DATA_AGE_DMD;
      }

      /**
       * @brief inequality operator
        * @returns the negative of the equality operator
        */
      bool operator!=(const PlotDataAgeDemand& other) const
      {
        return !operator==(other);
      }

      /**
      * @brief Serialise function required for communications
      */
      template <class T>
      void Serialise(T& archive) 
      {
        archive.Serialise(RDRC_F_PLOT_DATA_AGE_DMD, "RDRC_F_PLOT_DATA_AGE_DMD");
      }

      LCA_TOPIC("PlotDataAgeDemand", 1, 0);

    };
  }
}


#endif