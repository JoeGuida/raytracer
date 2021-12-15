#include "../headers/canvas.h"

Vector3 canvas_to_viewport(Canvas c, Viewport v, int x, int y, int d) {
	float vx = x * (float(v.width) / float(c.width));
	float vy = y * (float(v.height) / float(c.height));
	return Vector3(vx, vy, d);
}

void put_pixel(int x, int y, const Color& c, std::ofstream& filestream) {
	if (filestream.is_open())
		filestream << c.r << ' ' << c.g << ' ' << c.b << std::endl;
}