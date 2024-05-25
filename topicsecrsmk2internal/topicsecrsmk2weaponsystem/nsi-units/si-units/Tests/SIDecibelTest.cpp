#include <SIUnitless.h>
#include "catch.hpp"
#include <SIDecibel.h>
#include <SIDegree.h>

namespace SI {
    TEST_CASE("SIDecibel constructors")
    {
        SECTION("SIDecibel Double constructor")
        {
            SI::SIDecibel result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIDecibel unit arithmetic")
    {
        SI::SIDecibel db4(4.0);
        SI::SIDecibel db2(2.0);

        SECTION("SIDecibel / SIDecibel")
        {
            SI::SIUnitless  result = db4 / db2;
            CHECK(result() == 2.0);
        }

        SECTION("SIDecibel = Double")
        {
            const double testValue{ 0.785398163 };
            SI::SIDecibel result(1.0);
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }

    TEST_CASE("SIDecibel assignments")
    {
        SI::SIDegree toBeAssignedDeg(2.345);
        SI::SIDegree uut1(1.234);

        SECTION("Self assignment")
        {
            uut1 = uut1;
            CHECK(uut1() == 1.234);
        }

        SECTION("SIDegree assignment")
        {
            SI::SIDegree result = toBeAssignedDeg;
            CHECK(result() == 2.345);
        }

    }
}