#ifndef _SCENE_H_
#define _SCENE_H_

#include "sphere.h"
#include "plane.h"
#include "canvas.h"
#include "viewport.h"
#include "hit.h"
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

	float bias = 0.0001f;

	const Color BACKGROUND_COLOR = Color(128, 128, 128);

	Scene() {

	}

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

	float get_closest_intersection(const Ray& ray, Hit& hit, float tmin, float tmax);
	Color trace_ray(const Ray& ray, Hit& hit, float tmin, float tmax, int depth);
	Color compute_lighting(Hit& hit, const Ray& ray, int depth);
	float compute_diffuse_lighting(const Light& light, const Hit& hit);
	float compute_specular_lighting(const Light& light, const Hit& hit, const Vector3& v);

} Scene;


#endif