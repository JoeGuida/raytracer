#ifndef RAYTRACER_CYLINDER_HPP
#define RAYTRACER_CYLINDER_HPP

#include "glm/mat3x3.hpp"

#include "hit.hpp"
#include "material.hpp"
#include "ray.hpp"

struct Cylinder {
	glm::vec3 position;
	float radius;
	float height;
	Material material;

	Cylinder(const glm::vec3& position, float radius, float height, const Material& material) : position(position), radius(radius), height(height), material(material) {}
	Cylinder(const Cylinder&) = default;
	Cylinder(Cylinder&&) = default;
	virtual ~Cylinder() = default;

	virtual bool intersects(const Ray& ray, Hit& hit) const;
	virtual Material get_material() const { return material; }
	virtual glm::vec3 get_pos() const { return position; }
};

#endif