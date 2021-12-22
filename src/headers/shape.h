#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "vector.h"
#include "ray.h"

typedef struct Shape {

	virtual float raycast(const Ray& ray) const = 0;
	virtual Vector3 get_normal(const Point& point) const = 0;

} Shape;

#endif