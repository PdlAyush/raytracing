#ifndef _COLOR_H_
#define _COLOR_H_
#include "vec3.h"
#include <iostream>

void write_color(std::ostream &out, color pixel_color) {
  // We have used getters in vec3.h such that e[0] = x, e[1] = y
  out << static_cast<int>(255.999 * pixel_color.x()) << " "
      << static_cast<int>(255.999 * pixel_color.y()) << " "
      << static_cast<int>(255.999 * pixel_color.z()) << "\n";
}

#endif