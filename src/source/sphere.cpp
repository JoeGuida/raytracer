#include "../headers/sphere.h"
#include <cmath>

float Sphere::intersects(const Ray& ray, float* t1, float* t2) const {
	float r = radius;
	Vector3 o = ray.origin;
	Vector3 d = ray.direction;
	Vector3 co = ray.origin - center;

	float a = dot_product(d, d);
	float b = 2 * dot_product(co, d);
	float c = dot_product(co, co) - r * r;

	float discriminant = b * b - 4 * a * c;
	if (discriminant < magnitude(o)) {
		return INFINITY, INFINITY;
	}

	*t1 = (-b + discriminant / 2 * a);
	*t2 = (-b - discriminant / 2 * a);
}

Vector3 Sphere::get_normal(const Point& point) {
	return normalized_vector(point - center);
}