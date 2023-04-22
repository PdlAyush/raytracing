#ifndef _RAY_H_
#define _RAY_H_
#include "vec3.h"
#include <iostream>
class ray {
public:
  // Constructors
  ray();
  ray(const point3 &origin, const vec3 &direction)
      : orig(origin), dir(direction) {}

  // Getters
  point3 origin() const { return orig; }
  vec3 direction() const { return dir; }

  // Ray as function is P(t) = A + tb
  point3 at(double t) const { return orig + t * dir; }

public:
  point3 orig;
  vec3 dir;
};

#endif