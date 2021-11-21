#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "ray.h"
#include "color.h"

class Sphere {
public:
	Vector3 center;
	float radius;
	Color color;

	Sphere() {
		center = Vector3();
		radius = 1;
		color = Color(255, 0, 0);
	}

	Sphere(Vector3 p, float r, Color c) {
		center = p;
		radius = r;
		color  = c;
	}

	float Sphere::intersects(const Ray& ray, float* t1, float* t2) const;
};

#endif