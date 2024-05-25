
#include "SIRadianPerSecondSquared.h"
#include "SIDegree.h"
#include "SIRadian.h"
#include "SIRadianPerSecond.h"
#include "SISecond.h"
#include "SISecondSquared.h"
#include "SIUnitless.h"

namespace SI{

SIRadianPerSecondSquared::SIRadianPerSecondSquared(const double aValue) : SIUnit(aValue, "rad/s^2")
{

}

SIRadianPerSecond SIRadianPerSecondSquared::operator*(const SISecond& aSecond) const
{
    const SIRadianPerSecond result((*this)() * aSecond());
    
    return result;
}

SIRadian SIRadianPerSecondSquared::operator*(const SISecondSquared& aSecondSquared) const
{
    const SIRadian result((*this)() * aSecondSquared());
    
    return result;
}

SIUnitless SIRadianPerSecondSquared::operator/(const SIRadianPerSecondSquared& aRadianPerSecondSquared) const
{
    const SIUnitless result((*this)() / aRadianPerSecondSquared());
    
    return result;
}

SIRadianPerSecondSquared& SIRadianPerSecondSquared::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}