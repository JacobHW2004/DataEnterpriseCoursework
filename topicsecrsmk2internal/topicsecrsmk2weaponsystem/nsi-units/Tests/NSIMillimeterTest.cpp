#include "catch.hpp"
#include <iostream>

#include "NSIUnitless.h"
#include "NSIMillimeter.h"
#include "NSIFoot.h"
#include "NSINauticalMile.h"
#include "SIMeter.h"

namespace NSI {

    TEST_CASE("NSIMillimeter constructors")
    {
        
        SECTION("NSINauticalMile to NSIMillimeter constructor")
        {
            NSI::NSINauticalMile aNauticalMile {6.00};
            NSI::NSIMillimeter result(aNauticalMile);
            CHECK(result() == 11112000);
        }

        SECTION("NSIFoot to NSIMillimeter constructor")
        {
            NSI::NSIFoot aFoot {7};
            NSI::NSIMillimeter result(aFoot);
            CHECK(result() == Approx(2134));
        }

        SECTION("SIMeter to NSIMillimeter contructor")
        {
            SI::SIMeter aMeter {6.00};
            NSI::NSIMillimeter result(aMeter);
            CHECK(result() == 6000);
        }
    }

    TEST_CASE("NSIMillimeter arithmetic operators")
    {
        NSI::NSIMillimeter          twoMm{2};
        NSI::NSIMillimeter          threeMm{3};

        SECTION("NSIMillimeter + NSIMillimeter")
        {
            NSI::NSIMillimeter result = twoMm + threeMm;
            CHECK(result() == 5);
        }

        SECTION("NSIMillimeter - NSIMillimeter")
        {
            NSI::NSIMillimeter result = threeMm - twoMm;
            CHECK(result() == 1);
        }

        SECTION("NSIMillimeter / NSIMillimeter")
        {
            NSI::NSIUnitless result = threeMm / twoMm;
            CHECK(result() == 1.5);
        }

        SECTION("NSIMillimeter == NSIMillimeter")
        {
            NSI::NSIMillimeter anotherTwoMm{2};

            //success
            bool successful = {twoMm == twoMm};
            CHECK(successful == true);

            //success
            successful = {twoMm == anotherTwoMm};
            CHECK(successful == true);

            //fail
            successful = {threeMm == twoMm};
            CHECK(successful == false);
        }

        SECTION("NSIMillimeter = Integer")
        {
            const int32_t testValue{ 1 };
            NSI:NSIMillimeter result{1};
            result = testValue;
            CHECK(result() == 1);
        }
        
    }

}