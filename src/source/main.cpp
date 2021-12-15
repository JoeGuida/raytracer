#include "../headers/scene.h"
#include <iostream>
#include <fstream>

int main() {
	// Create the scene
	Canvas canvas(512, 512);
	Viewport viewport(1, 1);
	Scene scene(canvas, viewport);
	
	// Camera for casting rays into the scene
	Ray camera(Point(0, 0, 0), Vector3(0, 0, 1));

	// Create some materials
	Material red_material = Material(Color(255, 0, 0), 500, 0.2f);
	Material blue_material = Material(Color(0, 0, 255), 500, 0.3f);
	Material green_material = Material(Color(0, 255, 0), 10, 0.4f);

	// Create some spheres
	scene.Add(Sphere(Point(0, -1, 3), 1, red_material));
	scene.Add(Sphere(Point(2, 0, 4), 1, blue_material));
	scene.Add(Sphere(Point(-2, 0, 4), 1, green_material));

	// Create some lights
	scene.Add(Light(0.2f, Color(255, 255, 255)));
	scene.Add(Light(Point(2, 1, 0), 0.8f, Color(255, 255, 255)));
	scene.Add(Light(0.2f, Color(255, 255, 255), Vector3(1, 0, 4)));

	// Main Loop
	std::ofstream image;
	image.open("image.ppm");
	image << "P3\n" << canvas.width << ' ' << canvas.height << "\n255\n";
	for (int y = canvas.height / 2; y > -canvas.height / 2; y--) {
		for (int x = -canvas.width / 2; x < canvas.width / 2; x++) {
			Hit hit;
			Vector3 direction = canvas_to_viewport(canvas, viewport, x, y, camera.direction.z);
			Color color = scene.trace_ray(Ray(camera.origin, direction), hit, 1, INFINITY, 3);
			put_pixel(x, y, color, image);
		}
	}

	return 0;
}