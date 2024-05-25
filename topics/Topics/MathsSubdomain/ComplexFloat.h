#ifndef COMPLEX_FLOAT_H
#define COMPLEX_FLOAT_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    class ComplexFloat {
    /**
    * @brief Topic class to represent a complex number to single precision accuracy
    *
    */

    public:
        float re{ 0.0f };
        float im{ 0.0f };

        ComplexFloat() = default;

        ComplexFloat(const float real, const float imag) :
            re(real),
            im(imag)
        {}

        /**
        * @brief Serialise function required for communications. Also performs de-serialisation
        */
        template <class T>
        void Serialise(T& archive) {

            archive.Serialise(re, "re");
            archive.Serialise(im, "im");

        }

        LCA_TOPIC("ComplexFloat", 1, 0)
    };
} 

#endif
