#ifndef SIMeterPerSecond_H
#define SIMeterPerSecond_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIMeter;

class SIMeterPerSecondSquared;

class SISecond;

class SIUnitless;


/**
* @brief A class to describe Range rates.
*
*/
class SIMeterPerSecond : public SIUnit
{
    
public :

    explicit SIMeterPerSecond(const double aValue = 0.0);
    
    
    SIMeter operator*(const SISecond& aSecond) const;
    
    SIMeterPerSecondSquared operator/(const SISecond& aSecond) const;

    bool operator==(const SIMeterPerSecond& rhs) const;
    
    SIUnitless operator/(const SIMeterPerSecond& aMeterPerSecond) const;

    SIMeterPerSecond& operator=(const double rhs);
};

}
#endif
