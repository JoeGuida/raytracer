#ifndef _CANVAS_H_
#define _CANVAS_H_

#include "vector.h"
#include "viewport.h"
#include "color.h"
#include <fstream>

typedef struct Canvas {

	int width;
	int height;

	Canvas(int x, int y) {
		width = x;
		height = y;
	}

} Canvas;

Vector3 CanvasToViewport(Canvas c, Viewport v, int x, int y, int d) {
	float vx = x * (float(v.width) / float(c.width));
	float vy = y * (float(v.height) / float(c.height));
	return Vector3(vx, vy, d);
}

void PutPixel(int x, int y, Color c, std::ofstream& filestream) {
	if(filestream.is_open())
		filestream << c.r << ' ' << c.g << ' ' << c.b << std::endl;
}

#endif