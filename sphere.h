#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "object.h"

class Sphere : virtual Object {
public:
	Vector3 position;
	float radius;

	Sphere() {
		position = Vector3();
		radius = 1;
	}

	Sphere(Vector3 p, float r) {
		position = p;
		radius = r;
	}

	virtual bool intersects(const Ray& ray);
};

#endif