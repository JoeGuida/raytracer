#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "object.h"

class Sphere : public Object {
public:
	Vector3 center;
	float radius;

	Sphere() {
		center = Vector3();
		radius = 1;
		material = Material();;
	}

	Sphere(Vector3 p, float r, Material m) {
		center = p;
		radius = r;
		material = m;
	}

	bool intersects(const Ray& ray) const;
};

#endif