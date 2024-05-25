#ifndef NSIUnit_H
#define NSIUnit_H


#include <string>

/**
* @brief NSI Units 
* A collection of classes and methods used to represent data types not included in the International System of Units.
*/
namespace NSI{

/**
* @brief A class to describe any NSI Unit - provides storage of the underlying value using a double and implements toString functionality. 
* Although not abstract it is unlikely client code would use this type directly.
*
*/
class NSIUnit
{
    
public :

    NSIUnit(const double aValue, const std::string& aSymbol);
    
    double operator()(void) const;
    std::string toString() const;

protected :

    void setValue(const double aValue);


private :

    double value;
    std::string symbol;
    

};

}
#endif

