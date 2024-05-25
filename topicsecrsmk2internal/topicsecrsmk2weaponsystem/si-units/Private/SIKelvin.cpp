#include"SIKelvin.h"


namespace SI {

SIKelvin::SIKelvin(const double aValue) : SIUnit(aValue, "K")
{
    
}

SIKelvin SIKelvin::operator+(const SIKelvin& aKelvin) const
{
    const SIKelvin result((*this)() + aKelvin());

    return result;
}

bool SIKelvin::operator==(const SIKelvin& rhs) const
{
    return SI::floatEqualityChecker::AlmostEqual((*this)(), rhs());
}

SIKelvin SIKelvin::operator-(const SIKelvin& aKelvin) const
{   
    const SIKelvin result((*this)() - aKelvin());

    return result;
}

/**
 * @brief Protection against divide by 0 needs to be done by the code calling the function.
 * 
*/
SIKelvin SIKelvin::operator/(const double& aDouble) const
{ 
    const SIKelvin result ((*this)() / aDouble);

    return result;
}

SIKelvin SIKelvin::operator*(const double& aDouble) const
{ 
    const SIKelvin result ((*this)() * aDouble);

    return result;
}


SIKelvin& SIKelvin::operator=(const double rhs)
{
    setValue(rhs);

    return *this;
}

}