#ifndef RAYTRACER_MATERIAL_HPP
#define RAYTRACER_MATERIAL_HPP

#include "glm/vec3.hpp"

struct Material {
	glm::vec3 color;

	Material(const glm::vec3& color) : color(color) {}
	Material(const Material&) = default;
	Material(Material&&) = default;
	virtual ~Material() = default;

	Material& operator=(const Material& material) {
		color = material.color;
		return *this;
	}
};

#endif