#include "catch.hpp"
#include <iostream>
#include <SISecond.h>
#include <SISecondSquared.h>
#include <SIUnitless.h>

namespace SI {
    TEST_CASE("SISecondSquared constructors")
    {
        SECTION("SISecondSquared Double constructor")
        {
            SI::SISecondSquared result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SISecondSquared arithmetic operators")
    {
        SI::SISecondSquared    tenSecSqrd(10.0);
        SI::SISecond twoSec(2.0);
        SI::SISecondSquared    fiveSecSqrd(5.0);

        SECTION("SISecondSquared / SISecond")
        {
            SI::SISecond result = tenSecSqrd / twoSec;
            CHECK(result() == 5.0);
        }

        SECTION("SISecondSquared / SISecondSquared")
        {
            SI::SIUnitless   result = tenSecSqrd / fiveSecSqrd;
            CHECK(result() == 2.0);
        }
    }
}
