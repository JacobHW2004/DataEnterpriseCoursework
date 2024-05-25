#include "NSIFeetPerMinute.h"

namespace NSI {

NSIFeetPerMinute::NSIFeetPerMinute(const double aValue) : NSIUnit(aValue, "ft/min")
{
    
}

NSIFeetPerMinute::NSIFeetPerMinute(const SI::SIMeterPerSecond& aMeterPerSecondValue) : NSIUnit(convertMpsToFpm(aMeterPerSecondValue()), "ft/min")
{

}

NSIFeetPerMinute::NSIFeetPerMinute(const NSI::NSIKnot& aKnot) : NSIUnit(convertKnotsToFpm(aKnot()), "ft/min")
{

}

NSIFeetPerMinute NSIFeetPerMinute::operator+(const NSIFeetPerMinute& aFeetPerMinuteValue) const
{
    const NSIFeetPerMinute result((*this)() + aFeetPerMinuteValue());

    return result;
}

bool NSIFeetPerMinute::operator==(const NSIFeetPerMinute& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

NSIFeetPerMinute NSIFeetPerMinute::operator-(const NSIFeetPerMinute& aFeetPerMinuteValue) const
{   
    const NSIFeetPerMinute result((*this)() - aFeetPerMinuteValue());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
NSIUnitless NSIFeetPerMinute::operator/(const NSIFeetPerMinute& aFeetPerMinuteValue) const
{ 
    const NSIUnitless result ((*this)() / aFeetPerMinuteValue());

    return result;
}

NSIFeetPerMinute& NSIFeetPerMinute::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

double NSIFeetPerMinute::convertMpsToFpm(const double aMeterPerSecondValue)
{
    return aMeterPerSecondValue * 196.850;
}


double NSIFeetPerMinute::convertKnotsToFpm(const double aKnot)
{
    return aKnot * 101.269;
}


}
