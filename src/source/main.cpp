#include "../headers/scene.h"
#include <iostream>
#include <fstream>

void ray_trace_scene(Scene& scene, std::ofstream& image) {
	image.open("image.ppm");
	image << "P3\n" << scene.canvas.width << ' ' << scene.canvas.height << "\n255\n";
	for (int y = scene.canvas.height / 2; y > -scene.canvas.height / 2; y--) {
		for (int x = -scene.canvas.width / 2; x < scene.canvas.width / 2; x++) {
			RaycastHit hit;
			const Vector3 direction = canvas_to_viewport(scene.canvas, scene.viewport, x, y, 1) * scene.camera.rotation;
			const Color color = scene.trace_ray(Ray(scene.camera.position, direction), hit, 0, INFINITY, 3);
			put_pixel(x, y, color, image);
		}
	}
}

int main() {
	// Create the scene
	const Canvas canvas(512, 512);
	const Viewport viewport(1, 1);
	const Camera camera(Vector3(0, 0, 0), Matrix3D(1, 0, 0, 0, 1, 0, 0, 0, 1));
	Scene scene(canvas, viewport, camera);

	// Create some materials
	const Material sphere0_material(Color(255, 0, 0), 10000, 0.7f);
	const Material spere1_material(Color(0, 0, 255), 1000, 0.5f);
	const Material sphere2_material(Color(0, 255, 0), 500, 0.5f);

	// Create some spheres
	scene.Add(Sphere(Point(0, -1, 3), 1, sphere0_material));
	scene.Add(Sphere(Point(2, 0, 4), 1, spere1_material));
	scene.Add(Sphere(Point(-2, 0, 4), 1, sphere2_material));

	// Create some lights
	scene.Add(Light(0.2f, Color(255, 255, 255)));
	scene.Add(Light(0.6f, Color(255, 255, 255), Vector3(1, -0.5, 1)));
	scene.Add(Light(Point(0, 10, 10), 0.2f, Color(255, 255, 255)));

	// Raytrace the scene
	std::ofstream image;
	ray_trace_scene(scene, image);

	return 0;
}