#include <SIUnitless.h>
#include <SISquareMeter.h>
#include "catch.hpp"
#include <SIMeter.h>
#include <SICubicMeter.h>

namespace SI {
    TEST_CASE("SICubicMeter constructors")
    {
        SECTION("SICubicMeter Double constructor")
        {
            SI::SICubicMeter result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SICubicMeter arithmetic operators")
    {
        SI::SICubicMeter cubicMeter4(4.0);
        SI::SICubicMeter cubicMeter2(2.0);
        SI::SIMeter      meter4(4.0);

        SECTION("SICubicMeter / SIMeter")
        {
            SI::SISquareMeter result = cubicMeter4 / meter4;
            CHECK(result() == 1.0);
        }

        SECTION("SICubicMeter / SICubicMeter")
        {
            SI::SIUnitless result = cubicMeter4 / cubicMeter2;
            CHECK(result() == 2.0);
        }

    }
}