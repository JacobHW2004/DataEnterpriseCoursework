#ifndef SISquareMeter_H
#define SISquareMeter_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SICubicMeter;

class SIMeter;

class SIUnitless;


/**
* @brief A class to describe Areas.
*
*/
class SISquareMeter : public SIUnit
{
    
public :

    explicit SISquareMeter(const double aValue = 0.0);
    
    
    SICubicMeter operator*(const SIMeter& aMeter) const;
    
    SIMeter operator/(const SIMeter& aMeter) const;

    bool operator==(const SISquareMeter& rhs) const;
    
    SIUnitless operator/(const SISquareMeter& aSquareMeter) const;

    SISquareMeter& operator=(const double rhs);
};

}
#endif
