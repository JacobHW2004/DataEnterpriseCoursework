
#include "SIHour.h"
#include "FloatEqualityChecker.h"
#include "SIUnitless.h"

namespace SI{

SIHour::SIHour(const double aValue) : SIUnit(aValue, "h")
{
    
}

bool SIHour::operator!=(const SIHour& rhs) const
{
    return !( floatEqualityChecker::AlmostEqual((*this)(), rhs()) );
}

SIUnitless SIHour::operator/(const SIHour& aHour) const
{
    return (SIUnitless((*this)() / aHour()));
}

bool SIHour::operator==(const SIHour& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIHour& SIHour::operator=(const SIHour& rhs)
{
    // Check for self-assignment
    if (this != &rhs)
    {
        // Set second attribute equal to rhs
        setValue(rhs());
    } // end if

    return *this;
}

SIHour& SIHour::operator=(const double rhs)
{
    // Set second attribute equal to rhs
    setValue(rhs);

    return *this;
}

}