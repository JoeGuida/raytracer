#ifndef _RAY_H_
#define _RAY_H_

#include "vector.h"
#include "point.h"

typedef struct Ray {

	Point origin;
	Vector3 direction;

	Ray() {
		origin = Point();
		direction = Vector3();
	}

	Ray(Point o, Vector3 d) {
		origin = o;
		direction = Normalized(d);
	}

} Ray;

#endif