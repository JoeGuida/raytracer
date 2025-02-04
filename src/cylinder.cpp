#include "cylinder.hpp"

bool Cylinder::intersects(const Ray& ray, Hit& hit) const {
	glm::vec3 a = glm::normalize(axis);
	glm::vec3 v(0.0f, 0.0f, 1.0f);

	if (glm::length(glm::cross(v, a)) == 0.0f) {
		v = glm::vec3(1.0f, 0.0f, 0.0f);
	}

	glm::vec3 b = glm::normalize(glm::cross(v, a));
	glm::vec3 c = glm::cross(a, b);

	glm::mat3x3 R = {b, c, a};

	return false;
}