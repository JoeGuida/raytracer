#ifndef RAYTRACER_HIT_HPP
#define RAYTRACER_HIT_HPP

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

#include "material.hpp"

struct Hit {
	BRDFMaterial* material;
	float t;
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 tex_coords;

	Hit() : material(nullptr), t(0.0f), position(glm::vec3(0.0f)), normal(glm::vec3(0.0f)), tex_coords(glm::vec2(0.0f)) {}
	Hit(BRDFMaterial* material, float t, const glm::vec3& position, const glm::vec3& normal, const glm::vec2& tex_coords) : material(material), t(t), position(position), normal(normal), tex_coords(tex_coords) {}
};

#endif