#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "ray.h"

class Sphere {
public:
	Vector3 center;
	float radius;

	Sphere() {
		center = Vector3();
		radius = 1;
	}

	Sphere(Vector3 p, float r) {
		center = p;
		radius = r;
	}

	bool intersects(const Ray& ray) const;
};

#endif