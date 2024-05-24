#include "Fabric/Topology/Topology.h"
#include "Fabric/Topology/TopologyImpl.h"
#include "Logging/ConsoleLoggerSink.h"

//Topology Parts
#include "Topology_user.h"

namespace lca {
	namespace fabric {
        void Topology::load(ConnectionBuilder& builder) {
			lca::fabric::SingleComponent::load(builder);
        }
		
		Topology::Topology(const std::shared_ptr<schedule::SchedulerRuntime>& scheduleIn, const std::set<std::string>& componentList)
		{
			builder = std::make_shared<ConnectionBuilder>(this, componentList);
			Topology::getLog()->setLogLevel(utils::logging::eLogLevel::Info);
			INITIALISE_CONSOLE_LOGGER(Topology::getLog());

			this->load(*builder);
		}
	}
}