#ifndef SIKilogram_H
#define SIKilogram_H

#include "SIUnit.h"
#include "FloatEqualityChecker.h"
#include "SIUnitless.h"
#include <string>


namespace SI {

class SIKilogram;

class SIUnitless;


/**
* @brief A class to describe Weight.
*
*/
class SIKilogram : public SIUnit
{

public :

    explicit SIKilogram(const double aValue = 0.0);

    SIKilogram operator+(const SIKilogram& aKilogram) const;

    bool operator==(const SIKilogram& rhs) const;

    SIKilogram operator-(const SIKilogram& aKilogram) const;

    SIKilogram operator*(const double& aDouble) const;

    SIKilogram operator/(const double& aDouble) const;

    SIKilogram& operator=(const double rhs);

};

}
#endif