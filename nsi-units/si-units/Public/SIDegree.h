#ifndef SIDegree_H
#define SIDegree_H

#include "SIUnit.h"

#include <string>
#include <cmath>

namespace SI{

class SIUnitless;

class floatEqualityChecker;


/**
* @brief This SIDegree class is deliberately minimal to attempt to persuade 
* engineers to use the more featured SIRadian class.
*
*/
class SIDegree : public SIUnit
{
    
public :

    explicit SIDegree(const double aValue = 0);
    
    SIDegree(const SIDegree& aSIDegree);
       
    SIUnitless operator/(const SIDegree& aDegree) const;
    
    SIDegree& operator=(const SIDegree& rhs);
    
    SIDegree& operator=(const double rhs);

    bool operator==(const SIDegree& rhs) const;
};

}
#endif
