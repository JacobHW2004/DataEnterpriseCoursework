#ifndef PLOT_HEADER
#define PLOT_HEADER

#include <SISecond.h>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics
{
    namespace PlotReporting
    {
        enum class INTERNAL_SYNC_ENUM : uint8_t
        {
            EXTERNAL_SYNC_IN_USE = 0x00,
            INTERNAL_SYNC_IN_USE = 0x01
        };

        /**
        * @brief  Header message sent before the plot data message 
        */
        class PlotHeader
        {
            public:
                /**
                 * @brief default constructor for the plot header
                 */
                PlotHeader() : PlotHeader(0, SI::SISecond{0}) {}

                /**
                 * @brief constructor allowing the number of plots and the time code to be defined, internal sync will be default initialised 
                 * @param noPlotsInList : the number of plots being sent as part of this message sequence
                 * @param timeCode : The time at which the tag word of the header message was scheduled for transfer
                 */
                PlotHeader(uint16_t noPlotsInList, SI::SISecond timeCode) : PlotHeader(noPlotsInList, timeCode, INTERNAL_SYNC_ENUM::INTERNAL_SYNC_IN_USE) {}

                /**
                 * @brief constructor allowing the number of plots and the time code to be defined, internal sync will be default initialised 
                 * @param noPlotsInList : the number of plots being sent as part of this message sequence
                 * @param timeCode : The time at which the tag word of the header message was scheduled for transfer
                 * @param internalSync : Specifies whether internal or external video sync is in use
                 */
                PlotHeader(uint16_t noPlotsInList, SI::SISecond timeCode, INTERNAL_SYNC_ENUM internalSync) : 
                NO_OF_PLOTS_IN_LIST { noPlotsInList },
                TIME_CODE { timeCode },
                INTERNAL_SYNC { internalSync }
                {}

                /**
                 * @brief getter for the number of plots that will be sent as part of this message sequence 
                 * @return the number of plots that will be sent as part of this message sequence
                 */
                uint16_t getNoPlotsInList()
                {
                    return NO_OF_PLOTS_IN_LIST;
                }

                /**
                 * @brief getter for the time at which the tag word of the header message is schedulded for transfer
                 * @return the time at which the tag word of the header message is scheduled for transfer
                 */
                SI::SISecond getTimeCode()
                {
                    return TIME_CODE;
                }

                /**
                 * @brief getter for the internal sync
                 * @return the internal sync
                 */
                INTERNAL_SYNC_ENUM getInternalSync()
                {
                    return INTERNAL_SYNC;
                }

                /**
                 * @brief equality operator
                 * @return true if objects are populated with the same fields, false otherwise 
                 */
                bool operator==(const PlotHeader& other) const
                {
                    return this->NO_OF_PLOTS_IN_LIST == other.NO_OF_PLOTS_IN_LIST &&
                            this->TIME_CODE == other.TIME_CODE && 
                            this->INTERNAL_SYNC == other.INTERNAL_SYNC;
                }

                /**
                 * @brief inequality operator
                 * @return the negative of the equality operator
                 */
                bool operator!=(const PlotHeader& other) const
                {
                    return !operator==(other);
                }

                /**
                * @brief Serialise function required for communications
                */
                template <class T>
                void Serialise(T& archive) 
                {
                    double doubleTimeCode{TIME_CODE()};
                    archive.Serialise(doubleTimeCode, "timeCodeCount");
                    archive.Serialise(NO_OF_PLOTS_IN_LIST, "NO_OF_PLOTS_IN_LIST");
                    archive.Serialise(INTERNAL_SYNC, "INTERNAL_SYNC");
                    TIME_CODE = doubleTimeCode;
                }

                LCA_TOPIC("PlotHeader", 1, 0);

            private:
                /**
                * @brief the number of plots to be sent in this message sequence 
                */
                uint16_t NO_OF_PLOTS_IN_LIST;
                /**
                * @brief time at which the tag word of the header message is schedulded for transfer
                */
                SI::SISecond TIME_CODE;
                /**
                * @brief The internal sync
                */
                INTERNAL_SYNC_ENUM INTERNAL_SYNC;
        };
    } // namespace PlotReporting
}

#endif