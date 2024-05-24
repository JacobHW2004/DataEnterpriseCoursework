#ifndef SIAmplitudePower_H
#define SIAmplitudePower_H


#include "SIUnit.h"
#include <cmath>

namespace SI{

class SIDecibel;

/**
* @brief A class to describe Amplitude Powers.
*
*/
class SIAmplitudePower : public SIUnit
{
    
public :

    explicit SIAmplitudePower(const SIDecibel& aDecibel);
    
    SIAmplitudePower(void);
};


}
#endif