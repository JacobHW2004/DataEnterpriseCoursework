#ifndef PLOT_BUNDLE_H
#define PLOT_BUNDLE_H

#include "Fabric/Utils/LCA_Macros.h"
#include <vector>
#include <cstdint>
#include "TrackingDomainPlot.h"

namespace Topics {
    class PlotBundle {
    public:
		std::uint32_t plot_bundle_id{ 0 };

        std::vector<Topics::Tracking::Plot> bundle{};

        PlotBundle() = default;

		PlotBundle(const std::vector<Topics::Tracking::Plot>& aBundleOfPlots, std::uint32_t bundleId) :
			bundle(aBundleOfPlots),
			plot_bundle_id(bundleId)
        {}

        template <class T>
        void Serialise(T& archive) {
			archive.Serialise(plot_bundle_id, "plot_bundle_id");
            archive.Serialise(bundle, "plot", "bundle");

        }

        LCA_TOPIC("PlotBundle", 2, 0);
    };
}

#endif