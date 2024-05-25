
#ifndef SISecond_H
#define SISecond_H


#include "SIUnit.h"

#include <string>

namespace SI{

class floatEqualityChecker;

class SIDegree;

class SIMeter;

class SIMeterPerSecond;

class SIRadian;

class SIRadianPerSecond;

class SIUnitless;


/**
* @brief A class to describe Time.
*
*/
class SISecond : public SIUnit
{
    
public :

    explicit SISecond(const double aValue = 0.0);
    
    
    bool operator!=(const SISecond& rhs) const;
    
    SIMeter operator*(const SIMeterPerSecond& aMeterPerSecond) const;
    
    SIRadian operator*(const SIRadianPerSecond& aRadianPerSecond) const;

    SISecond& operator=(const SISecond& rhs);

    SISecond& operator=(const double rhs);
    
    inline SISecond operator+(const SISecond& aSecond) const
    {
        SISecond result((*this)());
        
        result += aSecond;
        
        return result;
    }
    
    inline void operator+=(const SISecond& aSecond)
    {
        setValue((*this)() + aSecond());
    }
    
    inline SISecond operator-(const SISecond& aSecond) const
    {
        SISecond result((*this)());
        
        result -= aSecond;
        
        return result;
    }
    
    inline void operator-=(const SISecond& aSecond)
    {
        setValue((*this)() - aSecond());
    }
    
    SIUnitless operator/(const SISecond& aSecond) const;
    
    inline bool operator<(const SISecond& rhs) const
    {
        return (*this)() < rhs();
    }
    
    inline bool operator<=(const SISecond& rhs) const
    {
        return (*this)() <= rhs();
    }
    
    bool operator==(const SISecond& rhs) const;
    
    inline bool operator>(const SISecond& rhs) const
    {
        return (*this)() > rhs();
    }
    
    inline bool operator>=(const SISecond& rhs) const
    {
        return (*this)() >= rhs();
    }
};

}
#endif
