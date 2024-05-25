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
    TEST_CASE("SIMeterPerSecondSquared constructors")
    {
        SECTION("Double constructor")
        {
            SI::SIMeterPerSecondSquared result(1.234);
            CHECK(result() == 1.234);

        }
    }

    TEST_CASE("SIMeterPerSecondSquared arithmetic operators")
    {
        SI::SIMeterPerSecondSquared  tenMeterPerSecSqrd(10.0);
        SI::SIMeterPerSecondSquared  fiveMeterPerSec(5.0);
        SI::SISecond                 fourSec(4.0);
        SI::SISecondSquared          twoSecSqrd(2.0);

        SECTION("SIMeterPerSecondSquared * SISecondSquared")
        {
            SI::SIMeterPerSecond         result = tenMeterPerSecSqrd * fourSec;
            CHECK(result() == 40.0);
        }

        SECTION("SIMeterPerSecondSquared * SISecond")
        {
            SI::SIMeter result = tenMeterPerSecSqrd * twoSecSqrd;
            CHECK(result() == 20.0);
        }

        SECTION("SIMeterPerSecondSquared / SIMeterPerSecondSquared")
        {
            SI::SIUnitless result = tenMeterPerSecSqrd / fiveMeterPerSec;
            CHECK(result() == 2.0);
        }

        SECTION("SIMeterPerSecondSquared == SIMeterPerSecondSquared")
		{
            SI::SIMeterPerSecondSquared anothertenMeterPerSecSqrd(10.0);

			//successful
			bool successful = (tenMeterPerSecSqrd == tenMeterPerSecSqrd);
			CHECK(successful == true); 

            //successful
			successful = (tenMeterPerSecSqrd == anothertenMeterPerSecSqrd);
			CHECK(successful == true); 

			//unsuccessful
			successful = (fiveMeterPerSec == tenMeterPerSecSqrd);
			CHECK(successful == false); 
		}
        
        SECTION("SIMeterPerSecondSquared = Double")
        {
            const double testValue{ 0.785398163 };
            SI::SIMeterPerSecondSquared result(1.0);
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }

    }
}

