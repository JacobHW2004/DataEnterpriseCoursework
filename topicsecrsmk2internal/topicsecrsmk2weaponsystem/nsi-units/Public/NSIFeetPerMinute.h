#ifndef NSIFeetPerMinute_H
#define NSIFeetPerMinute_H

#include "NSIUnit.h"
#include "SIMeterPerSecond.h"
#include "NSIKnot.h"
#include "NSIUnitless.h"
#include "FloatEqualityChecker.h"
#include <string>


namespace NSI {
class NSIKnot;


/**
* @brief A class to describe Range rates.
*
*/
class NSIFeetPerMinute : public NSIUnit
{

private:

    static double convertMpsToFpm(const double aMeterPerSecondValue);
    static double convertKnotsToFpm(const double aKnot);


public :

    explicit NSIFeetPerMinute(const double aValue = 0.0);

    explicit NSIFeetPerMinute(const SI::SIMeterPerSecond& aMeterPerSecondValue);
    
    explicit NSIFeetPerMinute(const NSI::NSIKnot& aKnot);

    NSIFeetPerMinute operator+(const NSIFeetPerMinute& aFeetPerMinuteValue) const;

    bool operator==(const NSIFeetPerMinute& rhs) const;

    NSIFeetPerMinute operator-(const NSIFeetPerMinute& aFeetPerMinuteValue) const;

    NSIUnitless operator/(const NSIFeetPerMinute& aFeetPerMinuteValue) const;

    NSIFeetPerMinute& operator=(const double rhs);

};

}
#endif