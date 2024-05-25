
#ifndef SIUnitless_H
#define SIUnitless_H

#include "SIUnit.h"

#include <string>

namespace SI{

/**
* @brief A class to describe values with no unit.
*
*/
class SIUnitless : public SIUnit
{
    
public :

    explicit SIUnitless(const double aValue = 0);
};

}
#endif

