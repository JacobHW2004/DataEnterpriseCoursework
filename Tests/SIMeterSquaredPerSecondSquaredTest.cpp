

#include <SIMeterSquaredPerSecondSquared.h>
#include "catch.hpp"


namespace SI {

    TEST_CASE("SIMeterSquaredPerSecondSquared constructor")
    {
        SECTION("SIMeterSquaredPerSecondSquared Double constructor")
        {
            SI::SIMeterSquaredPerSecondSquared result(1.234);

            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIMeterSquaredPerSecondSquared assignments")
    {
        SECTION("Self assignment")
        {
            SI::SIMeterSquaredPerSecondSquared selfAssignmentData(1.234);

            selfAssignmentData = selfAssignmentData;
            CHECK(selfAssignmentData() == 1.234);
        }

        SECTION("SIMeterSquaredPerSecondSquared assignment")
        {
            SI::SIMeterSquaredPerSecondSquared toBeAssignedData(2.345);

            SI::SIMeterSquaredPerSecondSquared result = toBeAssignedData;
            CHECK(result() == 2.345);
        }
    }

    SI::SIMeterSquaredPerSecondSquared oneMeterSquaredPerSecondSquared(1.0);
    SI::SIMeterSquaredPerSecondSquared oneMeterSquaredPerSecondSquaredSmaller(0.99);
    SI::SIMeterSquaredPerSecondSquared oneMeterSquaredPerSecondSquaredEqual(1.0);
    SI::SIMeterSquaredPerSecondSquared oneMeterSquaredPerSecondSquaredLarger(1.01);

    TEST_CASE("SIMeterSquaredPerSecondSquared == operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SIMeterSquaredPerSecondSquared, SI::SIMeterSquaredPerSecondSquared, bool>({
                        { oneMeterSquaredPerSecondSquared, oneMeterSquaredPerSecondSquaredSmaller, false },
                        { oneMeterSquaredPerSecondSquared, oneMeterSquaredPerSecondSquaredEqual,   true  },
                        { oneMeterSquaredPerSecondSquared, oneMeterSquaredPerSecondSquaredLarger,  false }
            }));
        CHECK((first == second) == result);
    }
}

