
#include "SIRadian.h"
#include "FloatEqualityChecker.h"
#include "SIDegree.h"
#include "SIRadianPerSecond.h"
#include "SIRadianPerSecondSquared.h"
#include "SISecond.h"
#include "SISecondSquared.h"
#include "SIUnitless.h"

namespace SI{

const double SIRadian::DEG_180(180.0);

SIRadian::SIRadian(const SIDegree& aDegree) : SIUnit(normalizeRadian((aDegree() / DEG_180) * PI()), "rad")
{
    
}

SIRadian::SIRadian(const double aValue) : SIUnit(normalizeRadian(aValue), "rad")
{
    
}

SIRadian::SIRadian(void) : SIUnit(0.0, "rad")
{
   
}

SIRadian SIRadian::abs(void) const
{
    return fabs();
}

SIRadian SIRadian::acos(const double aValue)
{
    return SIRadian(::acos(aValue));
}

SIRadian SIRadian::asin(const double aValue)
{
    return SIRadian(::asin(aValue));
}

SIRadian SIRadian::atan(const double aValue)
{
    return SIRadian(::atan(aValue));
}

SIRadian SIRadian::atan2(const double aY, const double aX)
{
    return SIRadian(::atan2(aY, aX));
}

SIRadian SIRadian::atan2(const double aY, const double aX, const double aTolerance)
{
    SIRadian result;
    
    if ((::fabs(aY) >= aTolerance) && (::fabs(aX) >= aTolerance))
    {
       result = SIRadian(::atan2(aY, aX));
    } // end if
    
    return result;
}

SIRadian SIRadian::fabs(void) const
{
    double absAngle = ((*this)() < 0.0) ? -(*this)() : (*this)();
    
    SIRadian result(absAngle);
    
    return result;
}

bool SIRadian::inArc(const SIRadian& aFrom, const SIRadian& aTo) const
{
    // Check if the arc straddles the -PI/+PI disjoint and if it
    // does negate the result of the check of being in the other possible arc
    bool result = (aFrom() <= aTo())
                  ? ((aFrom() <= (*this)()) && ((*this)() <= aTo()))
                  : ! ((aTo() <= (*this)()) && ((*this)() <= aFrom()));
    
    return result;
}

bool SIRadian::isApproximatelyEqual(const SIRadian& rhs, const SIRadian& aTolerance) const
{
    const SIRadian delta(*this - rhs);
    const bool     result = delta.abs().inArc(-aTolerance, aTolerance);
    
    return result;
}

bool SIRadian::isPositive(void) const
{
    return (*this)() > 0.0;
}

bool SIRadian::isZeroOrPositive(void) const
{
    return (*this)() >= 0.0;
}

void SIRadian::limitToMax(const SIRadian& aSIRadian)
{
    if ((*this)() > aSIRadian())
    {
       setValue(aSIRadian());
    } // end if
}

void SIRadian::limitToMin(const SIRadian& aSIRadian)
{
    if ((*this)() < aSIRadian())
    {
       setValue(aSIRadian());
    } // end if
}

bool SIRadian::operator!=(const SIRadian& rhs) const
{
    return ( !floatEqualityChecker::AlmostEqual((*this)(), rhs()) );
}

SIRadian SIRadian::operator*(const double aValue) const
{
    
    SIRadian result((*this)());
    
    result *= aValue;
    
    return result;
}

SIRadian& SIRadian::operator*=(const double aValue)
{
    setValue((*this)() * aValue);
    
    normalize();
    
    return *this;
}

SIRadian SIRadian::operator+(const SIRadian& rhs) const
{
    
    SIRadian result((*this)());
    
    result += rhs;
    
    return result;
}

SIRadian& SIRadian::operator+=(const SIRadian& rhs)
{
    setValue((*this)() + rhs());
    
    normalize();
    
    return *this;
}

SIRadian SIRadian::operator-(const SIRadian& rhs) const
{
    
    SIRadian result((*this)());
    
    result -= rhs;
    
    return result;
}

SIRadian SIRadian::operator-(void) const
{
    const SIRadian result(-(*this)());
    
    return result;
}

SIRadian& SIRadian::operator-=(const SIRadian& rhs)
{
    setValue((*this)() - rhs());
    
    normalize();
    
    return *this;
}

SIRadian SIRadian::operator/(const double aValue) const
{
    
    SIRadian result((*this)());
    
    result /= aValue;
    
    return result;
}

SIRadianPerSecond SIRadian::operator/(const SISecond& aSecond) const
{
    const SIRadianPerSecond result((*this)() / aSecond());
    
    return result;
}

SIRadianPerSecondSquared SIRadian::operator/(const SISecondSquared& aSecondSquared) const
{
    const SIRadianPerSecondSquared result((*this)() / aSecondSquared());
    
    return result;
}

SIUnitless SIRadian::operator/(const SIRadian& aRadian) const
{
    const SIUnitless result((*this)() / aRadian());
    
    return result;
}

SIRadian& SIRadian::operator/=(const double aValue)
{
    setValue((*this)() / aValue);
    
    normalize();
    
    return *this;
}

bool SIRadian::operator<(const SIRadian& rhs) const
{
    return (*this)() < rhs();
}

bool SIRadian::operator<=(const SIRadian& rhs) const
{
    return (*this)() <= rhs();
}

SIRadian& SIRadian::operator=(const double rhs)
{
    setValue(rhs);
    normalize();
    
    return *this;
}

bool SIRadian::operator==(const SIRadian& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

bool SIRadian::operator>(const SIRadian& rhs) const
{
    return (*this)() > rhs();
}

bool SIRadian::operator>=(const SIRadian& rhs) const
{
    return (*this)() >= rhs();
}

double SIRadian::tan(void) const
{
    return ::tan((*this)());
}

SIDegree SIRadian::toDegree(void) const
{
    return SIDegree(((*this)() * DEG_180) / PI());
}

void SIRadian::normalize(void)
{
    setValue(normalizeRadian( (*this)() ) );
    
}

double SIRadian::normalizeRadian(const double aAngle)
{
    double retAngle = aAngle;
    
    if(retAngle > PI())
    {
    	while (true)
    	{
    	   retAngle -= TWO_PI();
    	   if(retAngle <= PI())
    	   {
    	       break;
    	   }
    	}
    }
    
    if(retAngle < -PI())
    {
    	while (true)
    	{
    	   retAngle += TWO_PI();
    	   if(retAngle >= -PI())
    	   {
    	       break;
    	   }
    	}
    }
    
    return retAngle;
    
}

}

