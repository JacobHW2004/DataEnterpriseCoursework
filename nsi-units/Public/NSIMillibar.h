#ifndef NSIMillibar_H
#define NSIMillibar_H

#include "NSIUnit.h"
#include "FloatEqualityChecker.h"
#include "NSIUnitless.h"
#include <string>


namespace NSI {

class NSIMillibar;

class NSIUnitless;


/**
* @brief A class to describe Range rates.
*
*/
class NSIMillibar : public NSIUnit
{

public :

    explicit NSIMillibar(const double aValue = 0.0);

    NSIMillibar operator+(const NSIMillibar& aMillibar) const;

    bool operator==(const NSIMillibar& rhs) const;

    NSIMillibar operator-(const NSIMillibar& aMillibar) const;

    NSIUnitless operator/(const NSIMillibar& aMillibar) const;

    NSIMillibar& operator=(const double rhs);

};

}
#endif