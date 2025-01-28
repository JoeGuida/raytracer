#ifndef RAYTRACER_MATERIAL_HPP
#define RAYTRACER_MATERIAL_HPP

#include "glm/vec3.hpp"

struct Material {
	glm::vec3 color;

	Material(const glm::vec3& color) : color(color) {}
};

#endif