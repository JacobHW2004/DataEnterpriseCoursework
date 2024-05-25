

#include <SIMeterSquared.h>
#include "catch.hpp"


namespace SI {

    TEST_CASE("SIMeterSquared constructor")
    {
        SECTION("SIMeterSquared Double constructor")
        {
            SI::SIMeterSquared result(1.234);

            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIMeterSquared assignments")
    {
        SECTION("Self assignment")
        {
            SI::SIMeterSquared selfAssignmentData(1.234);

            selfAssignmentData = selfAssignmentData;
            CHECK(selfAssignmentData() == 1.234);
        }

        SECTION("SIMeterSquared assignment")
        {
            SI::SIMeterSquared toBeAssignedData(2.345);

            SI::SIMeterSquared result = toBeAssignedData;
            CHECK(result() == 2.345);
        }
    }

    SI::SIMeterSquared oneMeterSquared(1.0);
    SI::SIMeterSquared oneMeterSquaredSmaller(0.99);
    SI::SIMeterSquared oneMeterSquaredEqual(1.0);
    SI::SIMeterSquared oneMeterSquaredLarger(1.01);

    TEST_CASE("SIMeterSquared == operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SIMeterSquared, SI::SIMeterSquared, bool>({
                        { oneMeterSquared, oneMeterSquaredSmaller, false },
                        { oneMeterSquared, oneMeterSquaredEqual,   true  },
                        { oneMeterSquared, oneMeterSquaredLarger,  false }
            }));
        CHECK((first == second) == result);
    }
}

