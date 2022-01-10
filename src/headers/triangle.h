#ifndef _TRIANGLE_H_
#define _TRAINGLE_H_

#include "primitive.h"
#include "point.h"
#include "ray.h"

typedef struct Triangle : Primitive {

	Point a;
	Point b;
	Point c;

	Triangle() {
		a = Point(0, 0, 0);
		b = Point(0, 0, 0);
		c = Point(0, 0, 0);
	}

	Triangle(const Point& x, const Point& y, const Point& z) {
		a = x;
		b = y;
		c = z;
	}

	void raycast(const Ray& ray, std::pair<float, float>& t) const;
	Vector3 get_normal(const Point& point) const;

} Triangle;

#endif