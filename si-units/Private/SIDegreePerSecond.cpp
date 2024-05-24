#include "SIDegreePerSecond.h"
#include "FloatEqualityChecker.h"
#include "SIDegree.h"
#include "SIDegreePerSecondSquared.h"
#include "SISecond.h"
#include "SIUnitless.h"

namespace SI{

SIDegreePerSecond::SIDegreePerSecond(const double aValue) : SIUnit(aValue, "deg/s")
{
    
}

SIDegree SIDegreePerSecond::operator*(const SISecond& aSecond) const
{
    const SIDegree result((*this)() * aSecond());
    
    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
SIDegreePerSecondSquared SIDegreePerSecond::operator/(const SISecond& aSecond) const
{
    const SIDegreePerSecondSquared result((*this)() / aSecond());
    
    return result;
}

bool SIDegreePerSecond::operator==(const SIDegreePerSecond& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
SIUnitless SIDegreePerSecond::operator/(const SIDegreePerSecond& aDegreePerSecond) const
{
    const SIUnitless result((*this)() / aDegreePerSecond());
    
    return result;
}

SIDegreePerSecond& SIDegreePerSecond::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}
