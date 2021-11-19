#include "scene.h"

// Open ppm image file and set header
// Trace every pixel on the scene canvas
// Output pixel color to ppm file
void Scene::RayTrace() {
	std::ofstream image;
	image.open("image.ppm");
	image << "P3\n" << windowSize.x << ' ' << windowSize.y << "\n255\n";
	for (int i = 0; i < windowSize.y; i++) {
		for (int j = 0; j < windowSize.x; j++) {
			Color c = Trace(i, j);
			image << c.r << ' ' << c.g << ' ' << c.b << std::endl;
		}
	}
}

Color Scene::Trace(int i, int j) {
	Ray ray(camera.position, Vector3(j, i, camera.direction.z));
	Sphere* hit;

	for (Sphere& sphere : spheres) {
		if (sphere.intersects(ray))
		{
			return sphere.material.color;
		}
	}
	return Color(100, 100, 100);
}
