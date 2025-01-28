#ifndef RAYTRACER_RAY_HPP
#define RAYTRACER_RAY_HPP

#include "glm/geometric.hpp"
#include "glm/vec3.hpp"

struct Ray {
	glm::vec3 origin;
	glm::vec3 direction;

	Ray(const glm::vec3& origin, const glm::vec3& direction) : origin(origin), direction(glm::normalize(direction)) {}
};

#endif