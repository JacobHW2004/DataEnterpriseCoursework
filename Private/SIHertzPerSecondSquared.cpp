
#include "SIHertzPerSecondSquared.h"
#include "SIHertzPerSecond.h"
#include "SISecond.h"
#include "SIUnitless.h"

namespace SI{

SIHertzPerSecondSquared::SIHertzPerSecondSquared(const double aValue) : SIUnit(aValue, "Hz/s^2")
{
    
}

SIHertzPerSecond SIHertzPerSecondSquared::operator*(const SISecond& aSecond) const
{
    const SIHertzPerSecond result((*this)() * aSecond());
    
    return result;
}

SIUnitless SIHertzPerSecondSquared::operator/(const SIHertzPerSecondSquared& aPerSecondCubed) const
{
    const SIUnitless result((*this)() / aPerSecondCubed());
    
    return result;
}

}
