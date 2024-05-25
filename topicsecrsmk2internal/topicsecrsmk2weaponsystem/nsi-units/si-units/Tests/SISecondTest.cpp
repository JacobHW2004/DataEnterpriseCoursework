#include "catch.hpp"
#include <iostream>
#include <SISecond.h>
#include <SIMeterPerSecond.h>
#include <SIRadianPerSecond.h>
#include <SIMeter.h>
#include <SIUnitless.h>
#include <SIRadian.h>

using namespace Catch::Generators;
namespace SI {
    TEST_CASE("SISecond constructors")
    {
        SECTION("SISecond Double constructor")
        {
            SI::SISecond result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SISecond arithmetic operators")
    {
        SI::SISecond oneSec(1.0);
        SI::SISecond halfSec(0.5);
        SI::SISecond tenSec(10.0);
        SI::SISecond fiveSec(5.0);
        SI::SIMeterPerSecond        fiveMeterPerSec(5.0);
        SI::SIRadianPerSecond       twoRadPerSec(2.0);

        SECTION("SISecond + SISecond")
        {
            SI::SISecond result = oneSec + halfSec;
            CHECK(result() == 1.5);
        }

        SECTION("SISecond - SISecond")
        {
            SI::SISecond result = oneSec - halfSec;
            CHECK(result() == 0.5);
        }

        SECTION("SISecond * SIMeterPerSecond")
        {
            SI::SIMeter result = tenSec * fiveMeterPerSec;
            CHECK(result() == 50.0);
        }

        SECTION("SISecond * SIRadianPerSecond")
        {
            SI::SIRadian  result = tenSec * twoRadPerSec;
            CHECK(result() == fmod(20.0, SI::SIRadian::PI()));
        }

        SECTION("SISecond / SISecond")
        {
            SI::SIUnitless   result = tenSec / fiveSec;
            CHECK(result() == 2.0);
        }
    }

    SI::SISecond oneSec(1.0);
    SI::SISecond smaller(0.99);
    SI::SISecond equal(1.0);
    SI::SISecond larger(1.01);

    TEST_CASE("SISecond < operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SISecond, SI::SISecond, bool>({
                        { oneSec, smaller, false},
                        { oneSec, equal, false},
                        { oneSec, larger, true }
            }));

        CHECK((first < second) == result);
    }

    TEST_CASE("SISecond <= operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SISecond, SI::SISecond, bool>({
                        { oneSec, smaller, false},
                        { oneSec, equal, true},
                        { oneSec, larger, true }
            }));

        CHECK((first <= second) == result);
    }

    TEST_CASE("SISecond == operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SISecond, SI::SISecond, bool>({
                        { oneSec, smaller, false},
                        { oneSec, equal, true},
                        { oneSec, larger, false }
            }));
        CHECK((first == second) == result);
    }

    TEST_CASE("SISecond >= operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SISecond, SI::SISecond, bool>({
                        { oneSec, smaller, true},
                        { oneSec, equal, true},
                        { oneSec, larger, false }
            }));
        CHECK((first >= second) == result);
    }

    TEST_CASE("SISecond > operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SISecond, SI::SISecond, bool>({
                        { oneSec, smaller, true},
                        { oneSec, equal, false},
                        { oneSec, larger, false }
            }));
        CHECK((first > second) == result);
    }

    TEST_CASE("SISecond != operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SISecond, SI::SISecond, bool>({
                        { oneSec, smaller, true},
                        { oneSec, equal, false},
                        { oneSec, larger, true }
            }));
        CHECK((first != second) == result);
    }

    TEST_CASE("SISecond assigments")
    {
        SI::SISecond toBeAssignedSecond(2.345);
        double  toBeAssignedDbl (3.456);

        SECTION("SISecond self assigment - initialise variable then assign variable to itself ")
        {
            SI::SISecond result(1.234);
            result = result;
            CHECK(result() == 1.234);
        }


        SECTION("SISecond assignment - initialise variable then assign variable to another variable initialised as seconds")
        {
            SI::SISecond result(1.234);
            result = toBeAssignedSecond;
            CHECK(result() == 2.345);
        }

        SECTION("Double assignment - initialise variable then assign variable to another variable initialised as double")
        {
            SI::SISecond result(1.234);
            result = toBeAssignedDbl;
            CHECK(result() == 3.456);
        }

    }
}










