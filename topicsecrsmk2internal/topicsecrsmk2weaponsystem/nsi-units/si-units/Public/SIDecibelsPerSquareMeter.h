#ifndef SIDecibelsPerSquareMeter_H
#define SIDecibelsPerSquareMeter_H


#include "SIUnit.h"

#include <string>

namespace SI{


/**
* @brief A class to describe decibels per square metre.
*
*/
class SIDecibelsPerSquareMeter : public SIUnit
{
    
public :

    explicit SIDecibelsPerSquareMeter(const double aValue = 0.0);

    SIDecibelsPerSquareMeter& operator=(const double rhs);

    bool operator==(const SIDecibelsPerSquareMeter& rhs) const;

};

}
#endif
