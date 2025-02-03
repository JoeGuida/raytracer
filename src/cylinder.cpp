#include "cylinder.hpp"

bool Cylinder::intersects(const Ray& ray, Hit& hit) const {
	glm::vec3 p1 = base;
	glm::vec3 p2 = (base + axis) * height;

	glm::vec3 pa = p1;
	glm::vec3 va = (p2 - p1) / glm::length(p2 - p1);
	
	return false;
}