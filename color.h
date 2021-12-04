#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct Color {

	float r;
	float g;
	float b;

	Color() {
		r = 0;
		g = 0;
		b = 0;
	}

	Color(float x, float y, float z) {
		r = x;
		g = y;
		b = z;
	}

} Color;

Color operator +(const Color& a, const Color& b);
Color operator +(const Color& c, float s);
Color operator -(const Color& a, const Color& b);
Color operator -(const Color& c, float s);
Color operator *(const Color& a, const Color& b);
Color operator *(const Color& c, float s);
Color operator /(const Color& a, const Color& b);
Color operator /(const Color& c, float s);
Color ColorfToColori(const Color& c);

#endif