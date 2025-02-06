#include "cylinder.hpp"

bool Cylinder::intersects(const Ray& ray, Hit& hit) const {
	Ray rt(
		rotation_matrix * (ray.origin - base),
		glm::vec3(0.0f));
	rt.direction = rotation_matrix * ray.direction;
	Interval cap_interval = slab.intersection(ray);

	float a = (rt.direction.x * rt.direction.x) + (rt.direction.y * rt.direction.y);
	float b = 2 * ((rt.direction.x * rt.origin.x) + (rt.direction.y * rt.origin.y));
	float c = (rt.origin.x * rt.origin.x) + (rt.origin.y * rt.origin.y) - (radius * radius);
	float discriminant = (b * b) - (4 * a * c);
	
	if (discriminant < 0.0f) {
		return false;
	}

	float t0 = -b + sqrtf(discriminant) / (2 * a);
	float t1 = -b - sqrtf(discriminant) / (2 * a);
	
	if (t0 > t1) {
		float temp = t0;
		t0 = t1;
		t1 = temp;
	}

	glm::vec3 n0 = glm::vec3(
		rt.origin.x + (t0 * rt.direction.x), 
		rt.origin.y + (t0 * rt.direction.y), 
		0.0f);
	glm::vec3 n1(
		rt.origin.x + (t1 * rt.direction.x), 
		rt.origin.y + (t1 * rt.direction.y), 
		0.0f);
	n0 = glm::transpose(rotation_matrix) * n0;
	n1 = glm::transpose(rotation_matrix) * n1;

	Interval body_interval(t0, t1, n0, n1);
	Interval interval;
	interval.t0 = std::max(cap_interval.t0, body_interval.t0);
	interval.t1 = std::min(cap_interval.t1, body_interval.t1);

	if (interval.t0 > interval.t1) {
		return false;
	}

	hit.material = material;
	hit.normal = interval.n0;
	hit.point = ray.origin + ray.direction * interval.t0;
	hit.t = interval.t0;
	return true;
}