#ifndef _PLANE_H_
#define _PLANE_H_

#include "shape.h"
#include "point.h"
#include "material.h"

typedef struct Plane : public Shape {

	Vector3 normal;
	float distance;
	Material material;

	Plane() {
		normal = Vector3(1, 0, 0);
		distance = 1.0f;
		material = Material();
	}

	Plane(const Vector3& n, float d, Material m) {
		normal = normalized_vector(n);
		distance = d;
		material = m;
	}

	float raycast(const Ray& ray) const;
	Vector3 get_normal(const Point& point) const;

} Plane;

float plane_equation(const Point& point, const Plane& plane);

#endif