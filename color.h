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

	inline Color operator +(const Color& c) const;
	inline Color operator +(float s) const;
	inline Color operator -(const Color& c) const;
	inline Color operator -(float s) const;
	inline Color operator *(const Color& c) const;
	inline Color operator *(float s) const;
	inline Color operator /(const Color& c) const;
	inline Color operator /(float s) const;

	inline void operator +=(const Color& c);
	inline void operator +=(float s);
	inline void operator -=(const Color& c);
	inline void operator -=(float s);
	inline void operator *=(const Color& c);
	inline void operator *=(float s);
	inline void operator /=(const Color& c);
	inline void operator /=(float s);

} Color;

#endif