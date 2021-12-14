#include "../headers/color.h"

Color operator +(const Color& a, const Color& b) {
	return Color(a.r + b.r, a.g + b.g, a.b + b.b);
}

Color operator +(const Color& c, float s) {
	return Color(c.r + s, c.g + s, c.b + s);
}

Color operator -(const Color& a, const Color& b) {
	return Color(a.r - b.r, a.g - b.g, a.b - b.b);
}

Color operator -(const Color& c, float s) {
	return Color(c.r - s, c.g - s, c.b - s);
}

Color operator *(const Color& a, const Color& b) {
	return Color(a.r * b.r, a.g * b.g, a.b * b.b);
}

Color operator *(const Color& c, float s) {
	return Color(c.r * s, c.g * s, c.b * s);
}

Color operator /(const Color& a, const Color& b) {
	return Color(a.r * (1.f / b.r), a.g * (1.f / b.g), a.b * (1.f / b.b));
}

Color operator /(const Color& c, float s) {
	s = 1.f / s;
	return Color(c.r * s, c.g * s, c.b * s);
}