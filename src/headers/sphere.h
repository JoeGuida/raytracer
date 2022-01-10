#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "primitive.h"
#include "ray.h"
#include "color.h"
#include "material.h"
#include <utility>

class Sphere : Primitive {
public:
	Point center;
	float radius;
	Material material;

	Sphere() {
		center = Point();
		radius = 1;
		material = Material(Color(255, 0, 0), 10, 0.2f);
	}

	Sphere(Point p, float r, Material m) {
		center = p;
		radius = r;
		material = m;
	}

	void raycast(const Ray& ray, std::pair<float, float>& t) const;
	Vector3 get_normal(const Point& point) const;
};

#endif