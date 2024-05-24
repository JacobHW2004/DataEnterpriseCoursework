
#ifndef SIHertz_H
#define SIHertz_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIHertzPerSecond;

class SISecond;

class SIUnitless;

/**
* @brief A class to describe frequencies.
*
*/
class SIHertz : public SIUnit
{
    
public :

    explicit SIHertz(const double aValue = 0.0);
    

    SIUnitless operator*(const SISecond& aSecond) const;
    
    SIHertzPerSecond operator/(const SISecond& aSecond) const;
    
    SIUnitless operator/(const SIHertz& aPerSecond) const;
};

}
#endif
