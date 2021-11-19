#include "scene.h"
#include "sphere.h"

int main() {

	// Create the scene
	const Vector2 windowSize(256, 256);
	const Camera cammera(Vector3(0, 0, -1000), Normalized(Vector3(0, 0, 1)));
	Scene scene(windowSize, cammera);
	
	// Create some objects
	Sphere spheres[5];
	spheres[0] = Sphere(Vector3(0, 0, 0), 1);
	spheres[1] = Sphere(Vector3(0, 0, 1), 1);
	spheres[2] = Sphere(Vector3(-1, 0, 0), 1);
	spheres[3] = Sphere(Vector3(1, 0, 0), 1);
	spheres[4] = Sphere(Vector3(1, 0, 1), 1);
	
	// Add the objects to the scene
	for (Sphere& sphere : spheres) 
		scene.Add(sphere);
	
	// Raytrace the scene
	scene.Raytrace();


	return 0;
}