#include <SIUnitless.h>
#include <SISquareMeter.h>
#include "catch.hpp"
#include <SIMeter.h>
#include <SICubicMeter.h>


namespace SI {
    TEST_CASE("SISquareMeter constructors")
    {
        SECTION("SISquareMeter Double constructor")
        {
            SI::SISquareMeter result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SISquareMeter arithmetic operators")
    {
        SI::SISquareMeter fourMeterSqrd(4.0);
        SI::SISquareMeter twoMeterSqrd(2.0);
        SI::SIMeter       fourMeter(4.0);


        SECTION("SISquareMeter * SIMeter")
        {
            SI::SICubicMeter  result = fourMeterSqrd * fourMeter;
            CHECK(result() == 16.0);
        }

        SECTION("SISquareMeter / SIMeter")
        {
            SI::SIMeter       result = fourMeterSqrd / fourMeter;
            CHECK(result() == 1.0);
        }

        SECTION("SISquareMeter == SISquareMeter")
		{
            SI::SISquareMeter anotherfourMeterSqrd(4.0);

			//successful
			bool successful = (fourMeterSqrd == fourMeterSqrd);
			CHECK(successful == true); 

            //successful
			successful = (fourMeterSqrd == anotherfourMeterSqrd);
			CHECK(successful == true); 

			//unsuccessful
			successful = (twoMeterSqrd == fourMeterSqrd);
			CHECK(successful == false); 
		}

        SECTION("SISquareMeter / SISquareMeter")
        {
            SI::SIUnitless    result = fourMeterSqrd / twoMeterSqrd;
            CHECK(result() == 2.0);

        }

        SECTION("SISquareMeter = Double")
        {
            const double testValue{ 10.0 };
            SI::SISquareMeter result(1.0);
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}