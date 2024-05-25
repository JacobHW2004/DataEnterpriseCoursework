
#ifndef SIDegreePerSecondSquared_H
#define SIDegreePerSecondSquared_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIDegree;

class SIDegreePerSecond;

class SISecond;

class SISecondSquared;

class SIUnitless;

/**
* @brief A class to describe Angular accelerations.
*
*/
class SIDegreePerSecondSquared : public SIUnit
{
    
public :

    explicit SIDegreePerSecondSquared(const double aValue = 0.0);
    
    SIDegreePerSecond operator*(const SISecond& aSecond) const;
    
    SIDegree operator*(const SISecondSquared& aSecondSquared) const;

    bool operator==(const SIDegreePerSecondSquared& rhs) const;
    
    SIUnitless operator/(const SIDegreePerSecondSquared& aDegreePerSecondSquared) const;

    SIDegreePerSecondSquared& operator=(const double rhs);

};

}
#endif
