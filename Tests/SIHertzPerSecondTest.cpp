#include <SIUnitless.h>
#include "catch.hpp"
#include <SIHertz.h>
#include <SISecond.h>
#include <SIHertzPerSecond.h>
#include <SIHertzPerSecondSquared.h>

namespace SI {
    TEST_CASE("SIHertzPerSecond constructors")
    {
        SECTION("SIHertzPerSecond Double constructor")
        {
            SI::SIHertzPerSecond result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIHertzPerSecond unit arithmetic")
    {
        SI::SIHertzPerSecond         fiftyHzPerSec(50.0);
        SI::SISecond                 twoSec(2.0);
        SI::SIHertzPerSecond         tenHzPerSec(10.0);

        SECTION("SIHertzPerSecond * SISecond")
        {
            SI::SIHertz result = fiftyHzPerSec * twoSec;
            CHECK(result() == 100.0);
        }

        SECTION("SIHertzPerSecond / SISecond")
        {
            SI::SIHertzPerSecondSquared result = fiftyHzPerSec / twoSec;
            CHECK(result() == 25.0);
        }

        SECTION("SIHertzPerSecond / SIHertzPerSecond")
        {
            SI::SIUnitless result = fiftyHzPerSec / tenHzPerSec;
            CHECK(result() == 5.0);
        }

    }
}

