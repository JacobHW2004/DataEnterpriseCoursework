
#include "SIMilliSecond.h"
#include "FloatEqualityChecker.h"
#include "SIUnitless.h"

namespace SI{

SIMilliSecond::SIMilliSecond(const double aValue) : SIUnit(aValue, "ms")
{
    
}

bool SIMilliSecond::operator!=(const SIMilliSecond& rhs) const
{
    return !( floatEqualityChecker::AlmostEqual((*this)(), rhs()) );
}

SIUnitless SIMilliSecond::operator/(const SIMilliSecond& aMilliSecond) const
{
    return (SIUnitless((*this)() / aMilliSecond()));
}

bool SIMilliSecond::operator==(const SIMilliSecond& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIMilliSecond& SIMilliSecond::operator=(const SIMilliSecond& rhs)
{
    // Check for self-assignment
    if (this != &rhs)
    {
        // Set second attribute equal to rhs
        setValue(rhs());
    } // end if

    return *this;
}

SIMilliSecond& SIMilliSecond::operator=(const double rhs)
{
    // Set second attribute equal to rhs
    setValue(rhs);

    return *this;
}

}