#include "catch.hpp"
#include <iostream>
#include "NSIKnot.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include"NSIFeetPerMinute.h"
#include "SISecond.h"
#include "SISecondSquared.h"
#include "NSIUnitless.h"

namespace NSI {

    TEST_CASE("NSIKnot constructors")
    {
        SECTION("NSIKnot Double contructor")
        {
            NSI::NSIKnot result {1.234};
            CHECK(result() == 1.234);
        }

        SECTION("NSIFeetPerMinute to NSIKnots constructor")
        {
            NSI::NSIFeetPerMinute aFeetPerMinuteValue{600};
            NSI::NSIKnot result {aFeetPerMinuteValue};
            CHECK(result() == Approx(5.92484));
        }

        SECTION("SIMeterPerSecond to NSIKnots constructor")
        {
            SI::SIMeterPerSecond aMeterPerSecondValue{8.00};
            NSI::NSIKnot result {aMeterPerSecondValue};
            CHECK(result() == Approx(15.55072));
        }
    }

    TEST_CASE("NSIKnot arithmetic operators")
    {
        SI::SISecond            twoSec{2.0};
        NSI::NSIKnot              tenKnots{10.0};
        NSI::NSIKnot              fiveKnots{5.0};

        SECTION("NSIKnot + NSIKnot")
        {
            const NSIKnot result = tenKnots + fiveKnots;
            CHECK(result() == 15.0);
        }

        SECTION("NSIKnot == NSIKnot")
        {
            NSI::NSIKnot anotherKnotValue{10.0};

            //success
            bool successful = (tenKnots == tenKnots);
            CHECK(successful == true);

            //success
            successful = (tenKnots == anotherKnotValue);
            CHECK(successful == true);

            //fail
            successful = (fiveKnots == tenKnots);
            CHECK(successful == false);
        }

        SECTION("NSIKnot / NSIKnot")
        {
            NSI::NSIUnitless result = tenKnots / fiveKnots;
            CHECK(result() == 2.0);
        }

        SECTION("NSIKnot = Double")
        {
            const double testValue{ 0.983645271 };
            NSI::NSIKnot result{0.1};
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}