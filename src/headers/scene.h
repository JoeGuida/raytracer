#ifndef _SCENE_H_
#define _SCENE_H_

#include "mathhelpers.h"
#include "options.h"
#include "sphere.h"
#include "plane.h"
#include "canvas.h"
#include "viewport.h"
#include "raycasthit.h"
#include "light.h"
#include "point.h"
#include "camera.h"
#include <vector>

class Scene {
private:
	// Object storage
	std::vector<Sphere> spheres;
	std::vector<Light> lights;

	// Constructor properties
	Canvas canvas;
	Viewport viewport;
	Camera camera;

	// Shadow
	float shadow_bias = 0.0001f;
	RaycastHit hit;

	// Options
	Options options;
	std::ofstream image;

	Color trace_ray(const Ray& ray, RaycastHit& hit, float tmin, float tmax, int recursion_depth);
	bool intersects_object(const Ray& ray, float tmin, float tmax);
	float get_closest_intersection(const Ray& ray, RaycastHit& hit, float tmin, float tmax, std::pair<float, float>& t) const;
	float compute_lighting(const RaycastHit& hit, const Ray& ray);
	float compute_diffuse_lighting(const Vector3& light_direction, const RaycastHit& hit) const;
	float compute_specular_lighting(const Vector3& light_direction, const Vector3& view_direction, const RaycastHit& hit) const;
	Vector3 compute_refraction_vector(const Ray& view_ray, const RaycastHit& hit);
	Color supersample_pixels(const std::vector<Vector3>& pixels, int subdivisions, float offset);

public:
	// Debugging
	static long rays_casted;

	Scene() {
		rays_casted = 0;
	}

	Scene(Canvas c, Viewport v, Camera cam, Options o) {
		canvas = c;
		viewport = v;
		camera = cam;
		options = o;
		rays_casted = 0;
	}

	void Add(const Sphere& sphere) {
		spheres.push_back(sphere);
	}

	void Add(const Light& light) {
		lights.push_back(light);
	}

	void ray_trace_ppm_image(std::string filename);

};


#endif