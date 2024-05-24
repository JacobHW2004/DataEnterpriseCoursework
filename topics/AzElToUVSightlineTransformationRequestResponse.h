#ifndef AZ_EL_TO_UV_SIGHTLINE_TRANSFORMATION_REQUEST_RESPONSE_H
#define AZ_EL_TO_UV_SIGHTLINE_TRANSFORMATION_REQUEST_RESPONSE_H

#include "UVSightline.h"
#include "AzElToUVSightlineTransformation.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    /**
    * @brief topic containing the relevant information for requesting a transformation
    * from a Sightline in AzEl into a UV Sightline. A Sightline in UV will always need to be in Frame 6UV.
    *
    */

    struct AzElToUVSightlineTransformationRequestResponse
    {
        /// Information associated with a request for transforming a Sightline in AzEl into a UV sightline
        AzElToUVSightlineTransformation azElToUVSightlineTransformationRequest {};

        /// Response containing a UVSightline
        UVSightline transformationResponse {};

        /**
        * @brief Serialise function required for communications
        */
        template <typename T>
        void Serialise(T& archive) {
            archive.Serialise(azElToUVSightlineTransformationRequest, "azElToUVSightlineTransformationRequest");
            archive.Serialise(transformationResponse, "transformationResponse");
        }

        LCA_TOPIC("AzElToUVSightlineTransformationRequestResponse", 1, 0)
    };

} //namespace Topics

#endif