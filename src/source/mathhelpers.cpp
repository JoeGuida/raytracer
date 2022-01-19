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