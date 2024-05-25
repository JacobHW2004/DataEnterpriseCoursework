#include <SIDecibelsPerSquareMeter.h>
#include "catch.hpp"


namespace SI {

    TEST_CASE("SIDecibelsPerSquareMeter constructor")
    {
        SECTION("SIDecibelsPerSquareMeter Double constructor")
        {
            SI::SIDecibelsPerSquareMeter result(1.234);
            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIDecibelsPerSquareMeter assignments")
    {
        SI::SIDecibelsPerSquareMeter toBeAssignedDbsm(2.345);
        SI::SIDecibelsPerSquareMeter uut1(1.234);

        SECTION("Self assignment")
        {
            uut1 = uut1;
            CHECK(uut1() == 1.234);
        }

        SECTION("SIDecibelsPerSquareMeter assignment")
        {
            SI::SIDecibelsPerSquareMeter result = toBeAssignedDbsm;
            CHECK(result() == 2.345);
        }

    }

    SI::SIDecibelsPerSquareMeter oneDbsm(1.0);
    SI::SIDecibelsPerSquareMeter dbsmSmaller(0.99);
    SI::SIDecibelsPerSquareMeter dbsmEqual(1.0);
    SI::SIDecibelsPerSquareMeter dbsmLarger(1.01);

    TEST_CASE("SIDecibelsPerSquareMeter == operator")
    {
        auto [first, second, result] = GENERATE(table< SI::SIDecibelsPerSquareMeter, SI::SIDecibelsPerSquareMeter, bool>({
                        { oneDbsm, dbsmSmaller, false },
                        { oneDbsm, dbsmEqual,   true  },
                        { oneDbsm, dbsmLarger,  false }
            }));
        CHECK((first == second) == result);
    }

    SI::SIDecibelsPerSquareMeter oneDbsm_hp(1.0e-15);
    SI::SIDecibelsPerSquareMeter dbsmSmaller_hp(0.99999999999999e-15);
    SI::SIDecibelsPerSquareMeter dbsmEqual_hp(1.0e-15);
    SI::SIDecibelsPerSquareMeter dbsmLarger_hp(1.00000000000001e-15);

    TEST_CASE("SIDecibelsPerSquareMeter == operator (high precision)")
    {
        auto [first, second, result] = GENERATE(table< SI::SIDecibelsPerSquareMeter, SI::SIDecibelsPerSquareMeter, bool>({
                        { oneDbsm_hp, dbsmSmaller_hp, false },
                        { oneDbsm_hp, dbsmEqual_hp,   true  },
                        { oneDbsm_hp, dbsmLarger_hp,  false }
            }));
        CHECK((first == second) == result);
    }
}