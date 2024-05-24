
#ifndef NSIUnitless_H
#define NSIUnitless_H

#include "NSIUnit.h"

#include <string>

namespace NSI{

/**
* @brief A class to describe values with no unit.
*
*/
class NSIUnitless : public NSIUnit
{
    
public :

    explicit NSIUnitless(const double aValue = 0);
};

}
#endif

