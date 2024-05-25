#ifndef PLOT_DATA_AGE_SELECTED
#define PLOT_DATA_AGE_SELECTED

#include <stdint.h>
#include "PlotReportingCommonValues.h"

namespace Topics
{
  namespace PlotReporting
  {

    /**
     * @brief class containing the Plot Age setting as
     * selected by the radar
      */
    class PlotDataAgeSelected
    {
      /**
      * @brief the field containing the selected plot data age setting
      */      
      PLOT_DATA_AGE_ENUM RDRS_F_PLOT_DATA_AGE_SELC {};

    public:

      /**
       * @brief default constructor, sets all values to ICD defaults
        */
      PlotDataAgeSelected():
        RDRS_F_PLOT_DATA_AGE_SELC(PLOT_DATA_AGE_ENUM_DEFAULT) { }

      /**
       * @brief getter for the selected plot data age setting
       * @returns the selected plot data age setting
       */
      PLOT_DATA_AGE_ENUM getSelectedPlotDataAge() const
      {
        return RDRS_F_PLOT_DATA_AGE_SELC;
      }

      /**
       * @brief setter for the selected plot data age setting
       * @param selectedAgeSetting the data age setting to be set
       */
      void setSelectedPlotDataAge(PLOT_DATA_AGE_ENUM selectedAgeSetting)
      {
        RDRS_F_PLOT_DATA_AGE_SELC = selectedAgeSetting;
      }

      /**
       * @brief equality operator
        * @returns true if other has the same PlotDataAgeSelected, false otherwise
        */
      bool operator==(const PlotDataAgeSelected& other) const
      {
        return this->RDRS_F_PLOT_DATA_AGE_SELC == other.RDRS_F_PLOT_DATA_AGE_SELC;
      }

      /**
       * @brief inequality operator
        * @returns the negative of the equality operator
        */
      bool operator!=(const PlotDataAgeSelected& other) const
      {
        return !operator==(other);
      }

      /**
      * @brief Serialise function required for communications
      */
      template <class T>
      void Serialise(T& archive) 
      {
        archive.Serialise(RDRS_F_PLOT_DATA_AGE_SELC, "RDRS_F_PLOT_DATA_AGE_SELC");
      }

      LCA_TOPIC("PlotDataAgeSelected", 1, 0);

    };
  }
}

#endif