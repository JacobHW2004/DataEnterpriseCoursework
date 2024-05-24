#include "SIUnit.h"

namespace SI{

SIUnit::SIUnit(const double aValue, const std::string& aSymbol) : value(aValue), symbol(aSymbol)
{

}

double SIUnit::operator()(void) const
{
    return value;
}


std::string SIUnit::toString() const
{
   
    return (std::to_string(value) + symbol);
}

void SIUnit::setValue(const double aValue)
{
    value = aValue;
}

}
