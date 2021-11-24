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

	Color TraceRay(const Ray& ray, Hit& hit, float tmin, float tmax);
	float ComputeLighting(const Point& point, const Vector3& normal);


} Scene;


#endif