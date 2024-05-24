#include <FloatEqualityChecker.h>
#include <SIUnit.h>
#include "catch.hpp"

namespace SI {
    TEST_CASE("FloatEqualityChecker class - AlmostEqual (float, float, float)")
    {
		SECTION("Exact match")
        {
			//values exactly the same
			CHECK(floatEqualityChecker::AlmostEqual(0.01F, 0.01F) == true);
		}

		SECTION("Within threshold")
        {
			//left and right values within threshold of each other
			CHECK(floatEqualityChecker::AlmostEqual(0.01F, 0.02F, 0.01F) == true);
			CHECK(floatEqualityChecker::AlmostEqual(0.02F, 0.01F, 0.01F) == true);
		}

		SECTION("Outside threshold")
        {
			//left and right values not within threshold of each other
			CHECK(floatEqualityChecker::AlmostEqual(0.01F, 0.02F, 0.001F) == false);
			CHECK(floatEqualityChecker::AlmostEqual(0.02F, 0.01F, 0.001F) == false);
		}

		SECTION("Bounds check")
        {
			CHECK(floatEqualityChecker::AlmostEqual(0.1F, 0.11F, 0.01F ) == true); //exact threshold
			CHECK(floatEqualityChecker::AlmostEqual(0.1F, 0.11F, 0.011F) == true); //threshold greater
			CHECK(floatEqualityChecker::AlmostEqual(0.1F, 0.11F, 0.009F) == false); //threshold under

			CHECK(floatEqualityChecker::AlmostEqual(0.11F, 0.1F, 0.01F ) == true); //exact threshold
			CHECK(floatEqualityChecker::AlmostEqual(0.11F, 0.1F, 0.011F) == true); //threshold greater
			CHECK(floatEqualityChecker::AlmostEqual(0.11F, 0.1F, 0.009F) == false); //threshold under
		}

		SECTION("Negative comparison values")
        {
			//negative values used for comparisons
			CHECK(floatEqualityChecker::AlmostEqual(-0.1F, -0.11F,  0.01F ) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.1F, -0.11F,  0.011F) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.1F, -0.11F,  0.009F) == false);

			CHECK(floatEqualityChecker::AlmostEqual(-0.11F, -0.1F,  0.01F ) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.11F, -0.1F,  0.011F) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.11F, -0.1F,  0.009F) == false);
		}

		SECTION("Mixed comparison values")
        {
			//mixed positive and negative values used for comparisons
			CHECK(floatEqualityChecker::AlmostEqual(-0.1F,  0.1F,  0.2F ) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.1F,  0.1F,  0.21F) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.1F,  0.1F,  0.19F) == false);

			CHECK(floatEqualityChecker::AlmostEqual(0.1F,  -0.1F,  0.2F ) == true);
			CHECK(floatEqualityChecker::AlmostEqual(0.1F,  -0.1F,  0.21F) == true);
			CHECK(floatEqualityChecker::AlmostEqual(0.1F,  -0.1F,  0.19F) == false);
		}

		SECTION("Negative threshold values")
        {
			//threshold values should be positive, but making sure this still works even if someone puts in a negative value
			CHECK(floatEqualityChecker::AlmostEqual( 0.1F,  0.11F, -0.01F ) == true);
			CHECK(floatEqualityChecker::AlmostEqual( 0.11F,  0.1F, -0.01F ) == true);
		}
	}

	TEST_CASE("FloatEqualityChecker class - AlmostEqual (double, double, double)")
    {
		SECTION("Exact match")
        {
			//values exactly the same
			CHECK(floatEqualityChecker::AlmostEqual(0.01, 0.01) == true);
		}

		SECTION("Within threshold")
        {
			//left and right values within threshold of each other
			CHECK(floatEqualityChecker::AlmostEqual(0.01, 0.02, 0.01) == true);
			CHECK(floatEqualityChecker::AlmostEqual(0.02, 0.01, 0.01) == true);
		}

		SECTION("Outside threshold")
        {
			//left and right values not within threshold of each other
			CHECK(floatEqualityChecker::AlmostEqual(0.01, 0.02, 0.001) == false);
			CHECK(floatEqualityChecker::AlmostEqual(0.02, 0.01, 0.001) == false);
		}

		SECTION("Bounds check")
        {
			CHECK(floatEqualityChecker::AlmostEqual(0.1, 0.11, 0.01 ) == true); //exact threshold
			CHECK(floatEqualityChecker::AlmostEqual(0.1, 0.11, 0.011) == true); //threshold greater
			CHECK(floatEqualityChecker::AlmostEqual(0.1, 0.11, 0.009) == false); //threshold under

			CHECK(floatEqualityChecker::AlmostEqual(0.11, 0.1, 0.01 ) == true); //exact threshold
			CHECK(floatEqualityChecker::AlmostEqual(0.11, 0.1, 0.011) == true); //threshold greater
			CHECK(floatEqualityChecker::AlmostEqual(0.11, 0.1, 0.009) == false); //threshold under
		}

		SECTION("Negative comparison values")
        {
			//negative values used for comparisons
			CHECK(floatEqualityChecker::AlmostEqual(-0.1, -0.11,  0.01 ) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.1, -0.11,  0.011) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.1, -0.11,  0.009) == false);

			CHECK(floatEqualityChecker::AlmostEqual(-0.11, -0.1,  0.01 ) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.11, -0.1,  0.011) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.11, -0.1,  0.009) == false);
		}

		SECTION("Mixed comparison values")
        {
			//mixed positive and negative values used for comparisons
			CHECK(floatEqualityChecker::AlmostEqual(-0.1,  0.1,  0.2 ) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.1,  0.1,  0.21) == true);
			CHECK(floatEqualityChecker::AlmostEqual(-0.1,  0.1,  0.19) == false);

			CHECK(floatEqualityChecker::AlmostEqual(0.1,  -0.1,  0.2 ) == true);
			CHECK(floatEqualityChecker::AlmostEqual(0.1,  -0.1,  0.21) == true);
			CHECK(floatEqualityChecker::AlmostEqual(0.1,  -0.1,  0.19) == false);
		}

		SECTION("Negative threshold values")
        {
			//threshold values should be positive, but making sure this still works even if someone puts in a negative value
			CHECK(floatEqualityChecker::AlmostEqual( 0.1,  0.11, -0.01) == true);
			CHECK(floatEqualityChecker::AlmostEqual( 0.11,  0.1, -0.01) == true);
		}
	}
}
