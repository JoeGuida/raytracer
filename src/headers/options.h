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

	void set_supersampling_levels(int levels) {
		sampling = 2;
		sampling_amount = levels;
	}

	void set_subsampling_levels(int levels) {
		sampling = 1;
		sampling_amount = levels;
	}

	void set_background_color(const Color& color) {
		background_color = color;
	}

} Options;

#endif