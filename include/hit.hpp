#ifndef RAYTRACER_HIT_HPP
#define RAYTRACER_HIT_HPP

#include "glm/vec3.hpp"

#include "material.hpp"

struct Hit {
	Material material;
	glm::vec3 normal;
	glm::vec3 point;
	float t;

	Hit() : material(glm::vec3(0.0f)), normal(glm::vec3(0.0f)), point(glm::vec3(0.0f)), t(0.0f) {}
	Hit(const Hit&) = default;
	Hit(Hit&&) = default;
	virtual ~Hit() = default;
};

#endif