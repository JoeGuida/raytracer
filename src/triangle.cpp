#include "triangle.hpp"

bool Triangle::intersects(const Ray& ray, Hit& hit) const {
	glm::vec3 e1 = v1 - v0;
	glm::vec3 e2 = v2 - v0;
	glm::vec3 p = glm::cross(ray.direction, e2);
	float d = glm::dot(p, e1);

	if (fabsf(d - 0.0f) < FLT_EPSILON) {
		return false;
	}

	glm::vec3 s = ray.origin - v0;
	float u = glm::dot(p, s) / d;

	if (u < 0.0f || u > 1.0f) {
		return false;
	}

	glm::vec3 q = glm::cross(s, e1);
	float v = glm::dot(ray.direction, q) / d;
	if (v < 0.0f || (u + v) > 1.0f) {
		return false;
	}

	float t = glm::dot(e2, q) / d;
	if (t < 0.0f) {
		return false;
	}

	hit.material = &material;
	hit.normal = glm::normalize(glm::cross(e1, e2));
	hit.point = ray.origin + ray.direction * t;
	hit.t = t;
	return true;
}