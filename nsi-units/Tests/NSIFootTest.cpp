
#include "catch.hpp"
#include <iostream>

#include "NSIUnitless.h"
#include "NSIFoot.h"
#include "NSINauticalMile.h"
#include "NSIMillimeter.h"
#include "SIMeter.h"

namespace NSI {

    TEST_CASE("NSIFoot constructors")
    {
        SECTION("NSIFoot Double Constructor")
        {
            NSI::NSIFoot result{1};
            CHECK(result() == 1);
        }
        
        SECTION("NSINauticalMile to NSIFoot constructor")
        {
            NSI::NSINauticalMile aNauticalMile {6.00};
            NSI::NSIFoot result(aNauticalMile);
            CHECK(result() == 36457);
        }

        SECTION("NSIMillimeter to NSIFoot constructor")
        {
            NSI::NSIMillimeter aMillimeter {6000};
            NSI::NSIFoot result(aMillimeter);
            CHECK(result() == 20);
        }

        SECTION("SIMeter to NSIFoot contructor")
        {
            SI::SIMeter aMeter {6.00};
            NSI::NSIFoot result(aMeter);
            CHECK(result() == Approx(20));
        }
    }

    TEST_CASE("NSIFoot arithmetic operators")
    {
        NSI::NSIFoot          twoFeet{2};
        NSI::NSIFoot          threeFeet{3};

        SECTION("NSIFoot + NSIFoot")
        {
            NSI::NSIFoot result = twoFeet + threeFeet;
            CHECK(result() == 5);
        }

        SECTION("NSIFoot - NSIFoot")
        {
            NSI::NSIFoot result = threeFeet - twoFeet;
            CHECK(result() == 1);
        }

        SECTION("NSIFoot / NSIFoot")
        {
            NSI::NSIUnitless result = threeFeet / twoFeet;
            CHECK(result() == 1.5);
        }

        SECTION("NSIFoot == NSIFoot")
        {
            NSI::NSIFoot anotherTwoFeet{2};

            //success
            bool successful = {twoFeet == twoFeet};
            CHECK(successful == true);

            //success
            successful = {twoFeet == anotherTwoFeet};
            CHECK(successful == true);

            //fail
            successful = {threeFeet == twoFeet};
            CHECK(successful == false);
        }

        SECTION("NSIFoot = Integer")
        {
            const int32_t testValue{ 1 };
            NSI:NSIFoot result{1};
            result = testValue;
            CHECK(result() == 1);
        }
        
    }

}