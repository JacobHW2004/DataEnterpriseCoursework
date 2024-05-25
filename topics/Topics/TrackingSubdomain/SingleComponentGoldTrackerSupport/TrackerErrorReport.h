#ifndef TRACKER_ERROR_REPORT_H
#define TRACKER_ERROR_REPORT_H
#include <cstdint>
#include <vector>

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

class ErrorMessageRecord{
public:
    std::uint32_t              error_id                  {0};
    std::uint8_t               error_type                {0};
    std::uint16_t              tracks_affected           {0};
    std::vector<std::uint32_t> track_IDs_affected_vector {}; // length 0-500
    std::uint8_t               error_action              {0};
    
    ErrorMessageRecord() = default;
    ErrorMessageRecord(std::uint32_t error_id,
                       std::uint8_t error_type,
                       std::uint16_t tracks_affected,
                       const std::vector<std::uint32_t>& track_IDs_affected_vector,
                       std::uint8_t error_action)
    : error_id(error_id),
      error_type(error_type),
      tracks_affected(tracks_affected),
      track_IDs_affected_vector(track_IDs_affected_vector),
      error_action(error_action)
    {}
    
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(error_id, "error_id");
        archive.Serialise(error_type, "error_type");
        archive.Serialise(tracks_affected, "tracks_affected");
        archive.Serialise(track_IDs_affected_vector, "track_ID", "track_IDs_affected_vector");
        archive.Serialise(error_action, "error_action");
    }

    LCA_TOPIC("ErrorMessageRecord",1,0);
};

class TrackerErrorReport{
public:
    std::uint32_t error_report_id;
    std::uint8_t no_of_error_messages;
    std::vector<ErrorMessageRecord> error_message_record; // length 0-50
    
    TrackerErrorReport() = default;
    TrackerErrorReport(std::uint32_t error_report_id,
                       std::uint8_t no_of_error_messages,
                       const std::vector<ErrorMessageRecord>& error_message_record)
    : error_report_id(error_report_id),
      no_of_error_messages(no_of_error_messages),
      error_message_record(error_message_record)
    {}
    
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(error_report_id, "error_report_id");
        archive.Serialise(no_of_error_messages, "no_of_error_messages");
        archive.Serialise(error_message_record, "error", "error_message_record");
    }

    LCA_TOPIC("TrackerErrorReport",1,0);
};

}

#endif