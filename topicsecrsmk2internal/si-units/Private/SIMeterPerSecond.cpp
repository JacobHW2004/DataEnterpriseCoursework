
#include "SIMeterPerSecond.h"
#include "SIMeter.h"
#include "SIMeterPerSecondSquared.h"
#include "SISecond.h"
#include "SIUnitless.h"
#include "FloatEqualityChecker.h"

namespace SI{

SIMeterPerSecond::SIMeterPerSecond(const double aValue) : SIUnit(aValue, "m/s")
{
    
}

SIMeter SIMeterPerSecond::operator*(const SISecond& aSecond) const
{
    const SIMeter result((*this)() * aSecond());
    
    return result;
}

SIMeterPerSecondSquared SIMeterPerSecond::operator/(const SISecond& aSecond) const
{
    const SIMeterPerSecondSquared result((*this)() / aSecond());
    
    return result;
}

bool SIMeterPerSecond::operator==(const SIMeterPerSecond& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIUnitless SIMeterPerSecond::operator/(const SIMeterPerSecond& aMeterPerSecond) const
{
    const SIUnitless result((*this)() / aMeterPerSecond());
    
    return result;
}

SIMeterPerSecond& SIMeterPerSecond::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}