#include "plane.h"

float plane_equation(const Point& point, const Plane& plane) {
	return dot_product(point, plane.normal) - plane.distance;
}

float Plane::raycast(const Ray& ray) const {
	float ray_direction_dot_normal = dot_product(ray.direction, normal);
	float ray_origin_dot_normal = dot_product(ray.origin, normal);

	if (ray_direction_dot_normal >= 0)
		return -1;

	float t = (distance - ray_origin_dot_normal) / ray_direction_dot_normal;

	if (t >= 0)
		return t;

	return -1;
}

Vector3 Plane::get_normal(const Point& point) const {
	return normal;
}
