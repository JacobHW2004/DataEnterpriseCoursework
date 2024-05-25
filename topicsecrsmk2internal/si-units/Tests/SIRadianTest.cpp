#include "catch.hpp"
#include "SIRadian.h"
#include "SIDegree.h"
#include "SISecond.h"
#include "SISecondSquared.h"
#include "SIRadianPerSecond.h"
#include "SIRadianPerSecondSquared.h"
#include "SIUnitless.h"
#include <iostream>

namespace SI {
	TEST_CASE("SIRadian constructors")
    {
        SECTION("SIRadian Double constructor")
        {
			//within -PI and PI bounds
            SI::SIRadian result(1.234);
            CHECK(result() == 1.234);

			//check normalization less than -PI 
			SI::SIRadian negativeFourRad(-4);
            CHECK(negativeFourRad() == Approx(2.2831853072).epsilon(0.1));

			//check normalization more than PI
			SI::SIRadian fourRad(4);
            CHECK(fourRad() == Approx(-2.2831853072).epsilon(0.1));
        }

        SECTION("SIRadian copy Constructor")
        {
            SI::SIRadian toBeCopied(2.345);
            SI::SIRadian result(toBeCopied);
            CHECK(result() == 2.345);
        }

		SECTION("SIRadian SIDegree Constructor")
        {
            SI::SIDegree degrees(57.2958); 
            SI::SIRadian result(degrees);
            CHECK(result() == Approx(1).epsilon(0.1)); 
        }
    }

	TEST_CASE("SIRadian arithmetic functions")
	{
		SI::SIRadian negativeOneRad(-1);
		SI::SIRadian oneRad(1);
		SI::SIRadian zeroRad(0);

		SECTION("abs")
		{
			SIRadian result = negativeOneRad.abs();
			CHECK(result() == 1.0); // 1 rad
		}

		SECTION("acos")
		{
			SIRadian result = result.acos(1);
			CHECK(result() == 0); // 0 rad
		}

		SECTION("asin")
		{
			SIRadian result = result.asin(1);
			CHECK(result() == Approx(1.57079633).epsilon(0.1)); // PI/2 rad
		}

		SECTION("atan")
		{
			SIRadian result = result.atan(1);
			CHECK(result() == Approx(0.785398163).epsilon(0.1)); // PI/4 rad
		}

		SECTION("atan2")
		{
			//arc tangent of 2 numbers of y / x - results are expressed in radians
			SIRadian result = result.atan2(1, 2);
			CHECK(result() == Approx(0.463647609).epsilon(0.1));
		}

		SECTION("atan2 with a tolerance")
		{
			//arc tangent of 2 numbers of y / x with a tolerence - results are expressed in radians
			SIRadian result = result.atan2(1, 2, 0.1);
			CHECK(result() == Approx(0.463647609).epsilon(0.1));
		}

		SECTION("fabs")
		{
			SIRadian result = negativeOneRad.fabs();
			CHECK(result() == 1);
		}

		SECTION("inArc")
		{
			//successful
			SIRadian aFrom(-1.5708);
			SIRadian aTo(1.5708);
			SIRadian result(1);
			bool successful = result.inArc(aFrom, aTo);
			CHECK(successful == true);

			//unsuccessful
			aFrom = 1.5708;
			aTo = -1.5708;
			successful = result.inArc(aFrom, aTo);
			CHECK(successful == false);

		}

		SECTION("isApproximatelyEqual")
		{
			//successful
			SIRadian overOneRadian(1.00000000001);
			SIRadian tolerance(0.000001);
			bool successful = oneRad.isApproximatelyEqual(overOneRadian, tolerance);
			CHECK(successful == true);

			//unsuccessful
			overOneRadian = 1.001;
			successful = oneRad.isApproximatelyEqual(overOneRadian, tolerance);
			CHECK(successful == false);
		}

		SECTION("isPositive")
		{
			//successful
			bool successful = oneRad.isPositive();
			CHECK(successful == true);

			//boundary
			successful = zeroRad.isPositive();
			CHECK(successful == false);

			//unsuccessful
			successful = negativeOneRad.isPositive();
			CHECK(successful == false);
		}

		SECTION("zeroOrPositive")
		{
			//successful
			bool successful = oneRad.isZeroOrPositive();
			CHECK(successful == true);

			//boundary
			successful = zeroRad.isZeroOrPositive();
			CHECK(successful == true);

			//unsuccessful 
			successful = negativeOneRad.isZeroOrPositive();
			CHECK(successful == false);
		}

		SECTION("limitToMax")
		{
			//successful
			SIRadian result(oneRad);
			result.limitToMax(negativeOneRad);
			CHECK(result() == -1); 	//changes to -1

			//unsuccessful
			result = negativeOneRad;
			result.limitToMax(oneRad);
			CHECK(result() == -1); //stays at -1
		}

		SECTION("limitToMin")
		{
			//successful
			SIRadian result(negativeOneRad);
			result.limitToMin(oneRad);
			CHECK(result() == 1); //changes to 1

			//unsuccessful 
			result = oneRad;
			result.limitToMin(negativeOneRad);
			CHECK(result() == 1); //stays at 1
		}

		SECTION("tan")
		{
			double result = oneRad.tan();
			CHECK(result == Approx(1.57079633).epsilon(0.1)); // PI/2 rad
		}

		SECTION("toDegree")
		{
			SI::SIRadian fortyFiveDeg(0.785398163);
			SI::SIDegree result = fortyFiveDeg.toDegree();
			CHECK(result() == Approx(45).epsilon(0.1)); // 45 deg
		}

	}
	
