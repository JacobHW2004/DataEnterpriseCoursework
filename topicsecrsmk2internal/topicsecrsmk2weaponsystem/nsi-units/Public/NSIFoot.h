#ifndef NSIFoot_H
#define NSIFoot_H

#include "NSIUnit.h"
#include "NSIUnitless.h"
#include "FloatEqualityChecker.h"
#include "NSINauticalMile.h"
#include "NSIMillimeter.h"
#include "SIMeter.h"
#include <string>

namespace NSI {

class NSIUnitless;

class NSINauticalMile;

class NSIMillimeter;

class SIMeter;

/**
* @brief A class to describe Ranges
* 
*/ 

class NSIFoot : public NSIUnit
{

private :

    static int32_t convertNauticalMileToFt(const double aNauticalMileValue);

    static int32_t convertMmToFt(const double aMillimeterValue);

    static int32_t convertMeterToFt(const double meter);

public :

    explicit NSIFoot(const int32_t aValue = 0);

    explicit NSIFoot(const NSINauticalMile& aNauticalMileValue);

    explicit NSIFoot(const NSIMillimeter& aMillimeterValue);

    explicit NSIFoot(const SI::SIMeter& aMeterValue);

    NSIFoot operator+(const NSIFoot& aFoot) const;

    bool operator==(const NSIFoot& rhs) const;

    NSIFoot operator-(const NSIFoot& aFoot) const;

    NSIUnitless operator/(const NSIFoot& aFoot) const;

    NSIFoot& operator=(const double rhs);

};

}
#endif