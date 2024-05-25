#ifndef PLOT_DATA_MESSAGE
#define PLOT_DATA_MESSAGE

#include <array>
#include <vector>
#include "PlotData.h"

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    namespace PlotReporting
    {
            
        /**
        * @brief Maximum number of plots that can be transfered
        */
        constexpr uint8_t MAX_PLOTS {180};

        /**
         * @brief Plot data message containing the capcity for 180 plot datas that can be sent
         */
        class PlotDataMessage
        {
            public:
                /**
                 *  @brief default constructor will construct all plots with default values
                 */
                PlotDataMessage() :
                    plotDataVector {}
                {}

                /**
                 *  @brief adds a plot to the message
                 *  @param plotData the plot data to be added to the message
                 */
                void addPlot(const PlotData plotData)
                {
                    if(plotDataVector.size() < MAX_PLOTS)
                    {
                        plotDataVector.push_back(plotData);
                    }
                }

                /**
                 *  @brief gets the plot data array
                 *  @returns the array of plot data
                 */
                const std::array<PlotData, MAX_PLOTS> getPlotData() const
                {
                    std::array<PlotData, MAX_PLOTS> result{};
                    uint16_t index {0};
                    for (PlotData const& plotData : plotDataVector)
                    {
                        result[index++] = plotData;
                    }
                    return result;
                }

                /**
                 * @brief equality operator
                 * @returns true if other has the same plot data array elements, false otherwise
                 */
                bool operator==(const PlotDataMessage& other) const
                {
                    return this->plotDataVector == other.plotDataVector;
                }
                
                /**
                 * @brief inequality operator
                 * @returns the negative of the equality operator
                 */
                bool operator!=(const PlotDataMessage& other) const
                {
                    return !operator==(other);
                }

                /**
                * @brief Serialise function required for communications
                */
                template <class T>
                void Serialise(T& archive) 
                {
                    archive.Serialise(plotDataVector, "plotDataVector", "plotDatas");
                }
                
                LCA_TOPIC("PlotDataMessage", 1, 0);

            private:
                /**
                 * @brief the array of plot data
                 */
                std::vector<PlotData> plotDataVector;
        };
    } // namespace PlotReporting
} // namespace Topics


#endif