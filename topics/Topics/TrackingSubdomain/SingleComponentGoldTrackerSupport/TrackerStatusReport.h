#ifndef TRACKER_STATUS_REPORT_H
#define TRACKER_STATUS_REPORT_H
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"
namespace Topics{

class TrackerStatusReport {
public:
    std::uint8_t  status_word          {0};                
    std::uint32_t status_report_id     {0};
    std::uint8_t  errors_detected_flag {0};
    
    TrackerStatusReport() = default;
    TrackerStatusReport(std::uint8_t status_word, std::uint32_t status_report_id,
                        std::uint8_t errors_detected_flag)
        : status_word(status_word),
          status_report_id(status_report_id),
          errors_detected_flag(errors_detected_flag)
    {}
    
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(status_word,"status_word");
        archive.Serialise(status_report_id,"status_report_id");
        archive.Serialise(errors_detected_flag,"errors_detected_flag");
    }
    
    LCA_TOPIC("TrackerStatusReport",1,0);
};

}
#endif