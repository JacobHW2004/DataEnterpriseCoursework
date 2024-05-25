#include "NSIUnit.h"
#include "catch.hpp"

namespace NSI {
    TEST_CASE("NSIUnit class")
    {
		double testDouble { 6.66 };
		std::string testString { "m" };
		std::string expectedResult { std::to_string(testDouble) + testString};
		NSI::NSIUnit result(testDouble, testString);

		SECTION("Constructor value")
        {
			CHECK(result() == testDouble);
		}

		SECTION("toString()")
        {       	
			CHECK(result.toString() == expectedResult);
		}
    }
}
