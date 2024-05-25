#ifndef PLOT_SENTINAL
#define PLOT_SENTINAL

namespace Topics
{
    namespace PlotReporting
    {
        /**
        * @brief  Plot Sentinal message represents 32 bits of reserved space
        */
        class PlotSentinal {
            public :
                PlotSentinal()
                {}

                /**
                * @brief Serialise function required for communications
                */
                template <class T>
                void Serialise(T& archive) 
                {  
                }

                LCA_TOPIC("PlotSentinal", 1, 0);
        };
    } // namespace PlotReporting
} // namespace Topics


#endif