#ifndef _VIEWPORT_H_
#define _VIEWPORT_H_

typedef struct Viewport {

	int width;
	int height;

	Viewport() {
		width = 1;
		height = 1;
	}

	Viewport(int x, int y) {
		width = x;
		height = y;
	}

} Viewport;

#endif