#include "catch.hpp"
#include <iostream>
#include "SIKilogram.h"
#include "SIUnitless.h"

namespace SI {

    TEST_CASE("SIKilogram constructors")
    {
        SECTION("SIKilogram Double contructor")
        {
            SI::SIKilogram result {1.234};
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIKilogram arithmetic operators")
    {
        SI::SIKilogram              tenKilograms{10.0};
        SI::SIKilogram              fiveKilograms{5.0};

        SECTION("SIKilogram + SIKilogram")
        {
            const SIKilogram result = tenKilograms + fiveKilograms;
            CHECK(result() == 15.0);
        }

        SECTION("SIKilogram == SIKilogram")
        {
            SI::SIKilogram anotherKilogramValue{10.0};

            //success
            bool successful = (tenKilograms == tenKilograms);
            CHECK(successful == true);

            //success
            successful = (tenKilograms == anotherKilogramValue);
            CHECK(successful == true);

            //fail
            successful = (fiveKilograms == tenKilograms);
            CHECK(successful == false);
        }

        SECTION("SIKilogram / SIKilogram")
        {
            SI::SIKilogram result = tenKilograms / 5.0;
            CHECK(result() == 2.0);
        }

        SECTION("SIKilogram = Double")
        {
            const double testValue{ 0.983645271 };
            SI::SIKilogram result{0.1};
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}