#include "../headers/plane.h"

void Plane::raycast(const Ray& ray, std::pair<float, float>& t) const {
	float direction_dot_normal = dot_product(ray.direction, normal);
	float origin_dot_normal = dot_product(ray.origin, normal);

	if (direction_dot_normal >= 0.0f) {
		t = std::pair<float, float>(INFINITY, INFINITY);
		return;
	}

	float plane_t = (distance - origin_dot_normal) / direction_dot_normal;
	if (plane_t >= 0.0f)
		t.first = plane_t;
}

Vector3 Plane::get_normal(const Point& point) const {
	return normal;
}

float plane_equation(const Plane& plane, const Point& point) {
	return dot_product(point, plane.normal) - plane.distance;
}