#ifndef RAYTRACER_PLANE_HPP
#define RAYTRACER_PLANE_HPP

#include "glm/geometric.hpp"
#include "glm/vec3.hpp"

struct Plane {
	glm::vec3 normal;
	float distance;

	Plane(const glm::vec3& normal, float distance) : normal(glm::normalize(normal)), distance(distance) {}
	Plane(const Plane&) = default;
	Plane(Plane&&) = default;
	virtual ~Plane() = default;
};

#endif