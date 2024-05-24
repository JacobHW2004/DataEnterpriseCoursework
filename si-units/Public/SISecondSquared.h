
#ifndef SISecondSquared_H
#define SISecondSquared_H

#include "SIUnit.h"

#include <string>

namespace SI{

class SISecond;

class SIUnitless;

/**
* @brief A class to describe Time rates.
*
*/
class SISecondSquared : public SIUnit
{
    
public :

    explicit SISecondSquared(const double aValue = 0.0);
    
    
    SISecond operator/(const SISecond& aSecond) const;
    
    SIUnitless operator/(const SISecondSquared& aSecondSquared) const;
};

}
#endif