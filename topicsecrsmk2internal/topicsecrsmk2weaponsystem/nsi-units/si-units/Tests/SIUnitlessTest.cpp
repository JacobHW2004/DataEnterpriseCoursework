#include <SIUnitless.h>
#include "catch.hpp"

namespace SI {
    TEST_CASE("SIUnitless Double constructor")
    {
        SI::SIUnitless result(1.234);
        CHECK(result() == 1.234);
    }
}
