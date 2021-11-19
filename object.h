#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "ray.h"

class Object {
public:

	Object() {}
	virtual bool intersects(const Ray& ray) = 0;

};

#endif