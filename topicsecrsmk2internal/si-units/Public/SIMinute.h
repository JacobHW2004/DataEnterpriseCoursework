
#ifndef SIMinute_H
#define SIMinute_H


#include "SIUnit.h"

#include <string>

namespace SI{

class floatEqualityChecker;

class SIUnitless;

/**
* @brief A class to describe Time.
*
*/
class SIMinute : public SIUnit
{
    
public :

    explicit SIMinute(const double aValue = 0.0);
    template <typename T> SIMinute(const T aValue, const float aResolution) : SIUnit(aValue*aResolution, "min")
    {

    }

    bool operator!=(const SIMinute& rhs) const;

    SIMinute& operator=(const SIMinute& rhs);

    SIMinute& operator=(const double rhs);
    
    inline SIMinute operator+(const SIMinute& aMinute) const
    {        
        return SIMinute((*this)()+aMinute());
    }
    
    inline void operator+=(const SIMinute& aMinute)
    {
        setValue((*this)() + aMinute());
    }
    
    inline SIMinute operator-(const SIMinute& aMinute) const
    {        
        return SIMinute((*this)()-aMinute());
    }
    
    inline void operator-=(const SIMinute& aMinute)
    {
        setValue((*this)() - aMinute());
    }
    
    SIUnitless operator/(const SIMinute& aMinute) const;
    
    inline bool operator<(const SIMinute& rhs) const
    {
        return (*this)() < rhs();
    }
    
    inline bool operator<=(const SIMinute& rhs) const
    {
        return (*this)() <= rhs();
    }
    
    bool operator==(const SIMinute& rhs) const;
    
    inline bool operator>(const SIMinute& rhs) const
    {
        return (*this)() > rhs();
    }
    
    inline bool operator>=(const SIMinute& rhs) const
    {
        return (*this)() >= rhs();
    }
};

}
#endif
