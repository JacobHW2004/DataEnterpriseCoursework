#include "SIKilogram.h"

namespace SI {

SIKilogram::SIKilogram(const double aValue) : SIUnit(aValue, "kg")
{
    
}

SIKilogram SIKilogram::operator+(const SIKilogram& aKilogram) const
{
    const SIKilogram result((*this)() + aKilogram());

    return result;
}

bool SIKilogram::operator==(const SIKilogram& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIKilogram SIKilogram::operator-(const SIKilogram& aKilogram) const
{   
    const SIKilogram result((*this)() - aKilogram());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
SIKilogram SIKilogram::operator/(const double& aDouble) const
{ 
    const SIKilogram result ((*this)() / aDouble);

    return result;
}

SIKilogram SIKilogram::operator*(const double& aDouble) const
{ 
    const SIKilogram result ((*this)() * aDouble);

    return result;
}

SIKilogram& SIKilogram::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}