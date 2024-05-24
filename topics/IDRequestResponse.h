#ifndef ID_REQUEST_RESPONSE
#define ID_REQUEST_RESPONSE

#include "Fabric/Utils/LCA_Macros.h"
#include <cstdint>

namespace Topics {

    class IDRequestResponse {
    public:

        std::uint32_t idResponse{0};

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(idResponse, "idResponse");
        }

        LCA_TOPIC("IDRequestResponse", 1, 0)

    };

}


#endif
