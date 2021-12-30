#include "../headers/scene.h"
#include <iostream>
#include <fstream>

int main() {
	// Create the scene
	const int CANVAS_WIDTH = 640;
	const int CANVAS_HEIGHT = 360;
	const float ASPECT_RATIO = float(CANVAS_WIDTH) / float(CANVAS_HEIGHT);

	const float VIEWPORT_WIDTH = 2;
	const float VIEWPORT_HEIGHT = VIEWPORT_WIDTH / ASPECT_RATIO;

	const Canvas canvas(CANVAS_WIDTH, CANVAS_HEIGHT);
	const Viewport viewport(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
	const Camera camera(Vector3(0, 0, 0), Matrix3D(1, 0, 0, 0, 1, 0, 0, 0, 1));

	Options options;
	options.set_supersampling_levels(2);
	options.set_background_color(Color(128, 128, 128));
	options.set_recursion_depth(3);

	Scene scene(canvas, viewport, camera, options);

	//Create some materials
	const Material sphere0_material(Color(255, 0, 255), 10000, 0.0f, 1.52f, 0.5f);
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