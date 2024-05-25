
#include "SIAmplitudePower.h"
#include "SIDecibel.h"

namespace SI{

SIAmplitudePower::SIAmplitudePower(const SIDecibel& aDecibel) : SIUnit(pow(10.0, aDecibel()/10.0), "W" )
{
    
}

SIAmplitudePower::SIAmplitudePower(void) : SIUnit(1.0,"W") 
{
}

}