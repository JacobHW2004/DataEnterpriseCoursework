#ifndef RADAR_INSTALLATION_CONSTANTS_REQUEST_RESPONSE_H
#define RADAR_INSTALLATION_CONSTANTS_REQUEST_RESPONSE_H

#include "RadarInstallationConstants.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {


struct RadarInstallationConstantsRequestResponse {

    RadarInstallationConstants radarInstallationConstantsResponse{};

    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(radarInstallationConstantsResponse, "radarInstallationConstantsResponse");
    }

    LCA_TOPIC("RadarInstallationConstantsRequestResponse", 1, 0)

};

}  // namespace Topics

#endif