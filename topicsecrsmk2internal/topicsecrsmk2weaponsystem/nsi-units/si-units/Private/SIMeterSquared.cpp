

#include "SIMeterSquared.h"
#include "FloatEqualityChecker.h"

namespace SI{

    SIMeterSquared::SIMeterSquared(const double aValue) : SIUnit(aValue, "m^2")
    {
    
    }

    bool SIMeterSquared::operator==(const SIMeterSquared& rhs) const
    {
        return floatEqualityChecker::AlmostEqual((*this)(), rhs());
    }

    SIMeterSquared& SIMeterSquared::operator=(const double rhs)
    {
        setValue(rhs);
        return *this;
    }

}
