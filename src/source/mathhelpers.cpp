#include "../headers/mathhelpers.h"

float lerp(float a, float b, float x) {
	return a * (1 - x) + b * x;
}

Color lerp(const Color& a, const Color& b, float x) {
	return a * (1 - x) + b * x;
}