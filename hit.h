#ifndef _HIT_H_
#define _HIT_H_

#include "vector.h"
#include "point.h"

typedef struct Hit {

	Point point;
	Vector3 normal;

} Hit;

#endif