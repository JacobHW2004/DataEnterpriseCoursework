#ifndef SDI_VIDEO_SYNC_NOTIFICATION
#define SDI_VIDEO_SYNC_NOTIFICATION

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics{

    /**
    * @brief  This topic is a notification that a Plot Data message should now be sent
    */
    class VideoSyncNotification
    {
        public:
            /**
            * @brief Serialise function required for communications
            */
            template <class T>
            void Serialise(T& archive) 
            {  
            }

            LCA_TOPIC("VideoSyncNotification", 1, 0);
        };
}

#endif