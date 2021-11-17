#include "scene.h"

void Scene::Trace(int i, int j) {
	std::ofstream image;
	image.open("image.ppm");

	image << "P3\n" << windowSize.x << ' ' << windowSize.y << "\n255\n";
	for (int i = 0; i < windowSize.y; i++) {
		for (int j = 0; j < windowSize.x; j++) {

			//image << r << ' ' << g << ' ' << b << std::endl;
		}
	}
}
