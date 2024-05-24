#ifndef SIMeterPerSecondSquared_H
#define SIMeterPerSecondSquared_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIMeter;

class SIMeterPerSecond;

class SISecond;

class SISecondSquared;

class SIUnitless;

/**
* @brief A class to describe Range Accelerations.
*
*/
class SIMeterPerSecondSquared : public SIUnit
{
       
public :

    explicit SIMeterPerSecondSquared(const double aValue = 0.0);
    
    SIMeterPerSecond operator*(const SISecond& aSecond) const;
    
    SIMeter operator*(const SISecondSquared& aSecondSquared) const;

    bool operator==(const SIMeterPerSecondSquared& rhs) const;
    
    SIUnitless operator/(const SIMeterPerSecondSquared& aMeterPerSecondSquared) const;

    SIMeterPerSecondSquared& operator=(const double rhs);
};

}
#endif