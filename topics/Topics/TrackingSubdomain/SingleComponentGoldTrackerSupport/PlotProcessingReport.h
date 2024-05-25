#ifndef PLOT_PROCESSING_REPORT_H
#define PLOT_PROCESSING_REPORT_H
#include <vector>
#include <cstdint>

#include "Fabric/Utils/LCA_Macros.h"

#include "OwnshipAndFrame0Nav.h"
#include "TrackingDomainPlotWithRelatedTracks.h"

namespace Topics{

class RejectedPlotData{
public:
    std::uint32_t plot_id         {0};
    std::uint8_t  rejection_cause {0};
    
    RejectedPlotData() = default;
    RejectedPlotData(std::uint32_t plot_id, std::uint8_t rejection_cause)
    : plot_id(plot_id), rejection_cause(rejection_cause) {}
    
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(plot_id,"plot_id");
        archive.Serialise(rejection_cause,"rejection_cause");
    }
    
    LCA_TOPIC("RejectedPlotData",1,0);
};

class PlotRejectionList{
public:
    std::uint32_t rejection_record_id;
    std::uint16_t no_of_plot_rejections;
    std::vector<RejectedPlotData> rejected_plot_list; // length 0-500

    PlotRejectionList() = default;
    PlotRejectionList(std::uint32_t rejection_record_id,
                      std::uint16_t no_of_plot_rejections,
                      const std::vector<RejectedPlotData>& rejected_plot_list)
    : rejection_record_id(rejection_record_id),
      no_of_plot_rejections(no_of_plot_rejections),
      rejected_plot_list(rejected_plot_list)
    {}
    
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(rejection_record_id,"rejection_record_id");
        archive.Serialise(no_of_plot_rejections,"no_of_plot_rejections");
        archive.Serialise(rejected_plot_list,"rejected_plot","rejected_plot_list");
    }

    LCA_TOPIC("PlotRejectionList",1,0);
};

class PlotProcessingReport{
public:

    std::uint16_t no_of_plots;
    std::vector<Tracking::PlotWithRelatedTracks> plot_reports_out; // length 0-500
    PlotRejectionList correlation_stage_rejected_plots;
    PlotRejectionList update_stage_rejected_plots;
    
    PlotProcessingReport() = default;
    PlotProcessingReport(std::uint16_t no_of_plots,
                         std::vector<Tracking::PlotWithRelatedTracks> plot_reports_out,
                         PlotRejectionList correlation_stage_rejected_plots,
                         PlotRejectionList update_stage_rejected_plots)
    : no_of_plots(no_of_plots),
      plot_reports_out(plot_reports_out),
      correlation_stage_rejected_plots(correlation_stage_rejected_plots),
      update_stage_rejected_plots(update_stage_rejected_plots)
    {}
    
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(no_of_plots,"no_of_plots");
        archive.Serialise(plot_reports_out,"plot_report","plot_reports_out");
        archive.Serialise(correlation_stage_rejected_plots,"correlation_stage_rejected_plots");
        archive.Serialise(update_stage_rejected_plots,"update_stage_rejected_plots");
    }
    
    LCA_TOPIC("PlotProcessingReport",1,0);
};

}

#endif