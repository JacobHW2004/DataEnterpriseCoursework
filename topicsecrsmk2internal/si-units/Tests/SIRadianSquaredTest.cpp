

#include <SIRadianSquared.h>
#include "catch.hpp"


namespace SI {

    TEST_CASE("SIRadianSquared constructor")
    {
        SECTION("SIRadianSquared Double constructor")
        {
            SI::SIRadianSquared result(1.234);

            CHECK(result() == 1.234);
        }
    }

    TEST_CASE("SIRadianSquared assignments")
    {
        SECTION("Self assignment")
        {
            SI::SIRadianSquared selfAssignmentData(1.234);

            selfAssignmentData = selfAssignmentData;
            CHECK(selfAssignmentData() == 1.234);
        }

        SECTION("SIRadianSquared assignment")
        {
            SI::SIRadianSquared toBeAssignedData(2.345);

            SI::SIRadianSquared result = toBeAssignedData;
            CHECK(result() == 2.345);
        }
    }

    SI::SIRadianSquared oneRadianSquared(1.0);
    SI::SIRadianSquared oneRadianSquaredSmaller(0.99);
    SI::SIRadianSquared oneRadianSquaredEqual(1.0);
    SI::SIRadianSquared oneRadianSquaredLarger(1.01);

    TEST_CASE("SIRadianSquared == operator")
    {
        auto [first, second, result] = GENERATE_REF(table< SI::SIRadianSquared, SI::SIRadianSquared, bool>({
                        { oneRadianSquared, oneRadianSquaredSmaller, false },
                        { oneRadianSquared, oneRadianSquaredEqual,   true  },
                        { oneRadianSquared, oneRadianSquaredLarger,  false }
            }));
        CHECK((first == second) == result);
    }
}

