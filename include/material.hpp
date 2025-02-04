#ifndef RAYTRACER_MATERIAL_HPP
#define RAYTRACER_MATERIAL_HPP

#include "glm/vec3.hpp"

struct Material {
	glm::vec3 color;
	int specularity;

	Material(const glm::vec3& color, int specularity) : color(color), specularity(specularity) {}
	Material(const Material&) = default;
	Material(Material&&) = default;
	virtual ~Material() = default;

	Material& operator=(const Material& material) {
		color = material.color;
		specularity = material.specularity;
		return *this;
	}
};

#endif