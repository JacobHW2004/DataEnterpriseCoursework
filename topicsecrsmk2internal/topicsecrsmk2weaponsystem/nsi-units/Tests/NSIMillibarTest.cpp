#include "catch.hpp"
#include <iostream>
#include "NSIMillibar.h"
#include "NSIUnitless.h"

namespace NSI {

    TEST_CASE("NSIMillibar constructors")
    {
        SECTION("NSIMillibar Double contructor")
        {
            NSI::NSIMillibar result {1.234};
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("NSIMillibar arithmetic operators")
    {
        NSI::NSIMillibar              tenMillibars{10.0};
        NSI::NSIMillibar              fiveMillibars{5.0};

        SECTION("NSIMillibar + NSIMillibar")
        {
            const NSIMillibar result = tenMillibars + fiveMillibars;
            CHECK(result() == 15.0);
        }

        SECTION("NSIMillibar == NSIMillibar")
        {
            NSI::NSIMillibar anotherMillibarValue{10.0};

            //success
            bool successful = (tenMillibars == tenMillibars);
            CHECK(successful == true);

            //success
            successful = (tenMillibars == anotherMillibarValue);
            CHECK(successful == true);

            //fail
            successful = (fiveMillibars == tenMillibars);
            CHECK(successful == false);
        }

        SECTION("NSIMillibar / NSIMillibar")
        {
            NSI::NSIUnitless result = tenMillibars / fiveMillibars;
            CHECK(result() == 2.0);
        }

        SECTION("NSIMillibar = Double")
        {
            const double testValue{ 0.983645271 };
            NSI::NSIMillibar result{0.1};
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}