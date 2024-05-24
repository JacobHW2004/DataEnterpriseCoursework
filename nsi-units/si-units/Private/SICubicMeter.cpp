
#include "SICubicMeter.h"
#include "SIMeter.h"
#include "SISquareMeter.h"
#include "SIUnitless.h"

namespace SI{

SICubicMeter::SICubicMeter(const double aValue) : SIUnit(aValue, "m^3")
{
    
}

SISquareMeter SICubicMeter::operator/(const SIMeter& aMeter) const
{
    const SISquareMeter result((*this)() / aMeter());
    
    return result;
}

SIUnitless SICubicMeter::operator/(const SICubicMeter& aCubicMeter) const
{
    const SIUnitless result((*this)() / aCubicMeter());
    
    return result;
}

}