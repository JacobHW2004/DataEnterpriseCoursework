#include "catch.hpp"
#include <iostream>
#include <SIMeter.h>
#include <SISquareMeter.h>
#include <SIMeterPerSecond.h>
#include <SICubicMeter.h>
#include <SISecond.h>
#include <SIMeterPerSecondSquared.h>
#include <SISecondSquared.h>
#include <SIUnitless.h>

namespace SI {

    TEST_CASE("SIMeterPerSecond constructors")
    {
        SECTION("Double Constructor")
        {
            SI::SIMeterPerSecond result(1.234);
            CHECK(result() == 1.234);

        }
    }

    TEST_CASE("SIMeterPerSecond arithmetic operators")
    {
        SI::SISecond          twoSec(2.0);
        SI::SIMeterPerSecond  tenMeterPerSec(10.0);
        SI::SIMeterPerSecond  fiveMeterPerSec(5.0);

        SECTION("SIMeterPerSecond * SISecond")
        {
            SI::SIMeter result = tenMeterPerSec * twoSec;
            CHECK(result() == 20.0);
        }

        SECTION("SIMeterPerSecond / SISecond")
        {
            SI::SIMeterPerSecondSquared result = tenMeterPerSec / twoSec;
            CHECK(result() == 5.0);
        }

        SECTION("SIMeterPerSecond / SIMeterPerSecond")
        {
            SI::SIUnitless result = tenMeterPerSec / fiveMeterPerSec;
            CHECK(result() == 2.0);
        }

        SECTION("SIMeterPerSecond == SIMeterPerSecond")
		{
            SI::SIMeterPerSecond anothertenMeterPerSec(10.0);

			//successful
			bool successful = (tenMeterPerSec == tenMeterPerSec);
			CHECK(successful == true); 

            //successful
			successful = (tenMeterPerSec == anothertenMeterPerSec);
			CHECK(successful == true); 

			//unsuccessful
			successful = (fiveMeterPerSec == tenMeterPerSec);
			CHECK(successful == false); 
		}

        SECTION("SIMeterPerSecond = Double")
        {
            const double testValue{ 0.785398163 };
            SI::SIMeterPerSecond result(1.0);
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}