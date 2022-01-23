#ifndef _MATH_HELPERS_H_
#define _MATH_HELPERS_H_

#include <numeric>
#include <cfloat>
#include "color.h"

float lerp(float a, float b, float x);
Color lerp(const Color& a, const Color& b, float x);
bool cmp_float(float a, float b);
float radians_to_degrees(float radians);
float degrees_to_radians(float degrees);

#endif