#ifndef _VIEWPORT_H_
#define _VIEWPORT_H_

typedef struct Viewport {

	float width;
	float height;

	Viewport() {
		width = 1;
		height = 1;
	}

	Viewport(float x, float y) {
		width = x;
		height = y;
	}

} Viewport;

#endif