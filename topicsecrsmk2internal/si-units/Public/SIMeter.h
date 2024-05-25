#ifndef SIMeter_H
#define SIMeter_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SICubicMeter;

class SIMeterPerSecond;

class SIMeterPerSecondSquared;

class SISecond;

class SISecondSquared;

class SISquareMeter;

class SIUnitless;


/**
* @brief A class to describe Ranges.
*
*/
class SIMeter : public SIUnit
{
    
public :

    explicit SIMeter(const double aValue = 0.0);
    
    
    SISquareMeter operator*(const SIMeter& aMeter) const;
    
    SICubicMeter operator*(const SISquareMeter& aSquareMeter) const;
    
    SIMeter operator+(const SIMeter& aMeter) const;

    bool operator==(const SIMeter& rhs) const;
    
    SIMeter operator-(const SIMeter& aMeter) const;
    
    SIMeterPerSecond operator/(const SISecond& aSecond) const;
    
    SIMeterPerSecondSquared operator/(const SISecondSquared& aSecondSquared) const;
    
    SIUnitless operator/(const SIMeter& aMeter) const;

    SIMeter& operator=(const double rhs);
};

}
#endif

