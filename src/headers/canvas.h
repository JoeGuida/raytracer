#ifndef _CANVAS_H_
#define _CANVAS_H_

#include "vector.h"
#include "viewport.h"
#include "color.h"
#include <fstream>

typedef struct Canvas {

	int width;
	int height;

	Canvas() {
		width = 256;
		height = 256;
	}

	Canvas(int x, int y) {
		width = x;
		height = y;
	}

} Canvas;

Vector3 canvas_to_viewport(const Canvas& c, const Viewport& v, float x, float y, float d);
void put_pixel(int x, int y, const Color& c, std::ofstream& filestream);

#endif