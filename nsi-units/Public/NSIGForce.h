#ifndef NSIGForce_H
#define NSIGForce_H

#include "NSIUnit.h"
#include "FloatEqualityChecker.h"
#include "NSIUnitless.h"
#include <string>


namespace NSI {
/**
* @brief A class to describe Range rates.
*
*/
class NSIGForce : public NSIUnit
{

public :

    explicit NSIGForce(const double aValue = 0.0);

    NSIGForce operator+(const NSIGForce& aGForce) const;

    bool operator==(const NSIGForce& rhs) const;

    NSIGForce operator-(const NSIGForce& aGForce) const;

    NSIUnitless operator/(const NSIGForce& aGForce) const;

    NSIGForce& operator=(const double rhs);

};

}
#endif