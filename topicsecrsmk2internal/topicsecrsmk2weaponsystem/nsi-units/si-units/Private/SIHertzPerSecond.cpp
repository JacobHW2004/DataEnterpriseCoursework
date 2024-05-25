#include "SIHertzPerSecond.h"
#include "SIHertz.h"
#include "SIHertzPerSecondSquared.h"
#include "SISecond.h"
#include "SIUnitless.h"

namespace SI{

SIHertzPerSecond::SIHertzPerSecond(const double aValue) : SIUnit(aValue, "Hz/s")
{
    
}

SIHertz SIHertzPerSecond::operator*(const SISecond& aSecond) const
{
    const SIHertz result((*this)() * aSecond());
    
    return result;
}

SIHertzPerSecondSquared SIHertzPerSecond::operator/(const SISecond& aSecond) const
{
    const SIHertzPerSecondSquared result((*this)() / aSecond());
    
    return result;
}

SIUnitless SIHertzPerSecond::operator/(const SIHertzPerSecond& aPerSecondSquared) const
{
    const SIUnitless result((*this)() / aPerSecondSquared());
    
    return result;
}

}