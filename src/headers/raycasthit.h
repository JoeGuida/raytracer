#ifndef _RAYCASTHIT_H_
#define _RAYCASTHIT_H_

#include "vector.h"
#include "point.h"
#include "material.h"
#include "sphere.h"

typedef struct RaycastHit {

	Point point;
	Vector3 normal;
	Material material;
	const Sphere* object;

	RaycastHit() {
		point = Point();
		normal = Vector3();
		material = Material();
		object = nullptr;
	}

	bool is_null() const {
		return point == Vector3() && normal == Vector3() && material == Material() && object == nullptr;
	};

} RaycastHit;

#endif