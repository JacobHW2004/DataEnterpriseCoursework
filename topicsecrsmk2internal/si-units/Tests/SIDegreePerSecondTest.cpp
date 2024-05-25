#include "catch.hpp"

#include <iostream>
#include <SIDegreePerSecond.h>
#include <SISecond.h>
#include <SIDegree.h>
#include <SIDegreePerSecondSquared.h>
#include <SIUnitless.h>

namespace SI {
    TEST_CASE("SIDegreePerSecond constructors")
    {
        SECTION("SIDegreePerSecond Double constructor")
        {
            SI::SIDegreePerSecond result(1.234);

            CHECK(result() == 1.234);
        }
    }


    TEST_CASE("SIDegreePerSecond arithmetic operators")
    {
        SI::SIDegreePerSecond  ninetyDegPerSec(90.0);
        SI::SISecond           twoSec(2.0);
        SI::SIDegreePerSecond  fifteenDegPerSec(15.0);

        SECTION("SIDegreePerSecond * SISecond")
        {
            SI::SIDegree result = ninetyDegPerSec * twoSec;
            CHECK(result() == 180.0);
        }

        SECTION("SIDegreePerSecond / SISecond")
        {
            SI::SIDegreePerSecondSquared result = ninetyDegPerSec / twoSec;
            CHECK(result() == 45.0);
        }

        SECTION("SIDegreePerSecond / SIDegreePerSecond")
        {
            SI::SIUnitless  result = ninetyDegPerSec / fifteenDegPerSec;
            CHECK(result() == 6.0);
        }

        SECTION("SIDegreePerSecond == SIDegreePerSecond")
		{
            SI::SIDegreePerSecond anotherDegreePerSecVal(15.0);

			//successful
			bool successful = (fifteenDegPerSec == fifteenDegPerSec);
			CHECK(successful == true); 

            //successful
			successful = (fifteenDegPerSec == anotherDegreePerSecVal);
			CHECK(successful == true); 

			//unsuccessful
			successful = (ninetyDegPerSec == fifteenDegPerSec);
			CHECK(successful == false); 
		}
    }
}