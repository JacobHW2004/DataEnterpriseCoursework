#include "SISecondSquared.h"
#include "SISecond.h"
#include "SIUnitless.h"

namespace SI{

SISecondSquared::SISecondSquared(const double aValue) : SIUnit(aValue, "s^2")
{
   
}

SISecond SISecondSquared::operator/(const SISecond& aSecond) const
{
    const SISecond result((*this)() / aSecond());
    
    return result;
}

SIUnitless SISecondSquared::operator/(const SISecondSquared& aSecondSquared) const
{

    const SIUnitless result((*this)() / aSecondSquared());
    
    return result;
}

}
