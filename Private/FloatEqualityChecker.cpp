#include "FloatEqualityChecker.h"

namespace SI{

bool floatEqualityChecker::AlmostEqual(const float aVal1, const float aVal2, const float aEpsilon)
{
    bool returnValue { false };

    const float diff { static_cast<float>(fabs(aVal1 - aVal2)) };
    
    const float absoluteEpsilon {std::fabs(aEpsilon)};

    if(diff <= absoluteEpsilon)
    {
        returnValue = true;
    }
    
    return returnValue;
}

bool floatEqualityChecker::AlmostEqual(const double aVal1, const double aVal2, const double aEpsilon)
{
    bool returnValue { false };

    const double diff { fabs(aVal1 - aVal2) };
    
    const double absoluteEpsilon {std::fabs(aEpsilon)};
    
    if(diff <= absoluteEpsilon)
    {
        returnValue = true;
    }
    
    return returnValue;
}

}
