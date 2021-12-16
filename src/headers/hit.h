#ifndef _HIT_H_
#define _HIT_H_

#include "vector.h"
#include "point.h"
#include "material.h"

typedef struct Hit {

	Point point;
	Vector3 normal;
	Material material;

	Hit() {
		point = Point();
		normal = Vector3();
		material = Material();
	}

} Hit;

#endif