#include "../headers/sphere.h"
#include <cmath>

float Sphere::intersects(const Ray& ray, float* t1, float* t2) const {
	float r = radius;
	Vector3 O = ray.origin;
	Vector3 D = ray.direction;
	Vector3 CO = ray.origin - center;

	float a = Dot(D, D);
	float b = 2 * Dot(CO, D);
	float c = Dot(CO, CO) - r * r;

	float discriminant = b * b - 4 * a * c;
	if (discriminant < Magnitude(O)) {
		return INFINITY, INFINITY;
	}

	*t1 = (-b + discriminant / 2 * a);
	*t2 = (-b - discriminant / 2 * a);
}