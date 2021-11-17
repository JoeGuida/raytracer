#include "color.h"

inline Color Color::operator +(const Color& c) const {
	return Color(r + c.r, g + c.g, b + c.b);
}

inline Color Color::operator +(float s) const {
	return Color(r + s, g + s, b + s);
}

inline Color Color::operator -(const Color& c) const {
	return Color(r - c.r, g - c.g, b - c.b);
}

inline Color Color::operator -(float s) const {
	return Color(r - s, g - s, b - s);
}

inline Color Color::operator *(const Color& c) const {
	return Color(r * c.r, g * c.g, b * c.b);
}

inline Color Color::operator *(float s) const {
	return Color(r * s, g * s, b * s);
}

inline Color Color::operator /(const Color& c) const {
	return Color(r * (1.0f / c.r), g * (1.0f / c.g), b * (1.0f / c.b));
}

inline Color Color::operator /(float s) const {
	s = 1.0f / s;
	return Color(r * s, g * s, b * s);
}

inline void Color::operator +=(const Color& c) {
	r += c.r;
	g += c.g;
	b += c.b;
}

inline void Color::operator +=(float s) {
	r += s;
	g += s;
	b += s;
}

inline void Color::operator -=(const Color& c) {
	r -= c.r;
	g -= c.g;
	b -= c.b;
}

inline void Color::operator -=(float s) {
	r -= s;
	g -= s;
	b -= s;
}

inline void Color::operator *=(const Color& c) {
	r *= c.r;
	g *= c.g;
	b *= c.b;
}

inline void Color::operator *=(float s) {
	r *= s;
	g *= s;
	b *= s;
}

inline void Color::operator /=(const Color& c) {
	r *= (1.0f / c.r);
	g *= (1.0f / c.g);
	b *= (1.0f / c.b);
}

inline void Color::operator /=(float s) {
	s = 1.0f / s;
	r *= s;
	g *= s;
	b *= s;
}