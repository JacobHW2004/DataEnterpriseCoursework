#include "catch.hpp"
#include <SIDecibel.h>
#include <SIAmplitudePower.h>

namespace SI {

    TEST_CASE("SIAMplitudePower constructors")
    {
        SI::SIDecibel db(-3.0);
        SECTION("Default constructor")
        {
            SI::SIAmplitudePower result;
            CHECK(result() == 1.0);
        }

        SECTION("Decibel constructor")
        {
            SI::SIAmplitudePower result(db);
            CHECK(result() == Approx(0.50118723).margin(0.0000001));
        }

    }
}