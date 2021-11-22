#ifndef _SCENE_H_
#define _SCENE_H_

#include "sphere.h"
#include "canvas.h"
#include "viewport.h"
#include <vector>

typedef struct Scene {

	std::vector<Sphere> spheres;
	Canvas canvas;
	Viewport viewport;

	Scene() {

	}

	Scene(Canvas c, Viewport v) {
		canvas = c;
		viewport = v;
	}

	void Add(Sphere sphere) {
		spheres.push_back(sphere);
	}

	Color TraceRay(const Ray& ray, float tmin, float tmax);

} Scene;


#endif