#ifndef COMMAND_CHECKER_RESPONDER_H
#define COMMAND_CHECKER_RESPONDER_H

#include "CommandChecker.h"
#include "CommandValidityRequestResponse.h"
#include <memory>

// LCA includes
#include "Container/ContainerContextInstance.h"
#include "Fabric/RequestResponse/RequestResponse.h"

namespace CommandCheckerLCA
{
    class CommandCheckerResponder final
    {
        private:
            /** @brief Context Instance for the Container */
            std::weak_ptr<lca::container::ContainerContextInstance> mContextInstance;

            /** @brief Shared pointer to the business logic */
            std::shared_ptr<CommandChecker> mCommandChecker;

            /** @brief Responder Facade for GeoLLAToFrameReferencedRequestResponse */
            lca::fabric::Responder<Topics::CommandValidityRequestResponse> commandValidityResponder;

        public:
            /** @brief User-defined constructor taking a pointer to the ContainerContextInstance */
            CommandCheckerResponder(
                std::shared_ptr<lca::container::ContainerContextInstance> const& aContext,
                std::shared_ptr<CommandChecker> mCommandChecker
            );

            /** @brief deleted copy constructor */
            CommandCheckerResponder(CommandCheckerResponder const& aCommandCheckerResponder) = delete;

            /** @brief deleted move constructor */
            CommandCheckerResponder(CommandCheckerResponder&& aCommandCheckerResponder) = delete;
            
            /** @brief deleted copy assignment */
            CommandCheckerResponder& operator=(CommandCheckerResponder const& aCommandCheckerResponder) = delete;
            
            /** @brief deleted move assignment */
            CommandCheckerResponder& operator=(CommandCheckerResponder&& aCommandCheckerResponder) = delete;

            /** @brief destructor to unregister the responder data members */
            ~CommandCheckerResponder();
    };
}

#endif