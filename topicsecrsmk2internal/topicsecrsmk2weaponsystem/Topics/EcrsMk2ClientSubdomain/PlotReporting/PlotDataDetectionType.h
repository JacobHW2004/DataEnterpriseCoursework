#ifndef PLOT_DATA_DETECTION_TYPE
#define PLOT_DATA_DETECTION_TYPE

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    namespace PlotDetectionType
    {
        /**
         * @brief enumeration for the data detection type
         */
        enum class RDRC_F_PLOT_DATA_DET_TYPE_ENUM : uint8_t
        {
            ALL = 0x00,
            AIR = 0x01,
            SURFACE = 0x02
        };

        /**
         * @brief Plot Data detection type topic
         */
        class PlotDataDetectionType
        {
            public:
                /**
                 * @brief default constructor, sets the detection type to All
                 */
                PlotDataDetectionType() :
                RDRC_F_PLOT_DATA_DET_TYPE {RDRC_F_PLOT_DATA_DET_TYPE_ENUM::ALL}
                {}

                /**
                 * @brief constructor allowing the definition of the detection type
                 */
                PlotDataDetectionType(RDRC_F_PLOT_DATA_DET_TYPE_ENUM detectionType) :
                RDRC_F_PLOT_DATA_DET_TYPE {detectionType}
                {}

                /**
                 * @brief getter for the plot data detection type
                 * @returns the plot data detection type
                 */
                RDRC_F_PLOT_DATA_DET_TYPE_ENUM getDetectionType()
                {
                    return RDRC_F_PLOT_DATA_DET_TYPE;
                }

                /**
                 * @brief equality operator
                 * @returns true if other has the same plot data detection type, false otherwise
                 */
                bool operator==(const PlotDataDetectionType& other) const
                {
                    return this->RDRC_F_PLOT_DATA_DET_TYPE == other.RDRC_F_PLOT_DATA_DET_TYPE;
                }

                /**
                 * @brief inequality operator
                 * @returns the negative of the equality operator
                 */
                bool operator!=(const PlotDataDetectionType& other) const
                {
                    return !operator==(other);
                }

                /**
                * @brief Serialise function required for communications
                */
                template <class T>
                void Serialise(T& archive) 
                {  
                    archive.Serialise(RDRC_F_PLOT_DATA_DET_TYPE, "RDRC_F_PLOT_DATA_DET_TYPE");
                }
                
                LCA_TOPIC("PlotDataDetectionType", 1, 0);

            private:
                /**
                 * @brief the plot data detection type, this field commands the system to ouput normal plots information (not Vectored Plots) in one of three ways
                 *          All : air and surface uncorrelated plots ranked by their detection time, most recent first
                 *          Air : Only air uncorrelated plots ranked by their detection time, most recent first
                 *          SURFACE : Only surface uncorrelated plots ranked by their detection time, most recent first 
                 */
                RDRC_F_PLOT_DATA_DET_TYPE_ENUM RDRC_F_PLOT_DATA_DET_TYPE;

        };
    } // namespace PlotDetectionType
}

#endif