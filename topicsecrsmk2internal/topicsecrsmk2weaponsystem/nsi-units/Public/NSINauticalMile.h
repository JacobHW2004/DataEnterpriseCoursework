#ifndef NSINautical_Mile_H
#define NSINautical_Mile_H

#include "NSIUnit.h"
#include "NSIUnitless.h"
#include "NSIFoot.h"
#include "NSIMillimeter.h"
#include "SIMeter.h"
#include "FloatEqualityChecker.h"
#include <string>

namespace NSI {

class NSIUnitless;

class NSIMillimeter;

class NSIFoot;

/**
* @brief A class to describe Ranges.
*
*/
class NSINauticalMile : public NSIUnit
{

private :

    static double convertFtToNauticalMiles(const double aFootValue);

    static double convertMeterToNauticalMiles(const double aMeterValue);

    static double convertMillimeterToNauticalMiles(const double aMillimeterValue);

public :

    explicit NSINauticalMile(const double aValue = 0.0);

    explicit NSINauticalMile(const NSIFoot& aFootValue);

    explicit NSINauticalMile(const SI::SIMeter& aMeterValue);
    
    explicit NSINauticalMile(const NSIMillimeter& aMillimeterValue);

    NSINauticalMile operator+(const NSINauticalMile& aNauticalMile) const;

    bool operator==(const NSINauticalMile& rhs) const;

    NSINauticalMile operator-(const NSINauticalMile& aNauticalMile) const;

    NSIUnitless operator/(const NSINauticalMile& aNauticalMile) const;

    NSINauticalMile& operator=(const double rhs);

};

}
#endif