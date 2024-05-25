#include "catch.hpp"
#include <iostream>
#include "NSIGForce.h"
#include "NSIUnitless.h"

namespace NSI {

    TEST_CASE("NSIGForce constructors")
    {
        SECTION("NSIGForce Double contructor")
        {
            NSI::NSIGForce result {1.234};
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("NSIGForce arithmetic operators")
    {
        NSI::NSIGForce              tenGForces{10.0};
        NSI::NSIGForce              fiveGForces{5.0};

        SECTION("NSIGForce + NSIGForce")
        {
            const NSIGForce result = tenGForces + fiveGForces;
            CHECK(result() == 15.0);
        }

        SECTION("NSIGForce == NSIGForce")
        {
            NSI::NSIGForce anotherGForceValue{10.0};

            //success
            bool successful = (tenGForces == tenGForces);
            CHECK(successful == true);

            //success
            successful = (tenGForces == anotherGForceValue);
            CHECK(successful == true);

            //fail
            successful = (fiveGForces == tenGForces);
            CHECK(successful == false);
        }

        SECTION("NSIGForce / NSIGForce")
        {
            NSI::NSIUnitless result = tenGForces / fiveGForces;
            CHECK(result() == 2.0);
        }

        SECTION("NSIGForce = Double")
        {
            const double testValue{ 0.983645271 };
            NSI::NSIGForce result{0.1};
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}