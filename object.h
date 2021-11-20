#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cmath>
#include "ray.h"
#include "material.h"

class Object {
public:
	Material material;

	virtual bool intersects(const Ray& ray) const = 0;

};

#endif