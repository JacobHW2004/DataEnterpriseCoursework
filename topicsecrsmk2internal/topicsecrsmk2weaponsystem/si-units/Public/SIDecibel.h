#ifndef SIDecibel_H
#define SIDecibel_H


#include "SIUnit.h"

#include <string>

namespace SI{

class SIUnitless;

/**
* @brief A class to describe decibels.
*
*/
class SIDecibel : public SIUnit
{
    
public :

    explicit SIDecibel(const double aValue = 0);
    
    
    SIUnitless operator/(const SIDecibel& aDecibel) const;

    SIDecibel& operator=(const double rhs);
};

}
#endif
