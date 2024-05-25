#ifndef TEST_COMPLETED_H
#define TEST_COMPLETED_H

#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

struct TestCompleted
{
   std::string testName{};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(testName, "testName");
  }

   LCA_TOPIC("TestCompleted", 1, 0)

};

}  // namespace Topics

#endif