#ifndef TOPOLOGY_TOPOLOGY_USER_GEN_H_
#define TOPOLOGY_TOPOLOGY_USER_GEN_H_

#include "Fabric/Topology/Topology.h"
#include "Fabric/Topology/TopologyImpl.h"

//Driver Technologies
#include "Fabric/ConnectionDrivers/Direct/Direct.h"

// Topics in alphabetical order
#include "CommandValidityRequestResponse.h"

//Topics Includes
#include "Fabric/Topics/Shutdown.h"

#include "Fabric/Utils/DllUtils.h"
#include "Container/LoadContainer.h"
#include "Container/Component/LoadComponent.h"

#include "Fabric/Topology/IP/IPv4.h"
#include "Fabric/Topology/IP/Port.h"

#include "Fabric/Topology/ConnectionBuilders/ConnectionBuilder.h"
#include "Fabric/Topology/ConnectionBuilders/ConnectionPairBuilder.h"

namespace lca
{
	using namespace container;

	namespace fabric
	{
			//Operation List - Required Operations
			// Topics used by LCA Container
			REQUEST_RESPONSE(LoadComponent)
			REQUEST_RESPONSE(LoadContainer)
			PUBLISH_SUBSCRIBE(PublishStatisticSetBundle)
			REQUEST_RESPONSE(Shutdown)
			PUBLISH_SUBSCRIBE(Shutdown)

			// Other Topics used by the System in alphabetical order

			REQUEST_RESPONSE(Topics::CommandValidityRequestResponse)


		namespace SingleComponent
		{
			void load(ConnectionBuilder &builder)
			{

            }
		} // namespace EcrsMk2
	} // namespace fabric
} // namespace lca
#endif /*TOPOLOGY_TOPOLOGY_USER_GEN_H_*/