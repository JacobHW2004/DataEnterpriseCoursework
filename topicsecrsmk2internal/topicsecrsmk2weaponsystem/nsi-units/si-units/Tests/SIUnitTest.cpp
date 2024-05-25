#include <SIUnit.h>
#include "catch.hpp"

namespace SI {
    TEST_CASE("SIUnit class")
    {
		double testDouble { 6.66 };
		std::string testString { "m" };
		std::string expectedResult { std::to_string(testDouble) + testString};
		SI::SIUnit result(testDouble, testString);

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