	TEST_CASE("SIRadian arithmetic operators")
	{
		SI::SIRadian fortyFiveDeg(0.785398163);
		SI::SIRadian ninetyDeg(1.57079633);
		SI:SISecond twoSeconds(2);
		SISecondSquared twoSecondsSquared(2);
	
        SECTION("SIRadian * Double")
        {
        	SI::SIRadian result = fortyFiveDeg*2;
        	CHECK(result() == Approx(1.57079633).epsilon(0.1)); // PI/2 rad
		}

		SECTION("SIRadian *= Double")
        {
			SI::SIRadian result(0.785398163); //45 deg
        	result *=2;
        	CHECK(result() == Approx(1.57079633).epsilon(0.1)); // PI/2 rad
		}

		SECTION("SIRadian + SIRadian")
        {
			SI::SIRadian result = fortyFiveDeg + fortyFiveDeg;
        	CHECK(result() == Approx(1.57079633).epsilon(0.1)); // PI/2 rad
		}

		SECTION("SIRadian += SIRadian")
        {
			SI::SIRadian result(0.785398163); //45 deg
			result += fortyFiveDeg;
        	CHECK(result() == Approx(1.57079633).epsilon(0.1)); // PI/2 rad
		}

		SECTION("SIRadian - SIRadian")
        {
			SI::SIRadian result = ninetyDeg - fortyFiveDeg;
        	CHECK(result() == Approx(0.785398163).epsilon(0.1)); // PI/4 rad
		}

		SECTION("SIRadian -= SIRadian")
        {
			SI::SIRadian result(1.57079633); //90 deg
			result -= fortyFiveDeg;
        	CHECK(result() == Approx(0.785398163).epsilon(0.1)); // PI/4 rad
		}

		SECTION("SIRadian / double")
		{
			SI::SIRadian result = ninetyDeg / 2.0;
        	CHECK(result() == Approx(0.785398163).epsilon(0.1)); // PI/4 rad
		}

		SECTION("SIRadian / SISecond")
		{
			SI::SIRadianPerSecond result = ninetyDeg / twoSeconds;
			CHECK(result() == Approx(0.785398163).epsilon(0.1)); // PI/4 rad per second
		}

		SECTION("SIRadian / SISecondSquared")
		{
			SIRadianPerSecondSquared result = ninetyDeg / twoSecondsSquared;
			CHECK(result() == Approx(0.785398163).epsilon(0.1)); // PI/4 rad per second squared
		}

		SECTION("SIRadian / SIRadian")
		{
			SI::SIUnitless result = fortyFiveDeg / ninetyDeg;
			CHECK(result() == Approx(0.5).epsilon(0.1)); 
		}

		SECTION("SIRadian /= Double")
		{
			SI::SIRadian result = ninetyDeg; 
			result /=2; 
			CHECK(result() == Approx(0.785398163).epsilon(0.1)); // PI/4 rad 
		}

		SECTION("SIRadian < SIRadian")
		{
			//successful
			bool successful = (fortyFiveDeg < ninetyDeg);
			CHECK(successful == true); 

			//boundary
			successful = (fortyFiveDeg < fortyFiveDeg);
			CHECK(successful == false); 

			//unsuccessful
			successful = (ninetyDeg < fortyFiveDeg);
			CHECK(successful == false); 
		}

		SECTION("SIRadian <= SIRadian")
		{
			//successful
			bool successful = (fortyFiveDeg <= ninetyDeg);
			CHECK(successful == true); 

			//boundary
			successful = (fortyFiveDeg <= fortyFiveDeg);
			CHECK(successful == true); 

			//unsuccessful 
			successful = (ninetyDeg <= fortyFiveDeg);
			CHECK(successful == false); 
		}

		SECTION("SIRadian == SIRadian")
		{
			//successful
			bool successful = (fortyFiveDeg == fortyFiveDeg);
			CHECK(successful == true); 

			//unsuccessful
			successful = (ninetyDeg == fortyFiveDeg);
			CHECK(successful == false); 
		}

		SECTION("SIRadian > SIRadian")
		{
			//successful
			bool successful = (ninetyDeg > fortyFiveDeg);
			CHECK(successful == true); 
		
			//boundary
			successful = (fortyFiveDeg > fortyFiveDeg);
			CHECK(successful == false); 

			//unsuccessful 
			successful = (fortyFiveDeg > ninetyDeg);
			CHECK(successful == false); 
		}

		SECTION("SIRadian >= SIRadian")
		{
			//successful
			bool successful = (ninetyDeg >= fortyFiveDeg);
			CHECK(successful == true); 

			//boundary
			successful = (fortyFiveDeg >= fortyFiveDeg);
			CHECK(successful == true); 
	
			//unsuccessful
			successful = (fortyFiveDeg >= ninetyDeg);
			CHECK(successful == false); 
		}

	 	SECTION("SIRadian != SIRadian")
		{
			//successful
			bool successful = (fortyFiveDeg != ninetyDeg);
			CHECK(successful == true); 
	
			//unsuccessful
			successful = (fortyFiveDeg != fortyFiveDeg);
			CHECK(successful == false); 
		}

		SECTION("SIRadian = Double")
        {
			const double testValue{ 0.785398163 }; // PI/4 rad
            SI::SIRadian result(1.0);
            result = testValue;
        	CHECK(result() == Approx(testValue).epsilon(1.0e-10)); 
        }
	}
}
