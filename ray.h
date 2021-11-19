#ifndef _RAY_H_
#define _RAY_H_

#include "vector.h"

typedef struct Ray {

	Vector3 origin;
	Vector3 direction;

	Ray() {
		origin = Vector3();
		direction = Vector3();
	}

	Ray(Vector3 o, Vector3 d) {
		origin = o;
		direction = Normalized(d);
	}

} Ray;

#endif