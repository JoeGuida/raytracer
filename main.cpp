#include "vector.h"
#include <iostream>

int main() {

	// Image Dimensions
	const int image_height = 256;
	const int image_width = 256;

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int i = 0; i < image_height; i++) {
		for (int j = 0; j < image_width; j++) {

			//std::cout << r << ' ' << g << ' ' << b << std::endl;
		}
	}

	return 0;
}