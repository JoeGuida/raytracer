#ifndef _PRIMITIVE_H_
#define _PRIMITIVE_H_

#include "point.h"
#include "ray.h"
#include "vector.h"
#include "material.h"
#include <utility>

class Primitive {
protected:
	Material material;

public:
	virtual void raycast(const Ray& ray, std::pair<float, float>& t) const = 0;
	virtual Vector3 get_normal(const Point& point) const = 0;
};

#endif