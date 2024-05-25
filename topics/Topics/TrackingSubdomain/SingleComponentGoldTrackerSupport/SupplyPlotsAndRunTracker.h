#ifndef SUPPLY_PLOTS_AND_RUN_TRACKER_H
#define SUPPLY_PLOTS_AND_RUN_TRACKER_H
#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"

#include "OwnshipAndFrame0Nav.h"
#include "TrackingDomainPlot.h"

namespace Topics {
namespace MVP_Tracking {
// Namespace for preliminary topics that drive the MVP single-component tracker in command form

class SupplyPlotsAndRunTracker {
public:
    std::uint32_t       message_diagnostic_id  {0};
    double              dwell_time             {0.0};
    std::uint32_t       dwell_id               {0};
    OwnshipAndFrame0Nav nav_data               {};
    double              minimum_target_size    {0.0};
    double              clutter_notch_value    {0.0};
    double              sightline_az           {0.0};
    double              sightline_el           {0.0};
    std::uint16_t       no_of_plots            {0};
    bool                flush_plot_buffer_flag {false};
    
    std::vector<double> quality_deletion_threshold_vector {}; // length 0-70
    std::vector<Tracking::Plot> plot_list                 {}; // length 0-500

    SupplyPlotsAndRunTracker() = default;
    SupplyPlotsAndRunTracker(std::uint32_t message_diagnostic_id, double dwell_time, std::uint32_t dwell_id,
                             const OwnshipAndFrame0Nav& nav_data, double minimum_target_size, double clutter_notch_value,
                             double sightline_az, double sightline_el, std::uint16_t no_of_plots,
                             bool flush_plot_buffer_flag,
                             const std::vector<double>& quality_deletion_threshold_vector,
                             const std::vector<Tracking::Plot>& plot_list)
        : message_diagnostic_id(message_diagnostic_id),
          dwell_time(dwell_time),
          dwell_id(dwell_id),
          nav_data(nav_data),
          minimum_target_size(minimum_target_size),
          clutter_notch_value(clutter_notch_value),
          sightline_az(sightline_az),
          sightline_el(sightline_el),
          no_of_plots(no_of_plots),
          flush_plot_buffer_flag(flush_plot_buffer_flag ? 1 : 0),
          quality_deletion_threshold_vector(quality_deletion_threshold_vector),
          plot_list(plot_list)
    {}

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(message_diagnostic_id, "message_diagnostic_id");
        archive.Serialise(dwell_time, "dwell_time");
        archive.Serialise(dwell_id, "dwell_id");
        archive.Serialise(nav_data, "nav_data");
        archive.Serialise(minimum_target_size, "minimum_target_size");
        archive.Serialise(clutter_notch_value, "clutter_notch_value");
        archive.Serialise(sightline_az, "sightline_az");
        archive.Serialise(sightline_el, "sightline_el");
        archive.Serialise(no_of_plots, "no_of_plots");
        archive.Serialise(flush_plot_buffer_flag, "flush_plot_buffer_flag");
        archive.Serialise(quality_deletion_threshold_vector,"threshold", "quality_deletion_threshold_vector");
        archive.Serialise(plot_list, "plot_record", "plot_list");
    }

    LCA_TOPIC("SupplyPlotsAndRunTracker",1,0);
};

}
}

#endif