#ifndef STANAG_TRACKER_POSITION_TOPIC_H_
#define STANAG_TRACKER_POSITION_TOPIC_H_
#include <string>
#include <cmath>
#include "Fabric/Utils/LCA_Macros.h"

//The code contained in this file was written for the LSAF Demo and is not a work product of the Digital Radar Team
//This file contains topics required to display track data on the map component contained in the C# Bindings Application
//Which can be found here: http://desuk27was045v:7990/projects/LCFM/repos/lca_c-sharp_bindings/browse

namespace Topics
{
    namespace StanagTrackerTopics
    {
        class DegreesD {
        private:
            double_t val{ 0.0 };

        public:
            DegreesD() = default;
            DegreesD(double_t degreesIn) : val(degreesIn) {}

            // Serialiser
            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(val, "Value");
            }

            double_t getValue() const { return val; }

            LCA_TOPIC("com::leonardo::lsaf::DegreesD", 1, 0);
        };

        class LatDegreesD {
        private:
            DegreesD degrees{};

        public:
            LatDegreesD() = default;
            LatDegreesD(DegreesD degreesIn) : degrees(degreesIn) {}
            // Serialiser
            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(degrees, "DegreesD");
            }

            const DegreesD& getDegreesD() const { return degrees; }

            LCA_TOPIC("com::leonardo::lsaf::LatDegreesD", 1, 0);

        };

        class LonDegreesD {
        private:
            DegreesD degrees{};

        public:
            LonDegreesD() = default;
            LonDegreesD(DegreesD degreesIn) : degrees(degreesIn) {}
            // Serialiser
            template <class T>
            void Serialise(T& archive) {
                archive.Serialise(degrees, "DegreesD");
            }

            const DegreesD& getDegreesD() const { return degrees; }

            LCA_TOPIC("com::leonardo::lsaf::LonDegreesD", 1, 0);
        };

        class GeodeticCoordinateDegreesD {
        private:
            LatDegreesD lat{};
            LonDegreesD lon{};

        public:
            GeodeticCoordinateDegreesD() = default;
            GeodeticCoordinateDegreesD(LatDegreesD latIn, LonDegreesD lonIn) : lat(latIn), lon(lonIn) {}

            const LatDegreesD& getLat() const { return lat; }
            const LonDegreesD& getLon() const { return lon; }

            // Serialiser
            template <class T>
            void Serialise(T& archive){
                archive.Serialise(lat, "LatDegrees");
                archive.Serialise(lon, "LonDegrees");
            }
            LCA_TOPIC("com::leonardo::lsaf::GeodeticCoordinateDegreesD", 1, 0);
        };
    }
} 
#endif // #ifndef STANAG_TRACKER_POSITION_TOPIC_H_