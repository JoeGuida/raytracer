#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "ray.h"

class Object {
public:

	bool intersects(const Ray& ray);

};

#endif