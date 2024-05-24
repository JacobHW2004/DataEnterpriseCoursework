
#ifndef SIHertzPerSecondSquared_H
#define SIHertzPerSecondSquared_H

#include "SIUnit.h"

#include <string>

namespace SI{

class SIHertzPerSecond;

class SISecond;

class SIUnitless;

/**
* @brief A class to describe Frequency accelerations.
*
*/
class SIHertzPerSecondSquared : public SIUnit
{
    
public :

    explicit SIHertzPerSecondSquared(const double aValue = 0.0);
    
    
    SIHertzPerSecond operator*(const SISecond& aSecond) const;
    
    SIUnitless operator/(const SIHertzPerSecondSquared& aPerSecondCubed) const;
};

}
#endif