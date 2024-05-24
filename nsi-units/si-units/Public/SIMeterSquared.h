#ifndef SIMeterSquared_H
#define SIMeterSquared_H


#include "SIUnit.h"

namespace SI{

    /**
    * @brief A class to describe Meter Squared.
    *
    */
    class SIMeterSquared : public SIUnit
    {
    
    public :

        explicit SIMeterSquared(const double aValue = 0.0);
    
        bool operator==(const SIMeterSquared& rhs) const;
    
        SIMeterSquared& operator=(const double rhs);
    };

}
#endif

