#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct Colorf {

	float r;
	float g;
	float b;

	Colorf() {
		r = 0;
		g = 0;
		b = 0;
	}

	Colorf(float x, float y, float z) {
		r = x;
		g = y;
		b = z;
	}

	Colorf(const Colori& c) {
		r = float(c.r);
		g = float(c.g);
		b = float(c.b);
	}

} Colorf;

typedef struct Colori {

	int r;
	int g;
	int b;

	Colori() {
		r = 0;
		g = 0;
		b = 0;
	}

	Colori(int x, int y, int z) {
		r = x;
		g = y;
		b = z;
	}

	Colori(const Colorf& c) {
		r = int(c.r);
		g = int(c.g);
		b = int(c.b);
	}

} Colori;

Colorf operator +(const Colorf& a, const Colorf& b);
Colorf operator +(const Colorf& c, float s);
Colorf operator -(const Colorf& a, const Colorf& b);
Colorf operator -(const Colorf& c, float s);
Colorf operator *(const Colorf& a, const Colorf& b);
Colorf operator *(const Colorf& c, float s);
Colorf operator /(const Colorf& a, const Colorf& b);
Colorf operator /(const Colorf& c, float s);

Colori operator +(const Colori& a, const Colori& b);
Colori operator +(const Colori& c, float s);
Colori operator -(const Colori& a, const Colori& b);
Colori operator -(const Colori& c, float s);
Colori operator *(const Colori& a, const Colori& b);
Colori operator *(const Colori& c, float s);
Colori operator /(const Colori& a, const Colori& b);
Colori operator /(const Colori& c, float s);

#endif