#include "sphere.hpp"
#include <iostream>

bool Sphere::intersects(const Ray& ray, Hit& hit) const {
	glm::vec3 q = ray.origin - center;
	float qdotd = glm::dot(q, ray.direction);
	float bsq = std::powf(qdotd, 2.0f);
	float c = glm::dot(q, q) - std::powf(radius, 2.0f);
	float discriminant = bsq - c;

	if (discriminant < 0.0f) {
		return false;
	}

	discriminant = std::sqrtf(discriminant);
	float t0 = -qdotd + discriminant;
	float t1 = -qdotd - discriminant;

	if (t0 < 0.0f && t1 < 0.0f) {
		return false;
	}

	glm::vec3 p0 = ray.origin + ray.direction * t0;
	glm::vec3 p1 = ray.origin + ray.direction * t1;

	if (t0 < t1 && t0 > 0.0f) {
		hit.material = material;
		hit.normal = glm::normalize(p0 - center);
		hit.point = p0;
		hit.t = t0;
	}
	else if(t1 < t0 && t1 > 0.0f){
		hit.material = material;
		hit.normal = glm::normalize(p1 - center);
		hit.point = p1;
		hit.t = t1;
	}

	return true;
}