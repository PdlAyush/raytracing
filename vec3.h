#ifndef _VEC3_H_
#define _VEC3_H_

#include <cmath>
#include <iostream>
using std::sqrt;

class vec3 {
public:
  // Constructors
  vec3() : e{0, 0, 0} {}
  vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

  // Getters
  double const x() { return e[0]; }
  double const y() { return e[1]; }
  double const z() { return e[2]; }

  // Operator overloading
  vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

  double operator[](int i) const { return e[i]; }

  double &operator[](int i) { return e[i]; }

  vec3 &operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
  }

  vec3 &operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
  }

  vec3 &operator/=(const double t) { return *this *= 1 / t; }

  // Methods
  double length() const { return sqrt(length_squared()); }

  double length_squared() const {
    return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
  }

  // Property of the vec3 class
public:
  double e[3];
};

// Aliases
using point3 = vec3; // 3d point
using color = vec3;  // rgb color

// Operator overloading

inline std::ostream &operator<<(std::ostream &out, const vec3 &v) {
  return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
  return vec3{v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]};
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
  return vec3{v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]};
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
  return vec3{v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]};
}

inline vec3 operator*(double t, const vec3 &v1) {
  return vec3{t * v1.e[0], t * v1.e[1], t * v1.e[2]};
}

inline vec3 operator/(const vec3 &v1, double t) {
  return vec3(v1.e[0] / t, v1.e[1] / t, v1.e[2] / t);
}

inline vec3 operator*(const vec3 &v, double t) { return vec3(t * v); }

// Inline Methods
inline double dot(const vec3 &v1, const vec3 &v2) {
  return (v1.e[0] + v2.e[0] + v1.e[1] + v2.e[1] + v1.e[2] + v2.e[2]);
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
  return vec3{v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
              v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
              v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]};
}

inline vec3 unit_vector(vec3 v) { return (v / v.length()); }

#endif