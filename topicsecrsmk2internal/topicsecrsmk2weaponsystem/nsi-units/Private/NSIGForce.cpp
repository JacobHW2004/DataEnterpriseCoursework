#include "NSIGForce.h"

namespace NSI {

NSIGForce::NSIGForce(const double aValue) : NSIUnit(aValue, "g")
{
    
}

NSIGForce NSIGForce::operator+(const NSIGForce& aGForce) const
{
    const NSIGForce result((*this)() + aGForce());

    return result;
}

bool NSIGForce::operator==(const NSIGForce& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

NSIGForce NSIGForce::operator-(const NSIGForce& aGForce) const
{   
    const NSIGForce result((*this)() - aGForce());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
NSIUnitless NSIGForce::operator/(const NSIGForce& aGForce) const
{
    const NSIUnitless result ((*this)() / aGForce());

    return result;
}

NSIGForce& NSIGForce::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}