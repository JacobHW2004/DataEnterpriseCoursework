#ifndef TRACK_DELETION_STATUS
#define TRACK_DELETION_STATUS

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics{
    namespace TrackDeletion{
        /**
         * @brief This enumeration indicates the Status of Nose Radar Track Deletion. 
         */
        enum class RDRS_F_DEL_RADAR_TRACKS_ENUM : uint8_t {
            NO_ACTION = 0x00,
            SUCCESS_ALL = 0x01,
            SUCCESS_ALL_AIR = 0x02,
            SUCCESS_ALL_SRFC = 0x03,
            SUCCESS_INDIVIDUAL = 0x04,
            FAILURE_INVALID_ID = 0x05,
            FAILURE_TASKED_ID = 0x06,
            FAILURE_OTHER = 0x07
        };
        
        /**
         * @brief class to encapsulate the status of a deletion of a track from the functional parameters
         */
        class TrackDeletionStatus{
            public:
                /**
                 * @brief constructor for the Track Deletion Status 
                 * @param deletionStatus : the status of the track deletion
                 */
                TrackDeletionStatus(RDRS_F_DEL_RADAR_TRACKS_ENUM deletionStatus = RDRS_F_DEL_RADAR_TRACKS_ENUM::NO_ACTION) :
                    RDRS_F_DEL_RADAR_TRACKS{deletionStatus}
                {
                }
                /**
                 * @brief getter for the RDRS_F_DEL_RADAR_TRACKS functional parameter
                 * @returns the track deletion status
                 */
                const RDRS_F_DEL_RADAR_TRACKS_ENUM getDeletionStatus() const noexcept
                {
                    return RDRS_F_DEL_RADAR_TRACKS;
                }
                /**
                * @brief Serialise function required for communications
                */
                template <class T>
                void Serialise(T& archive) 
                {  
                    archive.Serialise(RDRS_F_DEL_RADAR_TRACKS, "RDRS_F_DEL_RADAR_TRACKS");
                }

                LCA_TOPIC("TrackDeletionStatus", 1, 0);
            private:
                /**
                 * @brief This field indicates the Status of Nose Radar Track Deletion.
                 */
                RDRS_F_DEL_RADAR_TRACKS_ENUM RDRS_F_DEL_RADAR_TRACKS;
        };
    }
}

#endif