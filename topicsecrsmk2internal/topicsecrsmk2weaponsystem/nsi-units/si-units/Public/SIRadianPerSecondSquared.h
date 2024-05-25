
#ifndef SIRadianPerSecondSquared_H
#define SIRadianPerSecondSquared_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIDegree;

class SIRadian;

class SIRadianPerSecond;

class SISecond;

class SISecondSquared;

class SIUnitless;

/**
* @brief A class to describe Angular accelerations.
*
*/
class SIRadianPerSecondSquared : public SIUnit
{
    
public :

    explicit SIRadianPerSecondSquared(const double aValue = 0.0);
    
    SIRadianPerSecond operator*(const SISecond& aSecond) const;
    
    SIRadian operator*(const SISecondSquared& aSecondSquared) const;
    
    SIUnitless operator/(const SIRadianPerSecondSquared& aRadianPerSecondSquared) const;

    SIRadianPerSecondSquared& operator=(const double rhs);

};

}
#endif
