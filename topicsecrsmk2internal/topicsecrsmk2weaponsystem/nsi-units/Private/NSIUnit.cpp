#include "NSIUnit.h"

namespace NSI{

NSIUnit::NSIUnit(const double aValue, const std::string& aSymbol) : value(aValue), symbol(aSymbol)
{

}

double NSIUnit::operator()(void) const
{
    return value;
}


std::string NSIUnit::toString() const
{
   
    return (std::to_string(value) + symbol);
}

void NSIUnit::setValue(const double aValue)
{
    value = aValue;
}

}
