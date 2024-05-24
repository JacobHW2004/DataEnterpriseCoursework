
#include "SISecond.h"
#include "FloatEqualityChecker.h"
#include "SIDegree.h"
#include "SIMeter.h"
#include "SIMeterPerSecond.h"
#include "SIRadian.h"
#include "SIRadianPerSecond.h"
#include "SIUnitless.h"

namespace SI{

SISecond::SISecond(const double aValue) : SIUnit(aValue, "s")
{
    
}

bool SISecond::operator!=(const SISecond& rhs) const
{
    return !( floatEqualityChecker::AlmostEqual((*this)(), rhs()) );
}

SIMeter SISecond::operator*(const SIMeterPerSecond& aMeterPerSecond) const
{
    const SIMeter result((*this)() * aMeterPerSecond());
    
    return result;
}

SIRadian SISecond::operator*(const SIRadianPerSecond& aRadianPerSecond) const
{
    const SIRadian result((*this)() * aRadianPerSecond());
    
    return result;
}

SIUnitless SISecond::operator/(const SISecond& aSecond) const
{
    const SIUnitless result((*this)() / aSecond());
    
    return result;
}

bool SISecond::operator==(const SISecond& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SISecond& SISecond::operator=(const SISecond& rhs)
{
    // Check for self-assignment
    if (this != &rhs)
    {
        // Set second attribute equal to rhs
        setValue(rhs());
    } // end if

    return *this;
}

SISecond& SISecond::operator=(const double rhs)
{
    // Set second attribute equal to rhs
    setValue(rhs);

    return *this;
}

}