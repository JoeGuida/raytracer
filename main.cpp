#include "canvas.h"
#include "viewport.h"
#include "ray.h"
#include "color.h"
#include "sphere.h"
#include <iostream>
#include <fstream>
#include <vector>

Color TraceRay(const Ray& ray, float tmin, float tmax, std::vector<Sphere> spheres) {
	float closest_t = INFINITY;
	Sphere* closestSphere = NULL;
	for (Sphere& sphere : spheres) {
		float t1, t2 = 0;
		sphere.intersects(ray, &t1, &t2);

		if (t1 > tmin && t1 < tmax && t1 < closest_t) {
			closest_t = t1;
			closestSphere = &sphere;
		}
		if (t2 > tmin && t2 < tmax && t2 < closest_t) {
			closest_t = t2;
			closestSphere = &sphere;
		}
	}
	if (closestSphere == NULL) {
		return Color(255, 255, 255);
	}
	return closestSphere->color;
}

int main() {
	// Camera settings
	const float ASPECT_RATIO = 16.0 / 9.0;

	// Create canvas and viewport
	Canvas canvas(512, 512);
	Viewport viewport(1, 1);
	
	// Camera for casting rays into the scene
	Ray camera(Vector3(0, 0, 0), Vector3(0, 0, 1));

	// Create some spheres
	std::vector<Sphere> spheres;
	spheres.push_back( Sphere(Vector3(0, -1, 3), 1, Color(255, 0, 0)) );
	spheres.push_back(Sphere(Vector3(2, 0, 4), 1, Color(0, 0, 255)));
	spheres.push_back(Sphere(Vector3(-2, 0, 4), 1, Color(0, 255, 0)));

	// Main Loop
	std::ofstream image;
	image.open("image.ppm");
	image << "P3\n" << canvas.width << ' ' << canvas.height << "\n255\n";
	for (int y = canvas.height / 2; y > -canvas.height / 2; y--) {
		for (int x = -canvas.width / 2; x < canvas.width / 2; x++) {
			Vector3 direction = CanvasToViewport(canvas, viewport, x, y, camera.direction.z);
			Color color = TraceRay(Ray(camera.origin, direction), 1, INFINITY, spheres);
			PutPixel(x, y, color, image);
		}
	}

	return 0;
}