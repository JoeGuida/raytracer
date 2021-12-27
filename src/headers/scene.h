#ifndef _SCENE_H_
#define _SCENE_H_

#include "sphere.h"
#include "plane.h"
#include "canvas.h"
#include "viewport.h"
#include "raycasthit.h"
#include "light.h"
#include "point.h"
#include "camera.h"
#include <vector>

typedef struct Scene {

	std::vector<Sphere> spheres;
	std::vector<Plane> planes;
	std::vector<Light> lights;

	Canvas canvas;
	Viewport viewport;
	Camera camera;

	float shadow_bias = 0.0001f;
	RaycastHit hit;

	const Color BACKGROUND_COLOR = Color(128, 128, 128);

	Scene() {}

	Scene(Canvas c, Viewport v, Camera cam) {
		canvas = c;
		viewport = v;
		camera = cam;
	}

	void Add(const Sphere& sphere) {
		spheres.push_back(sphere);
	}

	void Add(const Plane& plane) {
		planes.push_back(plane);
	}

	void Add(const Light& light) {
		lights.push_back(light);
	}

	Color trace_ray(const Ray& ray, RaycastHit& hit, float tmin, float tmax, int recursion_depth);
	bool intersects_object(const Ray& ray, float tmin, float tmax);
	float get_closest_intersection(const Ray& ray, RaycastHit& hit, float tmin, float tmax) const;
	float compute_lighting(RaycastHit& hit, const Ray& ray);
	float compute_diffuse_lighting(const Vector3& light_direction, const RaycastHit& hit) const;
	float compute_specular_lighting(const Vector3& light_direction, const RaycastHit& hit, const Vector3& view_direction) const;

} Scene;


#endif