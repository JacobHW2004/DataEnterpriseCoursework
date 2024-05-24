#include "catch.hpp"

#include <iostream>
#include <SIRadianPerSecond.h>
#include <SISecond.h>
#include <SIRadian.h>
#include <SIRadianPerSecondSquared.h>
#include <SIUnitless.h>
#include <SISecondSquared.h>


namespace SI {
    TEST_CASE("SIRadianPerSecondSquared constructors")
    {
        SECTION("SIRadianPerSecondSquared Double constructor")
        {
            SI::SIRadianPerSecondSquared result(1.234);

            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIRadianPerSecondSquared arithmetic operators")
    {
        SI::SISecond   fourSec(4.0);
        SI::SISecondSquared  twoSecSqrd(2.0);
        SI::SIRadianPerSecondSquared  fiveRadrPerSec(5.0);
        SI::SIRadianPerSecondSquared  tenRadPerSecSqrd(10.0);

        SECTION("SIRadianPerSecondSquared * SISecondSquared")
        {
            SI::SIRadianPerSecond  result = tenRadPerSecSqrd * fourSec;
            CHECK(result() == 40.0);
        }

        SECTION("SIRadianPerSecondSquared * SISecond")
        {
            SI::SIRadian result = tenRadPerSecSqrd * twoSecSqrd;
            CHECK(result() == fmod(20.0, SI::SIRadian::PI()));
        }

        SECTION("SIRadianPerSecondSquared / SIRadianPerSecondSquared")
        {
            SI::SIUnitless result = tenRadPerSecSqrd / fiveRadrPerSec;
            CHECK(result() == 2.0);
        }

        SECTION("SIRadianPerSecondSquared = Double")
        {
            const double testValue{ 0.785398163 }; // PI/4 rad 
            SI::SIRadianPerSecondSquared result(1.0);
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}