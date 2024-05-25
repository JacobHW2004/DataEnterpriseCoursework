
#ifndef SIRadianSquared_H
#define SIRadianSquared_H

#include "SIUnit.h"

namespace SI {

    /**
    * @brief A class to describe radians squared.
    *
    */
    class SIRadianSquared : public SIUnit
    {

    public:

        explicit SIRadianSquared(const double aValue = 0.0);

        bool operator==(const SIRadianSquared& rhs) const;

        SIRadianSquared& operator=(const double rhs);
    };

}
#endif

