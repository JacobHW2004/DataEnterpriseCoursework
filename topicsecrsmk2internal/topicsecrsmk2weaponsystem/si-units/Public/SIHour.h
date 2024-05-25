
#ifndef SIHour_H
#define SIHour_H


#include "SIUnit.h"

#include <string>

namespace SI{

class floatEqualityChecker;

class SIUnitless;

/**
* @brief A class to describe Time.
*
*/
class SIHour : public SIUnit
{
    
public :

    explicit SIHour(const double aValue = 0.0);
    template <typename T> SIHour(const T aValue, const float aResolution) : SIUnit(aValue*aResolution, "h")
    {

    }

    bool operator!=(const SIHour& rhs) const;

    SIHour& operator=(const SIHour& rhs);

    SIHour& operator=(const double rhs);
    
    inline SIHour operator+(const SIHour& aHour) const
    {        
        return SIHour((*this)()+aHour());
    }
    
    inline void operator+=(const SIHour& aHour)
    {
        setValue((*this)() + aHour());
    }
    
    inline SIHour operator-(const SIHour& aHour) const
    {        
        return SIHour((*this)()-aHour());
    }
    
    inline void operator-=(const SIHour& aHour)
    {
        setValue((*this)() - aHour());
    }
    
    SIUnitless operator/(const SIHour& aHour) const;
    
    inline bool operator<(const SIHour& rhs) const
    {
        return (*this)() < rhs();
    }
    
    inline bool operator<=(const SIHour& rhs) const
    {
        return (*this)() <= rhs();
    }
    
    bool operator==(const SIHour& rhs) const;
    
    inline bool operator>(const SIHour& rhs) const
    {
        return (*this)() > rhs();
    }
    
    inline bool operator>=(const SIHour& rhs) const
    {
        return (*this)() >= rhs();
    }
};

}
#endif
