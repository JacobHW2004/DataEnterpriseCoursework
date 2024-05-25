
#ifndef SICubicMeter_H
#define SICubicMeter_H

#include "SIUnit.h"
#include <string>

namespace SI{

class SIMeter;

class SISquareMeter;

class SIUnitless;

/**
* @brief A class to describe Volumes.
*
*/
class SICubicMeter : public SIUnit
{
    
public :

    explicit SICubicMeter(const double aValue = 0.0);
    
  
    
    SISquareMeter operator/(const SIMeter& aMeter) const;
    
    SIUnitless operator/(const SICubicMeter& aCubicMeter) const;
};

}
#endif