#include "color.h"

Colorf operator +(const Colorf& a, const Colorf& b) {
	return Colorf(a.r + b.r, a.g + b.g, a.b + b.b);
}

Colorf operator +(const Colorf& c, float s) {
	return Colorf(c.r + s, c.g + s, c.b + s);
}

Colorf operator -(const Colorf& a, const Colorf& b) {
	return Colorf(a.r - b.r, a.g - b.g, a.b - b.b);
}

Colorf operator -(const Colorf& c, float s) {
	return Colorf(c.r - s, c.g - s, c.b - s);
}

Colorf operator *(const Colorf& a, const Colorf& b) {
	return Colorf(a.r * b.r, a.g * b.g, a.b * b.b);
}

Colorf operator *(const Colorf& c, float s) {
	return Colorf(c.r * s, c.g * s, c.b * s);
}

Colorf operator /(const Colorf& a, const Colorf& b) {
	return Colorf(a.r * (1.f / b.r), a.g * (1.f / b.g), a.b * (1.f / b.b));
}

Colorf operator /(const Colorf& c, float s) {
	s = 1.f / s;
	return Colorf(c.r * s, c.g * s, c.b * s);
}

Colori operator +(const Colori& a, const Colori& b) {
	return Colori(a.r + b.r, a.g + b.g, a.b + b.b);
}

Colori operator +(const Colori& c, float s) {
	return Colori(c.r + s, c.g + s, c.b + s);
}

Colori operator -(const Colori& a, const Colori& b) {
	return Colori(a.r - b.r, a.g - b.g, a.b - b.b);
}

Colori operator -(const Colori& c, float s) {
	return Colori(c.r - s, c.g - s, c.b - s);
}

Colori operator *(const Colori& a, const Colori& b) {
	return Colori(a.r * b.r, a.g * b.g, a.b * b.b);
}

Colori operator *(const Colori& c, float s) {
	return Colori(c.r * s, c.g * s, c.b * s);
}

Colori operator /(const Colori& a, const Colori& b) {
	return Colori(a.r * (1.f / b.r), a.g * (1.f / b.g), a.b * (1.f / b.b));
}

Colori operator /(const Colori& c, float s) {
	s = 1.f / s;
	return Colori(c.r * s, c.g * s, c.b * s);
}
