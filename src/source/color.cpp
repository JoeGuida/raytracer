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

bool operator ==(const Color& l, const Color& r) {
	return l.r == r.r && l.g == r.g && l.b == r.b;
}

bool operator !=(const Color& l, const Color& r) {
	return !(l == r);
}

Color float_to_rgb_color(const Color& color) {
	return Color(int(color.r), int(color.g), int(color.b));
}