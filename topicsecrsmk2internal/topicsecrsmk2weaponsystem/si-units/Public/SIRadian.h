
#ifndef SIRadian_H
#define SIRadian_H

#include "SIUnit.h"

#include <string>
#include <cmath>

namespace SI{
    
class floatEqualityChecker;

class SIDegree;

class SIRadianPerSecond;

class SIRadianPerSecondSquared;

class SISecond;

class SISecondSquared;

class SIUnitless;

/**
* @brief An abstraction of a radian unit. This normalizes all values to [-pi, pi] and 
* provides an API such that the user will rarely have to resort of the underlying real representation (via operator()).
*
*/
class SIRadian : public SIUnit
{
 
public :

    explicit SIRadian(const SIDegree& aDegree);
    
    explicit SIRadian(const double aValue);
    
    SIRadian(void);
    
    /**
    * @return the FIRST valid value of this type. Named to be similar to "static const int32_t_t FIRST = ...;" equivalents.
    */
    inline static SIRadian FIRST(void);
    
    inline static double HALF_PI(void);
    
    /**
    * @return the FIRST valid value of this type. Named to be similar to "static const int32_t_t LAST = ...;" equivilants.
    */
    inline static SIRadian LAST(void);
    
    inline static double PI(void);
    
    inline static double TWO_PI(void);
    
    SIRadian abs(void) const;
    
    
    static SIRadian acos(const double aValue);
    
    
    static SIRadian asin(const double aValue);
    
    
    static SIRadian atan(const double aValue);
    
    
    static SIRadian atan2(const double aY, const double aX);
    
    /** 
    * @brief A variant of atan2 that allows a check on the inputs against a known tolerance. If both inputs are smaller than the tolerance a 0 rad value is returned.
    */
    static SIRadian atan2(const double aY, const double aX, const double aTolerance);
    
    
    inline double cos(void) const;
    
    
    SIRadian fabs(void) const;
    
    /**
     * @brief Determine if this radian falls in the arc described by 2 given angles.
     *
     * The user should take care to describe the arc they really want ('from' -> 'to') as there is obviously another arc 
     * ('to' -> 'from') possible from the same angles.
     * 
     * This operation takes handles the circular nature of radians, i.e. the case where 'from' > 'to', through the -PI/+PI disjoint.
     *
     * @param aFrom the starting angle of the arc.
     * @param aTo the end angle of the arc.
     * @return false if the radian does not fall in arc described by the two angles, otherwise true.
     */
    bool inArc(const SIRadian& aFrom, const SIRadian& aTo) const;
    
    bool isApproximatelyEqual(const SIRadian& rhs, const SIRadian& aTolerance) const;
    
    /// Includes 0.
    bool isPositive(void) const;
    
    /// Includes 0.
    bool isZeroOrPositive(void) const;
    
    void limitToMax(const SIRadian& aSIRadian);
    
    void limitToMin(const SIRadian& aSIRadian);
    
    bool operator!=(const SIRadian& rhs) const;
    
    SIRadian operator*(const double aValue) const;
    
    SIRadian& operator*=(const double aValue);
    
    SIRadian operator+(const SIRadian& rhs) const;
    
    SIRadian& operator+=(const SIRadian& rhs);
    
    SIRadian operator-(const SIRadian& rhs) const;
    
    SIRadian operator-(void) const;
    
    SIRadian& operator-=(const SIRadian& rhs);
    
    SIRadian operator/(const double aValue) const;
    
    SIRadianPerSecond operator/(const SISecond& aSecond) const;
    
    SIRadianPerSecondSquared operator/(const SISecondSquared& aSecondSquared) const;
    
    SIUnitless operator/(const SIRadian& aRadian) const;
    
    SIRadian& operator/=(const double aValue);
    
    bool operator<(const SIRadian& rhs) const;
    
    bool operator<=(const SIRadian& rhs) const;
    
    SIRadian& operator=(const double rhs);
    
    bool operator==(const SIRadian& rhs) const;
    
    bool operator>(const SIRadian& rhs) const;
    
    bool operator>=(const SIRadian& rhs) const;
    
    inline double sin(void) const;
    
    
    double tan(void) const;
    
    
    SIDegree toDegree(void) const;

protected :

    /**
    * @brief Default implementation limit to +/- 2PI - but can be overriden to other limits in derivations.
    */
    void normalize(void);

private :

    /**
    * @brief Default implementation limit to +/- 2PI - but can be overriden to other limits in derivations.
    */
    static double normalizeRadian(const double aAngle);
    
    static const double DEG_180;
};

inline SIRadian SIRadian::FIRST(void)
{
    return SIRadian(-PI());
}

inline double SIRadian::HALF_PI(void)
{
    return 1.5707963267948966192313216916398;
    
}

inline SIRadian SIRadian::LAST(void)
{
    return SIRadian(PI());
}

inline double SIRadian::PI(void)
{
    return 3.1415926535897932384626433832795;
}

inline double SIRadian::TWO_PI(void)
{
    return (2.0 * PI());
}

inline double SIRadian::cos(void) const
{
    return ::cos((*this)());
}

inline double SIRadian::sin(void) const
{
    return ::sin((*this)());

}

}
#endif
