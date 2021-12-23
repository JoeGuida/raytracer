#include "../headers/plane.h"

float Plane::raycast(const Ray& ray) {
	float direction_dot_normal = dot_product(ray.direction, normal);
	float origin_dot_normal = dot_product(ray.origin, normal);

	if (direction_dot_normal >= 0.0f)
		return -1;

	float t = (distance - origin_dot_normal) / direction_dot_normal;

	if (t >= 0.0f)
		return t;
	
	return -1;
}

Vector3 Plane::get_normal(const Point& point) {
	return normal;
}

float plane_equation(const Plane& plane, const Point& point) {
	return dot_product(point, plane.normal) - plane.distance;
}