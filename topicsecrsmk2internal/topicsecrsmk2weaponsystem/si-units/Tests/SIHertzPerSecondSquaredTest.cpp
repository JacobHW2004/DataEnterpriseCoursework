#include <SIUnitless.h>
#include "catch.hpp"
#include <SIHertz.h>
#include <SISecond.h>
#include <SIHertzPerSecond.h>
#include <SIHertzPerSecondSquared.h>

namespace SI {
    TEST_CASE("SIHertzPerSecondSquared constructors")
    {
        SECTION("SIHertzPerSecondSquared Double constructor")
        {
            SI::SIHertzPerSecondSquared result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIHertzPerSecondSquared unit arithmetic")
    {
        SI::SIHertzPerSecondSquared  fiftyHzPerSecSqrd(50.0);
        SI::SISecond                 twoSec(2.0);
        SI::SIHertzPerSecondSquared  tenHzPerSecSqrd(10.0);

        SECTION("SIHertzPerSecondSquared * SISecond ")
        {
            SI::SIHertzPerSecond  result = fiftyHzPerSecSqrd * twoSec;
            CHECK(result() == 100.0);
        }

        SECTION("SIHertzPerSecondSquared / SIHertzPerSecondSquared")
        {
            SI::SIUnitless    result = fiftyHzPerSecSqrd / tenHzPerSecSqrd;
            CHECK(result() == 5.0);
        }

    }
}

