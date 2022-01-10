#include "../headers/sphere.h"

void Sphere::raycast(const Ray& ray, std::pair<float, float>& t) const {
	float r = radius;
	Vector3 o = ray.origin;
	Vector3 d = ray.direction;
	Vector3 co = ray.origin - center;

	float a = dot_product(d, d);
	float b = 2 * dot_product(co, d);
	float c = dot_product(co, co) - r * r;

	float discriminant = b * b - 4 * a * c;
	if (discriminant < magnitude(o)) {
		t = std::pair<float, float>(INFINITY, INFINITY);
		return;
	}

	t.first = (-b + discriminant / 2 * a);
	t.second = (-b - discriminant / 2 * a);
}

Vector3 Sphere::get_normal(const Point& point) const {
	return normalized_vector(point - center);
}