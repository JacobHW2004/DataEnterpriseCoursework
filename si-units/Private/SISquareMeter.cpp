

#include "SISquareMeter.h"
#include "SICubicMeter.h"
#include "SIMeter.h"
#include "SIUnitless.h"
#include "FloatEqualityChecker.h"

namespace SI{

SISquareMeter::SISquareMeter(const double aValue) : SIUnit(aValue, "m^2")
{
    
}

SICubicMeter SISquareMeter::operator*(const SIMeter& aMeter) const
{
    const SICubicMeter result((*this)() * aMeter());
    
    return result;
}

SIMeter SISquareMeter::operator/(const SIMeter& aMeter) const
{
    const SIMeter result((*this)() / aMeter());
    
    return result;
}

bool SISquareMeter::operator==(const SISquareMeter& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIUnitless SISquareMeter::operator/(const SISquareMeter& aSquareMeter) const
{
    const SIUnitless result((*this)() / aSquareMeter());
    
    return result;
}

SISquareMeter& SISquareMeter::operator=(const double rhs)
{
    setValue(rhs);
    return *this;
}

}