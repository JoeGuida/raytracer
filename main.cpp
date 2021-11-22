#include "canvas.h"
#include "viewport.h"
#include "ray.h"
#include "color.h"
#include "sphere.h"
#include "scene.h"
#include <iostream>
#include <fstream>
#include <vector>

int main() {
	// Camera settings
	const float ASPECT_RATIO = 16.0 / 9.0;

	// Create the scene
	Canvas canvas(512, 512);
	Viewport viewport(1, 1);
	Scene scene(canvas, viewport);
	
	// Camera for casting rays into the scene
	Ray camera(Vector3(0, 0, 0), Vector3(0, 0, 1));

	// Create some spheres
	std::vector<Sphere> spheres;
	scene.Add(Sphere(Vector3(0, -1, 3), 1, Color(255, 0, 0)));
	scene.Add(Sphere(Vector3(2, 0, 4), 1, Color(0, 0, 255)));
	scene.Add(Sphere(Vector3(-2, 0, 4), 1, Color(0, 255, 0)));

	// Main Loop
	std::ofstream image;
	image.open("image.ppm");
	image << "P3\n" << canvas.width << ' ' << canvas.height << "\n255\n";
	for (int y = canvas.height / 2; y > -canvas.height / 2; y--) {
		for (int x = -canvas.width / 2; x < canvas.width / 2; x++) {
			Vector3 direction = CanvasToViewport(canvas, viewport, x, y, camera.direction.z);
			Color color = scene.TraceRay(Ray(camera.origin, direction), 1, INFINITY);
			PutPixel(x, y, color, image);
		}
	}

	return 0;
}