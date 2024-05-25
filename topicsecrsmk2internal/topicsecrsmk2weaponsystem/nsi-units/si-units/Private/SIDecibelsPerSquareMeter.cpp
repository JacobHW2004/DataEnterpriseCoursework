#include "FloatEqualityChecker.h"

#include "SIDecibelsPerSquareMeter.h"
#include "SIUnitless.h"

namespace SI{


 SIDecibelsPerSquareMeter::SIDecibelsPerSquareMeter(const double aValue) : SIUnit(aValue, "dBsm")
{
    
}

SIDecibelsPerSquareMeter& SIDecibelsPerSquareMeter::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

bool SIDecibelsPerSquareMeter::operator==(const SIDecibelsPerSquareMeter& rhs) const
{
    return floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

}