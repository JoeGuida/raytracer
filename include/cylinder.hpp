#ifndef RAYTRACER_CYLINDER_HPP
#define RAYTRACER_CYLINDER_HPP

#include "glm/mat3x3.hpp"

#include "hit.hpp"
#include "interval.hpp"
#include "material.hpp"
#include "plane.hpp"
#include "ray.hpp"
#include "shape.hpp"

struct Cylinder : Shape {
	glm::vec3 base;
	glm::vec3 axis;
	float radius;
	float height;
	Material material;

	Cylinder(const glm::vec3& base, const glm::vec3& axis, float radius, float height, const Material& material) : 
		base(base), axis(axis), radius(radius), height(height), material(material) {}
	Cylinder(const Cylinder&) = default;
	Cylinder(Cylinder&&) = default;
	virtual ~Cylinder() = default;

	virtual bool intersects(const Ray& ray, Hit& hit) const;
	virtual Material get_material() const { return material; }
	virtual glm::vec3 get_pos() const { return base; }
};

#endif