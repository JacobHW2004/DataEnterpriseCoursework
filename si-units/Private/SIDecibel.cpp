
#include "SIDecibel.h"
#include "SIUnitless.h"

namespace SI{

SIDecibel::SIDecibel(const double aValue) : SIUnit(aValue, "dB")
{
    
}

SIUnitless SIDecibel::operator/(const SIDecibel& aDecibel) const
{
    const SIUnitless result((*this)() / aDecibel());
    
    return result;
}

SIDecibel& SIDecibel::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}