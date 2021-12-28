#include "../headers/scene.h"
#include <iostream>
#include <fstream>

int main() {
	// Create the scene
	const Canvas canvas(512, 512);
	const Viewport viewport(1.5f, 1.5f);
	const Camera camera(Vector3(0, 0, 0), Matrix3D(1, 0, 0, 0, 1, 0, 0, 0, 1));
	const Options options(2, 8, Color(128, 128, 128));
	Scene scene(canvas, viewport, camera, options);

	//Create some materials
	const Material sphere0_material(Color(255, 0, 255), 10000, 0.25f);
	const Material spere1_material(Color(0, 255, 255), 1000, 0.3f);
	const Material sphere2_material(Color(255, 255, 255), 500, 0.0f);
	const Material sphere3_material(Color(255, 255, 0), 1000, 1.0f);

	// Create some spheres
	scene.Add(Sphere(Point(0, -1, 3), 1, sphere0_material));
	scene.Add(Sphere(Point(2, 0, 4), 1, spere1_material));
	scene.Add(Sphere(Point(-2, 0, 4), 1, sphere2_material));
	scene.Add(Sphere(Point(0, 0, 5), 1, sphere3_material));

	// Create some lights
	scene.Add(Light(0.2f, Color(255, 255, 255)));
	scene.Add(Light(0.3f, Color(255, 255, 255), Vector3(-10, 0, 100)));
	scene.Add(Light(Point(0, 10, 10), 0.5f, Color(255, 255, 255)));

	// Raytrace the scene
	scene.ray_trace_ppm_image("image");
	std::cout << "Rays Casted: " << scene.rays_casted << std::endl;

	return 0;
}