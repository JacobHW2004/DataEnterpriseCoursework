#ifndef NSIMillimeter_H
#define NSIMillimeter_H

#include "NSIUnit.h"
#include "NSIUnitless.h"
#include "NSIFoot.h"
#include "NSIMillimeter.h"
#include "NSINauticalMile.h"
#include "FloatEqualityChecker.h"
#include "SIMeter.h"
#include <string>

namespace NSI {

class NSIUnitless;

class NSINauticalMile;

class NSIFoot;

class SIMeter;

/**
* @brief A class to describe Ranges
* 
*/ 

class NSIMillimeter : public NSIUnit
{

private :

    static int32_t convertNauticalMileToMm(const double aNauticalMileValue);

    static int32_t convertFtToMm(const double aFootValue);

    static int32_t convertMeterToMm(const double meter);

public :

    explicit NSIMillimeter(const int32_t aValue = 0);

    explicit NSIMillimeter(const NSINauticalMile& aNauticalMileValue);

    explicit NSIMillimeter(const NSIFoot& aFootValue);

    explicit NSIMillimeter(const SI::SIMeter& aMeterValue);

    NSIMillimeter operator+(const NSIMillimeter& aMillimeter) const;

    bool operator==(const NSIMillimeter& rhs) const;

    NSIMillimeter operator-(const NSIMillimeter& aMillimeter) const;

    NSIUnitless operator/(const NSIMillimeter& aMillimeter) const;

    NSIMillimeter& operator=(const double rhs);

};

}
#endif