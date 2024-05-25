#ifndef UV_MONOPULSE_CORRECTION_H
#define UV_MONOPULSE_CORRECTION_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {
    namespace SipTopics {

        class UVMonopulseCorrection {
            /* Topic to represent the correction that is to be applied to a UV sightline. */

        public:

            float UCorrection{ 0.0F };
            float VCorrection{ 0.0F };

            UVMonopulseCorrection() = default;

            UVMonopulseCorrection(
                float UCorrection,
                float VCorrection
            )
                :UCorrection(UCorrection),
                VCorrection(VCorrection)
            {}

            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(UCorrection, "UCorrection");
                archive.Serialise(VCorrection, "VCorrection");
            }

            LCA_TOPIC("UVMonopulseCorrection", 1, 0);
        };
    }
}
#endif // #ifndef UV_MONOPULSE_CORRECTION_H
