
#include "SIMeter.h"
#include "SICubicMeter.h"
#include "SIMeterPerSecond.h"
#include "SIMeterPerSecondSquared.h"
#include "SISecond.h"
#include "SISecondSquared.h"
#include "SISquareMeter.h"
#include "SIUnitless.h"
#include "FloatEqualityChecker.h"

namespace SI{

SIMeter::SIMeter(const double aValue) : SIUnit(aValue, "m")
{
   
}

SISquareMeter SIMeter::operator*(const SIMeter& aMeter) const
{
    const SISquareMeter result((*this)() * aMeter());
    
    return result;
}

SICubicMeter SIMeter::operator*(const SISquareMeter& aSquareMeter) const
{
    const SICubicMeter result((*this)() * aSquareMeter());
    
    return result;
}

SIMeter SIMeter::operator+(const SIMeter& aMeter) const
{
    const SIMeter result((*this)() + aMeter());
    
    return result;
}

bool SIMeter::operator==(const SIMeter& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIMeter SIMeter::operator-(const SIMeter& aMeter) const
{
    const SIMeter result((*this)() - aMeter());
    
    return result;
}

SIMeterPerSecond SIMeter::operator/(const SISecond& aSecond) const
{
    const SIMeterPerSecond result((*this)() / aSecond());
    
    return result;
}

SIMeterPerSecondSquared SIMeter::operator/(const SISecondSquared& aSecondSquared) const
{
    const SIMeterPerSecondSquared result((*this)() / aSecondSquared());
    
    return result;
}

SIUnitless SIMeter::operator/(const SIMeter& aMeter) const
{
    const SIUnitless result((*this)() / aMeter());
    
    return result;
}

SIMeter& SIMeter::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}