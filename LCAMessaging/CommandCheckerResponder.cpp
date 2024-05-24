#include "CommandCheckerResponder.h"
#include <chrono>
#include <string>

namespace CommandCheckerLCA
{
    CommandCheckerResponder::CommandCheckerResponder(
        std::shared_ptr<lca::container::ContainerContextInstance> const& aContext,
        std::shared_ptr<CommandChecker> aCommandCheckerPtr) : 
        mContextInstance{ aContext },
        mCommandChecker{ aCommandCheckerPtr },
        commandValidityResponder{
            aContext,
            [this]
            (lca::fabric::Responder<Topics::CommandValidityRequestResponse>::ReqPtr const request,
            lca::fabric::Responder<Topics::CommandValidityRequestResponse>::RespPtr response)
            {
                if (mCommandChecker != nullptr)
                {
                    response->get()->commandValidityResponse = mCommandChecker->ValidateVolumeParameters(request->get().commandValidityRequest.vol, request->get().commandValidityRequest.taskType);
                }
                else
                {
                    LOG_ERROR(
                        (std::shared_ptr<lca::container::ContainerContextInstance>(mContextInstance))->getLogger(), 
                        std::string{"CommandCheckerMessaging:: Error accessing business logic"}
                    )
                }
            }
        }
        {}

        CommandCheckerResponder::~CommandCheckerResponder()
        {
            commandValidityResponder.unregister();
        }
}