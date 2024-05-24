#ifndef SIDegreePerSecond_H
#define SIDegreePerSecond_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIDegree;

class SIDegreePerSecondSquared;

class SISecond;

class SIUnitless;

/**
* @brief A class to describe Angular rates.
*
*/
class SIDegreePerSecond : public SIUnit
{
    
public :

    explicit SIDegreePerSecond(const double aValue = 0.0);
    
    SIDegree operator*(const SISecond& aSecond) const;
    
    SIDegreePerSecondSquared operator/(const SISecond& aSecond) const;

    bool operator==(const SIDegreePerSecond& rhs) const;
    
    SIUnitless operator/(const SIDegreePerSecond& aDegreePerSecond) const;

    SIDegreePerSecond& operator=(const double rhs);

};

}
#endif