#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "ray.h"
#include "color.h"
#include "material.h"

class Sphere {
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

	float intersects(const Ray& ray, float* t1, float* t2) const;
	Vector3 get_normal(const Point& point);
};

#endif