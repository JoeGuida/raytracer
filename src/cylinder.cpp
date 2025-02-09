#include "cylinder.hpp"

bool Cylinder::intersects(const Ray& ray, Hit& hit) const {
	Ray rt(R * (ray.origin - base), R * ray.direction);
	Interval cap_interval = slab.intersection(rt);

	float a = (rt.direction.x * rt.direction.x) + (rt.direction.y * rt.direction.y);
	float b = 2 * ((rt.direction.x * rt.origin.x) + (rt.direction.y * rt.origin.y));
	float c = (rt.origin.x * rt.origin.x) + (rt.origin.y * rt.origin.y) - (radius * radius);
	float discriminant = (b * b) - (4 * a * c);
	
	if (discriminant < 0.0f) {
		return false;
	}

	float t0 = (-b + sqrtf(discriminant)) / (2 * a);
	float t1 = (-b - sqrtf(discriminant)) / (2 * a);
	
	if (t0 > t1) {
		float temp = t0;
		t0 = t1;
		t1 = temp;
	}

	glm::vec3 n0(rt.origin.x + (t0 * rt.direction.x), rt.origin.y + (t0 * rt.direction.y), 0.0f);
	glm::vec3 n1(rt.origin.x + (t1 * rt.direction.x), rt.origin.y + (t1 * rt.direction.y), 0.0f);
	n0 = glm::transpose(R) * n0;
	n1 = glm::transpose(R) * n1;

	Interval body_interval(t0, t1, glm::normalize(n0), glm::normalize(n1));

	Interval interval;
	interval.calculate(cap_interval, body_interval);

	if (interval.t0 > interval.t1) {
		return false;
	}

	if (interval.t0 > 0.0f) {
		hit.material = &material;
		hit.normal = interval.n0;
		hit.point = ray.origin + ray.direction * interval.t0;
		hit.t = interval.t0;
		return true;
	}

	else if (interval.t1 > 0.0f) {
		hit.material = &material;
		hit.normal = interval.n1;
		hit.point = ray.origin + ray.direction * interval.t1;
		hit.t = interval.t1;
		return true;
	}

	return false;
}