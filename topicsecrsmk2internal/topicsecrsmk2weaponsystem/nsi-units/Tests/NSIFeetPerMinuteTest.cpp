#include "catch.hpp"
#include <iostream>
#include "NSIFeetPerMinute.h"
#include "NSIKnot.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "SISecond.h"
#include "SISecondSquared.h"
#include "NSIUnitless.h"

namespace NSI {

    TEST_CASE("NSIFeetPerMinute constructors")
    {
        SECTION("NSIFeetPerMinute Double contructor")
        {
            NSI::NSIFeetPerMinute result {1.234};
            CHECK(result() == 1.234);
        }

        SECTION("SIMeterPerSecond to NSIFeetPerMinutes constructor")
        {
            SI::SIMeterPerSecond aMeterPerSecondValue{7.00};
            NSI::NSIFeetPerMinute result {aMeterPerSecondValue};
            CHECK(result() == Approx(1377.95));
        }

        SECTION("Knots to NSIFeetPerMinutes constructor")
        {
            NSI::NSIKnot aKnot{7.00};
            NSI::NSIFeetPerMinute result {aKnot};
            CHECK(result() == Approx(708.88));
        }
    }

    TEST_CASE("NSIFeetPerMinute arithmetic operators")
    {
        NSI::NSIFeetPerMinute              tenFeetPerMinute{10.0};
        NSI::NSIFeetPerMinute              fiveFeetPerMinute{5.0};

        SECTION("NSIFeetPerMinute + NSIFeetPerMinute")
        {
            const NSIFeetPerMinute result = tenFeetPerMinute + fiveFeetPerMinute;
            CHECK(result() == 15.0);
        }

        SECTION("NSIFeetPerMinute == NSIFeetPerMinute")
        {
            NSI::NSIFeetPerMinute anotherFeetPerMinuteValue{10.0};

            //success
            bool successful = (tenFeetPerMinute == tenFeetPerMinute);
            CHECK(successful == true);

            //success
            successful = (tenFeetPerMinute == anotherFeetPerMinuteValue);
            CHECK(successful == true);

            //fail
            successful = (fiveFeetPerMinute == tenFeetPerMinute);
            CHECK(successful == false);
        }

        SECTION("NSIFeetPerMinute / NSIFeetPerMinute")
        {
            NSI::NSIUnitless result = tenFeetPerMinute / fiveFeetPerMinute;
            CHECK(result() == 2.0);
        }

        SECTION("NSIFeetPerMinute = Double")
        {
            const double testValue{ 0.983645271 };
            NSI::NSIFeetPerMinute result{0.1};
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}