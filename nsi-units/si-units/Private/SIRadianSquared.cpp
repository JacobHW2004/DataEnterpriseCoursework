

#include "SIRadianSquared.h"
#include "FloatEqualityChecker.h"

namespace SI{

    SIRadianSquared::SIRadianSquared(const double aValue) : SIUnit(aValue, "rad^2")
    {
    
    }

    bool SIRadianSquared::operator==(const SIRadianSquared& rhs) const
    {
        return floatEqualityChecker::AlmostEqual((*this)(), rhs());
    }


    SIRadianSquared& SIRadianSquared::operator=(const double rhs)
    {
        setValue(rhs);

        return *this;
    }

}
