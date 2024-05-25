#include "catch.hpp"
#include <iostream>
#include <SIHertz.h>
#include <SIUnitless.h>
#include <SISecond.h>
#include <SIHertzPerSecond.h>

namespace SI {
    TEST_CASE("SIHertz constructors")
    {
        SECTION("SIHertz Double constructor")
        {
            SI::SIHertz result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIHertz arithmetic operators")
    {
        SI::SIHertz      fiftyHz(50.0);
        SI::SISecond     twoSec(2.0);
        SI::SIHertz      tenHz(10.0);

        SECTION("SIHertz / SISecond")
        {
            SI::SIHertzPerSecond result = fiftyHz / twoSec;
            CHECK(result() == 25.0);
        }

        SECTION("SIHertz * SISecond")
        {
            SI::SIUnitless  result = fiftyHz * twoSec;
            CHECK(result() == 100.0);
        }

        SECTION("SIHertz / SIHertz")
        {
            SI::SIUnitless  result = fiftyHz / tenHz;
            CHECK(result() == 5.0);
        }
    }
}