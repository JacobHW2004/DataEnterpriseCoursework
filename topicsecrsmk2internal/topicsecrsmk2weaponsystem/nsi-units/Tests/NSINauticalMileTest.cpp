#include "catch.hpp"
#include <iostream>
#include "NSINauticalMile.h"
#include "NSIFoot.h"
#include "NSIMillimeter.h"
#include "SIMeter.h"
#include "NSIUnitless.h"

namespace NSI {

    TEST_CASE("NSINauticalMile constructors")
    {
        SECTION("NSINauticalMile Double contructor")
        {
            NSI::NSINauticalMile result {1.234};
            CHECK(result() == 1.234);
        }

        SECTION("NSIFoot to NSINauticaMile constructor")
        {
            NSI::NSIFoot aFoot {36000};
            NSI::NSINauticalMile result(aFoot);
            CHECK(result() == Approx(5.92483));
        }

        SECTION("NSIMillimeter to NSINauticaMile constructor")
        {
            NSI::NSIMillimeter aMillimeterValue {5556000};
            NSI::NSINauticalMile result(aMillimeterValue);
            CHECK(result() == Approx(3.00));
        }

        SECTION("SIMeter to NSINauticalMile constructor")
        {
            SI::SIMeter aMeter {10.00};
            NSI::NSINauticalMile result(aMeter);
            CHECK(result() == Approx(0.00539957));
        }
    }

    TEST_CASE("NSINauticalMile arithmetic operators")
    {
        NSI::NSINauticalMile          twoNM{2.0};
        NSI::NSINauticalMile          threeNM{3.0};

        SECTION("NSINauticalMile + NSINauticalMile")
        {
            NSI::NSINauticalMile result = twoNM + threeNM;
            CHECK(result() == 5.0);
        }

        SECTION("NSINauticalMile - NSINauticalMile")
        {
            NSI::NSINauticalMile result = threeNM - twoNM;
            CHECK(result() == 1.0);
        }

        SECTION("NSINauticalMile / NSINauticalMile")
        {
            NSI::NSIUnitless result = threeNM / twoNM;
            CHECK(result() == 1.5);
        }

        SECTION("NSINauticalMile == NSINauticalMile")
        {
            NSI::NSINauticalMile anotherTwoNM{2.0};

            //success
            bool successful = {twoNM == twoNM};
            CHECK(successful == true);

            //success
            successful = {twoNM == anotherTwoNM};
            CHECK(successful == true);

            //fail
            successful = {threeNM == twoNM};
            CHECK(successful == false);
        }

        SECTION("NSINauticalMile = Double")
        {
            const double testValue{ 0.657382910 };
            NSI::NSINauticalMile result{1.0};
            result = testValue;
            CHECK(result() == Approx(testValue).epsilon(1.0e-10));
        }
    }

}
