#include "NSIKnot.h"

namespace NSI {

NSIKnot::NSIKnot(const double aValue) : NSIUnit(aValue, "kn")
{
    
}

NSIKnot::NSIKnot(const SI::SIMeterPerSecond& aMeterPerSecondValue) : NSIUnit(convertMpsToKnots(aMeterPerSecondValue()), "kn")
{

}

NSIKnot::NSIKnot(const NSIFeetPerMinute& aFeetPerMinuteValue) : NSIUnit(convertFpmToKnots(aFeetPerMinuteValue()), "kn")
{

}

NSIKnot NSIKnot::operator+(const NSIKnot& aKnot) const
{
    const NSIKnot result((*this)() + aKnot());

    return result;
}

bool NSIKnot::operator==(const NSIKnot& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

NSIKnot NSIKnot::operator-(const NSIKnot& aKnot) const
{   
    const NSIKnot result((*this)() - aKnot());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
NSIUnitless NSIKnot::operator/(const NSIKnot& aKnot) const
{
    const NSIUnitless result ((*this)() / aKnot());

    return result;
}

NSIKnot& NSIKnot::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

double NSIKnot::convertMpsToKnots(const double aMeterPerSecondValue)
{
    return aMeterPerSecondValue * 1.94384;
}

double NSIKnot::convertFpmToKnots(const double aFeetPerMinuteValue)
{
    return aFeetPerMinuteValue/101.269;
}


}