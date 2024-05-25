
#ifndef SIMilliSecond_H
#define SIMilliSecond_H


#include "SIUnit.h"

#include <string>

namespace SI{

class floatEqualityChecker;

class SIUnitless;

/**
* @brief A class to describe Time.
*
*/
class SIMilliSecond : public SIUnit
{
    
public :

    explicit SIMilliSecond(const double aValue = 0.0);
    template <typename T> SIMilliSecond(const T aValue, const float aResolution) : SIUnit(aValue*aResolution, "ms")
    {

    }

    bool operator!=(const SIMilliSecond& rhs) const;

    SIMilliSecond& operator=(const SIMilliSecond& rhs);

    SIMilliSecond& operator=(const double rhs);
    
    inline SIMilliSecond operator+(const SIMilliSecond& aMilliSecond) const
    {        
        return SIMilliSecond((*this)()+aMilliSecond());
    }
    
    inline void operator+=(const SIMilliSecond& aMilliSecond)
    {
        setValue((*this)() + aMilliSecond());
    }
    
    inline SIMilliSecond operator-(const SIMilliSecond& aMilliSecond) const
    {        
        return SIMilliSecond((*this)()-aMilliSecond());
    }
    
    inline void operator-=(const SIMilliSecond& aMilliSecond)
    {
        setValue((*this)() - aMilliSecond());
    }
    
    SIUnitless operator/(const SIMilliSecond& aMilliSecond) const;
    
    inline bool operator<(const SIMilliSecond& rhs) const
    {
        return (*this)() < rhs();
    }
    
    inline bool operator<=(const SIMilliSecond& rhs) const
    {
        return (*this)() <= rhs();
    }
    
    bool operator==(const SIMilliSecond& rhs) const;
    
    inline bool operator>(const SIMilliSecond& rhs) const
    {
        return (*this)() > rhs();
    }
    
    inline bool operator>=(const SIMilliSecond& rhs) const
    {
        return (*this)() >= rhs();
    }
};

}
#endif
