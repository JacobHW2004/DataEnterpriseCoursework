#ifndef TASKMAPPING_H
#define TASKMAPPING_H

#include <string>
#include <cstdint>
#include "Fabric/Utils/LCA_Macros.h"
#include "RadarTaskType.h"

//missing files in the non secret repo -- this is here temporarily

namespace Topics {

/**
* @brief This topic class provides the new task mapping request. 
* Contains the type of radar category to map.  
*
*/
class TaskMapping {
public:

	/** The radarTaskCategory defines the new type of task to map within the Radar
	*/
    Common::RadarTaskCategoryType radarTaskCategory;

	double timeCalculated_s;

	/**
	 * @brief Topic Constructor
	 */
	TaskMapping() : 
		timeCalculated_s{0.0},
		radarTaskCategory{ Common::RadarTaskCategoryType::INVALID_CATEGORY} {};

   /**
    * @brief Serialise function required for communications
    * @todo Bools don't serialise
    */
    template <class T>
    void Serialise(T& archive) {
        
		archive.Serialise(radarTaskCategory, "radarTaskCategory");
        archive.Serialise(timeCalculated_s, "timeCalculated_s");
        
    }

    LCA_TOPIC("TaskMapping", 1, 0)

 
};

}  // namespace Topics

#endif