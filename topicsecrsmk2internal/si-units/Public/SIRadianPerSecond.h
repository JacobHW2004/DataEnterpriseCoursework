#ifndef SIRadianPerSecond_H
#define SIRadianPerSecond_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIDegree;

class SIRadian;

class SIRadianPerSecondSquared;

class SISecond;

class SIUnitless;

/**
* @brief A class to describe Angular rates.
*
*/
class SIRadianPerSecond : public SIUnit
{
    
public :

    explicit SIRadianPerSecond(const double aValue = 0.0);
    
    SIRadian operator*(const SISecond& aSecond) const;
    
    SIRadianPerSecondSquared operator/(const SISecond& aSecond) const;
    
    SIUnitless operator/(const SIRadianPerSecond& aRadianPerSecond) const;

    SIRadianPerSecond& operator=(const double rhs);

};

}
#endif