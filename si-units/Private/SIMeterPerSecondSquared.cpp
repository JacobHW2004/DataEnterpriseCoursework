#include "SIMeterPerSecondSquared.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "SISecond.h"
#include "SISecondSquared.h"
#include "SIUnitless.h"
#include "FloatEqualityChecker.h"

namespace SI{

SIMeterPerSecondSquared::SIMeterPerSecondSquared(const double aValue) : SIUnit(aValue, "m/s^2")
{
    
}

SIMeterPerSecond SIMeterPerSecondSquared::operator*(const SISecond& aSecond) const
{
    const SIMeterPerSecond result((*this)() * aSecond());
    
    return result;
}

SIMeter SIMeterPerSecondSquared::operator*(const SISecondSquared& aSecondSquared) const
{
    const SIMeter result((*this)() * aSecondSquared());
    
    return result;
}

bool SIMeterPerSecondSquared::operator==(const SIMeterPerSecondSquared& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIUnitless SIMeterPerSecondSquared::operator/(const SIMeterPerSecondSquared& aMeterPerSecondSquared) const
{
    const SIUnitless result((*this)() / aMeterPerSecondSquared());
    
    return result;
}

SIMeterPerSecondSquared& SIMeterPerSecondSquared::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}