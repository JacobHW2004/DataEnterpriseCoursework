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
    TEST_CASE("SIMeter constructors")
    {
        SECTION("SIMeter Double constructor")
        {
            SI::SIMeter result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIMeter arithmetic operators")
    {
        SI::SIMeter           twoMeter(2.0);
        SI::SIMeter           threeMeter(3.0);
        SI::SISquareMeter     fiveMeterSqrd(5.0);
        SI::SISecond twoSec(2.0);
        SI::SISecondSquared   fourSecSqrd(4.0);

        SECTION("SIMeter + SIMeter")
        {
            SI::SIMeter  result = twoMeter + threeMeter;
            CHECK(result() == 5.0);
        }

        SECTION("SIMeter - SIMeter")
        {
            SI::SIMeter  result = threeMeter - twoMeter;
            CHECK(result() == 1.0);
        }

        SECTION("SIMeter * SIMeter")
        {
            SI::SISquareMeter  result = twoMeter * threeMeter;
            CHECK(result() == 6.0);
        }

        SECTION("SIMeter * SISquareMeter")
        {
            SI::SICubicMeter result = twoMeter * fiveMeterSqrd;
            CHECK(result() == 10.0);
        }

        SECTION("SIMeter / SISecond")
        {
            SI::SIMeterPerSecond  result = twoMeter / twoSec;
            CHECK(result() == 1.0);
        }

        SECTION("SIMeter / SISecondSquared")
        {
            SI::SIMeterPerSecondSquared  result = twoMeter / fourSecSqrd;
            CHECK(result() == 0.5);
        }

        SECTION("SIMeter / SIMeter")
        {
            SI::SIUnitless  result = threeMeter / twoMeter;
            CHECK(result() == 1.5);
        }

        SECTION("SIMeter == SIMeter")
		{
            SI::SIMeter anothertwoMeter(2.0);

			//successful
			bool successful = (twoMeter == twoMeter);
			CHECK(successful == true); 

            //successful
			successful = (twoMeter == anothertwoMeter);
			CHECK(successful == true); 

			//unsuccessful
			successful = (threeMeter == twoMeter);
			CHECK(successful == false); 
		}

        SECTION("SIMeter = Double")
        {
            const double testValue{ 0.785398163 };
            SI::SIMeter result(1.0);
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}