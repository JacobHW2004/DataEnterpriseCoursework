
#ifndef SIKelvin_H
#define SIKelvin_H


#include "SIUnit.h"
#include "SIUnitless.h"
#include "FloatEqualityChecker.h"
#include <string>

namespace SI{

class SIUnitless;

/**
* @brief A class to describe temperatures.
*
*/
class SIKelvin : public SIUnit
{
    
public :
    
    explicit SIKelvin(const double aValue = 0.0);

    SIKelvin operator+(const SIKelvin& aKelvin) const;

    bool operator==(const SIKelvin& rhs) const;

    SIKelvin operator-(const SIKelvin& aKelvin) const;

    SIKelvin operator/(const double& aDouble) const;

    SIKelvin operator*(const double& aDouble) const;

    SIKelvin& operator=(const double rhs);
};

}
#endif