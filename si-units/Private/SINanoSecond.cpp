
#include "SINanoSecond.h"
#include "FloatEqualityChecker.h"
#include "SIUnitless.h"

namespace SI{

SINanoSecond::SINanoSecond(const double aValue) : SIUnit(aValue, "ns")
{
    
}

bool SINanoSecond::operator!=(const SINanoSecond& rhs) const
{
    return !( floatEqualityChecker::AlmostEqual((*this)(), rhs()) );
}

SIUnitless SINanoSecond::operator/(const SINanoSecond& aNanoSecond) const
{
    return (SIUnitless((*this)() / aNanoSecond()));
}

bool SINanoSecond::operator==(const SINanoSecond& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SINanoSecond& SINanoSecond::operator=(const SINanoSecond& rhs)
{
    // Check for self-assignment
    if (this != &rhs)
    {
        // Set second attribute equal to rhs
        setValue(rhs());
    } // end if

    return *this;
}

SINanoSecond& SINanoSecond::operator=(const double rhs)
{
    // Set second attribute equal to rhs
    setValue(rhs);

    return *this;
}

}