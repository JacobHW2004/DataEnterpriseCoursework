#ifndef NSIMach_H
#define NSIMach_H

#include "NSIUnit.h"
#include "FloatEqualityChecker.h"
#include "SIMeterPerSecond.h"
#include "NSIKnot.h"
#include "NSIFeetPerMinute.h"
#include "NSIUnitless.h"
#include <string>


namespace NSI {
/**
* @brief A class to describe Range rates.
*
*/
class NSIMach : public NSIUnit
{

private: 

    static double convertMpsToMach(const double aMeterPerSecondValue);
    static double convertKnotsToMach(const double aKnot);
    static double convertFpmToMach(const double aFootValue);

public :

    explicit NSIMach(const double aValue = 0.0);

    explicit NSIMach(const SI::SIMeterPerSecond& aMeterPerSecondValue);
    
    explicit NSIMach(const NSI::NSIKnot& aKnot);

    explicit NSIMach(const NSI::NSIFeetPerMinute& aFeetPerMinuteValue);

    NSIMach operator+(const NSIMach& aMach) const;

    bool operator==(const NSIMach& rhs) const;

    NSIMach operator-(const NSIMach& aMach) const;

    NSIUnitless operator/(const NSIMach& aMach) const;

    NSIMach& operator=(const double rhs);

};

}
#endif