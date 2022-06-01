#pragma once
#include <memory>
#include <cmath>
#include <limits>
#include <cstdlib>

//usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

//constants
const float infinity = std::numeric_limits<float>::infinity();
const float Pi = 3.1415926535897932385;

//utility function
const float degrees_to_radians(float degree) {
	return degree * Pi / 180.0;
}

inline float clamp(float x, float min, float max) {
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

inline float random_float() {
	//return a random real  in [0,1]
	return rand() / (RAND_MAX + 1.0);
}
inline float random_float(float min, float max) {
	// Returns a random real in [min,max).
	return min + (max - min) * random_float();
}

//common headers

#include "ray.h"
#include "vec3.h"
