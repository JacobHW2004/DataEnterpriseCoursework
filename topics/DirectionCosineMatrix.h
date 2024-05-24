#ifndef DIRECTIONALCOSINEMATRIX_H
#define DIRECTIONALCOSINEMATRIX_H

#include <array>

namespace Topics {

struct DirectionCosineMatrix 
{
   // x0, x1, x2
   // y0, y1, y2
   // z0, z1, z2
   std::array<double, 3> x {0};
   std::array<double, 3> y {0};
   std::array<double, 3> z {0};
   bool isValid;
   DirectionCosineMatrix() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(x[0], "x0");
      archive.Serialise(x[1], "x1");
      archive.Serialise(x[2], "x2");
      archive.Serialise(y[0], "y0");
      archive.Serialise(y[1], "y1");
      archive.Serialise(y[2], "y2");
      archive.Serialise(z[0], "z0");
      archive.Serialise(z[1], "z1");
      archive.Serialise(z[2], "z2");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("DirectionCosineMatrix", 1, 0)
   
};

}  // namespace Topics
#endif