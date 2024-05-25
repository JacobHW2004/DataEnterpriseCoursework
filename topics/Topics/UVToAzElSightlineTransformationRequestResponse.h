#ifndef UV_TO_AZ_EL_SIGHTLINE_TRANSFORMATION_REQUEST_RESPONSE_H
#define UV_TO_AZ_EL_SIGHTLINE_TRANSFORMATION_REQUEST_RESPONSE_H

#include "Sightline.h"
#include "UVToAzElSightlineTransformation.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    /**
    * @brief topic containing the relevant information for requesting a transformation
    * from a UV Sightline to a Sightline in AzEl.
    */

    struct UVToAzElSightlineTransformationRequestResponse
    {
        /// Information associated with a request for transforming from a UVSightline
        UVToAzElSightlineTransformation uvToAzElSightlineTransformationRequest {};

        /// Response containing a Sightline transformed from UVSightline
        Sightline transformationResponse {};

        /**
        * @brief Serialise function required for communications
        */
        template <typename T>
        void Serialise(T& archive) {
            archive.Serialise(uvToAzElSightlineTransformationRequest, "uvToAzElSightlineTransformationRequest");
            archive.Serialise(transformationResponse, "transformationResponse");
        }

        LCA_TOPIC("UVToAzElSightlineTransformationRequestResponse", 1, 0)
    };

} //namespace Topics

#endif