#ifndef SIUnit_H
#define SIUnit_H


#include <string>

/**
* @brief SI Units 
* A collection of classes and methods used to represent data types in the format of the International System of Units.
*/
namespace SI{

/**
* @brief A class to describe any SI Unit - provides storage of the underlying value using a double and implements toString functionality. 
* Although not abstract it is unlikely client code would use this type directly.
*
*/
class SIUnit
{
    
public :

    SIUnit(const double aValue, const std::string& aSymbol);
    
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

