

#include "SIRadianPerSecond.h"
#include "SIDegree.h"
#include "SIRadian.h"
#include "SIRadianPerSecondSquared.h"
#include "SISecond.h"
#include "SIUnitless.h"

namespace SI{

SIRadianPerSecond::SIRadianPerSecond(const double aValue) : SIUnit(aValue, "rad/s")
{
    
}

SIRadian SIRadianPerSecond::operator*(const SISecond& aSecond) const
{
    const SIRadian result((*this)() * aSecond());
    
    return result;
}

SIRadianPerSecondSquared SIRadianPerSecond::operator/(const SISecond& aSecond) const
{
    const SIRadianPerSecondSquared result((*this)() / aSecond());
    
    return result;
}

SIUnitless SIRadianPerSecond::operator/(const SIRadianPerSecond& aRadianPerSecond) const
{
    const SIUnitless result((*this)() / aRadianPerSecond());
    
    return result;
}

SIRadianPerSecond& SIRadianPerSecond::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}
