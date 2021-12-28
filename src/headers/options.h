#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include "color.h"

typedef struct Options {

	int sampling;
	int sampling_amount;
	Color background_color;

	Options() {
		sampling = 0; // 1 = subsampling, 2 = supersampling
		sampling_amount = 0;
		background_color = Color(0, 0, 0);
	}

	Options(int s, int a, const Color& b) {
		sampling = s;
		sampling_amount = a;
		background_color = b;
	}

} Options;

#endif