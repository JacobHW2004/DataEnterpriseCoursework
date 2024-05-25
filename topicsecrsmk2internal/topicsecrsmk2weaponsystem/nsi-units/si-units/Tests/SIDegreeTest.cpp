#include "catch.hpp"
#include <iostream>
#include <SIDegree.h>
#include <SIUnitless.h>

namespace SI {
    TEST_CASE("SIDegree constructors")
    {
        SECTION("SIDegree Double constructor")
        {
            SI::SIDegree result(1.234);
            CHECK(result() == 1.234);
        }

        SECTION("SIDegree Copy Constructor")
        {
            SI::SIDegree toBeCopied(2.345);
            SI::SIDegree result(toBeCopied);
            CHECK(result() == 2.345);
        }
    }

    TEST_CASE("SIDegree assigments")
    {
        SI::SIDegree toBeAssignedDeg(2.345);
        double  toBeAssignedDbl = 3.456;

        SECTION("SIDegree self assigment - initialise variable then assign variable to itself ")
        {
            SI::SIDegree result(1.234);
            result = result;
            CHECK(result() == 1.234);
        }


        SECTION("SIDegree assignment - initialise variable then assign variable to another variable initialised as degrees")
        {
            SI::SIDegree result(1.234);
            result = toBeAssignedDeg;
            CHECK(result() == 2.345);
        }

        SECTION("Double assignment - - initialise variable then assign variable to another variable initialised as double")
        {
            SI::SIDegree result(1.234);
            result = toBeAssignedDbl;
            CHECK(result() == 3.456);
        }

    }

    TEST_CASE("SIDegree arithmetic operators")
    {
        SI::SIDegree fortyFiveDeg(45.0);
        SI::SIDegree ninetyDeg(90.0);

        SECTION("SIDegree / SIDegree")
        {
            SI::SIDegree fiftyDeg(50.0);
            SI::SIDegree tenDeg(10.0);

            SI::SIUnitless result = fiftyDeg / tenDeg;
            CHECK(result() == 5.0);
        }
        SECTION("SIDegree == SIDegree")
		{
            SI::SIDegree anotherFortyFiveDeg(45.0);

			//successful
			bool successful = (fortyFiveDeg == fortyFiveDeg);
			CHECK(successful == true); 

            //successful
			successful = (fortyFiveDeg == anotherFortyFiveDeg);
			CHECK(successful == true); 


			//unsuccessful
			successful = (ninetyDeg == fortyFiveDeg);
			CHECK(successful == false); 
		}

    }
}