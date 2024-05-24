#include"NSIMillibar.h"

namespace NSI {

NSIMillibar::NSIMillibar(const double aValue) : NSIUnit(aValue, "mbar")
{
    
}

NSIMillibar NSIMillibar::operator+(const NSIMillibar& aMillibar) const
{
    const NSIMillibar result((*this)() + aMillibar());

    return result;
}

bool NSIMillibar::operator==(const NSIMillibar& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

NSIMillibar NSIMillibar::operator-(const NSIMillibar& aMillibar) const
{   
    const NSIMillibar result((*this)() - aMillibar());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
NSIUnitless NSIMillibar::operator/(const NSIMillibar& aMillibar) const
{
    const NSIUnitless result ((*this)() / aMillibar());

    return result;
}

NSIMillibar& NSIMillibar::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}