#ifndef SIHertzPerSecond_H
#define SIHertzPerSecond_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIHertz;

class SIHertzPerSecondSquared;

class SISecond;

class SIUnitless;

/**
* @brief A class to describe Frequency rates.
*
*/
class SIHertzPerSecond : public SIUnit
{
    
public :

    explicit SIHertzPerSecond(const double aValue = 0.0);
    
    
    SIHertz operator*(const SISecond& aSecond) const;
    
    SIHertzPerSecondSquared operator/(const SISecond& aSecond) const;
    
    SIUnitless operator/(const SIHertzPerSecond& aPerSecondSquared) const;
};

}
#endif