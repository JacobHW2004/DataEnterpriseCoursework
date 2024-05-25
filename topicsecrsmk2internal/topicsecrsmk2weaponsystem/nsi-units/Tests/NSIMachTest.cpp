#include "catch.hpp"
#include <iostream>
#include "NSIMach.h"
#include "NSIFeetPerMinute.h"
#include "SIMeterPerSecond.h"
#include "NSIKnot.h"
#include "NSIUnitless.h"

namespace NSI {

    TEST_CASE("NSIMach constrsuctors")
    {
        SECTION("NSIMach Double contructor")
        {
            NSI::NSIMach result {1.234};
            CHECK(result() == 1.234);
        }

        SECTION("SIMeterPerSecond to NSIMach constructor")
        {
            SI::SIMeterPerSecond aMeterPerSecondValue{680.6};
            NSI::NSIMach result {aMeterPerSecondValue};
            CHECK(result() == Approx(1.9842566));
        }

        SECTION("NSIKnots to NSIMach constructor")
        {
            NSI::NSIKnot aKnot{2000};
            NSI::NSIMach result {aKnot};
            CHECK(result() == Approx(2.999676));
        }

         SECTION("NSIFeetPerMinute to NSIMach constructor")
        {
            NSI::NSIFeetPerMinute aFeetPerMinuteValue{450000};
            NSI::NSIMach result {aFeetPerMinuteValue};
            CHECK(result() == Approx(6.66472303));
        }
    }

    TEST_CASE("NSIMach arithmetic operators")
    {
        NSI::NSIMach              twoMachs{2.0};
        NSI::NSIMach              fiveMachs{5.0};

        SECTION("NSIMach + NSIMach")
        {
            const NSIMach result = twoMachs + fiveMachs;
            CHECK(result() == 7.0);
        }

        SECTION("NSIMach == NSIMach")
        {
            NSI::NSIMach anotherMachValue{2.0};

            //success
            bool successful = (twoMachs == twoMachs);
            CHECK(successful == true);

            //success
            successful = (twoMachs == anotherMachValue);
            CHECK(successful == true);

            //fail
            successful = (fiveMachs == twoMachs);
            CHECK(successful == false);
        }

        SECTION("NSIMach / NSIMach")
        {
            NSI::NSIUnitless result = twoMachs / fiveMachs;
            CHECK(result() == 0.4);
        }

        SECTION("NSIMach = Double")
        {
            const double testValue{ 0.983645271 };
            NSI::NSIMach result{0.1};
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}