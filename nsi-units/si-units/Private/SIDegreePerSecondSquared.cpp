
#include "SIDegreePerSecondSquared.h"
#include "SIDegree.h"
#include "SIDegreePerSecond.h"
#include "SISecond.h"
#include "SISecondSquared.h"
#include "SIUnitless.h"
#include "FloatEqualityChecker.h"

namespace SI{

SIDegreePerSecondSquared::SIDegreePerSecondSquared(const double aValue) : SIUnit(aValue, "deg/s^2")
{

}

SIDegreePerSecond SIDegreePerSecondSquared::operator*(const SISecond& aSecond) const
{
    const SIDegreePerSecond result((*this)() * aSecond());
    
    return result;
}

SIDegree SIDegreePerSecondSquared::operator*(const SISecondSquared& aSecondSquared) const
{
    const SIDegree result((*this)() * aSecondSquared());
    
    return result;
}

bool SIDegreePerSecondSquared::operator==(const SIDegreePerSecondSquared& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
SIUnitless SIDegreePerSecondSquared::operator/(const SIDegreePerSecondSquared& aDegreePerSecondSquared) const
{
    const SIUnitless result((*this)() / aDegreePerSecondSquared());
    
    return result;
}

SIDegreePerSecondSquared& SIDegreePerSecondSquared::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}