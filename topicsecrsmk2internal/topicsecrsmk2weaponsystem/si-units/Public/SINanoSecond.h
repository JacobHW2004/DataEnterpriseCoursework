
#ifndef SINanoSecond_H
#define SINanoSecond_H


#include "SIUnit.h"

#include <string>

namespace SI{

class floatEqualityChecker;

class SIUnitless;

/**
* @brief A class to describe Time.
*
*/
class SINanoSecond : public SIUnit
{
    
public :

    explicit SINanoSecond(const double aValue = 0.0);
    template <typename T> SINanoSecond(const T aValue, const float aResolution) : SIUnit(aValue*aResolution, "ns")
    {

    }

    bool operator!=(const SINanoSecond& rhs) const;

    SINanoSecond& operator=(const SINanoSecond& rhs);

    SINanoSecond& operator=(const double rhs);
    
    inline SINanoSecond operator+(const SINanoSecond& aNanoSecond) const
    {        
        return SINanoSecond((*this)()+aNanoSecond());
    }
    
    inline void operator+=(const SINanoSecond& aNanoSecond)
    {
        setValue((*this)() + aNanoSecond());
    }
    
    inline SINanoSecond operator-(const SINanoSecond& aNanoSecond) const
    {        
        return SINanoSecond((*this)()-aNanoSecond());
    }
    
    inline void operator-=(const SINanoSecond& aNanoSecond)
    {
        setValue((*this)() - aNanoSecond());
    }
    
    SIUnitless operator/(const SINanoSecond& aNanoSecond) const;
    
    inline bool operator<(const SINanoSecond& rhs) const
    {
        return (*this)() < rhs();
    }
    
    inline bool operator<=(const SINanoSecond& rhs) const
    {
        return (*this)() <= rhs();
    }
    
    bool operator==(const SINanoSecond& rhs) const;
    
    inline bool operator>(const SINanoSecond& rhs) const
    {
        return (*this)() > rhs();
    }
    
    inline bool operator>=(const SINanoSecond& rhs) const
    {
        return (*this)() >= rhs();
    }
};

}
#endif
