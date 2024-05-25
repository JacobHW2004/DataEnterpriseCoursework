#ifndef ANTENNA_BEAM_CHARACTERISTICS_H
#define ANTENNA_BEAM_CHARACTERISTICS_H

#include "Fabric/Utils/LCA_Macros.h"
#include "Topics/UVSightline.h"

namespace Topics
{

    struct AntennaBeamCharacteristics
    {
        /**
         * @brief Topic struct to hold the characteristics of the antenna beam within a burst demand
         * 
         */

        UVSightline transmitSightline;


        /**
        * @brief Serialise/deserialise function required for communications
        */
        template <class T>
        void Serialise(T& archive) {

            archive.Serialise(transmitSightline, "transmitSightline");

        }

        LCA_TOPIC("AntennaBeamCharacteristics", 1, 0)

    };

}   //End namespace Topics

#endif