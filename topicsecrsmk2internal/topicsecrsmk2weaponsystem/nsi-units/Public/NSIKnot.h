#ifndef NSIKnot_H
#define NSIKnot_H

#include "NSIUnit.h"
#include "SIMeterPerSecond.h"
#include "NSIFeetPerMinute.h"
#include "NSIUnitless.h"
#include "FloatEqualityChecker.h"
#include <string>


namespace NSI {

class NSIKnot;

class NSIFeetPerMinute;

class NSIUnitless;


/**
* @brief A class to describe Range rates.
*
*/
class NSIKnot : public NSIUnit
{

private:

    static double convertMpsToKnots(const double aMeterPerSecondValue);

    static double convertFpmToKnots(const double aFeetPerMinuteValue);

public :

    explicit NSIKnot(const double aValue = 0.0);

    explicit NSIKnot(const SI::SIMeterPerSecond& aMeterPerSecondValue);

    explicit NSIKnot(const NSIFeetPerMinute& aFeetPerMinuteValue);

    NSIKnot operator+(const NSIKnot& aKnot) const;

    bool operator==(const NSIKnot& rhs) const;

    NSIKnot operator-(const NSIKnot& aKnot) const;

    NSIUnitless operator/(const NSIKnot& aKnot) const;

    NSIKnot& operator=(const double rhs);

};

}
#endif