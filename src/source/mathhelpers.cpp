#include "../headers/mathhelpers.h"

float lerp(float a, float b, float x) {
	return a * (1 - x) + b * x;
}

Color lerp(const Color& a, const Color& b, float x) {
	return a * (1 - x) + b * x;
}

bool cmp_float(float a, float b) {
	return (fabsf((a)-(b)) <= FLT_EPSILON * fmaxf(1.0f, fmaxf(fabsf(a), fabsf(b))));
}

float radians_to_degrees(float radians) {
	return radians * 57.295754f;
}

float degrees_to_radians(float degrees) {
	return degrees * 0.0174533f;
}