
#ifndef floatEqualityChecker_H
#define floatEqualityChecker_H


#include <cmath>

namespace SI{


/**
* @brief A class for floating point comparison.
*/
class floatEqualityChecker
{
    
public :

    /**
     * @brief Takes in two values for comparison and an epsilon value (used as a threshold / margin of error)
     * The two values are compared and if there within range of the epsilon value, true is returned. otherwise false
     * 
     * If a negative epsilon value is passed, it will be converted to a positive one inside the function
     * 
     * @param aVal1 
     * @param aVal2 
     * @param aEpsilon 
     * @return true 
     * @return false 
     */
    static bool AlmostEqual(const float aVal1, const float aVal2, const float aEpsilon = 1e-25);

    /**
     * @brief Takes in two values for comparison and an epsilon value (used as a threshold / margin of error)
     * The two values are compared and if there within range of the epsilon value, true is returned. otherwise false
     * 
     * If a negative epsilon value is passed, it will be converted to a positive one inside the function
     * 
     * @param aVal1 
     * @param aVal2 
     * @param aEpsilon 
     * @return true 
     * @return false 
     */
    static bool AlmostEqual(const double aVal1, const double aVal2, const double aEpsilon = 1e-300);
    

};

}
#endif

