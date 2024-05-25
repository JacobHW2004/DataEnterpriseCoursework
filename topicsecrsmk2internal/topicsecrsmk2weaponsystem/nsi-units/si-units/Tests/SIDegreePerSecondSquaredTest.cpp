#include "catch.hpp"

#include <iostream>
#include <SIDegreePerSecond.h>
#include <SISecond.h>
#include <SIDegree.h>
#include <SIDegreePerSecondSquared.h>
#include <SIUnitless.h>
#include <SISecondSquared.h>


namespace SI {
    TEST_CASE("SIDegreePerSecondSquared constructors")
    {
        SECTION("SIDegreePerSecondSquared Double constructor")
        {
            SI::SIDegreePerSecondSquared result(1.234);

            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIDegreePerSecondSquared arithmetic operators")
    {
        SI::SISecond   fourSec(4.0);
        SI::SISecondSquared  twoSecSqrd(2.0);
        SI::SIDegreePerSecondSquared  fiveDegrPerSecSqrd(5.0);
        SI::SIDegreePerSecondSquared  tenDegPerSecSqrd(10.0);

        SECTION("SIDegreePerSecondSquared * SISecond")
        {
            SI::SIDegreePerSecond  result = tenDegPerSecSqrd * fourSec;
            CHECK(result() == 40.0);
        }

        SECTION("SIDegreePerSecondSquared * SISecondSquarded")
        {
            
            SI::SIDegree result = tenDegPerSecSqrd * twoSecSqrd;
            CHECK(result() == 20.0);
        }

        SECTION("SIDegreePerSecondSquared / SIDegreePerSecondSquared")
        {
            SI::SIUnitless result = tenDegPerSecSqrd / fiveDegrPerSecSqrd;
            CHECK(result() == 2.0);
        }

        SECTION("SIDegreePerSecondSquared == SIDegreePerSecondSquared")
		{
            SI::SIDegreePerSecondSquared anotherDegreePerSecSqrdVal(5.0);

			//successful
			bool successful = (fiveDegrPerSecSqrd == fiveDegrPerSecSqrd);
			CHECK(successful == true); 

            //successful
			successful = (fiveDegrPerSecSqrd == anotherDegreePerSecSqrdVal);
			CHECK(successful == true); 

			//unsuccessful
			successful = (tenDegPerSecSqrd == fiveDegrPerSecSqrd);
			CHECK(successful == false); 
		}
    }
}