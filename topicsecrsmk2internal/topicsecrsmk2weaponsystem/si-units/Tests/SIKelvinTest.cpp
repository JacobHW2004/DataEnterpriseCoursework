#include "catch.hpp"
#include <iostream>
#include "SIKelvin.h"
#include "SIUnitless.h"

namespace SI {

    TEST_CASE("SIKelvin constructors")
    {
        SECTION("SIKelvin Double contructor")
        {
            SI::SIKelvin result {1.234};
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIKelvin arithmetic operators")
    {
        SI::SIKelvin              tenKelvins{10.0};
        SI::SIKelvin              fiveKelvins{5.0};

        SECTION("SIKelvin + SIKelvin")
        {
            const SIKelvin result = tenKelvins + fiveKelvins;
            CHECK(result() == 15.0);
        }

        SECTION("SIKelvin == SIKelvin")
        {
            SI::SIKelvin anotherKelvinValue{10.0};

            //success
            bool successful = (tenKelvins == tenKelvins);
            CHECK(successful == true);

            //success
            successful = (tenKelvins == anotherKelvinValue);
            CHECK(successful == true);

            //fail
            successful = (fiveKelvins == tenKelvins);
            CHECK(successful == false);
        }

        SECTION("SIKelvin / Double")
        {
            SI::SIKelvin result = tenKelvins / 5.0;
            CHECK(result() == 2.0);
        }
        
        SECTION("SIKelvin * double")
        {
            const double testValue{2.0};
            SI::SIKelvin result = tenKelvins * testValue;
            CHECK(result() == 20.0);
        }

        SECTION("SIKelvin = Double")
        {
            const double testValue{ 0.983645271 };
            SI::SIKelvin result{0.1};
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }
}