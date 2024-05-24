#ifndef SEARCH_QUALITY_REPORT_H
#define SEARCH_QUALITY_REPORT_H

#include <string>
#include <vector>
#include "Fabric/Utils/LCA_Macros.h"
#include "SearchQuality.h"

namespace Topics {

/** @brief This topic class provides a report of search qualities */
class SearchQualityReport {
public:
     
    /** @brief Contains a list of search qualities.*/
    std::vector<SearchQuality> searchQualities{};
    
    /** @brief Serialise function required for communications. */
    template <class T>
    void Serialise(T& archive) {
        archive.Serialise(searchQualities,"searchQuality", "searchQualities");
    }

    LCA_TOPIC("SearchQualityReport", 1, 0)

 
};

}  // namespace Topics

#endif
