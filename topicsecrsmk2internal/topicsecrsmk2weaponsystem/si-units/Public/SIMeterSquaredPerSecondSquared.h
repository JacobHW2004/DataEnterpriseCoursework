
#ifndef SIMeterSquaredPerSecondSquared_H
#define SIMeterSquaredPerSecondSquared_H

#include "SIUnit.h"

namespace SI {

    /**
    * @brief A class to describe meters squared per second squared.
    *
    */
    class SIMeterSquaredPerSecondSquared : public SIUnit
    {

    public:

        explicit SIMeterSquaredPerSecondSquared(const double aValue = 0.0);

        bool operator==(const SIMeterSquaredPerSecondSquared& rhs) const;

        SIMeterSquaredPerSecondSquared& operator=(const double rhs);
    };

}
#endif

