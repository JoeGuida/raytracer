#ifndef _RAY_H_
#define _RAY_H_

#include "vector.h"
#include "point.h"

typedef struct Ray {

	Point origin;
	Vector3 direction;
	float refraction_index;

	Ray() {
		origin = Point();
		direction = Vector3();
		refraction_index = 1.000273f;
	}

	Ray(Point o, Vector3 d) {
		origin = o;
		direction = normalized_vector(d);
		refraction_index = 1.000273f;
	}

	Ray(Point o, Vector3 d, float r) {
		origin = o;
		direction = normalized_vector(d);
		refraction_index = r;
	}

} Ray;

#endif