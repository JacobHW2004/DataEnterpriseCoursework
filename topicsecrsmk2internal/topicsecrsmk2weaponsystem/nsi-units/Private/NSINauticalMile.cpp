#include "NSINauticalMile.h"
namespace NSI {

NSINauticalMile::NSINauticalMile(const double aValue) : NSIUnit(aValue, "NM")
{

}

NSINauticalMile::NSINauticalMile(const NSIFoot& aFootValue) : NSIUnit(convertFtToNauticalMiles(aFootValue()), "NM")
{

}

NSINauticalMile::NSINauticalMile(const NSIMillimeter& aMillimeterValue) : NSIUnit(convertMillimeterToNauticalMiles(aMillimeterValue()), "NM")
{

}

NSINauticalMile::NSINauticalMile(const SI::SIMeter& aMeterValue) : NSIUnit(convertMeterToNauticalMiles(aMeterValue()), "NM")
{

}

NSINauticalMile NSINauticalMile::operator+(const NSINauticalMile& aNauticalMile) const
{
    const NSINauticalMile result((*this)() + aNauticalMile());

    return result;
}

bool NSINauticalMile::operator==(const NSINauticalMile& rhs) const
{   
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

NSINauticalMile NSINauticalMile::operator-(const NSINauticalMile& aNauticalMile) const
{
    const NSINauticalMile result((*this)() - aNauticalMile());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
NSIUnitless NSINauticalMile::operator/(const NSINauticalMile& aNauticalMile) const
{
    const NSIUnitless result((*this)() / aNauticalMile());

    return result;
}

NSINauticalMile& NSINauticalMile::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

double NSINauticalMile::convertFtToNauticalMiles(const double aFootValue)
{
    return aFootValue / 6076.12;
}

double NSINauticalMile::convertMeterToNauticalMiles(const double aMeterValue)
{
    return aMeterValue / 1852.00;
}

double NSINauticalMile::convertMillimeterToNauticalMiles(const double aMillimeterValue)
{
    return aMillimeterValue / 1.852e+6;
}


}