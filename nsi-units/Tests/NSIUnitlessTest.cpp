#include "NSIUnitless.h"
#include "catch.hpp"

namespace NSI {
    TEST_CASE("NSIUnitless Double constructor")
    {
        NSI::NSIUnitless result(1.234);
        CHECK(result() == 1.234);
    }
}
