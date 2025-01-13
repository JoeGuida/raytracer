#ifndef RAYTRACER_CYLINDER_HPP
#define RAYTRACER_CYLINDER_HPP

#include "glm/vec3.hpp"

#include "hit.hpp"
#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"

struct Cylinder : Shape {
	glm::vec3 position;
	float radius;
	float height;
	BRDFMaterial material;

	Cylinder(const glm::vec3& position, float radius, float height, const BRDFMaterial& material) : position(position), radius(radius), height(height), material(material) {}
	bool intersects(const Ray& ray, Hit& hit) const override;
};

#endif