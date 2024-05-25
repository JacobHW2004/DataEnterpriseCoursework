
#include "SIDegree.h"
#include "SIUnitless.h"
#include "FloatEqualityChecker.h"

namespace SI{



SIDegree::SIDegree(const double aValue) : SIUnit(aValue, "deg")
{
   
}

SIDegree::SIDegree(const SIDegree& aSIDegree) : SIUnit(aSIDegree(), "deg")
{
    
}

SIUnitless SIDegree::operator/(const SIDegree& aDegree) const
{
    const SIUnitless result((*this)() / aDegree());
    
    return result;
}

bool SIDegree::operator==(const SIDegree& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}


SIDegree& SIDegree::operator=(const SIDegree& rhs)
{
    // Check for self-assignment
    if (this != &rhs)
    {
       // Set angle attribute equal to rhs
       setValue(rhs());
    } // end if
    
    return *this;
}

SIDegree& SIDegree::operator=(const double rhs)
{
    // Set angle attribute equal to rhs
    setValue(rhs);
    
    return *this;
}

}