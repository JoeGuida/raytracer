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

	const Color BACKGROUND_COLOR = Color(255, 255, 255);

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

	Color trace_ray(const Ray& ray, Hit& hit, float tmin, float tmax, int depth);
	float compute_lighting(const Hit& hit, const Ray& ray);
	float compute_diffuse_lighting(const Light& light, const Hit& hit);
	float compute_specular_lighting(const Light& light, const Hit& hit, const Vector3& v, float s);
	Color compute_reflection_color(const Light& light, const Hit& hit);

} Scene;


#endif