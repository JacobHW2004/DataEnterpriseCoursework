#include "NSIMillimeter.h"


namespace NSI {

NSIMillimeter::NSIMillimeter(const int32_t aValue) : NSIUnit(aValue, "mm")
{
    
}

NSIMillimeter::NSIMillimeter(const NSINauticalMile& aNauticalMileValue) : NSIUnit(convertNauticalMileToMm(aNauticalMileValue()), "mm")
{

}
NSIMillimeter::NSIMillimeter(const NSIFoot& aFootValue) : NSIUnit(convertFtToMm(aFootValue()), "mm")
{

} 

NSIMillimeter::NSIMillimeter(const SI::SIMeter& aMeterValue) : NSIUnit(convertMeterToMm((aMeterValue())), "mm")
{

}

NSIMillimeter NSIMillimeter::operator+(const NSIMillimeter& aMillimeter) const
{
    const NSIMillimeter result((*this) () + aMillimeter());

    return result;
}

bool NSIMillimeter::operator==(const NSIMillimeter& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

NSIMillimeter NSIMillimeter::operator-(const NSIMillimeter& aMillimeter) const
{
    const NSIMillimeter result((*this)() - aMillimeter());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
NSIUnitless NSIMillimeter::operator/(const NSIMillimeter& aMillimeter) const
{
    const NSIUnitless result((*this)() / aMillimeter());

    return result;
}

NSIMillimeter& NSIMillimeter::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

int32_t NSIMillimeter::convertNauticalMileToMm(const double aNauticalMileValue)
{
    return round(aNauticalMileValue * 1852000);
}

int32_t NSIMillimeter::convertFtToMm(const double aFoot)
{
    return round(aFoot * 304.800);
}

int32_t NSIMillimeter::convertMeterToMm(const double meter)
{
    return round(meter * 1000.00); 
}

}