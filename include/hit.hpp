#ifndef RAYTRACER_HIT_HPP
#define RAYTRACER_HIT_HPP

#include "glm/vec3.hpp"

#include "material.hpp"

struct Hit {
	const Material* material;
	glm::vec3 normal;
	glm::vec3 point;
	float t;

	Hit() : material(nullptr), normal(glm::vec3(0.0f)), point(glm::vec3(0.0f)), t(0.0f) {}
	Hit(const Hit&) = default;
	Hit(Hit&&) = default;

	Hit& operator=(const Hit& hit) {
		material = hit.material;
		normal = hit.normal;
		point = hit.point;
		t = hit.t;
		return *this;
	}

	virtual ~Hit() = default;
};

#endif