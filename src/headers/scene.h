#ifndef _SCENE_H_
#define _SCENE_H_

#include "sphere.h"
#include "canvas.h"
#include "viewport.h"
#include "hit.h"
#include "light.h"
#include "point.h"
#include <vector>

typedef struct Scene {

	std::vector<Sphere> spheres;
	std::vector<Light> lights;

	Canvas canvas;
	Viewport viewport;

	float bias = 0.001f;

	const Color BACKGROUND_COLOR = Color(128, 128, 128);

	Scene() {

	}

	Scene(Canvas c, Viewport v) {
		canvas = c;
		viewport = v;
	}

	void Add(const Sphere& sphere) {
		spheres.push_back(sphere);
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