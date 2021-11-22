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

Vector3 CanvasToViewport(Canvas c, Viewport v, int x, int y, int d);
void PutPixel(int x, int y, Color c, std::ofstream& filestream);

#endif