#include "catch.hpp"

#include <iostream>
#include <SIRadianPerSecond.h>
#include <SISecond.h>
#include <SIRadian.h>
#include <SIRadianPerSecondSquared.h>
#include <SIUnitless.h>

namespace SI {
    TEST_CASE("SIRadianPerSecond constructors")
    {
        SECTION("SIRadianPerSecond Double constructor")
        {
            SI::SIRadianPerSecond result(1.234);

            CHECK(result() == 1.234);
        }
    }


    TEST_CASE("SIRadianPerSecond arithmetic operators")
    {
        SI::SIRadianPerSecond  tenRadPerSec(10.0);
        SI::SISecond           twoSec(2.0);
        SI::SIRadianPerSecond  fiveRadPerSec(5.0);

        SECTION("SIRadianPerSecond * SISecond")
        {
            SI::SIRadian result = tenRadPerSec * twoSec;
            CHECK(result() == fmod(20.0, SI::SIRadian::PI()));
        }

        SECTION("SIRadianPerSecond / SISecond")
        {
            SI::SIRadianPerSecondSquared result = tenRadPerSec / twoSec;
            CHECK(result() == 5.0);
        }

        SECTION("SIRadianPerSecond / SIRadianPerSecond")
        {
            SI::SIUnitless  result = tenRadPerSec / fiveRadPerSec;
            CHECK(result() == 2.0);
        }

        SECTION("SIRadianPerSecond = Double")
        {
            const double testValue{ 0.785398163 }; // PI/4 rad 
            SI::SIRadianPerSecond result(1.0);
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}