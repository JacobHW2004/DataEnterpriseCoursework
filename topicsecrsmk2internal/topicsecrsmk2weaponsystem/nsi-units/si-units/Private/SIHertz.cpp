#include "SIHertz.h"
#include "SIHertzPerSecond.h"
#include "SISecond.h"
#include "SIUnitless.h"

namespace SI{

SIHertz::SIHertz(const double aValue) : SIUnit(aValue, "Hz")
{
    
}

SIUnitless SIHertz::operator*(const SISecond& aSecond) const
{
    const SIUnitless result((*this)() * aSecond());
    
    return result;
}

SIHertzPerSecond SIHertz::operator/(const SISecond& aSecond) const
{
    const SIHertzPerSecond result((*this)() / aSecond());
    
    return result;
}

SIUnitless SIHertz::operator/(const SIHertz& aPerSecond) const
{
    const SIUnitless result((*this)() / aPerSecond());
    
    return result;
}

}