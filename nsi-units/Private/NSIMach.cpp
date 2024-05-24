#include "NSIMach.h"

namespace NSI {

NSIMach::NSIMach(const double aValue) : NSIUnit(aValue, "Mach")
{
    
}

NSIMach::NSIMach(const SI::SIMeterPerSecond& aMeterPerSecondValue) : NSIUnit(convertMpsToMach(aMeterPerSecondValue()), " Mach")
{

}

NSIMach::NSIMach(const NSI::NSIKnot& aKnot) : NSIUnit(convertKnotsToMach(aKnot()), " Mach")
{

}

NSIMach::NSIMach(const NSI::NSIFeetPerMinute& aFeetPerMinuteValue) : NSIUnit(convertFpmToMach(aFeetPerMinuteValue()), " Mach")
{

}

NSIMach NSIMach::operator+(const NSIMach& aMach) const
{
    const NSIMach result((*this)() + aMach());

    return result;
}

bool NSIMach::operator==(const NSIMach& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

NSIMach NSIMach::operator-(const NSIMach& aMach) const
{   
    const NSIMach result((*this)() - aMach());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
NSIUnitless NSIMach::operator/(const NSIMach& aMach) const
{
    const NSIUnitless result ((*this)() / aMach());

    return result;
}

NSIMach& NSIMach::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

double NSIMach::convertMpsToMach(const double aMeterPerSecondValue)
{
    return aMeterPerSecondValue / 343;
}


double NSIMach::convertKnotsToMach(const double aKnot)
{
    return aKnot/666.738;
}

double NSIMach::convertFpmToMach(const double aFeetPerMinuuteValue)
{
    //some conflicting sources on this
    return aFeetPerMinuuteValue/67519.7;
}

}