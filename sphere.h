#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "ray.h"
#include "color.h"

class Sphere {
public:
	Point center;
	float radius;
	Color color;

	Sphere() {
		center = Point();
		radius = 1;
		color = Color(255, 0, 0);
	}

	Sphere(Point p, float r, Color c) {
		center = p;
		radius = r;
		color  = c;
	}

	float intersects(const Ray& ray, float* t1, float* t2) const;
};

#endif