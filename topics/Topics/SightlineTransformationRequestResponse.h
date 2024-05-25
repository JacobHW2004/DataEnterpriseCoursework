#ifndef SIGHTLINE_TRANSFORMATION_REQUEST_RESPONSE_H
#define SIGHTLINE_TRANSFORMATION_REQUEST_RESPONSE_H

#include "Sightline.h"
#include "SightlineTransformation.h"
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    /**
    * @brief Topic associated with a request and response to transform a Sightline's frame of reference and its coordinates into another frame of reference
    *
    */

    struct SightlineTransformationRequestResponse
    {
        /// Information associated with a request for transforming a Sightline's frame of reference and its coordinates
        SightlineTransformation sightlineTransformationRequest {};

        /// Response containing a Sightline with the requested frame of reference and transformed coordinates
        Sightline sightlineTransformationResponse {};

        /**
        * @brief Serialise function required for communications
        */
        template <typename T>
        void Serialise(T& archive) {
            archive.Serialise(sightlineTransformationRequest, "sightlineTransformationRequest");
            archive.Serialise(sightlineTransformationResponse, "sightlineTransformationResponse");
        }

        LCA_TOPIC("SightlineTransformationRequestResponse", 1, 0)
    };

} //namespace Topics

#endif