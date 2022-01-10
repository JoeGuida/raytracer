#ifndef _PLANE_H_
#define _PLANE_H_

#include "primitive.h"
#include "vector.h"
#include "material.h"
#include "ray.h"

typedef struct Plane : Primitive {

	Vector3 normal;
	float distance;
	Material material;

	Plane() {
		normal = Vector3();
		distance = 0.0f;
		material = Material();
	}

	Plane(Vector3 n, float d, Material m) {
		normal = n;
		distance = d;
		material = m;
	}

	void raycast(const Ray& ray, std::pair<float, float>& t) const;
	Vector3 get_normal(const Point& point) const;

} Plane;

float plane_equation(const Plane& plane, const Point& point);

#endif