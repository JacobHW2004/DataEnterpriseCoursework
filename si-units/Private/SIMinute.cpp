
#include "SIMinute.h"
#include "FloatEqualityChecker.h"
#include "SIUnitless.h"

namespace SI{

SIMinute::SIMinute(const double aValue) : SIUnit(aValue, "min")
{
    
}

bool SIMinute::operator!=(const SIMinute& rhs) const
{
    return !( floatEqualityChecker::AlmostEqual((*this)(), rhs()) );
}

SIUnitless SIMinute::operator/(const SIMinute& aMinute) const
{
    return (SIUnitless((*this)() / aMinute()));
}

bool SIMinute::operator==(const SIMinute& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIMinute& SIMinute::operator=(const SIMinute& rhs)
{
    // Check for self-assignment
    if (this != &rhs)
    {
        // Set second attribute equal to rhs
        setValue(rhs());
    } // end if

    return *this;
}

SIMinute& SIMinute::operator=(const double rhs)
{
    // Set second attribute equal to rhs
    setValue(rhs);

    return *this;
}

}