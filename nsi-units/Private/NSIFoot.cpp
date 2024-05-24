#include "NSIFoot.h"

namespace NSI {

NSIFoot::NSIFoot(const int32_t aValue) : NSIUnit(aValue, "ft")
{
    
}

NSIFoot::NSIFoot(const NSINauticalMile& aNauticalMileValue) : NSIUnit(convertNauticalMileToFt(aNauticalMileValue()), "ft")
{

} 

NSIFoot::NSIFoot(const NSIMillimeter& aMillimeterValue) : NSIUnit(convertMmToFt((aMillimeterValue())), "ft")
{

}

NSIFoot::NSIFoot(const SI::SIMeter& aMeterValue) : NSIUnit(convertMeterToFt((aMeterValue())), "ft")
{

}

NSIFoot NSIFoot::operator+(const NSIFoot& aFoot) const
{
    const NSIFoot result((*this) () + aFoot());

    return result;
}

bool NSIFoot::operator==(const NSIFoot& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

NSIFoot NSIFoot::operator-(const NSIFoot& aFoot) const
{
    const NSIFoot result((*this)() - aFoot());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
NSIUnitless NSIFoot::operator/(const NSIFoot& aFoot) const
{
        const NSIUnitless result((*this)() / aFoot());

        return result;
}

NSIFoot& NSIFoot::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

int32_t NSIFoot::convertNauticalMileToFt(const double aNauticalMileValue)
{
    return round(aNauticalMileValue * 6076.12);
}

int32_t NSIFoot::convertMmToFt(const double aMillimeterValue)
{
    return round(aMillimeterValue/304.804);
}

int32_t NSIFoot::convertMeterToFt(const double meter)
{
    return round(meter * 3.28084); 
}

}