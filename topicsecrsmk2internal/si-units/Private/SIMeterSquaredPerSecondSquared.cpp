

#include "SIMeterSquaredPerSecondSquared.h"
#include "FloatEqualityChecker.h"

namespace SI{

    SIMeterSquaredPerSecondSquared::SIMeterSquaredPerSecondSquared(const double aValue) : SIUnit(aValue, "m^2/s^2")
    {
    
    }

    bool SIMeterSquaredPerSecondSquared::operator==(const SIMeterSquaredPerSecondSquared& rhs) const
    {
        return floatEqualityChecker::AlmostEqual((*this)(), rhs());
    }


    SIMeterSquaredPerSecondSquared& SIMeterSquaredPerSecondSquared::operator=(const double rhs)
    {
        setValue(rhs);

        return *this;
    }

}
